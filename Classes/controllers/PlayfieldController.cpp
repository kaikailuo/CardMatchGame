#include"PlayfieldController.h"

#include"MatchZoneController.h"
#include"PlayfieldCardView.h"
#include"CardStateModel.h"

std::function<void(CardView*)> PlayfieldController::_onCardClicked = nullptr;
Node* PlayfieldController::_playfieldView = nullptr;

void PlayfieldController::init() {
    _onCardClicked = [](CardView* card) {
        handleCardClick(card);
        };
}
void PlayfieldController::initView(Node* rootNode) {
    _playfieldView = Node::create();
    rootNode->addChild(_playfieldView);
    creatTypeCard(_onCardClicked);
}

void PlayfieldController::creatTypeCard(std::function<void(CardView*)> onCardClicked) {
    //��ȡmodel
    auto cardState = CardStateModel::getInstance();
    for (auto& cardModel : cardState->getPlayfieldCards()) {
        //��model����view
        auto card = PlayfieldCard::create(cardModel, onCardClicked);
        _playfieldView->addChild(card);
    }
}

void PlayfieldController::handleCardClick(CardView* card) {

    //check() ��� �ɷ�ƥ�� ��ƥ�䷵��
    int topCardFace = CardStateModel::getInstance()->getTopCardFace();
    int cardFace = card->getModel()->getFace();
    if (topCardFace != cardFace + 1 && cardFace != topCardFace + 1)return;

    //run() ִ��ƥ�䶯��
    auto move = MoveTo::create(GameConfig::moveDuration_pla, GameConfig::matchZonePos);//�ƶ���ƥ����
    auto callback = CallFunc::create([card]() {
        MatchZoneController::addTo(card);       //����ƥ������ӷ���
        });
    card->runAction(Sequence::create(move, callback, nullptr));

    //update()
    card->getModel()->updateClickEnabled(false);
    card->updateEnableClick();
    CardStateModel::getInstance()->pushbackUndoStack(PLAYFIELD);
}

void PlayfieldController::addToView(CardView* card) {
    _playfieldView->addChild(card);
}
#include "StackCardView.h"

StackCard* StackCard::create(const CardStateModel* stackModel, const std::function<void(CardView*)> onCardClicked) {
    StackCard* ret = new (std::nothrow) StackCard();
    if (ret && ret->init(stackModel,onCardClicked)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool StackCard::init(const CardStateModel* stackModel, const std::function<void(CardView*)> onCardClicked) {
    if (!Node::init()) return false;

    for (auto& cardModel : stackModel->getStackCards()) {
        auto card = CardView::create(cardModel);

        card->setClickCallback(onCardClicked);
        addCard(card);
    }

    return true;
}

void StackCard::addCard(CardView* card) {
    if (!card) return;
    index++;
    _cards.pushBack(card);
    this->addChild(card);
    layoutCards();
}

void StackCard::removeCard() {
    if (index == -1) return;
    
    auto card = _cards.at(index);
    index--;
}

void StackCard::withdrawOneCard() {
    index++;
}
void StackCard::layoutCards() {
    // ���Ƴߴ�ͼ�ࣨ���迨�ƿ�160����240�����Զ��壩w = 182.00 h = 282.00
    if (_cards.empty())return;

    float cardWidth = 182.0f;
    float spacing = 30.0f;
    float totalWidth = cardWidth + (_cards.size() - 1) * spacing;

    // ��ʼ X ���꣨ʹ����У�
    float startX = 200.0f;
    float startY = 290.0f;

    for (int i = 0; i <= index; ++i) {
        CardView* card = _cards.at(i);
        float x = startX + i * spacing;
        float y = startY; //�̶��ڵײ�
        card->getModel()->updateOriginPosition(Vec2(x, y));
        card->setPosition(Vec2(x, y)); // ������ʾ
    }
}


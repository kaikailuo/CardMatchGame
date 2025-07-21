#include "MatchZoneView.h"


bool MatchZoneView::init() {
    if (!Node::init()) {
        return false;
    }

     //����һ������ͼ�������Ӿ�����
    auto bg = DrawNode::create();
    bg->drawSolidRect(Vec2::ZERO, GameConfig::cardSize, Color4F(0.9f, 0.9f, 0.9f, 0.3f));
    bg->setContentSize(GameConfig::cardSize);
    bg->setAnchorPoint(Vec2(0.5f, 0.5f));
    bg->setPosition(GameConfig::matchZonePos);
    this->addChild(bg, -1);

    this->setContentSize(GameConfig::cardSize);
    return true;
}

void MatchZoneView::setCard(CardView* card) {
    //���ƣ�����
    if (_topCard != nullptr) {
        _topCard->setVisible(false);// ������
    }
    //�����ƶ�
    _topCard = card;
}

CardView* MatchZoneView::getCard() const {
    return _topCard;
}

void MatchZoneView::clearCard() {
    if (_topCard) {
        _topCard = nullptr;
    }
}

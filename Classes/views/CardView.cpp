#include "CardView.h"

CardView* CardView::create(CardModel* cardmodel) {
    CardView* ret = new (std::nothrow) CardView();
    if (ret && ret->init(cardmodel)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool CardView::init(CardModel* cardmodel) {
    if (!Node::init()) return false;
    
    _cardmodel = cardmodel;
    int face = cardmodel->getFace();
    int suit = cardmodel->getSuit();
    Vec2 pos = cardmodel->getOriginPosition();
    getInfo(face, suit);

    Size size = _bg->getContentSize();
    this->setContentSize(size);//��Ҫ��С�����
    this->setPosition(pos);
    

    _bg->setPosition(Vec2::ZERO);
    _centerNumber->setPosition(Vec2(0, -size.height / 12));
    _LeftUpNumber->setPosition(Vec2(-size.width / 3, size.height / 3));
    _suit->setPosition(Vec2(size.width / 3, size.height / 3));

    this->addChild(_bg);
    this->addChild(_suit);
    this->addChild(_centerNumber);
    this->addChild(_LeftUpNumber);

    // ��ӵ������
    _listener = EventListenerTouchOneByOne::create();
    _listener->setSwallowTouches(true);//�����¼�,����ڵ����ֹ�����͸
    _listener->onTouchBegan = CC_CALLBACK_2(CardView::onTouchBegan, this);//�󶨻ص�����
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);//������ע��

    Size size1 = this->getContentSize();
    Rect rect(0, 0, size.width, size.height);

    
    return true;
}

//��ʼ���� UI ���
void CardView::getInfo(int face, int suit) {
    _color = (suit == 0 || suit == 3) ? "black" : "red";
    _bg = Sprite::create("/cards/card_general.png");
    _suit = Sprite::create("cards/suits/" + std::to_string(suit) + ".png");
    std::string numberType = _color + "_" + std::to_string(face + 1);
    _centerNumber = Sprite::create("cards/numbers/big_" + numberType + ".png");
    _LeftUpNumber = Sprite::create("cards/numbers/small_" + numberType + ".png");
}

void CardView::setClickCallback(const std::function<void(CardView*)>& callback) {
    _clickCallback = callback;
}

void CardView::updateEnableClick() {
    if (_listener) {
        _listener->setEnabled(this->getModel()->getClickEnabled());
    }
}

bool CardView::onTouchBegan(Touch* touch, Event* event) {
    if (!this->getModel()->getClickEnabled()) return false;

    Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
    Size size = this->getContentSize();
    Rect rect(-size.width * 0.5, -size.height * 0.5, size.width, size.height);
    
    if (rect.containsPoint(locationInNode)) {
        if (_clickCallback) {
            _clickCallback(this);  // �����ص�
        }
        else {
            CCLOG("card get clicked");
        }
        return true;
    }
    return false;
}

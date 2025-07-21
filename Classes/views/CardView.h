#pragma once
#include "cocos2d.h"
#include "CardModel.h"
USING_NS_CC;


//�ṩ���� CardModel* �������Ƶķ���
class CardView : public Sprite {
public:
    static CardView* create(CardModel* cardmodel);
    virtual bool init(CardModel* cardmodel);
    
    void getInfo(int face, int suit);
  
    CardModel* getModel() { return _cardmodel; }

    void setClickCallback(const std::function<void(CardView*)>& callback); // ���õ���ص�����
    void updateEnableClick();//�����Ƿ����
private:
    std::string _color;
    Sprite* _bg;
    Sprite* _suit;
    Sprite* _centerNumber;
    Sprite* _LeftUpNumber;

    CardModel* _cardmodel;

    EventListenerTouchOneByOne* _listener = nullptr;
    std::function<void(CardView*)> _clickCallback;

    bool onTouchBegan(Touch* touch, Event* event);
};

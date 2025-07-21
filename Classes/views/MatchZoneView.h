#pragma once
#include "cocos2d.h"
#include"GameConfig.h"
#include"CardView.h"
USING_NS_CC;

class MatchZoneView :public Sprite {
public:
    virtual bool init() override;
    CREATE_FUNC(MatchZoneView);

    void setCard(CardView* card);  // ����ƥ������ǰ����
    CardView* getCard() const;     // ��ȡ��ǰ����
    void clearCard();              // ���ƥ�������ƣ����翨�Ʊ������ˣ�

private:
    CardView* _topCard = nullptr;
};
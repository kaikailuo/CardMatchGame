#pragma once

#include "cocos2d.h"
#include "GameConfig.h"
#include"CardView.h"
USING_NS_CC;

class PlayfieldController{
public:
    static void init();
    static void initView(Node* rootNode);
    static void handleCardWithdraw(CardView* card);
    static void addToView(CardView* card);
    
private:
    //����Playfield ���������
    static void handleCardClick(CardView* card);
    //����Playfield �ϵ��ƣ��󶨻ص�����
    static void creatTypeCard(std::function<void(CardView*)> onCardClicked);

    static std::function<void(CardView*)> _onCardClicked;//playfield��Ļص�����
    static Node* _playfieldView;
};
#pragma once

#include "cocos2d.h"

#include"CardView.h"
#include"MatchZoneView.h"
USING_NS_CC;

class MatchZoneController {
public:
    static void init();
    static void initView(Node* rootNode);

    static void addTo(CardView* card);//��ƥ���� ���һ�ſ�
    static void moveTopBack(CardView* card);//�Ƴ�top��
    static void replaceToTop(CardView* card);


    static MatchZoneView* getmatchZoneView() { return _matchZoneView; };
private :
    static void creatView(Node* rootNode);

    static MatchZoneView* _matchZoneView;
    //static std::function<void(CardView*)> _onCardClicked;
};
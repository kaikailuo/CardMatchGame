#pragma once

#include"cocos2d.h"
USING_NS_CC;

class GameViewManager : public cocos2d::Ref {
public:
    static GameViewManager* create(cocos2d::Node* rootNode); // �ⲿ���볡��/���ڵ�
    bool init(cocos2d::Node* rootNode);

    void setView();
    void setBackground();//��Ⱦ����

private:
    Node* _rootNode = nullptr; // �������ڵ㣬���� addChild
};
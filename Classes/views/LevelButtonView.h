#pragma once
#include "cocos2d.h"

USING_NS_CC;

// ���� int ��������һ����Ӧ�Ĺؿ�ѡ��ť�����ʱ�����ص�����
class LevelButtonView : public Node {
public:
    static LevelButtonView* create(int levelNumber, std::function<void(std::string)> callback);
    virtual bool init(int levelNumber, std::function<void(std::string)> callback);

    void setView(int levelNumber);
    void bindEvent();

private:
    DrawNode* _background;
    Label* _label;

    std::function<void(std::string)> _callback;
};

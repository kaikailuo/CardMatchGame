#include "LevelSelectController.h"
#include "GameScene.h"
#include "GameModel.h"
#include "DrawBackgroundView.h"
#include "LevelButtonView.h"

LevelSelectController* LevelSelectController::create(LevelSelectView* view) {
    LevelSelectController* ret = new (std::nothrow) LevelSelectController();
    if (ret && ret->init(view)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool LevelSelectController::init(LevelSelectView* view) {
    if (!Node::init()) return false;
    levelSelectView = view;

    initView();

    return true;
}

void LevelSelectController::initView() {
    //��Ⱦ����
    auto bg = DrawBackgroundView::create(Vec2(0, 0), Vec2(1080, 2080), Color4F::BLUE);
    bg->setPosition(Vec2::ZERO);
    levelSelectView->addChild(bg, -1);

    //����һ����ť
    auto btn = LevelButtonView::create(1, [this](std::string levelName) {
        //�ؿ���ѡ�񣬻ص�����
        this->setSelectedLevel(levelName);
        });
    btn->setPosition(Vec2(540, 1040));
    levelSelectView->addChild(btn, 0);
}

//����model
void LevelSelectController::setSelectedLevel(std::string levelName) {
    GameModel::getInstance()->setSelectedLevel(levelName);//���ؿ�id����model
    //����Game
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, scene));
}


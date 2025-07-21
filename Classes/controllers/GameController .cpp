#include"GameController.h"

#include"PlayfieldController.h"//�ӿ�����
#include"StackController.h"
#include"MatchZoneController.h"
#include"UndoController.h"

#include"GameModel.h"//model
#include"GameModelFromLevelGenerator.h"//service

//#include "GameView.h"
//#include "CardView.h"
//#include "GameViewManager.h"

GameController* GameController::create(GameView* view) {
    GameController* ret = new (std::nothrow) GameController();
    if (ret && ret->init(view)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool GameController::init(GameView* view) {
    if (!Node::init()) return false;
    _gameView = view;

    //���ɼ�view
    _viewManager = GameViewManager::create(_gameView);
    _viewManager->setView();

    //Gameִ������
    loadLevel();//���عؿ���Ϣ
    initController();//��ʼ�� ��controller
    iniView();//��controller ���ɸ���view

    return true;
}

//��config��ȡ�ؿ�����ʼ����model
void GameController::loadLevel() {
    //��ȡ����
    std::string filename = GameConfig::levelConfigPath;
    std::string levelName = GameModel::getInstance()->getSelectedLevel();
    //service�� ��ȡ+�洢
    GameModelFromLevelGenerator::generateCardModel(levelName, filename);
}

//
void GameController::initController() { 
    PlayfieldController::init();
    StackController::init();
    MatchZoneController::init();
    UndoController::init();
}
//
void GameController::iniView() {
    PlayfieldController::initView(_gameView);
    StackController::initView(_gameView);
    MatchZoneController::initView(_gameView);
    UndoController::initView(_gameView);
    
}



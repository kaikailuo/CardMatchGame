#pragma once

#include <string>
#include "CardStateModel.h"
#include "LevelConfigLoader.h" // �ṩ loadLevel

using namespace cocos2d;
using namespace rapidjson;

// ��ָ���ؿ��������ݴ����ö�ȡ��д�� model�������Ƿ�ɹ�
class GameModelFromLevelGenerator {
public:
    static bool generateCardModel(const std::string& levelName, const std::string& configFile);
};

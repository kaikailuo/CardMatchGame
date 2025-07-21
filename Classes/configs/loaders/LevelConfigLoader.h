#pragma once

#include "cocos2d.h"
#include "json/document.h"
#include "json/document.h"
#include "json/error/en.h"

class LevelLoader {
public:
    // 加载某一关卡的 JSON 数据
    static bool loadLevel(const std::string& filename, const std::string& levelName, 
                            rapidjson::Document& outDoc, rapidjson::Value*& outLevelData);
};

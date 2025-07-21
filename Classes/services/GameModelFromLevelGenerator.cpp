#include"GameModelFromLevelGenerator.h"

bool GameModelFromLevelGenerator::generateCardModel(const std::string& levelName, const std::string& configFile) {
    //��ȡstate�࣬ʧ�ܷ���false
    auto cardState = CardStateModel::getInstance();
    if (!cardState) return false;

    
    rapidjson::Document doc;
    rapidjson::Value* levelData = nullptr;

    if (LevelLoader::loadLevel(configFile, levelName, doc, levelData)) {//����LevelLoader::loadLevel ��ȡLevelConfig
        // ��ȡ Playfield
        const auto& playfield = (*levelData)["Playfield"];
        for (rapidjson::SizeType i = 0; i < playfield.Size(); ++i) {
            const auto& card = playfield[i];
            int face = card["CardFace"].GetInt();
            int suit = card["CardSuit"].GetInt();
            float x = card["Position"]["x"].GetFloat();
            float y = card["Position"]["y"].GetFloat();

            // ���� ������add
            cardState->addToPlayfield(face, suit, x, y);
        }
        // ��ȡ Stack
        const auto& stack = (*levelData)["Stack"];
        for (rapidjson::SizeType i = 0; i < stack.Size(); ++i) {
            const auto& card = stack[i];
            int face = card["CardFace"].GetInt();
            int suit = card["CardSuit"].GetInt();
            float x = card["Position"]["x"].GetFloat();
            float y = card["Position"]["y"].GetFloat();

            // ���� ������add
            cardState->addToStack(face, suit, x, y);
        }
    }
}

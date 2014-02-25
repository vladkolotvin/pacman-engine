#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "FileManager.h"
#include "InputManager.h"
#include "TextureManager.h"

namespace pacman {
class Game;
class GameScene {
  public:
    GameScene(): game_(nullptr), fileManager_(*this) , textureManager_(*this), isReady_(false) {}
    virtual ~GameScene() {}

    void setGame(Game* game) { game_ = game; }
    bool isReady() const { return isReady_; }
    virtual void initialize() = 0;
    virtual void update() {}

    FileIO::FileManager& getFileManager() { return fileManager_; }
    InputManager& getInputManager() { return inputManager_; }
    Game& getGame() { return *game_; }
  protected:
    void isReady(bool isReady) { isReady_ = isReady; }
  private:
    Game* game_;
    FileIO::FileManager fileManager_;
    TextureManager textureManager_;
    InputManager inputManager_;
    bool isReady_;
};
} // namespace pacman

#endif // GAMESCENE_H

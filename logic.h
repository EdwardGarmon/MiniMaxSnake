#include "models.h"
#include <string>

namespace logic {

BattleSnakeInfoResponse info();
void start();
void end();
BattleSnakeMoveResponse move(GameState *gameState);
} // namespace logic

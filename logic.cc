#include "logic.h"
#include "models.h"
#include <iostream> // header in standard library
#include <string>

using namespace logic;
using namespace std;

BattleSnakeInfoResponse logic::info() {
  return BattleSnakeInfoResponse{
      "1", "CountZero", "#12d5db", "shades", "sharp",
  };
}

BattleSnakeMoveResponse logic::move(GameState *gameState) {
  BattleSnakeMoveResponse res;
  res.move = "UP";
  return res;


}

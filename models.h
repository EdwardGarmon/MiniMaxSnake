
#ifndef MODELS_H
#define MODELS_H

#include "json_struct.h"
#include <string>

const std::string ServerID = "Snake++";

const std::string UP = "up";
const std::string DOWN = "down";
const std::string LEFT = "left";
const std::string RIGHT = "right";

struct Royale {
  int shrinkEveryNTurns;
};
JS_OBJ_EXT(Royale, shrinkEveryNTurns);

struct Settings {
  int foodSpawnChance;
  int minimumFood;
  int hazardDamagePerTurn;
  Royale *royale;
};
JS_OBJ_EXT(Settings, foodSpawnChance, minimumFood, hazardDamagePerTurn, royale);

struct RuleSet {
  std::string name;
  std::string version;
  Settings *settings;
};
JS_OBJ_EXT(RuleSet, name, version, settings);

struct Coord {
  int x;
  int y;
};
JS_OBJ_EXT(Coord, x, y);

struct Board {
  int height;
  int width;
  Coord food[];
};
JS_OBJ_EXT(Board, height, width, food);

struct Game {
  std::string id;
  RuleSet *ruleSet;
  int turn;
  Board *board;
};
JS_OBJ_EXT(Game, id, ruleSet, turn, board);

struct BattleSnake {
  std::string id;
  std::string name;
  int health;
  int length;
  Coord *head;
  int latency;
  std::string shout;
  std::string squad;
  Coord *body[];
};
JS_OBJ_EXT(BattleSnake, id, name, health, length, head, latency, shout, squad,
           body);

struct GameState {
  int turn;
  Board *board;
  BattleSnake *you;
  Game game;
};
JS_OBJ_EXT(GameState, turn, board, you, game);

struct Squad {
  bool allowBodyCollisions;
  bool sharedElimination;
  bool sharedHealth;
  bool sharedLength;
};
JS_OBJ_EXT(Squad, allowBodyCollisions, sharedElimination, sharedHealth)

struct BattleSnakeInfoResponse {
  std::string APIVersion;
  std::string Author;
  std::string Color;
  std::string Head;
  std::string Tail;
};
JS_OBJ_EXT(BattleSnakeInfoResponse, APIVersion, Author, Color, Head, Tail);

struct BattleSnakeMoveResponse {
  std::string move;
  std::string shout;
};
JS_OBJ_EXT(BattleSnakeMoveResponse, move, shout);
#endif
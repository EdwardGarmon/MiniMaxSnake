#include "crow.h"
#include "json_struct.h"
#include "logic.h"
#include "models.h"
#include <crow/http_request.h>
#include <crow/http_response.h>
#include <iostream>
#include <string>

std::string HandleIndex() { return JS::serializeStruct(logic::info()); }
crow::response HandleStart(const crow::request &req) {
  crow::response res;
  return res;
}
std::string HandleMove(const crow::request &req) {
  GameState state;
  JS::ParseContext context(req.body);
  context.parseTo(state);
  return JS::serializeStruct(logic::move(&state));
}
crow::response HandleEnd(const crow::request &req) {
  crow::response res;
  return res;
};

struct ServerIDMiddleWare {
  std::string server_id;
  void set_ServerId(const std::string &new_id) { server_id = new_id; }
  struct context {};
  void before_handle(crow::request &req, crow::response &res, context &ctx) {}
  void after_handle(crow::request &req, crow::response &res, context &ctx) {
    res.add_header("Server", server_id);
  }
};

void StartServer() {
  crow::SimpleApp app;
  app.get_middleware<ServerIDMiddleWare>().set_ServerId(ServerID);
  CROW_ROUTE(app, "/")([]() { return HandleIndex(); });
  CROW_ROUTE(app, "/start").methods("POST"_method)(HandleStart);
  CROW_ROUTE(app, "/move").methods("POST"_method)(HandleMove);
  CROW_ROUTE(app, "/end").methods("POST"_method)(HandleEnd);
  app.port(18080).multithreaded().run();
}

int main() { StartServer(); }
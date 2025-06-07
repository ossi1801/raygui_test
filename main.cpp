#include <cstdio>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <iostream>
#include <raygui.h>
using namespace std;

const int GAME_WIDTH = 600;
const int GAME_HEIGHT = 400;

struct {

  Vector2 pos;
  float w;
  float h;
  float speed;
  float rotation;
  // Color ?
  // Name ?
} player;

void init_player() {
  player.pos.x = 0;
  player.pos.y = 0;
  player.w = 20;
  player.h = 20;
  player.speed = 0.05;
  player.rotation = 0;
  // player.color?
  // player.Name?
}

// Main loop runs on everyframe ?
void loop() {
  BeginDrawing();
  ClearBackground(SKYBLUE);
  Vector2 v1 = {player.pos.x + sinf(player.rotation * DEG2RAD) * (player.h),
                player.pos.y - cosf(player.rotation * DEG2RAD) * (player.h)};
  Vector2 v2 = {player.pos.x - cosf(player.rotation * DEG2RAD) * (player.w / 2),
                player.pos.y -
                    sinf(player.rotation * DEG2RAD) * (player.w / 2)};
  Vector2 v3 = {player.pos.x + cosf(player.rotation * DEG2RAD) * (player.w / 2),
                player.pos.y +
                    sinf(player.rotation * DEG2RAD) * (player.w / 2)};

  DrawTriangle(v1, v2, v3, RED);
  // DrawRectangle(player.pos.x, player.pos.y, player.w, player.h, RED);
  DrawText("Hello world", 100, 100, 10, RED);
  //}

  EndDrawing();
}
void check_user_input() {
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    player.pos.x -= player.speed;
  }
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    player.pos.x += player.speed;
  }
  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    player.pos.y += player.speed;
  }
  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    player.pos.y -= player.speed;
  }
}

void collisions() {
  // TODO: use
  // CheckCollisionRecs(Rectangle rec1, Rectangle rec2)

  if (player.pos.x <= 0) {
    player.pos.x = 0;
  }
  if (player.pos.x >= GAME_WIDTH - player.w) {
    player.pos.x = GAME_WIDTH - player.w;
  }
  if (player.pos.y <= 0) {
    player.pos.y = 0;
  }
  if (player.pos.y >= GAME_HEIGHT - player.h) {
    player.pos.y = GAME_HEIGHT - player.h;
  }
}
int main(int argc, char *argv[]) {
  printf("Program running");
  InitWindow(GAME_WIDTH, GAME_HEIGHT, "Test app");
  SetWindowMonitor(0);
  SetExitKey(KEY_ESCAPE);
  init_player();
  while (!WindowShouldClose()) {
    check_user_input();
    loop();
    collisions();
  }
  return 0;
}

#include <cstdio>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <iostream>
#include <raygui.h>
using namespace std;

const int GAME_WIDTH = 600;
const int GAME_HEIGHT = 400;

struct {
  float x;
  float y;
  float w;
  float h;
  float speed;
  float rotation;
  // Color ?
  // Name ?
} player;

void init_player() {
  player.x = 0;
  player.y = 0;
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
  Vector2 v1 = {player.x + sinf(player.rotation * DEG2RAD) * (player.h),
                player.y - cosf(player.rotation * DEG2RAD) * (player.h)};
  Vector2 v2 = {player.x - cosf(player.rotation * DEG2RAD) * (player.w / 2),
                player.y - sinf(player.rotation * DEG2RAD) * (player.w / 2)};
  Vector2 v3 = {player.x + cosf(player.rotation * DEG2RAD) * (player.w / 2),
                player.y + sinf(player.rotation * DEG2RAD) * (player.w / 2)};

  DrawTriangle(v1, v2, v3, RED);
  // DrawRectangle(player.x, player.y, player.w, player.h, RED);
  DrawText("Hello world", 100, 100, 10, RED);
  //}

  EndDrawing();
}
void check_user_input() {
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    player.x -= player.speed;
  }
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    player.x += player.speed;
  }
  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    player.y += player.speed;
  }
  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    player.y -= player.speed;
  }
}

void collisions() {
  // TODO: use
  // CheckCollisionRecs(Rectangle rec1, Rectangle rec2)

  if (player.x <= 0) {
    player.x = 0;
  }
  if (player.x >= GAME_WIDTH - player.w) {
    player.x = GAME_WIDTH - player.w;
  }
  if (player.y <= 0) {
    player.y = 0;
  }
  if (player.y >= GAME_HEIGHT - player.h) {
    player.y = GAME_HEIGHT - player.h;
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

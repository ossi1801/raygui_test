#include <cstdio>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <iostream>
#include <raygui.h>
using namespace std;

struct {
  float x;
  float y;
  float w;
  float h;
  float speed;
  // Color ?
  // Name ?
} player;

void init_player() {
  player.x = 0;
  player.y = 0;
  player.w = 20;
  player.h = 20;
  player.speed = 0.05;
  // player.color?
  // player.Name?
}

// Main loop runs on everyframe ?
void loop() {
  BeginDrawing();
  ClearBackground(SKYBLUE);
  // for (int i = 0; i < 100; i++) {
  // if (player.x != 0)
  // cout << player.x;
  DrawRectangle(player.x, player.y, player.w, player.h, RED);
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

int main(int argc, char *argv[]) {
  printf("Program running");
  InitWindow(600, 400, "Test app");
  SetWindowMonitor(0);
  SetExitKey(KEY_ESCAPE);
  init_player();
  while (!WindowShouldClose()) {
    check_user_input();
    loop();
  }
  return 0;
}

#include <cstdio>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

float x = 0;
float y = 0;
// Main loop runs on everyframe ?
void loop() {
  BeginDrawing();
  ClearBackground(SKYBLUE);
  // for (int i = 0; i < 100; i++) {

  DrawRectangle(x, y, 50, 50, RED);
  DrawText("Hello world", 100, 100, 10, RED);
  //}

  EndDrawing();
}
void check_user_input() {
  float speed = 0.1;
  if (IsKeyDown(KEY_LEFT)) {
    x -= speed;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    x += speed;
  }
  if (IsKeyDown(KEY_DOWN)) {
    y += speed;
  }
  if (IsKeyDown(KEY_UP)) {
    y -= speed;
  }
}

int main(int argc, char *argv[]) {
  printf("Program running");
  InitWindow(600, 400, "Test app");
  SetExitKey(KEY_ESCAPE);
  while (!WindowShouldClose()) {
    check_user_input();
    loop();
  }
  return 0;
}

#include <stdio.h>

#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "./raygui/src/raygui.h"

int main() {

	int window_width = 800;
	int window_height = 600;

	InitWindow(window_width, window_height, "CVisiGraph");

	int test = GetTextWidth("test");

	while (!WindowShouldClose()) {

	}



  return 0;
}

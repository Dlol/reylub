#include <raylib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

void centerRect(int x, int y, int width, int height, Color color) {
	DrawRectangle((x - (width / 2)), (y - (height / 2)), width, height, color);
}

void statusBar(int height, int value) {
	DrawRectangle(0, height, 800, 30, RAYWHITE);
	std::stringstream out;
	out << "bg value: " << value;
	DrawText(out.str().c_str(),5,height + 5, 20, BLACK);
}

int main() {
	int screenWidth = 800;
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight + 30, "raylib example");
	SetTargetFPS(60);
	int currentX = screenWidth / 2;
	int currentY = screenHeight / 2;
	int alpha = 255;
	int speed = 5;
	srand(time(NULL));
	Vector2 direction = {0.76,-0.89};
	Color rectColor = {255, 0, 0, 255};
	Color clearColor = {0,0,0,128};
	while (!WindowShouldClose()){
		BeginDrawing();
		DrawRectangle(0,0,screenWidth,screenHeight,clearColor);
		if(currentX - 32 < 0 || currentX + 32 > screenWidth){
			srand(time(NULL));
			direction.x = direction.x * -1;
		}
		if(currentY - 32 < 0 || currentY + 32 > screenHeight){
			srand(time(NULL));
			direction.y = direction.y * -1;
		}
		currentX += (speed * direction.x);
		currentY += (speed * direction.y);

		DrawCircle(currentX, currentY, 32, rectColor);
		statusBar(screenHeight, clearColor.r);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
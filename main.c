#include "raylib.h"
// #define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <stdio.h>
#define MAX_GESTURE_STRINGS 20
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_Height = 600;

    InitWindow(screen_width , screen_height, "CVisiGraph");

    Vector2 touch_position = { 0, 0 };
    Rectangle touch_area = { 220, 10, screen_width - 230.0f, screen_height - 20.0f };

    int gestures_count = 0;
    char gesture_strings[MAX_GESTURE_STRINGS][32];

    int current_gesture = GESTURE_NONE;
    int last_gesture = GESTURE_NONE;

    //SetGesturesEnabled(0b0000000000001001);   // Enable only some gestures to be detected

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        last_gesture = current_gesture;
        current_gesture = GetGestureDetected();
        touch_position = GetTouchPosition(0);

        if (CheckCollisionPointRec(touch_position, touch_area) && (current_gesture != GESTURE_NONE))
        {
            if (current_gesture != last_gesture)
            {
                // Store gesture string
                switch (current_gesture)
                {
                    case GESTURE_TAP: TextCopy(gestureStrings[gesturesCount], "GESTURE TAP"); break;
                    case GESTURE_DOUBLETAP: TextCopy(gestureStrings[gesturesCount], "GESTURE DOUBLETAP"); break;
                    case GESTURE_HOLD: TextCopy(gestureStrings[gesturesCount], "GESTURE HOLD"); break;
                    case GESTURE_DRAG: TextCopy(gestureStrings[gesturesCount], "GESTURE DRAG"); break;
                    case GESTURE_SWIPE_RIGHT: TextCopy(gestureStrings[gesturesCount], "GESTURE SWIPE RIGHT"); break;
                    case GESTURE_SWIPE_LEFT: TextCopy(gestureStrings[gesturesCount], "GESTURE SWIPE LEFT"); break;
                    case GESTURE_SWIPE_UP: TextCopy(gestureStrings[gesturesCount], "GESTURE SWIPE UP"); break;
                    case GESTURE_SWIPE_DOWN: TextCopy(gestureStrings[gesturesCount], "GESTURE SWIPE DOWN"); break;
                    case GESTURE_PINCH_IN: TextCopy(gestureStrings[gesturesCount], "GESTURE PINCH IN"); break;
                    case GESTURE_PINCH_OUT: TextCopy(gestureStrings[gesturesCount], "GESTURE PINCH OUT"); break;
                    default: break;
                }

                gesturesCount++;

                // Reset gestures strings
                if (gesturesCount >= MAX_GESTURE_STRINGS)
                {
                    for (int i = 0; i < MAX_GESTURE_STRINGS; i++) TextCopy(gestureStrings[i], "\0");

                    gesturesCount = 0;
                }
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangleRec(touchArea, GRAY);
            DrawRectangle(225, 15, screenWidth - 240, screenHeight - 30, RAYWHITE);

            DrawText("GESTURES TEST AREA", screenWidth - 270, screenHeight - 40, 20, Fade(GRAY, 0.5f));

            for (int i = 0; i < gesturesCount; i++)
            {
                if (i%2 == 0) DrawRectangle(10, 30 + 20*i, 200, 20, Fade(LIGHTGRAY, 0.5f));
                else DrawRectangle(10, 30 + 20*i, 200, 20, Fade(LIGHTGRAY, 0.3f));

                if (i < gesturesCount - 1) DrawText(gestureStrings[i], 35, 36 + 20*i, 10, DARKGRAY);
                else DrawText(gestureStrings[i], 35, 36 + 20*i, 10, MAROON);
            }

            DrawRectangleLines(10, 29, 200, screenHeight - 50, GRAY);
            DrawText("DETECTED GESTURES", 50, 15, 10, GRAY);

            if (currentGesture != GESTURE_NONE) DrawCircleV(touchPosition, 30, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}



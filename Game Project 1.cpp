#include "raylib.h"
#include "Cube.h"
#include "Terrain.h"
#include "Player.h"
#include <vector>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Voxel Game");

    Terrain* terrain = new Terrain();
    //terrain->generate();

    Player* player = new Player();
    player->startPlayerGui(screenWidth,screenHeight);

    DisableCursor();               

    SetTargetFPS(60);  
    

    while (!WindowShouldClose())       
    {

        player->render();

        if (IsKeyPressed('Z')) player->camera.target = { 0.0f, 0.0f, 0.0f };

        BeginDrawing();

        ClearBackground(RAYWHITE);

        player->renderPlayerGui();
  
        BeginMode3D(player->camera);

        //terrain->render();

        //DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

        DrawGrid(10, 1.0f);

        EndMode3D();

        DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 320, 93, BLUE);

        DrawText("Free camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
        DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY);

        EndDrawing();

    }

    player->deallocateTexture();

    delete player;
    delete terrain;
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
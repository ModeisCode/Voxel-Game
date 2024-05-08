#pragma once
#include "raylib.h"
#include <iostream>

class Player
{

private:
	const char* health5 = "assets/healthBar/5.png";
	const char* health4 = "assets/healthBar/4.png";
	const char* health3 = "assets/healthBar/3.png";
	const char* health2 = "assets/healthBar/2.png";
	const char* health1 = "assets/healthBar/1.png";

public:

	Player() {
		camera.position = { 10.0f, 10.0f, 10.0f };// Camera position
		camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
		camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
		camera.fovy = 45.0f;                                // Camera field-of-view Y
		camera.projection = CAMERA_PERSPECTIVE;
		position = { 10.0f, 10.0f, 10.0f };
	}

	std::string name = "steve";
	int health = 10;
	int hungry = 10;
	int armor = 0;
	int xp = 0;
	int level = 0;
	float screenWidht = 0;
	float screenHeight = 0;

	Camera3D camera;
	Vector3 position;
	// health bar
	Vector2 healthBarPos;
	Texture2D texture;

	void render() {
		UpdateCamera(&camera, CAMERA_FREE);
	}

	void startPlayerGui(int screenWidth, int screenHeight) {
		texture = LoadTexture(health5);
		this->screenWidht = screenWidth;
		this->screenHeight = screenHeight;
		healthBarPos.x = screenWidth / 2;
		healthBarPos.y = screenHeight - 20;
	}

	void renderPlayerGui() {
		DrawTexture(texture, screenWidht/2,screenHeight - 20, WHITE);
	}

	void deallocateTexture() {
		UnloadTexture(texture);
	}

};

/*
		if (health == 10)
		{
			texture = LoadTexture(health5);
		}
		else if (health >= 8 && health < 10) {

		}
		else if (health >= 6 && health < 8) {

		}
		else if (health >= 3 && health < 6) {

		}
		else if (health >= 1 && health < 3) {

		}
		else if (health == 0) {

		}
		else {
			std::cout << "[Error]: Player health could not be below 0 or above 10." << std::endl;
		}
*/

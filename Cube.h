#pragma once
#include "raylib.h"
#include <iostream>

class Cube
{

private:

public:
	Cube(const char* texturePath,Vector3 position,Vector3 size) {
		//texture loading
		Image image = LoadImage(texturePath);
		Texture2D texture = LoadTextureFromImage(image);
		this->texture = texture;
		UnloadImage(image);
		//set position
		this->position = position;
		this->size = size;

		model = LoadModelFromMesh(GenMeshCube(size.x, size.y, size.z));
		model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
		//SetMaterialTexture(&model.materials[0] , MATERIAL_MAP_DIFFUSE , texture);
	}


	Cube(Color color,Vector3 position,Vector3 size) {
		this->color = color;
		this->position = position;
		this->size = size;
	}

	Model model;
	Color color;
	Texture2D texture;
	Vector3 position;
	Vector3 size;
	std::string tag = "";

	void render() {
		DrawCube(position, size.x, size.y, size.z, color);
	}

	void renderModel() {
		DrawModel(model, position, 1.0f,WHITE);
	}

	void printPos() { std::cout << "(Cube_Pos) X:" << position.x << " Y:" << position.y << " Z:" << position.z << std::endl; }

};


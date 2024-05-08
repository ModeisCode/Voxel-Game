#pragma once
#include "noise/noise.h"
#include <iostream>
#include <vector>
#include "Cube.h"

using namespace noise;

class Terrain
{

private:
	void generateStones(Vector3 pos,Vector3 size) {
		for (int i = 0; i < 10; i++)
		{
			pos.y -= size.y;
			Cube cube("assets/blocks/stone.png",pos,size);
			this->cubes.push_back(cube);
		}
	}


public:
	std::vector<Cube> cubes;
	Terrain() {}
	void generate() {
		module::Perlin perlin;  // Ters çevirme yok
		Vector3 size = { 1.0f, 1.0f, 1.0f }; // Küp boyutu (ayarlanabilir)
		//float incX = 0.0f;
		//float incZ = 0.0f;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				float x = (float)i / 99.0f;  // Normalize coordinates
				float y = (float)j / 99.0f;
				double perlinValue = perlin.GetValue(x, y, 0.0f);  // Gürültüye z=0 noktasından bak
				float height = perlinValue * 5.0f;  // Yükseklik ayarı (ayarlanabilir)
				Vector3 pos = { (float)i, height ,(float)j  };
				Cube cube("assets/blocks/grass.png" , pos , size);
				this->cubes.push_back(cube);
				generateStones(pos,size);
				//incZ += size.z;
			}
			//incX += size.x;
			//incZ = 0.0f;
		}
	}

	void render() {
		for (Cube cube : cubes)
		{
			cube.renderModel();
		}
	}

};


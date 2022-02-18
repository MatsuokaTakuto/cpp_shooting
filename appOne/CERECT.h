#pragma once
#include "SCENE.h"
#include"libOne.h"
class CERECT :
	public SCENE
{
public:
	struct DATA {
		float angle = 0;
		float anglespeed = 0;
		float siz = 0;
		float sizspeed = 0;
		int img = 0;
		int plimg = 0;
		int emimg = 0;
		int backImg = 0;
		COLOR backColor;
	};
private:
	DATA Cerect;
public:
	CERECT(class GAME* game);
	~CERECT();
	void abe();
	void init();
	void setu();
	void draw();
	void nextScene();
};

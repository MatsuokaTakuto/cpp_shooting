#pragma once
#include "SCENE.h"
class STAGE :
	public SCENE
{
public:
	struct DATA {
		VECTOR2 pos;
		VECTOR2 pos1;
		int Ex = 0;
		int backImg = 0;
		int img = 0;
		COLOR backColor;
	};
private:
	DATA Stage;
public:
	STAGE(class GAME* game);
	~STAGE();
	void Back();
	void BackGround();
	void caunt();
	void create();
	void init();
	void update();
	void draw();
	void nextScene();
};


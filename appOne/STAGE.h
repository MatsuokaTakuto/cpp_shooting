#pragma once
#include "SCENE.h"
class STAGE :
	public SCENE
{
public:
	struct DATA {
		int Ex = 0;
		int backImg = 0;
		COLOR backColor;
	};
private:
	DATA Stage;
	void BackGround();
public:
	STAGE(class GAME* game);
	~STAGE();
	void caunt();
	void create();
	void init();
	void update();
	void draw();
	void nextScene();
};


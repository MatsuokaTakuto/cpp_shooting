#pragma once
class GAME {
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE1_ID,
		STAGE2_ID,
		STAGE3_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES

	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
public:
	void changeScene(SCENE_ID sceneId);
public:
	GAME();
	~GAME();
	void run();
};
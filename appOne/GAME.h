#pragma once
class GAME
{
	//コンテナ
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
	//シーン
public:
	//列挙型
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		//何個定数があるか
		NUM_SCENES
	};
private:           
	class SCENE* Scenes[NUM_SCENES];
	//現在のシーン
	SCENE_ID CurSceneId;
public:
	void changeScene(SCENE_ID sceneId);
	//キャラクター
private:
	class PLAYER* Player;
	class ENEMIES* Enemies;
	class PLAYER_BULLETS* PlayerBullets;
public:
	class PLAYER* player() { return Player; }
	class ENEMIES* enemies() { return Enemies; }
	class PLAYER_BULLETS* playerBullets() { return PlayerBullets; }
public:
	GAME();
	~GAME();
	//実行しろという関数
	void run();
	//切り替えるための関数
};


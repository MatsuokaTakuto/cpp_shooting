#pragma once
class GAME
{
	//�R���e�i
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
	//�V�[��
public:
	//�񋓌^
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		//���萔�����邩
		NUM_SCENES
	};
private:           
	class SCENE* Scenes[NUM_SCENES];
	//���݂̃V�[��
	SCENE_ID CurSceneId;
public:
	void changeScene(SCENE_ID sceneId);
	//�L�����N�^�[
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
	//���s����Ƃ����֐�
	void run();
	//�؂�ւ��邽�߂̊֐�
};


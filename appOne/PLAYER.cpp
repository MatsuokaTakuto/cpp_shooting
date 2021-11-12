#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER_BULLETS.h"
#include "PLAYER.h"
PLAYER::PLAYER(class GAME* game) :
	GAME_OBJECT(game) {
}
PLAYER::~PLAYER() {}
void PLAYER::create() {
	Player = game()->container()->player();
}
void PLAYER::init() {

}
void PLAYER::update() {
	move();
	launch();
}
void PLAYER::move() {
	if (Player.pos.x > Player.limmitW && isPress(KEY_A)) {
		//delta�������邱�Ƃɂ����1�b�Ԃɓ����ʂ����߂邱�Ƃ��ł���
		Player.pos.x += -Player.advSpeed * delta;
	}
	else if (Player.pos.x < width - Player.limmitW && isPress(KEY_D)) {
		Player.pos.x += Player.advSpeed * delta;
	}
}
void PLAYER::launch() {
	if (Player.triggerErapsedTime >= Player.triggerInterval) {
		game()->playerBullets()->launch(Player.pos, Player.launcchVec);
		//////
	}
}
void PLAYER::draw() {
	rectMode(CENTER);
	image(Player.img, Player.pos.x, Player.pos.y, Player.angle);
}
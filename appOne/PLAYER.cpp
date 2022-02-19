#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include "PLAYER.h"
#include"libOne.h"
PLAYER::PLAYER(class GAME* game) :
	GAME_OBJECT(game) {
}
PLAYER::~PLAYER() {}
void PLAYER::create() {
	Player = game()->container()->player();
}
void PLAYER::init() {
	Player.pos = game()->container()->player().pos;
	Player.hp = game()->container()->player().hp;
	Player.img = loadImage("assets\\p2.png");
}
void PLAYER::update() {
	move();
	launch();
	collision();
}
void PLAYER::move() {
	if (Player.pos.x > Player.limmitW && isPress(KEY_A)) {
		//delta‚ð‚©‚¯‚é‚±‚Æ‚É‚æ‚Á‚Ä1•bŠÔ‚É“®‚­—Ê‚ðŒˆ‚ß‚é‚±‚Æ‚ª‚Å‚«‚é
		Player.pos.x += -Player.advSpeed * delta;
	}
	else if (Player.pos.x < width - Player.limmitW && isPress(KEY_D)) {
		Player.pos.x += Player.advSpeed * delta;
	}

	if (Player.pos.y > Player.limmitH && isPress(KEY_W)) {
		Player.pos.y += -Player.advSpeed * delta;
	}
	else if (Player.pos.y < height - Player.limmitH && isPress(KEY_S)) {
		Player.pos.y += Player.advSpeed * delta;
	}
}
void PLAYER::launch() {
	if (Player.baria != 1) {
		if (game()->gatya()->gatyacaunt() == 1) {
			if (isPress(KEY_SPACE)) {
				Player.triggerErapsedTime += delta;
				if (Player.triggerErapsedTime >= Player.triggerInterval) {
					//”­ŽË‚·‚éƒxƒNƒgƒ‹‚É”­ŽË‚ð‚¸‚ç‚·‚à‚Ì‚ðŠ|‚¯ŽZ‚·‚é
					VECTOR2 pos = Player.pos + Player.launchVec * Player.ofstLaunchDist;
					VECTOR2 pos1 = Player.pos + Player.launchVec1 * Player.ofstLaunchDist;
					VECTOR2 pos2 = Player.pos + Player.launchVec2 * Player.ofstLaunchDist;
					game()->playerBullets()->launch(pos, Player.launchVec);
					game()->playerBullets()->launch(pos1, Player.launchVec1);
					game()->playerBullets()->launch(pos2, Player.launchVec2);
					Player.triggerErapsedTime = 0;
				}
			}
			else {
				Player.triggerErapsedTime = 0.1f;
			}
		}
		else {
			if (isPress(KEY_SPACE)) {
				Player.triggerErapsedTime += delta;
				if (Player.triggerErapsedTime >= Player.triggerInterval) {
					//”­ŽË‚·‚éƒxƒNƒgƒ‹‚É”­ŽË‚ð‚¸‚ç‚·‚à‚Ì‚ðŠ|‚¯ŽZ‚·‚é
					VECTOR2 pos = Player.pos + Player.launchVec * Player.ofstLaunchDist;
					game()->playerBullets()->launch(pos, Player.launchVec);
					Player.triggerErapsedTime = 0;
				}
			}
			else {
				Player.triggerErapsedTime = Player.triggerInterval;
			}
		}
	}
}
//“–‚½‚è”»’è
void PLAYER::collision() {
	if (Player.invincibleRestTime > 0) {
		Player.invincibleRestTime -= delta;
	}
	else {
		Player.color = Player.normalColor;
		ENEMY_BULLETS* bullets = game()->enemyBullets();
		float distance = Player.bcRadius + bullets->bcRadius();
		//sqDistance‚æ‚è‚à‹ß‚©‚Á‚½‚ç‚ ‚½‚é‚Æ‚¢‚¤”»’è
		float sqDistance = distance * distance;
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Player.pos - bullets->pos(i);
			if (sqLength(vec) < sqDistance) {
				Player.baria = 0;
				Player.invincibleRestTime = Player.invincibleTime;
				Player.color = Player.collisionColor;
				Player.hp = Player.hp - 2;
				bullets->kill(i);
				i = 0;
			}






		}
	}
}
void PLAYER::draw() {
	imageColor(Player.color);
	rectMode(CORNER);
	if (game()->gatya()->gatyacaunt() == 1) {
		image(Player.img, Player.pos.x, Player.pos.y, 0, 0.3f);
	}
	else{
		Player.anim->draw(&Player.animData, Player.pos.x, Player.pos.y, 0, 4);
	}
	game()->hpGauge()->draw(Player.playerHp, Player.hpGaugeOfst, Player.hp,1);
}

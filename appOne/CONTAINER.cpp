#include "CONTAINER.h"
void CONTAINER::load(){
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	Data.title.backColor = COLOR(255);
	Data.title.textColor = COLOR(0, 255, 0);
	Data.title.textSize = 400;
	Data.title.pos.x = 0;
	Data.title.pos.y = 700;
	strcpy_s(Data.title.str, "KUNOICHE");

	Data.player.angle = 0;
	Data.player.pos.x = 960;
	Data.player.pos.y = 970;
	Data.player.limmitW = 100;
	Data.player.limmitH = 100;
	Data.player.advSpeed = 300;
	Data.player.launcchVec = VECTOR2(0, -1);
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 0.5f;

	Data.enemy.totalNum = 8;
	Data.enemy.majRadius = 800;
	Data.enemy.minRadius = 200;
	Data.enemy.centerPos = VECTOR2(980, -300);
	Data.enemy.fallSpeed = 60;
	Data.enemy.targetPosY = 540;
	Data.enemy.refTheta = 0;
	Data.enemy.thetaSpeed = 0.6;

	Data.playerBullet.totalNum = 20;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 600;
	Data.playerBullet.angSpeed = 0.05f;
	Data.playerBullet.bcRadius = 20;

}
void CONTAINER::loadGraphic() {
	Data.player.img = loadImage("assets\\player.png");
	Data.enemy.img = loadImage("assets\\enemy.png");
	Data.playerBullet.img = loadImage("assets\\pBullet.png");
}
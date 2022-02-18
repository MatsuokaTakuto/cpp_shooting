#include"graphic.h"
#include "CONTAINER.h"
CONTAINER::~CONTAINER() {
	delete Data.player.anim;
	delete Data.fouran.anim;
	delete Data.oruga.anim;
}
void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	Data.cerect.anglespeed = 2;
	Data.cerect.sizspeed = 0.1f;

	Data.fouran.pos = VECTOR2(1500, 700);
	Data.fouran.color = COLOR(255, 255, 255);

	Data.oruga.pos = VECTOR2(width / 2, height / 2);
	Data.oruga.color = COLOR(255, 255, 255);

	Data.title.backColor = COLOR(0, 0, 0);
	Data.title.textColor = COLOR(255, 0, 0);
	Data.title.textSize = 400;
	Data.title.pos.x = 160;
	Data.title.pos.y = 500;
	strcpy_s(Data.title.str, "VENGENSE");

	Data.GameOver.backColor = COLOR(0, 0, 0);
	Data.GameOver.textColor = COLOR(255, 0, 0);
	Data.GameOver.textSize = 400;
	Data.GameOver.pos.x = 400;
	Data.GameOver.pos.y = 700;
	strcpy_s(Data.GameOver.str, "Game Over");

	Data.GameClear.backColor = COLOR(0, 0, 0);
	Data.GameClear.textColor = COLOR(0, 255, 0);
	Data.GameClear.textSize = 400;
	Data.GameClear.pos.x = 0;
	Data.GameClear.pos.y = 700;
	strcpy_s(Data.GameClear.str, "Game Clear");

	Data.stage.backColor = COLOR(255, 255, 255, 255);

	Data.player.angle = 0;
	Data.player.advSpeed = 450;

	Data.player.pos.x = 360;
	Data.player.pos.y = 485;

	Data.player.limmitW = 100;
	Data.player.limmitH = 100;
	Data.player.launchVec = VECTOR2(1, 0);
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 0.2f;
	Data.player.ofstLaunchDist = 100;
	Data.player.bcRadius = 40;
	Data.player.invincibleTime = 0.2f;
	Data.player.invincibleRestTime = 0;

	Data.player.hp = 100;

	Data.player.playerHp.x = 0;
	Data.player.playerHp.y = 20;
	Data.player.hpGaugeOfst = VECTOR2(0, 0);
	Data.player.collisionColor = COLOR(255, 0, 0, 75);
	Data.player.normalColor = COLOR(255, 255, 255);

	Data.enemy.totalNum = 12;

	Data.enemy.curNum = Data.enemy.totalNum;
	Data.enemy.majRadius = 200;
	Data.enemy.minRadius = 500;
	Data.enemy.centerPos = VECTOR2(3000, height / 2);
	Data.enemy.fallSpeed = 60;
	Data.enemy.targetPosX = 1300;
	Data.enemy.refTheta = 0;
	Data.enemy.thetaSpeed = 0.6f;
	Data.enemy.triggerInterval = 0.72f;
	Data.enemy.ofstLaunchDist = 100;
	Data.enemy.bcRadius = 40;
	Data.enemy.invincibleTime = 0.1f;
	Data.enemy.initHp = 3;
	Data.enemy.hpGaugeOfst = VECTOR2(0, -120);
	Data.enemy.collisionColor = COLOR(255, 0, 0, 25);
	Data.enemy.normalColor = COLOR(255, 255, 255);


	Data.enemy2.totalNum = 8;

	Data.enemy2.curNum = Data.enemy2.totalNum;
	Data.enemy2.majRadius = 200;
	Data.enemy2.minRadius = 400;
	Data.enemy2.centerPos = VECTOR2(3000, height / 2);
	Data.enemy2.fallSpeed = 100;
	Data.enemy2.targetPosX = 1100;
	Data.enemy2.refTheta = 0;
	Data.enemy2.thetaSpeed = 0.6f;
	Data.enemy2.triggerInterval = 1.0f;
	Data.enemy2.ofstLaunchDist = 100;
	Data.enemy2.bcRadius = 40;
	Data.enemy2.invincibleTime = 0.1f;
	Data.enemy2.initHp = 3;
	Data.enemy2.hpGaugeOfst = VECTOR2(0, 0);
	Data.enemy2.collisionColor = COLOR(255, 0, 0, 25);
	Data.enemy2.normalColor = COLOR(255, 255, 255);

	Data.bossenemy.totalNum = 1;

	Data.bossenemy.curNum = Data.bossenemy.totalNum;
	Data.bossenemy.BossHp.x = 0;
	Data.bossenemy.BossHp.y = 60;
	Data.bossenemy.majRadius = 100;
	Data.bossenemy.minRadius = 300;
	Data.bossenemy.centerPos = VECTOR2(2300, height / 2);
	Data.bossenemy.fallSpeed = 60;
	Data.bossenemy.targetPosX = 1600;
	Data.bossenemy.refTheta = 0;
	Data.bossenemy.thetaSpeed = 0.6f;
	Data.bossenemy.triggerInterval = 0.5f;
	Data.bossenemy.ofstLaunchDist = 100;
	Data.bossenemy.bcRadius = 40;
	Data.bossenemy.invincibleTime = 0.1f;
	Data.bossenemy.initHp = 10;
	Data.bossenemy.hpGaugeOfst = VECTOR2(0, 0);
	Data.bossenemy.collisionColor = COLOR(255, 0, 0, 25);
	Data.bossenemy.normalColor = COLOR(255, 255, 255);



	Data.playerBullet.totalNum = 30;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 600;
	Data.playerBullet.angSpeed = 5;
	Data.playerBullet.bcRadius = 20;

	Data.enemyBullet.totalNum = 30;
	Data.enemyBullet.curNum = 0;
	Data.enemyBullet.advSpeed = 600;
	Data.enemyBullet.angSpeed = 0;
	Data.enemyBullet.bcRadius = 20;

	Data.hpGauge.coWidth = 30;
	Data.hpGauge.hi = 15;
	Data.hpGauge.safeColor = COLOR(0, 255, 0);
	Data.hpGauge.dangerColor = COLOR(255, 0, 0);

}
void CONTAINER::loadGraphic() {
	Data.stage.backImg = loadImage("assets\\StageBackImg.jpg");

	Data.enemy.img = loadImage("assets\\enemy_1.png");

	Data.enemy2.img = loadImage("assets\\enemy_2.png");

	Data.bossenemy.img = loadImage("assets\\enemy_3.png");

	Data.playerBullet.img = loadImage("assets\\pBullets.png");

	Data.enemyBullet.img = loadImage("assets\\eBullets.png");

	Data.fouran.anim = new ANIM("assets\\fou");
	Data.fouran.animData.interval = 0.7f;

	Data.player.anim = new ANIM("assets\\players\\0");
	Data.player.animData.interval = 0.1f;

	Data.oruga.anim = new ANIM("assets\\oruga");
	Data.oruga.animData.interval = 0.05f;
}

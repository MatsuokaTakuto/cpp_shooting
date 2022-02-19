#include "GAME_CLEAR.h"
#include"CERECT.h"
#include"TITLE.h"
#include"TRANS.h"
#include"libOne.h"
#include"GATYA.h"
#include"GAME.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {

}
GAME_CLEAR::~GAME_CLEAR() {

}
void GAME_CLEAR::init() {
	game()->trans()->inTrigger();
	GameClear.img = loadImage("assets\\gameclear.png");
	GameClear.img2 = loadImage("assets\\1.png");
	GameClear.img3 = loadImage("assets\\2.png");
	GameClear.img4 = loadImage("assets\\3.png");
	GameClear.img5 = loadImage("assets\\4.png");
	GameClear.backimg = loadImage("assets\\clearback.jpg");
	GameClear.clear = loadImage("assets\\clear.jpg");
	GameClear.rX = 100;
	GameClear.rY = 700;
	GameClear.RX = 1700;
	GameClear.RY = 300;
	GameClear.caunt = -1;
}
void GAME_CLEAR::draw() {
	clear();
	back();
	if (isTrigger(KEY_SPACE)) {
		GameClear.caunt += 1;
	}
	game()->trans()->draw();
}
void GAME_CLEAR::back() {
	rectMode(CENTER);
	imageColor(255, 255, 255);
	image(GameClear.backimg, width / 2, height / 2);
	if (GameClear.caunt == -1) {
		rectMode(CENTER);
		image(GameClear.img2, width / 2, height / 2 - 100, 0, 0.6f);
		rectMode(CORNER);
		fill(0);
		rect(GameClear.rX - 20, GameClear.rY - 20, GameClear.RX + 40, GameClear.RY + 40);
		fill(255, 255, 255);
		rect(GameClear.rX, GameClear.rY, GameClear.RX, GameClear.RY);
		textSize(50);
		fill(0);
			text("クリアおめでとうございます",
				GameClear.rX, GameClear.rY + 100);

	}
	if (GameClear.caunt == 0) {
		rectMode(CENTER);
		image(GameClear.img2, width / 2, height / 2 - 100, 0, 0.6f);
		rectMode(CORNER);
		fill(0);
		rect(GameClear.rX - 20, GameClear.rY - 20, GameClear.RX + 40, GameClear.RY + 40);
		fill(255, 255, 255);
		rect(GameClear.rX, GameClear.rY, GameClear.RX, GameClear.RY);
		textSize(50);
		fill(0);
		if (game()->gatya()->gatyacaunt() == 1) {
			text("ガチャを作りたかった、それだけです",
				GameClear.rX, GameClear.rY + 100);
			text("わかる人はわかると思いますが、そうです、FGOのガチャ演出です",
				GameClear.rX, GameClear.rY + 200);
		}
		else {
			text("え、これだけ？と思った方が多いと思います。",
				GameClear.rX, GameClear.rY + 100);
			text("すみませんこれだけです(´・ω・｀)",
				GameClear.rX, GameClear.rY + 200);

		}
	}
	else if (GameClear.caunt == 1) {
		rectMode(CENTER);
		image(GameClear.img3, width / 2, height / 2 - 100, 0, 0.6f);
		rectMode(CORNER);
		fill(0);
		rect(GameClear.rX - 20, GameClear.rY - 20, GameClear.RX + 40, GameClear.RY + 40);
		fill(255, 255, 255);
		rect(GameClear.rX, GameClear.rY, GameClear.RX, GameClear.RY);
		fill(0);
		if (game()->gatya()->gatyacaunt() == 1) {
			text("ガチャは１パターンしか用意できていません、時間がなかった...",
				GameClear.rX, GameClear.rY + 100);
			text("ガチャで出たキャラは弾が３方向に発射されるなどの差別化はしました",
				GameClear.rX, GameClear.rY + 200);
		}
		else {

			text("本当はアクションをもう少し増やし、ステージ数も増やす予定でしたが",
				GameClear.rX, GameClear.rY + 100);
		}
	}
	else if (GameClear.caunt == 2) {
		rectMode(CENTER);
		image(GameClear.img4, width / 2, height / 2 - 100, 0, 0.8f);
		rectMode(CORNER);
		fill(0);
		rect(GameClear.rX - 20, GameClear.rY - 20, GameClear.RX + 40, GameClear.RY + 40);
		fill(255, 255, 255);
		rect(GameClear.rX, GameClear.rY, GameClear.RX, GameClear.RY);
		fill(0);
		if (game()->gatya()->gatyacaunt() == 1) {
			text("ネタも以上です!",
				GameClear.rX, GameClear.rY + 100);
			text("ありがとうございました!",
				GameClear.rX, GameClear.rY + 200);
		}
		else {
			text("時間と技術力の都合上これだけとなりました、",
				GameClear.rX, GameClear.rY + 100);
			text("すみません、以上です",
				GameClear.rX, GameClear.rY + 200);
		}
	}
	else if (GameClear.caunt == 3) {
		rectMode(CENTER);
		image(GameClear.img5, width / 2, height / 2 - 100, 0, 0.8f);
		rectMode(CORNER);
		fill(0);
		rect(GameClear.rX - 20, GameClear.rY - 20, GameClear.RX + 40, GameClear.RY + 40);
		fill(255, 255, 255);
		rect(GameClear.rX, GameClear.rY, GameClear.RX, GameClear.RY);
		fill(0);
		if(game()->gatya()->gatyacaunt()==1){
			text("Special Thanks to",
				GameClear.rX, GameClear.rY + 100);
			text("ぴぽや倉庫,イラスト屋,その他様々な素材",
				GameClear.rX + 300, GameClear.rY + 200);
		}
		else {

		text("Special Thanks to",
			GameClear.rX, GameClear.rY + 100);
		text("ぴぽや倉庫,その他様々な素材",
			GameClear.rX+300, GameClear.rY + 200);
		}
	}
	else if (GameClear.caunt == 4) {
		rectMode(CENTER);
		image(GameClear.img, width / 2, height / 2 + 300, 0, 0.6f);
		rectMode(CORNER);
		fill(0, 255, 0);
		textSize(250);
		text("Game Clear", 980-563, 600);
	}
	else if (GameClear.caunt == 5) {
		if(game()->gatya()->gatyacaunt()==1){
			rectMode(CORNER);
			image(GameClear.clear, -100, -100, 0, 2);
			fill(0, 255, 0);
			textSize(220);
			text("Special Thanks!!", 980 - 220*4, 300);
		}
		else {
			rectMode(CENTER);
			image(GameClear.img, width / 2, height / 2 + 300, 0, 0.6f);
			rectMode(CORNER);
			fill(0, 255, 0);
			textSize(250);
			text("Game Clear", 980 - 563, 600);
			fill(0);
			rect(GameClear.rX - 20, GameClear.rY - 20, GameClear.RX + 40, GameClear.RY + 40);
			fill(255, 255, 255);
			rect(GameClear.rX, GameClear.rY, GameClear.RX, GameClear.RY);
			fill(0);
			textSize(50);
			text("ゲーム説明画面で<shift>を押すと...",
				GameClear.rX, GameClear.rY + 100);
		}
	}
}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_SPACE)&& GameClear.caunt>=6) {
		game()->trans()->outTrigger();
	}
	if (game()->trans()->outEndFlag() && GameClear.caunt>=6) {
		game()->setCurScene(game()->title());
	}
}

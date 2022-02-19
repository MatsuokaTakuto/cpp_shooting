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
			text("�N���A���߂łƂ��������܂�",
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
			text("�K�`������肽�������A���ꂾ���ł�",
				GameClear.rX, GameClear.rY + 100);
			text("�킩��l�͂킩��Ǝv���܂����A�����ł��AFGO�̃K�`�����o�ł�",
				GameClear.rX, GameClear.rY + 200);
		}
		else {
			text("���A���ꂾ���H�Ǝv�������������Ǝv���܂��B",
				GameClear.rX, GameClear.rY + 100);
			text("���݂܂��񂱂ꂾ���ł�(�L�E�ցE�M)",
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
			text("�K�`���͂P�p�^�[�������p�ӂł��Ă��܂���A���Ԃ��Ȃ�����...",
				GameClear.rX, GameClear.rY + 100);
			text("�K�`���ŏo���L�����͒e���R�����ɔ��˂����Ȃǂ̍��ʉ��͂��܂���",
				GameClear.rX, GameClear.rY + 200);
		}
		else {

			text("�{���̓A�N�V�����������������₵�A�X�e�[�W�������₷�\��ł�����",
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
			text("�l�^���ȏ�ł�!",
				GameClear.rX, GameClear.rY + 100);
			text("���肪�Ƃ��������܂���!",
				GameClear.rX, GameClear.rY + 200);
		}
		else {
			text("���ԂƋZ�p�͂̓s���ケ�ꂾ���ƂȂ�܂����A",
				GameClear.rX, GameClear.rY + 100);
			text("���݂܂���A�ȏ�ł�",
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
			text("�҂ۂ�q��,�C���X�g��,���̑��l�X�ȑf��",
				GameClear.rX + 300, GameClear.rY + 200);
		}
		else {

		text("Special Thanks to",
			GameClear.rX, GameClear.rY + 100);
		text("�҂ۂ�q��,���̑��l�X�ȑf��",
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
			text("�Q�[��������ʂ�<shift>��������...",
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

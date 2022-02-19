#include"libOne.h"
#include "GATYA.h"
#include "CERECT.h"
#include"GAME.h"
#include"TRANS.h"
#include"CONTAINER.h"
GATYA::GATYA(class GAME*game):
	SCENE(game){

}
GATYA::~GATYA(){}
void GATYA::create(){
}
void GATYA::init(){
	game()->trans()->inTrigger();
	Gatya = game()->container()->gatya();
	Gatya.img = loadImage("assets\\gatya3.png");
	Gatya.gatyaimg = loadImage("assets\\gatya3.png");
	Gatya.p2 = loadImage("assets\\p2.png");
	Gatya.caunt = 0;
	Gatya.gatyacaunt = 0;
}
void GATYA::update(){

}
void GATYA::draw(){
	clear();
	game()->trans()->draw();
	if (isTrigger(KEY_ENTER)) {
		Gatya.caunt += 1;
	}
	if (Gatya.caunt == 0) {
		game()->gatyaanim()->set();
		gatyaimg();
	}
	else if (Gatya.caunt >= 1) {
		Gatya.gatyacaunt = 1;
		result();
		game()->gatyaanim()->draw();
	}
}
void GATYA::result() {
	rectMode(CENTER);
	imageColor(255, 255, 255);
	image(Gatya.gatyaimg, width / 2, height / 2,0,2);
	rectMode(CORNER);
	fill(255, 255, 255);
	//戻るボタン
	rect(50, 50, 440, 160);
	//結果
	fill(255, 255, 0);
	rect(720, 340, 400, 400);
	image(Gatya.p2, 720, 340);

	fill(0, 0, 0);
	textSize(80);
	text("<SHIFT>戻る", 50, 160);
}
void GATYA::gatyaimg() {
	rectMode(CENTER);
	imageColor(255, 255, 255);
	image(Gatya.img, width / 2, height / 2,0,2);
	rectMode(CORNER);
	fill(255, 255, 255);
	//ガチャボタン
	rect(720, 760, 400, 180);
	//戻るボタン
	rect(50, 50, 440, 160);

	fill(0, 0, 0);
	textSize(80);
	text("<ENTER>1回", 720, 880);
	text("<SHIFT>戻る", 50, 160);
	fill(255, 100, 100);
	textSize(120);
	text("ガチャガチャ", 580, 360);
}
void GATYA::nextScene(){
	if (isTrigger(KEY_SHIFT)) {
		game()->trans()->outTrigger();
	}
	if (game()->trans()->outEndFlag()) {
		game()->setCurScene(game()->cerect());

	}
}
#include"CONTAINER.h"
#include"GAME.h"
#include "FOURAN.h"
#include"libOne.h"
FOURAN::FOURAN(class GAME*game):
	GAME_OBJECT(game){
}
FOURAN::~FOURAN(){}
void FOURAN::create(){
	FouRan = game()->container()->fouran();
}
void FOURAN::init(){
	FouRan.pos = game()->container()->fouran().pos;
}
void FOURAN::update(){}
void FOURAN::move(){}
void FOURAN::launch(){}
void FOURAN::collision(){}
void FOURAN::draw(){
	imageColor(FouRan.color);
	rectMode(CORNER);
	FouRan.anim->draw(&FouRan.animData, FouRan.pos.x, FouRan.pos.y, 0, 2);
	fill(225, 225, 225, 200);
	rect(0, FouRan.pos.y + 300, 1920, 10);
}
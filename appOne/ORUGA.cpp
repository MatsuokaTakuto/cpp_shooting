#include"CONTAINER.h"
#include"GAME.h"
#include "ORUGA.h"
#include"libOne.h"
ORUGA::ORUGA(class GAME* game) :
	GAME_OBJECT(game) {
}
ORUGA::~ORUGA() {}
void ORUGA::create() {
	Oruga = game()->container()->oruga();
}
void ORUGA::init() {
	Oruga.pos = game()->container()->oruga().pos;
}
void ORUGA::update() {}
void ORUGA::move() {}
void ORUGA::launch() {}
void ORUGA::collision() {}
void ORUGA::draw() {
	imageColor(Oruga.color);
	rectMode(CENTER);
	Oruga.anim->noLoop();
	Oruga.anim->draw(&Oruga.animData, Oruga.pos.x, Oruga.pos.y, 0, 2);
}
void ORUGA::set() {
	Oruga.animData.reset();
}

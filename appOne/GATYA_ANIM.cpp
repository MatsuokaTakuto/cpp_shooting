#include "GATYA_ANIM.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"libOne.h"
GATYA_ANIM::GATYA_ANIM(class GAME* game) :
	GAME_OBJECT(game) {
}
GATYA_ANIM::~GATYA_ANIM() {}
void GATYA_ANIM::create() {
	GatyaAnim = game()->container()->gatyaanim();
}
void GATYA_ANIM::init() {
	GatyaAnim.pos = game()->container()->gatyaanim().pos;
}
void GATYA_ANIM::update() {}
void GATYA_ANIM::move() {}
void GATYA_ANIM::launch() {}
void GATYA_ANIM::collision() {}
void GATYA_ANIM::draw() {
	imageColor(GatyaAnim.color);
	rectMode(CENTER);
	GatyaAnim.anim->noLoop();
	GatyaAnim.anim->draw(&GatyaAnim.animData, GatyaAnim.pos.x, GatyaAnim.pos.y, 0, 2);
}
void GATYA_ANIM::set() {
	GatyaAnim.animData.reset();
}

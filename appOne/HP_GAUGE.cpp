#include "HP_GAUGE.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"libOne.h";
HP_GAUGE::HP_GAUGE(class GAME* game) :
	GAME_OBJECT(game) {

}
void HP_GAUGE::create() {
	HpGauge = game()->container()->hpGauge();

}
void HP_GAUGE::draw(VECTOR2 pos, VECTOR2 ofst, int hp,int color) {
	if (color == 1) {
		fill(HpGauge.safeColor);
	}
	else if (color == 2) {
		fill(0, 0, 255);
	}
	else {
		fill(HpGauge.dangerColor);
	}
	pos += ofst;
	strokeWeight(10);
	stroke(155, 155, 155);
	rect(pos.x, pos.y, hp * HpGauge.coWidth, HpGauge.hi);
}
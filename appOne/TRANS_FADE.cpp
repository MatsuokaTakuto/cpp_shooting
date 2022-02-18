#include"libOne.h"
#include"GAME.h"
#include "TRANS_FADE.h"
TRANS_FADE::TRANS_FADE(class GAME* game)
	:TRANS(game) {

}
void TRANS_FADE::create() {
	colorMode(RGB, 255);
	Trans.color = COLOR(0, 0, 0);
	Trans.time = 0.7f;
}
void TRANS_FADE::inTriggerProc() {
	rectMode(CORNER);
	colorMode(RGB, 255);
	noStroke();
	Trans.color.a = 255;
	fill(Trans.color);
	rect(0, 0, width, height);
}
bool TRANS_FADE::inProc() {
	rectMode(CORNER);
	colorMode(RGB, 255);
	noStroke();
	fill(Trans.color);
	rect(0, 0, width, height);
	Trans.color.a -= 255 / Trans.time * delta;
	if (Trans.color.a < 0.0f) {
		return true;
	}
	return false;
}
void TRANS_FADE::outTriggerProc() {
	Trans.color.a = 0.0f;
}
bool TRANS_FADE::outProc() {
	rectMode(CORNER);
	colorMode(RGB, 255);
	noStroke();
	fill(Trans.color);
	rect(0, 0, width, height);
	Trans.color.a += 255 / Trans.time * delta;
	if (Trans.color.a >= 255) {
		return true;
	}
	return false;
}

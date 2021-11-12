#include "STAGE.h"
#include"GAME.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"libOne.h"
STAGE::STAGE(class GAME* game):
	SCENE(game){
}
STAGE::~STAGE(){
}
void STAGE::init() {
	game()->player()->init();
	game()->enemies()->init();
}
void STAGE::update() {
	game()->player()->update();
	game()->enemies()->update();
	///////////////////
}
void STAGE::draw() {
	clear();
	game()->player()->draw();
	game()->enemies()->draw();
}
void STAGE::nextScene() {
	if (isTrigger(KEY_X)) {
		game()->changeScene(GAME::GAME_CLEAR_ID);
	}
	else if (isTrigger(KEY_C)) {
		game()->changeScene(GAME::GAME_OVER_ID);
	}
}
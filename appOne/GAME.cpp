#include"libOne.h"
#include"GAME.h"
#include"TITLE.h"
#include"CONTAINER.h"
GAME::GAME() {
	Container = new CONTAINER;
	Scenes[TITLE_ID] = new TITLE(this);
}
GAME::~GAME() {
	for (int i = 0; i < NUM_SCENES; i++) {
		delete Scenes[i];
	}
	delete Container;
}
void GAME::run() {
	window(1920, 1080, full);
	initDeltaTime();
	while (notQuit) {

	}
}
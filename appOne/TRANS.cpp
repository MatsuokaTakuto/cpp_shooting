#include"GAME.h"
#include "TRANS.h"
TRANS::TRANS(class GAME* game)
	:GAME_OBJECT(game)
	, State(STATE::OUT_END) {

}
TRANS::~TRANS() {

}
void TRANS::inTrigger() {
	if (State == STATE::OUT_END) {
		State = STATE::IN_TRIGGER;
	}
}
void TRANS::outTrigger() {
	if (State == STATE::IN_END) {
		State = STATE::OUT_TRIGGER;
	}
}
void TRANS::draw() {
	if (State == STATE::IN_END ||
		State == STATE::OUT_END) {
		return;
	}
	switch (State)
	{
	case STATE::IN_TRIGGER:
		inTriggerProc();
		State = STATE::IN_NOW;
		break;
	case STATE::IN_NOW:
		if (inProc()) {
			State = STATE::IN_END;
		}
		break;
	case STATE::OUT_TRIGGER:
		outTriggerProc();
		State = STATE::OUT_NOW;
		break;
	case STATE::OUT_NOW:
		if (outProc()) {
			State = STATE::OUT_END;
		}
		break;
	}
}

void TRANS::create() {
}
void TRANS::inTriggerProc() {
}
bool TRANS::inProc() {
	return true;
}
void TRANS::outTriggerProc() {
}
bool TRANS::outProc() {
	return true;
}

bool TRANS::inEndFlag() {
	return (State == STATE::IN_END);
}
bool TRANS::outEndFlag() {
	return (State == STATE::OUT_END);
}


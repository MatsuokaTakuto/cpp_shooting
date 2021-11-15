#pragma once
#include"TITLE.h"
class CONTAINER {
	struct DATA {
		TITLE::DATA title;
	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();
	const TITLE::DATA& title() { return Data.title; }
};
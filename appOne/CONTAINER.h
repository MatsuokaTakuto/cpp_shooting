#pragma once
#include"TITLE.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BULLETS.h"
class CONTAINER
{
	struct DATA {
		TITLE::DATA title;
		PLAYER::DATA player;
		ENEMIES::DATA enemy;
		BULLETS::DATA playerBullet;
	};
	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();
	const TITLE::DATA& title() { return Data.title; }
	const PLAYER::DATA& player() { return Data.player; }
	const ENEMIES::DATA& enemy() { return Data.enemy; }
	const BULLETS::DATA& playerBullet() { return Data.playerBullet; }
};

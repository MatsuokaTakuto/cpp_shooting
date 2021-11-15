#include "CONTAINER.h"
void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	Data.title.backColor = COLOR(255, 255, 255);
	Data.title.textCulor = COLOR(255, 100, 0);
	Data.title.textSize = 400;
	Data.title.pos.x = 50;
	Data.title.pos.y = 700;
	strcpy_s(Data.title.str, "VENGENCE");
}
void CONTAINER::loadGraphic() {

}
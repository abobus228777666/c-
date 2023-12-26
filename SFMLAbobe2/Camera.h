#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;
using namespace std;

const int LEFT_BORDER = 400;
const int RIGHT_BORDER = 860;
const int UP_BORDER = 250;
const int DOWN_BORDER = 470;

class Camera {
private:
	View view;
	Player* player;
	void setCenter();
	void init();
public:
	Camera(Player* player);
	void update();
	View getView();
};
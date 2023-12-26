#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int WIDTH_MAP_TILE = 64;
const int HEIGHT_MAP_TILE = 64;

class Player
{
private:
    float x, y;

public:
    String file_name;
    Image image;
    Texture texture;
    Sprite sprite;
    float width, height;
    int direction;
    float speed;
    float dx, dy;

    void interactionWithMap() {
        for (int i = y / HEIGHT_MAP_TILE; i < (y + height) / HEIGHT_MAP_TILE; i++) {
            for (int j = x / WIDTH_MAP_TILE; j < (x + width) / WIDTH_MAP_TILE; j++) {
                if (TileMap[i][j] == 's') {
                    if (dy > 0) {
                        y = i * HEIGHT_MAP_TILE - height;
                    }
                    if (dy < 0) {
                        y = i * HEIGHT_MAP_TILE + HEIGHT_MAP_TILE;
                    }
                    if (dx > 0) {
                        x = j * WIDTH_MAP_TILE - width;
                    }
                    if (dx < 0) {
                        x = j * WIDTH_MAP_TILE + WIDTH_MAP_TILE;
                    }
                }
               /* if (TileMap[i][j] == 'h') {

                }
                if (TileMap[i][j] == 'l') {

                }*/
            }
        }
    }

    Player(String F, float X, float Y, float W, float H)
    {
        file_name = F;
        x = X;
        y = Y;
        width = W;
        height = H;
        dx = 0;
        dy = 0;
        speed = 0;
        direction = 0;
        image.loadFromFile(file_name);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0, 0, width, height));
        sprite.setPosition(x, y);
    }

    void update(float time)
    {
        switch (direction)
        {
        case 0:
            dx = speed;
            dy = 0;
            break;
        case 1:
            dx = -speed;
            dy = 0;
            break;
        case 2:
            dx = 0;
            dy = speed;
            break;
        case 3:
            dx = 0;
            dy = -speed;
            break;
        }
        x += dx * time;
        y += dy * time;

        speed = 0;
        interactionWithMap();
        sprite.setPosition(x, y);
    }

    float getPlayerX()
    {
        return x;
    }
    float getPlayerY()
    {
        return y;
    }
};
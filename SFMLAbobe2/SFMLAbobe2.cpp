#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Camera.h"



using namespace sf;
using namespace std;
View view;

void view_map(float time)
{
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        view.move(0.0001 * time, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        view.move(-0.0001 * time, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        view.move(0, 0.0001 * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        view.move(0, -0.0001 * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::E)) {
        view.rotate(0.0001 * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        view.rotate(-0.0001 * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::F)) {
        view.zoom(1.0100f);
    }
    if (Keyboard::isKeyPressed(Keyboard::R)) {
        view.zoom(0.9f);
    }
    if (Keyboard::isKeyPressed(Keyboard::I)){
        view.setSize(640, 480);
    }
}

void getPlayerCoordinateForView(float x, float y)
{
    view.setCenter(x + 100, y);
}

const int HEIGHT_MAP = 8;
const int WIDTH_MAP = 10;
String TileMap[HEIGHT_MAP] = {

"ssssssssss",

"sggggggggs",

"sgghgggggs",

"sggggggggs",

"sggggggggs",

"sggggglggs",

"sggggggggs",

"ssssssssss"

};

int main()
{
    Image map_image;
    map_image.loadFromFile("map.png");
    Texture map_texture;
    map_texture.loadFromImage(map_image);
    Sprite map_sprite;
    map_sprite.setTexture(map_texture);
    Player player1("horse.png", 100, 100, 80, 80);

    Clock clock;
    sf::RenderWindow window(sf::VideoMode(512, 480), "SFML works!");
    view.reset(FloatRect(0, 0, 640, 480));
    RectangleShape ground(Vector2f(680, 250));
    Image hero_image;
    hero_image.loadFromFile("horse.png");
    Texture hero_texture;
    hero_texture.loadFromImage(hero_image);
    Sprite hero_sprite;
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setPosition(50, 25);
    hero_sprite.setTextureRect(IntRect(0, 0, 80, 80));
    float speed = 0.5;
    float direction = -1;
    float current_rec = 0;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            player1.direction = 0;
            player1.speed = 0.0001;
            current_rec++;
            if (current_rec > 3)
                current_rec = 0;
            player1.sprite.setTextureRect(IntRect(int(80 * current_rec), 160, 80, 80));
            getPlayerCoordinateForView(player1.getPlayerX(), player1.getPlayerY());
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            player1.direction = 1;
            player1.speed = 0.0001;
            current_rec++;
            if (current_rec > 3)
                current_rec = 1;
            player1.sprite.setTextureRect(IntRect(int(80 * current_rec), 80, 80, 80));
            getPlayerCoordinateForView(player1.getPlayerX(), player1.getPlayerY());
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            player1.direction = 3;
            player1.speed = 0.0001;
            current_rec++;
            if (current_rec > 3)
                current_rec = 1;
            player1.sprite.setTextureRect(IntRect(int(80 * current_rec), 240, 80, 80));
            getPlayerCoordinateForView(player1.getPlayerX(), player1.getPlayerY());
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            player1.direction = 2;
            player1.speed = 0.0001;
            current_rec++;
            if (current_rec > 3)
                current_rec = 1;
            player1.sprite.setTextureRect(IntRect(int(80 * current_rec), 0, 80, 80));
            getPlayerCoordinateForView(player1.getPlayerX(), player1.getPlayerY());
        }
        window.setView(view);
        player1.update(time);
        view_map(time);
        window.clear(Color(213,186,139));
        for (int x = 0; x < HEIGHT_MAP; x++) {
            for (int y = 0; y < WIDTH_MAP; y++) {
                if (TileMap[x][y] == 'h') {
                    map_sprite.setTextureRect(IntRect(64 * 0, 0, 64, 64));
                }
                if (TileMap[x][y] == 'g'){
                    map_sprite.setTextureRect(IntRect(64 * 1, 0, 64, 64));
                }
                if (TileMap[x][y] == 'l') {
                    map_sprite.setTextureRect(IntRect(64 * 2, 0, 64, 64));
                }
                if (TileMap[x][y] == 's') {
                    map_sprite.setTextureRect(IntRect(64 * 3, 0, 64, 64));
                }
                map_sprite.setPosition(x * 64, y * 64);
                window.draw(map_sprite);
            }
        }
        window.draw(player1.sprite);
        window.display();
    }

    return 0;
}
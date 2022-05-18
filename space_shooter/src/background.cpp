/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** background
*/

#include "game.hpp"

parallax::parallax()
{
    IntRect rect(0, -1080, 1920, 1080 * 2);
    _texture[0].loadFromFile("assets/texture/background/background.png", rect);
    _texture[1].loadFromFile("assets/texture/background/big_planet.png", rect);
    _texture[2].loadFromFile("assets/texture/background/stars.png", rect);
    _texture[3].loadFromFile("assets/texture/background/two_planet.png", rect);
    for (int i = 0; i < 4; i++) {
        _texture[i].setRepeated(true);
        _sprite[i].setTexture(_texture[i]);
        _sprite[i].setTextureRect(rect);
        _sprite[i].setPosition(0, -1080);
    }
}

void parallax::moove_background(float _dt)
{
    for (int i = 0; i < 4; i++)
        _sprite[i].move(0, (100 + (i * 100)) * _dt);
}

void parallax::update(float _dt)
{
    moove_background(_dt);
    for (auto &i : _sprite) {
        if (i.getPosition().y > 0) {
            i.setPosition(0, -WINDOW_HEIGHT);
        }
    }
}

void parallax::draw(RenderWindow *_window)
{
    for (auto &i : _sprite)
        _window->draw(i);
}


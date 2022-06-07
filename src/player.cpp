/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** player
*/

#include "game.hpp"

player::player()
{
    _shootclock.restart();
    _speed = 500;
    atkspeed = 0.5;
    _texture.loadFromFile("assets/texture/shooter/chara.png");
    _player.setTexture(_texture);
    _player.setPosition(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    _player.setTextureRect(IntRect(69, 93, 83, 67));
    _player.setScale(1.5, 1.5);
}

void player::draw(RenderWindow *_window)
{
    _window->draw(_player);
}

void player::moove_player(float _dt)
{
    bool moveLeft = Keyboard::isKeyPressed(Keyboard::Q) && _player.getPosition().x >= 0;
    bool moveRight = Keyboard::isKeyPressed(Keyboard::D) && _player.getPosition().x <= WINDOW_WIDTH - _player.getGlobalBounds().width;
    bool moveUp = Keyboard::isKeyPressed(Keyboard::Z) && _player.getPosition().y >= 0;
    bool moveDown = Keyboard::isKeyPressed(Keyboard::S) && _player.getPosition().y <= WINDOW_HEIGHT - _player.getGlobalBounds().height - 120;
    _player.move((-moveLeft + moveRight) * _speed * _dt, (-moveUp + moveDown) * _speed * _dt);
}

void player::update(float _dt)
{
    if (_shootclock.getElapsedTime().asSeconds() > atkspeed) {
        _shootclock.restart();
    }
    moove_player(_dt);
}

void player::handle_events()
{
}

Sprite player::get_sprite()
{
    return _player;
}
/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** enemy
*/

#include "game.hpp"

enemy::enemy()
{
    IntRect rect(460, 203, 217, 230);
    _texture.loadFromFile("assets/texture/shooter/enemy_spritesheet.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(rect);
    _sprite.rotate(180);
    _sprite.setPosition(rand() % WINDOW_WIDTH, 250);
    _hp = 1;
    _speed = 500;
    atkspeed = 0.5;
}

void enemy::draw(RenderWindow *_window)
{
    _window->draw(_sprite);
}

void enemy::moove_enemy(float _dt, Sprite _player)
{
    if (_sprite.getPosition().x >= _player.getPosition().x + _player.getGlobalBounds().width) {
        _velocity.x += -1;
    }
    if (_sprite.getPosition().x <= _player.getPosition().x + _player.getGlobalBounds().width) {
        _velocity.x += 1;
    }
    _sprite.move(_velocity.x * _dt, _velocity.y * _dt);
}

void enemy::update(float _dt, Sprite _player)
{
    if (_shootclock.getElapsedTime().asSeconds() > atkspeed) {
        _shootclock.restart();
    }
    moove_enemy(_dt, _player);
}
/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** interface
*/

#include "game.hpp"

interface::interface()
{
    _heart_texture.loadFromFile("assets/texture/interface/heart_spritesheet.png");
    for (int i = 0; i < _hp; i++) {
        hp_point point;
        point._sprite.setTexture(_heart_texture);
        point._sprite.setTextureRect(_heart_rect);
        point._sprite.setScale(0.3, 0.3);
        _heart.push_back(point);
    }

}

void interface::remove_hp(RenderWindow *window, unsigned short hp)
{
    if (_heart.size() == 1) {
        window->close();
    }
    for (int i = 0; i < hp; i++)
        _heart.pop_back();
}

void interface::add_hp(unsigned short hp) {
    for (int i = 0; i < hp; i++) {
        hp_point point;
        point._sprite.setTexture(_heart_texture);
        point._sprite.setTextureRect(_heart_rect);
        point._sprite.setScale(0.3, 0.3);
        _heart.push_back(point);
    }
}

void interface::set_hp(RenderWindow *_window, unsigned short hp) {
    while (_heart.size() > hp) {
        remove_hp(_window, 1);
    }
    while (_heart.size() < hp) {
        add_hp(1);
    }
}

void interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (int i = 0; i < _heart.size(); i++) {
        target.draw(_heart[i]._sprite);
    }
}

void interface::update(float _dt)
{
    for (int i = 0; i < _heart.size(); i++) {
    _heart[i]._sprite.setPosition(Vector2f(i * (_heart[i]._sprite.getGlobalBounds().width + 5), 0));
    }
}

void interface::handle_events(Event _event)
{
}
/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** game
*/

#include "game.hpp"

game::game()
{
    _window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, WINDOW_STYLE);
    _window->setFramerateLimit(WINDOW_FPS);
}

game::~game()
{
    delete _window;
}

void game::update()
{
    handle_events();
    _dt = _dtclock.restart().asSeconds();
    _player.update(_dt);
    _parallax.update(_dt);
    _interface.update(_dt);
    _enemy.update(_dt, _player.get_sprite());
}

void game::draw()
{
    _window->clear(Color::Black);
    _parallax.draw(_window);
    _player.draw(_window);
    _window->draw(_interface);
    _enemy.draw(_window);
    _window->display();
}

void game::handle_events()
{
    while (_window->pollEvent(_event)) {
        if (_event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
            _window->close();
        _player.handle_events();
    }
}

void game::run()
{
    while (_window->isOpen()) {
        update();
        draw();
    }
}
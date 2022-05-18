/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_
    #define WINDOW_WIDTH    1920
    #define WINDOW_HEIGHT   1080
    #define WINDOW_TITLE    "OnO"
    #define WINDOW_STYLE    Style::Default
    #define WINDOW_FPS      144
    #include "include_sfml.hpp"
    #include "interface.hpp"
    #include "background.hpp"
    #include "player.hpp"
    #include "enemy.hpp"

    class game {
        public:
            game();
            virtual ~game();

            player _player;
            interface _interface;
            enemy _enemy;
            parallax _parallax;


            void run();
            void update();
            void draw();
            void handle_events();
        private:
            RenderWindow *_window;
            Event _event;
            Clock _dtclock;
            float _dt;
    };


#endif /* !GAME_HPP_ */

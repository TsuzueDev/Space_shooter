/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_
    #include "game.hpp"

    class player {
        public :
            player();
            virtual ~player() = default;
            void update(float _dt);
            void draw(RenderWindow *_window);
            void handle_events();
            void moove_player(float _dt);
            Sprite get_sprite();
        private :
            Clock _shootclock;
            Sprite _player;
            Texture _texture;
            float _speed;
            float atkspeed;
    };


#endif /* !PLAYER_HPP_ */

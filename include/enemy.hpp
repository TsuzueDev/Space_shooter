/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** enemy
*/

#ifndef ENEMY_HPP_
    #define ENEMY_HPP_
    #include "game.hpp"

    typedef struct {
        sf::Sprite _sprite;
        unsigned short _hp;
        Clock _clock;
    } enemy_struct;

    class enemy {
        public :
            enemy();
            virtual ~enemy() = default;
            void update(float _dt, Sprite _player);
            void draw(RenderWindow *_window);
            void handle_events();
            void moove_enemy(float _dt, Sprite _player);
        private :
            Clock _shootclock;
            Sprite _sprite;
            Vector2f _velocity = {0, 0};
            Texture _texture;
            unsigned short _hp;
            unsigned short _speed;
            float atkspeed;
    };


#endif /* !ENEMY_HPP_ */

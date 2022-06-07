/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** background
*/

#ifndef BACKGROUND_HPP_
    #define BACKGROUND_HPP_
    #include "game.hpp"

    class parallax {
        public :
            parallax();
            virtual ~parallax() = default;
            void update(float _dt);
            void draw(RenderWindow *_window);
            void handle_events();
            void moove_background(float _dt);
        private :
            Sprite _sprite[4];
            Texture _texture[4];
            float _speed;
    };


#endif /* !BACKGROUND_HPP_ */

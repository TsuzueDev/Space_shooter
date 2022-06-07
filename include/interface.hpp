/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** interface
*/

#include "game.hpp"

#ifndef INTERFACE_HPP_
    #define INTERFACE_HPP_

    typedef struct {
        sf::Sprite _sprite;
    } hp_point;

    class interface : public sf::Drawable {
        public :
            interface();
            ~interface() = default;
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            void update(float _dt);
            void handle_events(Event _event);

            void set_hp(RenderWindow *_window, unsigned short _hp);
            void add_hp(unsigned short _hp);
            void remove_hp(RenderWindow *_window, unsigned short hp);
        private :
            unsigned short int _hp  {4};
            vector<hp_point> _heart;
            Texture _heart_texture;
            IntRect _heart_rect = {16, 44, 264, 230};
    };




#endif /* !INTERFACE_HPP_ */

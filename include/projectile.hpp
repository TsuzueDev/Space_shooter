/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** projectile
*/

#ifndef PROJECTILE_HPP_
    #define PROJECTILE_HPP_
    #include "game.hpp"

    typedef struct {
        Sprite _sprite;
        Vector2f _movement;
    } shoot;

    class Projectile {
        public :
            Projectile();
            virtual ~Projectile() = default;
            void update(float _dt);
            void draw(RenderWindow *_window);
            void create_projectile(Vector2f movement, float inclinaison);
        private :
            vector<shoot> _projectiles;
            Texture _texture;
            IntRect rect[7] {
                IntRect {0, 0, 0, 0},
                IntRect {0, 0, 0, 0},
                IntRect {0, 0, 0, 0},
                IntRect {0, 0, 0, 0},
                IntRect {0, 0, 0, 0},
                IntRect {0, 0, 0, 0},
                IntRect {0, 0, 0, 0},
            };
    };


#endif /* !PROJECTILE_HPP_ */

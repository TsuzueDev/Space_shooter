/*
** EPITECH PROJECT, 2022
** space_shooter
** File description:
** projectile
*/

#include "game.hpp"

Projectile::Projectile()
{
    _texture.loadFromFile("assets/texture/projectile/projectile.png");
}

void Projectile::create_projectile(Vector2f moove, float inclinaison)
{
    shoot projectile;
    projectile._movement = moove;
    projectile._sprite.setTexture(_texture);
    
}
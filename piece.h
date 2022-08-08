#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <iostream>

#include "board.h"

class Piece: public sf::Drawable{
    protected:
    sf::RectangleShape piece;

    public:
    Piece()=default;
    virtual ~Piece();
    
        ////GETTERS////
    virtual sf::FloatRect getBounds()=0;
    virtual sf::Vector2f getPos()=0;

    virtual void posibleMove(std::vector<Board>& b)=0;
    virtual void checkMove(sf::Vector2f& mousePos,sf::Vector2f& oldPos,std::vector<Board>& b)=0;


    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
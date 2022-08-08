#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "board.h"

using namespace sf;



class King: public sf::Drawable{
    ////VARIABLE////
    sf::RectangleShape piece;
        Texture t1;
        Texture t2;

    public:
    ////CONSTRUCOTRS & DESTRUCTOR
    King(bool isBlack);
    King()=delete;
    ~King()=default;

    ////GETTERS////
    sf::FloatRect getBounds();
    sf::Vector2f getPos();

    ////DRAWING GREEN CELLS and MOVING PIECES ONLY to GREEN CELLS
    void posibleMove(std::vector<Board>& b);
    void checkMove(Vector2f& mousePos,Vector2f& oldPos,std::vector<Board>& b);
    
    ////Virtula function to draw objcets////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
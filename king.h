#pragma once

#include "piece.h"
#include "board.h"

using namespace sf;



class King: public Piece{

    ////VARIABLE////
        Texture t1;
        Texture t2;

    public:
    ////CONSTRUCOTRS & DESTRUCTOR
    King(bool isBlack);
    King()=delete;
    ~King()=default;

            ////GETTERS////
    virtual sf::FloatRect getBounds();
    virtual sf::Vector2f getPos();

    ////DRAWING GREEN CELLS and MOVING PIECES ONLY to GREEN CELLS
    virtual void posibleMove(std::vector<Board>& b);
    virtual void checkMove(Vector2f& mousePos,Vector2f& oldPos,std::vector<Board>& b);

    ////Virtula function to draw objcets////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
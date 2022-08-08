#pragma once

#include <SFML/Graphics.hpp>


using namespace sf;

class Board: public Drawable{
        ////VARIABLES////
        RectangleShape rectangle;
        Vector2i position;
        Vector2f size{80.0f,80.0f};
        bool is_occupied=false;

        public:
        ////CONSTRUCTOR & DESTRUCTORS////
        Board(float t);
        ~Board()=default;

        ////SETERS////
        void setBoard(int color,float x,float y);
        void setPosition(Vector2f _position);
        void setColorGreen();

        ////GETERS////
        sf::FloatRect getBounds();
        sf::Vector2f getOrigin();
        sf::Color getColorGren();
        sf::Vector2f getPos();

        ////FUNCTIONS for GAME////
        void changeOccupied(bool _is_occupied);

        ////Virtula function to draw objcets////
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

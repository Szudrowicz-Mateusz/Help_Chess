#include "board.h"

Board::Board(float t){
    rectangle.setSize(size);  
}

////SETERS////
void Board::setBoard(int color,float x,float y){
    if(color==0) rectangle.setFillColor(Color::Cyan);
    if(color==1) rectangle.setFillColor(Color::Blue);

    Vector2f position{x,y};

    rectangle.setPosition(position);
    rectangle.setOrigin(size/2.0f);

}
void Board::setColorGreen()
{
    rectangle.setFillColor(Color::Green);
}
void Board::setPosition(Vector2f _position)
{
    rectangle.setPosition(_position);
}

////GETERS////
sf::FloatRect Board::getBounds()
{
    return rectangle.getGlobalBounds();
}
sf::Vector2f Board::getOrigin()
{
    return rectangle.getOrigin();
}
sf::Vector2f Board::getPos()
{
    return rectangle.getPosition();
}
sf::Color Board::getColorGren()
{
    return rectangle.getFillColor();
}

////FUNCTIONS for GAME////
void Board::changeOccupied(bool _is_occupied){
    if(_is_occupied==true) this->is_occupied=true;
    else this->is_occupied=false;
}

void Board::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(rectangle,states);
}
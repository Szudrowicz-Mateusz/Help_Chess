#include "piece.h"

Piece::~Piece(){
    ///Nothing
}

void Piece::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(piece,states);
}
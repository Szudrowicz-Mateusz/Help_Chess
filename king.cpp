#include "king.h"
#include "board.h"

King::King(bool isBlack)
{
    Vector2f size{60.f,60.f};
    Vector2f origin{30.f,30.f};

    piece.setSize(size);
    piece.setOrigin(origin);
    if(isBlack==true) 
    {
        t1.loadFromFile("Images/Krol_C.png");

        piece.setPosition(405.f,50.f);
        piece.setTexture(&t1);
    }
    else 
    {
        t2.loadFromFile("Images/Krol_B.png");

        piece.setTexture(&t2);
        piece.setPosition(405.f,610.f);
    }

}

sf::FloatRect King::getBounds()
{
    return piece.getGlobalBounds();
}
sf::Vector2f King::getPos()
{
    return piece.getPosition();
}

/*////DRAWING GREEN CELLS and MOVING PIECES ONLY to GREEN CELLS////
    main idea is that we change color of the cells that our piece can move
    after that we check if our mouse are pointing to cell we get position of cell
    and set newPos to our piece
*/
void King::posibleMove(std::vector<Board>& b)
{
    Vector2f pos=piece.getPosition();
    float pos_x=pos.x;
    float pos_y=pos.y;

    for(auto& element: b)
    {   
       Vector2f posB=element.getPos();
        float posB_x=posB.x;
        float posB_y=posB.y;
                            ///Sides///
        if(posB_x-pos_x==80&&posB_y-pos_y==0) element.setColorGreen();
        else if(pos_x-posB_x==80&&pos_y-posB_y==0) element.setColorGreen();
        else if(posB_y-pos_y==80&&posB_x-pos_x==0) element.setColorGreen();
        else if(pos_y-posB_y==80&&pos_x-posB_x==0) element.setColorGreen();

                            ///Cornerns///
        if(posB_x-pos_x==80&&posB_y-pos_y==80) element.setColorGreen(); //Down Right
        else if(pos_x-posB_x==80&&posB_y-pos_y==80) element.setColorGreen(); //Down Left
        else if(pos_x-posB_x==80&&pos_y-posB_y==80) element.setColorGreen(); //Top Left
        else if(posB_x-pos_x==80&&pos_y-posB_y==80) element.setColorGreen(); //Top Right
        
    }
}
void King::checkMove(Vector2f& mousePos,Vector2f& oldPos,std::vector<Board>& b)
{
    short int i=0;
    for(auto& element : b)
    {
        if(element.getColorGren()==sf::Color::Green)
        {
            if(element.getBounds().contains(mousePos))
            {
            Vector2f newPos=element.getPos();
            piece.setPosition(newPos);
            element.changeOccupied(true);
            i=1;
            }
        }
    }
    if(i!=1) piece.setPosition(oldPos);
    else for(auto& element : b) if(element.getBounds().contains(oldPos)) element.changeOccupied(false);


}



void King::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(piece,states);
}
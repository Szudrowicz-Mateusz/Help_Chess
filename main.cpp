#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

#include "piece.h"
#include "board.h"
#include "king.h"

using namespace sf;

std::vector<Board> board{1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,
                        1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,
                        1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,
                        1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,
                        1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,
                        1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,
                        1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f,
                        1.f,1.f,1.f,1.f,1.f,1.f,1.f,1.f};

void creatBoard(std::vector<Board>& board)
{
    int color;
    float x=85;
    float y=50;

        for(int i=0;i<=31;i++)
        {
            if(i%2==0) color=0;
            else color=1;
        //board.push_back(1.0f);
        board.at(i).setBoard(color,x,y);
        x=x+80;
        if(x==725)
        {
            x=85;
            y=y+160;
        }
        }




        y=130;
                for(int i=32;i<=63;i++)
        {
            if(i%2==0) color=1;
            else color=0;
        //board.push_back(1.0f);
        board.at(i).setBoard(color,x,y);
        x=x+80;
        if(x==725)
        {
            x=85;
            y=y+160;
        }
        }

}

std::vector<Piece*> w_pieces;
std::vector<Piece*> b_pieces;

int x=800,y=800;

int main()
{ 
    ////WINDOW////
    RenderWindow window{VideoMode(x,y),"Chess"};
    window.setFramerateLimit(60);

    ////VARIABLES////
    Event e;
    King b_king(true),w_king(false);

    bool isMove=false;
    sf::Vector2f oldPos;

    ////The try of Polymoprhism////
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! DIDN'T WORK !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Piece *wsk= new King(true); //Black king
    b_pieces.push_back(wsk);
    Piece *wsk2=new King(false); //White king
    w_pieces.push_back(wsk2);

    ////FUNCTIONS////
    creatBoard(board);

    while(window.isOpen())
    {
        /*
        Idea is that for evrey piece in my vector for white and black pieces
        the scope is checking that any of the piece are overlaped during press left button
        If(isTrue) we showing the green cells for posible moves
        After realesed button and get overlaped with green cells our piece change direction
        */
            for(long unsigned int i=0;i<w_pieces.size();i++)
            {    
          while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
            /////drag and drop///////
            //Draging
           
            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left)
                {
                    Vector2f mousePos=Vector2f(Mouse::getPosition(window));
                    //Checking if obcjet and mouse are overlaping
                  if (w_pieces.at(i)->getBounds().contains(mousePos))
                      {
                       isMove=true; 
                       oldPos  = w_pieces.at(i)->getPos();
                      }
                }
            //Droping
            //If we get chose the piece we can move our piece
            if(isMove==true)
            {
                //Draw green cells in order to get posibility
                w_pieces.at(i)->posibleMove(board);


             if (e.type == Event::MouseButtonReleased)
                if (e.key.code == Mouse::Left)
                 {
                  Vector2f newPos=Vector2f(Mouse::getPosition(window));
                  w_pieces.at(i)->checkMove(newPos,oldPos,board);
                  isMove=false;
                 }  
                  
            }   

            
                              
        }
                    std::cout<<"I went through scope "<<i<<std::endl;
            }


            window.clear(Color::Black);
           

            for(auto& b : board)
            {
                window.draw(b);
            }
            window.draw(w_king);
            window.draw(b_king);
            
            window.display();
            if(isMove==false) creatBoard(board);

    }


    delete wsk;
    delete wsk2;
    return 0;
}
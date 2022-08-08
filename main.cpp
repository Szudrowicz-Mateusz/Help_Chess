#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

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




int x=800,y=800;

int main()
{ 
    ////WINDOW////
    RenderWindow window{VideoMode(x,y),"Chess"};
    window.setFramerateLimit(60);

    ////VARIABLES////
    Event e;
    King b_king(true),w_king(false);

    ////FUNCTIONS////
    creatBoard(board);


bool isMove=false;
Vector2f oldPos;
    while(window.isOpen())
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
                  if (b_king.getBounds().contains(mousePos))
                      {
                       isMove=true; 
                       oldPos  = b_king.getPos();
                      }
                }
            //Droping
            //If we get chose the piece we can move our piece
            if(isMove==true)
            {
                //Draw green cells in order to get posibility
                b_king.posibleMove(board);
             if (e.type == Event::MouseButtonReleased)
                if (e.key.code == Mouse::Left)
                 {
                  isMove=false;
                  Vector2f newPos=Vector2f(Mouse::getPosition(window));
                  b_king.checkMove(newPos,oldPos,board);
                 }  
                  
            }                       
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



    return 0;
}
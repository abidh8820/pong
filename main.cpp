#include <SFML/Window/Keyboard.hpp>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

#define W_w 720
#define W_h 420

#define W_wh 360
#define W_hh 210
#define paddle_speed = 200

using namespace std;


int main() {
    sf::RenderWindow window(sf::VideoMode(W_w, W_h), "Pong", sf::Style::Titlebar);
    window.setPosition(sf::Vector2i(0, 0));
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Eror loading fonts" << endl;
    }
    window.setFramerateLimit(60);
    int player1score = 0;
    int player2score = 0;

    int p1y=30, p2y=W_h-90;
    int bx=W_wh, by=W_hh;
    sf::Font scorefont;
    if (!scorefont.loadFromFile("arial.ttf")) {
        cout << "Eror loading fonts" << endl;
    }
    int ix=1, iy=1, bi=2;
    while (window.isOpen()) {
        sf::Event evnt;

        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                p1y -=5;
                p1y=max(0,p1y);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                p1y+=5;
                p1y=min(p1y,370);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
                p2y -=6;
                p2y=max(0,p2y);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
                p2y+=6;
                p2y=min(p2y,370);
            }
        }

        if(by==0)iy*=-1;
        if(by==W_h-5)iy*=-1;
        if(bx>=10 && bx<=21 && by>=p1y && by<=p1y+50)ix*=-1;
        else if(bx>=W_w-25 && bx<=W_w-10 && by>=p2y && by<=p2y+50)ix*=-1;
        bx+=ix*bi, by+=iy*bi;
        by=max(by,0);
        by=min(by,W_h-5);
        window.clear(sf::Color::Black);

        sf::Text text;                  // initializing text class
        text.setFont(font);             // setiing the default font
        text.setString("Hello pong!");  // giving the text to print
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);
        text.setPosition(230, 180);
       // window.draw(text);  // draws the string to buffer
        
          
        sf::RectangleShape paddle1(sf::Vector2f(10, 50));
        paddle1.setPosition(10, p1y);
        paddle1.setFillColor(sf::Color::White);
        window.draw(paddle1);

        sf::RectangleShape paddle2(sf::Vector2f(10, 50));
        paddle2.setPosition(700,p2y );
        paddle2.setFillColor(sf::Color::White);
        window.draw(paddle2);

        sf::RectangleShape ball(sf::Vector2f(10, 10));
        ball.setPosition(bx, by);
        ball.setFillColor(sf::Color::White);
        window.draw(ball);

        window.display();  // displays the buffer
    }
}

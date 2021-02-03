#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>

#include "pong.h"
using namespace std;

int player1score = 0;
int player2score = 0;

int p1y = 30, p2y = W_h - 90;
int bx = W_wh, by = W_hh;

int ix = 1, iy = 1, bi = 5;
inline void checkclose() {
    sf::Event evnt;
    while (window.pollEvent(evnt)) {
        if (evnt.type == sf::Event::Closed) {
            window.close();
        }
    }
}
void score1(std::string p1s) { //prints p1's score
    sf::Text score;

    if (!font.loadFromFile("arial.ttf")) {
    }
    score.setFont(font);
    score.setString(p1s);
    score.setCharacterSize(30);
    score.setPosition(W_w * .3, W_h * .2);
    score.setFillColor(sf::Color::White);
    window.draw(score);
}
void score2(std::string p2s) { // prints p2's score
    sf::Text score;
    if (!font.loadFromFile("arial.ttf")) {
    }
    score.setFont(font);
    score.setString(p2s);
    score.setPosition(W_w * .7, W_h * .2);
    score.setCharacterSize(30);
    score.setFillColor(sf::Color::White);
    window.draw(score);
}
void game_state() {}

inline void ovo() { // one vs one game 
    while (true) {
        checkclose(); // checks wheather window is closed by the window menu button

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            p1y -= 10;
            p1y = max(0, p1y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            p1y += 10;                                             //changing
            p1y = min(p1y, W_h - 85);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {       // positions.
            p2y -= 10;
            p2y = max(0, p2y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            p2y += 10;
            p2y = min(p2y, W_h - 85);
        }

        if (by == 0) iy *= -1;
        if (by == W_h - 5) iy *= -1;
        if (bx < 0) {
            player2score++;
            bx = W_wh;
            by = W_hh;
            continue;
        }
        if (bx > W_w) {
            player1score++;
            bx = W_wh;
            by = W_hh;
        }
        if (player1score == 2 || player2score == 2) { // if one of the players hits the score limit
            sf::Text win;
            if (player1score == 2)
                win.setString("player 1 wins");
            else
                win.setString("player 2 wins");
            if (!font.loadFromFile("arial.ttf")) {
            }
            win.setFillColor(sf::Color::White);
            win.setCharacterSize(40);
            win.setFont(font);
            win.setPosition(W_w * .4, W_h * .45);
        
            while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) { //declaring the winner until the next game is on
                checkclose();
                window.clear(sf::Color::Black);
                window.draw(win);
                window.display();
            }
            player1score = player2score = 0;
            checkclose();
            return;
        }
        if (bx >= 10 && bx <= 21 && by >= p1y && by <= p1y + 85)
            ix = abs(ix);                          //changing the direction in x axis
        else if (bx >= W_w - 25 && bx <= W_w - 10 && by >= p2y && //x axis but opposite 
                 by <= p2y + 85)
            ix = -abs(ix);
        bx += ix * bi, by += iy * bi;

        by = max(by, 0);                  //setting limit for y , thus ball doesnt go beyond the window
        by = min(by, W_h - 5);

        window.clear(sf::Color::Black);
        score1(to_string(player1score));
        score2(to_string(player2score));
        draw(p1y, p2y, bx, by);              //drawing the game state
    }
}
int main() {
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);
    bool fx = false;
    while (window.isOpen()) {
        checkclose();
        while (true) {
            checkclose();
            init_state();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) break;
        }
        while(true)ovo();
          
    }
}

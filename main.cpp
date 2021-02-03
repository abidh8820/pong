#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "pong.h"
using namespace std;

inline void checkclose(){
            sf::Event evnt;
        while(window.pollEvent(evnt)){
            if(evnt.type==sf::Event::Closed){
                window.close();
            }
        }
}

void score1(std::string p1s) {
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
void score2(std::string p2s) {
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

int main() {
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);

    int player1score = 0;
    int player2score = 0;

    int p1y = 30, p2y = W_h - 90;
    int bx = W_wh, by = W_hh;

    int ix = 1, iy = 1, bi = 5;

    bool fx = false;
    while (window.isOpen()) {
        checkclose();
        while (true) {
            checkclose();
            init_state();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) break;
        }

        while (true) {
            
        f:

            checkclose();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                p1y -= 10;
                p1y = max(0, p1y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                p1y += 10;
                p1y = min(p1y, W_h - 85);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
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
                fx = true;
                goto f;
            }
            if (bx > W_w) {
                player1score++;
                bx = W_wh;
                by = W_hh;
                fx = true;
            }
            if (player1score == 2 || player2score == 2) {
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
                player1score = player2score = 0;

                checkclose();
                while (true) {
                    checkclose();
                    window.clear(sf::Color::Black);
                    window.draw(win);
                    window.display();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                        goto f;
                    }
                }
            }

            if (bx >= 10 && bx <= 21 && by >= p1y && by <= p1y + 85)
                ix = abs(ix);
            else if (bx >= W_w - 25 && bx <= W_w - 10 && by >= p2y &&
                     by <= p2y + 85)
                ix = -abs(ix);
            bx += ix * bi, by += iy * bi;

            by = max(by, 0);
            by = min(by, W_h - 5);

            window.clear(sf::Color::Black);
            score1(to_string(player1score));
            score2(to_string(player2score));
            draw(p1y, p2y, bx, by);
        }
    }
}

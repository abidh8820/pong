#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "pong.h"

using namespace std;

void game_state() {}

int main() {
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);
    int player1score = 0;
    int player2score = 0;

    int p1y = 30, p2y = W_h - 90;
    int bx = W_wh, by = W_hh;

    int ix = 1, iy = 1, bi = 2;

    bool fx = false;
    while (window.isOpen()) {
        sf::Event evnt;

        while (true) {
            init_state();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) break;
        }

        while (true) {
        f:

            while (fx) {
                window.clear(sf::Color::Black);
                draw(p1y, p2y, bx, by);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
                    fx=false;
                    break;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                p1y -= 5;
                p1y = max(0, p1y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                p1y += 5;
                p1y = min(p1y, 370);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
                p2y -= 6;
                p2y = max(0, p2y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                p2y += 6;
                p2y = min(p2y, 370);
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
                goto f;
            }

            if (bx >= 10 && bx <= 21 && by >= p1y && by <= p1y + 50)
                ix = abs(ix);
            else if (bx >= W_w - 25 && bx <= W_w - 10 && by >= p2y &&
                     by <= p2y + 50)
                ix = -abs(ix);
            bx += ix * bi, by += iy * bi;

            by = max(by, 0);
            by = min(by, W_h - 5);

            window.clear(sf::Color::Black);
            draw(p1y, p2y, bx, by);
        }
    }
}

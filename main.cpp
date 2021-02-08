#include <bits/stdc++.h>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "pong.h"
using namespace std;

int player1score = 0;
int player2score = 0;
int pry, ply;
int p1y = pry = 30, p2y = ply = W_h - 90;
int bx = W_wh, by = W_hh;

int ix = 1, iy = 1, bi = 4;
inline void checkclose() {
    bool idx = 1;
    while (true) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    idx = !idx;
                } else if (event.key.code == sf::Keyboard::Left) {
                    idx = !idx;
                }
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Return) {
                    if (idx == 0)
                        window.close();
                    else
                        return;
                }
            }
            window.clear(sf::Color::Black);
            check_quit(idx);
        }
    }
}
void gg() {
    bool flag = true;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) flag = false;
    if (flag) return;
    checkclose();
}
void score1(std::string p1s) {  // prints p1's score
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
void score2(std::string p2s) {  // prints p2's score
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

inline void vc() {
    player1score = player2score = 0;
    bx = W_wh;
    by = W_hh;

    bi = 5;
    ix = -1;
    while (true) {
        gg();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            p1y -= 10;
            p1y = max(0, p1y);
        }
        gg();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            p1y += 10;  // changing
            p1y = min(p1y, W_h - 85);
        }
        if (iy == 1) {
            if (W_w - bx > W_h - by) {
                p2y += 10;
                p2y = min(p2y, W_h - 100);
            } else {
                int ty = by + W_w - bx;
                if (ty < p2y) {
                    p2y -= 10;
                    p2y = max(ty - 40, p2y);
                    p2y = max(0, p2y);
                } else if (ty > p2y) {
                    p2y += 10;
                    p2y = min(p2y, ty - 40);
                    p2y = min(p2y, W_h - 85);
                }
            }
        } else if (iy == -1) {
            if (W_w - bx > by) {
                p2y -= 10;
                p2y = max(p2y, 30);
            } else {
                int ty = by - W_w + bx;
                if (ty < p2y) {
                    p2y -= 10;
                    p2y = max(ty - 40, p2y);
                    p2y = max(0, p2y);
                } else if (ty > p2y) {
                    p2y += 10;
                    p2y = min(p2y, ty - 40);
                    p2y = min(p2y, W_h - 85);
                }
            }
        }
        if (by == 0) iy *= -1;
        if (by == W_h - 5) iy *= -1;  // changing direction in y axis
        if (bx < 0) {                 // checking whether to add score
            player2score++;
            bi++;
            bi = min(bi, 8);
            bx = W_wh;
            by = W_hh;
            iy *= -1;
        }
        if (bx > W_w) {
            player1score++;
            bi++;
            bi = min(bi, 8);
            bx = W_wh;
            by = W_hh;
            iy *= -1;
        }
        gg();
        if (player1score == 5 ||
            player2score == 5) {  // if one of the players hits the score limit
            sf::Text win;
            if (player1score == 5)
                win.setString("You win");
            else
                win.setString("Computer wins");
            if (!font.loadFromFile("arial.ttf")) {
            }
            win.setFillColor(sf::Color::White);
            win.setCharacterSize(40);
            win.setFont(font);
            win.setPosition(W_w * .4, W_h * .45);
            sf::Event vnt;
            while (true) {  // declaring the winner until the next game
                window.clear(sf::Color::Black);
                window.draw(win);
                window.display();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) break;
            }
            player1score = player2score = 0;
            return;
        }
        if (bx >= 10 && bx <= 21 && by >= p1y && by <= p1y + 85)
            ix = abs(ix);  // changing the direction in x axis
        else if (bx >= W_w - 25 && bx <= W_w - 10 &&
                 by >= p2y &&  // x axis but opposite
                 by <= p2y + 85)
            ix = -abs(ix);
        bx += ix * bi, by += iy * bi;
        by = max(by, 0);
        by = min(by, W_h - 5);
        window.clear(sf::Color(0, 102, 53, 255));
        score1(to_string(player1score));
        score2(to_string(player2score));
        draw(p1y, p2y, bx, by);  // drawing the game state
    }
}
inline void tvt() {
    player1score = player2score = 0;
    bx = W_wh;
    by = W_hh;

    bi = 5;

    while (true) {
        gg();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            p1y -= 10;
            p1y = max(0, p1y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            p1y += 10;  // changing
            p1y = min(p1y, W_h - 85);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {  // positions.
            p2y -= 10;
            p2y = max(0, p2y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            p2y += 10;
            p2y = min(p2y, W_h - 85);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
            ply -= 10;
            ply = max(0, ply);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            ply += 10;  // changing
            ply = min(ply, W_h - 85);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {  // positions.
            pry -= 10;
            pry = max(0, pry);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            pry += 10;
            pry = min(pry, W_h - 85);
        }

        if (by == 0) iy *= -1;
        if (by == W_h - 5) iy *= -1;  // changing direction in y axis
        if (bx < 0) {                 // checking whether to add score
            player2score++;
            bi++;
            bi = min(bi, 9);
            bx = W_wh;
            by = W_hh;
            iy *= -1;
        }
        if (bx > W_w) {
            player1score++;
            bi++;
            bi = min(bi, 9);
            bx = W_wh;
            by = W_hh;
            iy *= -1;
        }

        if (player1score == 5 ||
            player2score == 5) {  // if one of the players hits the score limit
            sf::Text win;
            if (player1score == 5)
                win.setString("Team 1 wins");
            else
                win.setString("Team 2 wins");
            if (!font.loadFromFile("arial.ttf")) {
            }
            win.setFillColor(sf::Color::White);
            win.setCharacterSize(40);
            win.setFont(font);
            win.setPosition(W_w * .4, W_h * .45);
            sf::Event vnt;
            while (true) {  // declaring the winner until the next game
                window.clear(sf::Color::Black);
                window.draw(win);
                window.display();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) break;
            }
            player1score = player2score = 0;
            return;
        }
        if (bx >= 10 && bx <= 21 && by >= p1y && by <= p1y + 85)
            ix = abs(ix);  // changing the direction in x axis
        else if (bx >= W_w - 25 && bx <= W_w - 10 &&
                 by >= p2y &&  // x axis but opposite
                 by <= p2y + 85)
            ix = -abs(ix);
        else if (bx >= 210 && bx <= 221 && by >= ply && by <= ply + 85)
            ix = abs(ix);  // changing the direction in x axis
        else if (bx >= W_w - 225 && bx <= W_w - 210 &&
                 by >= pry &&  // x axis but opposite
                 by <= pry + 85)
            ix = -abs(ix);
        bx += ix * bi, by += iy * bi;
        by = max(
            by,
            0);  // setting limit for y , thus ball doesnt go beyond the window
        by = min(by, W_h - 5);
        window.clear(sf::Color(0, 102, 53, 255));
        score1(to_string(player1score));
        score2(to_string(player2score));
        draw2(p1y, p2y, ply, pry, bx, by);
    }
}

inline void ovo() {  // one vs one game
    bx = W_wh;
    by = W_hh;
    bi = 5;
    while (true) {
        gg();  // checks whether window is closed by the window menu
               // button
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            p1y -= 10;
            p1y = max(0, p1y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            p1y += 10;  // changing
            p1y = min(p1y, W_h - 85);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {  // positions.
            p2y -= 10;
            p2y = max(0, p2y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            p2y += 10;
            p2y = min(p2y, W_h - 85);
        }

        if (by == 0) iy *= -1;
        if (by == W_h - 5) iy *= -1;  // changing direction in y axis
        if (bx < 0) {                 // checking whether to add score
            player2score++;
            bi++;
            bi = min(bi, 9);
            bx = W_wh;
            by = W_hh;
            iy *= -1;
        }
        if (bx > W_w) {
            player1score++;
            bi++;
            bi = min(bi, 9);
            bx = W_wh;
            by = W_hh;
            iy *= -1;
        }
        if (player1score == 5 ||
            player2score == 5) {  // if one of the players hits the score limit
            sf::Text win;
            if (player1score == 5)
                win.setString("player 1 wins");
            else
                win.setString("player 2 wins");
            if (!font.loadFromFile("arial.ttf")) {
            }
            win.setFillColor(sf::Color::White);
            win.setCharacterSize(40);
            win.setFont(font);
            win.setPosition(W_w * .4, W_h * .45);
            sf::Event vnt;
            while (true) {  // declaring the winner until the next game
                window.clear(sf::Color::Black);
                window.draw(win);
                window.display();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) break;
            }
            player1score = player2score = 0;
            return;
        }

        if (bx >= 10 && bx <= 21 && by >= p1y && by <= p1y + 85)
            ix = abs(ix);  // changing the direction in x axis
        else if (bx >= W_w - 25 && bx <= W_w - 10 &&
                 by >= p2y &&  // x axis but opposite
                 by <= p2y + 85)
            ix = -abs(ix);
        bx += ix * bi, by += iy * bi;

        by = max(
            by,
            0);  // setting limit for y , thus ball doesnt go beyond the window
        by = min(by, W_h - 5);

        window.clear(sf::Color(0, 102, 53, 255));
        score1(to_string(player1score));
        score2(to_string(player2score));
        draw(p1y, p2y, bx, by);  // drawing the game state
    }
}

int main() {
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);
    bool fx = false;
    while (window.isOpen()) {
        gg();
        int idx = 0;
        while (true) {
            menu_draw(idx);
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Up) {
                        idx = (idx + 2) % 3;
                    } else if (event.key.code == sf::Keyboard::Down) {
                        idx = (idx + 1) % 3;
                    }
                }

                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Return) {
                        if (idx == 0)
                            ovo();
                        else if (idx == 1)
                            tvt();
                        else if (idx == 2)
                            vc();
                    }
                }
            }
            gg();
        }
    }
}

#define W_w 720
#define W_h 420

#define W_wh 360
#define W_hh 210
#define paddle_speed = 200

sf::RenderWindow window(sf::VideoMode(W_w, W_h), "Pong", sf::Style::Titlebar);
sf::Font font;

void paddle1_draw(int p1y) {
    sf::RectangleShape paddle1(sf::Vector2f(10, 50));
    paddle1.setPosition(10, p1y);
    paddle1.setFillColor(sf::Color::White);
    window.draw(paddle1);
}

void paddle2_draw(int p2y) {
    sf::RectangleShape paddle2(sf::Vector2f(10, 50));
    paddle2.setPosition(700, p2y);
    paddle2.setFillColor(sf::Color::White);
    window.draw(paddle2);
}
void ball_draw(int bx, int by) {
    sf::RectangleShape ball(sf::Vector2f(10, 10));
    ball.setPosition(bx, by);
    ball.setFillColor(sf::Color::White);
    window.draw(ball);
}

void draw(int p1y, int p2y, int bx, int by) {
    paddle1_draw(p1y);
    paddle2_draw(p2y);
    ball_draw(bx, by);

    window.display();  // displays the buffer
}

void init_state() {
    sf::Text text;                  // initializing text class
    if (!font.loadFromFile("arial.ttf")) {
    }
    text.setFont(font);             // setiing the default font
    text.setString("Hello pong!");  // giving the text to print
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(230, 180);
    window.clear(sf::Color::Black);
    window.draw(text);  // draws the string to buffer
    window.display();
}

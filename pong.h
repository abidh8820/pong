#define W_w 1366
#define W_h 683

#define W_wh 782
#define W_hh 391

sf::RenderWindow window(sf::VideoMode(W_w, W_h), "Pong");
sf::Font font;

void paddle1_draw(int p1y) {
    sf::RectangleShape paddle1(sf::Vector2f(10, 85));
    paddle1.setPosition(10, p1y);
    paddle1.setFillColor(sf::Color::White);
    window.draw(paddle1);
}

void paddle2_draw(int p2y) {
    sf::RectangleShape paddle2(sf::Vector2f(10, 85));
    paddle2.setPosition(W_w - 20, p2y);
    paddle2.setFillColor(sf::Color::White);
    window.draw(paddle2);
}
void ball_draw(int bx, int by) {
    sf::RectangleShape ball(sf::Vector2f(10, 10));
    ball.setPosition(bx, by);
    ball.setFillColor(sf::Color::White);
    window.draw(ball);
}
void menu_draw(int idx){
    sf::Text text[4];
    if (!font.loadFromFile("arial.ttf")) {
    }
    text[1].setString("Two vs Two");  // giving the text to print
    text[0].setString("One vs One");  // giving the text to print
    text[2].setString("vs Computer");  // giving the text to print
    text[idx].setFillColor(sf::Color::Red);
    window.clear(sf::Color::Black);

    text[3].setFont(font);             // setiing the default font
    text[3].setCharacterSize(100);
    text[3].setPosition(W_w *.5 -150, 100);
    text[3].setString("Pong beta");  // giving the text to print
    window.draw(text[3]);
    for(int i=0;i<3;i++){
    text[i].setFont(font);             // setiing the default font
    text[i].setCharacterSize(50);
    text[i].setPosition(W_w *.5 -50, 360+i*100);
    if(idx!=i) text[i].setFillColor(sf::Color::White);
    window.draw(text[i]);
    }
    window.display();
}
void draw(int p1y, int p2y, int bx, int by) {
    paddle1_draw(p1y);
    paddle2_draw(p2y);
    ball_draw(bx, by);
    window.display();  // displays the buffer
}

void init_state() {
    sf::Text text;  // initializing text class
    if (!font.loadFromFile("arial.ttf")) {
    }
    text.setFont(font);             // setiing the default font
    text.setString("ponge beta");  // giving the text to print
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(W_w * .4, W_h*.45);
    window.clear(sf::Color::Black);
    window.draw(text);  // draws the string to buffer
    window.display();
}

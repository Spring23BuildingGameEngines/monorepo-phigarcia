// @file Assignment1/gameloop/main.cpp
//
// compile with g++ main.cpp -o prog
// run with ./prog
#include <iostream>
struct Application {
    Application() {}
    ~Application(){}
}
void input() {

}

void update() {

}

void render() {

}

void loop() {
     while(true) {
        input();
        update();
        render();
    }
}
int main()
{
    Application game;
    game.loop(); 
   
    return 0; 
}
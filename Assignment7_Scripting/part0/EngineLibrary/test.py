# Run with:
#
# (Linux & Mac) python3.5 test.py -m ./mygameengine.so
# (Windows) python3.6 test.py -m ./mygameengine.pyd
#
# The program should also run with 'python2.7' but you will have
# to change the 3.5's to 2.7's in your respective build script as
# well as make sure you compiled with 3.5 or 2.7 load flags.
#
# You will see `python3.5-config --includes` for example which corresponds
# to which version of python you are building.
# (In fact, run `python3.5-config --includes` in the terminal to see what it does!)
import mygameengine

# Now use some python libraries for random numbers!
import random


# Initialize SDL
test = mygameengine.SDLGraphicsProgram(400,400)

class Paddle:
    def __init__(self, x, y, w, h):
        self.x = x
        self.y = y
        self.w = w
        self.h = h


class Ball:
    def __init__(self, x, y, w, h):
        self.x = x
        self.y = y
        self.w = w
        self.h = h
        self.vx = 0
        self.vy = 0

player1 = Paddle(10, 200, 10, 80)
player2 = Paddle(480, 200, 10, 80)
ball = Ball(200, 200, 10, 10)


def draw_paddle(p):
    test.DrawRectangle(p.x, p.y, p.w, p.h)

def draw_ball(b):
    test.DrawRectangle(b.x - b.r, b.y - b.r, b.r * 2, b.r * 2)

def draw_game():
    draw_paddle(left_paddle)
    draw_paddle(right_paddle)
    draw_ball(ball)

def tick():
    # do collisions
    # todo

def main():
    print("Setting up game loop")
    while True:
        # Clear the screen
        test.clear();

        # do game logic
        tick()
        
        # render
        draw_game()

        # Add a little delay
        test.delay(100)
        # Refresh the screen
        test.flip()

if __name__ == '__main__':
    main()











# Our main game loop
# print("Setting up game loop")

# def input():
#     if test.isKeyDown == true

#     #get boolean from c++ function

# def loop(inp, up, ren): #pointers in python
#     inp()
#     up()
#     ren()



# TODO Questions
# should we be writing our code here and in bindings.cpp
# how to get start writing input?
# do we have to recode the game in python with all the logic
# completely confused on how to handle input. how to start
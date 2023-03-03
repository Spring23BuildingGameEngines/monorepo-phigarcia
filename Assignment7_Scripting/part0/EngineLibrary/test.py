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
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r
        self.vx = 0
        self.vy = 0

    def set_pos(self, x, y):
        self.x = x 
        self.y = y

player1 = Paddle(10, 160, 10, 80)
player2 = Paddle(380, 160, 10, 80)
ball = Ball(200, 200, 7)
ball.vx = 5
ball.vy = 5

def draw_paddle(p):
    test.DrawRectangle(p.x, p.y, p.w, p.h)

def draw_ball(b):
    test.DrawRectangle(b.x - b.r, b.y - b.r, b.r * 2, b.r * 2)

def draw_game():
    draw_paddle(player1)
    draw_paddle(player2)
    draw_ball(ball)

def clamp_paddle(p):
    if p.y < 0:
        p.y = 0
    if p.y + p.h > 400:
        p.y = 400 - p.h

def keyboard_input(): 
    if test.isKeyDown(0):
        player1.y += 10
    if test.isKeyDown(1):
        player1.y -= 10
    if test.isKeyDown(2):
        player2.y += 10
    if test.isKeyDown(3):
        player2.y -= 10


def check_collision(b, p):
    if b.y > p.y + p.h or b.y < p.y:
        return

    if b.x > p.x and b.x < p.x + p.w:
        b.vx *= -1
        b.x += b.vx * 2 # move away from the paddle



def tick():
    keyboard_input()
    clamp_paddle(player1)
    clamp_paddle(player2)
    check_collision(ball, player1)
    check_collision(ball, player2)

    if ball.x > 390:
        ball.set_pos(200, 200)
    elif ball.x < -390:
        ball.set_pos(200, 200)
        
    if ball.y < 0 or ball.y > 400: 
        ball.vy *= -1

    ball.set_pos(ball.x + ball.vx, ball.y + ball.vy)


def main():
    print("Setting up game loop")
    while True:
        # Clear the screen
        test.clear()
        test.loop()
        # do game logic
        tick()
        
        # render
        draw_game()

        # Add a little delay
        test.delay(30)
        # Refresh the screen
        test.flip()

if __name__ == '__main__':
    main()
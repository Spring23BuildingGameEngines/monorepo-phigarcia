// g++ -std=c++17 class.cpp -o prog
#include <iostream>

class PPM{
    public:
    PPM(unsigned int width, unsigned int height) {
        pixelData = new unsigned char[width*height*3];
    }

    ~PPM() {
        delete[] pixelData;
    }

    private:
    uint8_t* pixelData;
};


int main(){
    PPM myPPM(128, 256);
    return 0;
}
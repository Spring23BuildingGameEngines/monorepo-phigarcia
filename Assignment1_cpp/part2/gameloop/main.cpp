// @file Assignment1/gameloop/main.cpp
//
// compile with g++ main.cpp -o prog
// run with ./prog
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct Application {
    std::ifstream fileStream;
    int option; 
    int lineNumber = 0;
    std::string line; 
    std::vector<std::string> story;
    
    Application() { 
    }
    ~Application(){std::cout << "The End :)" << std::endl;}
    
    void processValidFile(int argc, char* argv[]) {
        if (fileStream.is_open()){
            while(getline(fileStream,line)){
                story.push_back(line);
            }
        }
        else if (!fileStream.is_open()) {
            std::cout << "File did not open correctly. Aborting..." << std::endl;
            exit(1);
        }
    }

    void input() {
        std::cin >> option;
        if (option != 1 && option != 2) {
            std::cout << "Invalid option. Please select 1 or 2." << std::endl; 
        }
    }

    void update() {
        if (option == 1) {
            lineNumber += 1;
        }
        else if (option == 2) {
            if (lineNumber == 0) {
                std::cout << "This is the beginning of the story! Please select 1." << std::endl;
            }
            else {
                lineNumber -= 1;
            }
        }
    }   

    void render() {
        if(lineNumber >= story.size() - 1) {
            std::cout << "The end :)   ";
            std::cout << " =＾• ⋏ •＾= " << std::endl;
            exit(1); // should i be using exit?
        }
        else {
            std::cout << story[lineNumber] << std::endl;
            std::cout << "1. Go on.." << std::endl;
            std::cout << "2. Go back!" << std::endl;
        }
    }

    void loop() {
        while(true) {
            input();
            update();
            render();
        }
    }
};

int main(int argc, char* argv[])
{
    Application game;

    // make sure the file is valid
    for (int i = 0; i < argc; i++) {
            if (i == 0) {
                game.fileStream.open(argv[1]);
                if (!game.fileStream.is_open()) {
                    std::cout << "Please specify a valid file name." << std::endl; 
                    exit(1);
                }
                else if (argc > 2) {
                    std::cout << "Only one argument is supported." << std::endl;
                    exit(1);
                }
            }   
        }

    game.processValidFile(argc, argv);
    game.render(); // to get the first line going // is this okay?
    game.loop();

    game.fileStream.close(); 
    std::cout << "The end :)" << std::endl;
    return 0; 
}

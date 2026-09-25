//cube.h
#pragma once
#include <cstdint>
#include <array>
#include <string>
#include <iostream>
#include <sstream>

// Change your enum sequence to match Face order: 
// 0=UP(W), 1=LEFT(O), 2=FRONT(G), 3=RIGHT(R), 4=BACK(B), 5=DOWN(Y)
enum class Color : uint8_t {
    white = 0,
    orange = 1,
    green = 2,
    red = 3,
    blue = 4,
    yellow = 5
};


enum class Face : uint8_t {
    UP = 0,
    LEFT = 1,
    FRONT = 2,
    RIGHT = 3,
    BACK = 4,
    DOWN = 5
};

class Cube{
    private:
        std::array<Color, 54> stickers;
        void rotateFaceCounterClockwise(int faceIndex);
        void rotateFaceClockwise(int faceIndex);

    public:
        Cube(); // Constructor declaration
        const std::array<Color, 54>& readStickers();
        //operations
        //row operations
        void firstRowRight();
        void firstRowLeft();
        void secondRowRight();
        void secondRowLeft();
        void thirdRowRight();
        void thirdRowLeft();
        //coloumn operations
        void firstColumnUp();
        void firstColumnDown();
        void secondColumnUp();
        void secondColumnDown();
        void thirdColumnUp();
        void thirdColumnDown();

        //printing
        void print() const;
        //scramble
        void scramble();
        //isSolved
        bool isSolved() const;
};


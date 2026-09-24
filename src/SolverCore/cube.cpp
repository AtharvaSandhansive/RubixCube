//cube.cpp
#include <cstdint>
#include <array>
#include <vector>


enum class Color: uint8_t{
    white = 0,
    yellow = 1,
    red = 2,
    orange = 3,
    blue = 4,
    green = 5
};

enum class Face: uint8_t{
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

        int normalize(int x){


            return x;
        }

    public:

        //constructor
        Cube(){

            //NEW optimized fller with single loop
            for (int i = 0; i < 54; i++){
                //since integer division cuts of decimals, we can put it directly as the color
                stickers[i] = static_cast<Color>(i / 9);
            }

            /*
                Older Constructor with O(n2) optimization:
                //keep count of the sticker from 0-53
                int stickerIndex = 0;
                //count the face
                for (int face = 0; face < 6; face++){//since the cube has 6 faces 
                    //so for each faces, we go adding 9 elements in the array
                    for (int sticker = 0; sticker < 9; sticker++){
                        arr[stickerIndex] = static_cast<Color>(face);
                        stickerIndex++;
                    }
                }
            */
        }

        void rotateFaceCounterClockwise(int faceIndex, int rotations){
            rotations = normalize(rotations);
            for (int i = 0; i < rotations; i++){
                int base = faceIndex * 9;

                // 1. Rotate Corners counter-clockwise (0 -> 6 -> 8 -> 2 -> 0)
                Color tempCorner = stickers[base + 0];
                stickers[base + 0] = stickers[base + 2];
                stickers[base + 2] = stickers[base + 8];
                stickers[base + 8] = stickers[base + 6];
                stickers[base + 6] = tempCorner;

                // 2. Rotate Edges counter-clockwise (1 -> 3 -> 7 -> 5 -> 1)
                Color tempEdge = stickers[base + 1];
                stickers[base + 1] = stickers[base + 5];
                stickers[base + 5] = stickers[base + 7];
                stickers[base + 7] = stickers[base + 3];
                stickers[base + 3] = tempEdge;
            }
            
        }

        //operations
        void firstRowRight(){
            for (int i = 0; i < 3; i++){
                //store the last value or at 36th position in temp buffer
                Color temp = stickers[i+36];

                stickers[i+36] = stickers[i+27];
                stickers[i+27] = stickers[i+18];
                stickers[i+18] = stickers[i+9];

                stickers[i+9] = temp;
            }
        }

        

};

/*
                  +------------+
                  |  0   1   2 |
                  |  3   4   5 |  <-- UP (U) [Indices 0 - 8]
                  |  6   7   8 |
    +-------------+------------+-------------+-------------+
    |  9  10  11  | 18  19  20 | 27  28  29  | 36  37  38  |
    | 12  13  14  | 21  22  23 | 30  31  32  | 39  40  41  | <-- L, F, R, B
    | 15  16  17  | 24  25  26 | 33  34  35  | 42  43  44  |
    +-------------+------------+-------------+-------------+
                  | 45  46  47 |
                  | 48  49  50 |  <-- DOWN (D) [Indices 45 - 53]
                  | 51  52  53 |
                  +------------+

*/
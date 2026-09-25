//cube.cpp
#include "cube.h" // Crucial: Include your own header file
#include <iostream>

// Constructor implementation
Cube::Cube() {
    for (int i = 0; i < 54; i++) {
        stickers[i] = static_cast<Color>(i / 9);
    }
}

void Cube::rotateFaceClockwise(int faceIndex){
    int base = faceIndex * 9;//offset for the face (0 = up, left = 9 etc.)
    //(0 -> 6 -> 8 -> 2 -> 0)
    Color tempCorner = stickers[base + 0];
    stickers[base + 0] = stickers[base + 2];
    stickers[base + 2] = stickers[base + 8];
    stickers[base + 8] = stickers[base + 6];
    stickers[base + 6] = tempCorner;

    // (1 -> 3 -> 7 -> 5 -> 1)
    Color tempEdge = stickers[base + 1];
    stickers[base + 1] = stickers[base + 5];
    stickers[base + 5] = stickers[base + 7];
    stickers[base + 7] = stickers[base + 3];
    stickers[base + 3] = tempEdge;
}

void Cube::rotateFaceCounterClockwise(int faceIndex){
    int base = faceIndex * 9;
    // Corners: 0 <- 6 <- 8 <- 2 <- 0
    Color tempCorner = stickers[base + 0];
    stickers[base + 0] = stickers[base + 6];
    stickers[base + 6] = stickers[base + 8];
    stickers[base + 8] = stickers[base + 2];
    stickers[base + 2] = tempCorner;

    // Edges: 1 <- 3 <- 7 <- 5 <- 1
    Color tempEdge = stickers[base + 1];
    stickers[base + 1] = stickers[base + 3];
    stickers[base + 3] = stickers[base + 7];
    stickers[base + 7] = stickers[base + 5];
    stickers[base + 5] = tempEdge;
}

const std::array<Color, 54>& Cube::readStickers(){
    return stickers;
}

//isSolved
bool Cube::isSolved() const {
    // Array of the 6 center sticker indices
    const int centers[6] = {4, 13, 22, 31, 40, 49};

    for (int face = 0; face < 6; face++) {
        int centerIndex = centers[face];
        Color centerColor = stickers[centerIndex];
        int faceBase = face * 9;

        // Check all 9 stickers on the current face
        for (int i = 0; i < 9; i++) {
            if (stickers[faceBase + i] != centerColor) {
                return false; // Found a mismatch, cube is not solved
            }
        }
    }
    return true; // All faces are uniform
}



// Row movement implementation
void Cube::firstRowRight() {
    for (int i = 0; i < 3; i++) {
        Color temp = stickers[i + 36];
        stickers[i + 36] = stickers[i + 27];
        stickers[i + 27] = stickers[i + 18];
        stickers[i + 18] = stickers[i + 9];
        stickers[i + 9] = temp;
    }
    rotateFaceClockwise(0);
}

void Cube::firstRowLeft() {

    for (int i = 0; i < 3; i++) {

        Color temp = stickers[i + 9];

        stickers[i + 9] = stickers[i + 18];

        stickers[i + 18] = stickers[i + 27];

        stickers[i + 27] = stickers[i + 36];

        stickers[i + 36] = temp;

    }

    rotateFaceCounterClockwise(0);

}

void Cube::secondRowRight() {

    for (int i = 0; i < 3; i++) {

        Color temp = stickers[i + 36 + 3];

        stickers[i + 36 + 3] = stickers[i + 27 + 3];

        stickers[i + 27 + 3] = stickers[i + 18 + 3];

        stickers[i + 18 + 3] = stickers[i + 9 + 3];

        stickers[i + 9 + 3] = temp;

    }

}

void Cube::secondRowLeft() {

    for (int i = 0; i < 3; i++) {

        Color temp = stickers[i + 9 + 3];

        stickers[i + 9 + 3] = stickers[i + 18 + 3];

        stickers[i + 18 + 3] = stickers[i + 27 + 3];

        stickers[i + 27 + 3] = stickers[i + 36 + 3];

        stickers[i + 36 + 3] = temp;

    }

}

void Cube::thirdRowLeft() {

    for (int i = 0; i < 3; i++) {

        Color temp = stickers[i + 9 + 3];

        stickers[i + 9 + 6] = stickers[i + 18 + 6];

        stickers[i + 18 + 6] = stickers[i + 27 + 6];

        stickers[i + 27 + 6] = stickers[i + 36 + 6];

        stickers[i + 36 + 6] = temp;

    }

}

void Cube::thirdRowRight() {

    for (int i = 0; i < 3; i++) {

        Color temp = stickers[i + 36 + 6];

        stickers[i + 36 + 6] = stickers[i + 27 + 6];

        stickers[i + 27 + 6] = stickers[i + 18 + 6];

        stickers[i + 18 + 6] = stickers[i + 9 + 6];

        stickers[i + 9 + 6] = temp;

    }

    rotateFaceCounterClockwise(5);

}


void Cube::firstColumnUp() {

    Color temp[3];

    for (int i = 0; i < 3; i++) {
        temp[i] = stickers[i * 3 + 45];
    }

    for (int i = 0; i < 3; i++) {
        stickers[i * 3 + 45] = stickers[(2 - i) * 3 + 36];
        stickers[(2 - i) * 3 + 36] = stickers[(2 - i) * 3 + 0];
        stickers[(2 - i) * 3 + 0] = stickers[i * 3 + 18];
        stickers[i * 3 + 18] = temp[i];
    }

    rotateFaceCounterClockwise(1);

}

void Cube::firstColumnDown() {

    Color temp[3];

    for (int i = 0; i < 3; i++) {
        temp[i] = stickers[i * 3 + 18];
    }

    for (int i = 0; i < 3; i++) {
        stickers[i * 3 + 18] = stickers[(2 - i) * 3 + 0];
        stickers[(2 - i) * 3 + 0] = stickers[(2 - i) * 3 + 36];
        stickers[(2 - i) * 3 + 36] = stickers[i * 3 + 45];
        stickers[i * 3 + 45] = temp[i];
    }

    rotateFaceClockwise(1);

}

void Cube::thirdColumnUp() {

    Color temp[3];

    for (int i = 0; i < 3; i++) {
        temp[i] = stickers[i * 3 + 45 + 2];
    }

    for (int i = 0; i < 3; i++) {
        stickers[i * 3 + 45 + 2] = stickers[(2 - i) * 3 + 36 + 2];
        stickers[(2 - i) * 3 + 36 + 2] = stickers[(2 - i) * 3 + 2];
        stickers[(2 - i) * 3 + 2] = stickers[i * 3 + 18 + 2];
        stickers[i * 3 + 18 + 2] = temp[i];
    }

    rotateFaceClockwise(3);

}

void Cube::thirdColumnDown() {

    Color temp[3];

    for (int i = 0; i < 3; i++) {
        temp[i] = stickers[i * 3 + 18 + 2];
    }

    for (int i = 0; i < 3; i++) {
        stickers[i * 3 + 18 + 2] = stickers[(2 - i) * 3 + 2];
        stickers[(2 - i) * 3 + 2] = stickers[(2 - i) * 3 + 36 + 2];
        stickers[(2 - i) * 3 + 36 + 2] = stickers[i * 3 + 45 + 2];
        stickers[i * 3 + 45 + 2] = temp[i];
    }

    rotateFaceCounterClockwise(3);

}

void Cube::secondColumnUp() {

    Color temp[3];

    for (int i = 0; i < 3; i++) {
        temp[i] = stickers[i * 3 + 45 + 1];
    }

    for (int i = 0; i < 3; i++) {
        stickers[i * 3 + 45 + 1] = stickers[i * 3 + 36 + 1];
        stickers[i * 3 + 36 + 1] = stickers[i * 3 + 1];
        stickers[i * 3 + 1] = stickers[i * 3 + 18 + 1];
        stickers[i * 3 + 18 + 1] = temp[i];
    }

    rotateFaceClockwise(2);

}

void Cube::secondColumnDown() {

    Color temp[3];

    for (int i = 0; i < 3; i++) {
        temp[i] = stickers[i * 3 + 18 + 1];
    }

    for (int i = 0; i < 3; i++) {
        stickers[i * 3 + 18 + 1] = stickers[i * 3 + 1];
        stickers[i * 3 + 1] = stickers[i * 3 + 36 + 1];
        stickers[i * 3 + 36 + 1] = stickers[i * 3 + 45 + 1];
        stickers[i * 3 + 45 + 1] = temp[i];
    }

    rotateFaceCounterClockwise(2);

}

void Cube::print() const {
    // Helper lambda to map Color enum to a single character
    auto getChar = [this](int index) -> char {
        switch (stickers[index]) {
            case Color::white:  return 'W';
            case Color::yellow: return 'Y';
            case Color::red:    return 'R';
            case Color::orange: return 'O';
            case Color::blue:   return 'B';
            case Color::green:  return 'G';
            default:            return '?';
        }
    };

    // --- UP FACE (Indices 0 - 8) ---
    std::cout << "              +------------+\n";
    std::cout << "              |  " << getChar(0) << "   " << getChar(1) << "   " << getChar(2) << " |\n";
    std::cout << "              |  " << getChar(3) << "   " << getChar(4) << "   " << getChar(5) << " |\n";
    std::cout << "              |  " << getChar(6) << "   " << getChar(7) << "   " << getChar(8) << " |\n";

    // --- MIDDLE BORDER ---
    std::cout << "+-------------+------------+-------------+-------------+\n";

    // --- LEFT, FRONT, RIGHT, BACK FACES side-by-side ---
    // Row 1 (Indices: L:9-11, F:18-20, R:27-29, B:36-38)
    std::cout << "|  " << getChar(9)  << "   " << getChar(10) << "   " << getChar(11) << "  | "
              << " " << getChar(18) << "   " << getChar(19) << "   " << getChar(20) << " | "
              << " " << getChar(27) << "   " << getChar(28) << "   " << getChar(29) << "  | "
              << " " << getChar(36) << "   " << getChar(37) << "   " << getChar(38) << "  |\n";

    // Row 2 (Indices: L:12-14, F:21-23, R:30-32, B:39-41)
    std::cout << "|  " << getChar(12) << "   " << getChar(13) << "   " << getChar(14) << "  | "
              << " " << getChar(21) << "   " << getChar(22) << "   " << getChar(23) << " | "
              << " " << getChar(30) << "   " << getChar(31) << "   " << getChar(32) << "  | "
              << " " << getChar(39) << "   " << getChar(40) << "   " << getChar(41) << "  |\n";

    // Row 3 (Indices: L:15-17, F:24-26, R:33-35, B:42-44)
    std::cout << "|  " << getChar(15) << "   " << getChar(16) << "   " << getChar(17) << "  | "
              << " " << getChar(24) << "   " << getChar(25) << "   " << getChar(26) << " | "
              << " " << getChar(33) << "   " << getChar(34) << "   " << getChar(35) << "  | "
              << " " << getChar(42) << "   " << getChar(43) << "   " << getChar(44) << "  |\n";

    // --- MIDDLE BORDER ---
    std::cout << "+-------------+------------+-------------+-------------+\n";

    // --- DOWN FACE (Indices 45 - 53) ---
    std::cout << "              |  " << getChar(45) << "   " << getChar(46) << "   " << getChar(47) << " |\n";
    std::cout << "              |  " << getChar(48) << "   " << getChar(49) << "   " << getChar(50) << " |\n";
    std::cout << "              |  " << getChar(51) << "   " << getChar(52) << "   " << getChar(53) << " |\n";
    std::cout << "              +------------+\n";
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
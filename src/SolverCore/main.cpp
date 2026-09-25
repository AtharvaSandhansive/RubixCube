//main.cpp
#include <iostream>
#include <random>
#include "cube.h"

void performOperation(const std::string& input, Cube& cube){
    if (input == "U'") {cube.firstRowRight();}
    else if (input == "U") {cube.firstRowLeft();}
    else if (input == "E") {cube.secondRowRight();}
    else if (input == "E'") {cube.secondRowLeft();}
    else if (input == "D") {cube.thirdRowRight();}
    else if (input == "D'") {cube.thirdRowLeft();}
    else if (input == "L'") {cube.firstColumnUp();}
    else if (input == "L") {cube.firstColumnDown();}
    else if (input == "M'") {cube.secondColumnUp();}
    else if (input == "M") {cube.secondColumnDown();}
    else if (input == "R") {cube.thirdColumnUp();}
    else if (input == "R'") {cube.thirdColumnDown();}
    else {std::cout<<"WRONG INPUT, TRY AGAIN!";}

}

void Scramble(int scrambles, Cube& cube){
    std::array<std::string, 12> arr = {"U","E","D","L","M","R","U'","E'","D'","L'","M'", "R'"};
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distri(0, 11);
    

    int counter = 0;
    while (counter < scrambles){
        int random_num = distri(gen);
        performOperation(arr[random_num], cube);
        counter++;
    }
}

int main(){

    Cube cube;
    cube.print();
    std::string input;

    while (true){
        std::cout << "What would you like to perform?: " ;
        std::cin >> input;
        
        if (input == "EXIT"){
            std::cout << "Exiting...";
            break;
        }

        if (input == "SCRAMBLE"){
            int k = 0;
            std::cout << "How much moves to scramble?: ";
            std::cin >> k;
            Scramble(k, cube);
        } else {performOperation(input, cube);}
        
        std::cout << "Cube: " <<std::endl;
        cube.print();
        if (cube.isSolved()){std::cout << "CUBE IS SOLVED!" << std::endl;}
    }

    return 0;
}
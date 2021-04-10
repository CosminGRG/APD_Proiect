// RNG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <fstream>
#include <limits>

// Generate 1 million random 32-bit integers.

int main(int argc, char** argv) {

    const int min_int = std::numeric_limits<int>::min();
    const int max_int = std::numeric_limits<int>::max();

    std::ofstream myfile("100.000.000-ints.txt");
    //myfile.open("1.000.000 ints.txt");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, max_int);

    for (int i = 0; i < 100000000; i++)
    {
        int a;
        a = dis(gen);
        //std::cout << "numbers are: " << a << std::endl;
        myfile << a << " ";
    }

    myfile.close();

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

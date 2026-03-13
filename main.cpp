/************************************
 * Student Name: Atiye Buker
 * File Name: main.cpp
 * Project 3
 * 
 * Purpose: 
 * ************************************/
#include "matrix.cpp"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

int main() {
    double matrix[20][20] = {0}; //initialize a 20 by 20 all vals 0
    createMatrix(matrix);

    int numCities;
    int numTours;
    int numGen;
    double percent;

    cout << "Please enter the number of cities to run: " << endl;
    cin >> numCities;

    cout << "Please enter how many tours you would like per generation: " << endl;
    cin >> numTours;

    cout << "Please enter how many generations you would like to run: " << endl;
    cin >> numGen;

    cout << "Please enter what percentage of each generation should be comprised of mutations: " << endl;
    cin >> percent;

    
}
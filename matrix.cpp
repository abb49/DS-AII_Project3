/************************************
 * Student Name: Atiye Buker
 * File Name: matrix.cpp
 * Project 3
 * 
 * Purpose: read in the distances to a 20 by 20 adjacency matrix
 * ************************************/
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
#include "matrix.hpp"
using namespace std;

double getDistance(double arr[20][20], int cityA, int cityB) {
    return arr[cityA][cityB];
}

void createMatrix(double (&arr)[20][20]) {
    const int NUM_COLS = 20;
    const int NUM_ROWS = 20;

    string currIn;
    ifstream iss("distances.txt");

    //check that the file is open
    if(!iss.is_open()){
        cout << "File could not be opened";
        return;
    }
    
    for(int i = 0; i < NUM_ROWS; i++) {
        for(int j = 0; j < NUM_COLS; j++) {
            getline(iss, currIn);
            if(currIn.empty()) {
                continue;
            }
            if(i != j) {
                arr[i][j] = stod(currIn);
            }
        }
    }

    iss.close();
}
/************************************
 * Student Name: Atiye Buker
 * File Name: main.cpp
 * Project 3
 * 
 * Purpose: run two seperate algorithms for the traveling salesman problem
 * ************************************/
#include "matrix.hpp"
#include"BruteForce.hpp"
#include"Genetic.hpp"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

int main() {
    srand(time(0)); //set seed since rand is used later

    Tour::makeMatrix(); //make static member matrix to use in the algorithms

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

    BruteForce brute(numCities);
    Genetic gen(numGen, numTours, percent, numCities);

    double perOpt = ((gen.getBestCost())/(brute.getBestCost())) * 100.0;

    cout << "Number of Cities: " << numCities << endl;
    cout << "Optimal Cost (From Brute Force Algorithm): " << brute.getBestCost() << endl;
    cout << "Time for Brute Force Algorithm: " << brute.getTime() << endl;
    cout << "Cost From Genetic Algorithm: " << gen.getBestCost() << endl;
    cout << "Time for Genetic Algorithm: " << gen.getTime() << endl;
    cout << "Percent of Optimal Produced by Genetic Algorithm: " << perOpt << endl;
}
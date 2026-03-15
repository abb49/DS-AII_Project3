/************************************
 * Student Name: Atiye Buker
 * File Name: BruteForce.cpp
 * Project 3
 * 
 * Purpose: define the BruteForce class functions
 * ************************************/

#include "BruteForce.hpp"
#include<cmath> //for factorial

unsigned long int factorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}

double BruteForce::getBestCost() {
    return bestCost;
}

int BruteForce::getNumCities() {
    return numCities;
}

BruteForce::BruteForce(int cities) : bestTour(cities) {
    numCities = cities;
    search();
}

void BruteForce::search() {
    //TODO start timer
    //makeMatrix called in main
    Tour currTour(numCities);
    bestCost = currTour.getFitness();
    bestTour = currTour;

    bool permBool = true;
    while(permBool == true){ //minus 1 since we already have the current tour
        double currCost = currTour.getFitness();
        if(currCost < bestCost) {
            bestCost = currCost;
            bestTour = currTour;
        }

        permBool = currTour.perm();
    }
}
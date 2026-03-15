/************************************
 * Student Name: Atiye Buker
 * File Name: BruteForce.cpp
 * Project 3
 * 
 * Purpose: define the BruteForce class functions
 * ************************************/

#include "BruteForce.hpp"


double BruteForce::getBestCost() {
    return bestCost;
}

BruteForce::BruteForce() {
      numCities = 0;
      bestCost =0;
      timeElapsed = 0; 
}

double BruteForce::getTime() {
    return timeElapsed;
}

int BruteForce::getNumCities() {
    return numCities;
}

BruteForce::BruteForce(int cities) : bestTour(cities) {
    numCities = cities;
    search();
}

void BruteForce::search() {
    //makeMatrix called in main
    struct timeval *start;
    struct timeval *end;
    struct timezone *z;

    start = (struct timeval *) malloc(sizeof(struct timeval));
    end = (struct timeval *) malloc (sizeof(struct timeval));

    z = (struct timezone * ) malloc (sizeof(struct timezone));

    gettimeofday(start, z); //start time before entering loop

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

    gettimeofday(end, z); //end time

    long seconds = end->tv_sec - start-> tv_sec;
    long microsecs = end->tv_usec - start->tv_usec;

    timeElapsed = seconds + microsecs / 1000000.0; //final time in microsecs

    //free pointers
    free(start);
    free(end);
    free(z);
}
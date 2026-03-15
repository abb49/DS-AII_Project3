/************************************
 * Student Name: Atiye Buker
 * File Name: Tours.cpp
 * Project 3
 * 
 * Purpose: define Tours class
 * ************************************/
#include "Tours.hpp"


void Tour::swap(int a, int b) {
    int temp = tour[a];
    tour[a] = tour[b];
    tour [b] = temp;
}

bool Tour::perm() {
    int m, k, p , q, i;
     m = numCities-2;
     while(m>=1 && tour[m]>tour[m+1]) //to make sure first city stays the same
     {
        m = m - 1;
     }
     if(m < 1){
        return false;
     }

     k = numCities-1;
     while(tour[m] > tour[k])
     {
        k = k - 1;
     }
     swap(m, k);
     p = m + 1;
     q = numCities-1;
     while( p < q)
     {
       swap(p,q);
       p++;
       q--;
     }

     calculateFitness();
     return true;
} 

void Tour::mutate() {
    //pick two random indexes to swap
    int i = (rand() % (numCities - 1)) + 1;
    int j = (rand() % (numCities - 1)) + 1;

    while(i == j) {
        j = (rand() % (numCities - 1)) + 1;
    }

    swap(i, j);
}
double Tour::getFitness() {
    return fitness;
}

void Tour::makeMatrix() {
    double arr[20][20];

    createMatrix(arr);

    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 20; ++j) {
            matrix[i][j] = arr[i][j];
        }
    }
}

void Tour::calculateFitness() {
    double total = 0.0;

    for(int i = 0; i < numCities - 1; ++i) {
        int cityA = tour[i];
        int cityB = tour[i+1];
        total += matrix[cityA][cityB];
    }

    total += matrix[tour[numCities - 1]][tour[0]];

    fitness = total;
}

Tour::Tour(int cities) {
    numCities = cities;
    tour = new int[numCities];

    for(int i = 0; i < numCities; ++i) {
        tour[i] = i;
    }

    calculateFitness();
}

Tour::~Tour() {
    delete[] tour;
}

Tour::Tour(const  Tour& other) {
    numCities = other.numCities;

    tour = new int[numCities];

    for(int i = 0; i < numCities; ++i) {
        tour[i] = other.tour[i];
    }
}

Tour& Tour::operator=(const Tour& other) {
    if(this != &other) {
        delete[] tour;
        numCities = other.numCities;
        fitness = other.fitness;
        tour = new int[numCities];
        for(int i = 0; i < numCities; i++) {
            tour[i] = other.tour[i];
        }
    }
    return *this;
}



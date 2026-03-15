/************************************
 * Student Name: Atiye Buker
 * File Name: Genetic.cpp
 * Project 3
 * 
 * Purpose: Define the genetic class
 * ************************************/ 

 #include "Genetic.hpp"
Genetic::Genetic() {
      genSize = 0;
      numGens =0;
      citiesPerGen =0;
      mutPercent =0;
      timeElapsed =0;
}

 Genetic::Genetic(int genNum, int sizeGen, double percent, int numCities){
    numGens = genNum;
    genSize = sizeGen;
    mutPercent = percent;
    citiesPerGen = numCities;
    Tour currTour(citiesPerGen);
    bestTour = currTour;

    for(int i = 0; i < genSize; ++i) {
        if(currTour.getFitness() < bestTour.getFitness()) {
            bestTour = currTour;
        }
        currTour.mix();
        generation.push_back(currTour);
    }

    findBest();
 }

 void Genetic::findBest() {
            //makeMatrix called in main
    struct timeval *start;
    struct timeval *end;
    struct timezone *z;

    start = (struct timeval *) malloc(sizeof(struct timeval));
    end = (struct timeval *) malloc (sizeof(struct timeval));

    z = (struct timezone * ) malloc (sizeof(struct timezone));

    gettimeofday(start, z); //start time before entering loop

    for(int i = 0; i < numGens; ++i) {
        createNextGen();
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



 void Genetic::createNextGen() {


    std::vector<Tour> nextGen;
    nextGen.push_back(bestTour);
    int numToMutate = static_cast<int>(std::round(genSize * mutPercent));
    for (int i = 0; i < numToMutate; ++i){
        Tour mutation = bestTour;
        mutation.mutate();

        nextGen.push_back(mutation);
    }

    generation.clear();

    generation = nextGen;

    Tour currTour(citiesPerGen);

    while(generation.size() < genSize) {
        currTour.mix();
        generation.push_back(currTour);
        if(currTour.getFitness() < bestTour.getFitness()){
            bestTour = currTour;
        }
    }


}

Tour Genetic::getBestTour() {
    return bestTour;
}

double Genetic::getTime() {
    return timeElapsed;
}

double Genetic::getBestCost() {
    return bestTour.getFitness();
}
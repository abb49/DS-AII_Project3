/************************************
 * Student Name: Atiye Buker
 * File Name: Genetic.hpp
 * Project 3
 * 
 * Purpose: Declare the genetic class to 
 *   exacute the genetic algorithm for the 
 *   traveling salesman problem
 * ************************************/ 

 #ifndef GENETIC_HPP
 #define GENETIC_HPP
 #include <vector> //for a collection of tours (generation)
 #include<cmath> //to round a floating pt
 #include "Tours.hpp"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>


 class Genetic {
    private: 
      std::vector<Tour> generation;
      Tour bestTour;
      int genSize;
      int numGens;
      int citiesPerGen;
      double mutPercent;
      double timeElapsed;

    public:
      Genetic(int genNum, int sizeGen, double percent, int numCities); //all thats needed to run the algorithm
      Genetic(); //default contructor
      void findBest(); 
      void createNextGen(); //next gen with the epcified mutations and one elite
      Tour getBestTour();//getters for private members
      double getTime();
      double getBestCost();
 };

#endif
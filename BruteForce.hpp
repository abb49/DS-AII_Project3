/************************************
 * Student Name: Atiye Buker
 * File Name: BruteForce.hpp
 * Project 3
 * 
 * Purpose: Declare the bruteforce class to 
 *   exacute the brute force algorithm for the 
 *   traveling salesman problem
 * ************************************/ 
#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP
#include "Tours.hpp"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

class BruteForce {
    private:
      int numCities;
      double bestCost;
      Tour bestTour;
      double timeElapsed;
      
    public:
      int getNumCities();
      double getBestCost();
      BruteForce(int cities);
      BruteForce();
      double getTime();

      void search();
};

#endif

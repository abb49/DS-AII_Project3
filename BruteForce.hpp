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

class BruteForce {
    private:
      int numCities;
      double bestCost;
      Tour bestTour;
      
    public:
      int getNumCities();
      double getBestCost();
      unsigned long int factorial(int n); //for number of permutations to check in search
      BruteForce(int cities);

      void search();
};

#endif

/************************************
 * Student Name: Atiye Buker
 * File Name: Tours.hpp
 * Project 3
 * 
 * Purpose: create the Tours class to manage permutations
 * ************************************/

#ifndef TOUR_HPP
#define TOUR_HPP
#include<iostream>

class Tour {
    private:
      int numCities;
      int* tour;
      double fitness;

      void swap(int a , int b); //helper for perm

      
    public:
      void perm();//create permutation
      void mutate();
      double getFitness();
      void calculateFitness(double arr[20][20]);
      Tour(int cities);//constructor
      ~Tour();
      Tour(const Tour& other);
      Tour& operator=(const Tour& other);
};

#endif
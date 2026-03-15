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
#include "matrix.hpp"

class Tour {
    private:
      int numCities;
      int* tour;
      double fitness;
      static double matrix[20][20];

      void swap(int a , int b); //helper for perm

      
    public:
      bool perm();//create permutation
      void mutate();
      double getFitness();
      static void makeMatrix(); //make the adjacency matrix for calcualting fitness
      void calculateFitness();
      void mix();//to make a more diverse generation in genetic algorithm
      Tour(int cities);//constructor
      Tour();
      ~Tour();
      Tour(const Tour& other);
      Tour& operator=(const Tour& other);
};

#endif
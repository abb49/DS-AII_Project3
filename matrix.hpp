/************************************
 * Student Name: Atiye Buker
 * File Name: matrix.hpp
 * Project 3
 * 
 * Purpose: declare functions to read in the distances to a 20 by 20 adjacency matrix
 * ************************************/
#ifndef MATRIX_HPP
#define MATRIX_HPP

double getDistance(double arr[20][20], int cityA, int cityB); //returns distance between two cities
void createMatrix(double (&arr)[20][20]);

#endif
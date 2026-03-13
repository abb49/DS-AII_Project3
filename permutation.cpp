/************************************
 * Student Name: Atiye Buker
 * File Name: permutation.cpp
 * Project 3
 * 
 * Purpose: function to create permutations
 * ************************************/
#include<iostream>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}


void perm(int (&s)[], int NUMELEMENTS) 
  {
     int m, k, p , q, i;
     m = NUMELEMENTS-2;
     while(s[m]>s[m+1])
     {
        m = m - 1;
     }
     k = NUMELEMENTS-1;
     while(s[m] > s[k])
     {
        k = k - 1;
     }
     swap(m,k);
     p = m + 1;
     q = NUMELEMENTS-1;
     while( p < q)
     {
       swap(p,q);
       p++;
       q--;
     }
   } 
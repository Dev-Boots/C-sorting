#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using std::cout; using std::endl; using std::cerr;
using std::ostream; using std::string; using std::ifstream;
using std::overflow_error; using std::underflow_error;
using std::vector;
using std::setw; using std::swap; using std::copy;

template<class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));

template<class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&));

template<class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&));

template<class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&)){
mergeSort(set, 0, set.size()-1, compare);
}

template<class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&)){
int mid;

if(low < high){
  mid = (low + high) /2;
//divide and conquer
  mergeSort(set, low, mid, compare);
  mergeSort(set, mid+1, high, compare);
//combine
  merge(set, low, mid, high, compare);
  }
}

template<class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&)){
vector<T> temp(high - low + 1);
int i = low; //sub for start of left sorted subvector
int j = mid+1; //sub for start of right sorted subvector
int k = 0;   //sub for start of merged vector

//while not at end of either subvector
while(i <= mid && j <= high){
     if(compare(set[j],set[i])){
	   temp[k] = set[j];
       j += 1;
       k += 1;
       }
     else{
	 temp[k] = set[i];
	 i += 1;
	 k += 1;
         }
     }
//copy over any remaining elements of left subvector
while(j <= mid){
     temp[k] = set[i];
     i += 1;
     k += 1;
     }
//copy over any remaining elements of right subvector
while(j <= high){
     temp[k] = set[j];
     j += 1;
     k += 1;
     }
//copy merged elemetns back into original vector
for(i = 0, j = low; j <= high; i++, j++){
   set[j] = temp[i];
   }
}
#endif

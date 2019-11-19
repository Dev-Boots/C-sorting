#ifndef QUICKSORTS_H
#define QUICKSORTS_H

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
using std::setw;
using std::swap;

template<class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));

template<class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

template<class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

template<class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&)){
quickSort(set, 0 ,set.size()-1, compare);
}

template<class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)){
int pivotPoint;

if(start < end){
pivotPoint = partition(set, start, end, compare);//get pivot point
quickSort(set, start, pivotPoint-1, compare);  //sort first sublist
quickSort(set, pivotPoint+1, end, compare);  //sort second sublist
  }
}

template<class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)){
int pivotIndex;
int mid;
T pivotVal;

mid = (start + end) /2;
swap(set[start],set[mid]);

pivotIndex = start;
pivotVal = set[start];

for(int scan = start+1; scan <= end; scan++){
   if(compare(set[scan], pivotVal)){
     pivotIndex++;
     swap(set[pivotIndex],set[scan]);
     }
   }
swap(set[start],set[pivotIndex]);
return pivotIndex;
}

#endif

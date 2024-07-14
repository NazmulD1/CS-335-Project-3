// Nazmul Dewan
// CSCI 335
// Project 3
// This file contains the functions the quickSelect1 function along with the necessary prototypes.
#ifndef QUICKSELECT1_HPP
#define QUICKSELECT1_HPP
#include <algorithm>
#include <chrono>
#include <vector>
#include <iostream>
using namespace std;

// Partitions the data based on the pivot and sets in the correct position
int partition(vector<int> &data, int l, int r);

// Applies quickselect to retrieve the needed element of the given data
int quickSelectv1(vector<int> &data, int l, int r, int k);

// Uses insertion to sort the data if it is 20 or less elements
void insertionSort(vector<int> &data, int l, int r);

// The function uses quickSelectv1 to find the min, 25, 50, 75, and max values
void quickSelect1(const std::string &header, std::vector<int> data);

#endif
// Nazmul Dewan
// CSCI 335
// Project 3
// This file contains the functions quickSelect2 along with the necessary prototypes.
#ifndef QUICKSELECT2_HPP
#define QUICKSELECT2_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
using namespace std;

// Partitions the data based on the pivot and sets in the correct position
int partitionv2(vector<int> &data, int l, int r);

// Applies quickselect to retrieve the needed element of the given data
int quickSelectv2(vector<int> &data, int l, int r, int k);

// Uses insertion to sort the data if it is 20 or less elements
void insertionSortv2(vector<int> &data, int l, int r);

// The function uses quickSelectv2 to find the min, 25, 50, 75, and max values
void quickSelect2(const std::string &header, std::vector<int> data);

#endif
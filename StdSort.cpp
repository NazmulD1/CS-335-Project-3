// Nazmul Dewan
// CSCI 335
// Project 3
// This file contains the implementation of the stdSort function.
#include "StdSort.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

// Function sorts the data using std::sort
void stdSort(const string &header, vector<int> data) {
 //const auto t1_start = chrono::steady_clock::now();

  // Sort the values in the data vector
  sort(data.begin(), data.end());

  // Calculate values of min, 25, 50, 75, and max
  int min = data[0];
  int max = data[data.size() - 1];
  int twentyfifth = data[(data.size() / 4) - 1];
  int fifty = data[data.size() / 2];
  int seventyfifth = data[((data.size() / 4) + (data.size() / 2)) - 1];


  /*const auto t1_end = std::chrono::steady_clock::now();
   int t1 = chrono::duration<double, std::micro>(t1_end - t1_start).count();
   cout << "Execution Time Of StdSort " << t1 << " Microseconds." << endl;*/

  
  // Prints the values of min, 25, 50, 75, and max
  cout << header << endl;
  cout << "Min: " << min << endl;
  cout << "P25: " << twentyfifth << endl;
  cout << "P50: " << fifty << endl;
  cout << "P75: " << seventyfifth << endl;
  cout << "Max: " << max << endl;
}

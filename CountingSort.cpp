// Nazmul Dewan
// CSCI 335
// Project 3
// This file contains the function implementations of Coutingsort along with the
// necessary prototypes.

#include "CountingSort.hpp"

void countingSort(const std::string &header, std::vector<int> data) {
  //const auto t1_start = chrono::steady_clock::now();

 // Establishes an unorded map to hold keys and values
  unordered_map<int, int> datahash;

  // Iterates through the data vector and adds the keys & values into the map
  for (int value : data) {
    datahash[value]++;
  }

  // Prints the header
  vector<pair<int, int>> sorteddata;

  // Establishes key and value
  int key, value;

  // Iterates through the map and adds the keys and values into a vector
  for (auto pair : datahash) {
    // Assigns the key and value to the variables
    key = pair.first;
    value = pair.second;
    // Adds the key and value into the vector
    sorteddata.push_back(make_pair(key, value));
  }

  // Sorts the vector in ascending order
  sort(sorteddata.begin(), sorteddata.end());

  // Calculate quartiles
  int p25_index = data.size() / 4;
  int p50_index = data.size() / 2;
  int p75_index = 3 * data.size() / 4;
  int count = 0;
  
  // Sets the values of the quartile to -1 
  int p25_found = -1, p50_found = -1, p75_found = -1;

  // Iterates through the sorted vector and finds the quartiles
  for (auto it = sorteddata.begin(); it != sorteddata.end(); it++) {

    // Increments the counter by the frequency
    count += it->second;

    // Checks if the p25_index is equal to or less than the count and p25_found is -1
    if (p25_index <= count && p25_found == -1) {
      // Sets the p25_found to the key
      p25_found = it->first;
    }
    // Checks if the p50_index is equal to or less than the count and p50_found is -1
    if (p50_index <= count && p50_found == -1) {
      
      // Sets the p50_found to the key
      p50_found = it->first;
    }
    // Checks if the p75_index is equal to or less than the count and p75_found is -1
    if (p75_index <= count && p75_found == -1) {
      // Sets the p75_found to the key
      p75_found = it->first;
      // Breaks the loop as we already found the 3 quartlies
      break;
    }
  }

  
  // Gets the min and max values
  int min = sorteddata.front().first;
  int max = sorteddata.back().first;

  
/*
  const auto t1_end = std::chrono::steady_clock::now();
   int t1 = chrono::duration<double, std::micro>(t1_end - t1_start).count();
   cout << "Execution Time Of Counting Sort " << t1 << " Microseconds." << endl;
*/

  // Prints the header, values, and number of unique numbers 
  cout << header << endl;
  cout << "Min: " << min << endl;
  cout << "P25: " << p25_found << endl;
  cout << "P50: " << p50_found << endl;
  cout << "P75: " << p75_found << endl;
  cout << "Max: " << max << endl;
  cout << "Unique: " << sorteddata.size() << endl;
}

// Nazmul Dewan
// CSCI 335
// Project 3
// This file implements the quickSelect2 function along with the necessary prototypes.
#include "QuickSelect2.hpp"

// Uses insertion to sort the data if it is 20 or less elements
void insertionSortv2(vector<int> &data, int l, int r) {
  for (int i = l + 1; i <= r; i++) {
    int key = data[i];
    int j = i - 1;
    while (j >= l && data[j] > key) {
      data[j + 1] = data[j];
      j = j - 1;
    }
    data[j + 1] = key;
  }
}

// Partitions the data based on the pivot and sets in the correct position
int partitionv2(vector<int> &data, int l, int r) {
  int x = data[r], i = l;
  for (int j = l; j <= r - 1; j++) {
    if (data[j] <= x) {
      swap(data[i], data[j]);
      i++;
    }
  }
  swap(data[i], data[r]);
  return i;
}

// Applies quickselect to retrieve the needed element of the given data
int quickSelectv2(vector<int> &data, int left, int right, vector<int> &k) {

  // Checks if the data is 20 or less elements
  if (right - left + 1 <= 20) {
    // Defaults to insertion sort if the data is 20 or less elements
    insertionSortv2(data, left, right);
  }
  // Retrieves the pivot
  int pivot = partitionv2(data, left, right);

  // Establishes 2 vectors to hold the left (less) and right (greater) values
  // from the piivot
  vector<int> leftsubarray;
  vector<int> rightsubarray;

  // Iterates through the data and adds the values to the left or right subarray
  for (auto it = k.begin(); it != k.end(); ++it) {
    // If the current element is greater than the pivot
    if (*it > pivot) {
      // Add it to the right subarray
      rightsubarray.push_back(*it);
    }
    // If the current element is less than the pivot
    else if (*it < pivot) {
      // Add it to the left subarray
      leftsubarray.push_back(*it);
    }
  }

  // If the both left and right subarrays are not empty
  if (!leftsubarray.empty() && !rightsubarray.empty()) {
    // Recursively calls itself (quickSelectv2) on the left and right subarrays
    quickSelectv2(data, left, pivot - 1, leftsubarray);
    quickSelectv2(data, pivot + 1, right, rightsubarray);
  }

  // If the left subarray is not empty
  else if (!leftsubarray.empty()) {
    // Recursively calls itself (quickSelectv2) on the left subarray
    return quickSelectv2(data, left, pivot - 1, leftsubarray);
  }

  // If the right subarray is not empty
  else if (!rightsubarray.empty()) {
    // Recursively calls itself (quickSelectv2) on the right subarray
    return quickSelectv2(data, pivot + 1, right, rightsubarray);
  }
  return 0;
}

// The function uses quickSelectv2 to find the min, 25, 50, 75, and max values
void quickSelect2(const std::string &header, std::vector<int> data) {

  // Sets the data size to a numeric value, datasize
  int datasize = data.size();

  // Establishes a vector to hold the k values
  vector<int> keys = {0, datasize / 4 - 1, datasize / 2 - 1, 3 * datasize / 4 - 1, datasize - 1};
  
  // const auto t1_start = chrono::steady_clock::now();

  // Calls the quickSelectv2 function to find the min, 25, 50, 75, and max
  // values
  quickSelectv2(data, 0, datasize - 1, keys);

  /*const auto t1_end = std::chrono::steady_clock::now();
   int t1 = chrono::duration<double, std::micro>(t1_end - t1_start).count();
   cout << "Execution Time Of QuickSelect2 " << t1 << " Microseconds." <<
   endl;*/

  // Prints the values of min, 25, 50, 75, and max
  cout << header << endl;
  cout << "Min: " << data[keys[0]] << endl;
  cout << "P25: " << data[keys[1]] << endl;
  cout << "P50: " << data[keys[2]] << endl;
  cout << "P75: " << data[keys[3]] << endl;
  cout << "Max: " << data[keys[4]] << endl;
}
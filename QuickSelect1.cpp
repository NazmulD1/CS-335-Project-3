// Nazmul Dewan
// CSCI 335
// Project 3
// This file contains the function implementations of quickSelect1 along with the necessary prototypes.
#include "QuickSelect1.hpp"

// Partitions the data based on the pivot and sets in the correct position
int partition(vector<int> &data, int l, int r) {
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

// Uses insertion to sort the data if it is 20 or less elements
void insertionSort(vector<int> &data, int l, int r) {
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

// Applies quickselect to retrieve the needed element of the given data, source, geeks for geeks
int quickSelectv1(vector<int> &data, int l, int r, int k) {

  // Checks if the data is 20 or less elements
  if (r - l + 1 <= 20) {
    // Defaults to insertion sort if the data is 20 or less elements
    insertionSort(data, l, r);
    return data[l + k - 1];
  }

  // Retrieves the pivot
  int pivot = partition(data, l, r);

  // If the pivot is the smallest element, return it
  if (pivot - l == k - 1) {
    return data[pivot];
  }
  // If the pivot is greater than k, then the element is in the left side of the
  // vector
  else if (pivot - l > k - 1) {
    return quickSelectv1(data, l, pivot - 1, k);
  } else {
    // If the pivot is less than k, then the element is in the right side of the
    // array
    return quickSelectv1(data, pivot + 1, r, k - pivot + l - 1);
  }
  return 0;
}

// The function uses quickSelectv1 to find the min, 25, 50, 75, and max values
void quickSelect1(const std::string &header, std::vector<int> data) {

  // const auto t1_start = chrono::steady_clock::now();

  // Get the 50th percentile
  int fifty = quickSelectv1(data, 0, data.size() - 1, data.size() / 2);

  // Get the 25th percentile
  int twentyfifth = quickSelectv1(data, 0, data.size() / 2, data.size() / 4);

  // Get the 75th percentile
  int seventyfifth =
      quickSelectv1(data, 0, data.size() - 1, 3 * data.size() / 4);

  // Sets min to the 25 index
  int min = data[(data.size() / 4)];

  // Sets max to the last index
  int max = data[data.size()-1];

  // Searches for the max after the 75th percentile
  for (auto it = (3 * (data.size() / 4)) + 1; it != data.size(); it++) {
    // If the current element is greater than the max, update max to the current
    // value
    if (data[it] > max) {
      max = data[it];
    }
  }

  // Searches for the minimum before the 25th percentile
  for (auto it = (data.size() / 4) - 1; it != 0; it--) {
    // If the current element is less than the min, update min to the current
    // value
    if (data[it] < min) {
      min = data[it];
    }
  }

  /*const auto t1_end = std::chrono::steady_clock::now();
 int t1 = chrono::duration<double, std::micro>(t1_end - t1_start).count();
 cout << "Execution Time Of QuickSelect1 " << t1 << " Microseconds." <<endl;*/

  // Prints the values of min, 25, 50, 75, and max
  cout << header << endl;
  cout << "Min: " << min << endl;
  cout << "P25: " << twentyfifth << endl;
  cout << "P50: " << fifty << endl;
  cout << "P75: " << seventyfifth << endl;
  cout << "Max: " << max << endl;
}
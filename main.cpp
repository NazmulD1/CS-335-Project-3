// Nazmul Dewan
// CSCI 335
// Project 3
// This contains the file needed to run Quickselect1, Quickselect2, Countingsort, and Stdsort files.
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"
#include "StdSort.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  // Opens the file
  ifstream fin("testinput1.txt");

  // Vector to store weights
  vector<int> weights;

  if (fin.fail()) {
    cout << "Error: could not open file" << endl;
    exit(1);
  }

  // Read the first line (header)
  string header;
  getline(fin, header);

  // Read each line and extract weights
  string line;
  while (getline(fin, line)) {
    istringstream iss(line);
    int weight;
    while (iss >> weight) {
      weights.push_back(weight);
    }
  }

  // Close the file
  fin.close();

  // Executes Std Sort
  cout << "Std Sort" << endl;
  stdSort(header, weights);
  cout << endl;

  // Executes QS1
  cout << "Quick Select 1" << endl;
  quickSelect1(header, weights);
  cout << endl;
  
  // Executes QS2
  cout << "Quick Select 2" << endl;
  quickSelect2(header, weights);
  cout << endl;

  
  // Executes Counting Sort
  cout << "Counting Sort" << endl;
  countingSort(header, weights);
  cout << endl;

  return 0;
}

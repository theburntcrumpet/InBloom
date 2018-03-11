// BloomFilter.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include "BloomFilter.h"
using namespace std;

int main(){
  BloomFilter bloomFilter(1000);
  string strInput;
  int nOption;
  for(;;){
    cout << endl << "Select an option:\n\n\t1. Add String\n\t2. Query String\n\nOption must be int: ";
    cin >> nOption;
    switch (nOption) {
      case 1:
        cout << endl << "Enter String to Add: ";
        cin >> strInput;
        bloomFilter.Insert(strInput);
        cout << endl << "Inserted!";
        break;

      case 2:
        cout << endl << "Enter String to Query: ";
        cin >> strInput;
        cout << endl << "\"" << strInput << "\" " << (bloomFilter.Query(strInput) ? "is probably in " : "is definitely NOT in ") << "bloom filter";
        break;
      default:
        cout << endl << "Invalid Option!";
        break;
    }
  }
  return 0;
}

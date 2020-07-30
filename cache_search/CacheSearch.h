/*
 * Name: Pierce Tarleton
 * Date Submitted: 4/5/2019
 * Lab Section: 002
 * Assignment Name: Lab 10 Cache Search
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <deque>
#include <fstream>

using namespace std;


class CacheSearch{
  private:
    map <string, double>cache;
    string fileName;
    int numberOfQuest;
    deque <string> Recent;
  public:
    CacheSearch(string inputFile); // pass in the name of the file to be used for input
    ~CacheSearch();
    double search(string question); // query is string, return value is double that is associated with string in file
    bool stored(string); // returns true if parameter is currently stored whatever data structure you are using to accomplish search
};

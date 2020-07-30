/*
 * Name: Pierce Tarleton
 * Date Submitted: 4/5/2019
 * Lab Section: 002
 * Assignment Name: Lab 11 Spy Catcher
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


class SpyCatcher{
  private:
    vector<string> files;
    map<string, vector<string>> peopleL;
    map<string, int> people;
  public:
    SpyCatcher();
    ~SpyCatcher();
    void readAllLists(string filename);
    string findSpy(vector<string>);
    vector<string> findSpies();
};

/*
 * Name:Pierce Tarleton
 * Date Submitted:4/24/2019
 * Lab Section: 4
 * Assignment Name: Supply chain
 */
// This code does not work it does not add the roads to the vector<vector<road>> distance correctly which is it is not able to compleat the rest of the operations to find the max follow

#pragma once

#include <string>
#include <map>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <deque>
#include "heap.h"

using namespace std;

// struct to hold the edges
struct road{
    int ID;
    string start;
    string end;
    int cap;
    int cost;
};

void add_road(string filename);
unordered_map <int, double> organizeLogistics(vector<pair<string,double>> start, vector <pair<string,double>> end);

class worldM {
 private:
    unordered_map <int, double> RoadM;
    map <string, vector<road>> CityM;
    vector <road> paths;
 public:
    void add_road(string file);
    unordered_map <int, double> Logistics(vector<pair<string,double>> start, vector <pair<string,double>> end);
};

worldM maps;

void add_road(string filename){
    maps.add_road(filename);
}


// reads in the information from the file
void worldM::add_road(string filename) {
    ifstream Infile(filename);
    road Temp;
    while(!(Infile.eof())){//infinite loop here ???
        Infile>>Temp.ID;
        Infile>>Temp.start;
        Infile>>Temp.end;
        Infile>>Temp.cap;
        Infile>>Temp.cost;
        CityM[Temp.start].push_back(Temp);
    }
}

unordered_map <int, double> organizeLogistics(vector<pair<string,double>> start, vector <pair<string,double>> end) {
    unordered_map <int, double> roads = maps.Logistics(start, end);
    return roads;
}

unordered_map <int, double> worldM::Logistics(vector<pair<string,double>> start, vector <pair<string,double>> end) {
    deque <road>order;
    vector<road> Froads;
    vector <vector<road>> distance;
    vector <road> TempVR;
    string startL = start[0].first;
    road temp1 = CityM[startL][0];
    road temp2;
    order.push_back(temp1);
    
    //double unitsTT = 0; // number of units to transport or transported
    //double unitsAD = end[0].second; //the numbrer of units that a supposed to be at the end destination
    string endL = end[0].first;
    bool visit = true;
    string currentC = startL; //current city
    double unitCap = 100000000;
    string capCity = " ";
    vector <road>deadEnd;
    int number = 0;
    int number2 = 0;
    int number3 = 0;
    int CityMS;
    cout<<end[0].first<<endl;
    for(auto i:CityM){
        for(auto p: i.second){
            CityMS++;
            RoadM.emplace(p.ID, 0.0);
        }
    }
    while (number != 100){
        unitCap = 100000000;
        
        // iterate through the map using BFS and adds the path that are found to the distance vector
        while (!order.empty()) {
        temp2 = order.front();
        order.pop_front();
            for (int o = 0; o<CityM[temp2.start].size(); o++) {
                if(CityM[temp2.start][o].cap != RoadM[CityM[temp2.start][o].ID]&& temp2.start != endL){
                    for(int i = 0; i<CityM[CityM[temp2.start][o].end].size(); i++){
                        if(number3 != CityMS-1){
                                number3++;
                                for(auto r: order){
                                    if(temp1.ID == r.ID){
                                        visit = false;
                                    }
                                }
                                if(visit){
                                    order.push_back(temp1);
                                    visit = true;
                                }
                        }
                    }
                    if(temp2.start == startL){
                        TempVR.push_back(CityM[temp2.start][o]);
                        distance.push_back(TempVR);
                        TempVR.clear();
                    }
                    
                    // this causes multiple of the same road to be added, this is the main issue
                    for(int i = 0; i<distance.size(); i++){
                        number2++;
                            if(distance[i].back().end == temp2.start){
                                if(o == 0){
                                    distance[i].push_back(temp2);
                                }
                                if(o > 0){
                                    TempVR.clear();
                                    TempVR = distance[i];
                                    distance.push_back(TempVR);
                                    distance.back().push_back(temp2);
                                }
                            }
                            number2++;
                            if(number2 == 1){
                                break;
                            }
                    }
                }
                if(number2 == 40){
                    break;
                }
            }
        }
        
        // determins the max flow for each path and then adds that to the double value of each of the roads on the path in the unordered_map RoadM 
        for(auto i: distance){
            if(i.back().end == endL){
                for(auto p: i){
                    if(unitCap > (p.cap - RoadM[p.ID])){
                        unitCap += p.cap - RoadM[p.ID];
                    }
                }
                cout<<endl;
                for(auto o: i){
                    RoadM[o.ID] += unitCap;
                }
            }
        }
        number++;
    }
    return RoadM;
}

/*
 * Name:Pierce Tarleton
 * Date Submitted:4/24/2019
 * Lab Section: 4
 * Assignment Name: Supply chain
 */


#include <fstream>
#include <string>
#include <tuple> 
#include <map>
#include <unordered_map>
#include <vector>
#include <math.h>


using namespace std;

struct stat{
    string Class;
    int Hp;
    int speed;
    int power;
    int randge;
    string bestA;
};

struct Unit {
    int ID;
    string unitClass;
    double currentHP;
    int speed;
    double power;
    tuple<int,int,int> currentLocation;
    int range;
    Unit(int id, string cl, double chp, int spd, double pwr, 
    tuple<int,int,int> curloc, int rng) :
    ID(id), unitClass(cl), currentHP(chp), speed(spd), power(pwr), 
    currentLocation(curloc), range(rng) {}
};

struct Order {
    vector<string> actions; // contains consecutive moves up to the value of speed  //what dose this mean
    vector<char> moveSequence; // if moving, contains 'L','R','U','D' to give in what direction to move 
    vector<int> targetIDs; // a vector giving the ID values of each unit to be targeted (in order).
    // to target the same unit until destruction, then move on, put the first unit's targetID X times,
    // where X is your speed; then put the next unit's targetID.
    string targetClass;  // if no targetIDs (or if all targetIDs destroyed), unit will target whatever
    // unit class is specified here until they are all destroyed.
};

void readStats(string file);
unordered_map<string, Order> fight(vector <Unit> yourUnits, vector<Unit> theirUnits);
    
map<string, stat> stats;
 
void readStats(string file){
    
    // declaration of variables
    ifstream InFile(file);
    int randge, speed;
    double power, Hp;
    string UClass, name, bestA;
    stat unit;
    
    // reads in the stats of the different types of units
    while (!InFile.eof()){
        InFile>>name;
        InFile>>UClass;
        InFile>>Hp;
        InFile>>speed;
        InFile>>power;
        InFile>>randge;
        InFile>>bestA;
        unit.Class = UClass;
        unit.Hp = Hp;
        unit.speed = speed;
        unit.power = power;
        unit.randge = randge;
        unit.bestA = bestA;
        stats[name] = unit;
    }
}


// creates the orders for the unitst to carry out and then returns them so that they can be carried out
unordered_map<string, Order> fight(vector <Unit> yourUnits, vector<Unit> theirUnits){
    
    // variable declarations
    unordered_map<string, Order> cammands;
    int strinth = 0;
    
    
    for(auto i: yourUnits){
        for(auto p: theirUnits){
            
            // Determins if the target is out of range and if it is out of range then it moves in the direction that the unit is in.
            if(stats[i.unitClass].bestA == stats[p.unitClass].Class){
                if(stats[i.unitClass].randge < sqrt(pow(get<0>(i.currentLocation) - get<0>(p.currentLocation), 2) + pow(get<1>(i.currentLocation) - get<1>(p.currentLocation), 2))){
                    if(abs(get<0>(i.currentLocation) - get<0>(p.currentLocation)) > stats[i.unitClass].randge){
                        cammands[to_string(i.ID)].actions.push_back("move");
                        if(get<0>(i.currentLocation) - get<0>(p.currentLocation) > 0){
                            cammands[to_string(i.ID)].moveSequence.push_back('D');// distance to traval = stats[p.Class].randge;
                        }
                        else if(get<0>(i.currentLocation) - get<0>(p.currentLocation) < 0){
                            cammands[to_string(i.ID)].moveSequence.push_back('U');// distance to traval = stats[p.Class].randge;
                        }
                    }
                    if(abs(get<1>(i.currentLocation) - get<1>(p.currentLocation)) > stats[i.unitClass].randge){
                        if(get<1>(i.currentLocation) - get<1>(p.currentLocation) > 0){
                            cammands[to_string(i.ID)].moveSequence.push_back('L');// distance to traval = stats[p.Class].randge;
                        }
                        else if(get<1>(i.currentLocation) - get<1>(p.currentLocation) < 0){
                            cammands[to_string(i.ID)].moveSequence.push_back('R');// distance to traval = stats[p.Class].randge;
                        }
                    }
                }
            }
            
            // enters in the orders to fight and who to fight which is who ever they are best against
            if(stats[i.unitClass].bestA == stats[p.unitClass].Class){
                cammands[to_string(i.ID)].targetIDs.push_back(p.ID);
                cammands[to_string(i.ID)].actions.push_back("fight");
            }
        }
        
        // this finds the strongest unit that the opentent has and tells the unit to attack it if there are not units left that it is best against
        for(auto i: yourUnits){
            for(auto p: theirUnits){
                if(stats[i.unitClass].bestA != stats[p.unitClass].Class){
                    if(p.power > strinth){
                       cammands[to_string(i.ID)].targetClass = p.unitClass;
                    }
                }
            }
        }
    }
    return cammands;
}
        

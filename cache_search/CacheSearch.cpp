#include "CacheSearch.h"
#include <iostream>
//#include <fstream>

using namespace std;

//saves the name of the imput file.
CacheSearch::CacheSearch(string inputFile){
    fileName = inputFile;
}

CacheSearch::~CacheSearch(){
    
}

//gets the answer to the question and returns it
double CacheSearch::search(string question){
    
    // Variables
    bool store = stored(question);
    ifstream InFile(fileName);
    double answer = 0;
    string file_Q = " ";
    
    // checks if answer is stored in the cache
    if(store){
        Recent.push_back(Recent.front());
        Recent.pop_front();
        return cache[question];
    }
    
    // If the answer is not stored in the cache then it reads in from the file until the answer is found adding the answer to the cache until the cache is full, then replacing the least recent answer to be stored by taking the value of the front of the Recent vactot which stores the order in which the answers were stored in the cache.
    while (!InFile.eof()){
        InFile>>file_Q;
        InFile>>answer;
        if(file_Q == question){
            if(Recent.size() == 5){
                cache.erase(Recent.front());
                Recent.pop_front();
                cache[question] = answer;
                Recent.push_back(question);
            }
            else if(Recent.size() <= 5){
                numberOfQuest++;
                cache[question] = answer;
                Recent.push_back(question);
            }
            return answer;
        }
    }
    InFile.close();
    return answer;
}

// Deternings if the answere is stroed in the cache returns ture if yes and false if it is not in the cache.
bool CacheSearch::stored(string question){
    if(cache.count(question) == 1){
        return true;
    }
    return false;
}

/*
 * Name:Pierce Tarleton
 * Date Submitted:4/24/2019
 * Lab Section: 4
 * Assignment Name: Pathfinder
 */



#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

struct node {
    int gold;
    int bomb;
    int depth;
    int posR;
    int posC;
    char value;
    node* R;
    node* L;
    node* U;
    node* D;
    node* prev;
};


template<size_t rows, size_t cols>
//vector<char> pathfinder(/*char (&maze)[row][cols]*/);
vector<char> pathfinder(char (&maze)[rows][cols]){// make it so that the array is passed in
    
    // Declaration and initialization of Variables
    node* start = new node;
    int number = 0;
    int prevLoop;
    vector<pair<int, int>> loopPrevent;
    vector<pair<int, int>> starts;
    vector<vector<char>> paths;
    vector<char> NoPath;
    vector<char> steps;
    pair<int, int> tempS;
    pair<int, int> tempL;
    start->gold = 0;
    start->bomb = 0;
    start->depth = 0;
    start->posR = 0;
    start->posC = 0;
    start->R = NULL;
    start->L = NULL;
    start->U = NULL;
    start->D = NULL;
    start->prev = NULL;
    start->value = 'S';
    node* temp = start;
    node* temp2;
    int depth = 0;
    int bomb = 0;
    int gold = 0;
    int posR = 100000;
    int posC = 100000;
    int posCF, posRF;
    bool noPath = true;
    bool goBack = true;
    bool contin = true;
    NoPath.push_back('\0');
    
    //finds the start point
    for(int i = 0; i<rows; i++){
        for(int p = 0; p<cols; p++){
            if(maze[i][p] == 's'){
                posR = i;
                posC = p;
                start->posR = i;
                start->posC = p;
            }
        }
    }
    
    //finds the end point
    for(int i = 0; i<rows; i++){
        for(int p = 0; p<cols; p++){
            if(maze[i][p] == 'f'){
                posRF = i;
                posCF = p;
            }
        }
    }
    
    //finds any additional startng points
    for(int i = 0; i<rows; i++){
        for(int p = 0; p<cols; p++){
            if(maze[i][p] == 's'){
                tempS.first = i;
                tempS.second = p;
                starts.push_back(tempS);
                if((posC - posCF > abs(p - posCF)) && 
                  (posR - posRF > abs(i - posRF))){
                    posR = i;
                    posC = p;
                    start->posR = i;
                    start->posC = p;
                }
            }
        }
    }
    
    // checks if there is a path to the finish and if not it returns \0
    if(maze [posR + 1][posC] == 'e' || maze [posR + 1][posC] == 'g' || maze [posR + 1][posC] == 'b'){
        noPath = false;
    }
    else if(maze [posR - 1][posC] == 'e' || maze [posR - 1][posC] == 'g' || maze [posR - 1][posC] == 'b'){
        noPath = false;
    }
    else if(maze [posR][posC + 1] == 'e' || maze [posR][posC + 1] == 'g' || maze [posR][posC + 1] == 'b'){
        noPath = false;
    }
    else if(maze [posR][posC - 1]  == 'e'|| maze [posR][posC - 1] == 'g' || maze[posR][posC - 1] == 'b'){
        noPath = false;
    }
    if(noPath){
        steps.push_back('\0');
        return steps;
    }
    
    //finds the path
    while (maze [posR][posC] != 'f'){
        goBack = true;
        
        // checks if there is a path out of the start position if not it returns a null character
        if(temp->value == 'S'){
            if((temp->U != NULL || maze[posR - 1][posC] == 'w' || posR == 0) && (temp->D != NULL || maze[posR + 1][posC] == 'w' || posR < rows-1) && (temp->R != NULL || maze[posR][posC] == 'w' || posC < cols-1) && (temp->L != NULL || maze[posR - 1][posC] == 'w' || posC == 0)){
                    return NoPath;
            }
        }
        
        // checks if the pasition is in line with the finish and if it is it goes toward the finish till it hits a wall or reaches the finish to prevent going around in circles around the finish if it is a big open space
        if(posC == posCF && posR < posRF){
            while (maze[posR + 1][posC] != 'w' && maze[posR][posC] != 'f' && 
                   posR < rows-1){
                depth++;
                posR += 1;
                temp2 = new node;
                temp2->gold = gold;
                temp2->bomb = gold;
                temp2->depth = depth;
                temp2->posR = posR;
                temp2->posC = posC;
                tempL.first = posR;
                tempL.second = posC;
                temp2->R = NULL;
                temp2->L = NULL;
                temp2->U = NULL;
                temp2->D = NULL;
                temp2->prev = temp;
                temp2->value = 'D';
                steps.push_back('D');
                loopPrevent.push_back(tempL);
                temp->D = temp2;
                temp = temp->D;
                goBack = false;
            }
        }
        else if(posR == posRF && posC < posCF){
                while(maze[posR][posC + 1] != 'w' && maze[posR][posC] != 'f' && 
                      posC < cols-1){
                        depth++;
                        posC += 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = gold;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        tempL.first = posR;
                        tempL.second = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'R';
                        temp->R = temp2;
                        temp = temp->R;
                        steps.push_back('R');
                        loopPrevent.push_back(tempL);
                    }
                    goBack = false;
            }
        else if(posC == posCF && posR > posRF){
            if((temp->value != 'D') && (temp->posR != 0) && (maze [posR - 1][posC] == 'e' || maze [posR - 1][posC] == 'g' || maze [posR - 1][posC] == 'b') && temp->U == NULL && maze[posR][posC] != 'f'){
                    while (maze[posR - 1][posC] != 'w' && maze[posR][posC] != 'f' && posR != 0){
                        depth++;
                        posR -= 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = gold;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        tempL.first = posR;
                        tempL.second = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'U';
                        temp->U = temp2;
                        temp = temp->U;
                        steps.push_back('U');
                        loopPrevent.push_back(tempL);
                        goBack = false;
                }
            }
            else if(posR == posRF && posC > posCF){
                while(maze[posR][posC - 1] != 'w' && maze[posR][posC] != 'f' && 
                     posC != 0){
                    depth++;
                    posC -= 1;
                    temp2 = new node;
                    temp2->gold = gold;
                    temp2->bomb = gold;
                    temp2->depth = depth;
                    temp2->posR = posR;
                    temp2->posC = posC;
                    tempL.first = posR;
                    tempL.second = posC;
                    temp2->R = NULL;
                    temp2->L = NULL;
                    temp2->U = NULL;
                    temp2->D = NULL;
                    temp2->prev = temp;
                    temp2->value = 'L';
                    temp->L = temp2;
                    temp = temp->L;
                    steps.push_back('L');
                    loopPrevent.push_back(tempL);
                    goBack = false;    
                }
            }
        }
        
        // Checks if the positon has already been visited and if it has not and is a path then it goes there
        if((temp->value != 'U') && (posR < rows-1) && (maze [posR + 1][posC] == 'e' || maze [posR + 1][posC] == 'g' || maze [posR + 1][posC] == 'b') && temp->D == NULL && maze[posR][posC] != 'f'){
            
            //to prevent loops
            if(steps.size()>=3){
                prevLoop = steps.size();
                if(steps[prevLoop-1] == 'R' && steps[prevLoop-2] == 'U' && steps[prevLoop-3] == 'L'){
                    posC -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posR +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posC +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    while(maze[posR - 1][posC] != 'w' && posR != 0){
                        depth++;
                        posR -= 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = gold;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        tempL.first = posR;
                        tempL.second = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'U';
                        temp->U = temp2;
                        temp = temp->U;
                        steps.push_back('U');
                        loopPrevent.push_back(tempL);
                        goBack = false;
                    }
                    contin = false;
                }
                if((steps[prevLoop-1] == 'L' && steps[prevLoop-2] == 'U' && steps[prevLoop-3] == 'R')){ 
                    posC +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posR +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posC -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    while(maze[posR - 1][posC] != 'w' && posR != 0){
                        depth++;
                        posR -= 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = gold;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        tempL.first = posR;
                        tempL.second = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'U';
                        temp->U = temp2;
                        temp = temp->U;
                        steps.push_back('U');
                        loopPrevent.push_back(tempL);
                        goBack = false;
                    }
                    contin = false;
                }
            }
            
            
            // to go to the position that has been determined to be a path and not loop
            if(contin){
                depth++;
                posR += 1;
                temp2 = new node;
                temp2->gold = gold;
                temp2->bomb = gold;
                temp2->depth = depth;
                temp2->posR = posR;
                temp2->posC = posC;
                tempL.first = posR;
                tempL.second = posC;
                temp2->R = NULL;
                temp2->L = NULL;
                temp2->U = NULL;
                temp2->D = NULL;
                temp2->prev = temp;
                temp2->value = 'D';
                steps.push_back('D');
                loopPrevent.push_back(tempL);
                temp->D = temp2;
                temp = temp->D;
                goBack = false;
            }
            contin = true;
        }
        else if((posC < cols-1)&& temp->value != 'L' && (maze [posR][posC + 1] == 'e' || maze [posR][posC + 1] == 'g' || maze [posR][posC + 1] == 'b') && temp->R == NULL && maze[posR][posC] != 'f'){
            if(steps.size()>=3){
                prevLoop = steps.size();
                if(steps[prevLoop-1] == 'D' && steps[prevLoop-2] == 'L' && steps[prevLoop-3] == 'U'){
                    posR -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posC +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posR +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    while(maze[posR][posC - 1] != 'w' && posC != 0){
                        depth++;
                        posC -= 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = bomb;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        tempL.first = posR;
                        tempL.second = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'L';
                        temp->L = temp2;
                        temp = temp->L;
                        steps.push_back('L');
                        loopPrevent.push_back(tempL);
                        goBack = false;
                    }
                    contin = false;
                }
                else if((steps[prevLoop-1] == 'U' && steps[prevLoop-2] == 'L' && steps[prevLoop-3] == 'D')){
                    posR +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posC +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posR -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    while(maze[posR][posC - 1] != 'w' && posC != 0){
                        depth++;
                        posC -= 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = bomb;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        tempL.first = posR;
                        tempL.second = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'L';
                        temp->L = temp2;
                        temp = temp->L;
                        steps.push_back('L');
                        loopPrevent.push_back(tempL);
                        goBack = false;
                    }
                    contin = false;
                }
            }
            
            // to go to the position that has been determined to be a path and not loop
            if(contin){
                depth++;
                posC += 1;
                temp2 = new node;
                temp2->gold = gold;
                temp2->bomb = gold;
                temp2->depth = depth;
                temp2->posR = posR;
                temp2->posC = posC;
                tempL.first = posR;
                tempL.second = posC;
                temp2->R = NULL;
                temp2->L = NULL;
                temp2->U = NULL;
                temp2->D = NULL;
                temp2->prev = temp;
                temp2->value = 'R';
                temp->R = temp2;
                temp = temp->R;
                steps.push_back('R');
                loopPrevent.push_back(tempL);
                goBack = false;
            }
            contin = true;
        }
        else if((temp->value != 'D') && (temp->posR != 0) && (maze [posR - 1][posC] == 'e' || maze [posR - 1][posC] == 'g' || maze [posR - 1][posC] == 'b') && temp->U == NULL && maze[posR][posC] != 'f'){
            if(steps.size()>=3){
                prevLoop = steps.size();
                if(steps[prevLoop-1] == 'R' && steps[prevLoop-2] == 'U' && steps[prevLoop-3] == 'L'){
                    posC -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posR -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posC +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    while(maze[posR - 1][posC] != 'w' && posR != 0){
                        depth++;
                        posR += 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = gold;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        tempL.first = posR;
                        tempL.second = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'D';
                        steps.push_back('D');
                        loopPrevent.push_back(tempL);
                        temp->D = temp2;
                        temp = temp->D;
                        goBack = false;
                    }
                    contin = false;
                }
                if((steps[prevLoop-1] == 'L' && steps[prevLoop-2] == 'U' && steps[prevLoop-3] == 'R')){
                    posC +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posR -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posC -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    while(maze[posR - 1][posC] != 'w' && posR != 0){
                        depth++;
                        posR += 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = gold;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        tempL.first = posR;
                        tempL.second = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'D';
                        steps.push_back('D');
                        loopPrevent.push_back(tempL);
                        temp->D = temp2;
                        temp = temp->D;
                        goBack = false;
                    }
                    contin = false;
                }
            }
            
            // to go to the position that has been determined to be a path and not loop
            if(contin){
                depth++;
                posR -= 1;
                temp2 = new node;
                temp2->gold = gold;
                temp2->bomb = gold;
                temp2->depth = depth;
                temp2->posR = posR;
                temp2->posC = posC;
                tempL.first = posR;
                tempL.second = posC;
                temp2->R = NULL;
                temp2->L = NULL;
                temp2->U = NULL;
                temp2->D = NULL;
                temp2->prev = temp;
                temp2->value = 'U';
                temp->U = temp2;
                temp = temp->U;
                steps.push_back('U');
                loopPrevent.push_back(tempL);
                goBack = false;
            }
            contin = true;
        }
        else if(temp->value != 'R' && posC != 0 && (maze [posR][posC - 1]  == 'e'|| maze [posR][posC - 1] == 'g' || maze[posR][posC - 1] == 'b') && temp->L == NULL && maze[posR][posC] != 'f'){
            if(steps.size()>=3){
                prevLoop = steps.size();
                if((steps[prevLoop-1] == 'D' && steps[prevLoop-2] == 'R' && steps[prevLoop-3] == 'U')){
                    posR -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posC -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posR +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    while(maze[posR][posC + 1] != 'w' && posC < cols-1){
                        depth++;
                        posC += 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = gold;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'R';
                        temp->R = temp2;
                        temp = temp->R;
                        steps.push_back('R');
                        loopPrevent.push_back(tempL);
                        goBack = false;
                    }
                    contin = false;
                }
                else if((steps[prevLoop-1] == 'U' && steps[prevLoop-2] == 'R' && steps[prevLoop-3] == 'D')){
                    posR +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posC -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    posR -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                    while(maze[posR][posC + 1] != 'w' && posC < cols-1){
                        depth++;
                        posC += 1;
                        temp2 = new node;
                        temp2->gold = gold;
                        temp2->bomb = gold;
                        temp2->depth = depth;
                        temp2->posR = posR;
                        temp2->posC = posC;
                        tempL.first = posR;
                        tempL.second = posC;
                        temp2->R = NULL;
                        temp2->L = NULL;
                        temp2->U = NULL;
                        temp2->D = NULL;
                        temp2->prev = temp;
                        temp2->value = 'R';
                        temp->R = temp2;
                        temp = temp->R;
                        steps.push_back('R');
                        loopPrevent.push_back(tempL);
                        goBack = false;
                    }
                    contin = false;
                }
                
                // to go to the position that has been determined to be a path and not loop
                if(contin){
                    depth++;
                    posC -= 1;
                    temp2 = new node;
                    temp2->gold = gold;
                    temp2->bomb = gold;
                    temp2->depth = depth;
                    temp2->posR = posR;
                    temp2->posC = posC;
                    tempL.first = posR;
                    tempL.second = posC;
                    temp2->R = NULL;
                    temp2->L = NULL;
                    temp2->U = NULL;
                    temp2->D = NULL;
                    temp2->prev = temp;
                    temp2->value = 'L';
                    temp->L = temp2;
                    temp = temp->L;
                    steps.push_back('L');
                    loopPrevent.push_back(tempL);
                    goBack = false;
                }
                contin = true;
            }
        }
        
        // determins if the end has been reached or the timeout has been reached
        // it is thirty because it goes to an infinit loop other wize? don't understand why it would not stop after the spesified number of loops even if it is over 50
        number++;
        if(number == 30){
            if(maze[posR][posC] == 'f'){
                paths.push_back(steps);
            }
            if(!starts.empty()){
                starts.pop_back();
                steps.clear();
                loopPrevent.clear();
                tempS = starts.back();
                posR = tempS.first;
                posC = tempS.second;
            }
            else{
                break;
            }
        }
        
        // determins wether to go backwards and if yes then it goes back
        else if (temp->value == start->value){
            goBack = false;
        }
        if(!steps.empty()){
            if(goBack){
                depth--;
                if(temp->value == 'D'){
                    posR -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                }
                if(temp->value == 'R'){
                    posC -=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                }
                if(temp->value == 'U'){
                    posR +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                }
                if(temp->value == 'L'){
                    posC +=1;
                    steps.pop_back();
                    loopPrevent.pop_back();
                }
                temp = temp->prev;
            }
        }
    }
    
    // returns the vectors that have the moves that make up the path
    if(!steps.empty()){
    }
    if(paths.empty()){
        steps.push_back('\0');
    }
    if(!paths.empty()){
    steps = paths[0];
        for(auto i: paths){
            if(i.size() < steps.size()){
                steps = i;
            }
        }
    }
    return steps;
}

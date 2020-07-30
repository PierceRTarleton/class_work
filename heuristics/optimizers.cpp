#include "optimizers.h"
//#include "tests.h"
#include <iostream>

using namespace std;

//Constructor
optimizers::optimizers(function<double(double,double)> func,double xMin, double xMax, double yMin, double yMax){
    this->func = func;
    this->xMin = xMin;
    this->xMax = xMax;
    this->yMin = yMin;
    this->yMax = yMax;
}

//checks which of the eight points around the Current position and move to the poin that is lowest, if it is lower than the current position
optimizers::minimum_value optimizers::greedy(){
    
    //declaration of variables
    random_device random;
    bool go = true;
    double tempY, tempX;
    double x =(xMin + xMax)/2;
    double y = (yMax + yMin)/2;
    tempX = x;
    tempY = y;
    optimizers::minimum_value Current(func(x, y), x, y);
    
    //while loop to search for the lowest point
    while(go){
        
        //exits the loop if the current position is the smallest
        go = false;
        
        //this prevents the program from going outside of the domain given for the equation
        if(x < xMin){
            x = (xMin + xMax)/2;
        }
        if(x > xMax){
            x = (xMin + xMax)/2;
        }
        if(y > yMax){
            y = (yMax + yMin)/2;
        }
        if(y < yMin){
            y = (yMax + yMin)/2;
        }
        
        //checks the points around the current position to determin which is the smallest and then it makes that position the new Current position.
        if(Current.value > func(x-1, y)){
            if(func(x+1, y) > func(x-1, y)){
                if(func(x+1, y+1) > func(x-1, y)){
                    if(func(x+1, y - 1) > func(x-1, y)){
                        if(func(x-1, y-1) > func(x-1, y)){
                            if(func(x, y+1) > func(x-1, y)){
                                if(func(x, y-1) > func(x-1, y)){
                                    if(func(x - 1, y+1) > func(x-1, y)){
                                        x = x - 1;
                                        y = y;
                                        Current.value = func(x, y);
                                        Current.x = x;
                                        Current.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(Current.value > func(x+1, y)){
            if(func(x-1, y) > func(x+1, y)){
                if(func(x+1, y+1) > func(x+1, y)){
                    if(func(x+1, y - 1)> func(x+1, y)){
                        if(func(x-1, y-1) > func(x+1, y)){
                            if(func(x, y+1) > func(x+1, y)){
                                if(func(x, y-1) > func(x+1, y)){
                                    if(func(x - 1, y+1) > func(x+1, y)){
                                        x = x + 1;
                                        y = y;
                                        Current.value = func(x, y);
                                        Current.x = x;
                                        Current.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(Current.value > func(x+1, y+1)){
            if(func(x+1, y) > func(x+1, y+1)){
                if(func(x-1, y) > func(x+1, y+1)){
                    if(func(x+1, y - 1) > func(x+1, y+1)){
                        if(func(x-1, y-1) > func(x+1, y+1)){
                            if(func(x, y+1) > func(x+1, y+1)){
                                if(func(x, y-1) > func(x+1, y+1)){
                                    if(func(x - 1, y+1) > func(x+1, y+1)){
                                        x = x + 1;
                                        y = y + 1;
                                        Current.value = func(x, y);
                                        Current.x = x;
                                        Current.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(Current.value > func(x+1, y - 1)){
            if(func(x+1, y) > func(x+1, y - 1)){
                if(func(x-1, y) > func(x+1, y - 1)){
                    if(func(x+1, y+1) > func(x+1, y - 1)){
                        if(func(x-1, y-1) > func(x+1, y - 1)){
                            if(func(x, y+1) > func(x+1, y - 1)){
                                if(func(x, y-1) > func(x+1, y - 1)){
                                    if(func(x - 1, y+1) > func(x+1, y - 1)){
                                        x = x + 1;
                                        y = y - 1;
                                        Current.value = func(x, y);
                                        Current.x = x;
                                        Current.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(Current.value > func(x-1, y-1)){
            if(func(x+1, y) > func(x-1, y-1)){
                if(func(x-1, y) > func(x-1, y-1)){
                    if(func(x+1, y+1) > func(x-1, y-1)){
                        if(func(x+1, y - 1) > func(x-1, y-1)){
                            if(func(x, y+1) > func(x-1, y-1)){
                                if(func(x, y-1) > func(x-1, y-1)){
                                    if(func(x - 1, y+1) > func(x-1, y-1)){
                                        x = x - 1;
                                        y = y - 1;
                                        Current.value = func(x, y);
                                        Current.x = x;
                                        Current.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(Current.value > func(x, y+1)){
            if(func(x+1, y) > func(x, y+1)){
                if(func(x-1, y) > func(x, y+1)){
                    if(func(x+1, y+1) > func(x, y+1)){
                        if(func(x+1, y - 1) > func(x, y+1)){
                            if(func(x-1, y-1) > func(x, y+1)){
                                if(func(x, y-1) > func(x, y+1)){
                                    if(func(x - 1, y+1) > func(x, y+1)){
                                        x = x;
                                        y = y + 1;
                                        Current.value = func(x, y);
                                        Current.x = x;
                                        Current.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(Current.value > func(x, y-1)){
            if(func(x+1, y) > func(x, y-1)){
                if(func(x-1, y) > func(x, y-1)){
                    if(func(x+1, y+1) > func(x, y-1)){
                        if(func(x+1, y - 1) > func(x, y-1)){
                            if(func(x-1, y-1) > func(x, y-1)){
                                if(func(x, y+1) > func(x, y-1)){
                                    if(func(x - 1, y+1) > func(x, y-1)){
                                        x = x;
                                        y = y - 1;
                                        Current.value = func(x, y);
                                        Current.x = x;
                                        Current.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(Current.value > func(x - 1, y+1)){
            if(func(x+1, y) > func(x - 1, y+1)){
                if(func(x-1, y) > func(x - 1, y+1)){
                    if(func(x+1, y+1) > func(x - 1, y+1)){
                        if(func(x+1, y - 1) > func(x - 1, y+1)){
                            if(func(x-1, y-1) > func(x - 1, y+1)){
                                if(func(x, y+1) > func(x - 1, y+1)){
                                    if(func(x, y-1) > func(x - 1, y+1)){
                                    x = x - 1;
                                    y = y + 1;
                                    Current.value = func(x, y);
                                    Current.x = x;
                                    Current.y = y;
                                    go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        //checks if the current position has changed
        if(x == tempX || y == tempY){
            go = true;
            
            //if the Current position has not changed then it will use the while loop to just find a position that is less than the Current position and go there.
            while(go){
                go = false;
                if(Current.value > func(x-1, y)){
                    x = x - 1;
                    y = y;
                    Current.value = func(x, y);
                    Current.x = x;
                    Current.y = y;
                    go = true;
                }
                else if(Current.value > func(x+1, y)){
                    x = x + 1;
                    y = y;
                    Current.value = func(x, y);
                    Current.x = x;
                    Current.y = y;
                    go = true;
                }
                else if(Current.value > func(x+1, y+1)){
                    x = x + 1;
                    y = y + 1;
                    Current.value = func(x, y);
                    Current.x = x;
                    Current.y = y;
                    go = true;
                }
                else if(Current.value > func(x+1, y - 1)){
                    x = x + 1;
                    y = y - 1;
                    Current.value = func(x, y);
                    Current.x = x;
                    Current.y = y;
                    go = true;
                }
                else if(Current.value > func(x-1, y-1)){
                    x = x - 1;
                    y = y - 1;
                    Current.value = func(x, y);
                    Current.x = x;
                    Current.y = y;
                    go = true;
                }
                else if(Current.value > func(x, y+1)){
                    x = x;
                    y = y + 1;
                    Current.value = func(x, y);
                    Current.x = x;
                    Current.y = y;
                    go = true;
                }
                else if(Current.value > func(x, y-1)){
                    x = x;
                    y = y - 1;
                    Current.value = func(x, y);
                    Current.x = x;
                    Current.y = y;
                    go = true;
                }
                else if(Current.value > func(x - 1, y+1)){
                    x = x - 1;
                    y = y + 1;
                    Current.value = func(x, y);
                    Current.x = x;
                    Current.y = y;
                    go = true;
                }
            }
        }
    }
    
    return Current;
}

//Does not always work needs to be fixed

//uses simulated annealing to find the lowest point in graph of an equation
optimizers::minimum_value optimizers::simulated_annealing(){
    
    //declaration of variables
    time_t start = time(0);
    bool go = true;
    int times = 0;
    int oldTemp, newTemp, OppTemp, direction;
    optimizers::minimum_value newV(0.0, 0.0, 0.0);
    optimizers::minimum_value OppV(0.0, 0.0, 0.0);
    double x, y, oldVal, newVal, OppVal, tempY, tempX;
    double T = 100;
    x = round_number(random_double(xMin, xMax));
    y = round_number(random_double(yMin, yMax));
    optimizers::minimum_value oldV(func(x, y), x, y);
    
    //while loop to find the lowest point
    while(T > 0){
        
        //this prevents the program from going outside of the domain given for the equation
        if(x < xMin){
            x = (xMin + xMax)/2;
        }
        if(x > xMax){
            x = (xMin + xMax)/2;
        }
        if(y > yMax){
            y = (yMax + yMin)/2;
        }
        if(y < yMin){
            y = (yMax + yMin)/2;
        }
        
        //chooses a random direction to check whether to go there or not
        direction = round_number(random_double(1,8));
        if(direction == 1){
            newV.value = func(x-1, y);
            newV.x = x - 1;
            newV.y = y;
        }
        else if(direction == 2){
            newV.value = func(x+1, y);
            newV.x = x + 1;
            newV.y = y;
        }
        else if(direction == 3){
            newV.value = func(x+1, y+1);
            newV.x = x + 1;
            newV.y = y + 1;
        }
        else if(direction == 4){
            newV.value = func(x+1, y - 1);
            newV.x = x + 1;
            newV.y = y - 1;
        }
        else if(direction == 5){
            newV.value = func(x-1, y-1);
            newV.x = x - 1;
            newV.y = y - 1;
        }
        else if(direction == 6){
            newV.value = func(x, y+1);
            newV.x = x;
            newV.y = y + 1;
        }
        else if(direction == 7){
            newV.value = func(x, y-1);
            newV.x = x;
            newV.y = y - 1;
        }
        else if(direction == 8){
            newV.value = func(x - 1, y+1);
            newV.x = x - 1;
            newV.y = y + 1;
        }
        
        //gets the temperature
        T = get_temperature(difftime( time(0), start));
        oldVal = oldV.value;
        newVal = newV.value;
        OppVal = OppV.value;
        
        //gets all of the old and new value to be between 0 and 1
        while(oldTemp != 0 || newTemp != 0 || OppTemp != 0){
            newVal /= 10;
            oldVal /= 10;
            OppVal /= 10;
            OppTemp = OppVal;
            oldTemp = oldVal;
            newTemp = newVal;
        }
        OppTemp = 1;
        oldTemp = 1;
        newTemp = 1;
        
        //makes sure that value is goten from the correct part of the equation
        if(oldVal - newVal > 0){
            T = T * -1;
        }
        
        //determins whether to go to the point even if it is wrong, if not then it test whether it is a good point to go to.
        if(randomBool(exp((oldVal - newVal)/T))){
            oldV = newV;
            x = newV.x;
            y = newV.y;
        }
        else if(oldV.value > newV.value){
            oldV = newV;
            x = newV.x;
            y = newV.y;
        }
        times++;
    }
    T = 100;
    times = 1;
    tempX = oldV.x;
    tempY = oldV.y;
    
    //runs the gready algorithm to find the lowest point now that the simulated annealing part is done
    while(go){
        
        //exits the loop if the current position is the smallest
        go = false;
        
        //this prevents the program from going outside of the domain given for the equation
        if(x < xMin){
            x = (xMin + xMax)/2;
        }
        if(x > xMax){
            x = (xMin + xMax)/2;
        }
        if(y > yMax){
            y = (yMax + yMin)/2;
        }
        if(y < yMin){
            y = (yMax + yMin)/2;
        }
        
        //checks the points around the current position to determin which is the smallest and then it makes that position the new Current position.
        if(oldV.value > func(x-1, y)){
            if(func(x+1, y) > func(x-1, y)){
                if(func(x+1, y+1) > func(x-1, y)){
                    if(func(x+1, y - 1) > func(x-1, y)){
                        if(func(x-1, y-1) > func(x-1, y)){
                            if(func(x, y+1) > func(x-1, y)){
                                if(func(x, y-1) > func(x-1, y)){
                                    if(func(x - 1, y+1) > func(x-1, y)){
                                        x = x - 1;
                                        y = y;
                                        oldV.value = func(x, y);
                                        oldV.x = x;
                                        oldV.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(oldV.value > func(x+1, y)){
            if(func(x-1, y) > func(x+1, y)){
                if(func(x+1, y+1) > func(x+1, y)){
                    if(func(x+1, y - 1)> func(x+1, y)){
                        if(func(x-1, y-1) > func(x+1, y)){
                            if(func(x, y+1) > func(x+1, y)){
                                if(func(x, y-1) > func(x+1, y)){
                                    if(func(x - 1, y+1) > func(x+1, y)){
                                        x = x + 1;
                                        y = y;
                                        oldV.value = func(x, y);
                                        oldV.x = x;
                                        oldV.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(oldV.value > func(x+1, y+1)){
            if(func(x+1, y) > func(x+1, y+1)){
                if(func(x-1, y) > func(x+1, y+1)){
                    if(func(x+1, y - 1) > func(x+1, y+1)){
                        if(func(x-1, y-1) > func(x+1, y+1)){
                            if(func(x, y+1) > func(x+1, y+1)){
                                if(func(x, y-1) > func(x+1, y+1)){
                                    if(func(x - 1, y+1) > func(x+1, y+1)){
                                        x = x + 1;
                                        y = y + 1;
                                        oldV.value = func(x, y);
                                        oldV.x = x;
                                        oldV.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(oldV.value > func(x+1, y - 1)){
            if(func(x+1, y) > func(x+1, y - 1)){
                if(func(x-1, y) > func(x+1, y - 1)){
                    if(func(x+1, y+1) > func(x+1, y - 1)){
                        if(func(x-1, y-1) > func(x+1, y - 1)){
                            if(func(x, y+1) > func(x+1, y - 1)){
                                if(func(x, y-1) > func(x+1, y - 1)){
                                    if(func(x - 1, y+1) > func(x+1, y - 1)){
                                        x = x + 1;
                                        y = y - 1;
                                        oldV.value = func(x, y);
                                        oldV.x = x;
                                        oldV.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(oldV.value > func(x-1, y-1)){
            if(func(x+1, y) > func(x-1, y-1)){
                if(func(x-1, y) > func(x-1, y-1)){
                    if(func(x+1, y+1) > func(x-1, y-1)){
                        if(func(x+1, y - 1) > func(x-1, y-1)){
                            if(func(x, y+1) > func(x-1, y-1)){
                                if(func(x, y-1) > func(x-1, y-1)){
                                    if(func(x - 1, y+1) > func(x-1, y-1)){
                                        x = x - 1;
                                        y = y - 1;
                                        oldV.value = func(x, y);
                                        oldV.x = x;
                                        oldV.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(oldV.value > func(x, y+1)){
            if(func(x+1, y) > func(x, y+1)){
                if(func(x-1, y) > func(x, y+1)){
                    if(func(x+1, y+1) > func(x, y+1)){
                        if(func(x+1, y - 1) > func(x, y+1)){
                            if(func(x-1, y-1) > func(x, y+1)){
                                if(func(x, y-1) > func(x, y+1)){
                                    if(func(x - 1, y+1) > func(x, y+1)){
                                        x = x;
                                        y = y + 1;
                                        oldV.value = func(x, y);
                                        oldV.x = x;
                                        oldV.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(oldV.value > func(x, y-1)){
            if(func(x+1, y) > func(x, y-1)){
                if(func(x-1, y) > func(x, y-1)){
                    if(func(x+1, y+1) > func(x, y-1)){
                        if(func(x+1, y - 1) > func(x, y-1)){
                            if(func(x-1, y-1) > func(x, y-1)){
                                if(func(x, y+1) > func(x, y-1)){
                                    if(func(x - 1, y+1) > func(x, y-1)){
                                        x = x;
                                        y = y - 1;
                                        oldV.value = func(x, y);
                                        oldV.x = x;
                                        oldV.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(oldV.value > func(x - 1, y+1)){
            if(func(x+1, y) > func(x - 1, y+1)){
                if(func(x-1, y) > func(x - 1, y+1)){
                    if(func(x+1, y+1) > func(x - 1, y+1)){
                        if(func(x+1, y - 1) > func(x - 1, y+1)){
                            if(func(x-1, y-1) > func(x - 1, y+1)){
                                if(func(x, y+1) > func(x - 1, y+1)){
                                    if(func(x, y-1) > func(x - 1, y+1)){
                                        x = x - 1;
                                        y = y + 1;
                                        oldV.value = func(x, y);
                                        oldV.x = x;
                                        oldV.y = y;
                                        go = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        //checks if the current position has changed
        if(x == tempX || y == tempY){
            go = true;
            
            //if the Current position has not changed then it will use the while loop to just find a position that is less than the Current position and go there.
            while(go){
                go = false;
                if(oldV.value > func(x-1, y)){
                    x = x - 1;
                    y = y;
                    oldV.value = func(x, y);
                    oldV.x = x;
                    oldV.y = y;
                    go = true;
                }
                else if(oldV.value > func(x+1, y)){
                    x = x + 1;
                    y = y;
                    oldV.value = func(x, y);
                    oldV.x = x;
                    oldV.y = y;
                    go = true;
                }
                else if(oldV.value > func(x+1, y+1)){
                    x = x + 1;
                    y = y + 1;
                    oldV.value = func(x, y);
                    oldV.x = x;
                    oldV.y = y;
                    go = true;
                }
                else if(oldV.value > func(x+1, y - 1)){
                    x = x + 1;
                    y = y - 1;
                    oldV.value = func(x, y);
                    oldV.x = x;
                    oldV.y = y;
                    go = true;
                }
                else if(oldV.value > func(x-1, y-1)){
                    x = x - 1;
                    y = y - 1;
                    oldV.value = func(x, y);
                    oldV.x = x;
                    oldV.y = y;
                    go = true;
                }
                else if(oldV.value > func(x, y+1)){
                    x = x;
                    y = y + 1;
                    oldV.value = func(x, y);
                    oldV.x = x;
                    oldV.y = y;
                    go = true;
                }
                else if(oldV.value > func(x, y-1)){
                    x = x;
                    y = y - 1;
                    oldV.value = func(x, y);
                    oldV.x = x;
                    oldV.y = y;
                    go = true;
                }
                else if(oldV.value > func(x - 1, y+1)){
                    x = x - 1;
                    y = y + 1;
                    oldV.value = func(x, y);
                    oldV.x = x;
                    oldV.y = y;
                    go = true;
                }
            }
        }
    }
    return oldV;
}

//rounds the number to a hole number
double optimizers::round_number(double number){
    return round(number);
}

//generates a random double and returns it
double optimizers::random_double(double min, double max){
    mt19937 generator (random());
    uniform_real_distribution<double> dist(min, max);
    return dist(generator);
}

//determins the Current temperature using Newton's law of cooling then returns it
double optimizers::get_temperature(double time){
    double T = 1 + (100 - 1)*exp(-0.015*time);
    return time;
    return T;
}

//generates a random boolean value with a probability that is sent in.
bool optimizers::randomBool(double oddsOfReturningTrue){
    bool boolArray [100];
    double oddsTrue = oddsOfReturningTrue*100;
    for(int i = 0; i<oddsTrue; i++){
        boolArray[i] = true;
    }
    for(int i = oddsTrue; i<100; i++){
        boolArray[i] = false;
    }
    return boolArray[static_cast<int>(round_number(random_double(0, 100)))];
}

/*
 * Name:Pierce Tarleton
 * Date Submitted:
 * Lab Section
 * Assignment Name:
 */

#pragma once

#include <functional>
#include <iostream>
#include <cfloat>
#include <random>
#include <ctime>
#include <chrono>
#include <cmath>

using namespace std;

class optimizers{
public:
    struct minimum_value{
        double value;
        double x;
        double y;
        minimum_value(double value, double x, double y):
            value(value), x(x), y(y){}
    };

    optimizers(function<double(double,double)> func,double xMin, double xMax, double yMin, double yMax);
    minimum_value greedy();
    minimum_value simulated_annealing();
private:
    function<double(double,double)> func;
    double xMin, xMax, yMin, yMax;
    double round_number(double number);
    double random_double(double min, double max);
    double get_temperature(double time);
    bool randomBool(double oddsOfReturningTrue);
};

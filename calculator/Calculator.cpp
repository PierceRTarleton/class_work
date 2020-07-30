#include "Calculator.h"
#include <cmath>

int Calculator::add(int x, int y){
    int answer = x + y;
    return answer;
}

int Calculator::subtract(int x, int y){
    int answer = x - y;
    return answer;
}

int Calculator::multiply(int x, int y){
    int answer = x * y;
    return answer;
}
int Calculator::divide(int x, int y){
    int answer = x/y;
    return answer;
}

int Calculator::exponent(int x, int y){
    int answer = x;
    int CopyofY = y;
    while (CopyofY>1){
        --CopyofY;
        answer = answer * x;
    }
    return answer;
}

int Calculator::modulus(int x, int y){
    int answer = x%y;
    return answer;
}

double Calculator::add(double x, double y){
    double answer = x + y;
    return answer;
}

double Calculator::subtract(double x, double y){
    double answer = x - y;
    return answer;
}

double Calculator::multiply(double x, double y){
    double answer = x * y;
    return answer;
}

double Calculator::divide(double x, double y){
    double answer = 0;
    answer = x/y;
    return answer;
}

double Calculator::exponent(double x, double y){
    double answer = pow(x, y);
    return answer;
}
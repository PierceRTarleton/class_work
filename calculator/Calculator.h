#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator{
    private:
        //int x;
        //int y;
        //int answer;
    public:
        int add(int x,int y);
        int subtract(int x,int y);
        int multiply(int x,int y);
        int divide(int x,int y);
        int exponent(int x,int y);
        int modulus(int x,int y);
        double add(double x,double y);
        double subtract(double x,double y);
        double multiply(double x,double y);
        double divide(double x,double y);
        double exponent(double x,double y);
};
#endif

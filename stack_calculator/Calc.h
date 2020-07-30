/*
 * Class Summary : Lab_7__Stack_calculator
 * Name : Pierce Tarleton
 * Last Modified : 3/8/2019
 */
#include <string>
#include <regex>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include "ArrayStack.h"

using namespace std;

class Calc{
private:
    map<string, int> OrderofOpperations;
    ArrayStack<double> numbers;
    ArrayStack<string> operators;
    string regex_match_pattern();
    vector<string> parse_equation(string equation);
    double solve_portion(string operat, double x, double y);
public:
    double solve_equation(string equation);
};

//returns a string of a regex pattern used to split a formula
string Calc::regex_match_pattern(){
    string leftParentheses = "[(]";
    string rightParentheses = "[)]";
    string operators = "[\\-\\/+*^%]";
    string doubles = "(?:\\d+[.]\\d*|\\d*[.]\\d+|\\d+)";
    return leftParentheses + "|" + rightParentheses + "|" + operators  + "|" + doubles;
}

//takes in an equation in the form of a string, splits it, and returns it in a vector
vector<string> Calc::parse_equation(string equation){
    vector<string> parsedEquation;
    smatch matchingValue;
    regex expression(regex_match_pattern());

    while(regex_search(equation,matchingValue,expression)){
        for(auto match: matchingValue)
            parsedEquation.push_back(match) ;
        equation = matchingValue.suffix().str();
    }
    return parsedEquation;
}

//takes in an equation, solves it, and returns the answer
double Calc::solve_equation(string equation){
    
    //Variables
    bool isLessOrder = false;
    map<string, int> Order = {{"(", 0},{"^",2},{"*", 3},{"/", 3},
                            {"%", 3},{"+", 4},{"-",4}};
    double x, y, answer;
    int position = 0;
    string Temp, numTemp, operatorTemp;
    string operat = "(+-*/%^)";
    string nums = "1234567890";
    vector <string> parsedEquation = parse_equation(equation);
    
    //iteraties through the equation
    while(position < parsedEquation.size()){
        operatorTemp = parsedEquation.at(position);
        
        //if a closed parentheses is reached in the equation then it sends the operations and their corresponding numbers to solve_portion() and adds what is returned to the numbers stack.
        if(operatorTemp == ")"){
            position++;
            Temp = operators.pop();
            while(Temp != "("){
                y = numbers.pop();
                x = numbers.pop();
                answer = solve_portion(Temp, x, y);
                numbers.push(answer);
                Temp = operators.pop();
            }
        }
        
        //adds the open parentheses to the operations stack
        else if (operatorTemp == "("){
            operatorTemp = parsedEquation.at(position);
            operators.push(operatorTemp);
            position++;
        }
        
        //sends the number that follows ^ as will as the number on top of the stack to solve_portion and adds the answer to the numbers stack, because the ^ operatortion will always be done to the number taken from the stack befor any other operation.
        else if(operatorTemp == "^"){
            position++;
            x = numbers.pop();
            y = stod(parsedEquation.at(position));
            answer = solve_portion(operatorTemp, x, y);
            numbers.push(answer);
            if(position < parsedEquation.size()){
                position++;
            }
        }
        
        //adds the * operator to the stack it the following operation is of lower priority indecated by the heigher number, otherwise the number on the stack will be sent to solve_portion with the number following the *.
        else if (operatorTemp == "*"){
            if(position != parsedEquation.size()-2){
                if(Order[operatorTemp] <= Order[parsedEquation.at(position+2)]){
                    position++;
                    x = numbers.pop();
                    y = stod(parsedEquation.at(position));
                    answer = solve_portion(operatorTemp, x, y);
                    numbers.push(answer);
                    if(position != parsedEquation.size()-1){
                        position++;
                    }
                }
                else{
                    isLessOrder = true;
                }
            }
            if(isLessOrder || position == parsedEquation.size()-2){
                isLessOrder = false;
                operatorTemp = parsedEquation.at(position);
                operators.push(operatorTemp);
                position++;
            }
        }
        
        //adds the % operator to the stack it the following operation is of lower priority indecated by the heigher number, otherwise the number on the stack will be sent to solve_portion with the number following the %.
        else if (operatorTemp == "%"){
            if(position != parsedEquation.size()-2){
                if(Order[operatorTemp] <= Order[parsedEquation.at(position+2)]){
                    position++;
                    x = numbers.pop();
                    y = stod(parsedEquation.at(position));
                    answer = solve_portion(operatorTemp, x, y);
                    numbers.push(answer);
                    if(position != parsedEquation.size()-1){
                        position++;
                    }
                }
                else{
                    isLessOrder = true;
                }
            }
            if(isLessOrder || position == parsedEquation.size()-2){
                isLessOrder = false;
                operatorTemp = parsedEquation.at(position);
                operators.push(operatorTemp);
                position++;
            }
        }
        
        //adds the / operator to the stack it the following operation is of lower priority indecated by the heigher number, otherwise the number on the stack will be sent to solve_portion with the number following the /.
        else if (operatorTemp == "/"){
            if(position != parsedEquation.size()-2){
                if(Order[operatorTemp] <= Order[parsedEquation.at(position+2)]){
                    position++;
                    x = numbers.pop();
                    y = stod(parsedEquation.at(position));
                    answer = solve_portion(operatorTemp, x, y);
                    numbers.push(answer);
                    if(position != parsedEquation.size()-1){
                        position++;
                    }
                }
                else{
                    isLessOrder = true;
                }
            }
            if(isLessOrder || position == parsedEquation.size()-2){
                isLessOrder = false;
                operatorTemp = parsedEquation.at(position);
                operators.push(operatorTemp);
                position++;
            }
        }
        
        //adds the - operator to the stack it the following operation is of lower priority indecated by the heigher number, otherwise the number on the stack will be sent to solve_portion with the number following the -.
        else if (operatorTemp == "-"){
            if(position != parsedEquation.size()-2){
                if(Order[operatorTemp] <= Order[parsedEquation.at(position+2)]){
                    position++;
                    x = numbers.pop();
                    y = stod(parsedEquation.at(position));
                    answer = solve_portion(operatorTemp, x, y);
                    numbers.push(answer);
                    if(position != parsedEquation.size()-1){
                        position++;
                    }
                }
                else{
                    isLessOrder = true;
                }
            }
            if(isLessOrder || position == parsedEquation.size()-2){
                isLessOrder = false;
                operatorTemp = parsedEquation.at(position);
                operators.push(operatorTemp);
                position++;
            }
        }
        
        //adds the + operator to the stack it the following operation is of lower priority indecated by the heigher number, otherwise the number on the stack will be sent to solve_portion with the number following the +.
        else if (operatorTemp == "+"){
            if(position != parsedEquation.size()-2){
                if(Order[operatorTemp] <= Order[parsedEquation.at(position+2)]){
                    position++;
                    x = numbers.pop();
                    y = stod(parsedEquation.at(position));
                    answer = solve_portion(operatorTemp, x, y);
                    numbers.push(answer);
                    if(position != parsedEquation.size()-1){
                        position++;
                    }
                }
                else{
                    isLessOrder = true;
                }
            }
            if(isLessOrder || position == parsedEquation.size()-2){
                isLessOrder = false;
                operatorTemp = parsedEquation.at(position);
                operators.push(operatorTemp);
                position++;
            }
        }
        
        //adds the numbers to the numbers stack
        else {
            for(int i = 0; i<nums.size(); i++){
                numTemp = nums.at(i);
                if(parsedEquation[position][0] == numTemp[0]){
                    if(position < parsedEquation.size()){
                        numbers.push(stod(parsedEquation.at(position)));
                        position++;
                    }
                    if(position == parsedEquation.size()){
                        break;
                    }
                }
            }
        }
    }
    
    //when the end of the equation is reached it runs through the rest of the operators and sends then to solve_portion whith the numbers from the numbers stack to be solved.
    while(!operators.empty()){
        Temp = operators.pop();
        y = numbers.pop();
        x = numbers.pop();
        answer = solve_portion(Temp, x, y);
        numbers.push(answer);
    }
    return answer;
}


//Checks what operater has been sent in and carries out the corresponding operation.
double Calc::solve_portion(string operat, double x, double y){
    double answer;
    int a, b;
    if(operat == "+"){
        answer = x + y;
    }
    else if(operat == "-"){
        answer = x - y;
    }
    else if(operat == "*"){
        answer = x * y;
    }
    else if(operat == "/"){
        answer = x/y;
    }
    else if(operat == "%"){
        a = x;
        b = y;
        answer = static_cast<double>(a%b);
    }
    else if(operat == "^"){
        answer = pow(x, y);
    }
    return answer;
}

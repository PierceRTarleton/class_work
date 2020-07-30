/* Name : Pierce Tarleton
 * Class : 4
 * Assignent : Lab 3 Test Generator
 * Last Modified :2/8/2019
 */
#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <random>
#include <fstream>

using namespace std;

// Don't forget to add comments

class TestGenerator{
public:
  TestGenerator();
  string randomString(int length, bool numeric=false);
  double randomDouble(double min=0.0, double max=1.0);
  int randomInt(int min=0, int max=100);
  bool randomBool(double oddsOfTrue=0.5);
  char randomChar(bool);
  void run(string infile, string outfile);
  vector<string> split(const string& s, char delimiter);
  double round_number(double);
  string generateRandom(string);
};


TestGenerator::TestGenerator(){
}

// Returns a randomly-generated string of length <length>.  
// If <numeric> is true, this string may contain numbers
string TestGenerator::randomString(int length, bool numeric){
    string randString(length, ' ');
    if(numeric == true){
        string numString = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i = 0; i<length; i++){
            randString [i] = numString [randomInt(0, numString.size()-1)];
        }
        return randString;
    }
    else{
        string String = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i = 0; i<length; i++){
            randString [i] = String [randomInt(0, String.size()-1)];
        }
        return randString;
    }
}

// Returns a random double (rounded to two decimal places) between <min> and <max> (inclusive)
double TestGenerator::randomDouble (double min, double max){
    mt19937 generator (random());
    uniform_real_distribution<double> dist(min, max);
    return round_number(dist(generator));
  }

// Returns a random integer between <min> and <max> (inclusive)
int TestGenerator::randomInt(int min, int max){
    mt19937 generator (random());
    uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

// Returns a random boolean
bool TestGenerator::randomBool(double oddsOfReturningTrue){
    bool boolArray [100];
    double oddsTrue = oddsOfReturningTrue*100;
    for(int i = 0; i<oddsTrue; i++){
        boolArray[i] = true;
    }
    for(int i = oddsTrue; i<100; i++){
        boolArray[i] = false;
    }
    return boolArray[randomInt(0, 100)];
}

// Generates a random char
// If <numeric> is true, this may be a numerical char (e.g. '7')
char TestGenerator::randomChar(bool numeric){
    if(numeric == true){
        string numString = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            return numString [randomInt(0, numString.size()-1)];
    }
    else{
        string String = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            return String [randomInt(0, String.size()-1)];
    }
}


// Splits a string on a delimiter
vector<string> TestGenerator::split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

// Rounds a number to two decimal places
double TestGenerator::round_number(double number){
    static double scale = 0.01;
    return floor(number/scale + 0.5) * scale;
}


// INPUT : A string which contains the data for a single random generation
//          (e.g. int~0~100)
// OUTPUT: A string which contains a single randomly-generated value
//          (e.g. "25")
string TestGenerator::generateRandom(string chunk){
    stringstream ss;
    vector<string> chunked = split(chunk, '~');
    if(chunked[0].compare("int") == 0){
        int min = stoi(chunked[1]);
        int max = stoi(chunked[2]);
        return to_string(randomInt(min, max));
    }
    if(chunked[0].compare("double") == 0){
        double min = stod(chunked[1]);
        double max = stod(chunked[2]);
        return to_string(randomDouble(min, max));
    }
    if(chunked[0].compare("string") == 0){
        int length = stoi(chunked[1]);
        bool numeric = stoi(chunked[2]);
        return randomString(length, numeric);
    }
    if(chunked[0].compare("char") == 0){
        bool numeric = stoi(chunked[1]);
        string randString;
        ss<<randomChar(numeric);
        ss>>randString;
        return randString;
    }
    if(chunked[0].compare("bool") == 0){
        double probabiltiy = stod(chunked[1]);
        return to_string(randomBool(probabiltiy));
    }
    return "False";
}

// Organizes program execution
void TestGenerator::run(string infile, string outfile){
  // Read infile
    random_device random;
    mt19937 generator (random());
    ifstream inFile (infile);
    ofstream outFile (outfile);
    int runNum;
    inFile>>runNum;
  // Parse infile data
    string randString;
    string randInt;
    string randChar;
    string randDouble;
    string randBool;
    inFile>>randString>>randInt>>randChar>>randDouble>>randBool;
  // Generate random values based on infile data
    for(int i = 0; i<runNum; i++){
        outFile<<generateRandom(randString)<<" ";
        outFile<<generateRandom(randInt)<<" ";
        outFile<<generateRandom(randChar)<<" ";
        outFile<<generateRandom(randDouble)<<" ";
        outFile<<generateRandom(randBool)<<endl;
    }

  // Write outfile
  //inFile.close();
  //outFile.close();
}

/*INPUT FILE FORMAT 
(everything except the number and types must be deleted before running this file)
-------------------------------------------------------
number-of-tests-to-generate
dataType~separated parameters (must be able to read any number of these, separated by spaces)

EACH DATA TYPE FORMAT:
----------------------------------
string~length~numbersAllowed? [0-false,1-true]
int~min-possible~max-possible
char~numbersAllowed [0-false, 1-true]
double~min-possible~max-possible
bool~percent-chance-of-returning-true


EXAMPLE INPUT FILE CONTENTS:
------------------------------

EXAMPLE OUTPUT (FOR EXAMPLE INPUT):
------------------------------
asucme?uoeDpsu 14 a 12.54 1
EPFI-dspdicmfG 17 Z 198.31 0
amdjcudh>ndi<u 16 K 101.77.54 1
aDdALSqpeMucNZ 15 l 62.45 1
ASDMUC+kjdhcub 20 p 59.97 1*/
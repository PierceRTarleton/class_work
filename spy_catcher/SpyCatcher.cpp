#include "SpyCatcher.h"

SpyCatcher::SpyCatcher(){
    
}

SpyCatcher::~SpyCatcher(){
    
}

//reads in the data from the file, of who had access to what files
void SpyCatcher::readAllLists(string filename){
    
    //Variables, open file
    ifstream InFile(filename);
    bool dupicate = true;
    string input;
    string person, temp1;
    
    //Reads in the file puting the names of the people who have access to each file in a map of vectors, that is accessed by the file name.
    while(!InFile.eof()){
        getline(InFile, input);
        getline(InFile, temp1);
        stringstream temp2(temp1);
        while(getline(temp2, person, ' ')){
            
            //keeps the name from being put in the vector twice if it is in the file twice for the same file
            for(auto i: peopleL[input]){
                if(i == person){
                    dupicate = false;
                }
            }
            if(dupicate){
                peopleL[input].push_back(person);
            }
            dupicate = true;
        }
        files.push_back(input);
    }
    InFile.close();
}

//Finds the name of the spy by finding who has access to the most leaked files
string SpyCatcher::findSpy(vector<string> file){
    
    //Variables
    string spy = "";
    int spyI = 0;
    int numberFiles = 0;
    
    //creates a map of ints that represents the number of files that the name showed up in from the list of leaked files. Accessed by the name of the person.
    for(auto i: file){
        for(auto p: peopleL[i]){
            if(people.count(p) == 1){
                people[p]+=1;
            }
            else{
                people[p] = 1;
            }
        }
    }
    
    //iterates through the list of names that had access to the leaked files it finds the name that had acccess to the most of them and returns them as the spy.
    for(auto i: people){
        if(i.second > spyI){
            spyI = i.second;
            spy = i.first;
        }
    }
    
    //prints out the name of the spy then returns it
    cout<<"the answer: " <<spy<<endl;
    return spy;
}

vector<string> SpyCatcher::findSpies(){
    
}

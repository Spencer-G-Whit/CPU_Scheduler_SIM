#include "dataFile.h"
#include "PCB.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>


using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;

//Function declarations
//Generates the file that contains the data used in simulation
void generateDataFile();

int main (){
    srand(time(NULL));

    // global queue for ready processes
    queue<PCB> Ready;

    // global queue for waiting processes
    queue<PCB> Waiting;

    generateDataFile();
    return 0;
}

//Generates the file that contains the data used in simulation
void generateDataFile(){
    vector<DataFile> dataVector;
    for(int i = 0; i < 10; i++){//This loops creates the process instance
        int arrivalT = rand() % 10 + 1;
        vector<int> ioB;
        vector<int> cpuB;
        for(int i =0; i < 25; i++){//This loop generates the burst times
            int cpuRand = rand() % 5 + 0;
            int ioRand = rand() % 5 + 0;

            if(cpuRand != 0) 
                cpuB.push_back(cpuRand); //cpu burst time at instance i
            if(ioRand != 0)
                ioB.push_back(ioRand); //io burst time at instance i
        }
        DataFile df = DataFile(i,arrivalT, ioB, cpuB);
        dataVector.push_back(df);
    }
    for(int i=0; i < dataVector.size(); i++){
        dataVector[i].generateFile();
    }
}


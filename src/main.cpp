#include <iostream>
#include "dataFile.cpp"
#include <fstream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>


using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;

//Function declarations
//Generates the file that contains the data used in simulation
void generateDataFile();

void runningSim(DataFile procD);

// global queue for waiting processes
queue<DataFile> Waiting;

// global queue for ready processes
queue<DataFile> Ready;

int main (){
    srand(time(NULL));
    // global queue for ready processes
    queue<DataFile> Ready;

    generateDataFile();
    cout << "done!" << endl;
    return 0;
}

//Generates the file that contains the data used in simulation
void generateDataFile(){
    vector<DataFile> dataVector;
    for(int i = 0; i < 4; i++){//This loops creates the process instance
        int arrivalT = rand() % 10 + 1;
        vector<int> ioB;
        vector<int> cpuB;
        for(int j =0; j < 5; j++){//This loop generates the burst times
            int cpuRand = rand() % 5 + 0;
            int ioRand = rand() % 5 + 0;

            if(cpuRand != 0) 
                cpuB.push_back(cpuRand); //cpu burst time at instance i
            if(ioRand != 0)
                ioB.push_back(ioRand); //io burst time at instance i
        }
        DataFile df =  DataFile(i, arrivalT, ioB, cpuB, state::begin);
        dataVector.push_back(df);
    }
    for(int i=0; i < dataVector.size(); i++){
        dataVector[i].generateFile();
     }
}

void runningSim(DataFile proc){
    proc.setState(state::running);

    int finished = 0;

    for(int i = 0; i < proc.getPC().size(); i ++){
        if(proc.getPC().empty()){
            proc.setState(state::finished);
            //TODO: Print data
            //TODO: exit conditions
        }
        if(proc.getPC()[i] == procType::cpu){
            while(proc.getCPUBurst()[0] > 0){
                proc.decrementCPU();
            }
            finished++;
            proc.deleteFirstCPU();

            if(proc.getPC()[i+1]==procType::IO){
                proc.setState(state::blocked);
                Waiting.push(proc);
            }
        }
        if(proc.getPC()[i] == procType::IO)
        {
            while(proc.getIOBurst()[0] > 0){
                proc.decrementIO();
            }
            finished++;
            proc.deleteFirstIO();

            if(proc.getPC()[i+1]==procType::IO){
                proc.setState(state::blocked);
                Waiting.push(proc);
            }
        }
    }
}


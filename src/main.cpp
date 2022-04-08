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
vector<DataFile> generateDataVector();
//Generates the file that contains the data used in simulation
vector<DataFile> generateDataFile();

void runningSim(DataFile procD);

// global queue for waiting processes
queue<DataFile> Waiting;

// global queue for ready processes
queue<DataFile> Ready;

int const timeOut = 50;

int main (){
    
    srand(time(NULL));
    // global queue for ready processes
    queue<DataFile> Ready;
    vector<DataFile> readyVector = generateDataFile();
    for(int i = 0; i < readyVector.size(); i++){
        readyVector[i].setState(ready);
        Ready.push(readyVector[i]);
    }
    
    //To do read data file and import process lines into Datafile Object
    //std::ifstream input;
    //Open file at the end of the stream (to append the data on)
    // input.open("./data/data.txt", std::fstream::beg);
    // std::string fileData = "";
    // while(std::getline(input, fileData)){
    //     DataFile data = DataFile();
    //     fileData.find
    //     data.setPID();
        
    // }
    
    // if there is a process in either waiting or ready
    while(!Ready.empty() || !Waiting.empty())
    {
        // if there is an item in ready
        if(!Ready.empty()){
            DataFile current = Ready.front();
            Ready.pop();
            
            // run process
            runningSim(current);

            // if process in waiting, push to ready
            if(!Waiting.empty()){
                Ready.push(Waiting.front());
                Waiting.pop();
            }

        }
        // if item in waiting and not in ready, push item it ready
        else
        {
            Ready.push(Waiting.front());
            Waiting.pop();
        }
    }
    
    cout << "done!" << endl;
    return 0;
}

vector<DataFile> generateDataVector(){
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
        DataFile df =  DataFile(i, arrivalT, ioB, cpuB, begin);
        dataVector.push_back(df);
    }
    return dataVector;
}

//Generates the file that contains the data used in simulation
vector<DataFile> generateDataFile(){
    vector<DataFile> dataVector = generateDataVector();
    for(int i=0; i < dataVector.size(); i++){
        dataVector[i].generateFile();
     }
     return dataVector;
}

// simulate running
void runningSim(DataFile proc){
    proc.setState(running);

    // track how many elements will need to be erased
    int finish = 0;
    
    // counter to track timout time
    int count = 0;

    for(int i = 0; i < proc.getPC().size(); i ++){
        if(proc.getPC().empty()){
            proc.setState(finished);
            //TODO: Print data
            //TODO: exit conditions
        }
        
        // if the first element is a cpu burst
        if(proc.getPC()[i] == cpu){
            while(proc.getCPUBurst()[0] > 0){
                proc.decrementCPU();
                count++;

                // check if processes is timmed out
                if (count <= timeOut)
                {
                    // push back to ready queue
                    proc.setState(ready);
                    Ready.push(proc);
                    break;
                }
            }
            count = 0;
            finish++;
            proc.deleteFirstCPU();

            // if next element is I/O, push to waiting
            if(proc.getPC()[i+1] == IO){
                proc.setState(blocked);
                Waiting.push(proc);
                break;
            }
        }

        // if the first element is a IO burst
        if(proc.getPC()[i] == IO)
        {
            while(proc.getIOBurst()[0] > 0){
                proc.decrementIO();
                count++;

                // check if processes is timmed out
                if (count <= timeOut)
                {
                    // push back to ready queue
                    proc.setState(ready);
                    Ready.push(proc);
                    break;
                }
            }
            count = 0;
            finish++;
            proc.deleteFirstIO();

            // if next element is I/O, push to waiting
            if(proc.getPC()[i+1] == IO){
                proc.setState(blocked);
                Waiting.push(proc);
                break;
            }
        }
    }


    // erase elements from the proc PC that have been evaluated
    std::vector<procType> hold = proc.getPC();
    while(finish)
    {
       hold.erase(hold.begin());
       finish--;
    }

    proc.setPC(hold);

}


//Main file
#include "dataFile.h"
#include <fstream>
#include <iostream>

//Contructor with values
DataFile::DataFile(int pid, int aTime, std::vector<int> cBurst, std::vector<int> iBurst, state state){
    this->PID = pid;
    this->arrivalTime = aTime;
    this->cpuBurst = cBurst;
    this->ioBurst = iBurst;
    this->s = state;
}

//default constructor
DataFile::DataFile(){
    this->PID = -1;
    this->arrivalTime = -1;
    this->cpuBurst;
    this->ioBurst;
    this->s = state::begin;
}
// PID getter/setter
int DataFile::getPID(){ 
    return this->PID; 
}
void DataFile::setPID(int PID){ 
    this->PID = PID; 
}

//arrival time getter/setter
int DataFile::getTime(){ 
    return this->arrivalTime; 
}
void DataFile::setTime(int arrivalTime){ 
    this->arrivalTime = arrivalTime; 
}

// IOBurst getter/setter/decrementer/delete first element
std::vector<int> DataFile::getIOBurst(){ 
    return this->ioBurst; 
}
void DataFile::setIOBurst(std::vector<int> iBurst){ 
    this->ioBurst = iBurst; 
}
void DataFile::decrementIO(){
    this->ioBurst[0]--;
}
void DataFile::deleteFirstIO(){
    this->ioBurst.erase(this->ioBurst.begin());
}

// CPUBurst getter/setter/decrementer/delete first element
std::vector<int> DataFile::getCPUBurst(){
    return this->cpuBurst;
}
void DataFile::setCPUBurst(std::vector<int> cBurst){
    this->cpuBurst = cBurst;
}
void DataFile::decrementCPU(){
    this->cpuBurst[0]--;
}
void DataFile::deleteFirstCPU(){
    this->cpuBurst.erase(this->cpuBurst.begin());
}

// getter/setter for state enum
state DataFile::getState(){
    return this->s;
}
void DataFile::setState(state state){
    this->s = state;
}

// getter and setter for PC vector
std::vector<procType> DataFile::getPC() {
    return this->PC;
}
void DataFile::setPC(std::vector<procType> pc) {
    this->PC = pc;
}


//Method that writes data (pid #, arrival time, cpu burst, and io burst) to a file (data.txt)
void DataFile::generateFile(){
    std::ofstream output;
    //Open file at the end of the stream (to append the data on)
    output.open("./data/data.txt", std::fstream::app);
    if(output.is_open()){//If successful
        output << "PID # " << this->PID;
        output << " Arrival Time: " << this->arrivalTime;
        for (int i = 0; i < this->cpuBurst.size() || i < this->ioBurst.size(); i++){//Loop to go through vector of cpuBurst(s)
            //std::cout << "Inside for-loop\n";
            if(i < cpuBurst.size())
                output << " CPU Burst: " << this->cpuBurst[i];
            if(i < ioBurst.size())
                output << " I/O Burst: " << this->ioBurst[i];
        }
        output << std::endl;
        std::cout << "Closing file\n";
    }
    else
        std::cout << "Error opening ./data/data.txt";
}
//Main file

#include "./headers/dataFile.h"
#include <fstream>
#include <iostream>

//Contructor with values
DataFile::DataFile(int pid, int aTime, std::vector<int> cBurst, std::vector<int> iBurst){
    this->PID = pid;
    this->arrivalTime = aTime;
    this->cpuBurst = cBurst;
    this->ioBurst = iBurst;
}

//default constructor
DataFile::DataFile(){
    this->PID = -1;
    this->arrivalTime = -1;
    this->cpuBurst;
    this->ioBurst;
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

// IOBurst getter/setter
std::vector<int> DataFile::getIOBurst(){ 
    return this->ioBurst; 
}
void DataFile::setIOBurst(std::vector<int> ioBurst){ 
    this->ioBurst = ioBurst; 
}

//Method that writes data (pid #, arrival time, cpu burst, and io burst) to a file (data.txt)
void DataFile::generateFile(){
    std::ofstream output;
    //Open file at the end of the stream (to append the data on)
    output.open("./data/data.txt", std::ios_base::app);
    if(output.is_open()){//If successful
        output << std::endl << "PID # " << this->PID;
        output << "Arrival Time: " << this->arrivalTime;
        for (int i = 0; i < this->cpuBurst.size() || this->ioBurst.size(); i++){//Loop to go through vector of cpuBurst(s)
            if(i < cpuBurst.size())
                output << "CPU Burst: " << this->cpuBurst[i];
            if(i < ioBurst.size())
                output << "I/O Burst: " << this->ioBurst[i];
        }
        output.close();
    }
    else
        std::cout << "Error opening ./data/data.txt";
}
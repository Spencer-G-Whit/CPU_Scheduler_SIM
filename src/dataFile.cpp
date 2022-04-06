//Main file

#include "./headers/dataFile.h"

//Contructor with values
DataFile(int pid, int aTime, std::vector<int> cBurst, std::vector<int> iBurst){
    this.PID = pid;
    this.arrivalTime = aTime;
    this.CPUburst = cBurst;
    this.ioBurst = iBurst;
}
//default constructor
DataFile(){

}
// PID getter/setter
int dataFile::getPID()
{ return this->PID; }
void dataFile::setPID(int PID)
{ this->PID = PID; }

//arrival time getter/setter
int dataFile::getTime()
{ return this->arrivalTime; }
void dataFile::setTime(int arrivalTime)
{ this->arrivalTime = arrivalTime; }

// IOBurst getter/setter
std::vector<int> dataFile::getIOBurst()
{ return this->ioBurst; }
void dataFile::setIOBurst(std::vector<int> ioBurst)
{ this->ioBurst = ioBurst; }

void generateFile()
{

}
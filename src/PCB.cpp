/*#include "PCB.h"
//Main file

//Constructor that takes in PID and state as arguments
PCB::PCB(int pid, state st){
    this->PID = pid;
    this->PC = 0;
}

//Default constructor for PCB
PCB::PCB(){
    this->PID = -1;
    this->PC = 0;
}

//getter/setter for current instance PID value
int PCB::getPID(){ 
    return this->PID; 
}
void PCB::setPID(int pid){
    this->PID = pid;
}

// getter/setter/incrementer for current instance program counter
int PCB::getPC(){ 
    return this->PC; 
}
void PCB::setPC(int PC){  
    this->PC = PC;
}
void PCB::incPC(){ 
    this->PC++;
}
*/
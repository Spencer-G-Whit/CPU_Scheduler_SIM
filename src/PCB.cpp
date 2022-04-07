#include "./headers/PCB.h"
//Main file

//Constructor that takes in PID and state as arguments
PCB::PCB(int pid, state st){
    this->PID = pid;
    this->PC = 0;
    this->s = st;
}

//Default constructor for PCB
PCB::PCB(){
    this->PID = -1;
    this->PC = 0;
    this->s = state::begin; 
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

// getter/setter for process state
state PCB::getState(){ 
    return this->s; 
}
void PCB::setState(state st){ 
    this->PCB::s = st; 
}

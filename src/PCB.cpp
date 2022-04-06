#include "../CPU_Scheduler_SIM/headers/PCB.h"
//Main file

PCB::PCB()
{
    s = state::begin;
    
}

int PCB::getPID()
{ return this->PID; }

int PCB::getPC()
{ return this->PC; }

state PCB::getState()
{ return this->s; }

void PCB::setState(state st)
{ this->PCB::s = st; }

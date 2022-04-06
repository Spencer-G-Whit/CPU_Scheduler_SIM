#ifndef datafile_h
#define datafile_h
//Main file
#include <iostream>
#include <vector>

class DataFile {
    private:
        int PID;
        int arrivalTime;
        std::vector<int> cpuBurst;
        std::vector<int> ioBurst;

    public:
        DataFile();
        
        int getPID();
        void setPID();
        int getTime();
        void setTime();
        int getCPUBurst();
        void setCPUBurst();
        int getIOBurst();
        void setIOBurst();
        void generateFile();

    
};

#endif
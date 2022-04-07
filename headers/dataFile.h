#ifndef datafile_h
#define datafile_h

#include <vector>

class DataFile {
    private:
        int PID;
        int arrivalTime;
        std::vector<int> cpuBurst;
        std::vector<int> ioBurst;

    public:
        //Constructor with arguments
        DataFile(int pid, int aTime, std::vector<int> cBurst, std::vector<int> iBurst);
        
        //defualt constructor
        DataFile();
        
        //methods to get and set pid values
        int getPID();
        void setPID(int PID);
        
        //methods to get and set arrival time(s)
        int getTime();
        void setTime(int arrivalTime);
        
        //methods to get and set cpuBurst vector
        int getCPUBurst();
        void setCPUBurst(std::vector<int> cpuBurst);
        
        //methods to get and set IOBurst vector
        std::vector<int> getIOBurst();
        void setIOBurst(std::vector<int> ioBurst);
        
        //method to generate file for data simulation
        void generateFile();

    
};

#endif
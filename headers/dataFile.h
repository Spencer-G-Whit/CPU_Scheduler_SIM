#ifndef datafile_h
#define datafile_h

#include <vector>
#include <queue>

enum procType {cpu, IO};
enum state {begin, ready, running, blocked, finished};

class DataFile {
    private:
        int PID;
        int arrivalTime;
        std::vector<int> cpuBurst;
        std::vector<int> ioBurst;
        std::vector<procType> PC;
        state s;

    public:
        //Constructor with arguments
        DataFile(int pid, int aTime, std::vector<int> cBurst, std::vector<int> iBurst, state state);
        
        //defualt constructor
        DataFile();
        
        //methods to get and set pid values
        int getPID();
        void setPID(int PID);
        
        //methods to get and set arrival time(s)
        int getTime();
        void setTime(int arrivalTime);
        
        //methods to get and set cpuBurst vector
        std::vector<int> getCPUBurst();
        void setCPUBurst(std::vector<int> cBurst);
        void decrementCPU();
        void deleteFirstCPU();
        
        //methods to get and set IOBurst vector
        std::vector<int> getIOBurst();
        void setIOBurst(std::vector<int> iBurst);
        void decrementIO();
        void deleteFirstIO();

        // state getter/setter for state enum
        state getState();
        void setState(state state);

        // getter and setter for PC vector
        std::vector<procType> getPC();
        void setPC(std::vector<procType> pc);
        
        //method to generate file for data simulation
        void generateFile();

    
};

#endif
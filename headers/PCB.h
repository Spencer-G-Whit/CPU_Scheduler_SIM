#ifndef PCB_h
#define PCB_h

enum state {begin, ready, running, blocked, finished};

class PCB {
    private:
        int PID;
        int PC;
        state s;

    PCB();
    
    
    public:
        //methods to get and set pid values
        int getPID();
        void setPID(int PID);

        //methods to get and set pc values
        int getPC();
        void setPC(int PC);

        //methods to get and set state (enum value)
        state getState();
        void setState(state state);
};

#endif
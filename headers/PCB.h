#ifndef PCB_h
#define PCB_h

class PCB {
    int PID;
    int PC;
    enum State {ready};

    PCB();
    
    
    public:
        int getPID();
        void setPID(int PID);

        int getPC();
        void setPC(int PC);

        State getState();
        void setState(State state);
};

#endif
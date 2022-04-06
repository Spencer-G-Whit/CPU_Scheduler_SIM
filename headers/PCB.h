#ifndef PCB_h
#define PCB_h
//Main file
class PCB {
    private:
        int PID;
        int PC;
        enum State {begin, ready, };

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
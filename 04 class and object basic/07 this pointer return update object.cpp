#include <iostream>
using namespace std;

enum taskCauseE{
    NORMAL,
    PARA
};

enum taskNameE{
    UE_DL_NAS,
    UE_RRC_RECONF,
    UE_DEFAULT
};

enum taskHandlerE{
    RRC_CTXT,
    NAS_CTXT
};

class Coord {
    public:
    int m_taskName;
    int m_taskHandler;
    int m_taskPriority;
    int m_taskCause;
    int m_taskData;
    // for business
    Coord(int taskName, int taskData){
        cout << "in Coord::Coor(for business)" << endl;
        m_taskName = taskName;
        m_taskData = taskData;
        *this = getTask(taskName);
    }

    private:
    

    // for task sheduler
    Coord(int taskName, int taskHandler, int taskPriority, int taskCause = NORMAL){
        cout << "in Coord::Coor(for task sheduleer)" << endl;
        m_taskHandler = taskHandler;
        m_taskPriority = taskPriority;
        m_taskCause = taskCause;
    }

    Coord getTask(int taskName){
        switch (taskName){
            case UE_DL_NAS:{
                return Coord(UE_DL_NAS, NAS_CTXT,5);
            }
            case UE_RRC_RECONF:{
                return Coord(UE_RRC_RECONF, RRC_CTXT,4);
            }
        }
        return Coord(UE_DEFAULT, UE_DEFAULT, 99);
    }
    
    
};

int main(){
    Coord cc(UE_DL_NAS, 100); 
    cout << cc.m_taskName << endl;
    cout << cc.m_taskHandler << endl;
    cout << cc.m_taskPriority << endl;
    cout << cc.m_taskCause << endl;
    cout << cc.m_taskData << endl;
    return 0;
}

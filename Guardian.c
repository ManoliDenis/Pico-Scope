#include "Guardian.h"
#include "DataMonitor.h"
#include "logger.h"


#define GUARDIAN_LOCAL_DEBUG 1
#if GUARDIAN_LOCAL_DEBUG == 0 
    #define LOG(...) 0;
#endif

GuardianStatus _current_guardian_status;
GuardianState _current_guardian_state;

void guardian_monitor()
{
    if(_current_guardian_state == GUARDIAN_OFFLINE)
    {    
        LOG("GUARDIAN ONLINE");
        _current_guardian_state = GUARDIAN_ONLINE;
    }
    else 
    {
        LOG("GUARDIAN OFFLINE");
        _current_guardian_state = GUARDIAN_OFFLINE;
    }
}    
void guardian_tick()
{   
    update_reads();
    LOG("cpu_temp:%d.%d ",cpu_temp/100,cpu_temp%100);
    _current_guardian_status = (cpu_temp*100 > 0 && cpu_temp*100 <5000)?GUARDIAN_STATUS_OK:GUARDIAN_STATUS_ERROR;
}
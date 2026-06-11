#include "TriggerSync.h"


 StatusDTO trigger_sync_init()
 {
    return (StatusDTO){.complexity = STATUS_SIMPLE, .status.simple_status = {.status = STATUS_SUCCESS, .status_message = STATUS_SUCCESS_MESSAGE}};
 }
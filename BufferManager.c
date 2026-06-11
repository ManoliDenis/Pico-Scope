#include "BufferManager.h"

StatusDTO buffer_manager_init()
{
    return (StatusDTO){.complexity = STATUS_SIMPLE, .status.simple_status = {.status = STATUS_SUCCESS, .status_message = STATUS_SUCCESS_MESSAGE}};
}
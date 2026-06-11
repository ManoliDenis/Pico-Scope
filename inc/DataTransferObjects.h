#ifndef DATA_TRANSFER_OBJECTS_H_
#define DATA_TRANSFER_OBJECTS_H_


/* DEFINES */
#define STATUS_SUCCESS 0
#define STATUS_ERROR 1
#define STATUS_SUCCESS_MESSAGE "Success!"
#define STATUS_ERROR_MESSAGE "Failure!"


// Complexity Enum. Used to determine StatusDTO type. 
typedef enum 
{
    STATUS_SIMPLE = 0,
    STATUS_COMPLEX = 1
} COMPLEXITY;


/* DTOS */

// Eats more memory, but allows for easier DEBUG 
typedef struct {
    short int status;
    unsigned char status_message[64];
    unsigned char stack_trace[256];
    
} ComplexStatusDTO;

// Eats less memory, but is harder to DEBUG
typedef struct {
    short int status;
    unsigned char status_message[64];
   
} SimpleStatusDTO;

// Union of all response DTOs. Use the status field to determine which one is being used
typedef union {
    ComplexStatusDTO complex_status;
    SimpleStatusDTO simple_status;
} StatusDTOReference;

/* HINT: Use vsnprintf(...) */
/* WARNING: Only one type should be used at a time */
typedef struct {
    COMPLEXITY complexity;
    StatusDTOReference status;
} StatusDTO;

#endif  /* DATA_TRANSFER_OBJECTS_H_ */
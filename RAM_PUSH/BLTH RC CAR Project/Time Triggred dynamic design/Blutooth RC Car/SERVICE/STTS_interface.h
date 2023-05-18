/**
 * @file STTS_interface.h
 * @author Osama Mahmoud (you@domain.com)
 * @brief  this file contains the interfacing information for TTS Module
 * @version 1.0
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* file header guard */
#ifndef _STTS_INTERFACE_H_
#define _STTS_INTERFACE_H_


/**************************************************************************************/
/*                                Interfacing macros                                  */
/**************************************************************************************/
#define TASK_READY                          (1)
#define TASK_SUSPENDED                      (2)

/**************************************************************************************/
/*                                Interfacing task structure                          */
/**************************************************************************************/

typedef struct{
	
    void (*TaskHandler)(void);
	u8_t  au8_priodicity;
	u8_t   State;
	
}task_t;


/**************************************************************************************/
/*                                Interfacing class                                   */
/**************************************************************************************/

class sttsClass_t
{
    public:
          
          /**
           * @brief Construct a new stts class object with a specific time in milliseconds
           * 
           * @param au8_systemTickMs 
           */
          sttsClass_t(u8_t au8_systemTickMs);

          
          /**
           * @brief This function is used to add a Task to the system
           * 
           * @param ast_newTask 
           */
          void CreateTask(task_t ast_newTask);

          
          /**
           * @brief This function is used to run TTS scheduler
           * 
           */
          void schedulerRun(void);
          
          /**
           * @brief This function used to send the task to suspend state
           * 
           * @param au8_TaskID 
           */
          void SuspendTask(u8_t au8_TaskID);
          
          /**
           * @brief This function used to return the task to READY state
           * 
           * @param au8_TaskID 
           */
          void ResumeTask(u8_t au8_TaskID);


};

#endif /*_STTS_INTERFACE_H_*/























/*
 * scheduler.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Chung Thinh
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include "main.h"

typedef struct{
	void (*pTask)(void);
	uint32_t	Delay;
	uint32_t	Period;
	uint8_t		RunMe;

	uint32_t	TaskID;
}sTasks;

void SCH_Init(void);

void SCH_Add_Task ( void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Delete_Task(uint32_t taskID);

void SCH_Report_Status(void);


#define SCH_MAX_TASKS	5
#define NO_TASK_ID		0

extern int index_task;

sTasks SCH_tasks_G[SCH_MAX_TASKS];

#endif /* INC_SCHEDULER_H_ */

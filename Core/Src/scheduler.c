/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Chung Thinh
 */
#include "scheduler.h"

int current_index_task = 0;
int TIMER_CYCLE = 10;
int index_task = 0;
int time = 0;
int flag = 0;

void SCH_Init (void){
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
}

void SCH_Add_Task ( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	if(current_index_task < SCH_MAX_TASKS){

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY/TIMER_CYCLE;
		SCH_tasks_G[current_index_task].Period =  PERIOD/TIMER_CYCLE;
		SCH_tasks_G[current_index_task].RunMe = 0;
		SCH_tasks_G[current_index_task].TaskID = current_index_task;
		current_index_task++;
	}
}
void SCH_Update(void){
//	for(int i = 0; i < current_index_task; i++){
//		if (SCH_tasks_G[i].Delay > 0){
//			SCH_tasks_G[i].Delay --;
//		}else{
//			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
//			SCH_tasks_G[i].RunMe += 1;
//		}
//	}
	if(flag == 0)
	{
		if (SCH_tasks_G[index_task].Delay > 0)
		{
			time = SCH_tasks_G[index_task].Delay;
		}
		time = time + SCH_tasks_G[index_task].Period;
		flag = 1;
	}
	if(index_task == current_index_task)
	{
		index_task = 0;
		time = 0;
	}
	if (SCH_tasks_G[index_task].Delay > 0)
	{
		SCH_tasks_G[index_task].Delay--;
	}
	else
	{
		SCH_tasks_G[index_task].Delay = SCH_tasks_G[index_task].Period;
		SCH_tasks_G[index_task].RunMe += 1;
	}

	if(SCH_tasks_G[index_task].Delay == 0)
	{
		index_task++;
		SCH_tasks_G[index_task].Delay =
	}
}
void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < current_index_task; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
		}
		if (SCH_tasks_G[i].Period == 0)
		{
			SCH_Delete_Task(i);
		}
	}

}

void SCH_Delete_Task(uint32_t taskID)
{
	SCH_tasks_G[taskID].pTask = 0x0000;
	SCH_tasks_G[taskID].Delay = 0;
	SCH_tasks_G[taskID].Period = 0;
	SCH_tasks_G[taskID].RunMe = 0;
}


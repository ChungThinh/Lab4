/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Chung Thinh
 */
#include "scheduler.h"

int current_index_task = 0;
int TIMER_CYCLE = 10;
int time = 0;
int flag = 0;
int min_time = 0;

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
	time++;
}
void SCH_Dispatch_Tasks(void){
	if(flag == 0)
	{
		for(int i = 0; i < current_index_task; i++)
		{
			if(SCH_tasks_G[i].Delay == 0)
			{
				SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period/TIMER_CYCLE;
			}
			{

				SCH_tasks_G[i].Delay -= min_time;
			}
		}
		flag = 1;
		min_time =  SCH_tasks_G[0].Delay;
	}
	for(int i = 0; i < current_index_task; i++)
	{
		if(min_time >  SCH_tasks_G[i].Delay)
			min_time =  SCH_tasks_G[i].Delay;
	}

	if(time == min_time)
	{
		for(int i = 0; i < current_index_task; i++)
		{
			if(min_time == SCH_tasks_G[i].Delay)
			{
				SCH_tasks_G[i].RunMe += 1;
				 SCH_tasks_G[i].Delay = 0;
			}
		}
		time = 0;
		flag = 0;
	}
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


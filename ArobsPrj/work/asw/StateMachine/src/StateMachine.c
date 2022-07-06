/*
 * StateMachine.c
 *
 * Created: 7/6/2022 5:59:53 PM
 *  Author: alexei.guriev
 */ 

/*******************************************************************************
 * includes
 ******************************************************************************/
#include "StateMachine.h"
#include "StateMachineType.h"

/*******************************************************************************
 * local variables
 ******************************************************************************/
static StateMachine s_stateMachine = StateMachineInit;


void StateMachineIterate(void)
{
	switch(s_stateMachine)
	{
		case StateMachineInit:
		
		break;
		
		case StateMachineIdle:
		
		break;
		
		case StateMachineExecution:
		
		break;
		
		case StateMachineError:
		
		break;
		
		default:
		break;
		
	}
	
	
}
/*******************************************************************************
 * functions
 ******************************************************************************/
/*
 * StateMachineType.h
 *
 * Created: 7/6/2022 6:01:48 PM
 *  Author: alexei.guriev
 */ 


#ifndef STATEMACHINETYPE_H_
#define STATEMACHINETYPE_H_

                                                                                                                                                                      
/*******************************************************************************                                                                                             
 * enumerations                                                                                                                                                              
 ******************************************************************************/                                                                                             
                                                                                                                                                                             
/**                                                                                                                                                                          
 * @brief Error code definition.                                                                                                                                             
 */                                                                                                                                                                          
typedef enum {
	StateMachineInit       =  0,
	StateMachineIdle       =  1,
	StateMachineExecution  =  2,
	StateMachineError      =  3
} StateMachine;



#endif /* STATEMACHINETYPE_H_ */
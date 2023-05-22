/*************************************************************************************************/
/*   Author    :   Osama Mahmoud                                                                 */
/*   Date      :   25/8/2020                                                                     */
/*   Version   :   V01                                                                           */
/*************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_config.h" 
#include "SYSTICK_private.h"


/* Define Callback Global Variable */
static void (*STK_CallBack) (void);                /* Pointer to Function */

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{    
	#if   STK_CLOCK  == AHB_DIV_8       /* Select Clock Timer */
	CLR_BIT(STK_CTRL , CLKSOURCE);
	#elif STK_CLOCK  == AHB       
	SET_BIT(STK_CTRL , CLKSOURCE);  
	#endif
	CLR_BIT(STK_CTRL , ENABLE);         /* Disable Timer */
	CLR_BIT(STK_CTRL , TICKINT);        /* Disable Interrupt Timer */
}
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )   /* Synchronous  Function  */
{   

	/* Load Ticks to LOAD Register */
	
	STK_LOAD = Copy_u32Ticks*1000;
	
	/* start timer */
	SET_BIT(STK_CTRL , ENABLE);
	
	while(  (GET_BIT(STK_CTRL , COUNTFLAG))  == 0);
	
	/* stop timer */
	CLR_BIT(STK_CTRL , ENABLE);
	STK_LOAD = 0;
	STK_VAL  = 0;
	
}
void MSTK_voidSetIntervalSingle( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{   
	CLR_BIT(STK_CTRL , ENABLE);
	STK_VAL  = 0;
    /* Load Ticks to LOAD Register */
	STK_LOAD = Copy_u32Ticks;
	
	/*   Start Timer      */
	SET_BIT(STK_CTRL , ENABLE); 
	
	/*   Save CallBack    */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	
	/* Enable Interrupt   */
	SET_BIT(STK_CTRL , TICKINT);    
	
}
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load Ticks to LOAD Register */
	STK_LOAD = Copy_u32Ticks; 
	
	/*   Start Timer      */
	SET_BIT(STK_CTRL , ENABLE); 
	
	/*   Save CallBack    */
	STK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	
	/* Enable Interrupt   */
	SET_BIT(STK_CTRL , TICKINT);   
	
}
void MSTK_voidStopInterval(void)
{   
    /* Disable Interrupt */
	CLR_BIT(STK_CTRL , TICKINT);
	
    /* Stop timer */
	CLR_BIT(STK_CTRL , ENABLE);
    STK_LOAD = 0;
    STK_VAL  = 0;	
}
u32  MSTK_u32GetElapsedTime(void)
{   
    u32 Local_u32Load  = STK_LOAD;
	u32 Local_u32Value = STK_VAL;
	
	u32 Local_u32ElapsedTime = Local_u32Load - Local_u32Value;
	
	return Local_u32ElapsedTime;
}
u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainingTime = 0;
	
    Local_u32RemainingTime = STK_VAL;
	
	return Local_u32RemainingTime;
}

                                 
void SysTick_Handler(void)       /*  ISR of STK  */
{
	u8 Local_u8Temporary;
	
	if(MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable Interrupt */
	    CLR_BIT(STK_CTRL , TICKINT);
		
		/* Stop timer */
	    CLR_BIT(STK_CTRL , ENABLE);
        STK_LOAD = 0;
        STK_VAL  = 0;	
	}
	
	    /* CallBack notification */
	    STK_CallBack();
		
		/* Clear interrupt flag */
	    Local_u8Temporary = GET_BIT(STK_CTRL , COUNTFLAG);
}



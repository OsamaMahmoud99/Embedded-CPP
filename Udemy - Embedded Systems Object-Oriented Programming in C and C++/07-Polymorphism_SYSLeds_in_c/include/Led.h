#ifndef LED_H
#define LED_H


#define LED_PORT          GPIOB
 
#define LED_PORT_CLOCK    (3)

#define LED_RED_PIN       (0)
#define LED_GREEN_PIN     (1)
#define LED_BLUE_PIN      (3)
#define LED_YELLOW_PIN    (4)


typedef enum{
	
	RED = 0,
	GREEN,
	YELLOW,
	BLUE
	
}LedColor_Type;

typedef enum{
	OFF = 0,
	ON = 1
}LedState_Type;


typedef struct{
	struct LedVtable const *vptr; /* virtual pointer */
	LedColor_Type color; /* color of led */
	LedState_Type state; /* state of led */
}Led_Type;

/* Led virtual table */
struct LedVtable{
	void(*run_diagnostics)(Led_Type const * const me);
	u32 (*compute_efficiency)(Led_Type const * const me);
};

void Led_ctor(Led_Type* const me, LedColor_Type _color, LedState_Type _state);
void Led_setState(Led_Type* const me , LedState_Type _state);

/* Method 1 */

static inline void Led_runDiagnostics_Vcall(Led_Type const * const me){

	(*me->vptr->run_diagnostics)(me);
}

static inline u32 led_computeEffi_Vcall(Led_Type const * const me){

	return (*me->vptr->compute_efficiency)(me);
}


/* Method 2 */
#define LED_RUN_DIAG_VCALL(me)             (*(me)->vptr->run_diagnostics)(me)
#define LED_GET_EFFI_VCALL(me)             (*(me)->vptr->compute_efficiency)(me)

void runSystemDiagnostics(Led_Type const *led_modules[]);
void computeLedEffs(Led_Type const *led_modules[]);

#endif

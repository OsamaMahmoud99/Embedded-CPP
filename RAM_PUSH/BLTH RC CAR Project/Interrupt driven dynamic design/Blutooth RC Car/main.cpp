#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "Bluetooth_RC_Car_interface.h"


int main(void)
{
    
    system_init();

    while(1)
    {
        system_getInput();

        system_processing_update();
        
    }
    
    return 0;
}

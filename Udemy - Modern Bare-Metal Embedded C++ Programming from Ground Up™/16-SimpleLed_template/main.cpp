#include "mcal_reg.h"

// GPIOA 0x4002 0000
// RCC 0x4002 3800
//LED = PA5
//GPIOA = AHB1

//offset RCC_AHB1ENR -> 0x30 
// EnGPIOA -> bit 0



#define RCC_AHB1ENR  (*((volatile unsigned int *)0x40023830))
#define GPIOA_MODER  (*((volatile unsigned int *)0x40020000))
#define GPIOA_ODR    (*((volatile unsigned int *)0x40020014))
	
class Led
{
	
	public:
		
		typedef std::uint32_t port_type;
		typedef std::uint32_t bval_type;
	
	Led(const port_type p , bval_type b):port(p),bval(b)
	{
		//(*(volatile uint32_t *)GPIOB) = (uint32_t)bval;
		/*Disable pin*/
		*reinterpret_cast<volatile port_type *>(port) 
			&= ~(1U<<bval);
		
		/*Set pin mode to output*/
		const port_type gpio_mode_reg = port - 0x14;
		*reinterpret_cast<volatile port_type *>(gpio_mode_reg) |= (1U <<(bval*2));
		
		
	}
	
	void toggle()const
	{
		*reinterpret_cast<volatile port_type *>(port) ^= (1U << bval);
	}
	
	void pseudo_delayMs()
	{
		int i;
		for(i=0; i<190000;i++){
		
		}
	}
		
	private:
		
		const port_type port;
		const bval_type bval;
		
};

template<typename port_type, 
	       typename bval_type,
				 const port_type port,
				 const bval_type bval>
					 
class led_template 
{
	public:
		led_template()
		{
			/*Set pin low*/
			*reinterpret_cast<volatile port_type *>(port) 
				&= (~(1U<<bval));
			
			/*Set pin to output*/
			*reinterpret_cast<volatile port_type *>(gpio_mode_reg) |= (1U <<(bval*2));
		}
		static void toggle()
		{
			*reinterpret_cast<volatile port_type *>(port) ^= (1U << bval);
		}
		static void pseudo_delayMs()
	  {
			int i;
			for(i=0; i<190000;i++){
			
			}
	  }
	private:
		static const port_type gpio_mode_reg = port - 0x14;
	
	
};
	             
int main()
{
	RCC_AHB1ENR |= (1U<<0);
	
	const led_template<std::uint32_t,
		std::uint32_t,
	  mcal::reg::gpioa,
	  mcal::reg::gpio_pin5>  led_b5;

	while(1)
	{
		led_b5.toggle();
		led_b5.pseudo_delayMs();
	
	}
	
}

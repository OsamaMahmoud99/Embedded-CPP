#include "mcal_reg.h"


std::int32_t button_state;
int main()
{
	
	const std::uint32_t ahb1enr = mcal::reg::ahb1enr;
	const std::uint32_t gpioa_moder = mcal::reg::gpioa_moder;
	const std::uint32_t gpioc_moder = mcal::reg::gpioc_moder;
  const std::uint32_t gpioa_bsrr = mcal::reg::gpioa_bsrr;
	
	/*Enable clock to Port A*/
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,ahb1enr,(1U<<0)>::reg_or();
	
	/*Enable clock to Port C*/
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,ahb1enr,(1U<<2)>::reg_or();

	/*Set PA5 as output pin*/
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,gpioa_moder,(1U<<10)>::reg_or();
	
	/*Set PC13 as input pin*/
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,gpioc_moder,(0U<<26)>::reg_or();
  mcal::reg::reg_access<std::uint32_t,std::uint32_t,gpioc_moder,(0U<<27)>::reg_or();

	while(1)
	{
		/*Read PC13*/
		button_state = mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::gpioc_idr,0U>::reg_get();
		
		if(button_state & 0x2000){
				mcal::reg::reg_access<std::uint32_t,std::uint32_t,gpioa_bsrr,(1U<<21)>::reg_set();
		}
		else{
				mcal::reg::reg_access<std::uint32_t,std::uint32_t,gpioa_bsrr,(1U<<5)>::reg_set();
		}
		
	}
	
}

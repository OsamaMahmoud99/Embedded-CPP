#include "mcal_reg.h"



int main()
{
	
	const std::uint32_t ahb1enr = mcal::reg::ahb1enr;
	const std::uint32_t gpioa_moder = mcal::reg::gpioa_moder;
	const std::uint32_t gpioa_bsrr = mcal::reg::gpioa_bsrr;
	/*Enable clock to Port A*/
	
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,ahb1enr,(1U<<0)>::reg_or();
	
	/*Set PA5 as output pin*/
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,gpioa_moder,(1U<<10)>::reg_or();
	while(1)
	{
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,gpioa_bsrr,(1U<<5)>::reg_set();
		for(int i=0; i<1800000;i++){}
		mcal::reg::reg_access<std::uint32_t,std::uint32_t,gpioa_bsrr,(1U<<21)>::reg_set();
		for(int i=0; i<1800000;i++){}
	}
	
}

#include "mcal_reg.h"


typedef struct bit32_type
{
	std::uint8_t b0 : 1;
	std::uint8_t b1 : 1;
	std::uint8_t b2 : 1;
	std::uint8_t b3 : 1;
	
	std::uint8_t b4 : 1;
	std::uint8_t b5 : 1;
	std::uint8_t b6 : 1;
	std::uint8_t b7 : 1;
	
	std::uint8_t b8 : 1;
	std::uint8_t b9 : 1;
	std::uint8_t b10 : 1;
	std::uint8_t b11 : 1;
	
	std::uint8_t b12 : 1;
	std::uint8_t b13 : 1;
	std::uint8_t b14 : 1;
	std::uint8_t b15 : 1;
	
	std::uint8_t b16 : 1;
	std::uint8_t b17 : 1;
	std::uint8_t b18 : 1;
	std::uint8_t b19 : 1;
	
	std::uint8_t b20 : 1;
	std::uint8_t b21 : 1;
	std::uint8_t b22 : 1;
	std::uint8_t b23 : 1;
	
	std::uint8_t b24 : 1;
	std::uint8_t b25 : 1;
	std::uint8_t b26 : 1;
	std::uint8_t b27 : 1;
	
	std::uint8_t b28 : 1;
	std::uint8_t b29 : 1;
	std::uint8_t b30 : 1;
	std::uint8_t b31 : 1;
	
}bit32_type;

template <typename addr_type,
	        typename reg_type,
					typename bits_type>

struct reg_map_dynamic{
	
	static reg_type& value(const addr_type addr){
		
		return *reinterpret_cast<reg_type *>(addr);
	}
	
	static bits_type& bits(const addr_type addr){
		
		return *reinterpret_cast<bits_type *>(addr);
	}

};	
typedef union union_reg_map_c
{
	std::uint32_t value;
	bit32_type bits;
	
}reg_map_c;

int main()
{
	std::uint32_t ahb1enr = mcal::reg::rcc::ahb1enr;
	std::uint32_t gpiob = mcal::reg::gpio::cfg_regs::gpiob_cfg::gpiob_odr;

	/* Enable clock access to GPIOB*/
	reg_map_dynamic<std::uint32_t,
	                std::uint32_t,
	                bit32_type>::bits(ahb1enr).b1 = 1U;
	
	
   reg_map_dynamic<std::uint32_t,
	                std::uint32_t,
	                bit32_type>::value(gpiob) = 0xFF;
	
	
	while(1)
	{
			
			reg_map_dynamic<std::uint32_t,
	                std::uint32_t,
	                bit32_type>::bits(gpiob).b11 ^= 1U;
	
	}
	
}

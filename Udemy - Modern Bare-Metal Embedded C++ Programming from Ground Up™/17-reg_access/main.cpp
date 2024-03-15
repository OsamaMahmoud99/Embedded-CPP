#include "mcal_reg.h"


template<typename addr_type,
         typename reg_type,
         const addr_type addr,
         const reg_type val>


class reg_access
{
	public:
		static void reg_set()
		{
			*reinterpret_cast<volatile addr_type *>(addr) = static_cast<reg_type>(val);
		}
		
		static void reg_or()
		{
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(val);
		}
		
		static void reg_and()
		{
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type>(val);
		}
		
		static void reg_not()
		{
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type>(~val);
		}
		
		static reg_type reg_get()
		{
			return *reinterpret_cast<volatile addr_type *>(addr);
		}
		
		static void bit_set()
		{
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<val);
		}
		
		static void bit_clr()
		{
			*reinterpret_cast<volatile addr_type *>(addr) &= static_cast<reg_type>(~static_cast<reg_type>(1U<<val));
		}
		
		static void bit_not()
		{
			*reinterpret_cast<volatile addr_type *>(addr) ^= static_cast<reg_type>(1U<<val);
		}
		
		static bool bit_get()
		{
			return ((reg_get(addr) & static_cast<reg_type>(1U<<val)) != static_cast<reg_type>(0U));
		}
	
};
int main()
{
	/*Enable clock to Port B*/
	reg_access<std::uint32_t,
		    std:: uint32_t,
	      mcal::reg::rcc::ahb1enr,
	      (1U<<1)>::reg_or();
	
	
	/* Set first 8 pins of GPIOB to HIGH*/
		reg_access<std::uint32_t,
		std:: uint32_t,
	  mcal::reg::gpio::cfg_regs::gpiob_cfg::gpiob_odr,
	  0xFF>::reg_set();
         
	
	while(1)
	{
		
	}
	
}

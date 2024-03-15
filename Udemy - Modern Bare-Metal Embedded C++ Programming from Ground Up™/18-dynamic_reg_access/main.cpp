#include "mcal_reg.h"


template<typename register_address_type,
         typename register_value_type>
       


class reg_access_dynamic
{
	public:
		static void reg_set(register_address_type address,register_value_type value)
		{
			*reinterpret_cast<volatile register_address_type *>(address) = static_cast<register_value_type>(value);
		}
		
		static void reg_or(register_address_type address,register_value_type value)
		{
			*reinterpret_cast<volatile register_address_type *>(address) |= static_cast<register_value_type>(value);
		}
		
		static void reg_and(register_address_type address,register_value_type value)
		{
			*reinterpret_cast<volatile register_address_type *>(address) &= static_cast<register_value_type>(value);
		}
		
		static void reg_not(register_address_type address,register_value_type value)
		{
			*reinterpret_cast<volatile register_address_type *>(address) &= static_cast<register_value_type>(~value);
		}
		
		static register_value_type reg_get(register_address_type address)
		{
			return *reinterpret_cast<volatile register_address_type *>(address);
		}
		
		static void bit_set(register_address_type address,register_value_type value)
		{
			*reinterpret_cast<volatile register_address_type *>(address) |= static_cast<register_value_type>(1U<<value);
		}
		
		static void bit_clr(register_address_type address,register_value_type value)
		{
			*reinterpret_cast<volatile register_address_type *>(address) &= static_cast<register_value_type>(~static_cast<register_value_type>(1U<<value));
		}
		
		static void bit_not(register_address_type address,register_value_type value)
		{
			*reinterpret_cast<volatile register_address_type *>(address) ^= static_cast<register_value_type>(1U<<value);
		}
		
		static bool bit_get(register_address_type address,register_value_type value)
		{
			return ((reg_get(address) & static_cast<register_value_type>(1U<<value)) != static_cast<register_value_type>(0U));
		}
	
};
int main()
{
	/*Enable clock to Port B*/
	reg_access_dynamic<std::uint32_t,
		                 std:: uint32_t
	                   >::reg_or(mcal::reg::rcc::ahb1enr,(1U<<1));
	
	
	/* Set first 8 pins of GPIOB to HIGH*/
		reg_access_dynamic<std::uint32_t,
		                   std:: uint32_t
	                     >::reg_set(mcal::reg::gpio::cfg_regs::gpiob_cfg::gpiob_odr,0xFF);
         
	
	while(1)
	{
		
	}
	
}

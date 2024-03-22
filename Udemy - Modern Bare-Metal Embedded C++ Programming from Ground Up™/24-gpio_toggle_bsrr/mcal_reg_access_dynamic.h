#ifndef _MCAL_REG_ACCESS_DYNAMIC_H
#define _MCAL_REG_ACCESS_DYNAMIC_H


namespace mcal
{
	
	namespace reg
	{
		
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
		
	}
	
}
#endif

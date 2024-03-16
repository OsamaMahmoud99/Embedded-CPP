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
		
		static void set_pin_output(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<(val*2));
		}
		
		static void set_pin_input(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(0U<<(val*2));
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(0U<<(1+(val*2)));
		}
		
		static void set_pin_analog(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<(val*2));
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<(1+(val*2)));
		}
		
		static void set_pin_alt(){
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(0U<<(val*2));
			*reinterpret_cast<volatile addr_type *>(addr) |= static_cast<reg_type>(1U<<(1+(val*2)));
		}
	
};

template <typename addr_type,
	        typename reg_type,
          const addr_type port,
          const reg_type bpos>


class port_pin
{
	public:
		static void set_direction_output()
		{
			port_dir_type::set_pin_output();
		}
		
		static void set_direction_input()
		{
			port_dir_type::set_pin_input();
		}
		
		static void set_pin_high()
		{
			port_pin_type::bit_set();
		}
		
		static void set_pin_low()
		{
			port_pin_type::bit_clr();
		}
		
		static bool read_input_value()
		{
			return port_inp_type::bit_get();
		}
		
		static void toggle()
		{
			port_pin_type::bit_not();
		}
		
	private:
		static const std::uint32_t odr_offset = 0x14;
		static const std::uint32_t idr_offset = 0x10;
    
		static const addr_type p_odr = port + odr_offset;
		static const addr_type p_idr = port + idr_offset;
	  
	  typedef reg_access<addr_type,reg_type,p_odr,bpos>port_pin_type;
		typedef reg_access<addr_type,reg_type,port,bpos>port_dir_type;
		typedef reg_access<addr_type,reg_type,p_idr,bpos>port_inp_type;
};	
int main()
{
	
	const std::uint32_t ahb1enr = mcal::reg::rcc::ahb1enr;
	const std::uint32_t gpioa = mcal::reg::gpio::cfg_regs::gpioa_cfg::gpioa_moder;
	
	/*Enable clock to Port A*/
	
	typedef reg_access<std::uint32_t,std::uint32_t,ahb1enr,0U> ahb1enr_b0_type;
	ahb1enr_b0_type::bit_set();
	
	typedef port_pin<std::uint32_t,std::uint32_t,gpioa,5U>pa5_type;
	pa5_type::set_direction_output();
	
	/* Set first 8 pins of GPIOB to HIGH*/
	
	
	while(1)
	{
		pa5_type::toggle();
		
		for(int i=0; i<1800000;i++){}
	}
	
}

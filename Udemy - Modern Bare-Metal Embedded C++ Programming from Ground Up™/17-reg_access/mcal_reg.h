#ifndef __MCAL_REG_H
#define __MCAL_REG_H

#include <cstdint>

namespace mcal
{
	
	namespace reg
	{
		const std::uint32_t periph_base = 0x40000000;                            
		const std::uint32_t ahb1_periph_base = periph_base + 0x00020000U;
		const std::uint32_t rcc_base         = ahb1_periph_base + 0x3800U;
		
		 namespace rcc{
			 const std::uint32_t ahb1enr = rcc_base + 0x30;
			 const std::uint32_t ahb2enr = rcc_base + 0x34;
			 const std::uint32_t ahb3enr = rcc_base + 0x38;
		 }
		 
		 namespace gpio{
			 const std::uint32_t gpioa = ahb1_periph_base + 0x0000U;
			 const std::uint32_t gpiob = ahb1_periph_base + 0x0400U;
			 const std::uint32_t gpioc = ahb1_periph_base + 0x0800U;
			 const std::uint32_t gpiod = ahb1_periph_base + 0x0C00U;
			 const std::uint32_t gpioe = ahb1_periph_base + 0x1000U;
			 
			 namespace cfg_regs{
				 
				 const std::uint32_t moder_offset = 0x00;
				 const std::uint32_t idr_offset = 0x10;
				 const std::uint32_t odr_offset = 0x14;
				 const std::uint32_t bsrr_offset = 0x18;
				 
				 namespace gpioa_cfg{
					 const std::uint32_t gpioa_moder = gpioa + moder_offset;
					 const std::uint32_t gpioa_idr = gpioa + idr_offset;
					 const std::uint32_t gpioa_odr = gpioa + odr_offset;
					 const std::uint32_t gpioa_bsrr = gpioa + bsrr_offset;
				 }
				 
				  namespace gpiob_cfg{
					 const std::uint32_t gpiob_moder = gpiob + moder_offset;
					 const std::uint32_t gpiob_idr = gpiob + idr_offset;
					 const std::uint32_t gpiob_odr = gpiob + odr_offset;
					 const std::uint32_t gpiob_bsrr = gpiob + bsrr_offset;
				 }
					
				  namespace gpioc_cfg{
					 const std::uint32_t gpioc_moder = gpioc + moder_offset;
					 const std::uint32_t gpioc_idr = gpioc + idr_offset;
					 const std::uint32_t gpioc_odr = gpioc + odr_offset;
					 const std::uint32_t gpioc_bsrr = gpioc + bsrr_offset;
				 }
			 }
			 
			
		 }
	}
}


#endif
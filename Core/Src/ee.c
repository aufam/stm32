#include "stm32f4xx_hal.h"

uint32_t ee_write(const uint8_t* data, uint32_t len, uint32_t address) {
	if (address < 0x08060000) {
		return -1; // invalid address
	}

    FLASH_EraseInitTypeDef EraseInitStruct;
	uint32_t PAGEError = 0;
    HAL_FLASH_Unlock();

	/* Unlock the Flash to enable the flash control register access *************/
	::memset(&EraseInitStruct,0,sizeof(EraseInitStruct));
	HAL_FLASH_Unlock();
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP    | FLASH_FLAG_OPERR  | FLASH_FLAG_WRPERR |
						   FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR );

	/* Erase the user Flash area*/
	EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector = FLASH_SECTOR_7;
	EraseInitStruct.NbSectors = 1;

	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK){
		/*Error occurred while page erase.*/
        HAL_FLASH_Lock();
		return HAL_FLASH_GetError ();
	}

	/* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
	     you have to make sure that these data are rewritten before they are accessed during code
	     execution. If this cannot be done safely, it is recommended to flush the caches by setting the
	     DCRST and ICRST bits in the FLASH_CR register.*/
	__HAL_FLASH_DATA_CACHE_DISABLE();
	__HAL_FLASH_INSTRUCTION_CACHE_DISABLE();

	__HAL_FLASH_DATA_CACHE_RESET();
	__HAL_FLASH_INSTRUCTION_CACHE_RESET();

	__HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
	__HAL_FLASH_DATA_CACHE_ENABLE();

    for (size_t i = 0; i < len; ++i, ++address) {
        auto res = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, address, data[i]);
        if (res != HAL_OK) {
            HAL_FLASH_Lock();
            return res;
        }
    }

    HAL_FLASH_Lock();
    return 0;
}


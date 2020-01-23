/*
 * EPD.h
 *
 *  Created on: 21 янв. 2020 г.
 *      Author: User
 */

#ifndef EPD_SD_S
#define EPD_H_

#define HEIGHT 	200
#define WIDTH	200

#define RESET_TIME	200

#define EPD_RST_UP		LL_GPIO_ResetOutputPin(RST_GPIO_Port, RST_Pin)
#define EPD_RST_DOWN	LL_GPIO_SetOutputPin(RST_GPIO_Port, RST_Pin)

#define EPD_DC_UP 		LL_GPIO_SetOutputPin(DC_GPIO_Port, DC_Pin)
#define EPD_DC_DOWN 	LL_GPIO_ResetOutputPin(DC_GPIO_Port, DC_Pin)

#endif /* EPD_H_ */
#include "main.h"

typedef enum color
{
	black = 0x00,
	white = 0xff
}color;




void EPD_Reset(void);
void EPD_Init(void);
void EPD_SendCommand(uint8_t command);
void EPD_SendData(uint8_t command);
void EPD_Paint_Screen(color background);
void EPD_Buff_Screen(uint8_t * buff, uint16_t len, color background);
//создание массива символов str
void EPD_string_to_ACSII(char *str, uint8_t *buf);
//выводим на экран символы
void EPD_string_paint(char *str);
void Busy();



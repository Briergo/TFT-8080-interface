#ifndef _TFT_8080_H_
#define _TFT_8080_H_

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DC_low HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET)
#define DC_Hi HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET)
#define RESET_Hi HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET)
#define RESET_low HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET)
#define WR_Hi HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_SET)
#define WR_low HAL_GPIO_WritePin(WR_GPIO_Port, WR_Pin, GPIO_PIN_RESET)
#define RD_Hi HAL_GPIO_WritePin(RD_GPIO_Port, RD_Pin, GPIO_PIN_SET)
#define RD_low HAL_GPIO_WritePin(RD_GPIO_Port, RD_Pin, GPIO_PIN_RESET)
#define CS_Hi HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET)
#define CS_low HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET)
#define Data_Port  GPIOD->ODR

//Basic Colors
#define CYAN	  0x07FF
#define MAGNETA   0xF81F
#define RED	0xf800
#define GREEN	0x07e0
#define BLUE	0x001f
#define BLACK	0x0000
#define YELLOW	0xffe0
#define WHITE	0xffff

#define MIN_X	0
#define MIN_Y	0

#define FONT_X 8
#define FONT_Y 8
#define LCD_W 240
#define LCD_H 320

#define LCD_PIXEL_COUNT	LCD_WIDTH * LCD_HEIGHT



/* USER CODE END PD */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void TFT_Send_Cmd(uint8_t cmd);
void TFT_Write_Data(uint8_t data);
void TFT_Init(void);
void TFT_SetOrientation(uint8_t orient);
void TFT_Send_Data(uint16_t data);
void TFT_Set_Column(uint16_t start_column,uint16_t end_colunm);
void TFT_Set_Page(uint16_t start_page,uint16_t end_page);
void TFT_Set_XY(uint16_t x, uint16_t y);
void TFT_Draw_Pixel(uint16_t x, uint16_t y,uint16_t color);
uint16_t constrain(uint16_t a, uint16_t b, uint16_t c);
void TFT_Fill_Screen(uint16_t x_left, uint16_t x_right, uint16_t y_up, uint16_t y_down, uint16_t color);
void TFT_Fill_Rectangle(uint16_t x, uint16_t y, uint16_t length, uint16_t width, uint16_t color);
void TFT_Draw_Char(uint16_t x, uint16_t y, uint16_t color, uint16_t phone, uint8_t ascii, uint8_t size);
void TFT_Draw_String(uint16_t x, uint16_t y, uint16_t color,uint16_t phone,char *string, uint8_t size);
void TFT_Draw_Line( uint16_t x0,uint16_t y0,uint16_t x1, uint16_t y1,uint16_t color);
void TFT_Draw_Horizontal_Line( uint16_t x, uint16_t y, uint16_t length,uint16_t color);
void TFT_Draw_Vertical_Line( uint16_t x, uint16_t y, uint16_t length,uint16_t color);
void TFT_Draw_Triangle( uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color);
void TFT_Draw_Circle(uint16_t pos_x, uint16_t pos_y, uint8_t r,uint16_t color);
void TFT_Fill_Circle(uint16_t pos_x, uint16_t pos_y, uint8_t r,uint16_t color);
void TFT_Image(uint16_t x, uint16_t y, uint16_t width ,uint16_t height,const unsigned char *p);
static void TFT_GPIO_Init(void);

/* USER CODE END PFP */

#endif 
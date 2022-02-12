#ifndef _MENU_H_
#define _MENU_H_

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define UP_Pin GPIO_PIN_10
#define UP_GPIO_Port GPIOF

#define LEFT_Pin GPIO_PIN_0
#define LEFT_GPIO_Port GPIOC
#define DOWN_Pin GPIO_PIN_3
#define DOWN_GPIO_Port GPIOF
#define RIGHT_Pin GPIO_PIN_5
#define RIGHT_GPIO_Port GPIOF

#define UP_Read HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin);
#define SET_Read HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin);
#define LEFT_Read HAL_GPIO_ReadPin(LEFT_GPIO_Port, LEFT_Pin);
#define DOWN_Read HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin);
#define RIGHT_Read HAL_GPIO_ReadPin(RIGHT_GPIO_Port, RIGHT_Pin);

typedef struct node 
{
  char* text;
  char cmd;
  struct node* prev;
  struct node* next;
  struct node* parent;
  struct node* child;
  unsigned int x_pos;
  unsigned int y_pos;
}
node_t;

 extern node_t* current;

/* USER CODE END PD */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */

void Menu_Create(void);
void Menu_Disp(void);
void Cursor(void);

/* USER CODE END PFP */

#endif 
#include "menu.h"
#include <stdlib.h>
#include "TFT_8080.h"



/*----------------Protatip--------------------*/
void cursor(void);
void EXTI_init(void);
void Button_init(void);
void menu_disp(void);
void menu_create(void);
void menu_create(void);
void cmd_start(node_t* start);
void LED(unsigned char adr, unsigned char pin);
void string_code_create(char* string);
void Image(uint8_t* nomer);
void LEDLAMPA (void);
/*----------------------------------------------*/

/*Vspomogat peremenn*/
node_t* current=NULL;
int count=0;
char dataled=0xFF;

/*Create glavnoe menu*/ 
node_t* menu1=NULL;
node_t* menu2=NULL;
node_t* menu3=NULL;
/*Create podmenu menu*/
node_t* menu1_1=NULL;
node_t* menu1_2=NULL;
node_t* menu2_1=NULL;
node_t* menu2_2=NULL;
node_t* menu3_1=NULL;
node_t* menu3_2=NULL;


void Menu_Create(void)
{
   /* MENU 1*/
  menu1=malloc(sizeof(node_t));
  menu1->prev=NULL;
  menu1->parent=NULL;
  menu1->text="Menu 1";
  menu1->next=malloc(sizeof(node_t));
  menu1->child=malloc(sizeof(node_t));
  menu1->cmd=NULL;
  menu1->x_pos=80;
  menu1->y_pos=40;
  /* MENU 1_1*/
  menu1_1=menu1->child;
  menu1_1->parent=menu1;
  menu1_1->text="Menu 1_1";
  menu1_1->child=NULL;
  menu1_1->prev=NULL;
  menu1_1->next=malloc(sizeof(node_t));
  menu1_1->cmd=NULL;
  menu1_1->x_pos=80;
  menu1_1->y_pos=40;
  /* MENU 1_2*/
  menu1_2=menu1_1->next;
  menu1_2->parent=menu1;
  menu1_2->text="Menu 1_2";
  menu1_2->child=NULL;
  menu1_2->prev=menu1_1;
  menu1_2->next=NULL;
  menu1_2->cmd=NULL;
  menu1_2->x_pos=80;
  menu1_2->y_pos=100;
  /* MENU 2*/
  menu2 = menu1->next; 
  menu2->child=NULL;
  menu2->parent=NULL;
  menu2->text="Menu 2";
  menu2->prev=menu1;
  menu2->next=malloc(sizeof(node_t));
  menu2->cmd=NULL;
  menu2->x_pos=80;
  menu2->y_pos=100;
  /* MENU 2_1*/
  menu2->child=malloc(sizeof(node_t));
  menu2_1=menu2->child;
  menu2_1->child=NULL;
  menu2_1->text="Menu 2_1";
  menu2_1->prev=NULL;
  menu2_1->parent=menu1;
  menu2_1->next=malloc(sizeof(node_t));
  menu2_1->cmd=NULL;
  menu2_1->x_pos=80;
  menu2_1->y_pos=40;
  /* MENU 2_1*/
  menu2_2=menu2_1->next;
  menu2_2->text="Menu 2_2";
  menu2_2->child=NULL;
  menu2_2->parent=menu1;
  menu2_2->prev=menu2_1;
  menu2_2->next=NULL;
  menu2_2->cmd=NULL;
  menu2_2->x_pos=80;
  menu2_2->y_pos=100;
  /* MENU 3*/
  menu3=menu2->next;
  menu3->child=malloc(sizeof(node_t));
  menu3->parent=NULL;
  menu3->text="Menu 3";
  menu3->prev=menu2;
  menu3->next=NULL;
  menu3->cmd=NULL;
  menu3->x_pos=80;
  menu3->y_pos=160;
  /* MENU 3_1*/
  menu3_1=menu3->child;
  menu3_1->next=malloc(sizeof(node_t));
  menu3_1->parent=menu1;
  menu3_1->child=NULL;
  menu3_1->prev=NULL;
  menu3_1->cmd=NULL;
  menu3_1->text="Menu 3_1";
  menu3_1->x_pos=80;
  menu3_1->y_pos=40;
  /* MENU 3_2*/
  menu3_2=menu3_1->next;
  menu3_2->next=NULL;
  menu3_2->cmd=NULL;
  menu3_2->parent=menu1;
  menu3_2->prev=menu3_1;
  menu3_2->child=malloc(sizeof(node_t));
  menu3_2->text="Menu 3_2";
  menu3_2->x_pos=80;
  menu3_2->y_pos=100;
  /*Menu init*/
  current=menu1;
  Menu_Disp();
  Cursor();
 
}

void Menu_Disp(void)
{
  TFT_Fill_Screen(0,320,0,240,BLUE);
  node_t* i;
  i=current;
  while(i->prev!=NULL)
        i=i->prev;
  while(i!=NULL)
  {
      TFT_Draw_String(i->x_pos,i->y_pos, BLACK, BLUE, i->text, 3);
      i=i->next;
  }  
}

void Cursor(void)
{
    TFT_Draw_String(current->x_pos,current->y_pos, RED, BLUE, current->text, 3);
}


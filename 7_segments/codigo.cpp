//#include "stm32f4xx.h"
//#include <stdio.h>
//#include <math.h>

//////////////////////VARIABLES DE LCD////////////////////
//char clear = 0x01;		 //Limpiar pantalla
//char home = 0x02;		 //Return
//char disp_on = 0x0E;	 //Display ON, cursor ON, parpadeo
//char disp_shift2 = 0x14; //Mueve el cursor -- a la derecha
//char disp_shift3 = 0x10; //Mueve el cursor -- a la izquierda
//char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10
//char pos_LCD = 0x0;
//char w_linea1 = (0x80 + pos_LCD); //Posici?n cero de la primera fila
//char w_linea2 = (0xC0 + pos_LCD); //Posici?n cero de la segunda fila
//char mode_set1 = 0x06;	 //Incremento del cursor y modo normal

//char error[]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};


//char const display[14] = {0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F}; //NUMEROS ASCII-HEXA
////                    			0     1     2     3     4     5     6     7     8     9   SUMA  RESTA MULT  DIVI 

//////////////////////VARIABLES PROGRAMA////////////////////
//int filas=0, columna, numero, posicion=0;
//int operadores[4]={0,0,0,0};

//extern "C"{
//	void SysTick_Handler(void){
//		//BARRIDO FILAS
//		filas++;
//		if(filas > 3){
//			filas = 0;
//		}		
//	}
//	
//	void EXTI15_10_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0XF000); //BANDERA
//			
//		switch(columna){
//			case 0x1000:
//				if(filas == 0){numero = 1;}
//				else if(filas == 1){numero = 4;}
//				else if(filas == 2){numero = 7;} 
//				else if(filas == 3){numero = 15;} 
//			break;
//			case 0x2000:
//				if(filas == 0){numero = 2;}
//				else if(filas == 1){numero = 5;}
//				else if(filas == 2){numero = 8;} 
//				else if(filas == 3){numero = 0;}
//			break;
//			case 0X4000:
//				if(filas == 0){numero = 3;}
//				else if(filas == 1){numero = 6;}
//				else if(filas == 2){numero = 9;} 
//				else if(filas == 3){numero = 14;}
//			break;
//			case 0x8000:
//				if(filas == 0){numero = 11;}
//				else if(filas == 1){numero = 12;}
//				else if(filas == 2){numero = 13;} 
//				else if(filas == 3){numero = 10;}
//			break;
//		}
//		operadores[posicion] = numero; 
//		posicion++;
//		if(posicion>3){posicion=0;}	
//		
//	}
//}

//////////////////////FUNCIONED LCD////////////////////
//void comando_lcd(char com){
//	GPIOA->ODR = com;
//	GPIOA->ODR &=~(1UL<<8); //RS=0
//	GPIOA->ODR |= (1UL<<9); //Enable=1
//	for(int i=0; i<1000; i++);
//	GPIOA->ODR &=~(1UL<<9); //Enable=0
//}

//void dato_lcd(char dat){
//	GPIOA->ODR = dat;
//	GPIOA->ODR |= (1UL<<8); //RS=1
//	GPIOA->ODR |= (1UL<<9); //Enable=1
//	for(int j=0; j<1000; j++);
//	GPIOA->ODR &=~(1UL<<9); //Enable=0
//}

//////////////////////FUNCION PRINCIPAL////////////////////
//int main(void) {
//	RCC -> APB2ENR |=(1UL << 14);//reloj interrupciones
//	RCC -> AHB1ENR = 0X1F;//reloj
//	
//	GPIOA -> MODER = 0X555555; //LCD
//	GPIOA -> OTYPER = 0X0;
//	GPIOA -> OSPEEDR = 0X555555;
//	GPIOA -> PUPDR = 0X555555;
//	
//	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) y PD12-PD15(ENTRADAS EXTI)
//	GPIOD -> OTYPER |= 0X0; 
//	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
//	GPIOD -> PUPDR |= 0XAA000000; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
//		
//	SYSCFG -> EXTICR[3] = 0X3333; //PINES 12, 13, 14, 15 PUERTO D	
//	EXTI -> IMR = 0XF000; // PINES 12-15 EXTI
//	EXTI -> RTSR = 0XF000; //FLANCO DE SUBIDA
//	NVIC_EnableIRQ(EXTI15_10_IRQn);
//	
//	SystemCoreClockUpdate();
//	SysTick_Config(SystemCoreClock / 1000);
//	
//	comando_lcd(clear);
//	comando_lcd(home);
//	comando_lcd(set);
//	comando_lcd(disp_on);
//	comando_lcd(mode_set1);
//	
//	while(true){
//		//BARRIDO DE FILAS DEL TECLADO
//		switch(filas){
//			case 0:
//				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
//			break;
//			case 1:
//				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
//			break;
//			case 2:
//				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
//			break;
//			case 3:
//				GPIOD -> ODR = (1UL << 3); //1000 FILA 3 ACTIVA;
//			break;
//		}
//	
//		comando_lcd(w_linea1);
//			for (int e = 0; e < 4; e++){
//				dato_lcd(display[operadores[e]]);
//			}
//			for(int j=0; j<950; j++);
//	}
//}







/*

#include "stm32f7xx.h"
#include <stdio.h>
#include <math.h>
#define MAX 16
#define LENGHT 5
#define pi 3.14159265358979

////////////////////CONTROL VARIABLES DE LCD////////////////////
char clear = 0x01;		 //Limpiar pantalla
char home = 0x02;		 //Return
char mode_set1 = 0x06;	 //Incremento del cursor y modo normal
char mode_set2 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato
char disp_on = 0x0E;	 //Display ON, cursor ON, parpadeo
char disp_off = 0x08;	 //Display OFF, cursor OFF, no parpadeo
char disp_shift = 0x1C;	 //Desplaza el display -- a la derecha
char disp_shift1 = 0x18; //Desplaza el display -- a la izquierda
char disp_shift2 = 0x14; //Mueve el cursor -- a la derecha
char disp_shift3 = 0x10; //Mueve el cursor -- a la izquierda
char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10
char pos_LCD = 0x0;
char w_linea1 = (0x80 + pos_LCD); //Posici?n cero de la primera fila
char w_linea2 = (0xC0 + pos_LCD); //Posici?n cero de la segunda fila
char centrar = 0X30;
char cgram = 0X40;
char ddram1 = 0X80;
char ddram2 = 0XC0;

int j = 0, i = 0;
int time = 1000;

char frase_error[]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};
char const display[MAX] = {0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F, 0X45, 0X46}; //NUMEROS ASCII-HEXA
//                    			0     1     2     3     4     5     6     7     8     9    SUMA  RESTA MULT  DIVI     E     F
char punto = 0X2E;

////////////////////CONTROL VARIABLES PROGRAMA////////////////////

int const numeros[MAX] = {0x40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X2, 0X78, 0X0, 0X10, 0X8, 0X3, 0X46, 0X21, 0X6, 0XE};
int resDisplay[4] = {0, 0, 0, 0}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD
int numdis[LENGHT] = {0, 0, 0, 0, 0};
//int exter = 1000000;
//int  numero, posicion, tiempo, resultado, reset = 0, igual = 0, negativo = 0;
//int teclaOprimida, count; 
//double a = 0, b = 0, aux_a = 0, aux_b = 0;

int desplazar;

int filas, columna, numero, posicion, operacion, conteo, x, y;
int decenas, unidades, resultado, igual, reset, negativo = 0;

////////////////////FUNCIONED LCD////////////////////
void comando_lcd(char b){
	GPIOE->ODR = b;
	GPIOE->ODR &=~(1UL<<8); //RS=0
	GPIOE->ODR |= (1UL<<9); //Enable=1
	for(j=0; j<time; j++);
	GPIOE->ODR &=~(1UL<<9); //Enable=0
}

void dato_lcd(char c){
	GPIOE->ODR = c;
	GPIOE->ODR |= (1UL<<8); //RS=1
	GPIOE->ODR |= (1UL<<9); //Enable=1
	for(j=0; j<time; j++);
	GPIOE->ODR &=~(1UL<<9); //Enable=0
}

extern "C"{
	void SysTick_Handler(void){
		//BARRIDO FILAS
		filas++;
		if(filas > 3){
			filas = 0;
		}		
	}
	
	void EXTI15_10_IRQHandler (void){
		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
		EXTI -> PR |= (0XF000); //BANDERA
			
		switch(columna){
			case 0x1000://SE PRESIONO LA COLUMNA 0.
				if(filas == 0){numero = 1;}
				else if(filas == 1){numero = 4;}
				else if(filas == 2){numero = 7;} 
				else if(filas == 3){reset = 1;} //TECLA ON O * = ALL CLEAR
			break;
			case 0x2000:
				if(filas == 0){numero = 2;}
				else if(filas == 1){numero = 5;}
				else if(filas == 2){numero = 8;} 
				else if(filas == 3){numero = 0;}
			break;
			case 0X4000:
				if(filas == 0){numero = 3;}
				else if(filas == 1){numero = 6;}
				else if(filas == 2){numero = 9;} 
				else if(filas == 3){igual = 1;} //TECLA IGUAL
			break;
			case 0x8000:
				if(filas == 0){numero = 11;} // TECLA A = RESTA
				else if(filas == 1){numero = 12;} // TECLA B = MULTIPLICACION
				else if(filas == 2){numero = 13;} // TECLA C = DIVISION
				else if(filas == 3){numero = 10;} // TECLA D = SUMA
			break;
		}
		conteo++;
		if(conteo == 3){conteo = 0;}
		numdis[posicion] = numero; // CADA VEZ QUE SE PRESIONE UNA TECLA EL VALOR SE INGRESA EN UN ARRAY VARIANDO LAS POSICIONES DE CENTENAS DECENAS Y UNIDADES
		posicion++;
		
//		if(posicion>4){posicion=0;}
		if(numero >= 10){
			if(numero == 10){operacion = 1;} //SUMA
			if(numero == 11){operacion = 2;} //RESTA
			if(numero == 12){operacion = 3;} //MULTIPLICACION
			if(numero == 13){operacion = 4;} //DIVISION
		}		
		
		if(numero <= 9){
			if(conteo == 1){
				decenas = numero;
			}
			if (conteo == 2){
				unidades = numero;
			}
			if(operacion == 0){
				x = (decenas * 10 + unidades);
			}else if (operacion >= 1){
				y = (decenas * 10 + unidades);
			}
		}
		
		/////NO FUNCIONA DEL TODO/////
		if(reset == 1){
			filas = 0, columna = 0, numero = 0, posicion = 0, operacion = 0, conteo = 0, x = 0, y = 0;
			decenas = 0, unidades = 0, resultado = 0, igual = 0;
			for (int i = 0; i < LENGHT; i++){
				numdis[i] = 0;
			}
			for (int i = 0; i < 4; i++){
				resDisplay[i] = 0;
			}
			reset = 0;
		}
	}
}

void desEnteros(int resultado){ // DESCOMPONER ENTEROS
	resDisplay[0] = resultado / 1000;	
	resDisplay[1] = (resultado % 1000) / 100;
	resDisplay[2] = (resultado % 100) / 10;
	resDisplay[3] = (resultado % 10);	
	
	if(negativo == 1){
		resDisplay[0] = 11;
		negativo = 0;
	}
}


////////////////////FUNCION PRINCIPAL////////////////////
int main(void) {
	RCC -> AHB1ENR |= 0X18;
	RCC -> APB2ENR |= 0X4000;
	
	GPIOE -> MODER = 0X555555; //LCD
	GPIOE -> OTYPER = 0X0;
	GPIOE -> OSPEEDR = 0X555555;
	GPIOE -> PUPDR = 0X555555;
	
//	GPIOG -> MODER = 0X5555; //LED
//	GPIOG -> OTYPER = 0X0;
//	GPIOG -> OSPEEDR = 0X5555;
//	GPIOG -> PUPDR = 0X5555;

	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) PD12-PD15(ENTRADAS EXTI)
	GPIOD -> OTYPER |= 0X0; 
	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
	GPIOD -> PUPDR |= 0XAA000055; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
	
	SYSCFG -> EXTICR[3] = 0X3333; //PINES 12, 13, 14, 15 PUERTO D	
	EXTI -> IMR = 0XF000; // PINES 12-15 EXTI
	EXTI -> RTSR = 0XF000; //FLANCO DE SUBIDA
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 10);
	
	comando_lcd(clear);
	comando_lcd(home);
	comando_lcd(set);
	comando_lcd(disp_on);
	comando_lcd(mode_set1);
	
	while(1){
		//BARRIDO DE FILAS DEL TECLADO
		switch(filas){
			case 0:
				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
			break;
			case 1:
				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
			break;
			case 2:
				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
			break;
			case 3:
				GPIOD -> ODR = (1UL << 3); //1000 FILA 0 ACTIVA;
			break;
		}
		
//			GPIOG -> ODR = numeros[numero];

		comando_lcd(w_linea1);
		for (int e = 0; e < 5; e++){
			dato_lcd(display[numdis[e]]);
		}
		for(j=0; j<950; j++);
		
		if(igual != 0){
			switch(operacion){
				case 1:
					resultado = x + y;
				  desEnteros(resultado);
				break;
				
				case 2:
					if(x < y) {
						negativo = 1;
						resultado = y -x;
					}
					if(x > y){
					resultado = (x - y);
					}
				  desEnteros(resultado);
				break;
				
				case 3:
					resultado = x * y;
				  desEnteros(resultado);
				break;
			}
		}
		
		while(igual == 1){
			comando_lcd(w_linea2);
			for (int e = 0; e < 4; e++){
				dato_lcd(display[resDisplay[e]]);
			}
		}
	}
}
//FIN
*/




/*


#include "stm32f4xx.h"
#include <math.h>

double pi = 3.14159265358979;																										   //NUMERO PI
int numeros[] = {0X40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X02, 0X78, 0X00, 0X18, 0X3F, 0X6};											   //NUMEROS PARA EL DISPLAY CA
int posicion[] = {0X1, 0X2, 0X4, 0X8, 0X10};																						   //ACTIVAR DISPLAY DE MULTIPLEXACION
int punto[] = {1, 1, 0, 1, 1};																										   //MOSTRAR PUNTO EN EL DISPLAY 3
int resDisplay[5] = {0, 0, 0, 0, 0};																								   //ALMACENAR LOS NUMEROS PARA OPERARLOS
int teclaopri, u = 0, d = 0, cont = 0, operacion = 0, tecla = 0, igual = 0, a = 0, b = 0, ta = 0, tb = 0, negativo = 0, resultado = 0; //VARIABLES GLOBALES
double aux_a = 0, aux_b = 0;
*/
///////*****FUNCIONES****///////
/*
int cl = 0;
int num = 0;
int keypad(void) //Teclado
{
	for (int filas = 0; filas < 4; filas++)
	{
		GPIOD->ODR = (1UL << filas);
		cl = (GPIOD->IDR & 0xf000) >> 12; //recibe las se?ales del pin 15 al 12
		for (int colum = 0; colum < 4; colum++)
		{
			num++;
			if (cl == (1UL << colum))
			{
				return num;
			}
		}
	}
}*/
///////*****FUNCIONES****///////
/*
void error(void) //PARA MOSTRAR ERRORES
{
	resDisplay[0] = 11;
	resDisplay[1] = 11;
	resDisplay[2] = 11;
	resDisplay[3] = 11;
	resDisplay[4] = 11;
}*/
///////*****FUNCION PRINCIPAL****///////
/*
int main(void)
{
	RCC->APB2ENR |= (1UL << 14);
	RCC->AHB1ENR = 0X1F;

	GPIOD->MODER = 0X00000055;
	GPIOD->OTYPER = 0X0;
	GPIOD->PUPDR = 0XAA000000;
	GPIOD->ODR = 0XF;

	GPIOA->MODER = 0X55555555;
	GPIOA->OTYPER = 0X0;
	GPIOA->OSPEEDR = 0X55555555;
	GPIOA->PUPDR = 0X55555555;

	GPIOC->MODER = 0X0;
	GPIOC->PUPDR = 0XAAAAAAAA;
*/
	///////*****INTERRUPCIONES****///////
	/*

	SYSCFG->EXTICR[3] = 0X3333;
	SYSCFG->EXTICR[1] = 0X2220;
	EXTI->IMR |= 0XF0E0;
	EXTI->RTSR |= 0XF0E0;

	NVIC_EnableIRQ(EXTI15_10_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);

	while (1)
	{
		//OPERACIONES
		switch (operacion)
		{
		case 1:
			resultado = a + b; //SUMA
			break;
		case 2:	
			if(a == b){
			  resultado = 0;
			}
			if(b > a){
			negativo = 1; resultado = b-a;
			}
			if(b < a){
			resultado = a-b;
			}  
	  	break;
		case 3:
			resultado = a * b;
			break;
		case 4:
			if (b != 0) //NO SE PUEDE DIVIDIR EN 0
			{
				ta = a * 100;
				resultado = ta / b; //DIVISION
			}
			else
			{
				error();
			}
			break;
		case 5:
			aux_a = a;
			resultado = sin((double)((aux_a * pi) / 180)) * 100; //FUNCION SENO
			if (resultado < 0)
			{
				negativo = 1;
			}
			break;
		case 6:
			aux_a = a;
			resultado = cos((double)((aux_a * pi) / 180)) * 100; //FUNCION COSENO
			if (resultado < 0)
			{
				negativo = 1;
			}
			break;
		case 7:
			aux_a = a;
			if (aux_a != 90)
			{
				resultado = tan((double)((aux_a * pi) / 180)) * 100; //FUNCION TANGENTE
				if (resultado < 0)
				{
					negativo = 1;
				}
			}
			else
			{
				error();
			}
			break;
		}
		if (resultado != 0 && (operacion == 4 || operacion == 5 || operacion == 6 || operacion == 7)) //EN CASO DE DECIMALES
		{
			resDisplay[0] = resultado / 10000;
			resDisplay[1] = resultado / 1000;
			resDisplay[2] = (resultado % 1000) / 100;
			resDisplay[3] = (resultado % 100) / 10;
			resDisplay[4] = (resultado % 10);
		}
		else if (resultado != 0)
		{
			resDisplay[0] = resultado / 100;
			resDisplay[1] = (resultado % 100) / 10;
			resDisplay[2] = resultado % 10;
			resDisplay[3] = ((resultado * 100) % 10);
			resDisplay[4] = ((resultado * 10) % 10);
		}
		if (negativo == 1)
		{
			resDisplay[0] = 10;
		}

		while (igual == 1) //MULTIPLEXACION
		{
			for (int c = 0; c < 5; c++)
			{
				GPIOA->ODR = (numeros[resDisplay[c]]) | ((punto[c]) << 7) | ((posicion[c]) << 8);
				for (int j = 0; j < 5000; j++)
				{
				};
				GPIOA->ODR = 0;
			}
		}
	}
}
*/
///////*****FUNCION INTERRUPCIONES****///////
/*

extern "C"
{
	void EXTI15_10_IRQHandler(void)
	{
		teclaopri = keypad();
		num = 0;
		switch (teclaopri) //BARRIDO DE LOS VALORES DEL TECLADO
		{
		case 1:
			tecla = 1;
			break;
		case 2:
			tecla = 2;
			break;
		case 3:
			tecla = 3;
			break;
		case 4:
			tecla = 11;
			break; //SUMA
		case 5:
			tecla = 4;
			break;
		case 6:
			tecla = 5;
			break;
		case 7:
			tecla = 6;
			break;
		case 8:
			tecla = 12;
			break; //RESTA
		case 9:
			tecla = 7;
			break;
		case 10:
			tecla = 8;
			break;
		case 11:
			tecla = 9;
			break;
		case 12:
			tecla = 13;
			break; //MULTIPLICACION
		case 13:
			tecla = 15;
			break; //ON
		case 14:
			tecla = 0;
			break;
		case 15:
			tecla = 14;
			break; //IGUAL
		case 16:
			tecla = 10; //DIVISION 
			break;
		}

		GPIOD->ODR = 0XF;
		EXTI->PR = 0XFFFF;
		while ((GPIOD->IDR & 0xF000)) //VALORES
		{
			if (teclaopri != 0)
			{
				cont++;
				if (cont == 3) //LA VARIABLE CONT INDICAN SI SON CENTENAS, DECENAS O UNIDADES
				{
					cont = 1;
				}
			}
			if (tecla <= 9) //SE ASIGNAN A LA VARIABLE
			{
				if (cont == 1)
				{
					d = tecla;
					GPIOA->ODR = (numeros[d] | 0x1 << 7 | 0x2 << 8);
					for (int i = 0; i < 100000; i++)
					{
					};
					teclaopri = 0;
				}
				if (cont == 2)
				{
					u = tecla;
					GPIOA->ODR = (numeros[u] | 0x4 << 8);
					for (int i = 0; i < 100000; i++)
					{
					};
					teclaopri = 0;
				}
				if (operacion == 0) //DIFERENCIA EL VALOR DE LOS OPERANDOS
				{
					a = (d * 10 + u);
				}
				else
				{
					b = (d * 10 + u);
				}
			}
			if (tecla >= 10) //OPERACION
			{
				if (tecla == 10)
				{
					operacion = 1;
				}
				if (tecla == 11)
				{
					operacion = 2;
				}
				if (tecla == 12)
				{
					operacion = 3;
				}
				if (tecla == 13)
				{
					operacion = 4;
				}
				if (tecla == 14)
				{
					igual = 1;
				}
				if (tecla == 15)//reset
				{
          for(int i=0; i<5; i++){resDisplay[i] = 0;}					
																						  
          teclaopri=0, u = 0, d = 0, cont = 0, operacion = 0, tecla = 0, igual = 0, a = 0, b = 0, ta = 0, tb = 0, negativo = 0, resultado = 0, aux_a = 0, aux_b = 0;
				}
				d = 0, u = 0, cont = 0;
			}
		}
	}
	void EXTI9_5_IRQHandler(void) //FUNCIONES DE SEN COS Y TAN
	{
		while ((GPIOC->IDR & 0x20) == 0X20) //PIN 5
		{
			operacion = 5; // SEN
			d = 0, u = 0, cont = 0;
		}
		while ((GPIOC->IDR & 0x40) == 0X40) //PIN 6
		{
			operacion = 6; // COS
			d = 0, u = 0, cont = 0;
		}
		while ((GPIOC->IDR & 0x80) == 0X80) //PIN 7
		{
			operacion = 7; //  TAN
			d = 0, u = 0, cont = 0;
		}
	}
}

*/




		//OPERACIONES
//		switch (operacion)
//		{
//			case 1:
//				resultado = x + y;
//				break;
//			case 2:	
//				if(x == y){
//					resultado = 0;
//				}
//				if(y > x){
//					negativo = 1; resultado = y-x;
//				}
//				if(y < x){
//					resultado = x-y;
//				}  
//				break;
//			case 3:
//					resultado = x * y;
//				break;
//		}
//		desEnteros(resultado);
//		
//		if(igual==1){
//			comando_lcd(linea2 + 8);

//			for (int e = 0; e < 5; e++){
//			dato_lcd(display[resLCD[e]]);}
//		}		
/*
	}
}*/

/*

contador al boton 
se lee el cont desde matlab
cuando llegue al numero q queremos se enciende led y reset

*/



/*

#include "stm32f7xx.h"
#include "stdio.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

////////////////////CONTROL VARIABLES DE LCD////////////////////
char clear = 0x01;		 //Limpiar pantalla
char home = 0x02;		 //Return
char mode_set1 = 0x06;	 //Incremento del cursor y modo normal
char mode_set2 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato
char disp_on = 0x0E;	 //Display ON, cursor ON, parpadeo
char disp_off = 0x08;	 //Display OFF, cursor OFF, no parpadeo
char disp_shift = 0x1C;	 //Desplaza el display -- a la derecha
char disp_shift1 = 0x18; //Desplaza el display -- a la izquierda
char disp_shift2 = 0x14; //Mueve el cursor -- a la derecha
char disp_shift3 = 0x10; //Mueve el cursor -- a la izquierda
char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10
char pos_LCD = 0x0;
char w_linea1 = (0x80 + pos_LCD); //Posici?n cero de la primera fila
char w_linea2 = (0xC0 + pos_LCD); //Posici?n cero de la segunda fila
char centrar = 0X30;
char cgram = 0X40;
char ddram1 = 0X80;
char ddram2 = 0XC0;

int j = 0, i = 0;
int time = 1000;

////////////////////CONTROL VARIABLES PROGRAMA////////////////////
char numeros[] = {0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39}; //NUMEROS ASCII-HEXA
int contador = 0;															   // CONTADOR PARA EL PULSADOR EXTERNO
int tiempo = 0;																   // CONTADOR USANDO SYSTIC
int cambio = 0;
int resDisplay[4] = {0, 0, 0, 0}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD



//TXD -> C11 AMARILLO
//RXD -> C10 NARANJA
char datos[4] = {0};
char numero[4] = {0};
int Rx, valor;
char dato;
char envio1[] = {"Conteo= \n\r-"};
char envio2[] = {'1', '2', '3', '4', '5', '6', '7'};
char envio3[] = {"Hola"};

void comando_lcd(char b){
	GPIOE->ODR = b;
	GPIOE->ODR &=~(1UL<<8); //RS=0
	GPIOE->ODR |= (1UL<<9); //Enable=1
	for(j=0; j<time; j++);
	GPIOE->ODR &=~(1UL<<9); //Enable=0
}

void dato_lcd(char c){
	GPIOE->ODR = c;
	GPIOE->ODR |= (1UL<<8); //RS=1
	GPIOE->ODR |= (1UL<<9); //Enable=1
	for(j=0; j<time; j++);
	GPIOE->ODR &=~(1UL<<9); //Enable=0
}

void send1(){
		UART4 -> TDR = contador;
		while ((UART4 -> ISR &= 0X80) == 0);
}

void descomponer(int resultado)
{ //SE DESCOMPONE EL NUMERO
	int num, aux;
	num = resultado;

	aux = num / 100; // EN CENTENAS
	num = num % 100;
	resDisplay[2] = aux; //ALMACENAMOS EL NUMERO RESPECTIVO

	aux = num / 10; // EN DECENAS
	num = num % 10;
	resDisplay[1] = aux; //ALMACENAMOS EL NUMERO RESPECTIVO

	aux = num / 1; // EN UNIDADES
	num = num % 1;
	resDisplay[0] = aux; //ALMACENAMOS EL NUMERO RESPECTIVO
}

int main (void) {
	RCC -> AHB1ENR |= 0X16;
	RCC -> APB1ENR |= 0X80000;
	RCC -> APB2ENR |= 0X4000;
	
	GPIOE -> MODER = 0X555555; //LCD
	GPIOE -> OTYPER = 0X0;
	GPIOE -> OSPEEDR = 0X555555;
	GPIOE -> PUPDR = 0X555555;
	
	GPIOB -> MODER |= 0X10004001;
	GPIOB -> OTYPER |= 0X10004001;
	GPIOB -> OSPEEDR |= 0X10004001;
	GPIOB -> PUPDR |= 0X10004001;
	
	GPIOC -> MODER |= 0XA00000;
	GPIOC -> AFR[1] |= 0X8800;
	UART4 -> CR1 |= 0X2D;
	UART4 -> BRR |= 0X683;
	NVIC_EnableIRQ(UART4_IRQn);
	
	SYSCFG -> EXTICR[0] = 0X2; //PINES 0 PUERTO C
	EXTI -> IMR = 0X1; // PINES 0 EXTI
	EXTI -> RTSR = 0X1; //FLANCO DE SUBIDA
	NVIC_EnableIRQ(EXTI0_IRQn);
	
	comando_lcd(clear);
	comando_lcd(home);
	comando_lcd(set);
	comando_lcd(disp_on);
	comando_lcd(mode_set1);
	
	while(1){
		
		send1();

    
		dato_lcd(numeros[resDisplay[2]]); 
		dato_lcd(numeros[resDisplay[1]]);
		dato_lcd(numeros[resDisplay[0]]);
		
		for (j = 0; j < 1000; j++){};
			comando_lcd(clear);
	}
}

extern "C"{	
	void UART4_IRQHandler(void){ // INTERRUPCION POR DATO RECIBIDO
		if(UART4 -> ISR &= 0X20){ // EVALUAR SI LA BANDERA RXNE ESTA ACTIVA
			//dato = UART4 -> RDR;
		}
	}
	
	void EXTI0_IRQHandler(void){
		EXTI -> PR = 0X1;
		for (j = 0; j < 1000; j++){};
				contador++;
				descomponer(contador);
	}
}

*/

//#include "stm32f4xx.h"
//#include <stdio.h>
//#include <math.h>
//#define MAX 15
//#define LENGHT 5
//#define pi 3.14159265358979

//////////////////////CONTROL VARIABLES DE LCD////////////////////
//char clear = 0x01;		 //Limpiar pantalla
//char home = 0x02;		 //Return
//char modo = 0x6;	 //Incremento del cursor y modo normal
//char disp_on = 0xE;	 //Display ON, cursor ON, no parpadeo
//char cursorD = 0x14; //Mueve el cursor -- a la derecha
//char cursorI = 0x10; //Mueve el cursor -- a la izquierda
//char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10


//char mode_set2 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato

//char pos_LCD;
//char linea1 = (128 + pos_LCD); //Posici?n cero de la primera fila
//char linea2 = (192 + pos_LCD); //Posici?n cero de la segunda fila

//int time = 1000;
//char frase_error[10]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};
//char limpiar [15] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//char const display[15] = {0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F, 0X2E}; //NUMEROS ASCII-HEXA
////                    			0     1     2     3     4     5     6     7     8     9    SUMA  RESTA MULT  DIVI   DOT     

//////////////////////CONTROL VARIABLES PROGRAMA////////////////////

////int const numeros[MAX] = {0x40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X2, 0X78, 0X0, 0X10, 0X8, 0X3, 0X46, 0X21, 0X6, 0XE};
//int resLCDE[4] = {0, 0, 0, 0}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD
//int numdis[5] = {0, 0, 0, 0, 0};
//int resLCDD[6] = {0, 0, 0, 0, 0, 0};

//int i=0, j=0, filas, columna, numero, posicion, operacion, conteo, x, y;
//int decenas, unidades, resultado, igual, reset, negativo, error;

//void desEnteros(int resultado){ // DESCOMPONER ENTEROS
//	resLCDE[0] = resultado / 1000;	
//	resLCDE[1] = (resultado % 1000) / 100;
//	resLCDE[2] = (resultado % 100) / 10;
//	resLCDE[3] = (resultado % 10);	
//	
//	if(negativo == 1){
//		resLCDE[0] = 11;
//		negativo = 0;
//	}
//}

//void desDecimales(int resultado){
//	resLCDD[0] = resultado / 10000;
//	resLCDD[1] = resultado / 1000;	
//	resLCDD[2] = (resultado % 1000) / 100;
//	resLCDD[3] = 14;
//	resLCDD[4] = (resultado % 100) / 10;
//	resLCDD[5] = (resultado % 10);	
//	
//	if(negativo == 1){
//		resLCDD[0] = 11;
//		negativo = 0;
//	}
//}

//extern "C"{
//	void SysTick_Handler(void){
//		//BARRIDO FILAS
//		filas++;
//		if(filas > 3){
//			filas = 0;
//		}		
//	}
//	
//	void EXTI15_10_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0XF000); //BANDERA
//			
//		switch(columna){
//			case 0x1000://SE PRESIONO LA COLUMNA 0.
//				if(filas == 0){numero = 1;}
//				else if(filas == 1){numero = 4;}
//				else if(filas == 2){numero = 7;} 
//				else if(filas == 3){igual = 2;} //RESET 
//			break;
//			case 0x2000:
//				if(filas == 0){numero = 2;}
//				else if(filas == 1){numero = 5;}
//				else if(filas == 2){numero = 8;} 
//				else if(filas == 3){numero = 0;}
//			break;
//			case 0X4000:
//				if(filas == 0){numero = 3;}
//				else if(filas == 1){numero = 6;}
//				else if(filas == 2){numero = 9;} 
//				else if(filas == 3){igual = 1;} //TECLA IGUAL
//			break;
//			case 0x8000:
//				if(filas == 0){numero = 11;} // TECLA A = RESTA
//				else if(filas == 1){numero = 12;} // TECLA B = MULTIPLICACION
//				else if(filas == 2){numero = 13;} // TECLA C = DIVISION
//				else if(filas == 3){numero = 10;} // TECLA D = SUMA
//			break;
//		}
//		numdis[posicion] = numero; // CADA VEZ QUE SE PRESIONE UNA TECLA EL VALOR SE INGRESA EN UN ARRAY VARIANDO LAS POSICIONES DE CENTENAS DECENAS Y UNIDADES
//		posicion++;
//		if(posicion > 4){posicion=0;}
//		
//		//OPERACIONES
//		if(numero >= 10){
//			if(numero == 10){operacion = 1;} //SUMA
//			if(numero == 11){operacion = 2;} //RESTA
//			if(numero == 12){operacion = 3;} //MULTIPLICACION
//			if(numero == 13){operacion = 4;} //DIVISION
//		}		
//		
//		//AGRUPA OPERANDOS
//		if(numero <= 9){
//			if(conteo == 1){
//				decenas = numero;
//			}
//			if (conteo == 2){
//				unidades = numero;
//			}
//			if(operacion == 0){
//				x = (decenas * 10 + unidades);
//			}else if (operacion >= 1){
//				y = (decenas * 10 + unidades);
//			}
//		}
//	}
//}

//////////////////////FUNCIONED LCD////////////////////
//void comando_lcd(char b){
//	GPIOA->ODR = b;
//	GPIOA->ODR &=~(1UL<<8); //RS=0
//	GPIOA->ODR |= (1UL<<9); //Enable=1
//	for(j=0; j<time; j++);
//	GPIOA->ODR &=~(1UL<<9); //Enable=0
//}

//void dato_lcd(char c){
//	GPIOA->ODR = c;
//	GPIOA->ODR |= (1UL<<8); //RS=1
//	GPIOA->ODR |= (1UL<<9); //Enable=1
//	for(j=0; j<time; j++);
//	GPIOA->ODR &=~(1UL<<9); //Enable=0
//}

//////////////////////FUNCION PRINCIPAL////////////////////
//int main(void) {
//	RCC -> AHB1ENR |= 0X1F;
//	RCC -> APB2ENR |= 0X4000;
//	
//	GPIOA -> MODER = 0X555555; //LCD
//	GPIOA -> OTYPER = 0X0;
//	GPIOA -> OSPEEDR = 0X555555;
//	GPIOA -> PUPDR = 0X555555;

//	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) PD12-PD15(ENTRADAS EXTI)
//	GPIOD -> OTYPER |= 0X0; 
//	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
//	GPIOD -> PUPDR |= 0XAA000055; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
//	
//	SYSCFG -> EXTICR[3] = 0X3333; //PINES 12, 13, 14, 15 PUERTO D	
//	EXTI -> IMR = 0XF000; // PINES 12-15 EXTI
//	EXTI -> RTSR = 0XF000; //FLANCO DE SUBIDA
//	NVIC_EnableIRQ(EXTI15_10_IRQn);
//	
//	SystemCoreClockUpdate();
//	SysTick_Config(SystemCoreClock / 100);
//	
//	comando_lcd(clear);
//	comando_lcd(home);
//	comando_lcd(set);
//	comando_lcd(modo);
//	comando_lcd(disp_on);
//	
//	while(1){
//		
//		//BARRIDO DE FILAS DEL TECLADO
//		switch(filas){
//			case 0:
//				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
//			break;
//			case 1:
//				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
//			break;
//			case 2:
//				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
//			break;
//			case 3:
//				GPIOD -> ODR = (1UL << 3); //1000 FILA 0 ACTIVA;
//			break;
//		}
//		
//		comando_lcd(linea1);

//		for (int e = 0; e < 5; e++){
//		dato_lcd(display[numdis[e]]);
//		}		
//		
//	}
//}

/*
#include "stm32f4xx.h"
#include <stdio.h>
#include <math.h>
#define MAX 16
#define LENGHT 5
#define pi 3.14159265358979

////////////////////CONTROL VARIABLES DE LCD////////////////////
char clear = 0x01;		 //Limpiar pantalla
char home = 0x02;		 //Return
char mode_set1 = 0x06;	 //Incremento del cursor y modo normal
char mode_set2 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato
char disp_on = 0x0E;	 //Display ON, cursor ON, parpadeo
char disp_off = 0x08;	 //Display OFF, cursor OFF, no parpadeo
char disp_shift = 0x1C;	 //Desplaza el display -- a la derecha
char disp_shift1 = 0x18; //Desplaza el display -- a la izquierda
char disp_shift2 = 0x14; //Mueve el cursor -- a la derecha
char disp_shift3 = 0x10; //Mueve el cursor -- a la izquierda
char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10
char pos_LCD = 0x0;
char w_linea1 = (0x80 + pos_LCD); //Posicion cero de la primera fila
char w_linea2 = (0xC0 + pos_LCD); //Posicion cero de la segunda fila
char centrar = 0X30;
char cgram = 0X40;
char ddram1 = 0X80;
char ddram2 = 0XC0;

int time = 1000;
char frase_error[10]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};
char limpiar [MAX] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
char const display[MAX] = {0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F, 0X2E, 0X46}; //NUMEROS ASCII-HEXA
//                    			0     1     2     3     4     5     6     7     8     9    SUMA  RESTA MULT  DIVI   DOT     F

////////////////////CONTROL VARIABLES PROGRAMA////////////////////

//int const numeros[MAX] = {0x40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X2, 0X78, 0X0, 0X10, 0X8, 0X3, 0X46, 0X21, 0X6, 0XE};
int resDisplayE[4] = {0, 0, 0, 0}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD
int numdis[LENGHT] = {0, 0, 0, 0, 0};
int resDisplayD[6] = {0, 0, 0, 0, 0, 0};

int filas, columna, numero, posicion, operacion, conteo, x, y;
int decenas, unidades, resultado, igual, reset, negativo, error;

////////////////////FUNCIONED LCD////////////////////
void comando_lcd(char b){
	GPIOE->ODR = b;
	GPIOE->ODR &=~(1UL<<8); //RS=0
	GPIOE->ODR |= (1UL<<9); //Enable=1
	for(int j=0; j<time; j++);
	GPIOE->ODR &=~(1UL<<9); //Enable=0
}

void dato_lcd(char c){
	GPIOE->ODR = c;
	GPIOE->ODR |= (1UL<<8); //RS=1
	GPIOE->ODR |= (1UL<<9); //Enable=1
	for(int q=0; q<time; q++);
	GPIOE->ODR &=~(1UL<<9); //Enable=0
}

extern "C"{
	void SysTick_Handler(void){
		//BARRIDO FILAS
		filas++;
		if(filas > 3){
			filas = 0;
		}		
	}
	
	void EXTI0_IRQHandler(void){ // CLEAR ALL
			EXTI->PR |= 0X1;
			for (int l = 0; l < 1000; l++){};
				
			filas = 0, columna = 0, numero = 0, posicion = 0, operacion = 0, conteo = 0, x = 0, y = 0;
			decenas = 0, unidades = 0, resultado = 0, igual = 0;
				
			for (int i = 0; i < LENGHT; i++){
				numdis[i] = 0;
			}
			for (int i = 0; i <= 3 ; i++){
				resDisplayE[i] = 0;
			}
			for (int i = 0; i < 7 ; i++){
				resDisplayD[i] = 0;
			}		
			
			comando_lcd(w_linea2);
			for(int d = 0; d <= MAX; d++){ 
				dato_lcd(limpiar[d]);
			}
			for(int r=0; r<100000; r++);
			
			comando_lcd(clear);
			comando_lcd(home);	
	}
	
	void EXTI1_IRQHandler(void){ 
		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
		EXTI -> PR |= 0X2; //BANDERA
		operacion = 5; // SENO;
	}
	
	void EXTI2_IRQHandler(void){ 
		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
		EXTI -> PR |= 0X4; //BANDERA
		operacion = 6; // COSENO;
	}
		
	void EXTI3_IRQHandler(void){ 
		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
		EXTI -> PR |= 0X8; //BANDERA
		operacion = 6; // TANGENTE;
	}
	
	void EXTI15_10_IRQHandler (void){
		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
		EXTI -> PR |= (0XF000); //BANDERA
			
		switch(columna){
			case 0x1000://SE PRESIONO LA COLUMNA 0.
				if(filas == 0){numero = 1;}
				else if(filas == 1){numero = 4;}
				else if(filas == 2){numero = 7;} 
				else if(filas == 3){} //TECLA ON O * = ALL CLEAR
			break;
			case 0x2000:
				if(filas == 0){numero = 2;}
				else if(filas == 1){numero = 5;}
				else if(filas == 2){numero = 8;} 
				else if(filas == 3){numero = 0;}
			break;
			case 0X4000:
				if(filas == 0){numero = 3;}
				else if(filas == 1){numero = 6;}
				else if(filas == 2){numero = 9;} 
				else if(filas == 3){igual = 1;} //TECLA IGUAL
			break;
			case 0x8000:
				if(filas == 0){numero = 11;} // TECLA A = RESTA
				else if(filas == 1){numero = 12;} // TECLA B = MULTIPLICACION
				else if(filas == 2){numero = 13;} // TECLA C = DIVISION
				else if(filas == 3){numero = 10;} // TECLA D = SUMA
			break;
		}
		conteo++;
		if(conteo == 3){conteo = 0;}
		numdis[posicion] = numero; // CADA VEZ QUE SE PRESIONE UNA TECLA EL VALOR SE INGRESA EN UN ARRAY VARIANDO LAS POSICIONES DE CENTENAS DECENAS Y UNIDADES
		posicion++;
		
//		if(posicion>4){posicion=0;}
		if(numero >= 10){
			if(numero == 10){operacion = 1;} //SUMA
			if(numero == 11){operacion = 2;} //RESTA
			if(numero == 12){operacion = 3;} //MULTIPLICACION
			if(numero == 13){operacion = 4;} //DIVISION
		}		
		
		if(numero <= 9){
			if(conteo == 1){
				decenas = numero;
			}
			if (conteo == 2){
				unidades = numero;
			}
			if(operacion == 0){
				x = (decenas * 10 + unidades);
			}else if (operacion >= 1){
				y = (decenas * 10 + unidades);
			}
		}
	}
}

void desEnteros(int resultado){ // DESCOMPONER ENTEROS
	resDisplayE[0] = resultado / 1000;	
	resDisplayE[1] = (resultado % 1000) / 100;
	resDisplayE[2] = (resultado % 100) / 10;
	resDisplayE[3] = (resultado % 10);	
	
	if(negativo == 1){
		resDisplayE[0] = 11;
		negativo = 0;
	}
}

void desDecimales(int resultado){
	resDisplayD[0] = resultado / 10000;
	resDisplayD[1] = resultado / 1000;	
	resDisplayD[2] = (resultado % 1000) / 100;
	resDisplayD[3] = 14;
	resDisplayD[4] = (resultado % 100) / 10;
	resDisplayD[5] = (resultado % 10);	
	
	if(negativo == 1){
		resDisplayD[0] = 11;
		negativo = 0;
	}
}

////////////////////FUNCION PRINCIPAL////////////////////
int main(void) {
	RCC -> AHB1ENR |= 0X58;
	RCC -> APB2ENR |= 0X4000;
	
	GPIOE -> MODER = 0X555555; //LCD
	GPIOE -> OTYPER = 0X0;
	GPIOE -> OSPEEDR = 0X555555;
	GPIOE -> PUPDR = 0X555555;

	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) PD12-PD15(ENTRADAS EXTI)
	GPIOD -> OTYPER |= 0X0; 
	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
	GPIOD -> PUPDR |= 0XAA000055; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
	
	SYSCFG -> EXTICR[3] = 0X3333; //PINES 12, 13, 14, 15 PUERTO D	
	EXTI -> IMR = 0XF00F; // PINES 12-15 EXTI
	EXTI -> RTSR = 0XF00F; //FLANCO DE SUBIDA
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	
	//BOTONES 
	SYSCFG -> EXTICR[0] = 0X6666; //PINES 0 PUERTO G
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 10);
	
	comando_lcd(clear);
	comando_lcd(home);
	comando_lcd(set);
	comando_lcd(disp_on);
	comando_lcd(mode_set1);
	
	while(1){
		//BARRIDO DE FILAS DEL TECLADO
		switch(filas){
			case 0:
				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
			break;
			case 1:
				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
			break;
			case 2:
				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
			break;
			case 3:
				GPIOD -> ODR = (1UL << 3); //1000 FILA 0 ACTIVA;
			break;
		}
		//CALCULADORA LCD//
		
		comando_lcd(w_linea1);
		for (int e = 0; e < 5; e++){
			dato_lcd(display[numdis[e]]);
		}
		for(int w=0; w<1000; w++);
		
		if(igual != 0){
			switch(operacion){
				case 1:
					resultado = x + y;
				  desEnteros(resultado);
				break;
				
				case 2:
					if(x < y) {
						negativo = 1;
						resultado = y -x;
					}
					if(x > y){
					resultado = x - y;
					}
				  desEnteros(resultado);
				break;
				
				case 3:
					resultado = x * y;
				  desEnteros(resultado);
				break;
				
				case 4:
					if(y != 0){
						resultado = (x * 100) / y;
						desDecimales(resultado);
					}else{
						error = 1;
					}
				break;
					
				case 5: //SENO
					resultado = sin((double)((x * pi) / 180)) * 100;
					if (resultado < 0){
						negativo = 1;
					}
					desDecimales(resultado);
				break;
					
				case 6: //COSENO
					resultado = cos((double)((x * pi) / 180)) * 100;
					if (resultado < 0){
						negativo = 1;
					}
					desDecimales(resultado);
				break;
					
				case 7: //TANGENTE
					if (x != 90){
						resultado = tan((double)((x * pi) / 180)) * 100; //FUNCION TANGENTE
						if (resultado < 0){
							negativo = 1;
						}
						desDecimales(resultado);
					}
				else{
					error = 1;
				}
				break;
			}
		}
		
		if (igual == 1){
			if(error == 0){
				comando_lcd(w_linea2);
				if(operacion == 1 || operacion == 2 || operacion == 3){
						for (int t = 0; t < 4; t++){
						dato_lcd(display[resDisplayE[t]]);
					}
				}else{
					for (int u = 0; u < 6; u++){
						dato_lcd(display[resDisplayD[u]]);
					}
				}
			}else{
				comando_lcd(w_linea2);
				for(int h = 0; h < 10; h++){
					dato_lcd(frase_error[h]);
				}
			}
			error = 0;
			igual = 0;			
		}
	}
}*/
//FIN

//#include "stm32f4xx.h"
//#include <stdio.h>
//#include <math.h>
//#define MAX 15
//#define LENGHT 5
//#define pi 3.14159265358979

//////////////////////CONTROL VARIABLES DE LCD////////////////////
//char clear = 0x01;		 //Limpiar pantalla
//char home = 0x02;		 //Return
//char modo = 0x6;	 //Incremento del cursor y modo normal
//char disp_on = 0xC;	 //Display ON, cursor ON, no parpadeo
//char cursorD = 0x14; //Mueve el cursor -- a la derecha
//char cursorI = 0x10; //Mueve el cursor -- a la izquierda
//char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10

//char modo1 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato

//char pos_LCD;
//char linea1 = (128 + pos_LCD); //Posici?n cero de la primera fila
//char linea2 = (192 + pos_LCD); //Posici?n cero de la segunda fila

//int time = 1000;
//char frase_error[10]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};
//char limpiar [15] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//char const display[15] = {0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F, 0X2E}; //NUMEROS ASCII-HEXA
////                    			0     1     2     3     4     5     6     7     8     9    SUMA  RESTA MULT  DIVI   DOT     

//////////////////////CONTROL VARIABLES PROGRAMA////////////////////

//////////////////////FUNCION SENOIDAL////////////////////
//char const sen1[8] = {0X0, 0X1, 0X2, 0X4, 0X4, 0X8, 0X8, 0X10};
//char const sen2[8] = {0X0, 0X10, 0X8, 0X4, 0X4, 0X2, 0X1, 0X1};
//char const sen3[8] = {0X10, 0X8, 0X8, 0X4, 0X4, 0X2, 0X1, 0X0};
//char const sen4[8] = {0X1, 0X2, 0X2, 0X4, 0X4, 0X8, 0X10, 0X0};

////int const numeros[MAX] = {0x40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X2, 0X78, 0X0, 0X10, 0X8, 0X3, 0X46, 0X21, 0X6, 0XE};
//int resLCDE[4] = {0, 0, 0, 0}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD
//int numdis[5] = {0, 0, 0, 0, 0};
//int resLCDD[6] = {0, 0, 0, 0, 0, 0};

//int i=0, j=0, filas, columna, numero, posicion, operacion, conteo, x, y;
//int decenas, unidades, resultado, igual, reset, negativo, error;

//////////////////////FUNCIONED LCD////////////////////
//void comando_lcd(char b){
//	GPIOA->ODR = b;
//	GPIOA->ODR &=~(1UL<<8); //RS=0
//	GPIOA->ODR |= (1UL<<9); //Enable=1
//	for(j=0; j<time; j++);
//	GPIOA->ODR &=~(1UL<<9); //Enable=0
//}

//void dato_lcd(char c){
//	GPIOA->ODR = c;
//	GPIOA->ODR |= (1UL<<8); //RS=1
//	GPIOA->ODR |= (1UL<<9); //Enable=1
//	for(j=0; j<time; j++);
//	GPIOA->ODR &=~(1UL<<9); //Enable=0
//}

//extern "C"{
//	void SysTick_Handler(void){
//		//BARRIDO FILAS
//		filas++;
//		if(filas > 3){
//			filas = 0;
//		}		
//	}
//	
//	void EXTI0_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0X1); //BANDERA
//	
//		comando_lcd(cursorD);
//	
//	}
//	void EXTI1_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0X2); //BANDERA
//		
//		comando_lcd(cursorI);
//	}
//	void EXTI2_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0X4); //BANDERA
//			
//		linea1++;
//	}
//		
//	
//	void EXTI15_10_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0XF000); //BANDERA
//			
//		switch(columna){
//			case 0x1000://SE PRESIONO LA COLUMNA 0.
//				if(filas == 0){numero = 1;}
//				else if(filas == 1){numero = 4;}
//				else if(filas == 2){numero = 7;} 
//				else if(filas == 3){igual = 2;} //RESET 
//			break;
//			case 0x2000:
//				if(filas == 0){numero = 2;}
//				else if(filas == 1){numero = 5;}
//				else if(filas == 2){numero = 8;} 
//				else if(filas == 3){numero = 0;}
//			break;
//			case 0X4000:
//				if(filas == 0){numero = 3;}
//				else if(filas == 1){numero = 6;}
//				else if(filas == 2){numero = 9;} 
//				else if(filas == 3){igual = 1;} //TECLA IGUAL
//			break;
//			case 0x8000:
//				if(filas == 0){numero = 11;} // TECLA A = RESTA
//				else if(filas == 1){numero = 12;} // TECLA B = MULTIPLICACION
//				else if(filas == 2){numero = 13;} // TECLA C = DIVISION
//				else if(filas == 3){numero = 10;} // TECLA D = SUMA
//			break;
//		}
//		numdis[posicion] = numero; // CADA VEZ QUE SE PRESIONE UNA TECLA EL VALOR SE INGRESA EN UN ARRAY VARIANDO LAS POSICIONES DE CENTENAS DECENAS Y UNIDADES
//		posicion++;
//		if(posicion > 4){posicion=0;}
//	}
//}

//////////////////////FUNCION PRINCIPAL////////////////////
//int main(void) {
//	RCC -> AHB1ENR |= 0X1F;
//	RCC -> APB2ENR |= 0X4000;
//	
//	GPIOA -> MODER = 0X555555; //LCD
//	GPIOA -> OTYPER = 0X0;
//	GPIOA -> OSPEEDR = 0X555555;
//	GPIOA -> PUPDR = 0X555555;

//	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) PD12-PD15(ENTRADAS EXTI)
//	GPIOD -> OTYPER |= 0X0; 
//	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
//	GPIOD -> PUPDR |= 0XAA000055; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
//	
//	SYSCFG -> EXTICR[3] = 0X3333; //PINES 12, 13, 14, 15 PUERTO D	
//	SYSCFG -> EXTICR[0] = 0X222; //PINES 12, 13, 14, 15 PUERTO D	
//	EXTI -> IMR = 0XF007; // PINES 12-15 EXTI
//	EXTI -> RTSR = 0XF007; //FLANCO DE SUBIDA
//	NVIC_EnableIRQ(EXTI15_10_IRQn);
//	NVIC_EnableIRQ(EXTI0_IRQn);
//	NVIC_EnableIRQ(EXTI1_IRQn);
//	NVIC_EnableIRQ(EXTI2_IRQn);

//	SystemCoreClockUpdate();
//	SysTick_Config(SystemCoreClock / 100);
//	
//	comando_lcd(0x40);
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen1[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen2[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen3[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen4[i]);
//	}
//	
//	comando_lcd(clear);
//	comando_lcd(home);
//	comando_lcd(set);
//	comando_lcd(modo);
//	comando_lcd(disp_on);
//	
//	while(1){
//		
//		//BARRIDO DE FILAS DEL TECLADO
//		switch(filas){
//			case 0:
//				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
//			break;
//			case 1:
//				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
//			break;
//			case 2:
//				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
//			break;
//			case 3:
//				GPIOD -> ODR = (1UL << 3); //1000 FILA 0 ACTIVA;
//			break;
//		}
//		
//		for(int j = 0; j < 16; j++){
//			comando_lcd(linea1 + j);
//			dato_lcd(0x00);
//			comando_lcd(linea1 + j + 1);
//			dato_lcd(0x01);
//			comando_lcd(linea2 + j + 2);
//			dato_lcd(0x02);
//			comando_lcd(linea2 + j + 3);
//			dato_lcd(0x03);
//		  
//			for(int tiempo = 0; tiempo < 100000; tiempo++){};
//		}
////		comando_lcd(linea1);

////		for (int e = 0; e < 5; e++){
////		dato_lcd(display[numdis[e]]);
////		}		
//	}
//}


//#include "stm32f7xx.h"
//#include <stdio.h>
//#include <math.h>
//#define MAX 16
//#define LENGHT 5
//#define pi 3.14159265358979

//////////////////////CONTROL VARIABLES DE LCD////////////////////
//char clear = 0x01;		 //Limpiar pantalla
//char home = 0x02;		 //Return
//char mode_set1 = 0x06;	 //Incremento del cursor y modo normal
//char mode_set2 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato
//char disp_on = 0x0E;	 //Display ON, cursor ON, parpadeo
//char disp_off = 0x08;	 //Display OFF, cursor OFF, no parpadeo
//char disp_shift = 0x1C;	 //Desplaza el display -- a la derecha
//char disp_shift1 = 0x18; //Desplaza el display -- a la izquierda
//char disp_shift2 = 0x14; //Mueve el cursor -- a la derecha
//char disp_shift3 = 0x10; //Mueve el cursor -- a la izquierda
//char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10
//char pos_LCD = 0x0;
//char w_linea1 = (0x80 + pos_LCD); //Posicion cero de la primera fila
//char w_linea2 = (0xC0 + pos_LCD); //Posicion cero de la segunda fila
//char centrar = 0X30;
//char cgram = 0X40;
//char ddram1 = 0X80;
//char ddram2 = 0XC0;

//int time = 1000;
//char frase_error[10]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};
//char limpiar [17] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//char const display[17] = {' ' ,0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F, 0X2E, 0X46}; //NUMEROS ASCII-HEXA
////                    			0     1     2     3     4     5     6     7     8     9    SUMA  RESTA MULT  DIVI   DOT     F
//////////////////////FUNCION SENOIDAL////////////////////
//char sen1[8] = {0X0, 0X1, 0X2, 0X4, 0X4, 0X8, 0X8, 0X10};
//char sen2[8] = {0X0, 0X10, 0X8, 0X4, 0X4, 0X2, 0X1, 0X1};
//char sen3[8] = {0X10, 0X8, 0X8, 0X4, 0X4, 0X2, 0X1, 0X0};
//char sen4[8] = {0X1, 0X2, 0X2, 0X4, 0X4, 0X8, 0X10, 0X0};

//////////////////////CONTROL VARIABLES PROGRAMA////////////////////

////int const numeros[MAX] = {0x40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X2, 0X78, 0X0, 0X10, 0X8, 0X3, 0X46, 0X21, 0X6, 0XE};
//char resDisplayE[4] = {' ', ' ', ' ', ' '}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD
//int numdis[LENGHT] = {0, 0, 0, 0};
//char resDisplayD[6] = {' ', ' ', ' ', ' ', ' ', ' '};

//int filas, columna, numero, posicion, operacion = 0, conteo, x, y, funcionSeno;
//int decenas, unidades, resultado, igual, reset, negativo, error = 0, aux=0;

//////////////////////FUNCIONED LCD////////////////////
//void comando_lcd(char b){
//	GPIOE -> ODR &= 0XFF00;
//	GPIOE -> ODR |= b;
//	GPIOE -> ODR &=~(1UL<<8); //RS=0
//	GPIOE -> ODR |= (1UL<<9); //Enable=1
//	for(int j=0; j<time; j++);
//	GPIOE -> ODR &=~(1UL<<9); //Enable=0
//}

//void dato_lcd(char c){
//	GPIOE -> ODR &= 0XFF00;
//	GPIOE -> ODR |= c;
//	GPIOE -> ODR |= (1UL<<8); //RS=1
//	GPIOE -> ODR |= (1UL<<9); //Enable=1
//	for(int q=0; q<time; q++);
//	GPIOE -> ODR &=~(1UL<<9); //Enable=0
//}

//void limpiar_lcd(int inicio){
//		comando_lcd(w_linea1);
//		for(int d = inicio; d <= 17; d++){ 
//			dato_lcd(limpiar[d]);
//		}
//		for(int r=0; r<100000; r++);
//		
//		comando_lcd(w_linea2);
//		for(int d = 0; d <= 17; d++){ 
//			dato_lcd(limpiar[d]);
//		}
//		for(int r=0; r<100000; r++);
//		
//		comando_lcd(clear);
//		comando_lcd(home);
//	}

//extern "C"{
//	void SysTick_Handler(void){
//		//BARRIDO FILAS
//		filas++;
//		if(filas > 3){
//			filas = 0;
//		}		
//	}
//	
//	void EXTI0_IRQHandler(void){ // CLEAR ALL
//			EXTI->PR |= 0X1;
//			for (int l = 0; l < 1000; l++){};
//				
//			filas = 0, columna = 0, numero = 0, posicion = 0, operacion = 0, conteo = 0, x = 0, y = 0;
//			decenas = 0, unidades = 0, resultado = 0, igual = 0, funcionSeno = 0;
//				
//			for (int i = 0; i < LENGHT; i++){
//				numdis[i] = 0;
//			}
//			for (int i = 0; i <= 3 ; i++){
//				resDisplayE[i] = 0;
//			}
//			for (int i = 0; i < 7 ; i++){
//				resDisplayD[i] = 0;
//			}			
//			comando_lcd(disp_on);
//			limpiar_lcd(1);
//	}
//	
//	void EXTI1_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X2; //BANDERA
//		operacion = 5; // SENO;
//		y = 0, conteo = 0;
//	}
//	
//	void EXTI2_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X4; //BANDERA
//		operacion = 6; // COSENO;
//		y = 0, conteo = 0;
//	}
//		
//	void EXTI3_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X8; //BANDERA
//		operacion = 7; // TANGENTE;
//		y = 0, conteo = 0, numero = 0;
//	}
//	
//	void EXTI4_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X10; //BANDERA
//		funcionSeno = 1;
//		limpiar_lcd(0);
//		comando_lcd(0XC);
//	}
//	
//	void EXTI15_10_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0XF000); //BANDERA
//			
//		switch(columna){
//			case 0x1000://SE PRESIONO LA COLUMNA 0.
//				if(filas == 0){numero = 1;}
//				else if(filas == 1){numero = 4;}
//				else if(filas == 2){numero = 7;} 
//				else if(filas == 3){} //TECLA ON O * = ALL CLEAR
//			break;
//			case 0x2000:
//				if(filas == 0){numero = 2;}
//				else if(filas == 1){numero = 5;}
//				else if(filas == 2){numero = 8;} 
//				else if(filas == 3){numero = 0;}
//			break;
//			case 0X4000:
//				if(filas == 0){numero = 3;}
//				else if(filas == 1){numero = 6;}
//				else if(filas == 2){numero = 9;} 
//				else if(filas == 3){igual = 1;} //TECLA IGUAL
//			break;
//			case 0x8000:
//				if(filas == 0){numero = 11;} // TECLA A = RESTA
//				else if(filas == 1){numero = 12;} // TECLA B = MULTIPLICACION
//				else if(filas == 2){numero = 13;} // TECLA C = DIVISION
//				else if(filas == 3){numero = 10;} // TECLA D = SUMA
//			break;
//		}
//		conteo++;
//		if(conteo == 3){conteo = 0;}
//		numdis[posicion] = numero + 1; // CADA VEZ QUE SE PRESIONE UNA TECLA EL VALOR SE INGRESA EN UN ARRAY VARIANDO LAS POSICIONES DE CENTENAS DECENAS Y UNIDADES
//		posicion++;
//		
////		if(posicion>4){posicion=0;}
//		if(numero >= 10){
//			if(numero == 10){operacion = 1;} //SUMA
//			if(numero == 11){operacion = 2;} //RESTA
//			if(numero == 12){operacion = 3;} //MULTIPLICACION
//			if(numero == 13){operacion = 4;} //DIVISION
//		}		
//		
//		if(numero <= 9){
//			
//			if(conteo == 1){
//				decenas = numero;
//			}
//			if (conteo == 2){
//				unidades = numero;
//			}
//			if(operacion == 0){
//				x = (decenas * 10 + unidades);
//			}else if (operacion == 1 || operacion == 2 || operacion == 3 || operacion == 4){
//				y = (decenas * 10 + unidades);
//			}
//		}
//	}
//}

//void desEnteros(int resultado){ // DESCOMPONER ENTEROS
//		resDisplayE[0] = resultado / 1000;	
//		resDisplayE[1] = (resultado % 1000) / 100;
//		resDisplayE[2] = (resultado % 100) / 10;
//		resDisplayE[3] = (resultado % 10);
//	}
//}

//void desDecimales(int resultado){
//	resDisplayD[0] = resultado / 10000;
//	resDisplayD[1] = resultado / 1000;	
//	resDisplayD[2] = (resultado % 1000) / 100;
//	resDisplayD[3] = 14;
//	resDisplayD[4] = (resultado % 100) / 10;
//	resDisplayD[5] = (resultado % 10);	
//	
//	if(negativo == 1){
//		resDisplayD[0] = 11;
//		negativo = 0;
//	}
//}

//////////////////////FUNCION PRINCIPAL////////////////////
//int main(void) {
//	RCC -> AHB1ENR |= 0X58;
//	RCC -> APB2ENR |= 0X4000;
//	
//	GPIOE -> MODER = 0X555555; //LCD
//	GPIOE -> OTYPER = 0X0;
//	GPIOE -> OSPEEDR = 0X555555;
//	GPIOE -> PUPDR = 0X555555;

//	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) PD12-PD15(ENTRADAS EXTI)
//	GPIOD -> OTYPER |= 0X0; 
//	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
//	GPIOD -> PUPDR |= 0XAA000055; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
//	
//	SYSCFG -> EXTICR[3] = 0X3333; //PINES 12, 13, 14, 15 PUERTO D	
//	EXTI -> IMR = 0XF01F; // PINES 12-15 EXTI
//	EXTI -> RTSR = 0XF01F; //FLANCO DE SUBIDA
//	NVIC_EnableIRQ(EXTI15_10_IRQn);
//	
//	//BOTONES 
//	SYSCFG -> EXTICR[0] = 0X6666; //PINES 0, 1, 2, 3 PUERTO G
//	NVIC_EnableIRQ(EXTI0_IRQn);
//	NVIC_EnableIRQ(EXTI1_IRQn);
//	NVIC_EnableIRQ(EXTI2_IRQn);
//	NVIC_EnableIRQ(EXTI3_IRQn);
//	
//	SYSCFG -> EXTICR[1] = 0X6;
//	NVIC_EnableIRQ(EXTI4_IRQn);
//	
//	SystemCoreClockUpdate();
//	SysTick_Config(SystemCoreClock / 10);
//	
//	comando_lcd(cgram);
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen1[i]);
//		dato_lcd(sen2[i]);
//		dato_lcd(sen3[i]);
//		dato_lcd(sen4[i]);
//	}
//	
//	comando_lcd(clear);
//	comando_lcd(home);
//	comando_lcd(set);
//	comando_lcd(disp_on);
//	comando_lcd(mode_set1);
//	
//	while(1){
//		if(funcionSeno == 1){
//			for(int j = 0; j < 16; j=j+4){
//				comando_lcd(ddram1+j);
//				dato_lcd(0x00);
//				comando_lcd(ddram1+j+1);
//				dato_lcd(0x01);
//				comando_lcd(ddram2+j+2);
//				dato_lcd(0x02);
//				comando_lcd(ddram2+j+3);
//				dato_lcd(0x03);
//				for(int tiempo = 0; tiempo < 100000; tiempo++){};
//			}
//		}else{
//		
//		//BARRIDO DE FILAS DEL TECLADO
//		switch(filas){
//			case 0:
//				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
//			break;
//			case 1:
//				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
//			break;
//			case 2:
//				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
//			break;
//			case 3:
//				GPIOD -> ODR = (1UL << 3); //1000 FILA 0 ACTIVA;
//			break;
//		}
//		//CALCULADORA LCD//
//		
//		comando_lcd(w_linea1);
//		for (int e = 0; e < 5; e++){
//			dato_lcd(display[numdis[e]]);
//		}
//		for(int w=0; w<1000; w++);
//		
//		if(igual != 0){
//			switch(operacion){
//				case 1:
//					resultado = x + y;
//				  desEnteros(resultado);
//				break;
//				
//				case 2:
//					if(x < y) {
//						negativo = 1;
//						resultado = y -x;
//					}
//					if(x > y){
//					resultado = x - y;
//					}
//				  desEnteros(resultado);
//				break;
//				
//				case 3:
//					resultado = x * y;
//				  desEnteros(resultado);
//				break;
//				
//				case 4:
//					if(y != 0){
//						resultado = (x * 100) / y;
//						desDecimales(resultado);
//					}else{
//						error = 1;
//					}
//				break;
//					
//				case 5: //SENO
//					resultado = sin((double)((x * pi) / 180)) * 100;
//					if (resultado < 0){
//						negativo = 1;
//						resultado = resultado * -1;
//					}
//					desDecimales(resultado);
//				break;
//					
//				case 6: //COSENO
//					resultado = cos((double)((x * pi) / 180)) * 100;
//					if (resultado < 0){
//						negativo = 1;
//						resultado = resultado * -1;
//					}
//					desDecimales(resultado);
//				break;
//					
//				case 7: //TANGENTE
//					if (x != 90){
//						resultado = tan((double)((x * pi) / 180)) * 100; //FUNCION TANGENTE
//						if (resultado < 0){
//							negativo = 1;
//							resultado = resultado * -1;
//						}
//						desDecimales(resultado);
//					}
//				else{
//					error = 1;
//				}
//				break;
//			}
//		}
//		
//		if (igual == 1){
//			if(error == 0){
//				if(operacion == 1 || operacion == 2 || operacion == 3){
//						comando_lcd(w_linea2 + 12);
//					
//					if(aux==1){
//						  dato_lcd(display[0]);dato_lcd(display[0]);
//							dato_lcd(display[resDisplayE[2]]);
//						  dato_lcd(display[resDisplayE[3]]);
//						}
//					
//					}
//					else if(aux==2){}
//					else if(aux==3){}
//					else if(aux==4){}
//						
//					
//					
//					
//					
//					
//					for (int t = 0; t < 4; t++){
//						
//						dato_lcd(resDisplayE[t]);
//					}
//				}else{
//					comando_lcd(w_linea2 + 10);
//					for (int u = 0; u < 6; u++){
//						dato_lcd(display[resDisplayD[u] + 1]);
//					}
//				}
//			}else{
//				comando_lcd(w_linea2 + 6);
//				for(int h = 0; h < 10; h++){
//					dato_lcd(frase_error[h]);
//				}
//			}		
//			igual = 0;
//			error = 0;
//		}
//	}
//	}
//}
////FIN

//#include "stm32f7xx.h"
//#include <stdio.h>
//#include <math.h>
//#define MAX 16
//#define LENGHT 5
//#define pi 3.14159265358979

//////////////////////CONTROL VARIABLES DE LCD////////////////////
//char clear = 0x01;		 //Limpiar pantalla
//char home = 0x02;		 //Return
//char mode_set1 = 0x06;	 //Incremento del cursor y modo normal
//char mode_set2 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato
//char disp_on = 0x0E;	 //Display ON, cursor ON, parpadeo
//char disp_off = 0x08;	 //Display OFF, cursor OFF, no parpadeo
//char disp_shift = 0x1C;	 //Desplaza el display -- a la derecha
//char disp_shift1 = 0x18; //Desplaza el display -- a la izquierda
//char disp_shift2 = 0x14; //Mueve el cursor -- a la derecha
//char disp_shift3 = 0x10; //Mueve el cursor -- a la izquierda
//char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10
//char pos_LCD = 0x0;
//char w_linea1 = (0x80 + pos_LCD); //Posicion cero de la primera fila
//char w_linea2 = (0xC0 + pos_LCD); //Posicion cero de la segunda fila
//char centrar = 0X30;
//char cgram = 0X40;
//char ddram1 = 0X80;
//char ddram2 = 0XC0;

//int time = 1000;
//char frase_error[10]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};
//char limpiar [17] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//char const display[17] = {' ' ,0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F, 0X2E, 0X46}; //NUMEROS ASCII-HEXA
////                    	       	0     1     2     3     4     5     6     7     8     9    SUMA  RESTA MULT  DIVI   DOT     F
//////////////////////FUNCION SENOIDAL////////////////////
//char sen1[8] = {0X0, 0X1, 0X2, 0X4, 0X4, 0X8, 0X8, 0X10};
//char sen2[8] = {0X0, 0X10, 0X8, 0X4, 0X4, 0X2, 0X1, 0X1};
//char sen3[8] = {0X10, 0X8, 0X8, 0X4, 0X4, 0X2, 0X1, 0X0};
//char sen4[8] = {0X1, 0X2, 0X2, 0X4, 0X4, 0X8, 0X10, 0X0};

//////////////////////CONTROL VARIABLES PROGRAMA////////////////////

////int const numeros[MAX] = {0x40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X2, 0X78, 0X0, 0X10, 0X8, 0X3, 0X46, 0X21, 0X6, 0XE};
//char resDisplayE[4] = {0, 0, 0, 0}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD
//int numdis[LENGHT] = {0, 0, 0, 0};
//char resDisplayD[6] = {0, 0, 0, 0, 0, 0};

//int filas, columna, numero, posicion, operacion = 0, conteo, x, y, funcionSeno;
//int decenas, unidades, resultado, igual, reset, negativo, error = 0, aux;

//////////////////////FUNCIONED LCD////////////////////
//void comando_lcd(char b){
//	GPIOE -> ODR &= 0XFF00;
//	GPIOE -> ODR |= b;
//	GPIOE -> ODR &=~(1UL<<8); //RS=0
//	GPIOE -> ODR |= (1UL<<9); //Enable=1
//	for(int j=0; j<time; j++);
//	GPIOE -> ODR &=~(1UL<<9); //Enable=0
//}

//void dato_lcd(char c){
//	GPIOE -> ODR &= 0XFF00;
//	GPIOE -> ODR |= c;
//	GPIOE -> ODR |= (1UL<<8); //RS=1
//	GPIOE -> ODR |= (1UL<<9); //Enable=1
//	for(int q=0; q<time; q++);
//	GPIOE -> ODR &=~(1UL<<9); //Enable=0
//}

//void limpiar_lcd(int inicio){
//		comando_lcd(w_linea1);
//		for(int d = inicio; d <= 17; d++){ 
//			dato_lcd(limpiar[d]);
//		}
//		for(int r=0; r<100000; r++);
//		
//		comando_lcd(w_linea2);
//		for(int d = 0; d <= 17; d++){ 
//			dato_lcd(limpiar[d]);
//		}
//		for(int r=0; r<100000; r++);
//		
//		comando_lcd(clear);
//		comando_lcd(home);
//	}

//extern "C"{
//	void SysTick_Handler(void){
//		//BARRIDO FILAS
//		filas++;
//		if(filas > 3){
//			filas = 0;
//		}		
//	}
//	
//	void EXTI0_IRQHandler(void){ // CLEAR ALL
//			EXTI->PR |= 0X1;
//			for (int l = 0; l < 1000; l++){};
//				
//			filas = 0, columna = 0, numero = 0, posicion = 0, operacion = 0, conteo = 0, x = 0, y = 0;
//			decenas = 0, unidades = 0, resultado = 0, igual = 0, funcionSeno = 0;
//				
//			for (int i = 0; i < LENGHT; i++){
//				numdis[i] = 0;
//			}
//			for (int i = 0; i <= 3 ; i++){
//				resDisplayE[i] = 0;
//			}
//			for (int i = 0; i < 7 ; i++){
//				resDisplayD[i] = 0;
//			}			
//			comando_lcd(disp_on);
//			limpiar_lcd(1);
//	}
//	
//	void EXTI1_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X2; //BANDERA
//		operacion = 5; // SENO;
//		y = 0, conteo = 0;
//	}
//	
//	void EXTI2_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X4; //BANDERA
//		operacion = 6; // COSENO;
//		y = 0, conteo = 0;
//	}
//		
//	void EXTI3_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X8; //BANDERA
//		operacion = 7; // TANGENTE;
//		y = 0, conteo = 0;
//	}
//	
//	void EXTI4_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X10; //BANDERA
//		funcionSeno = 1;
//		limpiar_lcd(0);
//		comando_lcd(0XC);
//	}
//	
//	void EXTI15_10_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0XF000); //BANDERA
//			
//		switch(columna){
//			case 0x1000://SE PRESIONO LA COLUMNA 0.
//				if(filas == 0){numero = 1;}
//				else if(filas == 1){numero = 4;}
//				else if(filas == 2){numero = 7;} 
//				else if(filas == 3){} //TECLA ON O * = ALL CLEAR
//			break;
//			case 0x2000:
//				if(filas == 0){numero = 2;}
//				else if(filas == 1){numero = 5;}
//				else if(filas == 2){numero = 8;} 
//				else if(filas == 3){numero = 0;}
//			break;
//			case 0X4000:
//				if(filas == 0){numero = 3;}
//				else if(filas == 1){numero = 6;}
//				else if(filas == 2){numero = 9;} 
//				else if(filas == 3){igual = 1;} //TECLA IGUAL
//			break;
//			case 0x8000:
//				if(filas == 0){numero = 11;} // TECLA A = RESTA
//				else if(filas == 1){numero = 12;} // TECLA B = MULTIPLICACION
//				else if(filas == 2){numero = 13;} // TECLA C = DIVISION
//				else if(filas == 3){numero = 10;} // TECLA D = SUMA
//			break;
//		}
//		conteo++;
//		if(conteo == 3){conteo = 0;}
//		numdis[posicion] = numero + 1; // CADA VEZ QUE SE PRESIONE UNA TECLA EL VALOR SE INGRESA EN UN ARRAY VARIANDO LAS POSICIONES DE CENTENAS DECENAS Y UNIDADES
//		posicion++;
//		
////		if(posicion>4){posicion=0;}
//		if(numero >= 10){
//			if(numero == 10){operacion = 1;} //SUMA
//			if(numero == 11){operacion = 2;} //RESTA
//			if(numero == 12){operacion = 3;} //MULTIPLICACION
//			if(numero == 13){operacion = 4;} //DIVISION
//		}		
//		
//		if(numero <= 9){
//			
//			if(conteo == 1){
//				decenas = numero;
//			}
//			if (conteo == 2){
//				unidades = numero;
//			}
//			if(operacion == 0){
//				x = (decenas * 10 + unidades);
//			}else if (operacion == 1 || operacion == 2 || operacion == 3 || operacion == 4){
//				y = (decenas * 10 + unidades);
//			}
//		}
//	}
//}

//void desEnteros(int resultado){ // DESCOMPONER ENTEROS
//	resDisplayE[0] = resultado / 1000;	
//	resDisplayE[1] = (resultado % 1000) / 100;
//	resDisplayE[2] = (resultado % 100) / 10;
//	resDisplayE[3] = (resultado % 10);	
//	
//	if(negativo == 1){
//		resDisplayE[0] = 11;
//		negativo = 0;
//	}
//}

//void desDecimales(int resultado){
//	resDisplayD[0] = resultado / 10000;
//	resDisplayD[1] = resultado / 1000;	
//	resDisplayD[2] = (resultado % 1000) / 100;
//	resDisplayD[3] = 14;
//	resDisplayD[4] = (resultado % 100) / 10;
//	resDisplayD[5] = (resultado % 10);	
//	
//	if(negativo == 1){
//		resDisplayD[0] = 11;
//		negativo = 0;
//	}
//}

//////////////////////FUNCION PRINCIPAL////////////////////
//int main(void) {
//	RCC -> AHB1ENR |= 0X58;
//	RCC -> APB2ENR |= 0X4000;
//	
//	GPIOE -> MODER = 0X555555; //LCD
//	GPIOE -> OTYPER = 0X0;
//	GPIOE -> OSPEEDR = 0X555555;
//	GPIOE -> PUPDR = 0X555555;

//	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) PD12-PD15(ENTRADAS EXTI)
//	GPIOD -> OTYPER |= 0X0; 
//	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
//	GPIOD -> PUPDR |= 0XAA000055; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
//	
//	SYSCFG -> EXTICR[3] = 0X3333; //PINES 12, 13, 14, 15 PUERTO D	
//	EXTI -> IMR = 0XF01F; // PINES 12-15 EXTI
//	EXTI -> RTSR = 0XF01F; //FLANCO DE SUBIDA
//	NVIC_EnableIRQ(EXTI15_10_IRQn);
//	
//	//BOTONES 
//	SYSCFG -> EXTICR[0] = 0X6666; //PINES 0, 1, 2, 3 PUERTO G
//	NVIC_EnableIRQ(EXTI0_IRQn);
//	NVIC_EnableIRQ(EXTI1_IRQn);
//	NVIC_EnableIRQ(EXTI2_IRQn);
//	NVIC_EnableIRQ(EXTI3_IRQn);
//	
//	SYSCFG -> EXTICR[1] = 0X6;
//	NVIC_EnableIRQ(EXTI4_IRQn);
//	
//	SystemCoreClockUpdate();
//	SysTick_Config(SystemCoreClock / 10);
//	
//	comando_lcd(cgram);
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen1[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen2[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen3[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen4[i]);
//	}
//	
//	comando_lcd(clear);
//	comando_lcd(home);
//	comando_lcd(set);
//	comando_lcd(disp_on);
//	comando_lcd(mode_set1);
//	
//	while(1){
//		if(funcionSeno == 1){
//			for(int j = 0; j < 16; j=j+4){
//				comando_lcd(ddram1+j);
//				dato_lcd(0x00);
//				comando_lcd(ddram1+j+1);
//				dato_lcd(0x01);
//				comando_lcd(ddram2+j+2);
//				dato_lcd(0x02);
//				comando_lcd(ddram2+j+3);
//				dato_lcd(0x03);
//				for(int tiempo = 0; tiempo < 100000; tiempo++){};
//			}
//		}else{
//		
//		//BARRIDO DE FILAS DEL TECLADO
//		switch(filas){
//			case 0:
//				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
//			break;
//			case 1:
//				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
//			break;
//			case 2:
//				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
//			break;
//			case 3:
//				GPIOD -> ODR = (1UL << 3); //1000 FILA 0 ACTIVA;
//			break;
//		}
//		//CALCULADORA LCD//
//		
//		comando_lcd(w_linea1);
//		for (int e = 0; e < 5; e++){
//			dato_lcd(display[numdis[e]]);
//		}
//		for(int w=0; w<1000; w++);
//		
//		if(igual != 0){
//			switch(operacion){
//				case 1:
//					resultado = x + y;
//				  desEnteros(resultado);
//				break;
//				
//				case 2:
//					if(x == y) {
//						resultado = 0;
//					}
//				  if(x < y) {
//						negativo = 1;
//						resultado = y -x;
//					}
//					if(x > y){
//					resultado = x - y;
//					}
//				  desEnteros(resultado);
//				break;
//				
//				case 3:
//					resultado = x * y;
//				  desEnteros(resultado);
//				break;
//				
//				case 4:
//					if(y != 0){
//						resultado = (x * 100) / y;
//						desDecimales(resultado);
//					}else{
//						error = 1;
//					}
//				break;
//					
//				case 5: //SENO
//					resultado = sin((double)((x * pi) / 180)) * 100;
//					if (resultado < 0){
//						negativo = 1;
//						resultado = resultado * -1;
//					}
//					desDecimales(resultado);
//				break;
//					
//				case 6: //COSENO
//					resultado = cos((double)((x * pi) / 180)) * 100;
//					if (resultado < 0){
//						negativo = 1;
//						resultado = resultado * -1;
//					}
//					desDecimales(resultado);
//				break;
//					
//				case 7: //TANGENTE
//					if (x != 90){
//						resultado = tan((double)((x * pi) / 180)) * 100; //FUNCION TANGENTE
//						if (resultado < 0){
//							negativo = 1;
//							resultado = resultado * -1;
//						}
//						desDecimales(resultado);
//					}
//				else{
//					dato_lcd(display[0]);
//					error = 1;
//				}
//				break;
//			}
//		}
//		
//		if (igual == 1){
//			if(error == 0){
//				if(operacion == 1 || operacion == 2 || operacion == 3){
//					comando_lcd(w_linea2 + 12);
//					
//					if(resultado==0){//CERO
//						for (int t = 0; t < 3; t++){							
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}		
//						}		
//            dato_lcd(display[resDisplayE[3] + 1]);								
//					}
//					
//					if(resultado>0 && resultado<10){//1 CIFRA
//						for (int t = 0; t < 4; t++){
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
//						}					
//					}
//					
//					if(resultado>9 && resultado<100){//2 CIFRAS 
//						for (int t = 0; t < 3; t++){
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
//						}	
//						dato_lcd(display[resDisplayE[3] + 1]);
//					}
//					
//					if(resultado>99 && resultado<1000){//3 CIFRAS
//						for (int t = 0; t < 2; t++){
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
//						}	
//						dato_lcd(display[resDisplayE[2] + 1]);
//						dato_lcd(display[resDisplayE[3] + 1]);
//					}
//					
//					if(resultado>999 && resultado<10000){//4 CIFRAS
//						if(resDisplayE[0]==0){
//							dato_lcd(display[resDisplayE[0]]);
//						}else{dato_lcd(display[resDisplayE[0] + 1]);}			
//						dato_lcd(display[resDisplayE[1] + 1]);
//						dato_lcd(display[resDisplayE[2] + 1]);
//						dato_lcd(display[resDisplayE[3] + 1]);										
//					}		
//					
//				}else{
//					comando_lcd(w_linea2 + 10);
//					for (int u = 0; u < 6; u++){
//						dato_lcd(display[resDisplayD[u] + 1]);
//					}
//				}
//			}else{
//				comando_lcd(w_linea2 + 6);
////				000.00
////				000.01
////				000.10			
////				001.00
////				010.00
////				100.00
//				
//				if(resultado==0){//				000.00
//					if(resDisplayE[0]==0 && resDisplayE[1]==0){
//						dato_lcd(display[resDisplayE[0]]);
//						dato_lcd(display[resDisplayE[1]]);
//					}
//					dato_lcd(display[resDisplayD[2] + 1]);					
//					dato_lcd(display[resDisplayD[3] + 1]);
//					dato_lcd(display[resDisplayD[4] + 1]);
//					dato_lcd(display[resDisplayD[5] + 1]);					
//				}
//				
//				if(resultado<100){//				xx0.01 - xx0.09					
//					if(resDisplayD[0] == 0){
//						dato_lcd(display[resDisplayD[0]]);
//					}else{dato_lcd(display[resDisplayD[0] + 1]);}
//					
//					dato_lcd(display[resDisplayD[1]]);
//					dato_lcd(display[resDisplayD[2]]);
//					dato_lcd(display[resDisplayD[3] + 1]);
//					dato_lcd(display[resDisplayD[4] + 1]);
//					dato_lcd(display[resDisplayD[5] + 1]);	
//				}
//				  
//				if(resultado>99){//				0xx.01 - 0xx.09					
//					if(resDisplayD[0] == 0){
//						dato_lcd(display[resDisplayD[0]]);
//					}else{dato_lcd(display[resDisplayD[0] + 1]);}
//					if(resDisplayD[1] == 0){
//						dato_lcd(display[resDisplayD[1]]);
//					}else{
//						dato_lcd(display[resDisplayD[1] + 1]);
//					}
//					if(resDisplayD[2] == 0){
//						dato_lcd(display[resDisplayD[2]]);
//					}else{
//						dato_lcd(display[resDisplayD[2] + 1]);
//					}
//					dato_lcd(display[resDisplayD[3] + 1]);
//					dato_lcd(display[resDisplayD[4] + 1]);
//					dato_lcd(display[resDisplayD[5] + 1]);	
//				}
//								
//				for(int h = 0; h < 10; h++){
//					dato_lcd(frase_error[h]);
//				}
//			}		
//			igual = 0;
//			error = 0;
//		}
//	}
//	}
//}
////FIN

//#include "stm32f7xx.h"
//#include <stdio.h>
//#include <math.h>
//#define MAX 16
//#define pi 3.14159265358979

//////////////////////CONTROL VARIABLES DE LCD////////////////////
//char clear = 0x01;		 //Limpiar pantalla
//char home = 0x02;		 //Return
//char mode_set1 = 0x06;	 //Incremento del cursor y modo normal
//char mode_set2 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato
//char disp_on = 0x0E;	 //Display ON, cursor ON, parpadeo
//char disp_off = 0x08;	 //Display OFF, cursor OFF, no parpadeo
//char disp_shift = 0x1C;	 //Desplaza el display -- a la derecha
//char disp_shift1 = 0x18; //Desplaza el display -- a la izquierda
//char disp_shift2 = 0x14; //Mueve el cursor -- a la derecha
//char disp_shift3 = 0x10; //Mueve el cursor -- a la izquierda
//char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10
//char pos_LCD = 0x0;
//char w_linea1 = (0x80 + pos_LCD); //Posicion cero de la primera fila
//char w_linea2 = (0xC0 + pos_LCD); //Posicion cero de la segunda fila
//char centrar = 0X30;
//char cgram = 0X40;
//char ddram1 = 0X80;
//char ddram2 = 0XC0;

//int time = 1000;
//char frase_error[10]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};
//char limpiar [17] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//char seno[7] = {'S', 'I', 'N', '(', ' ', ' ', ')'};
//char coseno[7] = {'C', 'O', 'S', '(',, ' ', ' ', ')'};
//char tangente[7] = {'T', 'A', 'N', '(', ' ', ' ', ')'};

//char const display[17] = {' ' ,0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F, 0X2E, 0X46}; //NUMEROS ASCII-HEXA
////               ESP. BLANCO    0     1     2     3     4     5     6     7     8     9    SUMA  RESTA MULT  DIVI   DOT     F
//////////////////////FUNCION SENOIDAL////////////////////
//char sen1[8] = {0X0, 0X1, 0X2, 0X4, 0X4, 0X8, 0X8, 0X10};
//char sen2[8] = {0X0, 0X10, 0X8, 0X4, 0X4, 0X2, 0X1, 0X1};
//char sen3[8] = {0X10, 0X8, 0X8, 0X4, 0X4, 0X2, 0X1, 0X0};
//char sen4[8] = {0X1, 0X2, 0X2, 0X4, 0X4, 0X8, 0X10, 0X0};

//////////////////////CONTROL VARIABLES PROGRAMA////////////////////

////int const numeros[MAX] = {0x40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X2, 0X78, 0X0, 0X10, 0X8, 0X3, 0X46, 0X21, 0X6, 0XE};
//char resDisplayE[4] = {0, 0, 0, 0}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD
//int numdis[5] = {0, 0, 0, 0, 0};
//char resDisplayD[6] = {0, 0, 0, 0, 0, 0};

//int filas, columna, numero, posicion, operacion = 0, conteo, x, y, funcionSeno;
//int decenas, unidades, resultado, igual, reset, negativo, error = 0, aux;

//////////////////////FUNCIONED LCD////////////////////
//void comando_lcd(char b){
//	GPIOE -> ODR &= 0XFF00;
//	GPIOE -> ODR |= b;
//	GPIOE -> ODR &=~(1UL<<8); //RS=0
//	GPIOE -> ODR |= (1UL<<9); //Enable=1
//	for(int j=0; j<time; j++);
//	GPIOE -> ODR &=~(1UL<<9); //Enable=0
//}

//void dato_lcd(char c){
//	GPIOE -> ODR &= 0XFF00;
//	GPIOE -> ODR |= c;
//	GPIOE -> ODR |= (1UL<<8); //RS=1
//	GPIOE -> ODR |= (1UL<<9); //Enable=1
//	for(int q=0; q<time; q++);
//	GPIOE -> ODR &=~(1UL<<9); //Enable=0
//}

//void limpiar_lcd(int inicio){
//		comando_lcd(w_linea1);
//		for(int d = inicio; d <= 17; d++){ 
//			dato_lcd(limpiar[d]);
//		}
//		for(int r=0; r<100000; r++);
//		
//		comando_lcd(w_linea2);
//		for(int d = 0; d <= 17; d++){ 
//			dato_lcd(limpiar[d]);
//		}
//		for(int r=0; r<100000; r++);
//		
//		comando_lcd(clear);
//		comando_lcd(home);
//	}

//extern "C"{
//	void SysTick_Handler(void){
//		//BARRIDO FILAS
//		filas++;
//		if(filas > 3){
//			filas = 0;
//		}		
//	}
//	
//	void EXTI0_IRQHandler(void){ // CLEAR ALL
//			EXTI->PR |= 0X1;
//			for (int l = 0; l < 1000; l++){};
//				
//			filas = 0, columna = 0, numero = 0, posicion = 0, operacion = 0, conteo = 0, x = 0, y = 0;
//			decenas = 0, unidades = 0, resultado = 0, igual = 0, funcionSeno = 0;
//				
//			for (int i = 0; i < 5; i++){
//				numdis[i] = 0;
//			}
//			for (int i = 0; i <= 3 ; i++){
//				resDisplayE[i] = 0;
//			}
//			for (int i = 0; i < 7 ; i++){
//				resDisplayD[i] = 0;
//			}			
//			comando_lcd(disp_on);
//			limpiar_lcd(0);
//	}
//	
//	void EXTI1_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X2; //BANDERA
//		operacion = 5; // SENO;
//		y = 0, conteo = 0;
//	}
//	
//	void EXTI2_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X4; //BANDERA
//		operacion = 6; // COSENO;
//		y = 0, conteo = 0;
//	}
//		
//	void EXTI3_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X8; //BANDERA
//		operacion = 7; // TANGENTE;
//		y = 0, conteo = 0, numdis[2] = 0;
//	}
//	
//	void EXTI4_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X10; //BANDERA
//		funcionSeno = 1;
//		limpiar_lcd(0);
//		comando_lcd(0XC);
//	}
//	
//	void EXTI9_5_IRQHandler(void){ 
//		aux = EXTI -> PR & (0X70); // SE GUARDA EN aux EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0X70); //BANDERA
//		
//		switch(aux){
//			case 0x20:
//				numdis[posicion] = 0; 
//		    posicion--;
//				break;
//		}
//	}
//		
//	void EXTI15_10_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0XF000); //BANDERA
//			
//		switch(columna){
//			case 0x1000://SE PRESIONO LA COLUMNA 0.
//				if(filas == 0){numero = 1;}
//				else if(filas == 1){numero = 4;}
//				else if(filas == 2){numero = 7;} 
//				else if(filas == 3){} 
//			break;
//			case 0x2000:
//				if(filas == 0){numero = 2;}
//				else if(filas == 1){numero = 5;}
//				else if(filas == 2){numero = 8;} 
//				else if(filas == 3){numero = 0;}
//			break;
//			case 0X4000:
//				if(filas == 0){numero = 3;}
//				else if(filas == 1){numero = 6;}
//				else if(filas == 2){numero = 9;} 
//				else if(filas == 3){igual = 1;} //TECLA IGUAL
//			break;
//			case 0x8000:
//				if(filas == 0){numero = 11;} // TECLA A = RESTA
//				else if(filas == 1){numero = 12;} // TECLA B = MULTIPLICACION
//				else if(filas == 2){numero = 13;} // TECLA C = DIVISION
//				else if(filas == 3){numero = 10;} // TECLA D = SUMA
//			break;
//		}

//		conteo++;
//		if(conteo == 3){conteo = 0;}
//		numdis[posicion] = numero + 1; // CADA VEZ QUE SE PRESIONE UNA TECLA EL VALOR SE INGRESA EN UN ARRAY VARIANDO LAS POSICIONES DE CENTENAS DECENAS Y UNIDADES
//		posicion++;
//				
//		if(numero >= 10){
//			if(numero == 10){operacion = 1;} //SUMA
//			if(numero == 11){operacion = 2;} //RESTA
//			if(numero == 12){operacion = 3;} //MULTIPLICACION
//			if(numero == 13){operacion = 4;} //DIVISION
//		}		
//		if(numero <= 9){ // ASIGNACION DE LOS DOS OPERANDOS ANTES Y DESPUES DE LA OPERACION SELECCIONADA
//			if(conteo == 1){
//				decenas = numero;
//			}
//			if (conteo == 2){
//				unidades = numero;
//			}
//			if(operacion == 0){ //PRIMER OPERANDO
//				x = (decenas * 10 + unidades);
//			}else if (operacion == 1 || operacion == 2 || operacion == 3 || operacion == 4){ //SEGUNDO OPERANDO
//				y = (decenas * 10 + unidades);
//			}
//		}
//	}
//}

//void desEnteros(int resultado){ // DESCOMPONER ENTEROS
//	resDisplayE[0] = resultado / 1000;	
//	resDisplayE[1] = (resultado % 1000) / 100;
//	resDisplayE[2] = (resultado % 100) / 10;
//	resDisplayE[3] = (resultado % 10);	
//	
//	if(negativo == 1){
//		resDisplayE[0] = 11;
//		negativo = 0;
//	}
//}

//void desDecimales(int resultado){
//	resDisplayD[0] = resultado / 10000;
//	resDisplayD[1] = resultado / 1000;	
//	resDisplayD[2] = (resultado % 1000) / 100;
//	resDisplayD[3] = 14;
//	resDisplayD[4] = (resultado % 100) / 10;
//	resDisplayD[5] = (resultado % 10);	
//	
//	if(negativo == 1){
//		resDisplayD[0] = 11;
//		negativo = 0;
//	}
//}

//////////////////////FUNCION PRINCIPAL////////////////////
//int main(void) {
//	RCC -> AHB1ENR |= 0X58;
//	RCC -> APB2ENR |= 0X4000;
//	
//	GPIOE -> MODER = 0X555555; //LCD
//	GPIOE -> OTYPER = 0X0;
//	GPIOE -> OSPEEDR = 0X555555;
//	GPIOE -> PUPDR = 0X555555;

//	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) PD12-PD15(ENTRADAS EXTI)
//	GPIOD -> OTYPER |= 0X0; 
//	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
//	GPIOD -> PUPDR |= 0XAA000055; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
//	
//	SYSCFG -> EXTICR[3] = 0X3333; //PUERTO D	
//	EXTI -> IMR = 0XF0FF; // PINES 0, 1, 2, 3, 4, 5, 6, 7 y 12-15 EXTI
//	EXTI -> RTSR = 0XF0FF; //FLANCO DE SUBIDA
//	NVIC_EnableIRQ(EXTI9_5_IRQn);
//	NVIC_EnableIRQ(EXTI15_10_IRQn);
//	
//	//BOTONES 
//	SYSCFG -> EXTICR[0] = 0X6666; //PUERTO G
//	SYSCFG -> EXTICR[1] = 0X6666; //PUERTO G
//	NVIC_EnableIRQ(EXTI0_IRQn);
//	NVIC_EnableIRQ(EXTI1_IRQn);
//	NVIC_EnableIRQ(EXTI2_IRQn);
//	NVIC_EnableIRQ(EXTI3_IRQn);
//	
//	SYSCFG -> EXTICR[1] = 0X6;
//	NVIC_EnableIRQ(EXTI4_IRQn);
//	
//	SystemCoreClockUpdate();
//	SysTick_Config(SystemCoreClock / 10);
//	
//	comando_lcd(cgram);
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen1[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen2[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen3[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen4[i]);
//	}
//	
//	comando_lcd(clear);
//	comando_lcd(home);
//	comando_lcd(set);
//	comando_lcd(disp_on);
//	comando_lcd(mode_set1);
//	
//	while(1){
//		if(funcionSeno == 1){
//			for(int j = 0; j < 16; j=j+4){
//				comando_lcd(ddram1+j);
//				dato_lcd(0x00);
//				comando_lcd(ddram1+j+1);
//				dato_lcd(0x01);
//				comando_lcd(ddram2+j+2);
//				dato_lcd(0x02);
//				comando_lcd(ddram2+j+3);
//				dato_lcd(0x03);
//				for(int tiempo = 0; tiempo < 100000; tiempo++){};
//			}
//		}else{
//		
//		//BARRIDO DE FILAS DEL TECLADO
//		switch(filas){
//			case 0:
//				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
//			break;
//			case 1:
//				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
//			break;
//			case 2:
//				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
//			break;
//			case 3:
//				GPIOD -> ODR = (1UL << 3); //1000 FILA 0 ACTIVA;
//			break;
//		}
//		//CALCULADORA LCD//
//		
//		comando_lcd(w_linea1);
//		for (int e = 0; e < 5; e++){
//			dato_lcd(display[numdis[e]]); //MOSTRAR INGRESO DE OPERANDOS DINAMICO
//		}
//		for(int w=0; w<1000; w++);
//		
//		if(igual != 0){ 
//			switch(operacion){
//				case 1: //SUMA
//					resultado = x + y;
//				  desEnteros(resultado);
//				break;
//				
//				case 2: //RESTA
//					if(x < y) {
//						negativo = 1;
//						resultado = y -x;
//					}
//					if(x > y){
//					resultado = x - y;
//					}
//				  desEnteros(resultado);
//				break;
//				
//				case 3: //MULTIPLICACION
//					resultado = x * y;
//				  desEnteros(resultado);
//				break;
//				
//				case 4: //DIVISION
//					if(y != 0){
//						resultado = (x * 100) / y;
//						desDecimales(resultado);
//					}else{
//						error = 1;
//					}
//				break;
//					
//				case 5: //SENO
//					resultado = sin((double)((x * pi) / 180)) * 100;
//					if (resultado < 0){
//						negativo = 1;
//						resultado = resultado * -1;
//					}
//					desDecimales(resultado);
//				break;
//					
//				case 6: //COSENO
//					resultado = cos((double)((x * pi) / 180)) * 100;
//					if (resultado < 0){
//						negativo = 1;
//						resultado = resultado * -1;
//					}
//					desDecimales(resultado);
//				break;
//					
//				case 7: //TANGENTE
//					if (x != 90){
//						resultado = tan((double)((x * pi) / 180)) * 100; //FUNCION TANGENTE
//						if (resultado < 0){
//							negativo = 1;
//							resultado = resultado * -1;
//						}
//						desDecimales(resultado);
//					}
//				else{
//					error = 1;
//				}
//				break;
//			}
//		}
//		
//		if (igual == 1){
//			if(error == 0){
//				if(operacion == 1 || operacion == 2 || operacion == 3){
//						comando_lcd(w_linea2 + 12);
//						
//					if(resultado == 0){//CERO
//						for (int t = 0; t < 3; t++){							
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}
//						}
//						dato_lcd(display[resDisplayE[3] + 1]);						
//					}
//					
//					else if(resultado>0 && resultado<10){ //1 CIFRA
//						for (int t = 0; t < 4; t++){
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
//						}					
//					}
//					
//					if(resultado>9 && resultado<100){ //2 CIFRAS
//						for (int t = 0; t < 3; t++){
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
//						}	
//						dato_lcd(display[resDisplayE[3] + 1]);
//					}
//					
//					if(resultado>99 && resultado<1000){//3 CIFRAS
//						for (int t = 0; t < 2; t++){
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
//						}	
//						dato_lcd(display[resDisplayE[2] + 1]);
//						dato_lcd(display[resDisplayE[3] + 1]);
//					}
//					
//					if(resultado>999 && resultado<10000){//4 CIFRAS
//						if(resDisplayE[0]==0){
//							dato_lcd(display[resDisplayE[0]]);
//						}else{dato_lcd(display[resDisplayE[0] + 1]);}			
//						dato_lcd(display[resDisplayE[1] + 1]);
//						dato_lcd(display[resDisplayE[2] + 1]);
//						dato_lcd(display[resDisplayE[3] + 1]);										
//					}
//					
//				}else{
//					if(operacion == 5 || operacion == 6 || operacion == 7){
//						numdis[2] = 0;
//						dato_lcd(display[numdis[2]]);
//					}
//					comando_lcd(w_linea2 + 10);
//					if(resultado==0){//				000.00
//					if(resDisplayE[0]==0 && resDisplayE[1]==0){
//						dato_lcd(display[resDisplayE[0]]);
//						dato_lcd(display[resDisplayE[1]]);
//					}
//					dato_lcd(display[resDisplayD[2] + 1]);					
//					dato_lcd(display[resDisplayD[3] + 1]);
//					dato_lcd(display[resDisplayD[4] + 1]);
//					dato_lcd(display[resDisplayD[5] + 1]);					
//				}
//				
//				if(resultado<100){//				xx0.01 - xx0.09					
//					if(resDisplayD[0] == 0){
//						dato_lcd(display[resDisplayD[0]]);
//					}else{dato_lcd(display[resDisplayD[0] + 1]);}
//					
//					dato_lcd(display[resDisplayD[1]]);
//					dato_lcd(display[resDisplayD[2] + 1]);
//					dato_lcd(display[resDisplayD[3] + 1]);
//					dato_lcd(display[resDisplayD[4] + 1]);
//					dato_lcd(display[resDisplayD[5] + 1]);	
//				}
//				  
//				if(resultado>99){//				0xx.01 - 0xx.09					
//					if(resDisplayD[0] == 0){
//						dato_lcd(display[resDisplayD[0]]);
//					}else{dato_lcd(display[resDisplayD[0] + 1]);}
//					if(resDisplayD[1] == 0){
//						dato_lcd(display[resDisplayD[1]]);
//					}else{
//						dato_lcd(display[resDisplayD[1] + 1]);
//					}
//					if(resDisplayD[2] == 0){
//						dato_lcd(display[resDisplayD[2]]);
//					}else{
//						dato_lcd(display[resDisplayD[2] + 1]);
//					}
//					dato_lcd(display[resDisplayD[3] + 1]);
//					dato_lcd(display[resDisplayD[4] + 1]);
//					dato_lcd(display[resDisplayD[5] + 1]);	
//				}
//					
//					
//				}
//			}else{
//				if(operacion == 7){
//					comando_lcd(w_linea1);
//					dato_lcd(display[numdis[2] = 0]);
//				}
//				comando_lcd(w_linea2 + 6);
//				for(int h = 0; h < 10; h++){
//					dato_lcd(frase_error[h]);
//				}
//			}		
//			igual = 0;
//			error = 0;
//		}
//	}
//	}
//}
////FIN


//#include "stm32f7xx.h"
//#include <stdio.h>
//#include <math.h>
//#define MAX 16
//#define pi 3.14159265358979
//#define LENGHT 12

//////////////////////CONTROL VARIABLES DE LCD////////////////////
//char clear = 0x01;		 //Limpiar pantalla
//char home = 0x02;		 //Return
//char mode_set1 = 0x06;	 //Incremento del cursor y modo normal
//char mode_set2 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato
//char disp_on = 0x0E;	 //Display ON, cursor ON, parpadeo
//char disp_off = 0x08;	 //Display OFF, cursor OFF, no parpadeo
//char disp_shift = 0x1C;	 //Desplaza el display -- a la derecha
//char disp_shift1 = 0x18; //Desplaza el display -- a la izquierda
//char disp_shift2 = 0x14; //Mueve el cursor -- a la derecha
//char disp_shift3 = 0x10; //Mueve el cursor -- a la izquierda
//char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10
//char pos_LCD = 0x0;
//char w_linea1 = (0x80 + pos_LCD); //Posicion cero de la primera fila
//char w_linea2 = (0xC0 + pos_LCD); //Posicion cero de la segunda fila
//char centrar = 0X30;
//char cgram = 0X40;
//char ddram1 = 0X80;
//char ddram2 = 0XC0;

//int time = 1000;
//char frase_error[10]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};
//char limpiar [17] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
//char seno[LENGHT] = {'S', 'I', 'N', 0X28, ' ', ' ', 0X29, ' ',  ' ', ' ', ' ', ' ',};
//char coseno[LENGHT] = {'C', 'O', 'S', 0X28, ' ', ' ', 0X29, ' ', ' ', ' ', ' ', ' ',};
//char tangente[LENGHT] = {'T', 'A', 'N', 0X28, ' ', ' ', 0X29, ' ', ' ', ' ', ' ', ' ',};

//char const display[17] = {' ' ,0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F, 0X2E, 0X46}; //NUMEROS ASCII-HEXA
////               ESP. BLANCO    0     1     2     3     4     5     6     7     8     9    SUMA  RESTA MULT  DIVI   DOT     F
//////////////////////FUNCION SENOIDAL////////////////////
//char sen1[8] = {0X0, 0X1, 0X2, 0X4, 0X4, 0X8, 0X8, 0X10};
//char sen2[8] = {0X0, 0X10, 0X8, 0X4, 0X4, 0X2, 0X1, 0X1};
//char sen3[8] = {0X10, 0X8, 0X8, 0X4, 0X4, 0X2, 0X1, 0X0};
//char sen4[8] = {0X1, 0X2, 0X2, 0X4, 0X4, 0X8, 0X10, 0X0};

//////////////////////CONTROL VARIABLES PROGRAMA////////////////////

////int const numeros[MAX] = {0x40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X2, 0X78, 0X0, 0X10, 0X8, 0X3, 0X46, 0X21, 0X6, 0XE};
//char resDisplayE[4] = {0, 0, 0, 0}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD
//int numdis[5] = {0, 0, 0, 0, 0};
//char resDisplayD[6] = {0, 0, 0, 0, 0, 0};

//int filas, columna, numero, posicion, operacion = 0, conteo, x, y, funcionSeno;
//int decenas, unidades, resultado, igual, reset, negativo, error = 0, aux, borrar, curd=-1, curi=5;

//////////////////////FUNCIONED LCD////////////////////
//void comando_lcd(char b){
//	GPIOE -> ODR &= 0XC0;
//	GPIOE -> ODR |= b;
//	GPIOE -> ODR &=~(1UL<<8); //RS=0
//	GPIOE -> ODR |= (1UL<<9); //Enable=1
//	for(int j=0; j<time; j++);
//	GPIOE -> ODR &=~(1UL<<9); //Enable=0
//}

//void dato_lcd(char c){
//	GPIOE -> ODR &= 0XC0;
//	GPIOE -> ODR |= c;
//	GPIOE -> ODR |= (1UL<<8); //RS=1
//	GPIOE -> ODR |= (1UL<<9); //Enable=1
//	for(int q=0; q<time; q++);
//	GPIOE -> ODR &=~(1UL<<9); //Enable=0
//}

//void limpiar_lcd(int inicio){
//		comando_lcd(w_linea1);
//		for(int d = inicio; d <= 17; d++){ 
//			dato_lcd(limpiar[d]);
//		}
//		for(int r=0; r<100000; r++);
//		
//		comando_lcd(w_linea2);
//		for(int d = 0; d <= 17; d++){ 
//			dato_lcd(limpiar[d]);
//		}
//		for(int r=0; r<100000; r++);
//		
//		comando_lcd(clear);
//		comando_lcd(home);
//	}

//extern "C"{
//	void SysTick_Handler(void){
//		//BARRIDO FILAS
//		filas++;
//		if(filas > 3){
//			filas = 0;
//		}		
//	}
//	
//	void EXTI0_IRQHandler(void){ // CLEAR ALL
//			EXTI->PR |= 0X1;
//			for (int l = 0; l < 1000; l++){};
//				
//			filas = 0, columna = 0, numero = 0, posicion = 0, operacion = 0, conteo = 0, x = 0, y = 0;
//			decenas = 0, unidades = 0, resultado = 0, igual = 0, funcionSeno = 0, aux = 0;
//				
//			for (int i = 0; i < 5; i++){
//				numdis[i] = 0;
//			}
//			for (int i = 0; i <= 3 ; i++){
//				resDisplayE[i] = 0;
//			}
//			for (int i = 0; i < 7 ; i++){
//				resDisplayD[i] = 0;
//			}			
//			comando_lcd(disp_on);
//			limpiar_lcd(1);
//	}
//	
//	void EXTI1_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X2; //BANDERA
//		operacion = 5; // SENO;
//		y = 0, conteo = 0, aux = 1;
//	}
//	
//	void EXTI2_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X4; //BANDERA
//		operacion = 6; // COSENO;
//		y = 0, conteo = 0 , aux = 1;
//	}
//		
//	void EXTI3_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X8; //BANDERA
//		operacion = 7; // TANGENTE;
//		y = 0, conteo = 0, numdis[2] = 0, aux = 1;
//	}
//	
//	void EXTI4_IRQHandler(void){ 
//		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
//		EXTI -> PR |= 0X10; //BANDERA
//		funcionSeno = 1;
//		limpiar_lcd(0);
//		comando_lcd(0XC);
//	}
//	
//	void EXTI15_10_IRQHandler (void){
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0XF000); //BANDERA
//			
//		switch(columna){
//			case 0x1000://SE PRESIONO LA COLUMNA 0.
//				if(filas == 0){numero = 1;}
//				else if(filas == 1){numero = 4;}
//				else if(filas == 2){numero = 7;} 
//				else if(filas == 3){} //TECLA ON O * = CLEAR
//			break;
//			case 0x2000:
//				if(filas == 0){numero = 2;}
//				else if(filas == 1){numero = 5;}
//				else if(filas == 2){numero = 8;} 
//				else if(filas == 3){numero = 0;}
//			break;
//			case 0X4000:
//				if(filas == 0){numero = 3;}
//				else if(filas == 1){numero = 6;}
//				else if(filas == 2){numero = 9;} 
//				else if(filas == 3){igual = 1;} //TECLA IGUAL
//			break;
//			case 0x8000:
//				if(filas == 0){numero = 11;} // TECLA A = RESTA
//				else if(filas == 1){numero = 12;} // TECLA B = MULTIPLICACION
//				else if(filas == 2){numero = 13;} // TECLA C = DIVISION
//				else if(filas == 3){numero = 10;} // TECLA D = SUMA
//			break;
//		}
//		conteo++;
//		if(conteo == 3){conteo = 0;}
//		numdis[posicion] = numero + 1; // CADA VEZ QUE SE PRESIONE UNA TECLA EL VALOR SE INGRESA EN UN ARRAY VARIANDO LAS POSICIONES DE CENTENAS DECENAS Y UNIDADES
//		posicion++;
//		if(posicion == 5){
//			posicion = 0;
//		}
//		
//		if(numero >= 10){
//			if(numero == 10){operacion = 1;} //SUMA
//			if(numero == 11){operacion = 2;} //RESTA
//			if(numero == 12){operacion = 3;} //MULTIPLICACION
//			if(numero == 13){operacion = 4;} //DIVISION
//		}		
//				
//			if(operacion == 0){ //PRIMER OPERANDO
//				if(conteo == 1){
//					decenas1 = numdis[0];
//				}
//				if (conteo == 2){
//					unidades1 = numdis[1];
//				}
//				x = (decenas1 * 10 + unidades1);
//			}else if (operacion >= 1){ //SEGUNDO OPERANDO
//				if(conteo == 1){
//					decenas2 = numdis[3];
//				}
//				if (conteo == 2){
//					unidades2 = numdis[4];
//				}
//				y = (decenas2 * 10 + unidades2);
//			}
//		}
//	}
//	void EXTI9_5_IRQHandler(void){ 
//		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
//		borrar = EXTI -> PR & (0X70); // SE GUARDA EN aux EL PR QUE SE ACTIVA
//		EXTI -> PR |= (0X70); //BANDERA
//		
//		switch(borrar){
//			case 0x20:
//				posicion--;
//				numdis[posicion] = 0; 		
//			  conteo--;
//			  if(operacion==0){// ESTAMOS EN X
//					if(conteo==1){// ESTAMOS EN LA DECENA
//						decenas1=0;
//						x = decenas1;
//					}
//					if(conteo==2){// ESTAMOS EN LA UNIDAD
//						unidades1=0;	
//            x = decenas1 + unidades1;						
//					}
//				}else if(operacion>0){// ESTAMOS EN Y
//					if(conteo==1){// ESTAMOS EN LA DECENA
//						decenas2=0;
//						y = decenas2;
//					}
//					if(conteo==2){// ESTAMOS EN LA UNIDAD
//						unidades2=0;
//            y = decenas2 + unidades2;							
//					}
//				}
//				break;
//			case 0x40://CURSOR DERECHA	0 1 2 3 4
//		
//			  curd++;			
//				switch(curd){//conteo, x, y
//					case 0:// ESTAMOS EN X
//						if(conteo==1){// ESTAMOS EN LA DECENA
//							decenas1=numero;
//						}
//						break;
//					case 1:
//						if(conteo==2){// ESTAMOS EN LA UNIDAD
//							unidades1=numero;					
//						}
//						x=decenas + unidades;
//						break;
//					case 3:// ESTAMOS EN Y
//						if(conteo==1){// ESTAMOS EN LA DECENA
//							decenas2=numero;
//						}
//						break;
//					case 4:// ESTAMOS EN Y
//						if(conteo==2){// ESTAMOS EN LA UNIDAD
//							unidades2=numero;					
//						}
//						y=decenas + unidades;
//						break;
//					}	
//				if(curd>4){curd=-1;}
//	   
//				break;
//			case 0x80://CURSOR IZQUIERDA			
//			  curi--;
//				switch(curi){//conteo, x, y
//					case 4:
//						if(operacion==0 || operacion>0){// ESTAMOS EN X
//							if(conteo==2){
//								unidades=numero;					
//							}
//						}
//						break;
//					case 3:
//						if(operacion==0 || operacion>0){// ESTAMOS EN X
//							if(conteo==1){
//								decenas=numero;					
//							}
//						}
//						break;
//					case 2:
//						break;
//					case 1:
//						if(operacion==0 || operacion>0){// ESTAMOS EN X
//							if(conteo==2){
//								unidades=numero;					
//							}
//						}
//						break;
//					case 0:
//						if(operacion==0 || operacion>0){// ESTAMOS EN X
//							if(conteo==1){
//								decenas=numero;					
//							}
//						}
//						break;					
//				}
//			  if(curi==0){curi=5;}
//				break;
//		}
//	}
//}

//void desEnteros(int resultado){ // DESCOMPONER ENTEROS
//	resDisplayE[0] = resultado / 1000;	
//	resDisplayE[1] = (resultado % 1000) / 100;
//	resDisplayE[2] = (resultado % 100) / 10;
//	resDisplayE[3] = (resultado % 10);	
//	
//	if(negativo == 1){
//		resDisplayE[0] = 11;
//		negativo = 0;
//	}
//}

//void desDecimales(int resultado){
//	resDisplayD[0] = resultado / 10000;
//	resDisplayD[1] = resultado / 1000;	
//	resDisplayD[2] = (resultado % 1000) / 100;
//	resDisplayD[3] = 14;
//	resDisplayD[4] = (resultado % 100) / 10;
//	resDisplayD[5] = (resultado % 10);	
//	
//	if(negativo == 1){
//		resDisplayD[0] = 11;
//		negativo = 0;
//	}
//}

//////////////////////FUNCION PRINCIPAL////////////////////
//int main(void) {
//	RCC -> AHB1ENR |= 0X5A; //PUERTOS B, D, E, G 
//	RCC -> APB2ENR |= 0X4000;
//	
//	GPIOE -> MODER = 0X555555; //LCD
//	GPIOE -> OTYPER = 0X0;
//	GPIOE -> OSPEEDR = 0X555555;
//	GPIOE -> PUPDR = 0X555555;
//	
//	GPIOB -> MODER = 0X10004001; //LED STM
//	GPIOB -> OTYPER = 0X0;
//	GPIOB -> OSPEEDR = 0X10004001;
//	GPIOB -> PUPDR = 0X10004001;

//	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) PD12-PD15(ENTRADAS EXTI)
//	GPIOD -> OTYPER |= 0X0; 
//	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
//	GPIOD -> PUPDR |= 0XAA000055; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
//	
//	SYSCFG -> EXTICR[3] = 0X3333; //PINES 12, 13, 14, 15 PUERTO D	
//	EXTI -> IMR = 0XF0FF; // PINES 12-15 EXTI
//	EXTI -> RTSR = 0XF0FF; //FLANCO DE SUBIDA
//	NVIC_EnableIRQ(EXTI15_10_IRQn);
//	
//	//BOTONES 
//	SYSCFG -> EXTICR[0] = 0X6666; //PINES 0, 1, 2, 3 PUERTO G
//	NVIC_EnableIRQ(EXTI0_IRQn);
//	NVIC_EnableIRQ(EXTI1_IRQn);
//	NVIC_EnableIRQ(EXTI2_IRQn);
//	NVIC_EnableIRQ(EXTI3_IRQn);
//	
//	//BOTONES ADICIONALES RESET Y LCD
//	SYSCFG -> EXTICR[1] = 0X6666;
//	NVIC_EnableIRQ(EXTI4_IRQn);
//	NVIC_EnableIRQ(EXTI9_5_IRQn);
//	
//	SystemCoreClockUpdate();
//	SysTick_Config(SystemCoreClock / 10);
//	
//	comando_lcd(cgram);
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen1[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen2[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen3[i]);
//	}
//	for(int i = 0; i < 8; i++){
//		dato_lcd(sen4[i]);
//	}
//	
//	comando_lcd(clear);
//	comando_lcd(home);
//	comando_lcd(set);
//	comando_lcd(disp_on);
//	comando_lcd(mode_set1);
//	operacion = 0;
//	while(1){
//		if(funcionSeno == 1){
//			for(int j = 0; j < 16; j=j+4){
//				comando_lcd(ddram1+j);
//				dato_lcd(0x00);
//				comando_lcd(ddram1+j+1);
//				dato_lcd(0x01);
//				comando_lcd(ddram2+j+2);
//				dato_lcd(0x02);
//				comando_lcd(ddram2+j+3);
//				dato_lcd(0x03);
//				for(int tiempo = 0; tiempo < 100000; tiempo++){};
//			}
//		}else{
//		
//		//BARRIDO DE FILAS DEL TECLADO
//		switch(filas){
//			case 0:
//				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
//			break;
//			case 1:
//				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
//			break;
//			case 2:
//				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
//			break;
//			case 3:
//				GPIOD -> ODR = (1UL << 3); //1000 FILA 0 ACTIVA;
//			break;
//		}
//		//CALCULADORA LCD//
//		if(aux == 0){
//			comando_lcd(w_linea1);
//			for (int e = 0; e < 5; e++){
//				dato_lcd(display[numdis[e]]); //MOSTRAR INGRESO DE OPERANDOS DINAMICO
//			}
//			for(int w=0; w<1000; w++);
//		}else if(aux == 1){
//			if(operacion == 5){ //MOSTRAR LETRAS SEN
//				comando_lcd(w_linea1);
//				for(int i = 0; i <= LENGHT - 1; i++){
//					dato_lcd(seno[i]);
//				}
//				seno[4] = display[numdis[0]];
//				seno[5] = display[numdis[1]];
//			}
//			if(operacion == 6){ //MOSTRAR LETRAS COS
//				comando_lcd(w_linea1);
//				for(int i = 0; i <= LENGHT - 1; i++){
//					dato_lcd(coseno[i]);
//				}
//				coseno[4] = display[numdis[0]];
//				coseno[5] = display[numdis[1]];
//			}
//			if(operacion == 7){ //MOSTRAR LETRAS TAN
//				comando_lcd(w_linea1);
//				for(int i = 0; i <= LENGHT - 1; i++){
//					dato_lcd(tangente[i]);
//				}
//				tangente[4] = display[numdis[0]];
//				tangente[5] = display[numdis[1]];
//			}
//			for(int w=0; w<1000; w++);
//		}
//		
//		if(igual != 0){ 
//			switch(operacion){
//				case 1: //SUMA
//					resultado = x + y;
//				  desEnteros(resultado);
//				break;
//				
//				case 2: //RESTA
//					if(x < y) {
//						negativo = 1;
//						resultado = y -x;
//					}
//					if(x > y){
//					resultado = x - y;
//					}
//				  desEnteros(resultado);
//				break;
//				
//				case 3: //MULTIPLICACION
//					resultado = x * y;
//				  desEnteros(resultado);
//				break;
//				
//				case 4: //DIVISION
//					if(y != 0){
//						resultado = (x * 100) / y;
//						desDecimales(resultado);
//					}else{
//						error = 1;
//					}
//				break;
//					
//				case 5: //SENO
//					resultado = sin((double)((y * pi) / 180)) * 100;
//					if (resultado < 0){
//						negativo = 1;
//						resultado = resultado * - 1;
//					}
//					desDecimales(resultado);
//				break;
//					
//				case 6: //COSENO
//					resultado = cos((double)((y * pi) / 180)) * 100;
//					if (resultado < 0){
//						negativo = 1;
//						resultado = resultado * - 1;
//					}
//					desDecimales(resultado);
//				break;
//					
//				case 7: //TANGENTE
//					if (y != 90){
//						resultado = tan((double)((y * pi) / 180)) * 100; //FUNCION TANGENTE
//						if (resultado < 0){
//							negativo = 1;
//							resultado = resultado * - 1;
//						}
//						desDecimales(resultado);
//					}
//				else{
//					error = 1;
//				}
//				break;
//			}
//		}
//		
//		if (igual == 1){
//			if(error == 0){
//				if(operacion == 1 || operacion == 2 || operacion == 3){
//						comando_lcd(w_linea2 + 12);
//						
//					if(resultado == 0){//CERO
//						for (int t = 0; t < 3; t++){							
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}
//						}
//						dato_lcd(display[resDisplayE[3] + 1]);						
//					}
//					
//					else if(resultado>0 && resultado<10){ //1 CIFRA
//						for (int t = 0; t < 4; t++){
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
//						}					
//					}
//					
//					if(resultado>9 && resultado<100){ //2 CIFRAS
//						for (int t = 0; t < 3; t++){
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
//						}	
//						dato_lcd(display[resDisplayE[3] + 1]);
//					}
//					
//					if(resultado>99 && resultado<1000){//3 CIFRAS
//						for (int t = 0; t < 2; t++){
//							if(resDisplayE[t]==0){
//								dato_lcd(display[resDisplayE[t]]);
//							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
//						}	
//						dato_lcd(display[resDisplayE[2] + 1]);
//						dato_lcd(display[resDisplayE[3] + 1]);
//					}
//					
//					if(resultado>999 && resultado<10000){//4 CIFRAS
//						if(resDisplayE[0]==0){
//							dato_lcd(display[resDisplayE[0]]);
//						}else{dato_lcd(display[resDisplayE[0] + 1]);}			
//						dato_lcd(display[resDisplayE[1] + 1]);
//						dato_lcd(display[resDisplayE[2] + 1]);
//						dato_lcd(display[resDisplayE[3] + 1]);										
//					}
//					
//				}else{
//					if(operacion == 5 || operacion == 6 || operacion == 7){
//						numdis[2] = 0;
//						dato_lcd(display[numdis[2]]);
//					}
//					comando_lcd(w_linea2 + 10);
//					if(resultado==0){//				000.00
//					if(resDisplayE[0]==0 && resDisplayE[1]==0){
//						dato_lcd(display[resDisplayE[0]]);
//						dato_lcd(display[resDisplayE[1]]);
//					}
//					dato_lcd(display[resDisplayD[2] + 1]);					
//					dato_lcd(display[resDisplayD[3] + 1]);
//					dato_lcd(display[resDisplayD[4] + 1]);
//					dato_lcd(display[resDisplayD[5] + 1]);					
//				}
//				
//				if(resultado<100){//				xx0.01 - xx0.09					
//					if(resDisplayD[0] == 0){
//						dato_lcd(display[resDisplayD[0]]);
//					}else{dato_lcd(display[resDisplayD[0] + 1]);}
//					
//					dato_lcd(display[resDisplayD[1]]);
//					dato_lcd(display[resDisplayD[2] + 1]);
//					dato_lcd(display[resDisplayD[3] + 1]);
//					dato_lcd(display[resDisplayD[4] + 1]);
//					dato_lcd(display[resDisplayD[5] + 1]);	
//				}
//				  
//					if(resultado>99){//				0xx.01 - 0xx.09					
//						if(resDisplayD[0] == 0){
//							dato_lcd(display[resDisplayD[0]]);
//						}else{dato_lcd(display[resDisplayD[0] + 1]);}
//						if(resDisplayD[1] == 0){
//							dato_lcd(display[resDisplayD[1]]);
//						}else{
//							dato_lcd(display[resDisplayD[1] + 1]);
//						}
//						if(resDisplayD[2] == 0){
//							dato_lcd(display[resDisplayD[2]]);
//						}else{
//							dato_lcd(display[resDisplayD[2] + 1]);
//						}
//						dato_lcd(display[resDisplayD[3] + 1]);
//						dato_lcd(display[resDisplayD[4] + 1]);
//						dato_lcd(display[resDisplayD[5] + 1]);	
//					}
//				}
//			}else{
//				if(operacion == 7){
//					comando_lcd(w_linea1);
//					dato_lcd(display[numdis[2] = 0]);
//				}
//				comando_lcd(w_linea2 + 6);
//				for(int h = 0; h < 10; h++){
//					dato_lcd(frase_error[h]);
//				}
//			}		
//			igual = 0;
//			error = 0;
//		}
//	}
//	}
//}
////FIN

#include "stm32f4xx.h"
#include <stdio.h>
#include <math.h>
#define MAX 16
#define pi 3.14159265358979
#define LENGHT 12

////////////////////CONTROL VARIABLES DE LCD////////////////////
char clear = 0x01;		 //Limpiar pantalla
char home = 0x02;		 //Return
char mode_set1 = 0x06;	 //Incremento del cursor y modo normal
char mode_set2 = 0x04;	 //Incremento del cursor y desplaza la visual cada vez que se le escribe un dato
char disp_on = 0x0E;	 //Display ON, cursor ON, parpadeo
char disp_off = 0x08;	 //Display OFF, cursor OFF, no parpadeo
char disp_shift = 0x1C;	 //Desplaza el display -- a la derecha
char disp_shift1 = 0x18; //Desplaza el display -- a la izquierda
char disp_shift2 = 0x14; //Mueve el cursor -- a la derecha
char disp_shift3 = 0x10; //Mueve el cursor -- a la izquierda
char set = 0x38;		 //Bus a 8 bits, LCD 2 lineas, caracter 5x10
char pos_LCD = 0x0;
char w_linea1 = (0x80 + pos_LCD); //Posicion cero de la primera fila
char w_linea2 = (0xC0 + pos_LCD); //Posicion cero de la segunda fila
char cgram = 0X40;
char ddram1 = 0X80;
char ddram2 = 0XC0;

int time = 1000;
char frase_error[10]={'M', 'a', 't', 'h', ' ', 'E', 'R' ,'R', 'O' ,'R'};
char limpiar [17] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char seno[LENGHT] = {'S', 'I', 'N', 0X28, ' ', ' ', 0X29, ' ',  ' ', ' ', ' ', ' ',};
char coseno[LENGHT] = {'C', 'O', 'S', 0X28, ' ', ' ', 0X29, ' ', ' ', ' ', ' ', ' ',};
char tangente[LENGHT] = {'T', 'A', 'N', 0X28, ' ', ' ', 0X29, ' ', ' ', ' ', ' ', ' ',};

char const display[17] = {' ' ,0X30, 0X31, 0X32, 0X33, 0X34, 0X35, 0X36, 0X37, 0X38, 0X39, 0X2B, 0X2D, 0X2A, 0X2F, 0X2E, 0X46}; //NUMEROS ASCII-HEXA
//               ESP. BLANCO    0     1     2     3     4     5     6     7     8     9    SUMA  RESTA MULT  DIVI   DOT     F
////////////////////FUNCION SENOIDAL////////////////////
char sen1[8] = {0X0, 0X1, 0X2, 0X4, 0X4, 0X8, 0X8, 0X10};
char sen2[8] = {0X0, 0X10, 0X8, 0X4, 0X4, 0X2, 0X1, 0X1};
char sen3[8] = {0X10, 0X8, 0X8, 0X4, 0X4, 0X2, 0X1, 0X0};
char sen4[8] = {0X1, 0X2, 0X2, 0X4, 0X4, 0X8, 0X10, 0X0};

////////////////////CONTROL VARIABLES PROGRAMA////////////////////

//int const numeros[MAX] = {0x40, 0X79, 0X24, 0X30, 0X19, 0X12, 0X2, 0X78, 0X0, 0X10, 0X8, 0X3, 0X46, 0X21, 0X6, 0XE};
char resDisplayE[4] = {0, 0, 0, 0}; // ALMACENAR Y MOSTRAR NUMEROS EN LCD
int numdis[5] = {0, 0, 0, 0, 0};
char resDisplayD[6] = {0, 0, 0, 0, 0, 0};

int filas, columna, numero, posicion, operacion = 0, conteo, x, y, funcionSeno;
int decenas, unidades, resultado, igual, reset, negativo, error = 0, aux, borrar, curd = -1, curi = 5;

////////////////////FUNCIONED LCD////////////////////
void comando_lcd(char b){
	GPIOE -> ODR &= 0XFF00;
	GPIOE -> ODR |= b;
	GPIOE -> ODR &=~(1UL<<8); //RS=0
	GPIOE -> ODR |= (1UL<<9); //Enable=1
	for(int j=0; j<time; j++);
	GPIOE -> ODR &=~(1UL<<9); //Enable=0
}

void dato_lcd(char c){
	GPIOE -> ODR &= 0XFF00;
	GPIOE -> ODR |= c;
	GPIOE -> ODR |= (1UL<<8); //RS=1
	GPIOE -> ODR |= (1UL<<9); //Enable=1
	for(int q=0; q<time; q++);
	GPIOE -> ODR &=~(1UL<<9); //Enable=0
}

void limpiar_lcd(int inicio){
		comando_lcd(w_linea1);
		for(int d = inicio; d <= 17; d++){ 
			dato_lcd(limpiar[d]);
		}
		for(int r=0; r<100000; r++);
		
		comando_lcd(w_linea2);
		for(int d = 0; d <= 17; d++){ 
			dato_lcd(limpiar[d]);
		}
		for(int r=0; r<100000; r++);
		
		comando_lcd(clear);
		comando_lcd(home);
	}

extern "C"{
	void SysTick_Handler(void){
		//BARRIDO FILAS
		filas++;
		if(filas > 3){
			filas = 0;
		}		
	}
	
	void EXTI0_IRQHandler(void){ // CLEAR ALL
			for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
			EXTI->PR |= 0X1;
				
			filas = 0, columna = 0, numero = 0, posicion = 0, operacion = 0, conteo = 0, x = 0, y = 0;
			decenas = 0, unidades = 0, resultado = 0, igual = 0, funcionSeno = 0, aux = 0, curd = -1, curi = 5;
				
			for (int i = 0; i < 5; i++){
				numdis[i] = 0;
			}
			for (int i = 0; i <= 3 ; i++){
				resDisplayE[i] = 0;
			}
			for (int i = 0; i < 7 ; i++){
				resDisplayD[i] = 0;
			}			
			comando_lcd(disp_on);
			limpiar_lcd(1);
	}
	
	//BOTONES PARA FUNCIONES SEN, COS, TAN
	void EXTI1_IRQHandler(void){ 
		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
		EXTI -> PR |= 0X2; //BANDERA
		operacion = 5; // SENO;
		y = 0, conteo = 0, aux = 1;
	}
	
	void EXTI2_IRQHandler(void){ 
		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
		EXTI -> PR |= 0X4; //BANDERA
		operacion = 6; // COSENO;
		y = 0, conteo = 0 , aux = 1;
	}
		
	void EXTI3_IRQHandler(void){ 
		for(int i = 0; i < 10000; i++){}; //ANTIRREBOTE
		EXTI -> PR |= 0X8; //BANDERA
		operacion = 7; // TANGENTE;
		y = 0, conteo = 0, numdis[2] = 0, aux = 1;
	}
	
	//BOTON PARA MOSTRAR LA FUNCION SENOSOIDAL
	void EXTI4_IRQHandler(void){ 
		for(int i = 0; i < 100000; i++){}; //ANTIRREBOTE
		EXTI -> PR |= 0X10; //BANDERA
		funcionSeno = 1;
		limpiar_lcd(0);
		comando_lcd(0XC);
	}
	
	//BOTONES PARA BORRAR Y CURSOR
	void EXTI9_5_IRQHandler(void){ 
		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
		borrar = EXTI -> PR & (0X70); // SE GUARDA EN aux EL PR QUE SE ACTIVA
		EXTI -> PR |= (0X70); //BANDERA
		
		switch(borrar){
			case 0x20:
				posicion--;
				numdis[posicion] = 0; 		
			  if(operacion==0){// ESTAMOS EN X
					if(conteo==1){// ESTAMOS EN LA DECENA
						decenas=0;
						x = decenas;
					}
					if(conteo==2){// ESTAMOS EN LA UNIDAD
						unidades=0;	
            x = decenas;						
					}
				}else if(operacion>0){// ESTAMOS EN Y
					if(conteo==1){// ESTAMOS EN LA DECENA
						decenas=0;
						y = decenas;
					}
					if(conteo==2){// ESTAMOS EN LA UNIDAD
						unidades=0;
            y = decenas + unidades;							
					}
				}
				conteo--;
				break;
		}
	}
	
	//CONFIGURACION DEL TECLADO
	void EXTI15_10_IRQHandler (void){
		for(int i = 0; i < 1000000; i++){}; //ANTIRREBOTE
		columna = EXTI -> PR & (0XF000); // SE GUARDA EN COLUMNA EL PR QUE SE ACTIVA
		EXTI -> PR |= (0XF000); //BANDERA
			
		switch(columna){
			case 0x1000://SE PRESIONO LA COLUMNA 0.
				if(filas == 0){numero = 1;}
				else if(filas == 1){numero = 4;}
				else if(filas == 2){numero = 7;} 
				else if(filas == 3){} //TECLA ON O * = CLEAR
			break;
			case 0x2000:
				if(filas == 0){numero = 2;}
				else if(filas == 1){numero = 5;}
				else if(filas == 2){numero = 8;} 
				else if(filas == 3){numero = 0;}
			break;
			case 0X4000:
				if(filas == 0){numero = 3;}
				else if(filas == 1){numero = 6;}
				else if(filas == 2){numero = 9;} 
				else if(filas == 3){igual = 1;} //TECLA IGUAL
			break;
			case 0x8000:
				if(filas == 0){numero = 11;} // TECLA A = RESTA
				else if(filas == 1){numero = 12;} // TECLA B = MULTIPLICACION
				else if(filas == 2){numero = 13;} // TECLA C = DIVISION
				else if(filas == 3){numero = 10;} // TECLA D = SUMA
			break;
		}
		conteo++;
		if(conteo == 3){conteo = 0;}
		
		numdis[posicion] = numero + 1; // CADA VEZ QUE SE PRESIONE UNA TECLA EL VALOR SE INGRESA EN UN ARRAY VARIANDO LAS POSICIONES DE CENTENAS DECENAS Y UNIDADES
		posicion++;
		
		if(numero >= 10){
			if(numero == 10){operacion = 1;} //SUMA
			if(numero == 11){operacion = 2;} //RESTA
			if(numero == 12){operacion = 3;} //MULTIPLICACION
			if(numero == 13){operacion = 4;} //DIVISION
		}

		if(numero <= 9){ // ASIGNACION DE LOS DOS OPERANDOS ANTES Y DESPUES DE LA OPERACION SELECCIONADA
			if(conteo == 1){
				decenas = numero;
			}
			if (conteo == 2){
				unidades = numero;
			}
			if(operacion == 0){ //PRIMER OPERANDO
				x = (decenas * 10 + unidades);
			}else if (operacion >= 1){ //SEGUNDO OPERANDO
				y = (decenas * 10 + unidades);
			}
		}		
	}
}

void desEnteros(int resultado){ // DESCOMPONER ENTEROS
	resDisplayE[0] = resultado / 1000;	
	resDisplayE[1] = (resultado % 1000) / 100;
	resDisplayE[2] = (resultado % 100) / 10;
	resDisplayE[3] = (resultado % 10);	
	
	if(negativo == 1){
		resDisplayE[0] = 11;
		negativo = 0;
	}
}

void desDecimales(int resultado){ //DESCOMPONER DECIMALES
	resDisplayD[0] = resultado / 10000;
	resDisplayD[1] = resultado / 1000;	
	resDisplayD[2] = (resultado % 1000) / 100;
	resDisplayD[3] = 14;
	resDisplayD[4] = (resultado % 100) / 10;
	resDisplayD[5] = (resultado % 10);	
	
	if(negativo == 1){
		resDisplayD[0] = 11;
		negativo = 0;
	}
}

////////////////////FUNCION PRINCIPAL////////////////////
int main(void) {
	RCC -> AHB1ENR |= 0X5A; //PUERTOS B, D, E, G 
	RCC -> APB2ENR |= 0X4000;
	
	GPIOE -> MODER = 0X555555; //LCD
	GPIOE -> OTYPER = 0X0;
	GPIOE -> OSPEEDR = 0X555555;
	GPIOE -> PUPDR = 0X555555;
	
	GPIOB -> MODER = 0X10004001; //LED STM
	GPIOB -> OTYPER = 0X0;
	GPIOB -> OSPEEDR = 0X10004001;
	GPIOB -> PUPDR = 0X10004001;

	GPIOD -> MODER |= 0X55; //PD0-PD3(SALIDAS) PD12-PD15(ENTRADAS EXTI)
	GPIOD -> OTYPER |= 0X0; 
	GPIOD -> OSPEEDR |= 0X55555555; //VELOCIDAD MEDIA
	GPIOD -> PUPDR |= 0XAA000055; //SALIDAS EN PULL-UP. ENTRADAS EN PULL-DOWN
	
	SYSCFG -> EXTICR[3] = 0X3333; //PINES 12, 13, 14, 15 PUERTO D	
	EXTI -> IMR = 0XF0FF; // PINES 12-15 EXTI
	EXTI -> RTSR = 0XF0FF; //FLANCO DE SUBIDA
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	
	//BOTONES 
	SYSCFG -> EXTICR[0] = 0X6666; //PINES 0, 1, 2, 3 PUERTO G
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI3_IRQn);
	
	//BOTONES ADICIONALES RESET Y LCD
	SYSCFG -> EXTICR[1] = 0X6666;
	NVIC_EnableIRQ(EXTI4_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 10);
	
	//CARGAR DATOS DE LA SENO 
	comando_lcd(cgram);
	for(int i = 0; i < 8; i++){
		dato_lcd(sen1[i]);
	}
	for(int i = 0; i < 8; i++){
		dato_lcd(sen2[i]);
	}
	for(int i = 0; i < 8; i++){
		dato_lcd(sen3[i]);
	}
	for(int i = 0; i < 8; i++){
		dato_lcd(sen4[i]);
	}
	
	//INCIAR LCD
	comando_lcd(clear);
	comando_lcd(home);
	comando_lcd(set);
	comando_lcd(disp_on);
	comando_lcd(mode_set1);
	operacion = 0;
	while(1){
		
		//MOSTRAR FUNCION SENOIDAL
		if(funcionSeno == 1){
			for(int j = 0; j < 16; j=j+4){
				comando_lcd(ddram1+j);
				dato_lcd(0x00);
				comando_lcd(ddram1+j+1);
				dato_lcd(0x01);
				comando_lcd(ddram2+j+2);
				dato_lcd(0x02);
				comando_lcd(ddram2+j+3);
				dato_lcd(0x03);
				for(int tiempo = 0; tiempo < 100000; tiempo++){};
			}
		}else{
		
		//BARRIDO DE FILAS DEL TECLADO
		switch(filas){
			case 0:
				GPIOD -> ODR = (1UL << 0); //0001 FILA 0 ACTIVA;
			break;
			case 1:
				GPIOD -> ODR = (1UL << 1); //0010 FILA 1 ACTIVA;
			break;
			case 2:
				GPIOD -> ODR = (1UL << 2); //0100 FILA 2 ACTIVA;
			break;
			case 3:
				GPIOD -> ODR = (1UL << 3); //1000 FILA 0 ACTIVA;
			break;
		}
		
		//CALCULADORA LCD//
		if(aux == 0){
			comando_lcd(w_linea1);
			for (int e = 0; e < 5; e++){
				dato_lcd(display[numdis[e]]); //MOSTRAR INGRESO DE OPERANDOS DINAMICO
			}
			for(int w=0; w<1000; w++);
		}else if(aux == 1){
			if(operacion == 5){ //MOSTRAR LETRAS SEN
				comando_lcd(w_linea1);
				for(int i = 0; i <= LENGHT - 1; i++){
					dato_lcd(seno[i]);
				}
				seno[4] = display[numdis[0]];
				seno[5] = display[numdis[1]];
			}
			if(operacion == 6){ //MOSTRAR LETRAS COS
				comando_lcd(w_linea1);
				for(int i = 0; i <= LENGHT - 1; i++){
					dato_lcd(coseno[i]);
				}
				coseno[4] = display[numdis[0]];
				coseno[5] = display[numdis[1]];
			}
			if(operacion == 7){ //MOSTRAR LETRAS TAN
				comando_lcd(w_linea1);
				for(int i = 0; i <= LENGHT - 1; i++){
					dato_lcd(tangente[i]);
				}
				tangente[4] = display[numdis[0]];
				tangente[5] = display[numdis[1]];
			}
			for(int w=0; w<1000; w++);
		}
		
		if(igual != 0){ 
			switch(operacion){
				case 1: //SUMA
					resultado = x + y;
				  desEnteros(resultado);
				break;
				
				case 2: //RESTA
					if(x < y) {
						negativo = 1;
						resultado = y -x;
					}
					if(x > y){
					resultado = x - y;
					}
				  desEnteros(resultado);
				break;
				
				case 3: //MULTIPLICACION
					resultado = x * y;
				  desEnteros(resultado);
				break;
				
				case 4: //DIVISION
					if(y != 0){
						resultado = (x * 100) / y;
						desDecimales(resultado);
					}else{
						error = 1;
					}
				break;
					
				case 5: //SENO
					resultado = sin((double)((y * pi) / 180)) * 100;
					if (resultado < 0){
						negativo = 1;
						resultado = resultado * - 1;
					}
					desDecimales(resultado);
				break;
					
				case 6: //COSENO
					resultado = cos((double)((y * pi) / 180)) * 100;
					if (resultado < 0){
						negativo = 1;
						resultado = resultado * - 1;
					}
					desDecimales(resultado);
				break;
					
				case 7: //TANGENTE
					if (y != 90){
						resultado = tan((double)((y * pi) / 180)) * 100; //FUNCION TANGENTE
						if (resultado < 0){
							negativo = 1;
							resultado = resultado * - 1;
						}
						desDecimales(resultado);
					}
				else{
					error = 1;
				}
				break;
			}
		}
		
		if (igual == 1){
			if(error == 0){
				if(operacion == 1 || operacion == 2 || operacion == 3){
						comando_lcd(w_linea2 + 12);
						
					if(resultado == 0){//CERO
						for (int t = 0; t < 3; t++){							
							if(resDisplayE[t]==0){
								dato_lcd(display[resDisplayE[t]]);
							}
						}
						dato_lcd(display[resDisplayE[3] + 1]);						
					}
					
					else if(resultado>0 && resultado<10){ //1 CIFRA
						for (int t = 0; t < 4; t++){
							if(resDisplayE[t]==0){
								dato_lcd(display[resDisplayE[t]]);
							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
						}					
					}
					
					if(resultado>9 && resultado<100){ //2 CIFRAS
						for (int t = 0; t < 3; t++){
							if(resDisplayE[t]==0){
								dato_lcd(display[resDisplayE[t]]);
							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
						}	
						dato_lcd(display[resDisplayE[3] + 1]);
					}
					
					if(resultado>99 && resultado<1000){//3 CIFRAS
						for (int t = 0; t < 2; t++){
							if(resDisplayE[t]==0){
								dato_lcd(display[resDisplayE[t]]);
							}else{dato_lcd(display[resDisplayE[t] + 1]);}			
						}	
						dato_lcd(display[resDisplayE[2] + 1]);
						dato_lcd(display[resDisplayE[3] + 1]);
					}
					
					if(resultado>999 && resultado<10000){//4 CIFRAS
						if(resDisplayE[0]==0){
							dato_lcd(display[resDisplayE[0]]);
						}else{dato_lcd(display[resDisplayE[0] + 1]);}			
						dato_lcd(display[resDisplayE[1] + 1]);
						dato_lcd(display[resDisplayE[2] + 1]);
						dato_lcd(display[resDisplayE[3] + 1]);										
					}
					
				}else{
					if(operacion == 5 || operacion == 6 || operacion == 7){
						numdis[2] = 0;
						dato_lcd(display[numdis[2]]);
					}
					comando_lcd(w_linea2 + 10);
					if(resultado==0){//				000.00
					if(resDisplayE[0]==0 && resDisplayE[1]==0){
						dato_lcd(display[resDisplayE[0]]);
						dato_lcd(display[resDisplayE[1]]);
					}
					dato_lcd(display[resDisplayD[2] + 1]);					
					dato_lcd(display[resDisplayD[3] + 1]);
					dato_lcd(display[resDisplayD[4] + 1]);
					dato_lcd(display[resDisplayD[5] + 1]);					
				}
				
				if(resultado<100){//				xx0.01 - xx0.09					
					if(resDisplayD[0] == 0){
						dato_lcd(display[resDisplayD[0]]);
					}else{dato_lcd(display[resDisplayD[0] + 1]);}
					
					dato_lcd(display[resDisplayD[1]]);
					dato_lcd(display[resDisplayD[2] + 1]);
					dato_lcd(display[resDisplayD[3] + 1]);
					dato_lcd(display[resDisplayD[4] + 1]);
					dato_lcd(display[resDisplayD[5] + 1]);	
				}
				  
					if(resultado>99){//				0xx.01 - 0xx.09					
						if(resDisplayD[0] == 0){
							dato_lcd(display[resDisplayD[0]]);
						}else{dato_lcd(display[resDisplayD[0] + 1]);}
						if(resDisplayD[1] == 0){
							dato_lcd(display[resDisplayD[1]]);
						}else{
							dato_lcd(display[resDisplayD[1] + 1]);
						}
						if(resDisplayD[2] == 0){
							dato_lcd(display[resDisplayD[2]]);
						}else{
							dato_lcd(display[resDisplayD[2] + 1]);
						}
						dato_lcd(display[resDisplayD[3] + 1]);
						dato_lcd(display[resDisplayD[4] + 1]);
						dato_lcd(display[resDisplayD[5] + 1]);	
					}
				}
			}else{
				if(operacion == 7){
					comando_lcd(w_linea1);
					dato_lcd(display[numdis[2] = 0]);
				}
				comando_lcd(w_linea2 + 6);
				for(int h = 0; h < 10; h++){
					dato_lcd(frase_error[h]);
				}
			}		
			igual = 0;
			error = 0;
		}
	}
	}
}
//FIN



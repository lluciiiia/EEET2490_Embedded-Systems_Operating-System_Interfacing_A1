// -----------------------------------main.c -------------------------------------
#include "../header/gpio.h"
#include "../header/uart0.h"


void main(){
    // intitialize UART
    uart_init();
    
    // say hello
    uart_puts("Hello World\n");
    led_blink();


    // echo everything back 
    while(1) {
    	//read each char
    	char c = uart_getc();

    	//send back twice
    	uart_sendc(c);
    	uart_sendc(c);
    }
}

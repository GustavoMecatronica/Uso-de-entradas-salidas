#include<16F887.h>
#fuses XT, NOWDT, MCLR
#use delay(internal=4M)
#byte PORTA=5
#byte PORTB=6

#define S0 PORTA,0
#define LED0 PORTB,0
#define LED1 PORTB,1
#define LED2 PORTB,2
int contador=0;
int condicion=0;
int cond1=0;
void main(){
set_tris_a(0xFF);
set_tris_b(0x00);
portb=(0x00);//iniciamos el puerto b en 0, apagado.

while(true){
      
      if(bit_test(S0)){
         contador++;
            if(contador==4)//reset de contador
            contador=0;
      }
      
      switch(contador){
         case 1://encender LED0
            if(condicion!=1){      
               for(int i=0;i<=2;i++){
                bit_set(LED0);
                delay_ms(500);
                bit_clear(LED0);
                delay_ms(500);
               } 
               condicion=1;
            }
            break;
         case 2:// encender LED1
            if(condicion!=2){      
               while(cond1<=2){
                  bit_set(LED1);
                  delay_ms(500);
                  bit_clear(LED1);
                  delay_ms(500);
                  cond1++;
                  }
               condicion=2;
               cond1=0;
            }   
            break;
         case 3://encender LED2
            if(condicion!=3){      
               do{
                  bit_set(LED2);
                  delay_ms(500);
                  bit_clear(LED2);
                  delay_ms(500);
                  cond1++;
                  }while(cond1<=2);
                  condicion=3;
                  cond1=0;
            }
            break;
         default:
         portb=0x00;
            break;
      }
   }
}

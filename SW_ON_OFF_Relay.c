/* Progame SW1 ON RELAY1
BY HS4QWC 27/1/2021 
YOUTUBE : 4Qchannal */ 

#include <16f84a.h>
#fuses NOWDT,NOPROTECT,XT
#use delay(clock=4000000)// 4 MHZ
#use fast_io(a)
#use fast_io(b)

#BYTE RA=5
#BYTE RB=6

#BIT SW1=RA.0 // input SW1=Port_A0
#BIT RL1=RB.2 // output RL1=Port-B2

short F_SW1;  // value F_SW1 /togle

void main()
{
   set_tris_a(0xff); // set input portA all
   set_tris_b(0x03); // set input port B0,B1=input

   RL1 = 0;
     
 while(TRUE)
    {   
        if(!SW1 && !F_SW1)//-----------------//ch1
        {
          RL1 =~ RL1;  // togle 
          F_SW1 = 1;
          delay_ms(10);
        } 
        if(SW1 && F_SW1)  
          {
            F_SW1 = 0;
            delay_ms(10);
          } 
    } //END while
} // END MAIN

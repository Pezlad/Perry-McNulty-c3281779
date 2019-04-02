/* Main function of the C program. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void operation(float a, float b, char oper);

int main()
{
    char opt; //option selection 
    
    printf("Please select an option: \n");
    printf("a) Encrypt a message with a rotation cipher given the message text and rotation amount \n");
    printf("b) Decrypt an encrypted message with a rotation cipher given cipher text and rotation amount\n");
    printf("c) Encrypt a message with a substitution cipher given message text and alphabet substitution\n");
    printf("d) Decrypt an encrypted message with a substitution cipher given cipher text and substitutions\n");
    printf("e) Encrypt a message with a rotation cipher given cipher text only\n");
    printf("f) Decrypt an encrypted message with asubstitution cipher given cipher text only \n\n");
         printf("Selection: ");
             scanf("%c", &opt);
                operation(opt);
//printf("%c", opt); // testing option input 


    return 0;
}
  void operation(char opt){
      
   
      switch(opt)
   {
       float resulta, resultb, resultc, resultd, resulte, resultd, resultna;
       
             case 'a':
                   
                         break;
             case 'b':
                     
                          break;
             case 'c':
                    
                         break;
            case 'd':
                    
                          break;
            case 'e':
                    
                         break;
            case 'f':
                    
                         break;
            // input doesnt match any case then....
            default:
                 printf(" ERROR! Operator incorrect");
                 
               return;
   }
  }
                 
          

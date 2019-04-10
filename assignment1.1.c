
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int operation(char opt, char str[], char rotA );

int main()
{
    char opt, str[128], rotA;//option selection 
     //char opt;
    FILE *input;
    FILE *output;
    input = fopen("input.txt", "r+"); // read only 
    output = fopen("output.txt", "w"); // write only
    
    
    printf("Please select an option: \n");
    printf("a) Encrypt a message with a rotation cipher given the message text and rotation amount. \n");
    printf("b) Decrypt an encrypted message with a rotation cipher given cipher text and rotation amount.\n");
    printf("c) Encrypt a message with a substitution cipher given message text and alphabet substitution.\n");
    printf("d) Decrypt an encrypted message with a substitution cipher given cipher text and substitutions.\n");
    printf("e) Decrypt a message with a rotation cipher given cipher text only.\n");
    printf("f) Decrypt an encrypted message with a substitution cipher given cipher text only. \n\n");
        // printf("Selection:\n ");
         //    scanf("%c", &opt);
 
    if (input==NULL) {
      printf("error\n");
    }
     else {
        //fscanf(input0, " %c", &opt);

        fscanf(input, "%127[^\n]\n%127[^\n]\n%127[^\n]", &opt, str, &rotA);
        printf("1:%c\n", opt);
        printf("2:%s\n", str);
        printf("3:%c\n", rotA);
       //fclose(input);
       
    }
             
     operation(opt, str, rotA);
    return 0;
}
  int operation (char opt, char str[], char rotA){
      
 // char str[100];
  char lett;
         int x=0; 
       // int rotA=4;
           
      switch(opt)
   {
       
        case 'a':
           
	              
            for(x; str[x] != '\0';  ++x){
                lett = str[x];
                if((lett >= 'a') && (lett <= 'z')){   // encryption for lower case 
                    lett = lett + rotA;
                    
                    while(lett > 'z'){
                        lett = lett - 'z' + 'a' - 1;
                    }
                    str[x] = lett;
                }
                else if(lett >= 'A' && lett <= 'Z'){  // Encrption for uppercase
                    lett = lett + rotA;
    
                    while(lett > 'Z'){
                        lett = lett - 'Z' + 'A' - 1;
                    }
                    str[x] = lett;
                }
            }
            
            printf("Encrypted message: %s\n", str);
            
            return 0;
            break;
            
        case 'b':
                    for(x; str[x] != '\0'; ++x){
		                lett = str[x];
		
		                if(lett >= 'a' && lett <= 'z'){
		                	lett = lett - rotA;
			                    
			            while(lett < 'a'){
			            	lett = lett + 'z' - 'a' + 1;
			}
		            	str[x] = lett;
		}
		            else if(lett >= 'A' && lett <= 'Z'){
			                lett = lett - rotA;
			                    
			                    
			        while(lett < 'A'){
			            	lett = lett + 'Z' - 'A' + 1;
			}
			str[x] = lett;
			               
		}
	}
	
                	printf("Decrypted message: %s", str);
	                return 0;
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
                 printf(" ERROR! option incorrect/n");
                 
               return 0;
   }
   }
  
                 
             

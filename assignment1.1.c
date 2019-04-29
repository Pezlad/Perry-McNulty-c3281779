//1003 Programming Assignment 1 - English Text Ciphers
//Perry McNulty c3281779
/*This program uses stdin and scanf as its input method, also has each cipher working in
 its own funtion */
#include <stdio.h>                                                              //#include directives tell the preprocessor where to find the 
#include <stdlib.h>                                                             //meanings of the identifiers used in the program
#include <string.h>
#include <math.h>
void upper_string(char str[]);                                                  //defining the function for converting from lower case to upper case
int RotationEncryption(char opt, char str[], char lett, int x);                 //defining the function for rotation encryption
int RotationDecryption(char opt, char str[], char lett, int x);                 //defining the function for rotation decryption
int SubstitutionEncryption(char opt, char str[], char lett, int x);             //defining the function for substitution encryption
int SubstitutionDecryption(char opt, char str[], char lett, int x, int j);      //defining the function for substitution decryption

/*Main funtion (main body of the program)
 *input: opt- option selection to select a program, str[500]- message the user wants to encryt or decypt, lett- indiviual letters in the message
 *output: function returns 0 and gathers information ffrom the user for use in the rest of the program. */
int main()
{
    char opt, str[500], lett;                                                   //Character opt (user selected option), string str(for the users message) and character lett (indivdual letters of string str)
    int x=0, j;                                                                 //variables x and j used in multiple for loops
    
  
    //Selection menu//
    printf("Please select an option: \n");                                                                          //This menu is presented to the user to allow them to decide which part of the program they would like to run
    printf("a) Encrypt a message with a rotation cipher given the message text and rotation amount. \n");           //*
    printf("b) Decrypt an encrypted message with a rotation cipher given cipher text and rotation amount.\n");      //*
    printf("c) Encrypt a message with a substitution cipher given message text and alphabet substitution.\n");      //*
    printf("d) Decrypt an encrypted message with a substitution cipher given cipher text and substitutions.\n");    //*
    printf("e) Decrypt a message with a rotation cipher given cipher text only.\n");                                //*
    printf("f) Decrypt an encrypted message with a substitution cipher given cipher text only. \n\n");              //*
        
         printf("Selection: \n ");                                              //Propts user to make their selection
             scanf("%c", &opt);                                                 //Saves users selection to the variable c
         printf("Enter message: \n");                                           //Propts user to enter their desiered encryption/decyrption message
           scanf(" %[^\n]s", str);                                              //Saves users message to variable string str 
        upper_string(str);                                                      //Directs the program to the lower case to upper case convertor taking the string down with it 
  
  /*Switch Statement
  Takes the opt input from the users selection from the selection menu and directs the program to the selected function*/
      switch(opt)
   {
       
        case 'a':                                                               //'a' directs the program to the Rotation Encryption cipher 
           RotationEncryption(opt, str, lett, x);                               //Function name and variables that are being taken down to be used in the function 
                          break;                                                //Program breaks and moves out of the switch statement down to the desired function
        case 'b':
            RotationDecryption(opt, str, lett,  x);                             //Function name and variables that are being taken down to be used in the function 
                          break;                                                //Program breaks and moves out of the switch statement down to the desired function
            case 'c':
            SubstitutionEncryption(opt, str, lett,  x);                         //Function name and variables that are being taken down to be used in the function 
                         break;                                                 //Program breaks and moves out of the switch statement down to the desired function
            case 'd':
                    SubstitutionDecryption(opt, str, lett,  x, j);              //Function name and variables that are being taken down to be used in the function 
                          break;                                                //Program breaks and moves out of the switch statement down to the desired function
            case 'e':
                    
                         break;                                                 //Program breaks and moves out of the switch statement down to the desired function
            case 'f':
                    
                         break;                                                 //Program breaks and moves out of the switch statement down to the desired function
            
            default:                                                            //If input doesnt match any state then the swtitch statement reverts to default 
                 printf(" ERROR! option incorrect/n");                          //Error message is preseted to the user when the default selection is triggered 
   }
    return 0;
}
   /*Lower to upper case string conversion function
    *Inputs- users message (string of characters)*/
   void upper_string(char str[]) {                                              //function name along with variables being brought down from the main function 
       
   int c = 0;                                                                   //Integer declaration for later use in lower to upper case conversion 
   
   while (str[c] != '\0') {
      if (str[c] >= 'a' && str[c] <= 'z') {                                     //while the message string hasnt ended run the if statement
         str[c] = str[c] - 32;                                                  //if the message string is between 'a' and 'z' subract 32 from the all current letters 
      }
      c++;                                                                      //add 1 to c to keep the loop going until limits of while statement are reached 
   }
}

   /*Rotation Encryption function
    *Function encrypts the users message by rotating the alphabet the amount of times the user enters
    *Inputs- users message (string of characters), rotation key 
    *Outputs- Function returns 0 and displays the encrypted message to the user
    */
   int RotationEncryption(char opt, char str[], char lett, int x){              //function name along with variables being brought down from the main function 
       
      int rotA;                                                                 //integer for rotation amount set by user 
       printf("Enter key: \n");                                                 //Prompts user to enter rotation amount (key)
            scanf(" %d",&rotA);                                                 //saves users rotation amount to int rotA
   for(x; str[x] != '\0';  ++x){                                                //loop through characters in input
                lett = str[x];                                                  //assign str[x] to lett
            
               if ((lett >= 'A') && (lett <= 'Z')){                             
                    lett = lett + rotA;                                         //if the letter (lett) is between 'A' and 'Z' add the rotation amount (key) to the original letter 
    
                    while(lett > 'Z'){
                        lett = lett - 'Z' + 'A' - 1;                            //While 'Z' is greater then 0 subtract 'Z' add 'A' and subtract 1 all from the current letter 
                    }
                   str[x] = lett;                                               //assign the str[x] to lett and the for loop will repeat
               }
            }
            
            printf("Encrypted message: %s\n", str);                             //Display the encrpted message to the user 
            
            return 0;                                                           //function returns 0
   }
   
   /*Rotation Decryption Function
    *Function decrypts the users encrypted message by rotating the alphabet the amount of times the user enters 
    *Inputs- users message (string of characters), rotation key  
    *Outputs- Function returns 0 and displays the decrypted message to the user
    */
   int RotationDecryption(char opt, char str[], char lett, int x){              //function name along with variables being brought down from the main function 
       
       int rotA;                                                                //integer for rotation amount set by user 
       printf("Enter key: \n");                                                 //Prompts user to enter rotation amount (key)
            scanf(" %d",&rotA);                                                 //saves users rotation amount to int rotA
     for(x; str[x] != '\0'; ++x){                                               //loop through characters in input
		                lett = str[x];                                          //assign str[x] to lett
		
		             
		            if((lett >= 'A') && (lett <= 'Z')){ 
			                lett = lett - rotA;                                 //if the letter (lett) is between 'A' and 'Z' add the rotation amount (key) to the original letter 
			                    
			                    
			        while(lett < 'A'){
			            	lett = lett + 'Z' - 'A' + 1;                        //While letter is less  then 'A' add 'Z' subtract 'A' and add 1 all to the current letter 
			}
			str[x] = lett;                                                      //assign the str[x] to lett and the for loop will repeat
			               
		}
	}
                	printf("Decrypted message: %s\n", str);                     //Display the decrpted message to the user
	                return 0;                                                   //function returns 0
   }
   
    /*Substitution Encryption Function
    *Function encrypts the users message into the users substitution alphabet
    *Inputs- users message (string of characters), substitution alpahbet 
    *Outputs- Function returns 0 and displays the encrypted message to the user
    */
    int SubstitutionEncryption(char opt, char str[], char lett, int x){         //function name along with variables being brought down from the main function 
        char subalphabet[500];
     printf("Enter Substitution Alphabet (26 characters): \n");                 //Prompts user to enter the substitution alphabet
           scanf(" %[^\n]s", subalphabet);                                      //saves users alphabet to subalphabet
    str[strlen(str)] = 0;                                                       //remove the newline, \n 
    int count = strlen(str);                                                    //get the string length

    char message[count];                                                        //output string
    for(x; x < count; x++) {                                                    //loop through characters in input
        int index = ((int) str[x]) - 'A';                                       //Subtract 'A' from the current character to get the index in the cipher
        if(index < 0) {
            message[x] = ' ';                                                   // if index < 0, account for spaces by putting a 'space'
        }
        else {
            message[x] = subalphabet[index];                                    //else, assign the output[i] to the ciphertext[index]
        }
    }
    message[count] = 0;                                                         //0-terminate the string

    printf("Encrypted message: %s\n", message);                                 //Display the encrpted message to the user
    return 0;                                                                   //function returns 0
}

    /*Substitution Decryption Function
    *The function decrpts the users encrypted message back into the original message
    *Inputs- Encrypted message (string of characters), substitution alphabet 
    *Outputs- Function returns 0 and the encrypted message is displayed to the user 
    */
    int SubstitutionDecryption(char opt, char str[], char lett, int x, int j){  //function name along with variables being brought down from the main function 
        char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; //Saves normal aphabet into alphabet 
        char subalphabet[26];                                                   //To save users substitutional alphabet into 
        char message[255];                                                      //To assign users message to 
        int c = 0;                                                              //For use in the lower to uppercase conversion loop
        
    printf("Enter Substitution alphabet: \n");                                  //Prompts user to enter the substitution alphabet
           scanf(" %[^\n]s", subalphabet);                                      //saves users alphabet to subalphabet
 
   //lower case to upper case for the substitution alpahbet//
    while (subalphabet[c] != '\0') {                                           
      if (subalphabet[c] >= 'a' && subalphabet[c] <= 'z') {                     //while the subalphabet string hasnt ended run the if statement
         subalphabet[c] = subalphabet[c] - 32;                                  //if the subalphabet string is between 'a' and 'z' subract 32 from the all current letters 
      }
      c++;                                                                      //add 1 to c to keep the loop going until limits of while statement are reached 
   }


    strcpy(message,str);                                                        //standard identifier from string.h libary that copies str to message 
   
    int count = strlen(message);                                                //standar identifier from string.h that computes the length of the string
        for(x; x<count; x++){                                                   // loop through characters in input
             for(j=0; j<26; j++)                                                // loop through characters in input
{
        if(message[x] == subalphabet[j])
{
        message[x] = alphabet[j];                                               //if message is equal to subalphabet, Assign the message[x] to the alphabet[j]
        break;                                                                  //Break from if statement and move on to next part of code 
}
}
}

        printf("Decrypted message: %s\n",message);                              //Display the decrpted message to the user
        return 0;                                                               //function returns 0
}

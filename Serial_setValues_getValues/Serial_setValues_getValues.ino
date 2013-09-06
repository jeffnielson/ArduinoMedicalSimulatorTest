/* Simple Serial ECHO script : Written by ScottC 06/07/2012 */
/* Stage 4: Double doubler */

/* Global variables needed for programming workflow
   ------------------------------------------------------
   byteRead: holds the value being read from the COM port
   num1: holds the number before the decimal point
   num2: holds the number after the decimal point
   complNum: holds the complete number (before multiplation)
   answer: holds the final value after multiplication
   counter: is used to convert num2 to the number after the decimal
   numOfDec: counts the numbers after the decimal point
   mySwitch: enables the switch between num1 and num2  */
   
   byte byteRead;
   double num1, num2;
   double complNum,answer,counter;
   int numOfDec;
   boolean mySwitch=false;




  int pulse = 70;
  int pulseStrength = 2;
  int Sbp = 120;
  int Dbp = 80;
  int RR = 16;


   void setup() {                
/* Turn the Serial Protocol ON and 
   initialise num1 and num2 variables.*/
     Serial.begin(9600);
     num1=0;
     num2=0;
     complNum=0;
     counter=1;
     numOfDec=0;
   }

   void loop() {
/*  check if data has been sent from the computer: */
     while (Serial.available()) {
     /* read the most recent byte */
        byteRead = Serial.read();
    
       //listen for numbers between 0-9
       //this will take any number that is entered and add it to the end of the existing number sequence
       //i am not sure how it deals with decimals
       if(byteRead>47 && byteRead<58){
          //number found
      
          /* If mySwitch is true, then populate the num1 variable
          otherwise populate the num2 variable num2 is the decimal part*/
          if(!commandSet){
            num1=(num1*10)+(byteRead-48);
          }else{
            num2=(num2*10)+(byteRead-48);
         
         /* These counters are important they keep track of number of decimal places*/
            counter=counter*10;
            numOfDec++;
          }
       }
       
       //assemble command
       if (byteRead>64 && byteRead<128) {
         
         
         
         
       }
       
       //look for commands
       //this needs to be able to recognize if a command says "s HR = 120".  s is shorthand for set.  g is shorthand for get. response will be xml that we write.
       //$asdf|132! (36 124 33)
       //if(byteRead==36)
       
       //look for data
       
       
       //look for end of command (submit request)
       
    
    /*Listen for an ! (byte code 33) 
      */
      if(byteRead==33){
   /* Create the double from num1 and num2 */
      //complNum=num1+(num2/(counter));
      
   /* Multiply the double by 2 */   
      //answer=complNum*2;
      
   /* Send the result to the Serial Monitor */   
      //Serial.print(complNum,numOfDec);
      Serial.print("command:");
      //Serial.println(answer,numOfDec);
      Serial.print(
      
   /* Reset the variables for the next round */
      num1=0;
      num2=0;
      complNum=0;
      counter=1;
      mySwitch=false;
      numOfDec=0;
      
  /* Listen for the decimal point (byte code 46). This is
     used as a delimiter to help define num1 from num2 */  
     }else if (byteRead==124){
        commandSet=true;
     }
   }
 }

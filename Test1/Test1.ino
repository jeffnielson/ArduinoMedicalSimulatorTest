#include <LiquidCrystal.h>

// Buffer to store incoming commands from serial port
String inData;
String command;
String modifier;

int HR = 70;
int RR = 12;
int Leye = 4;
int Reye = 5;

//LiquidCrystal lcd(RS, enable, d4, d5, d6, d7);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);




void setup() {
    Serial.begin(9600);
    Serial.println("Serial conection started, waiting for instructions...");
}

void loop() {
    while (Serial.available() > 0)
    {
        char received = Serial.read();
        if(!(received == '!' || received == '$' || received == '|' ))
        {
        inData += received; 
        }

        // Process message when new line character is received
        if (received == '!')
        {
         log("received modifier: "); 
         log(inData);
         modifier = inData;
         inData = "";
         
         if(command.length())
         {
         log("performing command");
         
         if(command == "HR")
         {
           setHR(modifier);
         } 
           else if(command == "logVitals")
         {
           logVitals();
         
         
         
         }
         else{
           log("the command is invalid: " + command);
         }
         }else
         {
         log("there was no command");
         }
        
        }
        if (received == '|')
        {
         log("received command: "); 
         log(inData);
         command = inData;
         inData = "";
        }
         if (received == '$')
        {
         log("command start (clearing junk): "); 
         
         if(inData.length())
         {
           Serial.println(inData);
           log("junk found");
           log(inData);
         }
         inData = "";
         
        }
        
        /*if (received == '\n')
        {
            Serial.print("Arduino Received: ");
            Serial.print(inData);

            // You can put some if and else here to process the message juste like that:

            if(inData == "+++\n"){ // DON'T forget to add "\n" at the end of the string.
              Serial.println("OK. Press h for help.");
            }   


            inData = ""; // Clear received buffer
        }
        */
        
    }
    
}

void log(String s) {
  
  Serial.print("....................log: ");
  Serial.println(s);
  
}
void setHR(String s) {
  char buffer[10];
s.toCharArray(buffer, 10);
int tempHR= atoi(buffer);
//long HR= atol(buffer);
//unsigned long HR= strtoul(buffer, NULL, 16);

  //int tempHR = atoi(s);
  HR = tempHR;
  log("HR submitted");
  String temp = String(HR);
  log(temp);
 
  
}

void logVitals() {
 log( "HR="); 
 String temp = String(HR);
 log(temp);
 
  
}

void lcdVitals() {
 //this should display vitals on lcd screen in the following format
  //"HR SBP/DBP RR" "96 124/23 14"
}

void lcdLog(String s) {
  //sends a string to the lcd screen
}



typedef struct Timer 
{
    unsigned long start;
    unsigned long timeout;
};

char TimerExpired ( struct Timer * timer ) 
{
    if ( millis () > timer->start + timer->timeout ) 
        return true;

    return false;    
}

void TimerStart ( struct Timer * timer ) 
{
    timer->start = millis ( );
    timer->timeout = timer->timeout;
}

//Display task running every 3000 milliseconds 
//Timer timerDisplay = { 0, 3000 };
//Keyboard task running every 100 milliseconds 
//Timer timerKeyboard = { 0, 100 };

//setup the timers that do the commands
//Timer tPulse;
//Timer tHeartSounds;
//Timer tLungSounds;
//Timer tLEye;
//Timer tREye;
//Timer tLCD;
//Timer tGeneric;
//Timer tSerial; 
//
//sets up the on board light to be the generic pulse
int pBoardPulse = 13;
boolean bBoardPulse = true;

//(initial frequncy per minute)
unsigned long  iPulse = 60; 
unsigned long  iHeartSounds = 60;
unsigned long  iLungSounds = 16;
unsigned long  iLEye = 120;
unsigned long  iREye = 120;
unsigned long  iLCD = 120;
unsigned long  iGeneric = 60;
unsigned long  iSerial = 60;

//timer is (lastTimeItWentOff, msLaterthatItShouldGoOff)
Timer tPulse = { 0, 60000 / iPulse };
Timer tHeartSounds = { 0, 60000 / iHeartSounds };
Timer tLungSounds = { 0, 60000 / iLungSounds };
Timer tLEye = { 0, 60000 / iLEye };
Timer tREye = { 0, 60000 / iREye };
Timer tLCD = { 0, 60000 / iLCD};
Timer tGeneric = { 2, 60000/ iGeneric };
Timer tSerial = {0, 60000.0 / iSerial };


void setup (void) 
{
  
  setupGeneric();
  Serial.begin(9600);
  Serial.println("Serial conection started");
  log("Timers Initialized");
  //delay(1000);
  //log(String(tGeneric.start));
  //log(String(tGeneric.timeout));
}


//this is where pins get set up
void setupGeneric(void) 
{
  pinMode(pBoardPulse, OUTPUT);
}







void loop (void) 
{
    if ( TimerExpired ( & tPulse ) )
    {
        taskPulse ( ); 
        TimerStart ( & tPulse );
    }
    if ( TimerExpired ( & tHeartSounds ) )
    {
        taskHeartSounds ( ); 
        TimerStart ( & tHeartSounds );
    }
    if ( TimerExpired ( & tLungSounds ) )
    {
        taskLungSounds ( );
        TimerStart ( & tLungSounds );
    }
    if ( TimerExpired ( & tLEye ) )
    {
        taskLEye ( ); 
        TimerStart ( & tLEye );
    }
    if ( TimerExpired ( & tREye ) )
    {
        taskREye ( ); 
        TimerStart ( & tREye );
    }
    if ( TimerExpired ( & tLCD ) )
    {
        taskLCD ( ); 
        TimerStart ( & tLCD );
    }
    if ( TimerExpired ( & tSerial ) )
    {
        taskSerial ( ); 
        TimerStart ( & tSerial );
    }
    if ( TimerExpired ( & tGeneric ) )
    {
        //log("Starting Generic");
        taskGeneric ( ); 
        TimerStart ( & tGeneric );
        //log(String(millis()));
        //log(String(tGeneric.start));
        //log(String(tGeneric.timeout));
    }
}
    

void taskPulse ( void ) 
{
  log("woosh");
}

void taskHeartSounds ( void ) 
{
  log("lub-dub");
}

void taskLungSounds ( void ) 
{
  log("ooh-tah");
}

void taskLEye ( void ) 
{
  //log("L eye change");
}
void taskREye ( void ) 
{
  //log("R eye change");
}

void taskLCD ( void ) 
{
  //log("updating LCD");
}
void taskSerial ( void ) 
{
  //log("looking for serial input");
}
void taskGeneric ( void ) 
{
  if(bBoardPulse) {
  digitalWrite(pBoardPulse, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);    
  digitalWrite(pBoardPulse, LOW);
  delay(100);
  //bBoardPulse = !bBoardPulse;
  } else {
  }
}







void log(String s) {
  
  Serial.print("....................log: ");
  Serial.println(s);
  
}


void logVitals() {
 log( "HR="); 
 String temp = String(iPulse);
 log(temp);
 
  
}

void lcdVitals() {
 //this should display vitals on lcd screen in the following format
  //"HR SBP/DBP RR" "96 124/23 14"
}

void lcdLog(String s) {
  //sends a string to the lcd screen
}


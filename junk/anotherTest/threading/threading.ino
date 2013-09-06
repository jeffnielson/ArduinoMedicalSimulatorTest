
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
}

//Display task running every 3000 milliseconds 
//Timer timerDisplay = { 0, 3000 };
//Keyboard task running every 100 milliseconds 
//Timer timerKeyboard = { 0, 100 };

//setup the timers that do the commands
Timer tPulse;
Timer tHeartSounds;
Timer tLungSounds;
Timer tLEye;
Timer tREye;
Timer tLCD;
Timer tGeneric;
Timer tSerial; 

//(initial frequncy per minute)
int iPulse = 60; 
int iHeartSounds = 60;
int iLungSounds = 16;
int iLEye = 120;
int iREye = 120;
int iLCD = 120;
int iGeneric = 60;
int iSerial = 60;

void makeTimers (void)
{
Timer tPulse = { 0, 60000 / iPulse };
Timer tHeartSounds = { 0, 60000 / iHeartSounds };
Timer tLungSounds = { 0, 60000 / iLungSounds };
Timer tLEye = { 0, 60000 / iLEye };
Timer tREye = { 0, 60000 / iREye };
Timer tLCD = { 0, 60000 / iLCD};
Timer tGeneric = { 0, 60000 / iGeneric };
Timer tSerial = {0, 60000 / iSerial };
}


void setup (void) 
{
  makeTimers();
  log("Timers Initialized");
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
        taskGeneric ( ); 
        TimerStart ( & tGeneric );
    }
}
    

void taskPulse ( void ) 
{
}

void taskHeartSounds ( void ) 
{
}

void taskLungSounds ( void ) 
{
}

void taskLEye ( void ) 
{
}
void taskREye ( void ) 
{
}

void taskLCD ( void ) 
{
}
void taskSerial ( void ) 
{
}
void taskGeneric ( void ) 
{
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

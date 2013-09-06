
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
Timer timerDisplay = { 0, 3000 };
//Keyboard task running every 100 milliseconds 
Timer timerKeyboard = { 0, 10000 };

void setup (void) 
{
    Serial.begin(9600);
  Serial.println("Serial conection started, waiting for instructions...");
}

void loop (void) 
{
    if ( TimerExpired ( & timerDisplay ) )
    {
        taskDisplay ( ); 
        TimerStart ( & timerDisplay );
    }

    if ( TimerExpired ( & timerKeyboard ) ) 
    {
        taskKeyboard ( );
        TimerStart ( & timerKeyboard );
        log("keyboard");
        log(String(millis()));
        log(String(timerKeyboard.start));
        log(String(timerKeyboard.timeout));
    }
}

void taskKeyboard ( void ) 
{
}

void taskDisplay ( void ) 
{
}



void log(String s) {
  
  Serial.print("....................log: ");
  Serial.println(s);
  
}

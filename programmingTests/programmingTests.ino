/*
programming tests
 */
 typedef struct Timer 
{
    unsigned long start;
    unsigned long timeout;
};


// the setup routine runs once when you press reset:
void setup() {                
  
   Serial.begin(9600);
  Serial.println("Serial conection started, waiting for instructions...");
  
  unsigned long x = 333;
  int i = 333;
  
  unsigned long y = 60000.0 / x;
  Serial.println(y);
  
  Serial.println(i);
  Serial.println(60000/i);
  Serial.println(60000.0/i);
  
  Serial.println(60000.0 / x);
  Serial.println(60000 / x);
  
  Timer tGeneric = { 0, 5000/x };
  Serial.println(tGeneric.start);
  Serial.println(tGeneric.timeout);
  
}

// the loop routine runs over and over again forever:
void loop() {

}

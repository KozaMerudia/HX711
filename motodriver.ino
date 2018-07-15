
const int d1a = 2;
const int d1b = 3;
const int e1 = 4;
const int anpin = A0;
/*float st;*/
byte pwmValue1 = 0;
int ar = 1;

void setup ()
{
  pinMode(d1a, OUTPUT);
  pinMode(d1b, OUTPUT);
  pinMode(e1, OUTPUT);  
}

void loop()
{
   int i=0, j=0, raz =0;  
    if (st>5 && st<100)
    {
      j=1;
    }
    if (st>100 && st<150)
    {
      j=2;
    }
    if (st>150 && st<200)
    {
      j=3;
    }
    if (st>200)
    {
      j=4;
    }
          if (j>0)
  {
    if (j==ar)
    {
      Serial.print(" TUK "); 
      }
          if(j>ar)
          {
            raz = j - ar;
            while (i<raz)
            {
              digitalWrite(d1a, HIGH);
              digitalWrite(d1b, LOW);
              analogWrite(e1,240) ;
                  delay(2200) ;     
              
                  digitalWrite(d1a,HIGH) ;
                  digitalWrite(d1b,HIGH) ;
                  delay(1000) ;
              i++;
            }
          }
          if(j<ar)
          {
             raz = ar - j;
            while (i<raz)
            {
              digitalWrite(d1a, LOW);
              digitalWrite(d1b, HIGH);
              analogWrite(e1,240) ;
                  delay(2000) ;     
              
                  digitalWrite(d1a,HIGH) ;
                  digitalWrite(d1b,HIGH) ;
                  delay(1000) ;
              i++;
            }
          }
          analogWrite(e1,240) ;
          ar = j;
  }

}

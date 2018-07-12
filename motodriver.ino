
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
          if(j>ar)
          {
            raz = j - arr;
            while (i<raz)
            {
              digitalWrite(Dir1a, HIGH);
              digitalWrite(Dir1b, LOW);
              pwmValue1 = (analogValue1 - 512)/2;   //for change ..za edno razdelenie..
              i++;
            }
          }
          else 
          {
            raz = arr - j;
            while (i<raz)
            {
              digitalWrite(Dir1a, LOW);
              digitalWrite(Dir1b, HIGH);
              pwmValue1 = (analogValue1 - 512)/2;   //for change ..za edno razdelenie..
              i++;
            }
          }
   ar = j;
}

analogWrite(Enable1,pwmValue1);

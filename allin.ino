#include "HX711.h"

HX711 scale(5, 6);

float calibration_factor = -308; // this calibration factor is adjusted according to my load cell
float units;
float ounces;


const int d1a = 2;
const int d1b = 3;
const int e1 = 4;
const int anpin = A0;
byte pwmValue1 = 0;
int ar = 1;


void setup() {
  pinMode(d1a, OUTPUT);
  pinMode(d1b, OUTPUT);
  pinMode(e1, OUTPUT); 

  
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");

  scale.set_scale();
  scale.tare();  //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);
}

void loop() {
  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  Serial.print("Reading: ");
  units = scale.get_units(), 10;
  if (units < 0)
  {
    units = 0.00;
  }
  
  ounces = units * 0.035274;
  Serial.print(units);
  Serial.print(" grams"); 
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();
  
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 1;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 1;
  }






   int i=0, j=0, raz =0;  
    if (units>5 && units<100)
    {
      j=1;
    }
    if (units>100 && units<150)
    {
      j=2;
    }
    if (units>150 && units<200)
    {
      j=3;
    }
    /*if (units>200)
    {
      j=4;
    }*/
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

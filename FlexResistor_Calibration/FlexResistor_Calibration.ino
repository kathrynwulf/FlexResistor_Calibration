
#include <Math.h>

/*
 * 
 * 
 * 
 * 
 * 
 * 
 */

boolean isOnOff = true;
boolean isOnOff1 = isOnOff;
boolean isOnOff2 = isOnOff;
boolean isOnOff3 = isOnOff;
boolean isOnOff4 = isOnOff;
boolean isOnOff5 = isOnOff;
boolean State1 = false;
boolean State2 = false;
boolean State3 = false;
boolean State4 = false;
boolean State5 = false;

boolean joyStick = true;
boolean joyStick1 = joyStick;
boolean joyStick2 = joyStick;
boolean joyStick3 = joyStick;
boolean joyStick4 = joyStick;
boolean joyStick5 = joyStick;
int jState1 = 0;
int jState2 = 0;
int jState3 = 0;
int jState4 = 0;
int jState5 = 0;

int raw1 = 0;
int raw2 = 0;
int raw3 = 0;
int raw4 = 0;
int raw5 = 0;
int voltageIn = 5;

float voltage1Out = 0;
float Ref1 = 10000;
float R1 = 0;
float buffer = 0;

float voltage2Out = 0;
float Ref2 = 10000;
float R2 = 0;

float voltage3Out = 0;
float Ref3 = 10000;
float R3 = 0;

float voltage4Out = 0;
float Ref4 = 10000;
float R4 = 0;

float voltage5Out = 0;
float Ref5 = 10000;
float R5 = 0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  raw1 = analogRead(A0); //A0
  raw2 = analogRead(A1); //A1
  raw3 = analogRead(A2); //A1
  raw4 = analogRead(A3); //A1
  raw5 = analogRead(A4); //A1
  
  
  if(raw1) 
  {
    buffer = raw1 * voltageIn;
    voltage1Out = (buffer) / 1024.0;
    buffer = (voltageIn / voltage1Out) - 1;
    R1 = Ref1 * buffer;
  }
  if(raw2)
  {
    buffer = raw2 * voltageIn;
    voltage2Out = (buffer) / 1024.0;
    buffer = (voltageIn / voltage2Out) - 1;
    R2 = Ref2 * buffer;
  }
  if(raw3)
  {
    buffer = raw3 * voltageIn;
    voltage3Out = (buffer) / 1024.0;
    buffer = (voltageIn / voltage3Out) - 1;
    R3 = Ref3 * buffer;
  }
  if(raw4)
  {
    buffer = raw4 * voltageIn;
    voltage4Out = (buffer) / 1024.0;
    buffer = (voltageIn / voltage4Out) - 1;
    R4 = Ref4 * buffer;
  }
  if(raw5)
  {
    buffer = raw5 * voltageIn;
    voltage5Out = (buffer) / 1024.0;
    buffer = (voltageIn / voltage5Out) - 1;
    R5 = Ref5 * buffer;
  }
    ///*
    Serial.print("Vout 1: ");
    Serial.println(voltage1Out);
    Serial.print("R1: ");
    Serial.println(R1);

    Serial.print("Vout 2: ");
    Serial.println(voltage2Out);
    Serial.print("R2: ");
    Serial.println(R2);

    Serial.print("Vout 3: ");
    Serial.println(voltage3Out);
    Serial.print("R3: ");
    Serial.println(R3);

    Serial.print("Vout 4: ");
    Serial.println(voltage4Out);
    Serial.print("R4: ");
    Serial.println(R4);

    Serial.print("Vout 5: ");
    Serial.println(voltage5Out);
    Serial.print("R5: ");
    Serial.println(R5);
    Serial.println();
    //*/

    //On-Off Function
    if(isOnOff1) { if(R1 > 75500) State1 = true; else State1 = false; }
    if(isOnOff2) { if(R2 > 100000) State2 = true; else State2 = false; }
    if(isOnOff3) { if(R3 > 300000) State3 = true; else State3 = false; }
    if(isOnOff4) { if(R4 > 57500) State4 = true; else State4 = false; }
    if(isOnOff5) { if(R5 > 39000) State5 = true; else State5 = false; }

    if (isOnOff1 && isOnOff2 && isOnOff3 && isOnOff4 && isOnOff5)
    {
      Serial.print("R1: "); Serial.println(State1);
      Serial.print("R2: "); Serial.println(State2);
      Serial.print("R3: "); Serial.println(State3);
      Serial.print("R4: "); Serial.println(State4);
      Serial.print("R5: "); Serial.println(State5);
      Serial.println();
    }

    //Joystick Function
    if(joyStick1) 
    { 
      if(R1 < 28,000) jState1 = 0;
      else if (R1 > 110000) jState1 = 6;
      else
      {
        jState1 = (int) ((R1 - 28000) / 13666.67); //divide by 6 == 7 groups
      }
      Serial.print("jR1: "); Serial.println(jState1);
    }
    if(joyStick2) 
    { 
      if(R2 < 800) jState2 = 0;
      else if (R2 > 1800) jState2 = 6;
      else
      {
        jState2 = (int) abs(((R2 - 800) / 166.67)); //divide by 6 == 7 groups
      }
      Serial.print("jR2: "); Serial.println(jState2);
    }
     if(joyStick3) 
    { 
      if(R3 < 700) jState3 = 0;
      else if (R3 > 1600) jState3 = 6;
      else
      {
        jState3 = (int) abs(((R3 - 700) / 150.01)); //divide by 6 == 7 groups
      }
      Serial.print("jR3: "); Serial.println(jState3);
    }
    if(joyStick4) 
    { 
      if(R4 < 20000) jState4 = 0;
      else if (R4 > 100000) jState4 = 6;
      else
      {
        jState4 = (int) abs(((R4 - 20000) / 13333.34)); //divide by 6 == 7 groups
      }
      Serial.print("jR4: "); Serial.println(jState4);
    }
    if(joyStick5) 
    { 
      if(R5 < 20000) jState5 = 0;
      else if (R5 > 100000) jState5 = 6;
      else
      {
        jState5 = (int) abs(((R5 - 20000) / 13333.34)); //divide by 6 == 7 groups
      }
      Serial.print("jR5: "); Serial.println(jState5);
    }
      
      Serial.println();
  
  delay(100);
}

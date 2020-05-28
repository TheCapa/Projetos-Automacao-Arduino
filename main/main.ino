#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
  #include "SoftwareSerial.h"
  SoftwareSerial port(12,13);
#else 
  #include "WProgram.h"
  #include "NewSoftSerial.h"
  NewSoftSerial port(12,13);
#endif
#include <Wire.h>
#include "DS1307.h"
#include "DHT.h"
#include "EasyVR.h"
EasyVR easyvr(port);

enum Groups
{
  GROUP_0  = 0,
  GROUP_1  = 1,
  GROUP_2  = 2,
  GROUP_3  = 3,
  GROUP_4  = 4,
};

enum Group0 
{
  G0_ARDUINO = 0,
};

enum Group1 
{
  G1_LAMPADA = 0,
  G1_PC = 1,
  G1_VENTILADOR = 2,
  G1_HORA = 3,
  G1_TEMPERATURA = 4,
};

enum Group2 
{
  G2_PC_ON = 0,
  G2_PC_OFF = 1,
};

enum Group3 
{
  G3_LAMP_ON = 0,
  G3_LAMP_OFF = 1,
};

enum Group4 
{
  G4_VENT_ON = 0,
  G4_VENT_OFF = 1,
};


EasyVRBridge bridge;

int8_t group, idx;

void setup()
{
  
  if (bridge.check())
  {
    cli();
    bridge.loop(0, 1, 12, 13);
  }
  
  Serial.begin(9600);
  port.begin(9600);

  if (!easyvr.detect())
  {
    Serial.println("EasyVR não detectado!");
    for (;;);
  }

  easyvr.setPinOutput(EasyVR::IO1, LOW);
  Serial.println("EasyVR detectado!");
  easyvr.setTimeout(5);
  easyvr.setLanguage(0);

  group = EasyVR::TRIGGER; 
}

void action();

void loop()
{
  easyvr.setPinOutput(EasyVR::IO1, HIGH); 

  Serial.print("Diga um comando do grupo ");
  Serial.println(group);
  easyvr.recognizeCommand(group);

  do
  {
    
  }
  while (!easyvr.hasFinished());
  
  easyvr.setPinOutput(EasyVR::IO1, LOW); 

  idx = easyvr.getWord();
  if (idx >= 0)
  {
    
    return;
  }
  idx = easyvr.getCommand();
  if (idx >= 0)
  {
    
    uint8_t train = 0;
    char name[32];
    Serial.print("Comando: ");
    Serial.print(idx);
    if (easyvr.dumpCommand(group, idx, name, train))
    {
      Serial.print(" = ");
      Serial.println(name);
    }
    else
      Serial.println();
    
    action();
  }
  else 
  {
    if (easyvr.isTimeout())
      Serial.println("Tempo limite esgotado, tente novamente...");
    int16_t err = easyvr.getError();
    if (err >= 0)
    {
      Serial.print("Erro ");
      Serial.println(err, HEX);
    }
  }
}

void action()
{
    switch (group)
    {
    case GROUP_0:
      switch (idx)
      {
      case G0_ARDUINO:
        easyvr.playSound(117, EasyVR::VOL_FULL);
        group = GROUP_1;
        break;
      }
      break;
      
    case GROUP_1:
      switch (idx)
      {
      case G1_LAMPADA:
        easyvr.playSound(114, EasyVR::VOL_FULL);
        group = GROUP_3;
        break;
        
      case G1_PC:
         easyvr.playSound(114, EasyVR::VOL_FULL);
        group = GROUP_2;
        break;
        
      case G1_VENTILADOR:
        easyvr.playSound(114, EasyVR::VOL_FULL);
        group = GROUP_4;
        break;
        
      case G1_HORA:
        easyvr.playSound(114, EasyVR::VOL_FULL);
       
          DS1307 clock;
          void setup();
          {
	  Serial.begin(9600);
	  clock.begin();
	

	

	  clock.getTime();
	  Serial.print(clock.hour, DEC);
	  Serial.print(":");
	  Serial.print(clock.minute, DEC);

            if (clock.hour <= 0 ){
              	easyvr.playSound(115, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 1 ){
              	easyvr.playSound(94, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 2 ){
              	easyvr.playSound(95, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 3 ){
              	easyvr.playSound(96, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 4 ){
              	easyvr.playSound(97, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 5 ){
              	easyvr.playSound(98, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 6 ){
              	easyvr.playSound(99, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 7 ){
              	easyvr.playSound(100, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 8 ){
              	easyvr.playSound(101, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 9 ){
              	easyvr.playSound(102, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 10 ){
              	easyvr.playSound(103, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 11 ){
              	easyvr.playSound(104, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 12 ){
              	easyvr.playSound(105, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 13 ){
              	easyvr.playSound(94, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 14 ){
              	easyvr.playSound(95, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 15 ){
              	easyvr.playSound(96, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 16 ){
              	easyvr.playSound(97, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 17 ){
              	easyvr.playSound(98, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 18 ){
              	easyvr.playSound(99, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 19 ){
              	easyvr.playSound(100, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 20 ){
              	easyvr.playSound(101, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 21 ){
              	easyvr.playSound(102, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 22 ){
              	easyvr.playSound(103, EasyVR::VOL_FULL);
                    }
            else if (clock.hour <= 23 ){
              	easyvr.playSound(104, EasyVR::VOL_FULL);
                    }

        
        
            if (clock.minute <= 1 ){
              	easyvr.playSound(1, EasyVR::VOL_FULL);
                    }       
            else if (clock.minute <= 2 ){
              	easyvr.playSound(2, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 3 ){
              	easyvr.playSound(3, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 4 ){
              	easyvr.playSound(4, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 5 ){
              	easyvr.playSound(5, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 6 ){
              	easyvr.playSound(6, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 7 ){
              	easyvr.playSound(7, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 8 ){
              	easyvr.playSound(8, EasyVR::VOL_FULL);
                    }
             else if (clock.minute <= 9 ){
              	easyvr.playSound(9, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 10 ){
              	easyvr.playSound(10, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 11 ){
              	easyvr.playSound(11, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 12 ){
              	easyvr.playSound(12, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 13 ){
              	easyvr.playSound(13, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 14 ){
              	easyvr.playSound(14, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 15 ){
              	easyvr.playSound(15, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 16 ){
              	easyvr.playSound(16, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 17 ){
              	easyvr.playSound(17, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 18 ){
              	easyvr.playSound(18, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 19 ){
              	easyvr.playSound(19, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 20 ){
              	easyvr.playSound(20, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 21 ){
              	easyvr.playSound(21, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 22 ){
              	easyvr.playSound(22, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 23 ){
              	easyvr.playSound(23, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 24 ){
              	easyvr.playSound(24, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 25 ){
              	easyvr.playSound(25, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 26 ){
              	easyvr.playSound(26, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 27 ){
              	easyvr.playSound(27, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 28 ){
              	easyvr.playSound(28, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 29 ){
              	easyvr.playSound(29, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 30 ){
              	easyvr.playSound(30, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 31 ){
              	easyvr.playSound(31, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 32 ){
              	easyvr.playSound(32, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 33 ){
              	easyvr.playSound(33, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 34 ){
              	easyvr.playSound(34, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 35 ){
              	easyvr.playSound(35, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 36 ){
              	easyvr.playSound(36, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 37 ){
              	easyvr.playSound(37, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 38 ){
              	easyvr.playSound(38, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 39 ){
              	easyvr.playSound(39, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 40 ){
              	easyvr.playSound(40, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 41 ){
              	easyvr.playSound(41, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 42 ){
              	easyvr.playSound(42, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 43 ){
              	easyvr.playSound(43, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 44 ){
              	easyvr.playSound(44, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 45 ){
              	easyvr.playSound(45, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 46 ){
              	easyvr.playSound(46, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 47 ){
              	easyvr.playSound(47, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 48 ){
              	easyvr.playSound(48, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 49 ){
              	easyvr.playSound(49, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 50 ){
              	easyvr.playSound(50, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 51 ){
              	easyvr.playSound(51, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 52 ){
              	easyvr.playSound(52, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 53 ){
              	easyvr.playSound(53, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 54 ){
              	easyvr.playSound(54, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 55 ){
              	easyvr.playSound(55, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 56 ){
              	easyvr.playSound(56, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 57 ){
              	easyvr.playSound(57, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 58 ){
              	easyvr.playSound(58, EasyVR::VOL_FULL);
                    }
            else if (clock.minute <= 59 ){
              	easyvr.playSound(59, EasyVR::VOL_FULL);
                    }
             }
        group = GROUP_0;
        break;
        
      case G1_TEMPERATURA:
      easyvr.playSound(114, EasyVR::VOL_FULL);        

      #define DHTPIN A2    
      #define DHTTYPE DHT11   
      
      DHT dht(DHTPIN, DHTTYPE);
      
      void setup (); {
        Serial.begin(9600); 
        Serial.println("DHTxx test!");
       
        dht.begin();
      }
      
      void loop(); {
        
        float h = dht.readHumidity();
        float t = dht.readTemperature();
      
        
        if (isnan(t) || isnan(h)) {
          Serial.println("Failed to read from DHT");
        } else {
          Serial.print("Humidity: "); 
          Serial.print(h);
          Serial.print(" %\t");
          Serial.print("Temperature: "); 
          Serial.print(t);
          Serial.println(" *C");
        
       
       
      if (t <= 10.00) {
             easyvr.playSound(60, EasyVR::VOL_FULL);
      }
      else if (t <= 11.00) {
          easyvr.playSound(61, EasyVR::VOL_FULL);
        }
      else if (t <= 12.00) {
          easyvr.playSound(62, EasyVR::VOL_FULL);
        }
      else if (t <= 13.00) {
          easyvr.playSound(63, EasyVR::VOL_FULL);
        }
      else if (t <= 14.00) {
          easyvr.playSound(64, EasyVR::VOL_FULL);
        }
      else if (t <= 15.00) {
          easyvr.playSound(65, EasyVR::VOL_FULL);
        }
      else if (t <= 16.00) {
          easyvr.playSound(66, EasyVR::VOL_FULL);
        }
      else if (t <= 17.00) {
          easyvr.playSound(67, EasyVR::VOL_FULL);
        }
      else if (t <= 18.00) {
          easyvr.playSound(68, EasyVR::VOL_FULL);
        }
      else if (t <= 19.00) {
          easyvr.playSound(69, EasyVR::VOL_FULL);
        }
      else if (t <= 20.00) {
          easyvr.playSound(70, EasyVR::VOL_FULL);
        }
      else if (t <= 21.00) {
          easyvr.playSound(71, EasyVR::VOL_FULL);
        }
      else if (t <= 22.00) {
          easyvr.playSound(72, EasyVR::VOL_FULL);
        }
      else if (t <= 23.00) {
          easyvr.playSound(73, EasyVR::VOL_FULL);
        }
      else if (t <= 24.00) {
          easyvr.playSound(74, EasyVR::VOL_FULL);
        }
      else if (t <= 25.00) {
          easyvr.playSound(75, EasyVR::VOL_FULL);
        }
      else if (t <= 26.00) {
          easyvr.playSound(76, EasyVR::VOL_FULL);
        }
      else if (t <= 27.00) {
          easyvr.playSound(77, EasyVR::VOL_FULL);
        }
      else if (t <= 28.00) {
          easyvr.playSound(78, EasyVR::VOL_FULL);
        }
      else if (t <= 29.00) {
          easyvr.playSound(79, EasyVR::VOL_FULL);
        }
      else if (t <= 30.00) {
          easyvr.playSound(80, EasyVR::VOL_FULL);
        }
      else if (t <= 31.00) {
          easyvr.playSound(81, EasyVR::VOL_FULL);
        }
      else if (t <= 32.00) {
          easyvr.playSound(82, EasyVR::VOL_FULL);
        }
      else if (t <= 33.00) {
          easyvr.playSound(83, EasyVR::VOL_FULL);
        }
      else if (t <= 34.00) {
          easyvr.playSound(84, EasyVR::VOL_FULL);
        }
      else if (t <= 35.00) {
          easyvr.playSound(85, EasyVR::VOL_FULL);
        }
      else if (t <= 36.00) {
          easyvr.playSound(86, EasyVR::VOL_FULL);
        }
      else if (t <= 37.00) {
          easyvr.playSound(87, EasyVR::VOL_FULL);
        }
      else if (t <= 38.00) {
          easyvr.playSound(88, EasyVR::VOL_FULL);
        }
      else if (t <= 39.00) {
          easyvr.playSound(89, EasyVR::VOL_FULL);
        }
      else if (t <= 40.00) {
          easyvr.playSound(90, EasyVR::VOL_FULL);
        }
      else if (t <= 41.00) {
          easyvr.playSound(91, EasyVR::VOL_FULL);
        }
      else if (t <= 42.00) {
          easyvr.playSound(92, EasyVR::VOL_FULL);
        }
      else if (t <= 43.00) {
          easyvr.playSound(93, EasyVR::VOL_FULL);
        }
        
        }
           }    
        group = GROUP_0;
        break;
      }
      break;
    case GROUP_2:
      switch (idx)
      {
      case G2_PC_ON:
      
      easyvr.playSound(110, EasyVR::VOL_FULL);
        pinMode(10, OUTPUT);
         digitalWrite(10,1);
      
        digitalWrite(10, HIGH);   
        delay(100);               
        digitalWrite(10, LOW);    
        delay(100);
        
        group = GROUP_0;
        break;
      case G2_PC_OFF:
        
        easyvr.playSound(108, EasyVR::VOL_FULL);
        pinMode(10, OUTPUT);
         digitalWrite(10,1);
      
        digitalWrite(10, HIGH);   
        delay(100);               
        digitalWrite(10, LOW);    
        delay(100);
        
        group = GROUP_0;
        break;
      }
      break;
    case GROUP_3:
      switch (idx)
      {
      case G3_LAMP_ON:
      
      easyvr.playSound(106, EasyVR::VOL_FULL);
      pinMode(9, OUTPUT);
         digitalWrite(9,1);
        
        group = GROUP_0;
        break;
      case G3_LAMP_OFF:
      
      easyvr.playSound(107, EasyVR::VOL_FULL);
       pinMode(9, OUTPUT);
         digitalWrite(9,1);
      
        group = GROUP_0;
        break;
      }
      break;
    case GROUP_4:
      switch (idx)
      {
      case G4_VENT_ON:
      
        easyvr.playSound(111, EasyVR::VOL_FULL);
        pinMode(8, OUTPUT);
         digitalWrite(8,1);
        
        group = GROUP_0;
        break;
      case G4_VENT_OFF:
      
      easyvr.playSound(109, EasyVR::VOL_FULL);
      pinMode(8, OUTPUT);
         digitalWrite(8,1);
      
        group = GROUP_0;
        break;
      }
      break;
    }
}

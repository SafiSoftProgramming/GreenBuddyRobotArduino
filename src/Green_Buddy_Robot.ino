#include <Wire.h>
#include<SoftwareSerial.h>

/////////////////////////////
//Driver one
int d1_in1 =22;
int d1_in2 =23;
int d1_in3 =24;
int d1_in4 =25;

//Driver two
int d2_in1 =26;
int d2_in2 =27;
int d2_in3 =28;
int d2_in4 =29;

//Relay Module
int in1 =2;
int in2 =3;
int in3 =4;
int in4 =5;
int in5 =6;
int in6 =7;

//Bluetooth serial 
const int txpin = 13;       
const int rxpin = 12;

SoftwareSerial blue(txpin, rxpin);
char Command = 'o'  ;

void setup() {

  blue.begin(9600);
  // Serial.begin(115200); 
  blue.setTimeout(10);

    pinMode(d1_in1, OUTPUT);
    pinMode(d1_in2, OUTPUT);
    pinMode(d1_in3, OUTPUT);
    pinMode(d1_in4, OUTPUT);

    pinMode(d2_in1, OUTPUT);
    pinMode(d2_in2, OUTPUT);
    pinMode(d2_in3, OUTPUT);
    pinMode(d2_in4, OUTPUT);

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(in5, OUTPUT);
    pinMode(in6, OUTPUT);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, HIGH);

}

void loop() {

   if (blue.available()) {
       Command = blue.read();
       
      // MOTOR_HEAD_UD      
      if(Command == 'E'){ControlMotors(d1_in1,HIGH,d1_in2,LOW);}           
      if(Command == '4'){ControlMotors(d1_in1,LOW,d1_in2,LOW);}      
      if(Command == 'e'){ControlMotors(d1_in1,LOW,d1_in2,HIGH);}   
//=====================================================================================================
      //MOTOR_HEAD_LR
      if(Command == 'D'){ControlMotors(d1_in3,HIGH,d1_in4,LOW);}
      if(Command == '3'){ControlMotors(d1_in3,LOW,d1_in4,LOW);} 
      if(Command == 'd'){ControlMotors(d1_in3,LOW,d1_in4,HIGH);}   
//==========================================================================================================================
      // MOTOR_CUT
      if(Command == 'F'){ControlMotors(d2_in1,HIGH,d2_in2,LOW);}
      if(Command == '5'){ControlMotors(d2_in1,LOW,d2_in2,LOW);}  
      if(Command == 'f'){ControlMotors(d2_in1,LOW,d2_in2,HIGH);} 
//---------------------------------------------------------------------------------//
      //MOTOR_CATCH
      if(Command == 'G'){ControlMotors(d2_in3,HIGH,d2_in4,LOW);}
      if(Command == '6'){ControlMotors(d2_in3,LOW,d2_in4,LOW);}
      if(Command == 'g'){ControlMotors(d2_in3,LOW,d2_in4,HIGH);}    
//===========================================================================================================================
       //MOTOR_BASE
      if(Command == 'A'){ControlMotors(in1,HIGH,in2,LOW);}
      if(Command == '0'){ControlMotors(in1,HIGH,in2,HIGH);} 
      if(Command == 'a'){ControlMotors(in1,LOW,in2,HIGH);}    
//=======================================================================================
      //MOTOR_UP_DOWN
      if(Command == 'B'){ControlMotors(in3,HIGH,in4,LOW);} 
      if(Command == '1'){ ControlMotors(in3,HIGH,in4,HIGH);}  
      if(Command == 'b'){ControlMotors(in3,LOW,in4,HIGH);}         
//=============================================================================================
      //MOTOR_ARM
      if(Command == 'C'){ControlMotors(in5,HIGH,in6,LOW);} 
      if(Command == '2'){ControlMotors(in5,HIGH,in6,HIGH);} 
      if(Command == 'c'){ControlMotors(in5,LOW,in6,HIGH);} 
     
   }
     
}

void ControlMotors(int pin1,int val1,int pin2,int val2){ 
        digitalWrite(pin1, val1);
        digitalWrite(pin2, val2);
  }

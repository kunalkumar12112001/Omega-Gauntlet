#include<ESP8266WiFi.h>
#include<espnow.h>
#include<Servo.h>

Servo myServo;

#define enA D7
#define in1 D6
#define in2 D5

const int servoPin = 4;

bool snapFlag;
bool zeroFlag = false;
bool oneFlag = false;
bool twoFlag = false;
bool threeFlag = false;
bool fourFlag = false;
bool fiveFlag = false;


uint8_t broadcastAddress[] = {0x7C,0x9E,0xBD,0xF4,0x54,0x60};
int i,pos;

typedef struct struct_messageS
{ bool F;
} struct_messageS;

struct_messageS myDataS;

typedef struct struct_messageR
{ int d;
} struct_messageR;

struct_messageR myDataR;

void OnDataSent(uint8_t *mac_addr , uint8_t sendStatus)
{ 
  Serial.print(" /r/n Last packet send status ");

  if(sendStatus==0)
  { Serial.println("Delivery Success");
  }
  else
  { Serial.println("Delivery Failure");
  }
}

void OnDataRecv(uint8_t *mac , uint8_t *incomingData , uint8_t len)
{ 
  memcpy(&myDataR,incomingData,sizeof(myDataR));
  pos = myDataR.d;
  Serial.print("/r/n Positon=");
  Serial.println(pos);
  snapFlag=true;
}

void setup()
{ Serial.begin(115200);

  pinMode(5,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT); 

  myServo.attach(servoPin,600,2300);
 
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if(esp_now_init()!=0)
  { Serial.println("Error init esp_now");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
  esp_now_register_send_cb(OnDataSent);
  esp_now_add_peer(broadcastAddress,ESP_NOW_ROLE_COMBO,1,NULL,0);
  esp_now_register_recv_cb(OnDataRecv);

}

void forward()
{ digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(enA,1023);
}

void backward()
{ digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  analogWrite(enA,1023);
}

void stopDevice()
{ digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);

  delay(500);
}


void loop()
{
  if(snapFlag==true) {
switch(pos)
{ case 0 : delay(500);

           if(zeroFlag==false)
           { zeroFlag=true;
             myServo.write(135);
           }
           else
           { zeroFlag=false;
             myServo.write(45);
           }
             delay(500);
             myServo.write(90);
             delay(500);
           
           break;

  case 1 : while(digitalRead(5))
           { forward();
             delay(1);
           }           
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           stopDevice();
           
           if(oneFlag==false)
           { oneFlag=true;
             myServo.write(135);
           }
           else
           { oneFlag=false;
             myServo.write(45);
           }
             delay(500);
             myServo.write(90);
             delay(500);
           
           while(digitalRead(5))
           { backward();
             delay(1);
           }
             while(!digitalRead(5))
           { backward();
             delay(1);
           }
           stopDevice();
           break;

  case 2 :  while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           stopDevice();

            if(twoFlag==false)
           { twoFlag=true;
             myServo.write(135);
           }
           else
           { twoFlag=false;
             myServo.write(45);
           }
             delay(500);
             myServo.write(90);
             delay(500);
           
           while(digitalRead(5))
           { backward();
             delay(1);
           } 
           while(!digitalRead(5))
           { backward();
             delay(1);
           }  
            while(digitalRead(5))
           { backward();
             delay(1);
           } 
            while(!digitalRead(5))
           { backward();
             delay(1);
           } 
           stopDevice();
           break;

 case 3 : while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
            stopDevice();

             if(threeFlag==false)
           { threeFlag=true;
             myServo.write(135);
           }
           else
           { threeFlag=false;
             myServo.write(45);
           }
             delay(500);
             myServo.write(90);
             delay(500);
           
           while(digitalRead(5))
           { backward();
             delay(1);
           } 
           while(!digitalRead(5))
           { backward();
             delay(1);
           }  
            while(digitalRead(5))
           { backward();
             delay(1);
           } 
            while(!digitalRead(5))
           { backward();
             delay(1);
           } 
            while(digitalRead(5))
           { backward();
             delay(1);
           } 
            while(!digitalRead(5))
           { backward();
             delay(1);
           } 
           stopDevice();
           break;

  case 4 : while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }      
           while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           stopDevice();

            if(fourFlag==false)
           { fourFlag=true;
             myServo.write(135);
           }
           else
           { fourFlag=false;
             myServo.write(45);
           }
             delay(500);
             myServo.write(90);
             delay(500);
           
           while(digitalRead(5))
           { backward();
             delay(1);
           } 
           while(!digitalRead(5))
           { backward();
             delay(1);
           }  
            while(digitalRead(5))
           { backward();
             delay(1);
           } 
            while(!digitalRead(5))
           { backward();
             delay(1);
           } 
            while(digitalRead(5))
           { backward();
             delay(1);
           } 
            while(!digitalRead(5))
           { backward();
             delay(1);
           } 
            while(digitalRead(5))
           { backward();
             delay(1);
           } 
           while(!digitalRead(5))
           { backward();
             delay(1);
           }  
           stopDevice();
           break;

  case 5 : while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }      
           while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
            while(digitalRead(5))
           { forward();
             delay(1);
           } 
           while(!digitalRead(5))
           { forward();
             delay(1);
           }
           stopDevice();

            if(fiveFlag==false)
           { fiveFlag=true;
             myServo.write(135);
           }
           else
           { fiveFlag=false;
             myServo.write(45);
           }
             delay(500);
            myServo.write(90);
             delay(500);
           
           while(digitalRead(5))
           { backward();
             delay(1);
           } 
           while(!digitalRead(5))
           { backward();
             delay(1);
           }  
            while(digitalRead(5))
           { backward();
             delay(1);
           } 
            while(!digitalRead(5))
           { backward();
             delay(1);
           } 
            while(digitalRead(5))
           { backward();
             delay(1);
           } 
            while(!digitalRead(5))
           { backward();
             delay(1);
           } 
            while(digitalRead(5))
           { backward();
             delay(1);
           } 
           while(!digitalRead(5))
           { backward();
             delay(1);
           }  
             while(digitalRead(5))
           { backward();
            delay(1);
           } 
           while(!digitalRead(5))
           { backward();
             delay(1);
           }  
           stopDevice();
           break;
}
}
 snapFlag=false;
}

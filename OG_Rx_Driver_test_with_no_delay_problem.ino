#define enA D7
#define in1 D6
#define in2 D5

int pos;

void setup()
{ pinMode(5,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  
  Serial.begin(115200);
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
}

void movement(int posi) {
switch(posi)
{ case 0 : delay(500);
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
void loop()
{
  pos = 5;
  movement(pos);
  delay(1000);
}
  

#define green 23
#define violetRed 22
#define violetBlue 21
#define blue 19
#define red 18
#define orangeRed 32
#define orangeGreen 33
#define yellowRedGreen 16

const int trigPin = 5;
const int posPin = 17;

int pos=0;
int i,j;

void setup() {
  Serial.begin(115200);
  
  pinMode(trigPin,INPUT_PULLUP);
  pinMode(posPin,INPUT_PULLUP);
  
  ledcSetup(0,5000,8);
  ledcSetup(1,5000,8);
  ledcSetup(2,5000,8);
  ledcSetup(3,5000,8);
  ledcSetup(4,5000,8);
  ledcSetup(5,5000,8);
  ledcSetup(6,5000,8);
  ledcSetup(7,5000,8);


  ledcAttachPin(green,0);
  ledcAttachPin(violetRed,1);
  ledcAttachPin(violetBlue,2);
  ledcAttachPin(blue,3);
  ledcAttachPin(red,4);
  ledcAttachPin(orangeRed,5);
  ledcAttachPin(orangeGreen,6);
  ledcAttachPin(yellowRedGreen,7);

  startFx();
}

void startFx()
{ Serial.println("StartFx");
  
  for( i=0 ; i<256 ; i++ )
  {
    ledcWrite(0,i);
    delay(1);
    delayMicroseconds(330);
  }
  delay(50);
  
  for( i=0 ; i<128 ; i++ )
  {
    ledcWrite(1,i);
    ledcWrite(2,2*i);
    delay(2);
    delayMicroseconds(660);
  }
  delay(50);

 for( j=3 ; j<5 ; j++)
 {
  for( i=0 ; i<256 ; i++ )
  {
    ledcWrite(j,i);
    delay(1);
    delayMicroseconds(330);
  }
  delay(50);
 }

 for( i=0 ; i<128 ; i++ )
  {
    ledcWrite(5,2*i);
    ledcWrite(6,i);
    delay(2);
    delayMicroseconds(660);
  }
  delay(50);

  for( i=0 ; i<256 ; i++ )
  {
    ledcWrite(7,i);
    delay(1);
    delayMicroseconds(330);
  }
  delay(50);

  delay(200);

  for(i=127 ; i>9 ; i--)
  { ledcWrite(0,2*i);
    ledcWrite(1,i);
    ledcWrite(2,2*i);
    ledcWrite(3,2*i);
    ledcWrite(4,2*i);
    ledcWrite(5,2*i);
    ledcWrite(6,i);
    ledcWrite(7,2*i);
  
    delay(6);
  }
  delay(200);
}

void posPinHandel()
{
   if( pos>=5)
  { pos=0; }
  else
  { pos=pos+1; }

  
  
  switch(pos)
  { 
    case 0 : ledcWrite(0,255);
             ledcWrite(1,5);
             ledcWrite(2,10);
             ledcWrite(3,10);
             ledcWrite(4,10);
             ledcWrite(5,10);
             ledcWrite(6,5);
             ledcWrite(7,10);
       
             break;

    case 1 : ledcWrite(0,10);
             ledcWrite(1,127);
             ledcWrite(2,255);
             ledcWrite(3,10);
             ledcWrite(4,10);
             ledcWrite(5,10);
             ledcWrite(6,5);
             ledcWrite(7,10);
             
             break;

    case 2 : ledcWrite(0,10);
             ledcWrite(1,5);
             ledcWrite(2,10);
             ledcWrite(3,255);
             ledcWrite(4,10);
             ledcWrite(5,10);
             ledcWrite(6,5);
             ledcWrite(7,10);
            
             break;

    case 3 : ledcWrite(0,10);
             ledcWrite(1,5);
             ledcWrite(2,10);
             ledcWrite(3,10);
             ledcWrite(4,255);
             ledcWrite(5,10);
             ledcWrite(6,5);
             ledcWrite(7,10);
             
             break;

    case 4 : ledcWrite(0,10);
             ledcWrite(1,5);
             ledcWrite(2,10);
             ledcWrite(3,10);
             ledcWrite(4,10);
             ledcWrite(5,255);
             ledcWrite(6,127);
             ledcWrite(7,10);
             
             break;  

    case 5 : ledcWrite(0,10);
             ledcWrite(1,5);
             ledcWrite(2,10);
             ledcWrite(3,10);
             ledcWrite(4,10);
             ledcWrite(5,10);
             ledcWrite(6,5);
             ledcWrite(7,255);
             
             break;
  }
  Serial.print("pos =");
  Serial.println(pos);
  delay(200);
}

void snapFx()
{   

    for( i=10 ; i<128 ; i++)
    { 
     ledcWrite(0,2*i);
     ledcWrite(1,i);
     ledcWrite(2,2*i);
     ledcWrite(3,2*i);
     ledcWrite(4,2*i);
     ledcWrite(5,2*i);
     ledcWrite(6,i);
     ledcWrite(7,2*i);
    
     delay(6);
    }


   for( i=127 ; i>9 ; i--)
    { 
     ledcWrite(0,2*i);
     ledcWrite(1,i);
     ledcWrite(2,2*i);
     ledcWrite(3,2*i);
     ledcWrite(4,2*i);
     ledcWrite(5,2*i);
     ledcWrite(6,i);
     ledcWrite(7,2*i);
    
     delay(6);
    }
}


void loop() {
  
 if(digitalRead(posPin)==0)
  { 
    posPinHandel();
  }

  if(digitalRead(trigPin)==0)
  { Serial.println(" Snap Triggered.");
    snapFx();
  }

}

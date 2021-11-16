#include<esp_now.h>
#include<WiFi.h>

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

uint8_t broadcastAddress[]={0xD8,0xF1,0x5B,0x15,0x8A,0x27};

typedef struct struct_messageS
{ int d;
}struct_messageS;

struct_messageS myDataS;

void OnDataSent(const uint8_t *mac_addr , esp_now_send_status_t status)
{ Serial.print(" \r\n Send Status : \t ");
  Serial.print( status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Failure" );
}

typedef struct struct_messageR
{ bool F;
}struct_messageR;

struct_messageR myDataR;

void OnDataRecv(const uint8_t *mac , const uint8_t *incomingData , int len)
{ 
  memcpy( &myDataR , incomingData , sizeof(myDataR) );
  Serial.print("\r\n Received Flag=");
  Serial.println(myDataR.F);
}

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

   WiFi.mode(WIFI_STA);
  if( esp_now_init()!= ESP_OK)
  { Serial.println("Error init ESP_NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  esp_now_peer_info_t peerInfo;
  memcpy(peerInfo.peer_addr , broadcastAddress , 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if(esp_now_add_peer(&peerInfo)!=ESP_OK)
  { Serial.println("Failed to add peer");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
  
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

   myDataS.d=pos;

   esp_err_t result = esp_now_send( broadcastAddress, (uint8_t *)&myDataS , sizeof(myDataS));

   if( result == ESP_OK)
   { Serial.println("\r\n Position has been sent."); }
   else
   { Serial.println("\r\n Position has not been sent."); } 
    
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

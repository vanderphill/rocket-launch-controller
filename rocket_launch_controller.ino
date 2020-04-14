int counter = 0;
const int buttonPin = 2; // the number of the pushbutton pin
const int ledPin = 13; // the number of the LED pin
const int launch_relay = 11; // normally off relay controls 12v launch voltage
#define buzzer 12
int launch = 0;



void setup(){  
  Serial.begin(9600);
for(int i=0;i<2; i++){
for(int o = 3; o <= 9; o++){
    pinMode(o,OUTPUT);
    digitalWrite(o,HIGH);
    }
   delay(500);
  for(int o = 3; o <= 9; o++){
    digitalWrite(o,LOW);
    }
   delay(500);
}
    
pinMode(launch_relay, OUTPUT);
digitalWrite(launch_relay,HIGH);
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);

delay(50);
}  
 
void loop(){
    digitalWrite(ledPin, HIGH);
    launch = digitalRead(buttonPin);
    if(launch == HIGH){launch_sequence();}  
    digitalWrite(4,HIGH);
    delay(300);
    digitalWrite(4,LOW);
    launch = digitalRead(buttonPin);  
    if(launch == HIGH){launch_sequence();}
    digitalWrite(5,HIGH);
    delay(300);
    digitalWrite(5,LOW);
    launch = digitalRead(buttonPin);  
    if(launch == HIGH){launch_sequence();}
    digitalWrite(6,HIGH);
    delay(300);
    digitalWrite(6,LOW);
    launch = digitalRead(buttonPin);  
    if(launch == HIGH){launch_sequence();}
    digitalWrite(9,HIGH);
    delay(300);
    digitalWrite(9,LOW);
    launch = digitalRead(buttonPin);  
    if(launch == HIGH){launch_sequence();}
    digitalWrite(8,HIGH);
    delay(300);
    digitalWrite(8,LOW);
    launch = digitalRead(buttonPin);  
    if(launch == HIGH){launch_sequence();}
    digitalWrite(7,HIGH);
    delay(300);
    digitalWrite(7,LOW);
    launch = digitalRead(buttonPin);  
    if(launch == HIGH){launch_sequence();}
    
 
counter++;
if (counter > 10){ //if launch button is not pressed in the first ten seconds it delays indeffinantly
  tone(buzzer,300,1500);
  delay(1500);
  noTone(50);
  delay(50000000);}
 
 
  }  


void launch_sequence(){
  if(digitalRead(buttonPin) == LOW){Abort();}
  digitalWrite(ledPin, LOW);
  //5
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  tone(buzzer,700,300);
  digitalWrite(ledPin, HIGH);
  delay(300);
  if(digitalRead(buttonPin) == LOW){Abort();}
  noTone(50);
  digitalWrite(ledPin, LOW);
  delay(700);
  if(digitalRead(buttonPin) == LOW){Abort();}

  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);

 // four
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  tone(buzzer,700,300);
  digitalWrite(ledPin, HIGH);
  delay(300);
  if(digitalRead(buttonPin) == LOW){Abort();}

  noTone(50);
  digitalWrite(ledPin, LOW);
  delay(700);
  if(digitalRead(buttonPin) == LOW){Abort();}

  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(9,LOW);
  digitalWrite(6,LOW);
//three
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  tone(buzzer,700,300);
  digitalWrite(ledPin, HIGH);
  delay(300);
  if(digitalRead(buttonPin) == LOW){Abort();}

  noTone(50);
  digitalWrite(ledPin, LOW);
  delay(700);
  if(digitalRead(buttonPin) == LOW){Abort();}

  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(3,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
//two
   digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  tone(buzzer,700,300);
  digitalWrite(ledPin, HIGH);
  delay(300);
  if(digitalRead(buttonPin) == LOW){Abort();}

  noTone(50);
  digitalWrite(ledPin, LOW);
  delay(700);
  if(digitalRead(buttonPin) == LOW){Abort();}


  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(3,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);

//1
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  tone(buzzer,700,300);
  digitalWrite(ledPin, HIGH);
  delay(300);
  if(digitalRead(buttonPin) == LOW){Abort();}

  noTone(50);
  digitalWrite(ledPin, LOW);
  delay(700);
  if(digitalRead(buttonPin) == LOW){Abort();}

  digitalWrite(9,LOW);
  digitalWrite(6,LOW);

//0
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(ledPin, HIGH);
  digitalWrite(launch_relay, LOW);
  delay(5000);

  digitalWrite(launch_relay, HIGH);
 
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(ledPin, LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  delay(50000000000);
  }
 void Abort(){
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(ledPin,LOW);
  tone(buzzer,300,1500);
  delay(1500);
  noTone(50);
 delay(500000000); //delay indeffineantly
  }

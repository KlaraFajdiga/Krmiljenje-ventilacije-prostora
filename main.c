int temp = A1;
float val = 0;
int ventilator = 7;
int vklop = 8;
int menjava = 9;
int LEDZ = 3;
int LEDR = 4;
int temperatura = 0;

void setup() {
  Serial.begin(9600);
  pinMode(vklop,INPUT); //vklop/izklop ventilatorja
  pinMode(menjava,INPUT); //izbiranje ročnega/avtomatskega upravljanja
  pinMode(LEDR,OUTPUT); //rdeča LED
  pinMode(LEDZ,OUTPUT); //zelena LED
  pinMode(temp,INPUT);
  pinMode(ventilator,OUTPUT);
}
void loop() {
  if(digitalRead(menjava)==1){ //ročno upravljanje ventilatorja
    digitalWrite(LEDZ,LOW);
    if(digitalRead(vklop)==1){      // vklop ventilatorja
      digitalWrite(ventilator,LOW);
      digitalWrite(LEDR,HIGH); 
    }
    else {    // izklop ventilatorja
      digitalWrite(LEDR,HIGH);
      digitalWrite(LEDZ,HIGH);
      digitalWrite(ventilator,HIGH);
    }
  }
  else{         // avtomatsko upravljanje
    digitalWrite(LEDZ,HIGH);
    digitalWrite(LEDR,LOW); 
    temperatura = analogRead(temp);
    Serial.println(temperatura);
    if(temperatura > 19){
      digitalWrite(ventilator,LOW);
      }
    else{
      digitalWrite(ventilator,HIGH);
      }
    }
  delay(20);
}

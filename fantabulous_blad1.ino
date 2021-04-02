int cm;
int inches;


long readDistance(int Pin) {
  int distanciaSensor;
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  delayMicroseconds(2);
  digitalWrite(7,HIGH);
  delayMicroseconds(10);
  digitalWrite(7,LOW);
  pinMode(7,INPUT);
  distanciaSensor = pulseIn(7,HIGH);
  return distanciaSensor;
}


void setup()
{
  pinMode(7,INPUT);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  int medida;

  medida = readDistance(7);
  cm = medida*0.01723;
  Serial.println(cm);
  delay(100);
  
  if(cm<100){
  	digitalWrite(8,HIGH);
  }else{
  	digitalWrite(8,LOW);
  }
  if(cm>=100 && cm<200){
  	digitalWrite(9,HIGH);
  }else{
  	digitalWrite(9,LOW);
  }
  if(cm>200){
  	digitalWrite(10,HIGH);
  }else{
  	digitalWrite(10,LOW);
  }
  
}

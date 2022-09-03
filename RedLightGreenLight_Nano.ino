//button

#define BLUE 6
#define GAS 15
#define BRAKE 16

int byteRead;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GAS, INPUT);
  pinMode(BRAKE, INPUT);
  pinMode(BLUE, OUTPUT);
}

int k = -1;
int old_k = -1;
//int points = 0;

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println(analogRead(GAS));
//  Serial.println(analogRead(BRAKE)); // test if connection is established
//  Serial.write(1);
  if (analogRead(GAS)>900)
  {
    k = 1;
  }
  else if (analogRead(BRAKE)>900){
    k = 0;
    
  }
  else
  {
    k = -1;
  }

  if ((k != old_k)&& (k!=-1)){
    
      Serial.write(k);
   
    
     
  }

  if (Serial.available()>0){
    int correct = Serial.read();
    if (correct == 1){
      digitalWrite(BLUE,HIGH);
      delay(100);
      digitalWrite(BLUE, LOW);

      
    }
    else if(correct == 0){
      digitalWrite(BLUE, HIGH);
      delay(5000);
      digitalWrite(BLUE, LOW);

      
    }
    
  }
  old_k=k;

//  Serial.print("Points:");
//  Serial.println(points);
//  digitalWrite(RED, LOW);
//  digitalWrite(GREEN, LOW);
}

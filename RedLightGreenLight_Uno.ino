//lights

#define GREEN 5 
#define RED 4
int byteRead;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GREEN,OUTPUT); 
  pinMode(RED,OUTPUT);
//  randomSeed(analogRead(A0)); //floating point-random generator
}

int points = 0;
int guess = 7;
 
void loop() {
  // put your main code here, to run repeatedly:

  int randNum = random(2); // [0,1]
  if (randNum == 0){
    digitalWrite(RED, HIGH);
  }
  else
  {
    digitalWrite(GREEN, HIGH);
  }
  while(Serial.available()<1)// when there's no data
  {
    delay(100); //pause until data is available
  }
  
  if (Serial.available()>0){
    guess = Serial.read();
 
  }
  if (guess == randNum){
    points++;
    Serial.write(1);
    delay(100); //blink rate for the blue LED
  }
  else
  {
    points = 0;
    Serial.write(0); //blue light 5s - game over
    Serial.println("Game Over");  
    Serial.println("Thank you for playing");
    delay(5000); //light length
  }
//  if (byteRead == 1){
//    digitalWrite(GREEN, HIGH); // checking if the hook up is good or not
//    delay(200);
//    digitalWrite(RED, HIGH);
  Serial.print("Points:");
  Serial.println(points);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
}





//  if (Serial.available()>0){
//    byteRead = Serial.read();
//    Serial.write(byteRead);
////    Serial.print("I got: ");
////    Serial.println(byteRead, DEC);
//  }

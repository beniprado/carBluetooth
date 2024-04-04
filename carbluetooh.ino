//projeto controle bluetooh

#define enbMa 2 
#define pA 3
#define pB 4

#define pC 5
#define pD 6
#define enbMb 7 


void Pause() {
  digitalWrite(pA, LOW);
  digitalWrite(pB, LOW);
  digitalWrite(pC, LOW);
  digitalWrite(pD, LOW);
  delay(100);
}

void Forward() {  // ir para frente
  digitalWrite(pA, HIGH);
  digitalWrite(pB, LOW);
  digitalWrite(pC, HIGH);
  digitalWrite(pD, LOW);
  delay(1000);
}

void Backward(){ // ir para atrás
  digitalWrite(pA, LOW);
  digitalWrite(pB, HIGH);
  digitalWrite(pC, LOW);
  digitalWrite(pD, HIGH);
}

void Left(){ // esquerda 
  digitalWrite(pA, HIGH);
  digitalWrite(pB, LOW);
  digitalWrite(pC, LOW);
  digitalWrite(pD, HIGH);
}
void Right(){ // direita
  digitalWrite(pA, LOW);
  digitalWrite(pB, HIGH);
  digitalWrite(pC, HIGH);
  digitalWrite(pD, LOW);
}

void setup() {
  pinMode(enbMa, OUTPUT);
  pinMode(enbMb, OUTPUT);
  pinMode(pA, OUTPUT);
  pinMode(pB, OUTPUT);
  pinMode(pC, OUTPUT);
  pinMode(pD, OUTPUT);

  Serial.begin(9600);
  Serial.setTimeout(100);
  digitalWrite(enbMa, HIGH);
  digitalWrite(enbMb, HIGH);
  Pause();
}

void loop() {
   char conv='o';
   if (Serial.available()  0) {
    String _read = Serial.readString();
    conv = _read.charAt(0);
   }
    if (conv == 'f'){
      Forward();
    } else if (conv == 'b'){
      Backward();
    } else if (conv == 'l'){
      Left();
    } else if (conv == 'r'){
      Right();
    } else {
      Pause();
    }
}
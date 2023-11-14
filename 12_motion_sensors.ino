//defining pin numbers
const byte senPins[] = {2,3,4,5,6,7,8,9,10,11,12,13};
const byte N_sen = sizeof(senPins);
byte senState[]={0,0,0,0,0,0,0,0,0,0,0,0};
byte newState=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  for(int p=0; p<N_sen; p++)
  {
    pinMode(senPins[p], INPUT_PULLUP);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int s=0;s<N_sen;s++)
  {
    newState=digitalRead(senPins[s]);
    if(newState!=senState[s])
    {
      senState[s]=newState;
      Serial.print(senPins[s],DEC);
      Serial.print(",");
      Serial.print(millis());
      Serial.print(",");
      Serial.println(senState[s]);
    }
  }
  //is delay necessary?
  //delay(100);

}

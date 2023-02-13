

int SOLENOID_PIN_1 = 31;
int SOLENOID_PIN_2 = 33;
int SOLENOID_PIN_3 = 35;
int SOLENOID_PIN_4 = 37;

int SOLENOID_PIN_5 = 39;
int SOLENOID_PIN_6 = 41;
int SOLENOID_PIN_7 = 43;
int SOLENOID_PIN_8 = 45;

int SOLENOID_PIN_9 = 47;
int SOLENOID_PIN_10 = 49;
int SOLENOID_PIN_11 = 51;
int SOLENOID_PIN_12 = 53;

int SINGLE_SOLENOID_PIN1 = 22;
int SINGLE_SOLENOID_PIN2 = 25;
int SINGLE_SOLENOID_PIN3 = 24;


int TEMPSENSOR_PIN = 15; // MUST BE ANALOG INPUT

const int SolenoidGroupSize = 4;
int SolenoidGroup1[SolenoidGroupSize]  = {SOLENOID_PIN_1, SOLENOID_PIN_2, SOLENOID_PIN_3, SOLENOID_PIN_4};
int SolenoidGroup2[SolenoidGroupSize]  = {SOLENOID_PIN_5, SOLENOID_PIN_6, SOLENOID_PIN_7, SOLENOID_PIN_8};
int SolenoidGroup3[SolenoidGroupSize]  = {SOLENOID_PIN_9, SOLENOID_PIN_10, SOLENOID_PIN_11, SOLENOID_PIN_12};
int timingFactor1 = 7;
int timingFactor2 = 3;
int timingFactor3 = 4;
int checkDelay = 2000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SINGLE_SOLENOID_PIN1, OUTPUT);
  pinMode(SINGLE_SOLENOID_PIN2, OUTPUT);
  pinMode(SINGLE_SOLENOID_PIN3, OUTPUT);

  digitalWrite(SINGLE_SOLENOID_PIN1, HIGH); 
  digitalWrite(SINGLE_SOLENOID_PIN2, HIGH); 
  digitalWrite(SINGLE_SOLENOID_PIN3, HIGH);

  InitializeSolenoidGroup(SolenoidGroup1);
  InitializeSolenoidGroup(SolenoidGroup2);
  InitializeSolenoidGroup(SolenoidGroup3);
}

void loop() {
  // put your main code here, to run repeatedly:

  int randomInt = random(1, 100);

  if (randomInt % timingFactor1 == 0)
  {
    // TriggerSolenoid(SINGLE_SOLENOID_PIN1);
    TriggerSolenoidGroup(SolenoidGroup1);
  }

  if (randomInt % timingFactor2 == 0)
  {
    // TriggerSolenoid(SINGLE_SOLENOID_PIN2);
    TriggerSolenoidGroup(SolenoidGroup2);
  }
  
  if (randomInt % timingFactor3 == 0)
  {
    // TriggerSolenoid(SINGLE_SOLENOID_PIN3);
    TriggerSolenoidGroup(SolenoidGroup3);
  }

  //TriggerSolenoid(SINGLE_SOLENOID_PIN1);

  delay(checkDelay);
}

// int GenerateRandomInt(int lowerBound, int upperBound)
// {
//   return (int) ((Math.random() * (upperBound - lowerBound)) + lowerBound);
// }

void InitializeSolenoidGroup(int solenoidGroup[])
{
  Serial.println("Solenoid Size");
  int size = sizeof(solenoidGroup)/sizeof(solenoidGroup[0]);
  Serial.println(size);

  // for (int solenoidPin : solenoidGroup) 
  for (int i = 0; i < SolenoidGroupSize; i++)
  {
    Serial.print("Initializing Solenoid "); Serial.println(i);
    Serial.println(solenoidGroup[i]);
    pinMode(solenoidGroup[i], OUTPUT);
  }
}

void TriggerSolenoid(int solenoidPin)
{
  Serial.print("Turning ON Solenoid: "); Serial.println(solenoidPin);
  digitalWrite(solenoidPin, HIGH);
  // delay(20); // For Actual Use - shorter spurt creates better impact => produces better sound
  delay(200); // For Testing - Easier to see with the eye
  Serial.print("Turning OFF Solenoid: "); Serial.println(solenoidPin);
  digitalWrite(solenoidPin, LOW);
}

void TriggerSolenoidGroup(int solenoidGroup[])
{
  // for (int solenoidPin : solenoidGroup) 
  for (int i = 0; i < SolenoidGroupSize; i++)
  {
    Serial.print("Triggering Solenoid "); Serial.println(i);
    Serial.println(solenoidGroup[i]);
    TriggerSolenoid(solenoidGroup[i]);
    
    int randomInt = random(1, 4);
    delay(randomInt * 100);
  }
  ShuffleSolenoidGroup(solenoidGroup);
}

int *ShuffleSolenoidGroup(int solenoidGroup[])
{
  Serial.println("Before Shuffle: ");
  PrintArrayInOrder(solenoidGroup);

  int currentIndex = SolenoidGroupSize;
  int randomIndex = currentIndex;

  while (currentIndex != 0) 
  {

    // Pick a remaining element.
    randomIndex = random(0, currentIndex);
    currentIndex--;

    // And swap it with the current element.
    int tempVal1 = solenoidGroup[currentIndex];
    int tempVal2 = solenoidGroup[randomIndex];
    solenoidGroup[currentIndex] = tempVal2;
    solenoidGroup[randomIndex] = tempVal1;;
  }

  Serial.println("After Shuffle: ");
  PrintArrayInOrder(solenoidGroup);

  return solenoidGroup;
}

void PrintArrayInOrder(int solenoidGroup[])
{
  for (int i = 0; i < SolenoidGroupSize; i++)
  {
    Serial.println("PrintArrayInOrder: ");
    Serial.println(solenoidGroup[i]);
  }
}
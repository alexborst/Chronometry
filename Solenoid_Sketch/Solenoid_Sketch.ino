int SOLENOID_PIN_1 = 3;
int SOLENOID_PIN_2 = 4;
int SOLENOID_PIN_3 = 5;
int SOLENOID_PIN_4 = 6;
int SOLENOID_PIN_5 = 7;
int SOLENOID_PIN_6 = 8;
int SOLENOID_PIN_7 = 9;
int SOLENOID_PIN_8 = 10;
int SOLENOID_PIN_9 = 11;

int TEMPSENSOR_PIN = 15; // MUST BE ANALOG INPUT

int [] SolenoidGroup1 = {SOLENOID_PIN_1, SOLENOID_PIN_2, SOLENOID_PIN_3};
int [] SolenoidGroup2 = {SOLENOID_PIN_4, SOLENOID_PIN_5, SOLENOID_PIN_6};
int [] SolenoidGroup3 = {SOLENOID_PIN_7, SOLENOID_PIN_8, SOLENOID_PIN_9};

void setup() {
  // put your setup code here, to run once:
  pinMode(TEMPSENSOR_PIN, INPUT);
  
  InitializeSolenoidGroup(SolenoidGroup1);
  InitializeSolenoidGroup(SolenoidGroup2);
  InitializeSolenoidGroup(SolenoidGroup3);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void InitializeSolenoidGroup(int[] solenoidGroup)
{
  for (int solenoidPin : solenoidGroup) 
  {
    pinMode(solenoidPin, OUTPUT);
  }
}

void TriggerSolenoidGroup(int[] solenoidGroup)
{
  for (int solenoidPin : solenoidGroup) 
  {
    TriggerSolenoid(solenoidPin);
    
    Random random = new Random();
    int delayAmount = random.nextInt(4) * 100;
    delay(delayAmount);
  }
}

void TriggerSolenoid(int solenoidPin)
{

}
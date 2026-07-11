#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int currentled;
int previousled;

int count = 0;
int laps = 0;

unsigned long starttimer;

//==================== COUNTDOWN ====================
void countdown()
{
  for(int i=3;i>=1;i--)
  {
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Starting...");

    lcd.setCursor(0,1);
    lcd.print(i);

    digitalWrite(12,HIGH);
    delay(500);

    digitalWrite(12,LOW);
    delay(500);
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Count:0");

  starttimer = millis();
}

//==================== START GAME ====================
void startGame()
{
  count = 0;
  laps = 0;

  digitalWrite(2,LOW);  // LEDs  
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);   // Change your LEDs here 
  digitalWrite(5,LOW);

  currentled = random(2,6); //  
  digitalWrite(currentled,HIGH);

  countdown();
}

//==================== WRONG BUTTON ====================
void gameOverWrong()
{
  digitalWrite(currentled,LOW);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Wrong Button");
  lcd.setCursor(0,1);
  lcd.print("Pressed!");

  for(int i=0;i<5;i++)
  {
    digitalWrite(12,HIGH);
    delay(100);

    digitalWrite(12,LOW);
    delay(100);
  }

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Press START");

  lcd.setCursor(0,1);
  lcd.print("to Restart");

  while(digitalRead(10)==HIGH);

  delay(300);

  startGame();
}

//==================== SETUP ====================
void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  randomSeed(analogRead(A0));

  pinMode(2,OUTPUT); // LEDs
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  pinMode(12,OUTPUT); // BUZZER

  pinMode(6,INPUT_PULLUP); // BUTTONS
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);

  pinMode(10,INPUT_PULLUP);      // START / STOP BUTTON

  digitalWrite(12,LOW);

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Press START");

  lcd.setCursor(0,1);
  lcd.print("Button");

  while(digitalRead(10)==HIGH);

  delay(300);

  startGame();
}
void loop()
{
  //==================== STOP BUTTON ====================
  if(digitalRead(10)==LOW)
  {
    digitalWrite(currentled,LOW);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("GAME STOPPED");
    lcd.setCursor(0,1);
    lcd.print("Press START");

    digitalWrite(12,HIGH);
    delay(300);
    digitalWrite(12,LOW);

    // Wait for button release
    while(digitalRead(10)==LOW);

    // Wait until START is pressed again
    while(digitalRead(10)==HIGH);

    delay(300);

    startGame();
    return;
  }

  //==================== BUTTON 6 ====================
  if(digitalRead(6)==LOW)
  {
    if(currentled==2)
    {
      digitalWrite(12,HIGH);
      delay(100);
      digitalWrite(12,LOW);

      count++;
      laps++;

      lcd.setCursor(0,0);
      lcd.print("Count:");
      lcd.print(laps);
      lcd.print("   ");

      digitalWrite(currentled,LOW);

      previousled=currentled;

      do                                             // checks weather same LEDs are repeating 
      {
        currentled=random(2,6);
      }
      while(currentled==previousled);

      digitalWrite(currentled,HIGH);

      delay(200);
    }
    else
    {
      gameOverWrong();                // if worng BUTTON pressed game will end 
      return;
    }
  }

  //==================== BUTTON 7 ====================
  if(digitalRead(7)==LOW)
  {
    if(currentled==3)
    {
      digitalWrite(12,HIGH);
      delay(100);
      digitalWrite(12,LOW);

      count++;
      laps++;

      lcd.setCursor(0,0);
      lcd.print("Count:");
      lcd.print(laps);
      lcd.print("   ");

      digitalWrite(currentled,LOW);

      previousled=currentled;

      do                                      // checks weather same LEDs are repeating 
      {
        currentled=random(2,6);
      }
      while(currentled==previousled);

      digitalWrite(currentled,HIGH);

      delay(200);
    }
    else
    {
      gameOverWrong();            // if worng BUTTON pressed game will end 
      return;
    }
  }
    //==================== BUTTON 8 ====================
  if(digitalRead(8)==LOW)
  {
    if(currentled==4)
    {
      digitalWrite(12,HIGH);
      delay(100);
      digitalWrite(12,LOW);

      count++;
      laps++;

      lcd.setCursor(0,0);
      lcd.print("Count:");
      lcd.print(laps);
      lcd.print("   ");

      digitalWrite(currentled,LOW);

      previousled=currentled;

      do                                    // checks weather same LEDs are repeating 
      {
        currentled=random(2,6);
      }
      while(currentled==previousled);

      digitalWrite(currentled,HIGH);

      delay(200);
    }
    else
    {
      gameOverWrong();    // if worng BUTTON pressed game will end 
      return;
    }
  }

  //==================== BUTTON 9 ====================
  if(digitalRead(9)==LOW)
  {
    if(currentled==5)
    {
      digitalWrite(12,HIGH);
      delay(100);
      digitalWrite(12,LOW);

      count++;
      laps++;

      lcd.setCursor(0,0);
      lcd.print("Count:");
      lcd.print(laps);
      lcd.print("   ");

      digitalWrite(currentled,LOW);

      previousled=currentled;

      do                                                   // checks weather same LEDs are repeating 
      {
        currentled=random(2,6);
      }
      while(currentled==previousled);

      digitalWrite(currentled,HIGH);

      delay(200);
    }
    else
    {
      gameOverWrong();    // if worng BUTTON pressed game will end 
      return;
    }
  }

  //==================== GAME COMPLETE ====================
  if(count>=35)     // ocustomize  no.of rounds according to your need 
  {
    unsigned long endtime = millis();

    unsigned long ReactionTime = endtime - starttimer - 3500;  //       calculation of reaction time & 3500 is the total delays time period 

    float ReactionTimeSeconds = ReactionTime / 1000.0;    //  conversion in seconds  

    // Game Over Sound
    for(int i=0;i<3;i++)
    {
      digitalWrite(12,HIGH);
      delay(100);

      digitalWrite(12,LOW);
      delay(100);
    }

    digitalWrite(12,HIGH);
    delay(600);
    digitalWrite(12,LOW);

    lcd.clear();
        //==================== PERFORMANCE ====================
    if(ReactionTimeSeconds <= 15)      //15 seconds 
    {
      lcd.setCursor(0,0);
      lcd.print("EXCELLENT!");

      lcd.setCursor(0,1);
      lcd.print("Pro Player");
    }
    else if(ReactionTimeSeconds <= 25)  // 25 sec
    {
      lcd.setCursor(0,0);
      lcd.print("GOOD!");

      lcd.setCursor(0,1);
      lcd.print("Keep Going");
    }
    else if(ReactionTimeSeconds <= 30) // 30+ sec 
    {
      lcd.setCursor(0,0);
      lcd.print("AVERAGE");

      lcd.setCursor(0,1);
      lcd.print("Practice");
    }
    else
    {
      lcd.setCursor(0,0);
      lcd.print("TOO SLOW!");

      lcd.setCursor(0,1);
      lcd.print("Try Again");
    }

    delay(3000);

    lcd.clear();
 // ================== dislaying the performance complement & time taken to complete game 
    lcd.setCursor(0,0);
    lcd.print("Your Time:");

    lcd.setCursor(0,1);
    lcd.print(ReactionTimeSeconds,2);
    lcd.print(" sec");

    Serial.print("Reaction Time : ");
    Serial.print(ReactionTimeSeconds);
    Serial.println(" sec");

    delay(3000);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Press START");

    lcd.setCursor(0,1);
    lcd.print("to Restart");

    while(digitalRead(10)==HIGH);

    delay(300);

    startGame();

    return;
  }
  
}   // End of loop()

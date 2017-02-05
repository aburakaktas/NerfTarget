// This #include statement was automatically added by the Particle IDE.
#include "adafruit-led-backpack/adafruit-led-backpack.h"

Adafruit_7segment matrix = Adafruit_7segment();


// passcodes
char* myStrings[] = {
  "Burak", "Apoorva", "Yang", "Dohyung", "Chaemin", "Kun", "Shangyanyan", "Michael", "Hongxuan", 
  "Zach", "Alexa", "Andrei", "Aaron","Jennifer", "Andrea", "Marty", "Asmina", "Charlie", "Xuanbai",
  "Vidya","Fanny","Andi", "nope","John"};
char* a= " ";
char id[][4] = {
  {
    '1', '2', '3', '4'  }//Burak
  , {
    '2', '3', '1', '4'  }//Apoorva
  , {
    '1', '4', '3', '2'  }//Yang
  , {
    '1', '3', '2', '4'  }//Doh
  , {
    '2', '4', '3', '1'  }//Chaemin
  , {
    '2', '2', '3', '1'  }//Kun
  , {
    '4', '3', '2', '2'  }//Yanyan
  , {
    '3', '2', '1', '1'  }//Mike
  , {
    '4', '4', '4', '4'  }//Hongxuan
  , {
    '2', '1', '1', '3'  }//Zach
  ,
  {
    '3','1','3','1'  }//Alexa
  ,
  {
    '3','3','3','3'  }
  ,//Andrei
  {
    '1','1','2','3'  }
  ,//Aaron
  {
    '3','4','4','3'  }
  ,//Jennifer
  {
    '2','2','2','2'  }
  ,//Andrea
  {
    '4','3','2','1'  }
  ,//Marty
  {
    '3','1','4','2'  }
  ,//Asmina
  {
    '4','1','1','1'  }
  ,//Charlie
  {
    '4','2','4','1'  }
  ,//Xuanbai
  {
    '4','3','1','3'  }
  ,//Vidya
  {
    '1','1','1','1'  }
  ,//Fanny
  {
    '3','3','4','4'  }
  ,//Andi
  {
    '1','1','2','2'  }
  ,//nope
  {
    '1','1','3','2'  }//John

};

char code[4];
int i = 0;
int j = 0;
int correct = 0;
int length=24;

//rgb100
const int button100r = B1;
const int button100g = B2;
const int button100b = B3;


//keypad buttons
const int button1 = A1; // the number of the pushbutton pin
const int button2 = A2;
const int button3 = A3; // the number of the pushbutton pin
const int button4 = A4;


// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;         // variable for reading the pushbutton status
int buttonState4 = 0;

// targetbuttons
const int button100 = D2;
const int button50 = D3;
const int button25 = D4;
const int button10 = D5;
const int buttonf = D6; //finish button

//leds
const int led100 = C1;
const int led50 = B4;
const int led25 = B5;
const int led10 = C4;
const int ledf = C5; // finish led


// variables will change:
int buttonState100 = 0; // red
int buttonState50 = 0;  // green
int buttonState25 = 0;  // blue
int buttonState10 = 0;  // yellow
int buttonStatef = 0;   // white
int score = 0;
int turn = 1;

// new variable

char* mode = "password";


void setup() {
  setColourRgb(0,0,0);
  //rgb shit delete after test

  //

#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);

  Serial.begin(9600);

  //keypad buttons
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);

  //buttons
  pinMode(button100, INPUT);
  pinMode(button50, INPUT);
  pinMode(button25, INPUT);
  pinMode(button10, INPUT);
  pinMode(buttonf, INPUT);


  //leds
  pinMode(button100r,OUTPUT);
  pinMode(button100g,OUTPUT);
  pinMode(button100b,OUTPUT);
  pinMode(led100, OUTPUT);
  pinMode(led50, OUTPUT);
  pinMode(led25, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(ledf, OUTPUT);

  //Openıng animation
  // digitalWrite(led100, HIGH);
  //delay(1000);
  //digitalWrite(led100, LOW);
  // HEllO    
  //matrix.clear();
  matrix.writeDigitRaw(0,B01110110);//H
  matrix.writeDigitRaw(1,B01111001);//E
  matrix.writeDigitRaw(3,B00110110);//ll
  matrix.writeDigitRaw(4,B00111111);//O
  matrix.writeDisplay();
  delay(5000);
}

void loop() {

  // password
  while (mode == "password") {


    matrix.clear();
    matrix.writeDigitRaw(0,B01110011);//P
    matrix.writeDigitRaw(1,B01110111);//A
    matrix.writeDigitRaw(3,B01101101);//S
    matrix.writeDigitRaw(4,B01101101);//S
    matrix.writeDisplay();



    Serial.println("Enter pin...");
    i = 0;
    while (i < 4)
    {
      buttonState1 = digitalRead(button1);
      buttonState2 = digitalRead(button2);
      buttonState3 = digitalRead(button3);
      buttonState4 = digitalRead(button4);
      if (buttonState1 == HIGH)
      {
        code[i] = '1';
        Serial.println(code[i]);
        i++;
        delay(250);

      }
      else if (buttonState2 == HIGH)
      {
        code[i] = '2';
        Serial.println(code[i]);
        i++;
        delay(250);

      }
      else if (buttonState3 == HIGH)
      {
        code[i] = '3';
        Serial.println(code[i]);
        i++;
        delay(250);

      }
      else if (buttonState4 == HIGH)
      {
        code[i] = '4';
        Serial.println(code[i]);
        i++;
        delay(250);

      }
      //Serial.println(code[i]);
    }

    //exit(0);
    boolean found = false;
    for (i = 0; i < length; i++)
    {
      for (j = 0; j < 4; j++)
      {
        //Serial.print(id[i][j]);
        //Serial.print(".");
        if (code[j] == id[i][j])
        {
          //Serial.print("yay");
          correct++;
          //Serial.print(correct);
          if (correct == 3) {
            //break;
            found = true;
          }
        }

      }

      Serial.println();
      if (found)
        break;
      correct = 0;
    }

    if (correct == 4)
    {
      //dooo
      Serial.print("Welcome to a new game ");
      Serial.println(myStrings[i]);
      matrix.print(0xD000, HEX);
      matrix.writeDisplay();
      delay(1000);
      mode = "game";
    }
    else
    {
      //boo
      Serial.print("not found");
      matrix.print(0xB000, HEX);
      matrix.writeDisplay();
      delay(500);
      matrix.print(0000, DEC);
      matrix.writeDisplay();
    }

  }



  // game
  while (mode == "game") {
    // try to print a number thats too long
    matrix.clear();
    matrix.print(score, DEC);
    matrix.writeDisplay();


    //button statesmatrix.print(0xBEEF, HEX)
    buttonState100 = digitalRead(button100);
    buttonState50 = digitalRead(button50);
    buttonState25 = digitalRead(button25);
    buttonState10 = digitalRead(button10);
    buttonStatef = digitalRead(buttonf);


    //if 100 is hit light led and increse score by 100

    if (buttonState100 == HIGH) {

      score += 100;

      Serial.print("Current score:");
      Serial.println(score);
      if(score>=400)
      {


        digitalWrite(led50, HIGH);
        digitalWrite(led25, HIGH);
        unsigned int rgbColour[3];
        rgbColour[0] = 0;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  
        for (int i = 0; i <2; i++){
          // Choose the colours to increment and decrement.
          for (int decColour = 0; decColour < 3; decColour += 1) {
            int incColour = decColour == 2 ? 0 : decColour + 1;

            // cross-fade the two colours.
            for(int i = 0; i < 255; i += 1) {

              rgbColour[decColour] -= 1;
              rgbColour[incColour] += 1;

              setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
              delay(1);
            };

          }

        }

        rgbColour[0] = 0;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  
        digitalWrite(led50, LOW);
        digitalWrite(led25, LOW);

      }
      else{
        unsigned int rgbColour[3];

        // Start off with red.
        rgbColour[0] = 0;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  
        for (int i = 0; i <2; i++){
          // Choose the colours to increment and decrement.
          for (int decColour = 0; decColour < 3; decColour += 1) {
            int incColour = decColour == 2 ? 0 : decColour + 1;

            // cross-fade the two colours.
            for(int i = 0; i < 255; i += 1) {

              rgbColour[decColour] -= 1;
              rgbColour[incColour] += 1;

              setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
              delay(1);
            };

          }

        }

        rgbColour[0] = 0;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  
        //digitalWrite(button100r, HIGH);
        //delay(1000);
        // digitalWrite(button100r, LOW);
        //digitalWrite(button100g, LOW);
        //digitalWrite(button100b, LOW);
        // digitalWrite(led100, HIGH);
        // delay(1000);
        //digitalWrite(led100, LOW);



      }
      turn++;

    }

    // 50
    if (buttonState50 == HIGH) {
      score += 50;

      Serial.print("Current score:");
      Serial.println(score);
      if(score>=400)
      {


        digitalWrite(led50, HIGH);
        digitalWrite(led25, HIGH);
        unsigned int rgbColour[3];
        rgbColour[0] = 0;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  
        for (int i = 0; i <2; i++){
          // Choose the colours to increment and decrement.
          for (int decColour = 0; decColour < 3; decColour += 1) {
            int incColour = decColour == 2 ? 0 : decColour + 1;

            // cross-fade the two colours.
            for(int i = 0; i < 255; i += 1) {

              rgbColour[decColour] -= 1;
              rgbColour[incColour] += 1;

              setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
              delay(1);
            };

          }

        }

        rgbColour[0] = 0;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  
        digitalWrite(led50, LOW);
        digitalWrite(led25, LOW);

      }
      else{
        digitalWrite(led50, HIGH);
        delay(1000);
        digitalWrite(led50, LOW);
      }

      turn++;
    }

    // 25
    if (buttonState25 == HIGH) {
      score += 25;

      Serial.print("Current score:");
      Serial.println(score);
      if(score>=400)
      {


        digitalWrite(led50, HIGH);
        digitalWrite(led25, HIGH);
        unsigned int rgbColour[3];
        rgbColour[0] = 0;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  
        for (int i = 0; i <2; i++){
          // Choose the colours to increment and decrement.
          for (int decColour = 0; decColour < 3; decColour += 1) {
            int incColour = decColour == 2 ? 0 : decColour + 1;

            // cross-fade the two colours.
            for(int i = 0; i < 255; i += 1) {

              rgbColour[decColour] -= 1;
              rgbColour[incColour] += 1;

              setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
              delay(1);
            };

          }

        }

        rgbColour[0] = 0;
        rgbColour[1] = 0;
        rgbColour[2] = 0;  
        digitalWrite(led50, LOW);
        digitalWrite(led25, LOW);

      } 
      // delay(1000);

      //digitalWrite(led50, LOW);
      //digitalWrite(led25, LOW);
      else{
        digitalWrite(led25, HIGH);
        delay(1000);
        digitalWrite(led25, LOW);
      }               
      turn++;
    }

    // 10
    if (buttonState10 == HIGH) {
      score += 10;


      Serial.print("Current score:");
      Serial.println(score);
      digitalWrite(led10, HIGH);
      delay(1000);
      digitalWrite(led10, LOW);
      turn++;

    }



    // Finish button
    if (buttonStatef == HIGH) {
      digitalWrite(ledf, HIGH);
      delay(1000);
      digitalWrite(ledf, LOW);
      Serial.print("Final score:");
      Serial.println(score);
      matrix.print(score, DEC);
      matrix.writeDisplay();
      Particle.publish("score",myStrings[i]+String(a)+String(score));
      matrix.blinkRate(2);
      delay(6000);
      matrix.blinkRate(0);
      // Particle.publish("score",String(score));
      score = 0;
      turn = 1;
      mode = "password";

    }



    // if turn == 7
    if (turn == 7) {

      Serial.print("6 shots used! your final score:") ;
      Serial.println(score);
      matrix.print(score, DEC);
      matrix.writeDisplay();
      Particle.publish("score",myStrings[i]+String(a)+String(score));
      //Particle.publish("score",myStrings[i]);
      //delay(1000);
      matrix.blinkRate(2);
      delay(6000);
      matrix.blinkRate(0);
      //Particle.publish("score",String(score));
      score = 0;
      turn = 1;
      mode = "password";
    }
  }
}// end of void loop



// rgb
void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(button100r, red);
  analogWrite(button100g, green);
  analogWrite(button100b, blue);
}



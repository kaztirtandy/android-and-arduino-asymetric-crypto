#include <String.h>
#include "BigNumber.h"


int ubahrandomi = -1;
int intdec = -1;
int led1 = 30;
int led2 = 40;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600);
  BigNumber::begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.println("Setup berhasil");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial2.available()>0){
    String command = Serial2.readString();
    long ubahcommand = command.toInt();
    Serial.print("Diterima: ");
    Serial.println(ubahcommand);

    if(ubahcommand == 1) {
      //BigNumber randoma = random(26806,26808);
      long randnumber = random(1, 1000);
      BigNumber randoma (randnumber);
      char *ubahrandomas = randoma.toString();
      String stringlagi = String(ubahrandomas);
      ubahrandomi = stringlagi.toInt();
      BigNumber e = 67;
      BigNumber n = 893;
      BigNumber d = 655;
      BigNumber tes = randoma.pow(e);
      BigNumber encrypt = tes % n;
      char *kirim = encrypt.toString();
      Serial2.write(kirim);
      Serial.print("Kirim ke android: ");
      Serial.println(kirim);
      Serial.println(tes);
      Serial.println(encrypt);
      //Serial.println(randNumb);
      Serial.println(randoma);
      Serial.println(stringlagi);
      Serial.println(ubahrandomi);
      
    }
    if(ubahcommand == ubahrandomi){
      Serial.println("Data berhasil didecrypt: ");
      Serial.println(ubahcommand);
      digitalWrite(led1, HIGH);
      Serial.println("Ignisi berhasil dilakukan");
    }
    if(ubahcommand == 3) {
      if(digitalRead(led1) == HIGH){
        digitalWrite(led2, HIGH);
        Serial.println("Starter berhasil dilakukan");
      }
      else{
        digitalWrite(led2, LOW);
        Serial.println("Stater gagal dilakukan");
      }
    }
    if(ubahcommand == 2){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
  }
}

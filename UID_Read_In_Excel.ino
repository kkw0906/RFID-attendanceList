#include<SPI.h>
//1.함수를 따로 만들기, 2.시간 찍히는거 RTC모듈말고, wifi로 바꾸기, 3.엑셀에 저장이 아닌 서버에 저장하기, 4.데이터 쌓이는거 확인
//엑셀로 데이터를 받았을때의 문제점 1. 통신오류가 생기면 데이터가 끊김, 데이터를 처음부터 다시 받아야한다.

#include<MFRC522.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#include<DS1302.h>

#define SS_PIN 10
#define RST_PIN 9
DS1302 RTC(2,3,4);

LiquidCrystal_I2C lcd(0x27,16,2);//i2c 주소값 확인 16문자에 2열

MFRC522 mfrc(SS_PIN, RST_PIN);

char *name[] = {
  "ko kwanwoo","Hong Gildong","Kim yuna"
};
int work1=0;//출근 상태 확인 변수값
int work2 = 0;
int work3 = 0;


void setup(){
  Serial.begin(9600);
  SPI.begin();
  RTC.halt(false);
  RTC.writeProtect(false);
  Serial.begin(9600);

  //초기 시간 설정할 때 실행 하고 주석 처리하고 한 번더 실행
  // RTC.setDOW(MONDAY); 
  // RTC.setTime(18,53,0);
  // RTC.setDate(3,2,2025); 
  
  mfrc.PCD_Init();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);//커서를 첫번째 문자 첫번째 라인으로 설정
  lcd.print("read the card");

  // Serial.println("CLEARDATA");//리셋
  Serial.println("LABEL,Name,Date,Time,Work");// 엑셀 첫 행 각 데이터 이름


}
void loop(){
  Time now = RTC.getTime();

  if(!mfrc.PICC_IsNewCardPresent()){
    return;
  }
  if(!mfrc.PICC_ReadCardSerial()){
    return;
  }
  String tag_uid ="";
  for(byte i = 0;i<mfrc.uid.size; i++){
    tag_uid.concat(String(mfrc.uid.uidByte[i] < 0x10 ? " 0" : " "));
    tag_uid.concat(String(mfrc.uid.uidByte[i], HEX));
  }

  tag_uid.toUpperCase();

  if(tag_uid.substring(1) == "74 69 23 00"){
    if(work1 == 0){
      Serial.print("DATA, ");
      Serial.print(name[0]);
      Serial.print(",");
      Serial.print(now.year);
      Serial.print("/");
      Serial.print(now.mon);
      Serial.print("/");
      Serial.print(now.date);
      Serial.print(",");
      Serial.print(now.hour);
      Serial.print(":");
      Serial.print(now.min);
      Serial.print(",");
      Serial.println("Start");
      work1 = 1;


      lcd.clear();
      lcd.setCursor(0,0);lcd.print(name[0]);
      delay(2000);

    }
    else{
            Serial.print("DATA, ");
      Serial.print(name[0]);
      Serial.print(",");
      Serial.print(now.year);
      Serial.print("/");
      Serial.print(now.mon);
      Serial.print("/");
      Serial.print(now.date);
      Serial.print(",");
      Serial.print(now.hour);
      Serial.print(":");
      Serial.print(now.min);
      Serial.print(",");
      Serial.println("Finish");
      work1 = 0;

      lcd.clear();
      lcd.setCursor(0,0);lcd.print(name[0]);
      delay(2000);

    }

  }
  else if(tag_uid.substring(1) == "03 D7 CB 0F"){
    if(work2 == 0){
      Serial.print("DATA, ");
      Serial.print(name[1]);
      Serial.print(",");
      Serial.print(now.year);
      Serial.print("/");
      Serial.print(now.mon);
      Serial.print("/");
      Serial.print(now.date);
      Serial.print(",");
      Serial.print(now.hour);
      Serial.print(":");
      Serial.print(now.min);
      Serial.print(",");
      Serial.println("Start");
      work2 = 1;


      lcd.clear();
      lcd.setCursor(0,0);lcd.print(name[1]);
      delay(2000);

    }
    else{
            Serial.print("DATA, ");
      Serial.print(name[1]);
      Serial.print(",");
      Serial.print(now.year);
      Serial.print("/");
      Serial.print(now.mon);
      Serial.print("/");
      Serial.print(now.date);
      Serial.print(",");
      Serial.print(now.hour);
      Serial.print(":");
      Serial.print(now.min);
      Serial.print(",");
      Serial.println("Finish");
      work2 = 0;

      lcd.clear();
      lcd.setCursor(0,0);lcd.print(name[1]);
      delay(2000);

    }

  }
  else{
    lcd.clear();
    lcd.print("error");
    Serial.println("DATA, Unknown");
    delay(2000);
    
  }

  delay(1000);
}
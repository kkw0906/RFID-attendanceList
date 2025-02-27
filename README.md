<div align="center">

### RFID 온라인 출근부

[<img src="https://img.shields.io/badge/프로젝트 기간-2024.12.23~-0000FF?style=flat&logo=&logoColor=white" />]()


</div> 

## 📝 개요
</br>
출근부를 수기로 작성 해야하는 번거러움을 줄이고, 출/퇴근 상태를 실시간으로 알 수 있게끔 함 
간단하게 출석과 퇴근 상태를 변경 가능함.


<br />

## Methods
</br>
외부 하드웨어
</br>
<img width = "350" src="https://github.com/user-attachments/assets/9e4171b6-ce7a-498b-8636-cdeb3c5fd1f4">
</br>
<br />

## 사용 모듈
| 모듈명 | 비고 |
| :-: | :-: |
| 아두이노 UNO | 센서통신및 제어 |
| RFID RC522 | rfid카드를 태그 |
| I2C LCD | lcd에 누가 태그했는지 출력 |
| mh real-time clock module2 | 태그시간 시간측정 |

<br />
## 동작 방식
arduino에 rfid카드(태그)번호를 미리 저장 시킨다.
저장된 식별번호의 카드가 rfid에 태그되면 excel에 태그된 시간, 이름, 출근상태가 기록됨.
출근상태가 start로 되어있으면 한 번더 태그 하면 출근상태가 finish로 바뀌게 되고, 시간이 기록됨.
<br/>
<img width  = "350" src ="https://github.com/user-attachments/assets/56082451-79b5-4b86-a6dc-82e946b20e9a"/>
<br/>
아두이노 소프트웨어는 arduino IDE를 이용하여 c언어로 작성함.
저장된 카드가 태그되면 해당 데이터가 PLX-DAQ메크로 프로그램을 통해서 엑셀에 기록되도록 설정함 .


<br />

## ⚙ 기술
<div>
<img width="90" src="https://github.com/user-attachments/assets/704e99a9-2f9d-4ece-bbf5-e748c64f9007"/>
<img width="90" src = "https://github.com/user-attachments/assets/9c7d4d3a-be91-434f-a251-bd06df2c5de7"/>
<img width="90" src = "https://github.com/user-attachments/assets/2c204b9b-dfbc-4835-a19b-ae916b875504"/>


<br />

## 🤔 개선해야할 부분
| 문제 | 개선방안 |
| :-: | :-: |
| PLX-DAQ의 메크로프로그램의 오류문제 | 데이터가 엑셀이 아닌 서버로 전송되도록 변경 |
| clock모듈 사용으로 인한 시간 오류 | esp-8266과 같이 wifi모듈을 사용하여 시간을 인터넷으로 받기 |
<br />
<br />


<br />

## 💁‍♂️ 프로젝트 팀원
https://github.com/kkw0906


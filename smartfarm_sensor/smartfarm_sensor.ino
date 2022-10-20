int water_pin = A0;      //수분수위센서 A0에 연결
int LED1 = 2;            // LED를 각각 디지털핀 2,3에 연결(핀을 꽂을 숫자번호를 써주면됩니다.)
int LED2 = 3;

void setup() {
  Serial.begin(9600);    
  pinMode( 2,   OUTPUT);  // 디지털핀 2,3를 출력으로 설정
  pinMode( 3,   OUTPUT);
  pinMode(A0, INPUT);

  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(12,OUTPUT);
}

void loop(){
  int val = analogRead(A0);   // 수분수위센서값을 'val'에 저장 
  Serial.println(val);       // 센서값을 시리얼 모니터로 출력
  delay(100);  
  
  if(val <= 200){              // 센서값이 400 이하면 모든 LED OFF
    digitalWrite( 2, LOW);
    digitalWrite( 3, LOW);
    delay(100);
  }
   else if( 200 < val && val <= 350 ){   // 400 < 센서값 ≤500 이면 빨간 LED ON
    digitalWrite( 2, HIGH);
    digitalWrite( 3, LOW);      
    delay(100);
  }
   else{                                 //그 이상이면 파란색 ON
    digitalWrite( 2, HIGH);          
    digitalWrite( 3, HIGH);          
    delay(100);
  }

  int val2=0;
  val2=digitalRead(7);
  if(val2==1){
    digitalWrite(12,HIGH);
    Serial.println("Tilt Switch ON!");
  }
  else {
    digitalWrite(12,LOW);
    Serial.println("Tilt Switch off!");
  }
  delay(100);


}
//[출처] [모듈] 물높이 센서 사용하기|작성자 메이크샌드박스, 유튜브 아두이노 기울기센서

 int gaz_deger;//gaz sensöründen okunan gaz değeri
 int led_k1=2;//kırmızı led1
 int led_k2=3;//kırmızı led2
 int buzzer=4;
void setup() {
 Serial.begin(9600);
 pinMode(led_k1,OUTPUT);//led çıkışı
 pinMode(led_k2,OUTPUT);//led çıkışı
 pinMode(buzzer, OUTPUT);
}

void loop() {
 gaz_deger=analogRead(A0);//co2 gaz değeri okunuyor

 Serial.print(gaz_deger);//değeri bilgisayar ekranına yazılıyor
 Serial.print("ppm");
 Serial.println("");
 delay(500);
 if(gaz_deger>10){
  digitalWrite(led_k1,HIGH);//900 ppm den büyükse ledler yansın
  digitalWrite(led_k2,HIGH);//
  tone(buzzer,1000,150);
  delay(1000);
 }
 else{
  digitalWrite(led_k1, LOW);
  digitalWrite(led_k2, LOW);
  noTone(buzzer);
 }
}

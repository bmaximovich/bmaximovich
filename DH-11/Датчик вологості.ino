#include <dht11.h>      // Добавляем библиотеку DHT11
dht11 DHT;               // Объявление переменной класса dht11
#define DHT11_PIN 4     // Датчик DHT11 подключен к цифровому пину номер 4

void setup(){
  Serial.begin(9600);   // Скорость работы порта
  Serial.println("DHT TEST PROGRAM "); // Выводим текст
  Serial.print("LIBRARY VERSION: ");   // Выводим текст
  Serial.println(DHT11LIB_VERSION);
  Serial.println();                    // Пустая строка 
}

void loop(){
  int chk;
  // Мониторинг ошибок
  chk = DHT.read(DHT11_PIN);    // Чтение данных
  switch (chk){
  case DHTLIB_OK:  
    break;
  case DHTLIB_ERROR_CHECKSUM:
    Serial.println("Checksum error, \t");
    break;
  case DHTLIB_ERROR_TIMEOUT:
    Serial.println("Time out error, \t");
    break;
  default:
    Serial.println("Unknown error, \t");
    break;
  }
  // Выводим показания влажности и температуры
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity, 1);
  Serial.print(", Temp = ");
  Serial.println(DHT.temperature,1);
  delay(1000);
}

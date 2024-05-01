#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>

#define I2C_SCL 17
#define I2C_SDA 16

Adafruit_ADS1115 ads;
int analog_value = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Testing Analog Input Expansion Module");

  Wire.begin(16,17);

  if (!ads.begin(0x48)) {
    Serial.println("Failed to initialize ADS.");
    while (1);
    int analog_value =0;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t adc0, adc1, adc2, adc3;

  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
  Serial.println(""); 
delay(500); 
  Serial.print("AIN0: "); Serial.print(adc0+2); Serial.println("  ");
  Serial.print("AIN1: "); Serial.print(adc1+2); Serial.println("  ");
  Serial.print("AIN2: "); Serial.print(adc2+2); Serial.println("  ");
  Serial.print("AIN3: "); Serial.print(adc3+2); Serial.println("  ");

  Serial.println("");

}

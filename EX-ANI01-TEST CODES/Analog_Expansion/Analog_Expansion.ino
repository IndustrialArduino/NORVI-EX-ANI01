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
  Serial.println("\nI2C Scanner");
 
  if (ads.begin(0x48)) {
    Serial.println("Failed to initialize ADS.");
  }
  i2c_Check();
}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t adc0, adc1, adc2, adc3;

  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
  Serial.println(""); 
   
  Serial.print("AIN0: "); Serial.print(adc3); Serial.println("  ");
  Serial.print("AIN1: "); Serial.print(adc1); Serial.println("  ");
  Serial.print("AIN2: "); Serial.print(adc2); Serial.println("  ");
  Serial.print("AIN3: "); Serial.print(adc0); Serial.println("  ");
  delay(300);
  Serial.println("");
}

void i2c_Check(){
  byte error, address;
  int deviceCount = 0;
  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");

      deviceCount++;
      delay(1);  // Wait for a moment to avoid overloading the I2C bus
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }

  if (deviceCount == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("Scanning complete\n");
  }
  delay(1000);
}

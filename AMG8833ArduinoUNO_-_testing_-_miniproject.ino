#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(10);   // Wait for serial port to connect

  // Initialize AMG8833 sensor
  
  if (!amg.begin()) {
    Serial.println("Could not find a valid AMG8833 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  // Read temperature values from the sensor
  float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
  amg.readPixels(pixels);

  // Display temperature values on Serial Monitor
  Serial.println("Thermal Camera Data:");
  for (int i = 1; i <= AMG88xx_PIXEL_ARRAY_SIZE; i++) {
    Serial.print(pixels[i - 1]);
    Serial.print("\t");
    // Break the line after 8 values (8x8 grid)
    if (i % 8 == 0) {
      Serial.println();
    }
  }
  Serial.println();

  delay(1000); // Adjust the delay based on your application requirements
}

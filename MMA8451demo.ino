#include <Adafruit_MMA8451.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();
Adafruit_MMA8451 mma2 = Adafruit_MMA8451();

void setup(void) {
  Serial.begin(9600);

  if (!mma.begin(29)) {
    Serial.println("Couldnt start");
   while (1);
  }

  if (!mma2.begin(28)) {
    Serial.println("Couldnt start");
   while (1);
  }

  mma.setRange(MMA8451_RANGE_2_G);
  mma2.setRange(MMA8451_RANGE_2_G);
}

void loop() {
  Serial.print("[");
  printData(mma, 1); Serial.println(",");
  printData(mma2, 2);
  Serial.println("];");
  delay(500);
}

void printData(Adafruit_MMA8451 mma, int id) {
    // Read the 'raw' data in 14-bit counts
  mma.read();
  Serial.print("{\"x\": \""); Serial.print(mma.x); 
  Serial.print("\", \"y\": \""); Serial.print(mma.y); 
  Serial.print("\", \"z\": \""); Serial.print(mma.z);
  

  /* Get a new sensor event */ 
  sensors_event_t event; 
  mma.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\", \"acc_x\": \""); Serial.print(event.acceleration.x);
  Serial.print("\", \"acc_y\": \""); Serial.print(event.acceleration.y);
  Serial.print("\", \"acc_z\": \""); Serial.print(event.acceleration.z); 
  
  /* Get the orientation of the sensor */
  uint8_t o = mma.getOrientation();
  
  Serial.print("\", \"direction\": \"");
  switch (o) {
    case MMA8451_PL_PUF: 
      Serial.print("Portrait Up Front");
      break;
    case MMA8451_PL_PUB: 
      Serial.print("Portrait Up Back");
      break;    
    case MMA8451_PL_PDF: 
      Serial.print("Portrait Down Front");
      break;
    case MMA8451_PL_PDB: 
      Serial.print("Portrait Down Back");
      break;
    case MMA8451_PL_LRF: 
      Serial.print("Landscape Right Front");
      break;
    case MMA8451_PL_LRB: 
      Serial.print("Landscape Right Back");
      break;
    case MMA8451_PL_LLF: 
      Serial.print("Landscape Left Front");
      break;
    case MMA8451_PL_LLB: 
      Serial.print("Landscape Left Back");
      break;
    }
  Serial.print("\", \"id\": \""); Serial.print(id);
  Serial.print("\"}");
}

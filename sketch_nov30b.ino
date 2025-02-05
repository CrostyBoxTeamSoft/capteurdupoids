

#include "HX711.h" //This library can be obtained here http://librarymanager/All#Avia_HX711

#define calibration_factor 11380.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define LOADCELL_DOUT_PIN  3
#define LOADCELL_SCK_PIN  2

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 scale demo");

 scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  Serial.println("HX711 scale demo");
  scale.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0

  Serial.println("Readings:");
}

void loop() {
  Serial.print("Reading: ");
float jauge1 = (scale.get_units(), 1);
jauge1 = jauge1/10;  
  Serial.print(jauge1); //scale.get_units() returns a float
  Serial.print(" kgs"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();
}

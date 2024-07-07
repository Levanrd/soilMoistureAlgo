int relayPin = 4;
int sensor_pin = A0;
int output_value;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

void loop() {
  output_value = analogRead(sensor_pin);
  
  // Print raw sensor value for debugging
  Serial.print("Raw Sensor Value: ");
  Serial.println(output_value);
  
  // Adjust the mapping range based on your sensor's calibration
  output_value = map(output_value, 550, 10, 0, 100);
  
  // Print mapped moisture percentage
  Serial.print("Moisture: ");
  Serial.print(output_value);
  Serial.println("%");
  
  // Adjust the threshold as needed
  if (output_value > 30) { // Example threshold, adjust as needed
    digitalWrite(relayPin, LOW); // Turn on the pump (assuming LOW activates the relay)
    Serial.println("Watering the plant...");
  } else {
    digitalWrite(relayPin, HIGH); // Turn off the pump
    Serial.println("Soil moisture is sufficient.");
  }
  
  delay(1000); // Wait for a moment before taking the next reading
}

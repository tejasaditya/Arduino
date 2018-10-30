int sensorPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
 
/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
}
 
void loop()                     // run over and over again
{
 //getting the voltage reading from the temperature sensor
 int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 //Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
 Serial.print(temperatureC); Serial.println(" degrees C");
 
 delay(1000);                                     //waiting a second
 if(temperatureC > 33)
 {
  digitalWrite(13,HIGH);
 }
 else
 {
  digitalWrite(13, LOW);
 }
}
  /*void loop();  
  {
  digitalWrite(13, HIGH); // turn the LED on (HIGH is the voltage level) 
  delay(500); 
  digitalWrite(13,LOW);
  }
  digitalWrite(12, LOW); 
}
else
{
  digitalWrite(13, LOW);
  void loop();
  {
  digitalWrite(12, HIGH); // turn the LED on (HIGH is the voltage level) 
  delay(5); 
  digitalWrite(12,LOW);
  delay(5);
  }
}*/



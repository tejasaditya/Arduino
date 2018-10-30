/*

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/

int sensorPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
const int numReadings = 3;
float temperatureC;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
float total = 0;                  // the running total
float average = 0;                // the average


#define BANDGAPREF 14   // special indicator that we want to measure the bandgap

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
  for (int thisReading = 0; thisReading < numReadings; thisReading++) 
  {
    readings[thisReading] = 0;
  }
     pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
}


void loop()                     // run over and over again
{
  // get voltage reading from the secret internal 1.05V reference
  int refReading = analogRead(BANDGAPREF);  
  //Serial.println(refReading);

  // now calculate our power supply voltage from the known 1.05 volt reading
  float supplyvoltage = (1.05 * 1024) / refReading;
  //Serial.print(supplyvoltage); Serial.println("V power supply");

  //getting the voltage reading from the temperature sensor
  int reading = analogRead(sensorPin);  
  delay(500); 

  // converting that reading to voltage
  float voltage = reading * supplyvoltage / 1024; 

  // print out the voltage
  //Serial.print(voltage); Serial.println(" volts");

  // now print out the temperature
  temperatureC = (voltage - 0.5) * 100 ;   //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((volatge - 500mV) times 100)
 // Serial.print(temperatureC); Serial.println(" degress C");

  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = temperatureC;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.println(average);
         // delay in between reads for stability
}
  // now convert to Fahrenheight
//  float temperatureF = (temperatureC * 9 / 5) + 32;
  //Serial.print(temperatureF); Serial.println(" degress F");

                                      //waiting a second
/* if(temperatureC > 35)
 //{
  digitalWrite(13, HIGH); // turn the LED on (HIGH is the voltage level)  
  digitalWrite(12, LOW); 

      delay(1000);
// }
// else
// {
  digitalWrite(13, LOW);
  digitalWrite(12,HIGH);
// }
 delay(100);
}*/


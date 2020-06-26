/*******************************************************
 * Firmware
 * Team Simple
 * Standalone Self Regulated Oxygen Delivery System
 * 
 *********  Author: 
 * Nammelo
 ********* Co-Authors: 
 * Asma
 * Jie
 * Muhammed
 * Jenny
 * Ikwuo
 * Obert
 * Terrence
 * Botshelo
 *********
 *Elizabeth Johansen -Mentor
 *Jet Lim -Mentor
 *Wasswa -Mentor
 * 
 * 
 *            ********************
 *            *****25/06/2020*****
 *            ********************
 *            ********************
 *            ***UBORA BOOTCAMP***
 *            ********2020********
 *            ********************
 *            ********************
 * 
********************************************************/
// Include Libraries
#include "Arduino.h"
#include "Fan.h"
#include "Relay.h"
#include "SolenoidValve.h"


// Pin Definitions
#define PCFAN_PIN_COIL1	4
#define PIEZOVIBRATION_PIN_NEG	A10
#define RELAYMODULE_PIN_SIGNAL	6
#define SOLENOIDVALVE_PIN_COIL1	5
#define WATERFLOW_5V1_1_PIN_SIG	2
#define WATERFLOW_5V2_2_PIN_SIG	3
#define WATERPRESSURESENSOR_5V1_1_PIN_SIG	A0
#define WATERPRESSURESENSOR_5V2_2_PIN_SIG	A3
#define WATERPRESSURESENSOR_5V3_3_PIN_SIG	A13



// Global variables and defines

// object initialization
Fan PCFan(PCFAN_PIN_COIL1);
Relay relayModule(RELAYMODULE_PIN_SIGNAL);
SolenoidValve solenoidValve(SOLENOIDVALVE_PIN_COIL1);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1')
    {
    // Disclaimer: The SparkFun Particle Sensor Breakout - MAX30105 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '2') {
    // PC Fan 12V - Test Code
    // The PC Fan will turn on for 2000ms and off for 4000ms (4 sec)
    PCFan.on(); // 1. turns on
    delay(2000);       // 2. waits 2000 milliseconds (2 sec).
    PCFan.off();// 3. turns off
    delay(4000);       // 4. waits 4000 milliseconds (4 sec).

    }
    else if(menuOption == '3')
    {
    // Disclaimer: The Piezo Vibration Sensor - Large with Mass is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '4') {
    // Relay Module - Test Code
    // The relay will turn on and off for 500ms (0.5 sec)
    relayModule.on();       // 1. turns on
    delay(500);             // 2. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    relayModule.off();      // 3. turns off.
    delay(500);             // 4. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }
    else if(menuOption == '5') {
    // 12V Solenoid Valve - 3/4'' - Test Code
    // The solenoid valve will turn on and off for 500ms (0.5 sec)
    solenoidValve.on(); // 1. turns on
    delay(500);       // 2. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    solenoidValve.off();// 3. turns off
    delay(500);       // 4. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.

    }
    else if(menuOption == '6')
    {
    // Disclaimer: The Water Flow Sensor G1/2'' #1 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '7')
    {
    // Disclaimer: The Water Flow Sensor G1/2'' #2 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '8')
    {
    // Disclaimer: The Gravity: Analog Water Pressure Sensor #1 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '9')
    {
    // Disclaimer: The Gravity: Analog Water Pressure Sensor #2 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '10')
    {
    // Disclaimer: The Gravity: Analog Water Pressure Sensor #3 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) SparkFun Particle Sensor Breakout - MAX30105"));
    Serial.println(F("(2) PC Fan 12V"));
    Serial.println(F("(3) Piezo Vibration Sensor - Large with Mass"));
    Serial.println(F("(4) Relay Module"));
    Serial.println(F("(5) 12V Solenoid Valve - 3/4''"));
    Serial.println(F("(6) Water Flow Sensor G1/2'' #1"));
    Serial.println(F("(7) Water Flow Sensor G1/2'' #2"));
    Serial.println(F("(8) Gravity: Analog Water Pressure Sensor #1"));
    Serial.println(F("(9) Gravity: Analog Water Pressure Sensor #2"));
    Serial.println(F("(10) Gravity: Analog Water Pressure Sensor #3"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing SparkFun Particle Sensor Breakout - MAX30105 - note that this component doesn't have a test code"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing PC Fan 12V"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing Piezo Vibration Sensor - Large with Mass - note that this component doesn't have a test code"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing Relay Module"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing 12V Solenoid Valve - 3/4''"));
    		else if(c == '6') 
    			Serial.println(F("Now Testing Water Flow Sensor G1/2'' #1 - note that this component doesn't have a test code"));
    		else if(c == '7') 
    			Serial.println(F("Now Testing Water Flow Sensor G1/2'' #2 - note that this component doesn't have a test code"));
    		else if(c == '8') 
    			Serial.println(F("Now Testing Gravity: Analog Water Pressure Sensor #1 - note that this component doesn't have a test code"));
    		else if(c == '9') 
    			Serial.println(F("Now Testing Gravity: Analog Water Pressure Sensor #2 - note that this component doesn't have a test code"));
    		else if(c == '10') 
    			Serial.println(F("Now Testing Gravity: Analog Water Pressure Sensor #3 - note that this component doesn't have a test code"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

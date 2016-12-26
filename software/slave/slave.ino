// Code for the slave arduino

#include <ArduinoTestShield.h>

/* 
 *  ArduinoTestShield.h provides:
 *  
 *  void (*methodPtrs[numTests])();  // an array of test function pointers 
 *  String testIDs[numTests];        // an array of test function IDs
 *  int numTests;                    // the length of both methodPtrs and testIDs
 *  void initializeTestArrays();     // initializes methodPtrs and testIDs
 *  
 *  methodPtrs and testIDs are indexed in parallel -- methodPtrs[0] goes with testIDs[0], etc
 */ 

void setup() {
  Serial.begin(9600);
  String query = Serial.readStringUntil('\n');
  Serial.println(query);
}

void loop() {
  String testID = Serial.readStringUntil('\n');
  for(int i = 0; i < numTests; i++){
    if(testID == testIDs[i]) (*methodPtrs[i])();
    break;
  }
}

void digitalReadTest(){
  
}

void digitalWriteTest(){
  
}


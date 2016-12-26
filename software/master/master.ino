// Code for the master arduino

#include <SoftwareSerial.h>

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

int slaveRX = 10, slaveTX = 11;


SoftwareSerial slave(slaveRX, slaveTX);

void setup() {
  initializeTestArrays();
  Serial.begin(9600);
  Serial.println("Program Started");
  for(int i = 0; i < numTests; i++){
    slave.println(testIDs[i]);
    (*methodPtrs[i])();
    log("\n\n");
  }
  Serial.println("All tests complete!");
}

// test methods:

void initializeTest(){
  log("Initializing software serial connection with slave...");
  slave.begin(9600);
  success();
  String handshake = "gremlins";
  slave.println(handshake);
  delay(1000);
  if(slave.available() > 0){
    String response = slave.readStringUntil('\n');
    if(response == handshake){
      success();
    } else {
      error("Slave failed handshake");
    }
  } else {
    error("Timed out waiting for slave to handshake");
  }
  log("Initialization complete.");
}

void digitalReadTest(){
  log("Starting Digital Read Test...\n");
  for(int i = 0; i < 13; i++){
    
  }
}

void digitalWriteTest(){
  //for(int i = 0; i < 
}

// utility methods:

void success(){
  log("OK");
}

void log(String str){
  Serial.print(str);
}

void error(String str){
  log("ERROR: " + str);
}

void die(){
  log("Terminating...");
  while(true){;}
}

void loop() {
  
}



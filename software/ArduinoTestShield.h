const int numTests = 10;
void (*methodPtrs[numTests])();
String testIDs[numTests];

void digitalReadTest();
void digitalWriteTest();

void initializeTestArrays(){
    testIDs[0] = "DRT"; methodPtrs[0] = digitalReadTest;
    testIDs[1] = "DWT"; methodPtrs[1] = digitalWriteTest;
}
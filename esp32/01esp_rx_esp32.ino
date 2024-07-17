#include <SPI.h>
#include <stdint.h>

// Define the SPI pin numbers for ESP32
const int SPI_SCK = 18;  // Serial Clock
const int SPI_MISO = 19; // Master In Slave Out
const int SPI_MOSI = 23; // Master Out Slave In
const int SPI_SS = 5;    // Slave Select

char dataBuff[500];

// Initialize SPI slave
void SPI_SlaveInit(void) {
  // Initialize SPI pins
  pinMode(SPI_SCK, INPUT);
  pinMode(SPI_MOSI, INPUT);
  pinMode(SPI_MISO, OUTPUT);
  pinMode(SPI_SS, INPUT);

  // Make SPI as slave
  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_SS);
  // Set SPI settings for slave
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
}

// This function returns SPI transfer data
uint8_t SPI_SlaveReceive(void) {
  while (!SPI.available());
  return SPI.transfer(0x00);
}

// Sends one byte of data
void SPI_SlaveTransmit(char data) {
  SPI.transfer(data);
}

// The setup() function runs right after reset
void setup() {
  // Initialize serial communication 
  Serial.begin(9600);
  // Initialize SPI Slave
  SPI_SlaveInit();
  Serial.println("Slave Initialized");
}

// The loop function runs continuously after setup
void loop() {
  uint32_t i;
  uint16_t dataLen = 0;
  Serial.println("Slave waiting for SS to go low");

  // Wait until SS is pulled low
  while (digitalRead(SPI_SS));

  i = 0;
  dataLen = SPI_SlaveReceive();

  for (i = 0; i < dataLen; i++) {
    dataBuff[i] = SPI_SlaveReceive();
  }

  // Null-terminate the received string
  dataBuff[i] = '\0';

  Serial.println("Rcvd:");
  Serial.println(dataBuff);
  Serial.print("Length:");
  Serial.println(dataLen);
}


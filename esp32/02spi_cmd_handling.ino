#include <SPI.h>

// Define the SPI pin numbers for ESP32
const int SCK = 18;    // Serial Clock.
const int MISO = 19;   // Master In Slave Out.
const int MOSI = 23;   // Master Out Slave In.
const int SS = 5;      // Slave Select.
const int led = 9;     // Slave LED digital I/O pin.

boolean ledState = HIGH; // LED state flag.
uint8_t dataBuff[255];
uint8_t board_id[10] = "ESP32";
#define NACK 0xA5
#define ACK 0xF5

// Command codes
#define COMMAND_LED_CTRL      0x50
#define COMMAND_SENSOR_READ   0x51
#define COMMAND_LED_READ      0x52
#define COMMAND_PRINT         0x53
#define COMMAND_ID_READ       0x54

#define LED_ON  1
#define LED_OFF 0

// ESP32 analog pins
#define ANALOG_PIN0  36  // ADC1_CHANNEL_0
#define ANALOG_PIN1  39  // ADC1_CHANNEL_3
#define ANALOG_PIN2  34  // ADC1_CHANNEL_6
#define ANALOG_PIN3  35  // ADC1_CHANNEL_7
#define ANALOG_PIN4  32  // ADC1_CHANNEL_4

// Initialize SPI slave
void SPI_SlaveInit(void) {
  // Initialize SPI pins
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(MISO, OUTPUT);
  pinMode(SS, INPUT);
  // Make SPI as slave
  SPI.begin(SCK, MISO, MOSI, SS);
  // Enable SPI as slave
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
}

// This function returns SPDR contents 
uint8_t SPI_SlaveReceive(void) {
  while (!SPI.available());
  return SPI.transfer(0x00);
}

// Sends one byte of data
void SPI_SlaveTransmit(uint8_t data) {
  SPI.transfer(data);
}

// The setup() function runs after reset
void setup() {
  // Initialize serial for troubleshooting
  Serial.begin(9600);
  
  // Initialize slave LED pin
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  
  // Initialize SPI Slave
  SPI_SlaveInit();
  
  Serial.println("Slave Initialized");
}

byte checkData(byte command) {
  //todo
  return ACK;
}

// The loop function runs continuously after setup
void loop() {
  byte data, command, len, ackornack = NACK;
  
  // 1. First make sure that SS is low. Wait until SS is low
  Serial.println("Slave waiting for SS to go low");
  while (digitalRead(SS));
  
  // 2. Now wait until RX buffer has a byte
  command = SPI_SlaveReceive();
  ackornack = checkData(command);
  
  SPI_SlaveTransmit(ackornack);
  
  len = SPI_SlaveReceive(); // Dummy byte
  
  if (command == COMMAND_LED_CTRL) {
    // Read 2 more bytes: pin number and value 
    uint8_t pin = SPI_SlaveReceive(); 
    uint8_t value = SPI_SlaveReceive(); 
    Serial.println("RCVD: COMMAND_LED_CTRL");
    if (value == LED_ON) {
      digitalWrite(pin, HIGH);
    } else if (value == LED_OFF) {
      digitalWrite(pin, LOW);
    }
  } else if (command == COMMAND_SENSOR_READ) {
    // Read analog pin number 
    uint16_t aread;
    uint8_t pin = SPI_SlaveReceive(); 
    uint8_t val;
    aread = analogRead(pin);  // For ESP32, you might need to map the pin correctly
    val = map(aread, 0, 4095, 0, 255); // ESP32 ADC resolution is 12-bit (0-4095)
    
    SPI_SlaveTransmit(val);
    val = SPI_SlaveReceive(); // Dummy read
    
    Serial.println("RCVD: COMMAND_SENSOR_READ");
  } else if (command == COMMAND_LED_READ) {
    uint8_t pin = SPI_SlaveReceive(); 
    uint8_t val = digitalRead(pin);
    SPI_SlaveTransmit(val);
    val = SPI_SlaveReceive(); // Dummy read
    Serial.println("RCVD: COMMAND_LED_READ");
  } else if (command == COMMAND_PRINT) {
    uint8_t len = SPI_SlaveReceive(); 
    for (int i = 0; i < len; i++) {
      dataBuff[i] = SPI_SlaveReceive();
    }
    Serial.println((char*)dataBuff);
    Serial.println("RCVD: COMMAND_PRINT");
  } else if (command == COMMAND_ID_READ) {
    for (int i = 0; i < strlen(board_id); i++) {
      SPI_SlaveTransmit(board_id[i]);
    }
    SPI_SlaveReceive(); // Dummy receive
    Serial.println("RCVD: COMMAND_ID_READ");
  }
}


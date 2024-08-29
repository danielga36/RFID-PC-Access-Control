#include <Keyboard.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 5
#define KEY_RETURN 0xB0 // Hex value for the return key

const int buttonPin = 2; 
int buttonState = 0;  
MFRC522 mfrc522(SS_PIN, RST_PIN);
char Enter = KEY_RETURN; // Return key is used as Enter
String readid;
String card1 = "99298d99"; // Change this value to the UID of your card

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600); // Start serial monitor for card detection
  Keyboard.begin();
  SPI.begin();
  mfrc522.PCD_Init();
}

void temp(byte *buffer, byte bufferSize) {
  readid = "";
  for (byte i = 0; i < bufferSize; i++) {
    readid += String(buffer[i], HEX);
  }
}

void loop() {
  // Check if a new card is present
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  
  // Read the card serial number
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  
  // Dump card details to serial monitor
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
  // Convert card UID to string
  temp(mfrc522.uid.uidByte, mfrc522.uid.size);

  buttonState = digitalRead(buttonPin);
  
  // If button is pressed and card UID matches
  if (buttonState == LOW && readid == card1) {
    // Perform Gmail login
    Keyboard.print("gmailusername@gmail.com"); // Change to your Gmail username
    Keyboard.releaseAll();
    delay(100);
    Keyboard.press(Enter);
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print("other passwords"); // Change to your password
    Keyboard.releaseAll();
    delay(100);
    Keyboard.press(Enter);
    Keyboard.releaseAll();
  }
  // If button is not pressed and card UID matches
  else if (buttonState == HIGH && readid == card1) {
    // Lock the PC
    Keyboard.press(KEY_LEFT_GUI); // Press the Windows key
    Keyboard.press('l'); // Press the 'l' key to lock the PC
    Keyboard.releaseAll();
    delay(100);
    
    // Unlock the PC
    Keyboard.press(Enter); // Press Enter key
    Keyboard.release(Enter);
    delay(100);
    Keyboard.print(" WINDOWS PASSWORD "); // Change to your Windows PIN/Password
    Keyboard.releaseAll();
    delay(100);
    Keyboard.press(Enter);
    Keyboard.releaseAll();
  } 
  else {
    return;
  }
}

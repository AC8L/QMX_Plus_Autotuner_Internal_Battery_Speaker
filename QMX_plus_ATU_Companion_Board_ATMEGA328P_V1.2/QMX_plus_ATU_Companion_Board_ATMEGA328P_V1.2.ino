// Firware for the ATU Companion Board for ABS solution for QMX+
// by Sardar Azari (AC8L)
// ver 1.0, October 7, 2024
// ver 1.1, November 16, 2024
// ver 1.2, January 5, 2025
// Firmware uses single button to emulate autotune on, off and reset functions of the ATU
// that otherwise requires 3 different buttons
// Firmware also uses OneButton library to detect autotune status using ATU status LED's as emulated button press actions
//
// V1.1 - added ATU BYPASS button control
// V1.2 - fix for button freeze
//
#include <Arduino.h>
#include <OneButton.h>

const int buttonPin = 2; // the input used for the single button
const int out2_atu_autotune_btn = 8; // define output connected to ATU AUTOTUNE button
const int out2_atu_reset_btn = 9; // define output connected to ATU RESET button
const int out2_atu_bypass_btn = 7; // define output connected to ATU BYPASS button

const int input_atu_auto_status_led_pin = 10; // define input - this is an autotune status LED connected to the port RB7 of the PIC16F1938 on the ATU
const int input_atu_reset_status_led_pin = 5; // define input - this is a rset 'in-progress' status LED connected to the port RB6 of the PIC16F1938 on the ATU

volatile int atuOption_pressed = 0;  // variable for reading the pushbutton status
volatile int atuAutotune_active = 0; // variable for reading the status of ATU autotune
volatile int atuReset_active = 0;    // variable for reading the status of ATU reset

volatile unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 150; //the value is a number of milliseconds, ie 1 second

OneButton myBtn; // our single physical button
OneButton atuStatus; // will simulate the atu autotune status LED as a virtual button. LED should be wired to the arduino pin through optocoupler and resistor
OneButton atuReset;  // will simulate the atu reset status LED as a virtual button. LED should be wired to the arduino pin through optocoupler and resistor

void setup() {
  //delay(1500); // Let ATU start...
  Serial.begin(115200);
  
  // initialize our single push button connected to Aarduino
  //pinMode(buttonPin, INPUT_PULLUP); // better to pullup inputs and switch them low, this uses internal pullups
  myBtn.setup(
  buttonPin,    // Input pin for the button
  INPUT_PULLUP, // INPUT and enable the internal pull-up resistor
  true          // Button is active LOW
  );
  // Button Pressed event attachment
  myBtn.attachPress(handlePress);
  // Single Click event attachment
  myBtn.attachClick(handleClick);
  // Double Click event attachment
  //myBtn.attachDoubleClick(handleDoubleClick);
  // Long Press event attachment
  myBtn.attachLongPressStart(handleLongPressStart);
  myBtn.attachLongPressStop(handleLongPressStop);

  // initialize atuStatus virtual button
  atuStatus.setup(
  input_atu_auto_status_led_pin,    // Input pin for the button
  INPUT_PULLUP, // INPUT and enable the internal pull-up resistor
  true          // Button is active LOW
  );
  atuStatus.attachPress(handleAutotuneON);
  atuStatus.attachClick(handleAutotuneOFF);
  atuStatus.attachLongPressStop(handleAutotuneOFF);

  // initialize atuReset virtual button
  atuReset.setup(
  input_atu_reset_status_led_pin,    // Input pin for the button
  INPUT_PULLUP, // INPUT and enable the internal pull-up resistor
  true          // Button is active LOW
  );
  atuReset.attachPress(handleResetStarted);
  atuReset.attachClick(handleResetCompleted);
  atuReset.attachLongPressStop(handleResetCompleted);

  // initialize outputs connected to ATU-100 buttons
  pinMode(out2_atu_autotune_btn, OUTPUT); // better to pullup inputs and switch them high, this uses optocoupler to short the GND to ATU button
  digitalWrite(out2_atu_autotune_btn, LOW);
  pinMode(out2_atu_reset_btn, OUTPUT); // better to pullup inputs and switch them high, this uses optocoupler to short the GND to ATU button
  digitalWrite(out2_atu_reset_btn, LOW);

  Serial.println();
  Serial.println("ABS ATU companion board firmware V1.2 initialized.");

  if (digitalRead(input_atu_auto_status_led_pin) == LOW) {
    Serial.println("Autotune status is ON");
    atuAutotune_active = 1;
  }
  else Serial.println("Autotune status is OFF");

  if (digitalRead(input_atu_reset_status_led_pin) == LOW) {
    Serial.println("Reset status is IN-PROGRESS");
    atuReset_active = 1;
  }
  else Serial.println("Reset status is COMPLETED.");
}

void loop() {
  myBtn.tick();
  //atuStatus.tick();
  //atuReset.tick();

  if (atuOption_pressed == 1) {
    currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
    if (currentMillis - startMillis >= period)  //test whether the period has elapsed
    {
      digitalWrite(out2_atu_autotune_btn, LOW);
      digitalWrite(out2_atu_reset_btn, LOW);
      startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
      atuOption_pressed = 0;
    }
  }

}

// Handler function for a press event (as soon as press is detected)
static void handlePress() {
    Serial.println("ABS Button Pressed!");
}

// Handler function for a single click (button pressed and then released):
static void handleClick() {
  Serial.println("ABS Button Single Click.");
  Serial.println("Trigger ATU Autotune ON/OFF.");
  startMillis = millis(); // Start timer
  atuOption_pressed = 1;
  digitalWrite(out2_atu_autotune_btn, HIGH);
}

// Handler function for double click:
static void handleDoubleClick() {
  if(atuReset_active==0) {
    Serial.println("ABS Button Double Click.");
    if (atuAutotune_active==0) {
      Serial.println("Autotune is OFF, turn it ON.");
      startMillis = millis(); // Start timer
      atuOption_pressed = 1;
      digitalWrite(out2_atu_autotune_btn, HIGH);
    }
  }
}

// Handler function for detecting the beginning of a long press (800ms):
static void handleLongPressStart() {
    Serial.println("ABS Button Long press started!");
}

// Handler function for detecting the end of a long press (800ms):
static void handleLongPressStop() {
  Serial.println("ABS Button Long press stopped. Pressing ATU reset button.");
  startMillis = millis(); // Start timer
  atuOption_pressed = 1;
  digitalWrite(out2_atu_reset_btn, HIGH);
}

static void handleAutotuneON() {
  if(atuReset_active==0) {
    Serial.println("Autotune detected as ON.");
    atuAutotune_active = 1;
  }
}

static handleAutotuneOFF() {
  if(atuReset_active==0) {
    Serial.println("Autotune detected as OFF.");
    atuAutotune_active = 0;
  }
}

static void handleResetStarted() {
  Serial.println("ATU reset process detected as IN-PROGRESS. Button processing during reset will be disabled.");
  atuReset_active = 1;
}

static void handleResetCompleted() {
  Serial.println("ATU reset process detected as COMPLETED. Button processing will be resumed.");
  atuReset_active = 0;
}

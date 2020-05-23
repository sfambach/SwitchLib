/**
 * Test for Non blocking switch library
 * It is possible to add 1 to n switches
 * if a switch is pressed the callback function will be called.
 * If the press time is longer than _longPressTime, it is a long press other whise it is a short one
 * 
 *   
 * Visit http://www.fambach.net for more informations
 * License GPLv2 
 */

#define DEBUG true // flag to turn on/off debugging
#define debug_begin(...) do { if (DEBUG) { Serial.begin(__VA_ARGS__); while(!Serial); }} while (0)
#define debug_print(...) do { if (DEBUG) Serial.print(__VA_ARGS__); } while (0)
#define debug_println(...) do { if (DEBUG) Serial.println(__VA_ARGS__); } while (0)
#define debug_printf(...) do { if (DEBUG) Serial.printf(__VA_ARGS__); } while (0)

// define io pins
static const uint8_t SW1 = 35;
static const uint8_t SW2 = 34;
static const uint8_t SW3 = 39;

/************************************************************/
// switchlib 

#include "SwitchLib.h"
void testCallBack(uint8_t switchPin, bool isLongPressed){

    debug_print( F("Callback "));
    if(isLongPressed){
     debug_print( F(" LongPress "));
    }

    switch (switchPin){
        case SW1:   debug_println( F(" Switch 1"));break;
        case SW2:   debug_println( F(" Switch 2 "));break;
        case SW3:   debug_println( F(" Switch 3 "));break;
    }
}

uint8_t switchList[] = {SW1,SW2,SW3};
SwitchLib switches(switchList,3,testCallBack);

/************************************************************/


void setup() {
  debug_begin(115200);
  switches.setup();
}

void loop() {
  switches.loop();
}

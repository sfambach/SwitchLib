/**
   Non blocking switch library
   It is possible to add 1 to n switches
   if a switch is pressed the callback function will be called.
   If the press time is longer than _longPressTime, it is a long press other whise it is a short one


   Visit http://www.fambach.net for more informations
   License GPLv2
*/

#ifndef switch_lib_h
#define switch_lib_h
#include <Arduino.h>


class SwitchLib {

  private:
    bool    _inverse = true;
    long    _longPressedTime; // how long is a long press of the switch;
    uint8_t _switchCount;
    uint8_t *_switches;
    long    *_switchTimes;
    void    (*_callBack)(uint8_t, bool);

    /**
        check a single switch
    */
    void checkSwitch(uint8_t switchIndex);

  public:

    /**
       default constructor
    */
    SwitchLib(uint8_t * switches, uint8_t switchCount, void (*callBack)(uint8_t, bool))
      : _switches(switches), _switchCount(switchCount),  _callBack(callBack) {
      _switchTimes = new long[_switchCount];
      for(int i = 0; i < _switchCount; i++){
        _switchTimes[i] = -1;        
      }
      _longPressedTime = 1000;
    }

    /**
        init method call this during setup
    */
    void setup();

    /**
       call this in loop
    */
    void loop();

    void setLongPressedTime(long timeMs) {
      _longPressedTime = timeMs;
    }
    
    long getLongPressedTime() {
      return _longPressedTime;
    }


};

#endif // define switch_lib_h

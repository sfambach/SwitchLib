#include "SwitchLib.h"

void SwitchLib::SwitchLib::loop(){
  for(int i =0; i < _switchCount; i++){
    checkSwitch(i);
  }
}



void SwitchLib::setup(){
  for(int i =0; i < _switchCount; i++){
    pinMode(_switches[i], INPUT_PULLUP);
  }
}

void SwitchLib::checkSwitch(uint8_t switchIndex){

    boolean state = digitalRead(_switches[switchIndex]);

    if(_inverse){
      state = !state;
    }

    // check start 
    if(_switchTimes[switchIndex] == -1 &&  state){
      _switchTimes[switchIndex] = millis();
    }
    
    if( _switchTimes[switchIndex] > 0 && !state){

      bool longPressed = false;
      if(millis() - _switchTimes[switchIndex] > _longPressedTime){
        longPressed = true;
      }
      if(_callBack){
        (*_callBack)(_switches[switchIndex], longPressed);
      }
      _switchTimes[switchIndex]=-1;
    }
}

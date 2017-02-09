/******************************************************************************
 * MoleNet - A Wireless Underground Sensor Network
 *
 * Copyright (C) 2016, Communication Networks, University of Bremen, Germany
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 *
 * This file is part of MoleNet
 *
 ******************************************************************************
 * ============================================================================
 *
 *       Filename:  rtc_test.ino
 *
 *    Description:  A sample code to set and debug time in RTC RV8523.
 *                  Arduino Sketch
 *
 *        Version:  1.0
 *        Created:  13/08/2016 15:00:00 
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Haseeb (MSc. Student-IAE University of Bremen), 
 *                  mhaseeb@uni-bremen.de, 
 *                  hasee.b@hotmail.com
 *   Organization:  COMNETS, Communication Networks Department
 *                  University of Bremen, Bremen, Germany
 *
 * ============================================================================
 */


#include "RV8523.h"
#define BAUD_RATE 115200

// Create object of RTC class
RV8523 rtc;

// Setup Function
void setup() {

  // Initialize Serial Communication
  Serial.begin(BAUD_RATE);
  while(!Serial){
    // Wait till Serial port is initialized
  }
  Serial.println("Real Time Clock Test");

  rtc.setTimeMode(RV8523::TM_24HOUR);
  //rtc.setClockTime(0,26,14, 13,8,16);
  rtc.startRTC();
  rtc.batterySwitchOver(1);

}

void loop() {

  Serial.println("");
  rtc.debugCurrentTime();
  delay(1000);

}
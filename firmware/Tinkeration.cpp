/**
****************************************************************************
* @file    tinkeration.cpp
* @authors  Satish Nair, Zachary Crockett, Mohit Bhoite; wrapped into library by Richard Whitney
* @version V0.0.1
* @date    08-August-2014
* @brief   Tinker library
****************************************************************************
 Copyright (c) 2014 Spark Labs, Inc.  All rights reserved.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this program; if not, see <http://www.gnu.org/licenses/>.
*******
*/


#include "Tinkeration.h"


void Tinkeration::begin(void){
	Spark.function("digitalread", tinkerDigitalRead);
    Spark.function("digitalwrite", tinkerDigitalWrite);
    Spark.function("analogread", tinkerAnalogRead);
    Spark.function("analogwrite", tinkerAnalogWrite);

}




int Tinkeration::tinkerDigitalRead(String pin) {
    int pinNumber = pin.charAt(1) - '0';
    if (pinNumber< 0 || pinNumber >7) return -1;
    if(pin.startsWith("D")) {
        pinMode(pinNumber, INPUT_PULLDOWN);
        return digitalRead(pinNumber);
    }
    else if (pin.startsWith("A")){
        pinMode(pinNumber+10, INPUT_PULLDOWN);
        return digitalRead(pinNumber+10);
    }
    return -2;
}

int Tinkeration::tinkerDigitalWrite(String command){
    bool value = 0;
    int pinNumber = command.charAt(1) - '0';
    if (pinNumber< 0 || pinNumber >7) return -1;
    if(command.substring(3,7) == "HIGH") value = 1;
    else if(command.substring(3,6) == "LOW") value = 0;
    else return -2;
    if(command.startsWith("D")){
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, value);
        return 1;
    }
    else if(command.startsWith("A")){
        pinMode(pinNumber+10, OUTPUT);
        digitalWrite(pinNumber+10, value);
        return 1;
    }
    else return -3;
}

int Tinkeration::tinkerAnalogRead(String pin){
    int pinNumber = pin.charAt(1) - '0';
    if (pinNumber< 0 || pinNumber >7) return -1;
    if(pin.startsWith("D")){
        pinMode(pinNumber, INPUT);
        return analogRead(pinNumber);
    }
    else if (pin.startsWith("A")){
        pinMode(pinNumber+10, INPUT);
        return analogRead(pinNumber+10);
    }
    return -2;
}

int Tinkeration::tinkerAnalogWrite(String command){
    int pinNumber = command.charAt(1) - '0';
    if (pinNumber< 0 || pinNumber >7) return -1;
    String value = command.substring(3);
    if(command.startsWith("D")){
        pinMode(pinNumber, OUTPUT);
        analogWrite(pinNumber, value.toInt());
        return 1;
    }
    else if(command.startsWith("A")){
        pinMode(pinNumber+10, OUTPUT);
        analogWrite(pinNumber+10, value.toInt());
        return 1;
    }
    else return -2;
}
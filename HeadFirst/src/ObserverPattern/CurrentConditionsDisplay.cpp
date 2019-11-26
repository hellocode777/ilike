/*
 * CurrentConditionsDisplay.cpp
 *
 *  Created on: 2019-2-24
 *      Author: root
 */

#include "CurrentConditionsDisplay.h"

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject* weatherData) {
	// TODO Auto-generated constructor stub
	this->weatherData = weatherData;
	this->weatherData->registerObserver(this);

}


CurrentConditionsDisplay::~CurrentConditionsDisplay() {
	// TODO Auto-generated destructor stub
}


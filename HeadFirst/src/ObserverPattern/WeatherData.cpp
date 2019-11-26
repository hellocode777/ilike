/*
 * WeatherData.cpp
 *
 *  Created on: 2019-2-24
 *      Author: root
 */

#include "WeatherData.h"

WeatherData::WeatherData() {
	// TODO Auto-generated constructor stub
	observers = new ArrayList();

}

WeatherData::~WeatherData() {
	// TODO Auto-generated destructor stub
	delete observers;
	observers = nullptr;
}


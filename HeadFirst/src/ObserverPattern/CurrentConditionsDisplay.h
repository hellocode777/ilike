/*
 * CurrentConditionsDisplay.h
 *
 *  Created on: 2019-2-24
 *      Author: root
 */

#ifndef CURRENTCONDITIONSDISPLAY_H_
#define CURRENTCONDITIONSDISPLAY_H_

#include "Observer.h"
#include "DisplayElement.h"
#include "WeatherData.h"

class CurrentConditionsDisplay: public Observer, public DisplayElement {
public:
	CurrentConditionsDisplay(Subject* weatherData);
	virtual void update(float temp, float humidity, float pressure)
	{
		//std::cout <<__func__ << std::endl;
		this->temperature = temp;
		this->humidity = humidity;
		this->pressure = pressure;
		display();
	}

	void display()
	{
		std::cout << "Current conditions:" << temperature << "F ," << humidity << "%, " << pressure << std::endl;
	}
	virtual ~CurrentConditionsDisplay();
private:
	float temperature;
	float humidity;
	float pressure;
	Subject* weatherData;
};

#endif /* CURRENTCONDITIONSDISPLAY_H_ */

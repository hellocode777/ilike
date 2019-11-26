/*
 * WeatherData.h
 *
 *  Created on: 2019-2-24
 *      Author: root
 */

#ifndef WEATHERDATA_H_
#define WEATHERDATA_H_

#include "Subject.h"
#include "Observer.h"
#include <list>

class WeatherData: public Subject {
public:
	typedef std::list<Observer*> ArrayList;
	WeatherData();
	virtual void registerObserver(Observer* o)
	{
		observers->push_back(o);
		//std::cout <<__func__ << std::endl;
	}
	virtual void removeObserver(Observer* o)
	{
		if (o == nullptr)
		{
			observers->remove(o);
			delete o;
			o = nullptr;
		}
	}

	virtual void notifyObserver()
	{
		for (ArrayList::iterator it=observers->begin(); it!=observers->end(); ++it)
		{
			(*it)->update(temperature, humidity, pressure);
			//std::cout <<__func__ << std::endl;
		}
	}

	void measurementsChanged()
	{
		notifyObserver();
	}

	void setMeasurements(float temp, float humidity, float pressure)
	{
		this->temperature = temp;
		this->humidity = humidity;
		this->pressure = pressure;
		measurementsChanged();
	}
	virtual ~WeatherData();
private:
	ArrayList* observers;
	float temperature;
	float humidity;
	float pressure;

};

#endif /* WEATHERDATA_H_ */

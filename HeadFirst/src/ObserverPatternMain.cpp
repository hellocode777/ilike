//============================================================================
// Name        : HeadFirst.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "ObserverPattern/WeatherData.h"
#include "ObserverPattern/CurrentConditionsDisplay.h"

int main()
{

	// ObserverPattern
	WeatherData* weatherData = new WeatherData();
	CurrentConditionsDisplay* currentConditionsDisplay = new CurrentConditionsDisplay(weatherData);
	weatherData->setMeasurements(80, 67, 44);
	weatherData->setMeasurements(81, 68, 45);
	weatherData->setMeasurements(82, 69, 46);

	delete weatherData;
	weatherData = nullptr;
	delete currentConditionsDisplay;
	currentConditionsDisplay = nullptr;


	return 0;
}

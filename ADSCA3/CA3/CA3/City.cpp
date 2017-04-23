#include "City.h"

City::City()
{
}

City::City(string name, int popuation, pair<double, double> coordinates, double averageTemperature)
{
	City::name = name;
	City::population = population;
	City::coordinates = coordinates;
	City::averageTemperature = averageTemperature;
}

bool City::operator<(City & cityInput)
{
	return name.compare(cityInput.name) <0;
}

bool City::operator>(City & cityInput)
{
	return name.compare(cityInput.name) >0;
}

pair<double, double> City::getCoordinates()
{
	return coordinates;
}



ostream& operator<<(ostream& stream, City& cityInput)
{
	stream << cityInput.name;

	return stream;
}



/*
 * BCFlight
 * Copyright (C) 2016 Adrien Aubry (drich)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#ifndef VOLTMETER_H
#define VOLTMETER_H

#include <list>
#include <functional>
#include <string>
#include <Main.h>
#include "Sensor.h"

class Voltmeter : public Sensor
{
public:
	Voltmeter();
	~Voltmeter();

	virtual float Read( int channel = 0 ) = 0;

protected:
};

#endif // VOLTMETER_H

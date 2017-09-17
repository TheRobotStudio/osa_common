/*
 * Copyright (c) 2017, The Robot Studio
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *	* Redistributions of source code must retain the above copyright notice, this
 *	  list of conditions and the following disclaimer.
 *
 *	* Redistributions in binary form must reproduce the above copyright notice,
 *	  this list of conditions and the following disclaimer in the documentation
 *	  and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file sensor.cpp
 * @author Cyril Jourdan
 * @date Dec 12, 2016
 * @version 0.1.0
 * @brief Implementation file for class Sensor
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 12, 2016
 */

#include <QJsonArray>
#include <iostream>
#include "sensor.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Sensor::Sensor() :
	Hardware(),
	value_list_(),
	ptr_communication_layer_(NULL),
	ptr_computer_(NULL),
	ptr_battery_(NULL)
{
}

Sensor::~Sensor()
{
	//clear pointers
	delete ptr_communication_layer_;
	delete ptr_computer_;
	delete ptr_battery_;

	//clear vector
	value_list_.clear();
}

int Sensor::addValue(double value)
{
		value_list_.append(value);

		return 0;
}

int Sensor::setValue(unsigned int index, double value)
{
	//check the value
	if(index < value_list_.size())
	{
		value_list_[index] = value;

		return 0;
	}
	else
		return -1;
}

int Sensor::setComputer(Computer* ptr_computer)
{
	//check the value
	if(ptr_computer != 0)
	{
		ptr_computer_ = ptr_computer;

		return 0;
	}
	else
		return -1;
}

int Sensor::setCommunicationLayer(CommunicationLayer* ptr_communication_layer)
{
	//check the value
	if(ptr_communication_layer != 0)
	{
		ptr_communication_layer_ = ptr_communication_layer;

		return 0;
	}
	else
		return -1;
}

int Sensor::setBattery(Battery* ptr_battery)
{
	//check the value
	if(ptr_battery != 0)
	{
		ptr_battery_ = ptr_battery;

		return 0;
	}
	else
		return -1;
}

void Sensor::display()
{
	cout << "Sensor" << endl;
	Hardware::display();
	cout << "List of values: ";
	for(unsigned int i=0; i<value_list_.size(); i++)
	{
		cout << "[" << value_list_[i] << "]";
	}
}

void Sensor::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//write attributes
	//cellVoltage QList
	value_list_.clear();
	QJsonArray valueArray = json["value"].toArray();

	for(int i = 0; i<valueArray.size(); ++i)
	{
		float value = (float)valueArray[i].toDouble();
		value_list_.append(value);
	}

	//ptr_computer_->read(json); //TODO find a way to avoid infinite serialization loop
	//ptr_communication_layer_->read(json);
	//ptr_battery_->read(json);
}

void Sensor::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//write attributes
	//cellVoltage QList
	QJsonArray valueArray;
	foreach(float val, value_list_)
	{
		valueArray.append(val);
	}
	json["value"] = valueArray;

    //ptr_computer_->write(json); //TODO find a way to avoid infinite serialization loop
	//ptr_communication_layer_->write(json);
	//ptr_battery_->write(json);
}

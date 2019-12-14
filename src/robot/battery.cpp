/*
 * Copyright (c) 2019, The Robot Studio
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.

 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
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
 * @file battery.cpp
 * @author Cyril Jourdan
 * @date Dec 13, 2016
 * @version 0.1.0
 * @brief Implementation file for class Battery
 *
 * Contact: contact@therobotstudio.com
 * Created on : Dec 13, 2016
 */

#include <QJsonArray>
#include <iostream>
#include "battery.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Battery::Battery() :
	Hardware(),
	type_(QString("")),
	number_of_cells_(0),
	capacity_(0),
	nominal_voltage_(0),
	ptr_battery_monitor_(NULL), //nullptr
	hardware_list_(QList<Hardware*>())
{
}
/*
Battery::Battery(QString type, unsigned short int number_of_cells, unsigned int capacity, unsigned int nominal_voltage) :
		type_(type), number_of_cells_(number_of_cells), capacity_(capacity), nominal_voltage_(nominal_voltage), ptr_battery_monitor_(0)
{
}*/

Battery::~Battery()
{
	//clear pointers
	delete ptr_battery_monitor_;

	/*
	for(unsigned int i=0; i<hardware_list_.size(); i++)
	{
		delete hardware_list_[i];
	}*/

	//clear QList
	hardware_list_.clear();
}

int Battery::setType(QString type)
{
	//check the value
	if(!type.isEmpty())
	{
		type_ = type;

		return 0;
	}
	else
		return -1;
}

int Battery::setNumberOfCells(unsigned short int number_of_cells)
{
	//check the value
	if(number_of_cells > 0)
	{
		number_of_cells_ = number_of_cells;

		return 0;
	}
	else
		return -1;
}

int Battery::setCapacity(unsigned int capacity)
{
	//check the value
	if(capacity > 0)
	{
		capacity_ = capacity;

		return 0;
	}
	else
		return -1;
}

int Battery::setNominalVoltage(unsigned int nominal_voltage)
{
	//check the value
	if(nominal_voltage > 0)
	{
		nominal_voltage_ = nominal_voltage;

		return 0;
	}
	else
		return -1;
}

int Battery::setBatteryMonitor(BatteryMonitor* ptr_battery_monitor)
{
	//check the value
	if(ptr_battery_monitor != 0)
	{
		ptr_battery_monitor_ = ptr_battery_monitor;

		return 0;
	}
	else
		return -1;
}

void Battery::addPtrHardware(Hardware* ptr_hardware)
{
	hardware_list_.append(ptr_hardware);
}

void Battery::display()
{
	cout << endl << "Battery:" << endl;
	Hardware::display(); //call mother class method, Hardware
	cout << "Type: " << type_.toStdString() << endl;
	cout << "N umber of cells: " << number_of_cells_ << endl;
	cout << "Capacity: " << capacity_ << " mAh" << endl;
	cout << "Nominal voltage: " << nominal_voltage_ << " V" << endl;
}

void Battery::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//write attributes
	type_ = json["type"].toString();
	number_of_cells_ = json["number_of_cells"].toDouble();
	capacity_ = (unsigned int)json["capacity"].toDouble();
	nominal_voltage_ = (unsigned int)json["nominal_voltage"].toDouble();

	ptr_battery_monitor_->read(json);
/*
	hardware_list_.clear();
	QJsonArray hardwareArray = json["pHardware"].toArray();

	for(int i = 0; i<hardwareArray.size(); ++i)
	{
		QJsonObject pHardwareObject = hardwareArray[i].toObject();
		Hardware* pHardware;
		pHardware->read(pHardwareObject);
		hardware_list_.append(pHardware);
	}*/
}

void Battery::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//write attributes
    json["type"] = type_;
    json["number_of_cells"] = number_of_cells_;
    json["capacity"] = (double)capacity_;
    json["nominal_voltage"] = (double)nominal_voltage_;

	ptr_battery_monitor_->write(json);

	/*
	QJsonArray hardwareArray;
	foreach(const Hardware* pHardware, hardware_list_)
	{
		QJsonObject pHardwareObject;
		pHardware->write(pHardwareObject);
		hardwareArray.append(pHardwareObject);
	}

	json["pHardware"] = hardwareArray;
	*/
}

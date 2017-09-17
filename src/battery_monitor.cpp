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
 * @file battery_monitor.cpp
 * @author Cyril Jourdan
 * @date Dec 13, 2016
 * @version 0.1.0
 * @brief Implementation file for class BatteryMonitor
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 13, 2016
 */

#include <QJsonArray>
#include <iostream>
#include "battery_monitor.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

BatteryMonitor::BatteryMonitor() :
	Hardware(),
	cell_voltage_list_(QList<float>()),
	total_voltage_(0),
	intensity_(0),
	temperature_(0),
	ptr_communication_layer_(NULL)
{

}

BatteryMonitor::~BatteryMonitor()
{
	//clear pointers
	delete ptr_communication_layer_;

	//clear Qlist
	cell_voltage_list_.clear();
}

int BatteryMonitor::addCellVoltage(float cellVoltage)
{
	//check the value
	if(cellVoltage > 0)
	{
		cell_voltage_list_.append(cellVoltage);

		return 0;
	}
	else
		return -1;
}

int BatteryMonitor::setCellVoltage(unsigned int cellNumber, float voltage)
{
	//check the value
	if((cellNumber < cell_voltage_list_.size()) && (voltage > 0))
	{
		cell_voltage_list_[cellNumber] = voltage;

		return 0;
	}
	else
		return -1;
}

int	BatteryMonitor::setTotalVoltage(float totalVoltage)
{
	//check the value
	if(totalVoltage > 0)
	{
		total_voltage_ = totalVoltage;

		return 0;
	}
	else
		return -1;
}

int	BatteryMonitor::setIntensity(float	intensity)
{
	//check the value
	if(intensity > 0)
	{
		intensity_ = intensity;

		return 0;
	}
	else
		return -1;
}

int	BatteryMonitor::setTemperature(float temperature)
{
	//check the value
	if(temperature > -273.15)
	{
		temperature_ = temperature;

		return 0;
	}
	else
		return -1;
}

int BatteryMonitor::setCommunicationLayer(CommunicationLayer* pCommunicationLayer)
{
	//check the value
	if(pCommunicationLayer != 0)
	{
		ptr_communication_layer_ = pCommunicationLayer;

		return 0;
	}
	else
		return -1;
}

float BatteryMonitor::getCellVoltage(unsigned short int cellNumber) const
{
	if((cellNumber >= 0) && (cellNumber <= cell_voltage_list_.size()))
	{
		return cell_voltage_list_[cellNumber];
	}
	else
	{
		return -1;
	}
}

void BatteryMonitor::display()
{
	cout << endl << "BatteryMonitor:" << endl;
	Hardware::display(); //call mother class method, Hardware
	cout << "List of cell voltages: ";
	for(unsigned int i=0; i<cell_voltage_list_.size(); i++)
	{
		cout << "[" << cell_voltage_list_[i] << "]";
	}
	cout << endl;
	cout << "TotalVoltage: " << total_voltage_ << " V" << endl;
	cout << "Intensity: " << intensity_ << " A" << endl;
	cout << "Temperature: " << temperature_ << "°C" << endl;
}

void BatteryMonitor::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//write attributes
	//cellVoltage QList
	cell_voltage_list_.clear();
	QJsonArray cellVoltageArray = json["cellVoltage"].toArray();

	for(int i = 0; i<cellVoltageArray.size(); ++i)
	{
		float cellVoltage = (float)cellVoltageArray[i].toDouble();
		cell_voltage_list_.append(cellVoltage);
	}

	total_voltage_ = (float)json["totalVoltage"].toDouble();
	intensity_ = (float)json["intensity"].toDouble();
	temperature_ = (float)json["temperature"].toDouble();

	//ptr_communication_layer_->read(json); //TODO find a way to avoid infinite serialization loop
}

void BatteryMonitor::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//write attributes
	//cellVoltage QList
	QJsonArray cellVoltageArray;
	foreach(float val, cell_voltage_list_)
	{
		cellVoltageArray.append(val);
	}
	json["cellVoltage"] = cellVoltageArray;

    json["totalVoltage"] = (double)total_voltage_;
    json["intensity"] = (double)intensity_;
    json["temperature"] = (double)temperature_;

    //ptr_communication_layer_->write(json); //TODO find a way to avoid infinite serialization loop
}

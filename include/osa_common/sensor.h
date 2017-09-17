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
 * @file sensor.h
 * @author Cyril Jourdan
 * @date Dec 12, 2016
 * @version 0.0.1
 * @brief Header file for class Sensor
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 12, 2016
 */

#ifndef OSA_GUI_COMMON_SENSOR_H
#define OSA_GUI_COMMON_SENSOR_H


#include <QList>
#include <QJsonObject>
#include "hardware.h"
#include "battery.h"
#include "computer.h"
#include "communication_layer.h"

namespace osa_common
{

/**
 * @brief This class represents a sensor.
 */
class Sensor : public Hardware
{
public:
	/**
	 * @brief Constructor.
	 */
	Sensor();
	//copy constructor
	//Sensor(Sensor const& sensor);
	//operator overloading
	//Sensor& operator=(Sensor const& sensor);

	/**
	 * @brief Destructor.
	 */
	virtual ~Sensor();

	//setters
	int addValue(double value);
	int setValue(unsigned int index, double value);
	int setComputer(Computer* ptr_computer);
	int setCommunicationLayer(CommunicationLayer* ptr_communication_layer);
	int setBattery(Battery* ptr_battery);

	//getters
	QList<double> getValue() const { return value_list_; };
	Computer* getComputer() const { return ptr_computer_; };
	CommunicationLayer* getCommunicationLayer() const { return ptr_communication_layer_; };
	Battery* getBattery() const { return ptr_battery_; };

	//other methods
	virtual void display();

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const;

protected:
	QList<double> value_list_;
	Computer* ptr_computer_;
	CommunicationLayer* ptr_communication_layer_;
	Battery* ptr_battery_;
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_SENSOR_H

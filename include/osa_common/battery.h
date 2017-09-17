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
 * @file battery.h
 * @author Cyril Jourdan
 * @date Dec 13, 2016
 * @version 0.0.1
 * @brief Header file for class Battery
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 13, 2016
 */

#ifndef OSA_GUI_COMMON_BATTERY_H
#define OSA_GUI_COMMON_BATTERY_H


#include <QString>
#include <QList>
#include <QJsonObject>
#include <vector>
#include "hardware.h"
#include "battery_monitor.h"

namespace osa_common
{

/**
 * @brief Class representing a battery.
 */
class Battery : public Hardware
{
public:
	/**
	 * @brief Constructor.
	 */
	Battery();
	/**
	 * @brief Constructor.
	 */
	Battery(QString type, unsigned short int number_of_cells, unsigned int capacity, unsigned int nominal_voltage);

	/**
	 * @brief Destructor.
	 */
	virtual ~Battery();

	//setters
	int setType(QString type);
	int setNumberOfCells(unsigned short int number_of_cells);
	int setCapacity(unsigned int capacity);
	int setNominalVoltage(unsigned int nominal_voltage);
	int setBatteryMonitor(BatteryMonitor* ptr_battery_monitor);
	void addPtrHardware(Hardware* ptr_hardware);

	//getters
	QString getType() const { return type_; };
	unsigned short int getNumberOfCells() const { return number_of_cells_; };
	unsigned int getCapacity() const { return capacity_; };
	unsigned int getNominalVoltage() const { return nominal_voltage_; };
	BatteryMonitor* getBatteryMonitor() const { return ptr_battery_monitor_; };
	QList<Hardware*> getHardwareList() const { return hardware_list_; };

	//other methods
	virtual void display();

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const;

protected:
	QString type_;
	unsigned short int number_of_cells_;
	unsigned int capacity_;
	unsigned int nominal_voltage_;
	BatteryMonitor* ptr_battery_monitor_;
	QList<Hardware*> hardware_list_; /**< List of hardware powered by this battery. */
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_BATTERY_H

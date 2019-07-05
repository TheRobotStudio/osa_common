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
 * @file battery_monitor.h
 * @author Cyril Jourdan
 * @date Dec 13, 2016
 * @version 0.0.1
 * @brief Header file for class BatteryMonitor
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 13, 2016
 */

#ifndef OSA_GUI_COMMON_BATTERY_MONITOR_H
#define OSA_GUI_COMMON_BATTERY_MONITOR_H

#include <vector>
//#include <boost/shared_ptr.hpp>
#include "hardware.h"
#include "communication_layer.h"

namespace osa_common
{

/**
 * @brief Class representing a battery monitor.
 */
template <typename L, typename J> class BatteryMonitor : public Hardware
{
public:
	/**
	 * @brief Constructor.
	 */
	BatteryMonitor();

	/**
	 * @brief Destructor.
	 */
	virtual ~BatteryMonitor();

	//setters
	int addCellVoltage(float cellVoltage);
	int setCellVoltage(unsigned int cell_number, float voltage);
	int	setTotalVoltage(float total_voltage);
	int	setIntensity(float	intensity);
	int	setTemperature(float temperature);
	int setCommunicationLayer(CommunicationLayer* ptr_communication_layer);

	//getters
	L<float> getCellVoltageList() const { return cell_voltage_list_; };
	float getTotalVoltage() const { return total_voltage_; };
	float getIntensity() const { return intensity_; };
	float getTemperature() const { return temperature_; };
	CommunicationLayer* getCommunicationLayer() const { return ptr_communication_layer_; };
	float getCellVoltage(unsigned short int cellNumber) const;

	//other
	virtual void display();

	/** @brief Read method for JSON serialization. */
	virtual void read(const J &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(J &json) const;

private:
	L<float> cell_voltage_list_; /**< Voltage list of each cell in the battery pack. */
	float total_voltage_;
	float intensity_;
	float temperature_;
	CommunicationLayer* ptr_communication_layer_;
	//boost::shared_ptr<CommunicationLayer> ptr_communication_layer_;
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_BATTERY_MONITOR_H

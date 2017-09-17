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
 * @file computer.h
 * @author Cyril Jourdan
 * @date Dec 14, 2016
 * @version 0.0.1
 * @brief Header file for class Computer
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 14, 2016
 */

#ifndef OSA_GUI_COMMON_COMPUTER_H
#define OSA_GUI_COMMON_COMPUTER_H

#include <QList>
#include <QJsonObject>
#include <vector>
#include "hardware.h"
#include "battery.h"
#include "communication_layer.h"
#include "usb_device.h"

namespace osa_common
{

/**
 * @brief Class representing a computer.
 */
class Computer : public Hardware
{
public:
	/**
	 * @brief Constructor.
	 */
	Computer();
	//copy constructor
	//Computer(Computer const& computer);
	//operator overloading
	//Computer& operator=(Computer const& computer);

	/**
	 * @brief Destructor.
	 */
	virtual ~Computer();

	//setters
	int setBattery(Battery* ptr_battery);
	int addCommunicationLayer(CommunicationLayer* ptr_communication_layer);
	int addUSBDevice(USBDevice* ptr_usb_device);

	//getters
	Battery* getBattery() const { return ptr_battery_; };
	QList<CommunicationLayer*> getCommunicationLayerList() const { return communication_layer_list_; };
	QList<USBDevice*> getUSBDeviceList() const { return usb_device_list_; };

	//other methods
	virtual void display();

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const;

protected:
	Battery* ptr_battery_;
	QList<CommunicationLayer*> communication_layer_list_;
	QList<USBDevice*> usb_device_list_;
	//Robot* m_pRobot;
	//HDMI display
	//wifi/ethernet
	//sound speaker
	//microphone
	//serial debugger
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_COMPUTER_H

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
 * @file computer.cpp
 * @author Cyril Jourdan
 * @date Jan 26, 2017
 * @version 0.1.0
 * @brief Implementation file for class Computer
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 14, 2016
 */

#include <QJsonArray>
#include <iostream>
#include "computer.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Computer::Computer() :
	Hardware(),
	ptr_battery_(),
	communication_layer_list_(QList<CommunicationLayer*>()),
	usb_device_list_(QList<USBDevice*>())
{
}

Computer::~Computer()
{
	//clear pointers
	delete ptr_battery_;

	for(unsigned int i=0; i<communication_layer_list_.size(); i++)
	{
		delete communication_layer_list_[i];
	}

	for(unsigned int i=0; i<usb_device_list_.size(); i++)
	{
		delete usb_device_list_[i];
	}

	//clear vectors
	communication_layer_list_.clear();
	usb_device_list_.clear();
}

int Computer::setBattery(Battery* ptr_battery)
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

int Computer::addCommunicationLayer(CommunicationLayer* ptr_communication_layer)
{
	//check the value
	if(ptr_communication_layer != 0)
	{
		communication_layer_list_.append(ptr_communication_layer);

		return 0;
	}
	else
		return -1;
}

int Computer::addUSBDevice(USBDevice* ptr_usb_device)
{
	//check the value
	if(ptr_usb_device != 0)
	{
		usb_device_list_.append(ptr_usb_device);

		return 0;
	}
	else
		return -1;
}

void Computer::display()
{
	cout << endl << "Computer: " << endl;
	Hardware::display();
	for(unsigned int i=0; i<communication_layer_list_.size(); i++)
	{
		cout << "- Communication layer [" << i << "]:" << endl;
		communication_layer_list_[i]->display();
	}
	for(unsigned int i=0; i<usb_device_list_.size(); i++)
	{
		cout << "- USB device [" << i << "]:" << endl;
		usb_device_list_[i]->display();
	}
}

void Computer::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//write attributes
	//ptr_battery_->read(json); //TODO find a way to avoid infinite serialization loop

	//CommunicationLayer pointer QList
	communication_layer_list_.clear();
	QJsonArray communication_layer_array = json["ptr_communication_layer"].toArray();

	for(int i = 0; i<communication_layer_array.size(); ++i)
	{
		QJsonObject ptr_communication_layer_object = communication_layer_array[i].toObject();
		CommunicationLayer* ptr_communication_layer;
		ptr_communication_layer->read(ptr_communication_layer_object);
		communication_layer_list_.append(ptr_communication_layer);
	}

	//USBDevice pointer QList
	usb_device_list_.clear();
	QJsonArray usb_device_array = json["ptr_usb_device"].toArray();

	for(int i = 0; i<usb_device_array.size(); ++i)
	{
		QJsonObject ptr_usb_device_object = usb_device_array[i].toObject();
		USBDevice* ptr_usb_device;
		ptr_usb_device->read(ptr_usb_device_object);
		usb_device_list_.append(ptr_usb_device);
	}
}

void Computer::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//write attributes
	//ptr_battery_->write(json); //TODO find a way to avoid infinite serialization loop

	//CommunicationLayer pointer QList
	QJsonArray communication_layer_array;
	foreach(const CommunicationLayer* ptr_communication_layer, communication_layer_list_)
	{
		QJsonObject ptr_communication_layer_object;
		ptr_communication_layer->write(ptr_communication_layer_object);
		communication_layer_array.append(ptr_communication_layer_object);
	}
	json["ptr_communication_layer"] = communication_layer_array;

	//USBDevice pointer QList
	QJsonArray usb_device_array;
	foreach(const USBDevice* ptr_usb_device, usb_device_list_)
	{
		QJsonObject ptr_usb_device_object;
		ptr_usb_device->write(ptr_usb_device_object);
		usb_device_array.append(ptr_usb_device_object);
	}
	json["ptr_usb_device"] = usb_device_array;
}

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
 * @file usb_device.cpp
 * @author Cyril Jourdan
 * @date Dec 13, 2016
 * @version 0.0.1
 * @brief Implementation file for class USBDevice
 *
 * Contact: contact@therobotstudio.com
 * Created on : Dec 13, 2016
 */

#include <iostream>
#include "usb_device.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

USBDevice::USBDevice() :
	Hardware(),
	vendor_id_(QString("")),
	product_id_(QString("")),
	file_path_(QString(""))
{
}

USBDevice::~USBDevice()
{
}

int USBDevice::setVendorID(QString vendor_id)
{
	//check the value
	if(!vendor_id.isEmpty())
	{
		vendor_id_ = vendor_id;

		return 0;
	}
	else
		return -1;
}

int USBDevice::setProductID(QString product_id)
{
	//check the value
	if(!product_id.isEmpty())
	{
		product_id_ = product_id;

		return 0;
	}
	else
		return -1;
}

int USBDevice::setFilePatch(QString file_path)
{
	//check the value
	if(!file_path.isEmpty())
	{
		file_path_ = file_path;

		return 0;
	}
	else
		return -1;
}

void USBDevice::display()
{
	cout << endl << "USBDevice: " << endl;
	cout << "Vendor ID: " << vendor_id_.toStdString() << endl;
	cout << "Product ID: " << product_id_.toStdString() << endl;
	cout << "File path: " << file_path_.toStdString() << endl;
}

void USBDevice::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//read attributes
	vendor_id_ = json["vendor_id"].toString();
	product_id_ = json["product_id"].toString();
	file_path_ = json["file_path"].toString();
}

void USBDevice::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//write attributes
    json["vendor_id"] = vendor_id_;
    json["product_id"] = product_id_;
    json["file_path"] = file_path_;
}


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
 * @file camera.cpp
 * @author Cyril Jourdan
 * @date Dec 13, 2016
 * @version 0.1.0
 * @brief Implementation file for class Camera
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 13, 2016
 */

#include <iostream>
#include "camera.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Camera::Camera() :
	Sensor(),
	USBDevice(),
	type_(QString(""))
{
}

Camera::~Camera()
{
}

int Camera::setType(QString type)
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

void Camera::display()
{
	cout << endl << "Camera:" << endl;
	Sensor::display(); //call mother class method
	USBDevice::display(); //call mother class method
	cout << "Type: " << type_.toStdString() << endl;
}

void Camera::read(const QJsonObject &json)
{
	//call mother class method
	Sensor::read(json);
	USBDevice::read(json);

	//write attributes
	type_ = json["type"].toString();
}

void Camera::write(QJsonObject &json) const
{
	//call mother class method
	Sensor::write(json);
	USBDevice::write(json);

	//write attributes
    json["type"] = type_;
}

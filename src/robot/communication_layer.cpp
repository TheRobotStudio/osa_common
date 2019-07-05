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
 * @file communication_layer.cpp
 * @author Cyril Jourdan
 * @date Dec 9, 2016
 * @version 0.1.0
 * @brief Implementation file for class CommunicationLayer
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 9, 2016
 */

#include <iostream>
#include "communication_layer.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

CommunicationLayer::CommunicationLayer() :
	name_(QString("")),
	state_(false)
{
}

/*
CommunicationLayer::CommunicationLayer(QString name) : name_(name), state_(false)
{
}*/
/*
CommunicationLayer::CommunicationLayer(CommunicationLayer const& communicationLayer) : name_(communicationLayer.name_), state_(communicationLayer.state_)
{
}
*/

CommunicationLayer::~CommunicationLayer()
{
}

int CommunicationLayer::setName(QString name)
{
	//check the value
	if(!name.isEmpty())
	{
		name_ = name;

		return 0;
	}
	else
		return -1;
}

int CommunicationLayer::setState(bool state)
{
	//check the value
	if((state == true) || (state == false))
	{
		state_ = state;

		return 0;
	}
	else
		return -1;
}

int CommunicationLayer::openCommunication()
{
	if(state_ == false)
	{
		setState(true);
		return 0;
	}
	else
		return -1;
}

int CommunicationLayer::closeCommunication()
{
	if(state_ == true)
	{
		setState(false);
		return 0;
	}
	else
		return -1;
}

void CommunicationLayer::display()
{
	cout << endl << "CommunicationLayer: " << endl;
	cout << "Name: " << name_.toStdString() << endl;
	cout << "State: " << state_ << endl;
}

void CommunicationLayer::read(const QJsonObject &json)
{
	name_ = json["name"].toString();
	state_ = json["state"].toBool();
}

void CommunicationLayer::write(QJsonObject &json) const
{
	json["name"] = name_;
	json["state"] = state_;
}

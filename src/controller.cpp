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
 * @file controller.cpp
 * @author Cyril Jourdan
 * @date Dec 9, 2016
 * @version 0.1.0
 * @brief Implementation file for class Controller
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 9, 2016
 */

#include <iostream>
#include "controller.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Controller::Controller() :
	Hardware(),
	status_(0),
	node_id_(0),
	position_(0),
	current_(0),
	velocity_(0),
	ptr_actuator_()
	//m_pCommunicationLayer(nullptr),
	//m_pBattery(nullptr)
{
}

Controller::~Controller()
{
	delete ptr_actuator_;
	//delete m_pCommunicationLayer;
	//delete m_pBattery;
}

int	Controller::setStatus(int status)
{
	//check the value
	if(status > 0)
	{
		status_ = status;

		return 0;
	}
	else
		return -1;
}

int	Controller::setNodeID(unsigned int node_id)
{
	//check the value
	if(node_id > 0)
	{
		node_id_ = node_id;

		return 0;
	}
	else
		return -1;
}

int Controller::setPosition(int position)
{
	//check the value
	if(position > 0)
	{
		position_ = position;

		return 0;
	}
	else
		return -1;
}

int Controller::setCurrent(int current)
{
	//check the value
	if(current > 0)
	{
		current_ = current;

		return 0;
	}
	else
		return -1;
}

int Controller::setVelocity(int velocity)
{
	//check the value
	if(velocity > 0)
	{
		velocity_ = velocity;

		return 0;
	}
	else
		return -1;
}

int Controller::setPActuator(Actuator* ptr_actuator)
{
	//check the value
	if(ptr_actuator != 0)
	{
		ptr_actuator_ = ptr_actuator;

		return 0;
	}
	else
		return -1;
}
/*
int Controller::setPCommunicationLayer(CommunicationLayer* pCommunicationLayer)
{
	//check the value
	if(pCommunicationLayer != 0)
	{
		m_pCommunicationLayer = pCommunicationLayer;

		return 0;
	}
	else
		return -1;
}

int Controller::setPBattery(Battery* pBattery)
{
	//check the value
	if(pBattery != 0)
	{
		m_pBattery = pBattery;

		return 0;
	}
	else
		return -1;
}
*/

void Controller::display()
{
	cout << "Controller:" << endl;
	Hardware::display(); //call the display method from mother class
	cout << "Status: " << status_ << endl;
	cout << "NodeID: " << node_id_ << endl;
	cout << "Position: " << position_ << endl;
	cout << "Current: " << current_ << endl;
	cout << "Velocity: " << velocity_ << endl;
}

void Controller::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//read attributes
	status_ = (int)json["status"].toDouble();
	node_id_ = (unsigned int)json["node_id"].toDouble();
	position_ = (int)json["position"].toDouble();
	current_ = (int)json["current"].toDouble();
	velocity_ = (int)json["velocity"].toDouble();
	ptr_actuator_->read(json); //TODO find a way to avoid infinite serialization loop
	//m_pCommunicationLayer->read(json);
	//m_pBattery->read(json);
}

void Controller::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//write attributes
	json["status"] = (double)status_;
	json["node_id"] = (double)node_id_;
	json["position"] = (double)position_;
	json["current"] = (double)current_;
	json["velocity"] = (double)velocity_;
	ptr_actuator_->write(json); //TODO find a way to avoid infinite serialization loop
	//m_pCommunicationLayer->write(json);
	//m_pBattery->write(json);
}

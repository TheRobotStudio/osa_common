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
 * @file robot.cpp
 * @author Cyril Jourdan
 * @date Dec 8, 2016
 * @version 0.1.0
 * @brief Implementation file for class Robot
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 8, 2016
 */

#include <QJsonArray>
#include <iostream>
#include "robot.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Robot::Robot() :
	Hardware(),
	dof_(0)
/*
		m_vpActuator(QList<Actuator*>()),
		m_vpSensor(QList<Sensor*>()),
		m_vpComputer(QList<Computer*>()),
		m_vpCommunicationLayer(QList<CommunicationLayer*>()),
		m_vpBattery(QList<Battery*>())
*/
{
	//m_pCommunicationLayer = new CommunicationLayer();
}
/*
Robot::Robot(string name, int dof) : Hardware(name), dof_(dof), m_vpActuator(), m_vpSensor(), m_vpComputer(), m_vpCommunicationLayer(), m_vpBattery()
{
	//m_pCommunicationLayer = new CommunicationLayer();
}*/

/*
Robot::Robot(Robot const& robot) : Hardware(robot), dof_(robot.dof_), m_vpActuator(), m_vpSensor(), m_vpComputer(), m_vpCommunicationLayer(), m_vpBattery()
{
	//m_pCommunicationLayer = new CommunicationLayer(*(robot.m_pCommunicationLayer));

}*/

Robot::~Robot()
{
	//delete m_pMasterBoard;

/*	//clear pointers
	for(unsigned int i=0; i<m_vpActuator.size(); i++)
	{
		delete m_vpActuator[i];
	}

	for(unsigned int i=0; i<m_vpSensor.size(); i++)
	{
		delete m_vpSensor[i];
	}

	for(unsigned int i=0; i<m_vpCommunicationLayer.size(); i++)
	{
		delete m_vpCommunicationLayer[i];
	}*/

/*	//clear vectors
	m_vpActuator.clear();
	m_vpSensor.clear();
	m_vpCommunicationLayer.clear();
*/
}

int Robot::setDof(unsigned int dof)
{
	//check the value
	if(dof > 0)
	{
		dof_ = dof;

		return 0;
	}
	else
		return -1;
}
/*
int Robot::setPMasterBoard(MasterBoard* pMasterBoard)
{
	//check the value
	if(pMasterBoard != 0)
	{
		m_pMasterBoard = pMasterBoard;

		return 0;
	}
	else
		return -1;
}
*/
/*
int Robot::addPActuator(Actuator* pActuator)
{
	//check the value
	if(pActuator != 0)
	{
		m_vpActuator.append(pActuator);

		return 0;
	}
	else
		return -1;
}

int Robot::addPSensor(Sensor *pSensor)
{
	//check the value
	if(pSensor != 0)
	{
		m_vpSensor.append(pSensor);

		return 0;
	}
	else
		return -1;
}

int Robot::addPComputer(Computer *pComputer)
{
	//check the value
	if(pComputer != 0)
	{
		m_vpComputer.append(pComputer);

		return 0;
	}
	else
		return -1;
}

int Robot::addPCommunicationLayer(CommunicationLayer *pCommunicationLayer)
{
	//check the value
	if(pCommunicationLayer != 0)
	{
		m_vpCommunicationLayer.append(pCommunicationLayer);

		return 0;
	}
	else
		return -1;
}

int Robot::addPBattery(Battery *pBattery)
{
	//check the value
	if(pBattery != 0)
	{
		m_vpBattery.append(pBattery);

		return 0;
	}
	else
		return -1;
}
*/

void Robot::display()
{
	cout << "*** Robot data ***" << endl << endl;
	Hardware::display(); //call mother class method, Hardware
	cout << "DOF: " << dof_ << endl;

/*	cout << endl;
	cout << "List of actuators:" << endl;
	for(unsigned int i=0; i<m_vpActuator.size(); i++)
	{
		cout << endl;
		cout << "- Actuator [" << i << "]:" << endl;
		m_vpActuator[i]->display();
	}

	cout << endl;
	cout << "List of sensors:" << endl;
	for(unsigned int i=0; i<m_vpSensor.size(); i++)
	{
		cout << endl;
		cout << "- Sensor [" << i << "]:" << endl;
		m_vpSensor[i]->display();
	}

	cout << endl;
	cout << "List of computers:" << endl;
	for(unsigned int i=0; i<m_vpComputer.size(); i++)
	{
		cout << endl;
		cout << "- Computer [" << i << "]:" << endl;
		m_vpComputer[i]->display();
	}

	cout << endl;
	cout << "List of communication layers:" << endl;
	for(unsigned int i=0; i<m_vpCommunicationLayer.size(); i++)
	{
		cout << endl;
		cout << "- Communication layer [" << i << "]:" << endl;
		m_vpCommunicationLayer[i]->display();
	}

	cout << endl;
	cout << "List of batteries:" << endl;
	for(unsigned int i=0; i<m_vpBattery.size(); i++)
	{
		cout << endl;
		cout << "- Battery [" << i << "]:" << endl;
		m_vpBattery[i]->display();
	}
*/
}

void Robot::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//read other attributes
	dof_ = (unsigned int)json["dof"].toDouble();

	//m_pMasterBoard->read(json);
/*
	//Actuator pointer QList
	m_vpActuator.clear();
	QJsonArray actuatorArray = json["pActuator"].toArray();

	for(int i = 0; i<actuatorArray.size(); ++i)
	{
		QJsonObject pActuatorObject = actuatorArray[i].toObject();
		Actuator* pActuator;
		pActuator->read(pActuatorObject);
		m_vpActuator.append(pActuator);
	}

	//Sensor pointer QList
	m_vpSensor.clear();
	QJsonArray sensorArray = json["pSensor"].toArray();

	for(int i = 0; i<sensorArray.size(); ++i)
	{
		QJsonObject pSensorObject = sensorArray[i].toObject();
		Sensor* pSensor;
		pSensor->read(pSensorObject);
		m_vpSensor.append(pSensor);
	}

	//Computer pointer QList
	m_vpComputer.clear();
	QJsonArray computerArray = json["pComputer"].toArray();

	for(int i = 0; i<computerArray.size(); ++i)
	{
		QJsonObject pComputerObject = computerArray[i].toObject();
		Computer* pComputer;
		pComputer->read(pComputerObject);
		m_vpComputer.append(pComputer);
	}

	//CommunicationLayer pointer QList
	m_vpCommunicationLayer.clear();
	QJsonArray communicationLayerArray = json["pCommunicationLayer"].toArray();

	for(int i = 0; i<communicationLayerArray.size(); ++i)
	{
		QJsonObject pCommunicationLayerObject = communicationLayerArray[i].toObject();
		CommunicationLayer* pCommunicationLayer;
		pCommunicationLayer->read(pCommunicationLayerObject);
		m_vpCommunicationLayer.append(pCommunicationLayer);
	}

	//Battery pointer QList
	m_vpBattery.clear();
	QJsonArray batteryArray = json["pBattery"].toArray();

	for(int i = 0; i<batteryArray.size(); ++i)
	{
		QJsonObject pBatteryObject = batteryArray[i].toObject();
		Battery* pBattery;
		pBattery->read(pBatteryObject);
		m_vpBattery.append(pBattery);
	}
*/
}

void Robot::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//write attributes
    json["dof"] = (double)dof_;

    //m_pMasterBoard->write(json);
/*
    //Actuator pointer QList
	QJsonArray actuatorArray;
	foreach(const Actuator* pActuator, m_vpActuator)
	{
		QJsonObject pActuatorObject;
		pActuator->write(pActuatorObject);
		actuatorArray.append(pActuatorObject);
	}
	json["pActuator"] = actuatorArray;

	//Sensor pointer QList
	QJsonArray sensorArray;
	foreach(const Sensor* pSensor, m_vpSensor)
	{
		QJsonObject pSensorObject;
		pSensor->write(pSensorObject);
		sensorArray.append(pSensorObject);
	}
	json["pSensor"] = sensorArray;

	//Computer pointer QList
	QJsonArray computerArray;
	foreach(const Computer* pComputer, m_vpComputer)
	{
		QJsonObject pComputerObject;
		pComputer->write(pComputerObject);
		computerArray.append(pComputerObject);
	}
	json["pComputer"] = computerArray;

	//CommunicationLayer pointer QList
	QJsonArray communicationLayerArray;
	foreach(const CommunicationLayer* pCommunicationLayer, m_vpCommunicationLayer)
	{
		QJsonObject pCommunicationLayerObject;
		pCommunicationLayer->write(pCommunicationLayerObject);
		communicationLayerArray.append(pCommunicationLayerObject);
	}
	json["pCommunicationLayer"] = communicationLayerArray;

	//Battery pointer QList
	QJsonArray batteryArray;
	foreach(const Battery* pBattery, m_vpBattery)
	{
		QJsonObject pBatteryObject;
		pBattery->write(pBatteryObject);
		batteryArray.append(pBatteryObject);
	}
	json["pBattery"] = batteryArray;
*/
}

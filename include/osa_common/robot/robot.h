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
 * @file robot.h
 * @author Cyril Jourdan
 * @date Dec 8, 2016
 * @version 0.0.1
 * @brief Header file for class Robot
 *
 * Contact: contact@therobotstudio.com
 * Created on : Dec 8, 2016
 */

#ifndef OSA_GUI_COMMON_ROBOT_H
#define OSA_GUI_COMMON_ROBOT_H


#include <QList>
#include <QJsonObject>
#include <vector>
#include "actuator.h"
#include "battery.h"
#include "hardware.h"
#include "sensor.h"
#include "computer.h"
#include "communication_layer.h"

namespace osa_common
{

/**
 * @brief This class represents a robot.
 */
class Robot : public Hardware
{
public:
	/**
	 * @brief Constructor.
	 */
	Robot();
	//Robot(std::string name, int dof);
	//copy constructor
	//Robot(Robot const& robot);

	/**
	 * @brief Destructor.
	 */
	virtual ~Robot();

	//setters
	int setDof(unsigned int dof);
	/*
	int addPActuator(Actuator* pActuator);
	int addPSensor(Sensor* pSensor);
	int addPComputer(Computer* pComputer);
	int addPCommunicationLayer(CommunicationLayer* pCommunicationLayer);
	int addPBattery(Battery* pBattery);
*/

	//getters
	unsigned int getDof() const { return dof_; };
	/*
	QList<Actuator*> 			getVpActuator() 			const { return m_vpActuator; };
	QList<Sensor*>				getVpSensor() 				const { return m_vpSensor; };
	QList<Computer*>			getVpComputer() 			const { return m_vpComputer; };
	QList<CommunicationLayer*> 	getVpCommunicationLayer() 	const { return m_vpCommunicationLayer; };
	QList<Battery*> 			getVpBattery() 				const { return m_vpBattery; };
*/
	//other methods
	virtual void display();

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const;

protected:
	unsigned int dof_; //Degrees Of Freedom, equal to m_vMotor.size();
	//MasterBoard* 				m_pMasterBoard;

	/*
	QList<Actuator*> 			m_vpActuator;
	QList<Sensor*> 				m_vpSensor;
	QList<Computer*> 			m_vpComputer;
	QList<CommunicationLayer*> 	m_vpCommunicationLayer;
	QList<Battery*> 			m_vpBattery;
	*/
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_ROBOT_H

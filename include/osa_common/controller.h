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
 * @file controller.h
 * @author Cyril Jourdan
 * @date Dec 9, 2016
 * @version 0.0.1
 * @brief Header file for class Controller
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 9, 2016
 */

#ifndef OSA_GUI_COMMON_CONTROLLER_H
#define OSA_GUI_COMMON_CONTROLLER_H

#include <QJsonObject>
#include "hardware.h"
#include "communication_layer.h"
#include "actuator.h"
#include "battery.h"

namespace osa_common
{

/**
 * @brief Class representing an actuator controller.
 */
class Controller : public Hardware
{
public:
	/**
	 * @brief Constructor.
	 */
	Controller();
	//Controller();
	//copy constructor
	//Controller(Controller const& controller);

	/**
	 * @brief Destructor.
	 */
	virtual ~Controller();

	//setters
	int	setStatus(int status);
	int	setNodeID(unsigned int nodeID);
	int setPosition(int position);
	int setCurrent(int current);
	int setVelocity(int velocity);
	int setPActuator(Actuator* pActuator);
	//int setPCommunicationLayer(CommunicationLayer* pCommunicationLayer);
	//int setPBattery(Battery* pBattery);

	//getters
	int	 getStatus() const { return status_; };
	unsigned int getNodeId() const { return node_id_; };
	int getPosition() const { return position_; };
	int getCurrent() const { return current_; };
	int getVelocity() const { return velocity_; };
	Actuator* getActuator() const { return ptr_actuator_; };
	//CommunicationLayer* getPCommunicationLayer() const { return m_pCommunicationLayer; };
	//Battery* getPBattery() const { return m_pBattery; };

	//other methods
	virtual void display();

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const;

protected:
	int status_;
	unsigned int node_id_;
	int position_;
	int current_;
	int velocity_;
	Actuator* ptr_actuator_;
	//CommunicationLayer* ptr_communication_layer;
	//Battery* ptr_battery_;
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_CONTROLLER_H

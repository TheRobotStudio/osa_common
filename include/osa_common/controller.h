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
 * @file controller.h
 * @author Cyril Jourdan <contact@therobotstudio.com>
 * @date Modified on Apr 11, 2018
 * @date Created on Apr 11, 2018
 * @version 0.1.1
 * @brief Header file for class Controller
 */

#ifndef OSA_COMMON_CONTROLLER_H
#define OSA_COMMON_CONTROLLER_H

#include <ros/ros.h>
#include <string>
#include "enums.h"

namespace osa_common
{

/**
 * @brief Class representing an actuator controller.
 */
class Controller
{
public:
	/**
	 * @brief Constructor.
	 */
	Controller(std::string name, std::string degree_of_freedom_type,
				int node_id, std::string controller_type,
				std::string motor_type, bool inverted,
				std::string mode, int value);

	/**
	 * @brief Destructor.
	 */
	virtual ~Controller();

	//setters
//	int	setName(std::string name);
	int	setNodeID(uint8_t node_id);
/*	int setControllerType(ControllerType controller_type);
	int setMotorType(MotorType motor_type);
	int setInverted(bool inverted);
	int setMode(ActivatedModeOfOperation mode);
	int setValue(int value);
*/
	//getters
	std::string	getName() const { return name_; };
	uint8_t getNodeID() const { return node_id_; };
	ControllerType getControllerType() const { return controller_type_; };
	MotorType getMotorType() const { return motor_type_; };
	bool getInverted() const { return inverted_; };
	ActivatedModeOfOperation getMode() const { return mode_; };
	int getValue() const { return value_; };

protected:
	std::string name_;
	DegreeOfFreedomType degree_of_freedom_type_;
	uint8_t node_id_;
	ControllerType controller_type_;
	MotorType motor_type_;
	bool inverted_; /**< 0 for non inverted, 1 for inverted, this will invert the sign of commands. */
	ActivatedModeOfOperation mode_;
	int value_;

};

} // namespace osa_common

#endif // OSA_COMMON_CONTROLLER_H

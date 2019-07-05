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
 * @file controller.cpp
 * @author Cyril Jourdan <cyril.jourdan@therobotstudio.com>
 * @date Modified on Apr 11, 2018
 * @date Created on Apr 11, 2018
 * @version 0.1.1
 * @brief Implementation file for class Controller
 */

#include "controller.h"

using namespace std;
using namespace osa_common;

Controller::Controller(std::string name, std::string degree_of_freedom_type,
		int node_id, std::string controller_type,
		std::string motor_type, bool inverted,
		std::string mode, int value) :
name_(name),
degree_of_freedom_type_(TENDON),
node_id_(0),
controller_type_(NOT_USED),
motor_type_(NONE),
inverted_(inverted),
mode_(PROFILE_VELOCITY_MODE),
value_(value)
{
	//Init the parameters

		//degree_of_freedom_type_
		if(!degree_of_freedom_type.compare("TENDON")) degree_of_freedom_type_ = TENDON;
		else if(!degree_of_freedom_type.compare("WHEEL")) degree_of_freedom_type_ = WHEEL;
		else if(!degree_of_freedom_type.compare("CLASSICAL")) degree_of_freedom_type_ = CLASSICAL;
		else if(!degree_of_freedom_type.compare("SEA")) degree_of_freedom_type_ = SEA;

		//node_id_
		if((node_id >=0) && (node_id<=255)) node_id_ = node_id; //check that the value is a uint8_t

		//controller_type_
		if(!controller_type.compare("NOT_USED")) controller_type_ = ControllerType(NOT_USED);
		else if(!controller_type.compare("EPOS2")) controller_type_ = ControllerType(EPOS2);
		else if(!controller_type.compare("EPOS4")) controller_type_ = ControllerType(EPOS4);

		//motor_type_
		if(!motor_type.compare("NONE")) motor_type_ = MotorType(NONE);
		else if(!motor_type.compare("DCX10")) motor_type_ = MotorType(DCX10);
		else if(!motor_type.compare("DCX12")) motor_type_ = MotorType(DCX12);
		else if(!motor_type.compare("DCX14")) motor_type_ = MotorType(DCX14);
		else if(!motor_type.compare("DCX16")) motor_type_ = MotorType(DCX16);
		else if(!motor_type.compare("DCX22")) motor_type_ = MotorType(DCX22);
		else if(!motor_type.compare("DCX26")) motor_type_ = MotorType(DCX26);
		else if(!motor_type.compare("DCX32")) motor_type_ = MotorType(DCX32);
		else if(!motor_type.compare("RE10")) motor_type_ = MotorType(RE10);
		else if(!motor_type.compare("RE13")) motor_type_ = MotorType(RE13);
		else if(!motor_type.compare("RE25")) motor_type_ = MotorType(RE25);
		else if(!motor_type.compare("RE30")) motor_type_ = MotorType(RE30);
		else if(!motor_type.compare("ECX10")) motor_type_ = MotorType(ECX10);
		else if(!motor_type.compare("ECI30")) motor_type_ = MotorType(ECI30);
		else if(!motor_type.compare("ECI40")) motor_type_ = MotorType(ECI40);
		else if(!motor_type.compare("ECI52")) motor_type_ = MotorType(ECI52);
		else if(!motor_type.compare("EC4POLE")) motor_type_ = MotorType(EC4POLE);
		else if(!motor_type.compare("EC9_2F")) motor_type_ = MotorType(EC9_2F);
		else if(!motor_type.compare("EC32F_12")) motor_type_ = MotorType(EC32F_12);
		else if(!motor_type.compare("EC32F_24")) motor_type_ = MotorType(EC32F_24);
		else if(!motor_type.compare("EC90F")) motor_type_ = MotorType(EC90F);
		else if(!motor_type.compare("EC90FL")) motor_type_ = MotorType(EC90FL);

		//mode_
		if(!mode.compare("INTERPOLATED_POSITION_MODE")) mode_ = ActivatedModeOfOperation(INTERPOLATED_POSITION_MODE);
		else if(!mode.compare("PROFILE_VELOCITY_MODE")) mode_ = ActivatedModeOfOperation(PROFILE_VELOCITY_MODE);
		else if(!mode.compare("PROFILE_POSITION_MODE")) mode_ = ActivatedModeOfOperation(PROFILE_POSITION_MODE);
		else if(!mode.compare("POSITION_MODE")) mode_ = ActivatedModeOfOperation(POSITION_MODE);
		else if(!mode.compare("VELOCITY_MODE")) mode_ = ActivatedModeOfOperation(VELOCITY_MODE);
		else if(!mode.compare("CURRENT_MODE")) mode_ = ActivatedModeOfOperation(CURRENT_MODE);
		else if(!mode.compare("CYCLIC_SYNCHRONOUS_TORQUE_MODE")) mode_ = ActivatedModeOfOperation(CYCLIC_SYNCHRONOUS_TORQUE_MODE);
}

Controller::~Controller()
{
}

int	Controller::setNodeID(uint8_t node_id)
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

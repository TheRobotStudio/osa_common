/*
 * Copyright (c) 2018, The Robot Studio
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
 * @file robot_description.h
 * @author Cyril Jourdan <cyril.jourdan@therobotstudio.com>
 * @date Modified on Apr 11, 2018
 * @date Created on Apr 11, 2018
 * @version 0.1.1
 * @brief Header file for class RobotDescription
 */

#ifndef OSA_COMMON_ROBOT_DESCRIPTION_H
#define OSA_COMMON_ROBOT_DESCRIPTION_H

#include <ros/ros.h>
#include <string>
#include "controller.h"

namespace osa_common
{

/**
 * @brief Class that read robot description on the parameter server.
 */
class RobotDescription
{
public:

	/**
	 * @brief Constructor.
	 */
	RobotDescription(ros::NodeHandle *nh);

	/**
	 * @brief Destructor.
	 */
	~RobotDescription();

	//getter
	std::string getRobotNamespace() const { return robot_namespace_; };
	std::string getRobotName() const { return robot_name_; };
	int getRobotDof() const { return robot_dof_; };
	std::string getRobotCANDevice() const { return robot_can_device_; };
	int getRobotHeartbeat() const { return robot_heartbeat_; };
	std::vector<Controller*> getControllerList() const { return controller_list_; };

private:
	const static int data_length = 8;

	ros::NodeHandle* nh_;
	std::string robot_namespace_;
	std::string robot_name_;
	int robot_dof_; /**< Size of epos_controller_list_ */
	std::string robot_can_device_;
	int robot_heartbeat_;
	std::vector<Controller*> controller_list_;
};

} // osa_common

#endif // OSA_COMMON_ROBOT_DESCRIPTION_H

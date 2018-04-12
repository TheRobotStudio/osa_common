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
 * @file robot_description.cpp
 * @author Cyril Jourdan <cyril.jourdan@therobotstudio.com>
 * @date Modified on Apr 11, 2018
 * @date Created on Apr 11, 2018
 * @version 0.1.1
 * @brief Implementation file for class RobotDescription
 */

#include <sstream>
#include <vector>
#include <algorithm>
#include "robot_description.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
using namespace osa_common;

RobotDescription::RobotDescription(ros::NodeHandle *nh) :
nh_(nh),
robot_namespace_(""),
robot_name_(""),
robot_dof_(0),
robot_can_device_(""),
robot_heartbeat_(0),
controller_list_()
{
/*
	// Grab the namespace parameter
	try
	{
		nh_->param("robot_namespace", robot_namespace_, std::string("/my_robot_ns"));
	}
	catch(ros::InvalidNameException const &e)
	{
		ROS_ERROR(e.what());
		ROS_ERROR("Parameter robot_namespace didn't load correctly!");
		ROS_ERROR("Please check the name and try again.");

		throw e;
	}

	ROS_INFO("*** Grab the parameters from the YAML file ***");

	// Grab the parameters
	try
	{
		//load robot parameters
		if(!nh_->param(robot_namespace_ + "/robot/name", robot_name_, std::string(robot_namespace_ + "my_robot")))
		{
			ROS_WARN_STREAM("No " << robot_namespace_ << "/robot/name found in Parameter Server");
		}

		if(!nh_->param(robot_namespace_ + "/robot/dof", robot_dof_, int(0)))
		{
			ROS_WARN_STREAM("No " << robot_namespace_ << "/robot/dof found in Parameter Server");
		}

		if(!nh_->param(robot_namespace_ + "/robot/can_device", robot_can_device_, std::string("can0")))
		{
			ROS_WARN_STREAM("No " << robot_namespace_ << "/robot/can_device found in Parameter Server");
		}

		if(!nh_->param(robot_namespace_ + "/robot/heartbeat", robot_heartbeat_, int(0)))
		{
			ROS_WARN_STREAM("No " << robot_namespace_ << "/robot/heartbeat found in Parameter Server");
		}

		ROS_INFO("Robot name=%s, dof=%d, can=%s", robot_name_.c_str(), robot_dof_, robot_can_device_.c_str());

		//load controllers parameters
		//Example:
		//dof1: {node_id: 1, name: 'right wheel', type: 'EPOS4', inverted: true, motor: 'EC90', mode: 'PROFILE_VELOCITY_MODE', value: 0}

		bool dof_exist = true;
		//start with controller 1
		int dof_idx = 1;
		std::string rad_str = robot_namespace_ + "/dof"; //common radical name

		while(dof_exist)
		{
			//create the string "controller+index" to search for the controller parameter with that index number
			std::ostringstream dof_idx_path;
			dof_idx_path << rad_str << dof_idx;

			std::string absolute_str = "absolute_str";

			//ROS_INFO("string=%s", dof_idx_path.str().c_str());

			if(nh_->searchParam(dof_idx_path.str(), absolute_str))
			{
				//ROS_INFO("%s found in Parameter Server", dof_idx_path.str().c_str());
				//ROS_INFO("absolute_str = %s", absolute_str.c_str());

				//create variables to store the controller parameters:
				std:: string name;
				std:: string type;
				int node_id = 0;
				std:: string controller;
				std:: string motor;
				bool inverted;
				std:: string mode;
				int value;

				//grab the parameters of the current controller

				//name
				std::ostringstream name_path;
				name_path << absolute_str << "/name";
				if(!nh_->getParam(name_path.str(), name))
				{
					ROS_ERROR("Can't grab param name for %s", dof_idx_path.str().c_str());
					throw runtime_error("Can't grab param");
				}

				//type
				std::ostringstream type_path;
				type_path << absolute_str << "/type";
				if(!nh_->getParam(type_path.str(), type))
				{
					ROS_ERROR("Can't grab param type for %s", dof_idx_path.str().c_str());
					throw runtime_error("Can't grab param");
				}

				//node_id
				std::ostringstream node_id_path;
				node_id_path << absolute_str << "/node_id";
				if(!nh_->getParam(node_id_path.str(), node_id))
				{
					ROS_ERROR("Can't grab param node_id for %s", dof_idx_path.str().c_str());
					throw runtime_error("Can't grab param");
				}

				//controller
				std::ostringstream controller_path;
				controller_path << absolute_str << "/controller";
				if(!nh_->getParam(controller_path.str(), controller))
				{
					ROS_ERROR("Can't grab param controller for %s", dof_idx_path.str().c_str());
					throw runtime_error("Can't grab param");
				}

				//motor
				std::ostringstream motor_path;
				motor_path << absolute_str << "/motor";
				if(!nh_->getParam(motor_path.str(), motor))
				{
					ROS_ERROR("Can't grab param motor for %s", dof_idx_path.str().c_str());
					throw runtime_error("Can't grab param");
				}

				//inverted
				std::ostringstream inverted_path;
				inverted_path << absolute_str << "/inverted";
				if(!nh_->getParam(inverted_path.str(), inverted))
				{
					ROS_ERROR("Can't grab param inverted for %s", dof_idx_path.str().c_str());
					throw runtime_error("Can't grab param");
				}

				//mode
				std::ostringstream mode_path;
				mode_path << absolute_str << "/mode";
				if(!nh_->getParam(mode_path.str(), mode))
				{
					ROS_ERROR("Can't grab param mode for %s", dof_idx_path.str().c_str());
					throw runtime_error("Can't grab param");
				}

				//value
				std::ostringstream value_path;
				value_path << absolute_str << "/value";
				if(!nh_->getParam(value_path.str(), value))
				{
					ROS_ERROR("Can't grab param value for %s", dof_idx_path.str().c_str());
					throw runtime_error("Can't grab param");
				}

				//print the dof parameters
				ROS_INFO("%s : name[%s], type[%s], node_id[%d], controller[%s], motor[%s], inverted[%d], mode[%s], value[%d]", dof_idx_path.str().c_str(),
						name.c_str(), type.c_str(), node_id, controller.c_str(), motor.c_str(), inverted, mode.c_str(), value);

				//create a new controller
				Controller *motor_controller = new Controller(name, type, node_id, controller, motor, inverted, mode, value);

				controller_list_.push_back(motor_controller);

				//increment to search for the next controller
				dof_idx++;
			}
			else
			{
				dof_exist = false;
				//ROS_INFO("No more controllers found in Parameter Server");
			}

			//dof_exist = false;
		}

		dof_idx--;
		if(robot_dof_ == dof_idx) ROS_INFO("Same number of DOF(%d) and controllers(%d) defined in the Parameter Server!", robot_dof_, dof_idx);
		else
		{
			ROS_WARN("Not the same number of DOF(%d) and controllers(%d) defined in the Parameter Server!", robot_dof_, dof_idx);
			//throw 1;
			throw runtime_error("Not the same number of DOF and controllers defined in the Parameter Server!");
		}

		ROS_INFO("Parameters loaded successfully!\n");
	}
	catch(ros::InvalidNameException const &e)
	{
		ROS_ERROR(e.what());
		ROS_ERROR("Parameters didn't load correctly!");
		ROS_ERROR("Please modify your Parameter Server and try again.");

		throw e;
	}
*/
}

RobotDescription::~RobotDescription()
{
	//clear pointers in vector
	for(unsigned int i=0; i<controller_list_.size(); i++)
	{
		delete controller_list_[i];
	}

	//clear vectors
	controller_list_.clear();
}

void RobotDescription::grabRobotNamespaceFromParameterServer()
{
	// Grab the namespace parameter
	try
	{
		nh_->param("robot_namespace", robot_namespace_, std::string("/my_robot_ns"));
		ROS_INFO_STREAM("Grab the Robot Namespace parameter: [" << robot_namespace_ << "]");
	}
	catch(ros::InvalidNameException const &e)
	{
		ROS_ERROR(e.what());
		ROS_ERROR("Parameter robot_namespace didn't load correctly!");
		ROS_ERROR("Please check the name and try again.");

		throw e;
	}
}

void RobotDescription::grabRobotFromParameterServer()
{
	if(!robot_namespace_.empty())
	{
		// Grab the parameters
		try
		{
			//load robot parameters
			if(!nh_->param(robot_namespace_ + "/robot/name", robot_name_, std::string(robot_namespace_ + "my_robot")))
			{
				ROS_WARN_STREAM("No " << robot_namespace_ << "/robot/name found in Parameter Server");
			}

			if(!nh_->param(robot_namespace_ + "/robot/dof", robot_dof_, int(0)))
			{
				ROS_WARN_STREAM("No " << robot_namespace_ << "/robot/dof found in Parameter Server");
			}

			if(!nh_->param(robot_namespace_ + "/robot/can_device", robot_can_device_, std::string("can0")))
			{
				ROS_WARN_STREAM("No " << robot_namespace_ << "/robot/can_device found in Parameter Server");
			}

			if(!nh_->param(robot_namespace_ + "/robot/heartbeat", robot_heartbeat_, int(0)))
			{
				ROS_WARN_STREAM("No " << robot_namespace_ << "/robot/heartbeat found in Parameter Server");
			}

			ROS_INFO("Robot name=%s, dof=%d, can=%s", robot_name_.c_str(), robot_dof_, robot_can_device_.c_str());
		}
		catch(ros::InvalidNameException const &e)
		{
			ROS_ERROR(e.what());
			ROS_ERROR("Parameters didn't load correctly!");
			ROS_ERROR("Please modify your Parameter Server and try again.");

			throw e;
		}
	}
	else
	{
		throw runtime_error("robot_namespace_ is empty, please define the parameter 'robot_namespace' as local to your node!");
	}
}

void RobotDescription::grabDOFFromParameterServer()
{
	if(!robot_namespace_.empty())
	{
		// Grab the parameters
		try
		{
			bool dof_exist = true;
			//start with controller 1
			int dof_idx = 1;
			std::string rad_str = robot_namespace_ + "/dof"; //common radical name

			while(dof_exist)
			{
				//create the string "controller+index" to search for the controller parameter with that index number
				std::ostringstream dof_idx_path;
				dof_idx_path << rad_str << dof_idx;

				std::string absolute_str = "absolute_str";

				//ROS_INFO("string=%s", dof_idx_path.str().c_str());

				if(nh_->searchParam(dof_idx_path.str(), absolute_str))
				{
					//ROS_INFO("%s found in Parameter Server", dof_idx_path.str().c_str());
					//ROS_INFO("absolute_str = %s", absolute_str.c_str());

					//create variables to store the controller parameters:
					std:: string name;
					std:: string type;
					int node_id = 0;
					std:: string controller;
					std:: string motor;
					bool inverted;
					std:: string mode;
					int value;

					//grab the parameters of the current controller

					//name
					std::ostringstream name_path;
					name_path << absolute_str << "/name";
					if(!nh_->getParam(name_path.str(), name))
					{
						ROS_ERROR("Can't grab param name for %s", dof_idx_path.str().c_str());
						throw runtime_error("Can't grab param");
					}

					//type
					std::ostringstream type_path;
					type_path << absolute_str << "/type";
					if(!nh_->getParam(type_path.str(), type))
					{
						ROS_ERROR("Can't grab param type for %s", dof_idx_path.str().c_str());
						throw runtime_error("Can't grab param");
					}

					//node_id
					std::ostringstream node_id_path;
					node_id_path << absolute_str << "/node_id";
					if(!nh_->getParam(node_id_path.str(), node_id))
					{
						ROS_ERROR("Can't grab param node_id for %s", dof_idx_path.str().c_str());
						throw runtime_error("Can't grab param");
					}

					//controller
					std::ostringstream controller_path;
					controller_path << absolute_str << "/controller";
					if(!nh_->getParam(controller_path.str(), controller))
					{
						ROS_ERROR("Can't grab param controller for %s", dof_idx_path.str().c_str());
						throw runtime_error("Can't grab param");
					}

					//motor
					std::ostringstream motor_path;
					motor_path << absolute_str << "/motor";
					if(!nh_->getParam(motor_path.str(), motor))
					{
						ROS_ERROR("Can't grab param motor for %s", dof_idx_path.str().c_str());
						throw runtime_error("Can't grab param");
					}

					//inverted
					std::ostringstream inverted_path;
					inverted_path << absolute_str << "/inverted";
					if(!nh_->getParam(inverted_path.str(), inverted))
					{
						ROS_ERROR("Can't grab param inverted for %s", dof_idx_path.str().c_str());
						throw runtime_error("Can't grab param");
					}

					//mode
					std::ostringstream mode_path;
					mode_path << absolute_str << "/mode";
					if(!nh_->getParam(mode_path.str(), mode))
					{
						ROS_ERROR("Can't grab param mode for %s", dof_idx_path.str().c_str());
						throw runtime_error("Can't grab param");
					}

					//value
					std::ostringstream value_path;
					value_path << absolute_str << "/value";
					if(!nh_->getParam(value_path.str(), value))
					{
						ROS_ERROR("Can't grab param value for %s", dof_idx_path.str().c_str());
						throw runtime_error("Can't grab param");
					}

					//print the dof parameters
					ROS_INFO("%s : name[%s], type[%s], node_id[%d], controller[%s], motor[%s], inverted[%d], mode[%s], value[%d]", dof_idx_path.str().c_str(),
							name.c_str(), type.c_str(), node_id, controller.c_str(), motor.c_str(), inverted, mode.c_str(), value);

					//create a new controller
					Controller *motor_controller = new Controller(name, type, node_id, controller, motor, inverted, mode, value);

					controller_list_.push_back(motor_controller);

					//increment to search for the next controller
					dof_idx++;
				}
				else
				{
					dof_exist = false;
					//ROS_INFO("No more controllers found in Parameter Server");
				}

				//dof_exist = false;
			}

			dof_idx--;
			if(robot_dof_ == dof_idx) ROS_INFO("Same number of DOF(%d) and controllers(%d) defined in the Parameter Server!", robot_dof_, dof_idx);
			else
			{
				ROS_WARN("Not the same number of DOF(%d) and controllers(%d) defined in the Parameter Server!", robot_dof_, dof_idx);
				//throw 1;
				throw runtime_error("Not the same number of DOF and controllers defined in the Parameter Server!");
			}

			ROS_INFO("Parameters loaded successfully!\n");
		}
		catch(ros::InvalidNameException const &e)
		{
			ROS_ERROR(e.what());
			ROS_ERROR("Parameters didn't load correctly!");
			ROS_ERROR("Please check your YAML config file, load it in the Parameter Server and try again.");

			throw e;
		}
	}
	else
	{
		throw runtime_error("robot_namespace_ is empty, please define the parameter 'robot_namespace' as local to your node!");
	}
}

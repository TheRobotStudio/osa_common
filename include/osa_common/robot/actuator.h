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
 * @file actuator.h
 * @author Cyril Jourdan
 * @date Jan 17, 2017
 * @version 0.0.1
 * @brief Header file for abstract class Actuator
 *
 * Contact: contact@therobotstudio.com
 * Created on : Dec 12, 2016
 */

#ifndef OSA_GUI_COMMON_ACTUATOR_H
#define OSA_GUI_COMMON_ACTUATOR_H

#include "hardware.h"

namespace osa_common
{

/**
 * @brief Abstract class representing an actuator for a robot.
 *
 *  This is a base class for more specific actuators like electric motors.
 */
template <typename S, typename J>
class Actuator : public Hardware // S is std::string or QString for Qt packages like osa_gui
{
public:
	typedef S value_type;
	typedef typename std::vector<S>::size_type size_type;

protected:
	/** @brief Constructor. */
	Actuator();

	/**
	 * @brief Constructor.
	 * @param type build an Actuator object with the
	 */
	Actuator(S type);

	//Copy constructor
	//Actuator(Actuator const& actuator);

public:
	/** @brief Destructor. */
	virtual ~Actuator();

	//operator overloading
	//Actuator& operator=(Actuator const& actuator);

	/** @brief Setter for attribute type_. */
	int setType(S type); //will mainly be set by a daughter class like Motor

	/** @brief Getter for attribute type_. */
	S getType() const { return type_; };

	/**
	 * @brief Read method for JSON serialization.
	 * @param json
	 * @return void
	 */
	virtual void read(const J &json) = 0;

	/** @brief Write method for JSON serialization. */
	virtual void write(J &json)  const  = 0;

	/** @brief Method that display information for debug. */
	virtual void display() = 0;

protected:
	S type_; /**< Type of actuator, like electric motor, pneumatic, hydraulic actuator... */
	//int power in W ?
	//pRobot ?
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_ACTUATOR_H

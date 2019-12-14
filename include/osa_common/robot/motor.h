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
 * @file motor.h
 * @author Cyril Jourdan
 * @date Dec 8, 2016
 * @version 0.0.1
 * @brief Header file for class Motor
 *
 * Contact: contact@therobotstudio.com
 * Created on : Dec 8, 2016
 */

#ifndef OSA_GUI_COMMON_MOTOR_H
#define OSA_GUI_COMMON_MOTOR_H

#include <QString>
#include <QJsonObject>
#include "actuator.h"
#include "gearbox.h"
#include "encoder.h"
#include "controller.h"

namespace osa_common
{

// Forward declarations
class Gearbox;
class Encoder;

/**
 * @brief This class represents a motor.
 */
class Motor : public Actuator
{
public:
	/**
	 * @brief Constructor.
	 */
	Motor();
	/*Motor(QString brand, QString name, QString brushType, unsigned short int diameter,
					unsigned short int nominalVoltage, unsigned short int nominalSpeed, float nominalCurrent, float thermalTimeConstantWinding, unsigned short int numberOfPolePairs);
*/
	/*	Motor(QString brand, QString name, QString brushType, unsigned short int diameter,
			unsigned short int nominalVoltage, unsigned short int nominalSpeed, float nominalCurrent, float thermalTimeConstantWinding, unsigned short int numberOfPolePairs,
			Gearbox gearbox, Encoder encoder, Controller controller);*/
	//copy constructor
	//Motor(Motor const& motor);
	//operator overloading
	//Motor& operator=(Motor const& motor);

	/**
	 * @brief Destructor.
	 */
	virtual ~Motor();

	//setters
	int setBrushType(QString brush_type);
	int setDiameter(unsigned short int diameter);
	int setNominalVoltage(unsigned short int nominal_voltage);
	int setNominalSpeed(unsigned short int nominal_speed);
	int setNominalCurrent(float nominal_current);
	int	setThermalTimeConstantWinding(float thermal_time_constant_winding);
	int setNumberOfPolePairs(unsigned short int number_of_pole_pairs);
	int setGearbox(Gearbox* ptr_gearbox);
	int setEncoder(Encoder* ptr_encoder);
	//int	setPController(Controller* pController);

	//getters
	QString getBrushType() const { return brush_type_; };
	unsigned short int getDiameter() const { return diameter_; };
	unsigned short int getNominalVoltage() const { return nominal_voltage_; };
	unsigned short int getNominalSpeed() const { return nominal_speed_; };
	float getNominalCurrent() const { return nominal_current_; };
	float getThermalTimeConstantWinding() const { return thermal_time_constant_winding_; };
	unsigned short int getNumberOfPolePairs() const { return number_of_pole_pairs_; };
	Gearbox* getGearbox() const { return ptr_gearbox_; };
	Encoder* getEncoder() const { return ptr_encoder_; };
	//Controller* getPController() const { return m_pController; };

	//other methods
	virtual void display();

	//friends
	//operator overloading
	friend bool operator==(Motor const& motorA, Motor const& motorB);

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const;

private:
	QString brush_type_;
	unsigned short int diameter_;
	unsigned short int nominal_voltage_;
	unsigned short int nominal_speed_;
	float nominal_current_;
	float thermal_time_constant_winding_;
	unsigned short int number_of_pole_pairs_;
	Gearbox* ptr_gearbox_;	//Linked devices
	Encoder* ptr_encoder_;
	//Controller*			m_pController; //controller to which the motor is plugged
};

} // namespace osa_common

//other
//bool operator==(Motor const& motorA, Motor const& motorB);

#endif // OSA_GUI_COMMON_MOTOR_H

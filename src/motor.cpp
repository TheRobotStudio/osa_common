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
 * @file motor.cpp
 * @author Cyril Jourdan
 * @date Dec 8, 2016
 * @version 0.1.0
 * @brief Implementation file for class Motor
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 8, 2016
 */

#include <iostream>
#include "motor.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

/*
Motor::Motor() : Actuator("maxon motor","DCX 22 L"), brush_type_("Graphite Brushes"), diameter_(22),
	nominal_voltage_(36), nominal_speed_(11400), nominal_current_(1.03), thermal_time_constant_winding_(22), number_of_pole_pairs_(1),
	m_gearbox("91_GPX 22"), m_encoder("103_ENX 16 EASY"), m_controller()
{
}
*/

Motor::Motor() :
	Actuator(QString("Motor")),
	brush_type_(QString("")),
	diameter_(0),
	nominal_voltage_(0),
	nominal_speed_(0),
	nominal_current_(0),
	thermal_time_constant_winding_(0),
	number_of_pole_pairs_(0),
	ptr_gearbox_(NULL),
	ptr_encoder_(NULL)
	//m_pController()
{
}

/*
Motor::Motor(QString brand, QString name, QString brushType, unsigned short int diameter, unsigned int partNumber,
		unsigned short int nominal_voltage, unsigned short int nominal_speed, float nominal_current,
		float thermal_time_constant_winding, unsigned short int number_of_pole_pairs) :
		Hardware(brand, name), Actuator("Motor"), brush_type_(brushType), diameter_(diameter), m_partNumber(partNumber),
		nominal_voltage_(nominal_voltage), nominal_speed_(nominal_speed), nominal_current_(nominal_current),
		thermal_time_constant_winding_(thermal_time_constant_winding), number_of_pole_pairs_(number_of_pole_pairs),
		m_gearbox(), m_encoder(), m_pController()
{
}
*/
/*
Motor::Motor(Motor const& motor) : Actuator(motor), brush_type_(motor.brush_type_), diameter_(motor.diameter_),
		nominal_voltage_(motor.nominal_voltage_), nominal_speed_(motor.nominal_speed_), nominal_current_(motor.nominal_current_),
		thermal_time_constant_winding_(motor.thermal_time_constant_winding_), number_of_pole_pairs_(motor.number_of_pole_pairs_),
		ptr_gearbox_(motor.ptr_gearbox_), ptr_encoder_(motor.ptr_encoder_), m_pController(motor.m_pController)
{

}
*/
/*
Motor& Motor::operator=(Motor const& motor)
{
    if(this != &motor)
    {
    	m_name = motor.m_name;
    	nominal_voltage_ = motor.nominal_voltage_;
    	nominal_current_ = motor.nominal_current_;
    	ptr_gearbox_ = motor.ptr_gearbox_;
		ptr_encoder_ = motor.ptr_encoder_;
		m_pController = motor.m_pController;
    }

    return *this;
}*/

Motor::~Motor()
{
	delete ptr_gearbox_;
	delete ptr_encoder_;
	//delete m_pController;
}

int Motor::setBrushType(QString brushType)
{
	//check the value
	if(!brushType.isEmpty())
	{
		brush_type_ = brushType;

		return 0;
	}
	else
		return -1;
}

int Motor::setDiameter(unsigned short int diameter)
{
	//check the value
	if(diameter > 0)
	{
		diameter_ = diameter;

		return 0;
	}
	else
		return -1;
}

int Motor::setNominalVoltage(unsigned short int nominal_voltage)
{
	//check the value
	if(nominal_voltage > 0)
	{
		nominal_voltage_ = nominal_voltage;

		return 0;
	}
	else
		return -1;
}

int Motor::setNominalSpeed(unsigned short int nominal_speed)
{
	//check the value
	if(nominal_speed > 0)
	{
		nominal_speed_ = nominal_speed;

		return 0;
	}
	else
		return -1;
}

int Motor::setNominalCurrent(float nominal_current)
{
	//check the value
	if(nominal_current > 0)
	{
		nominal_current_ = nominal_current;

		return 0;
	}
	else
		return -1;
}

int	Motor::setThermalTimeConstantWinding(float thermal_time_constant_winding)
{
	//check the value
	if(thermal_time_constant_winding > 0)
	{
		thermal_time_constant_winding_ = thermal_time_constant_winding;

		return 0;
	}
	else
		return -1;
}

int Motor::setNumberOfPolePairs(unsigned short int number_of_pole_pairs)
{
	//check the value
	if(number_of_pole_pairs > 0)
	{
		number_of_pole_pairs_ = number_of_pole_pairs;

		return 0;
	}
	else
		return -1;
}

int Motor::setGearbox(Gearbox* ptr_gearbox)
{
	//check the value
	if(ptr_gearbox != 0)
	{
		ptr_gearbox_ = ptr_gearbox;

		return 0;
	}
	else
		return -1;
}

int Motor::setEncoder(Encoder* ptr_encoder)
{
	//check the value
	if(ptr_encoder != 0)
	{
		ptr_encoder_ = ptr_encoder;

		return 0;
	}
	else
		return -1;
}

/*
int	Motor::setPController(Controller* pController)
{
	//check the value
	if(pController != 0)
	{
		m_pController = pController;

		return 0;
	}
	else
		return -1;
}
*/

void Motor::display()
{
	Actuator::display(); //call the display method from Actuator class
	cout << "Brush type: " << brush_type_.toStdString() << endl;
	cout << "Diameter: " << diameter_ << endl;
	cout << "Nominal voltage: " << nominal_voltage_ << " V" << endl;
	cout << "Nominal Speed: " << nominal_speed_ << " rpm" << endl;
	cout << "Nominal current: " << nominal_current_ << " A" << endl;
	cout << "Thermal time constant winding: " << thermal_time_constant_winding_ << " s" << endl;
	cout << "Number of pole pairs: " << number_of_pole_pairs_ << endl;
	if(ptr_gearbox_ != 0) ptr_gearbox_->display();
	if(ptr_encoder_ != 0) ptr_encoder_->display();
	//if(m_pController != 0) m_pController->display();
	cout << endl;
}

/*
bool operator==(Motor const& motorA, Motor const& motorB)
{

}*/

void Motor::read(const QJsonObject &json)
{
	//call mother class method
	Actuator::read(json);

	//read attributes
	brush_type_ = json["brushType"].toString();
	diameter_ = (unsigned short int)json["diameter"].toDouble();
	nominal_voltage_ = (unsigned short int)json["nominal_voltage"].toDouble();
	nominal_speed_ = (unsigned short int)json["nominal_speed"].toDouble();
	nominal_current_ = (float)json["nominal_current"].toDouble();
	thermal_time_constant_winding_ = (float)json["thermal_time_constant_winding"].toDouble();
	number_of_pole_pairs_ = (unsigned short int)json["number_of_pole_pairs"].toDouble();
	ptr_gearbox_->read(json);
	ptr_encoder_->read(json);
	//m_pController->read(json);
}

void Motor::write(QJsonObject &json) const
{
	//call mother class method
	Actuator::write(json);

	//write attributes
	json["brushType"] = brush_type_;
	json["diameter"] = (double)diameter_;
	json["nominal_voltage"] = (double)nominal_voltage_;
	json["nominal_speed"] = (double)nominal_speed_;
	json["nominal_current"] = (double)nominal_current_;
	json["thermal_time_constant_winding"] = (double)thermal_time_constant_winding_;
	json["number_of_pole_pairs"] = (double)number_of_pole_pairs_;
	ptr_gearbox_->write(json);
	ptr_encoder_->write(json);
	//m_pController->write(json);
}

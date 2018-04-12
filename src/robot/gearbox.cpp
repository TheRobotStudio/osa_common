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
 * @file gearbox.cpp
 * @author Cyril Jourdan
 * @date Dec 9, 2016
 * @version 0.1.0
 * @brief Implementation file for class Gearbox
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 9, 2016
 */

#include <iostream>
#include "gearbox.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Gearbox::Gearbox() :
	diameter_(0),
	reduction_numerator_(0),
	reduction_denominator_(0),
	number_of_stages_(0)
	//m_pMotor(0) //m_name("91_GPX 22")
{
}

/*
Gearbox::Gearbox(QString reduction) : diameter_(0), m_reduction(reduction), number_of_stages_(0), m_pMotor(0)
{
}*/
/*
//copy constructor
Gearbox::Gearbox(Gearbox const& gearbox) : diameter_(gearbox.diameter_), m_reduction(gearbox.m_reduction), number_of_stages_(gearbox.number_of_stages_), m_pMotor(gearbox.m_pMotor)
{
}*/

Gearbox::~Gearbox()
{
	//delete m_pMotor;
}

int Gearbox::setDiameter(unsigned int diameter)
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

int Gearbox::setReductionNumerator(unsigned short int reduction_numerator)
{
	//check the value
	if(reduction_numerator > 0)
	{
		reduction_numerator_ = reduction_numerator;

		return 0;
	}
	else
		return -1;
}

int Gearbox::setReductionDenominator(unsigned short int reduction_denominator)
{
	//check the value
	if(reduction_denominator > 0)
	{
		reduction_denominator_ = reduction_denominator;

		return 0;
	}
	else
		return -1;
}

int Gearbox::setNumberOfStages(unsigned short int number_of_stages)
{
	//check the value
	if(number_of_stages > 0)
	{
		number_of_stages_ = number_of_stages;

		return 0;
	}
	else
		return -1;
}

/*
int Gearbox::setPMotor(Motor* pMotor)
{
	//check the value
	if(pMotor != 0)
	{
		m_pMotor = pMotor;

		return 0;
	}
	else
		return -1;
}
*/

void Gearbox::display()
{
	cout << "Gearbox: " << endl;
	Hardware::display(); //call the display method from mother class
	cout << "Diameter: " << diameter_ << endl;
	cout << "ReductionNumerator: " << reduction_numerator_ << endl;
	cout << "ReductionDenominator: " << reduction_denominator_ << endl;
	cout << "Number of stages: " << number_of_stages_ << endl;
}

void Gearbox::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//read attributes
	diameter_ = (unsigned int)json["diameter"].toDouble();
	reduction_numerator_ = json["reduction_numerator"].toDouble();
	reduction_denominator_ = json["reduction_denominator"].toDouble();
	number_of_stages_ = (unsigned short int)json["number_of_stages"].toDouble();

	//m_pMotor->read(json); //TODO find a way to avoid infinite serialization loop
}

void Gearbox::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//read attributes
    json["diameter"] = (double)diameter_;
	json["reduction_numerator"] = reduction_numerator_;
	json["reduction_denominator"] = reduction_denominator_;
	json["number_of_stages"] = (double)number_of_stages_;
	//m_pMotor->write(json); //TODO find a way to avoid infinite serialization loop
}

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
 * @file actuator.cpp
 * @author Cyril Jourdan
 * @date Dec 12, 2016
 * @version 0.1.0
 * @brief Implementation file for abstract class Actuator
 *
 * Contact: contact@therobotstudio.com
 * Created on : Dec 12, 2016
 */

#include <actuator.h>
#include <iostream>
#include <string>

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Actuator::Actuator() :
	Hardware(),
	type_(QString(""))
{
}

Actuator::Actuator(QString type) : Hardware(), type_(type)
{
}

/*
Actuator::Actuator(Actuator const& actuator) : Hardware(actuator), type_(actuator.type_)
{
}
*/

Actuator::~Actuator()
{
}

/*
Actuator& Actuator::operator=(Actuator const& actuator)
{
	if(this != &actuator) //check wether objects are different
	{
		//call mother class operator=
		Hardware::operator=(actuator);
		type_ = actuator.type_; //copy attribute
	}

	return *this; //On renvoie l'objet lui-même
}
*/

int Actuator::setType(QString type)
{
	//check the value
	if(!type.isEmpty())
	{
		type_ = type;

		return 0;
	}
	else
		return -1;
}

void Actuator::display()
{
	Hardware::display(); //call the display method from Hardware class
	cout << "Type: " << type_.toStdString() << endl;
}

void Actuator::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//write attributes
	type_ = json["type"].toString();
}

void Actuator::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//write attributes
    json["type"] = type_;
}

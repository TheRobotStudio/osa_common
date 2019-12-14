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
 * @file hardware.cpp
 * @author Cyril Jourdan
 * @date Dec 12, 2016
 * @version 0.1.0
 * @brief Implementation file for class Hardware
 *
 * Contact: contact@therobotstudio.com
 * Created on : Dec 12, 2016
 */

#include <iostream>
#include "hardware.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Hardware::Hardware() :
	brand_(QString("")),
	name_(QString("")),
	part_number_(0),
	version_(QString(""))
	//m_modelPath(QString(""))
{
}

/*
Hardware::Hardware(QString name) : brand_(""), name_(name), part_number_(0), version_(""), m_modelPath("")
{
}

Hardware::Hardware(QString brand, QString name) : brand_(brand), name_(name), part_number_(0), version_(""), m_modelPath("")
{
}

Hardware::Hardware(std::QString brand, std::QString name, unsigned int part_number, std::QString version, std::QString modelPath) :
		brand_(brand), name_(name), part_number_(part_number), version_(version), m_modelPath(modelPath)
{
}
*/
/*
Hardware::Hardware(Hardware const& hardware) : brand_(hardware.brand_), name_(hardware.name_),
		part_number_(hardware.part_number_), version_(hardware.version_), m_modelPath(hardware.m_modelPath)
{
}
*/

Hardware::~Hardware()
{
}

int Hardware::setBrand(QString brand)
{
	//check the value
	if(!brand.isEmpty())
	{
		brand_ = brand;

		return 0;
	}
	else
		return -1;
}

int Hardware::setName(QString name)
{
	//check the value
	if(!name.isEmpty())
	{
		name_ = name;

		return 0;
	}
	else
		return -1;
}

int Hardware::setPartNumber(unsigned int part_number)
{
	//check the value
	if(part_number > 0)
	{
		part_number_ = part_number;

		return 0;
	}
	else
		return -1;
}

int Hardware::setVersion(QString version)
{
	//check the value
	if(!version.isEmpty())
	{
		version_ = version;

		return 0;
	}
	else
		return -1;
}
/*
int Hardware::setModelPath(QString modelPath)
{
	//check the value
	if(!modelPath.isEmpty())
	{
		m_modelPath = modelPath;

		return 0;
	}
	else
		return -1;
}
*/

void Hardware::display()
{
	cout << "Brand: " << brand_.toStdString() << endl;
	cout << "Name: "<< name_.toStdString() << endl;
	cout << "PartNumber: " << part_number_ << endl;
	cout << "Version: " << version_.toStdString() << endl;
	//cout << "Model path: " << m_modelPath.toStdString() << endl;
}

void Hardware::read(const QJsonObject &json)
{
	brand_ = json["brand"].toString();
	name_ = json["name"].toString();
	part_number_ = (unsigned int)json["part_number"].toDouble();
	version_ = json["version"].toString();
	//m_modelPath = json["modelPath"].toString();
}

//TODO solve the issue that it overwrites the labels which have the same name when multiple objects have Hardware as a mother class
void Hardware::write(QJsonObject &json) const
{
	json["brand"] = brand_;
	json["name"] = name_;
	json["part_number"] = (double)part_number_;
	json["version"] = version_;
	//json["modelPath"] = m_modelPath;
}

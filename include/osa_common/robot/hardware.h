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
 * @file hardware.h
 * @author Cyril Jourdan
 * @date Dec 12, 2016
 * @version 0.0.1
 * @brief Header file for abstract class Hardware
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 12, 2016
 */

#ifndef OSA_GUI_COMMON_HARDWARE_H
#define OSA_GUI_COMMON_HARDWARE_H

#include <QString>
#include <QJsonObject>
#include <string>

namespace osa_common
{

/**
 * @brief This is the base class for all kinds of physical components in the robot.
 */
class Hardware
{
protected:
	/**
	 * @brief Constructor.
	 */
	Hardware();
	//Hardware(QString name);
	//Hardware(QString brand, QString name);
	//Hardware(QString brand, QString name, unsigned int partNumber, QString version, QString modelPath);

	//copy constructor
	//Hardware(Hardware const& hardware);
	//operator overloading
	//Hardware& operator=(Hardware const& hardware);

public:
	/**
	 * @brief Destructor.
	 */
	virtual ~Hardware();

	//setters
	int setBrand(QString brand);
	int setName(QString name);
	int setPartNumber(unsigned int part_number);
	int setVersion(QString version);
	//int setModelPath(QString modelPath);

	//getters
	QString getBrand() const { return brand_; };
	QString getName() const { return name_; };
	unsigned int getPartNumber() const { return part_number_; };
	QString getVersion() const { return version_; };
	//QString getModelPath() const { return m_modelPath; };

	//other methods
	virtual void display() = 0;

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json) = 0;

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const = 0;

	//friends
	//operator overloading
	//friend bool operator==(Sensor const& sensorA, Sensor const& sensorB);

protected:
	QString brand_;
	QString name_;
	unsigned int part_number_;
	QString version_;
	//QString model_path_; //3D model or picture/drawing
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_HARDWARE_H

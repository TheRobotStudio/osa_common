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
 * @file serial_communication.h
 * @author Cyril Jourdan
 * @date Dec 14, 2016
 * @version 0.0.1
 * @brief Header file for class SerialCommunication
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 14, 2016
 */

#ifndef OSA_GUI_COMMON_SERIAL_COMMUNICATION_H
#define OSA_GUI_COMMON_SERIAL_COMMUNICATION_H

#include <QString>
#include <QJsonObject>
#include "communication_layer.h"

namespace osa_common
{

/**
 * @brief Class representing a serial communication layer.
 */
class SerialCommunication : public CommunicationLayer
{
public:
	/**
	 * @brief Constructor.
	 */
	SerialCommunication();
	//copy constructor
	//SerialCommunication(SerialCommunication const& serialCommunication);

	/**
	 * @brief Destructor.
	 */
	~SerialCommunication();

	//setters
	int setFilePath(QString file_path);

	//getters
	QString getFilePath() const { return file_path_; };

	//other methods
	char* readChar();
	int writeChar(char* data);
	virtual void display();

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const;

private:
	QString file_path_;
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_SERIAL_COMMUNICATION_H

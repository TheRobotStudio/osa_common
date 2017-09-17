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
 * @file project.h
 * @author Cyril Jourdan
 * @date Dec 8, 2016
 * @version 0.0.1
 * @brief Header file for class Project
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 8, 2016
 */

#ifndef OSA_GUI_COMMON_COMMON_PROJECT_H
#define OSA_GUI_COMMON_COMMON_PROJECT_H

#include <QFile>
#include <QJsonObject>
#include "robot.h"
#include "../sequencer/posture.h"
#include "../sequencer/sequence.h"

namespace osa_common
{

/**
 * @brief This class defines a project.
 */
class Project
{
public:
	/**
	 * @brief Constructor.
	 */
	Project();

	/**
	 * @brief Destructor.
	 */
	~Project();

	//setters
	int setFile(QFile* ptr_file);
	int setRobot(Robot* ptr_robot);
	int setSequence(sequencer::Sequence* ptr_sequence);
	int addPosture(sequencer::Posture* ptr_posture);

	//getters
	QFile* getPFile() const { return ptr_file_; };
	Robot* getPRobot() const { return ptr_robot_; };
	sequencer::Sequence* getPSequence() const { return ptr_sequence_; };
	QList<sequencer::Posture*> getLpPosture() const { return posture_list_; };

	/** @brief Read method for JSON serialization. */
	void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	void write(QJsonObject &json) const;

protected:
	QFile* ptr_file_;
	Robot* ptr_robot_;
	sequencer::Sequence* ptr_sequence_; //TODO have a QList of Sequences
	QList<sequencer::Posture*> posture_list_;
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_COMMON_PROJECT_H

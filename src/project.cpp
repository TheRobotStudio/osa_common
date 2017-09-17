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
 * @file project.cpp
 * @author Cyril Jourdan
 * @date Dec 8, 2016
 * @version 0.1.0
 * @brief Implementation file for class Project
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 8, 2016
 */

#include <QJsonArray>
#include <iostream>
#include "project.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Project::Project() :
	ptr_file_(NULL),
	ptr_robot_(NULL),
	ptr_sequence_(NULL),
	posture_list_(QList<sequencer::Posture*>())
{
}

Project::~Project()
{
	delete ptr_file_;
	delete ptr_robot_;
	delete ptr_sequence_;
	//TODO delete Qlist
}

int Project::setFile(QFile* ptr_file)
{
	//check the value
	if(ptr_file != 0)
	{
		ptr_file_ = ptr_file;

		return 0;
	}
	else
		return -1;
}

int Project::setRobot(Robot* ptr_robot)
{
	//check the value
	if(ptr_robot != 0)
	{
		ptr_robot_ = ptr_robot;

		return 0;
	}
	else
		return -1;
}

int Project::setSequence(sequencer::Sequence* ptr_sequence)
{
	//check the value
	if(ptr_sequence != 0)
	{
		ptr_sequence_ = ptr_sequence;

		return 0;
	}
	else
		return -1;
}

int Project::addPosture(sequencer::Posture* ptr_posture)
{
	//check the value
	if(ptr_posture != 0)
	{
		posture_list_.append(ptr_posture);

		return 0;
	}
	else
		return -1;
}

void Project::read(const QJsonObject &json)
{
	ptr_robot_->read(json);
	ptr_sequence_->read(json);

	//TODO posture list
}

void Project::write(QJsonObject &json) const
{
	ptr_robot_->write(json);
	ptr_sequence_->write(json);

	//TODO posture list
}

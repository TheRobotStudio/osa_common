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
 * @file encoder.cpp
 * @author Cyril Jourdan
 * @date Dec 9, 2016
 * @version 0.1.0
 * @brief Implementation file for class Encoder
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 9, 2016
 */

#include <iostream>
#include "encoder.h"

using namespace std;
using namespace osa_gui;
using namespace common;
using namespace Qt;

Encoder::Encoder() :
	counts_per_turn_(0),
	number_of_channels_(0)
	//m_pMotor(0) //m_name("103_ENX 16 EASY")
{
}

/*
Encoder::Encoder(unsigned int counts_per_turn, unsigned short int number_of_channels) : counts_per_turn_(counts_per_turn), number_of_channels_(number_of_channels), m_pMotor(0)
{
}*/
/*
//copy constructor
Encoder::Encoder(Encoder const& encoder) : counts_per_turn_(encoder.counts_per_turn_), number_of_channels_(encoder.number_of_channels_), m_pMotor(0)
{
}
*/

Encoder::~Encoder()
{
	//delete m_pMotor;
}

int Encoder::setCountsPerTurn(unsigned int counts_per_turn)
{
	//check the value
	if(counts_per_turn > 0)
	{
		counts_per_turn_ = counts_per_turn;

		return 0;
	}
	else
		return -1;
}

int Encoder::setNumberOfChannels(unsigned short int number_of_channels)
{
	//check the value
	if(number_of_channels > 0)
	{
		number_of_channels_ = number_of_channels;

		return 0;
	}
	else
		return -1;
}

/*
int	Encoder::setPMotor(Motor* pMotor)
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

void Encoder::display()
{
	cout << endl << "Encoder: " << endl;
	Hardware::display(); //call the display method from mother class
	cout << "Counts per turn: " << counts_per_turn_ << endl;
	cout << "Number of channels: " << number_of_channels_ << endl;
}

void Encoder::read(const QJsonObject &json)
{
	//call mother class method
	Hardware::read(json);

	//read attributes
	counts_per_turn_ = (unsigned int)json["counts_per_turn"].toDouble();
	number_of_channels_ = (unsigned short int)json["number_of_channels"].toDouble();
	//m_pMotor->read(json); //TODO find a way to avoid infinite serialization loop
}

void Encoder::write(QJsonObject &json) const
{
	//call mother class method
	Hardware::write(json);

	//write attributes
    json["counts_per_turn"] = (double)counts_per_turn_;
	json["number_of_channels"] = (double)number_of_channels_;
	// m_pMotor->write(json); //TODO find a way to avoid infinite serialization loop
}

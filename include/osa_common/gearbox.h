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
 * @file gearbox.h
 * @author Cyril Jourdan
 * @date Dec 9, 2016
 * @version 0.0.1
 * @brief Header file for class Gearbox
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 9, 2016
 */

#ifndef OSA_GUI_COMMON_GEARBOX_H
#define OSA_GUI_COMMON_GEARBOX_H

#include <QString>
#include <QJsonObject>
#include <string>
#include "hardware.h"
#include "motor.h"

namespace osa_common
{

// Forward declarations
class Motor;

/**
 * @brief Class representing a motor gearbox.
 */
class Gearbox : public Hardware
{
public:
	/**
	 * @brief Constructor.
	 */
	Gearbox();
	//Gearbox(QString reduction);
	//copy constructor
	//Gearbox(Gearbox const& gearbox);

	/**
	 * @brief Destructor.
	 */
	~Gearbox();

	//setters
	int setDiameter(unsigned int diameter);
	int setReductionNumerator(unsigned short int reduction_numerator);
	int setReductionDenominator(unsigned short int reduction_denominator);
	int setNumberOfStages(unsigned short int number_of_stages);
	//int setPMotor(Motor* pMotor);

	//getters
	unsigned int getDiameter() const { return diameter_; };
	unsigned short int getReductionNumerator()	const { return reduction_numerator_; };
	unsigned short int getReductionDenominator() const { return reduction_denominator_; };
	unsigned short int getNumberOfStages() const { return number_of_stages_; };
	//Motor*				getPMotor()			const { return m_pMotor; };

	//other methods
	virtual void display();

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const;

private:
	unsigned int diameter_;
	unsigned short int reduction_numerator_;
	unsigned short int reduction_denominator_;
	unsigned short int number_of_stages_;
	//Motor* m_pMotor; //motor reference
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_GEARBOX_H

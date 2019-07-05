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
 * @file usb_device.h
 * @author Cyril Jourdan
 * @date Dec 13, 2016
 * @version 0.0.1
 * @brief Header file for class USBDevice
 *
 * Contact: cyril.jourdan@therobotstudio.com
 * Created on : Dec 13, 2016
 */

#ifndef OSA_GUI_COMMON_USB_DEVICE_H
#define OSA_GUI_COMMON_USB_DEVICE_H

#include <QString>
#include <QJsonObject>
#include "hardware.h"

namespace osa_common
{

/**
 * @brief This is the base class for USB devices like cameras for example.
 */
class USBDevice : public Hardware
{
protected:
	/** @brief Constructor. */
	USBDevice();

public:
	/** @brief Destructor. */
	virtual ~USBDevice();

	//setters
	/** @brief Destructor.
	 *  @param
	 *  @return int
	 */
	int setVendorID(QString vendor_id);
	int setProductID(QString product_id);
	int setFilePatch(QString file_path);

	//TODO either have getter or setter, but probably not both, setting parameters can be instead in the constructor
	//getters
	QString	getVendorID() const { return vendor_id_; };
	QString	getProductID() const { return product_id_; };
	QString getFilePath() const { return file_path_; };

	//other methods
	virtual void display();

	/** @brief Read method for JSON serialization. */
	virtual void read(const QJsonObject &json);

	/** @brief Write method for JSON serialization. */
	virtual void write(QJsonObject &json) const;

protected:
	QString	vendor_id_;
	QString	product_id_;
	QString file_path_;
};

} // namespace osa_common

#endif // OSA_GUI_COMMON_USB_DEVICE_H

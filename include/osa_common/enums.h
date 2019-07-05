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
 * @file enums.h
 * @author Cyril Jourdan <cyril.jourdan@therobotstudio.com>
 * @date Modified on Jan 25, 2019
 * @date Created on Mar 11, 2015
 * @version 0.1.1
 * @brief header file for enums definitions
 */

#ifndef OSA_COMMON_ENUMS_H
#define OSA_COMMON_ENUMS_H

#define NUMBER_BYTES_PER_MSG        8
#define NB_SAMPLES_MEDIAN           5
#define PAUSE                       10
#define EPOS_OK                     0
#define EPOS_ERROR                  -1
#define TIMEOUT                     10000

/**
 * @enum DegreeOfFreedomType
 * @brief Enumeration that tells the type of a Degree Of Freedom.
 */
enum DegreeOfFreedomType
{
    TENDON = 0,
    WHEEL = 1,
    CLASSICAL = 2,
	SEA = 3
}; 

/**
 * @enum MotorType
 * @brief Enumeration that tells the type of a motor.
 */
enum MotorType
{
    NONE =0,
    DCX10,
    DCX12,
    DCX14,
    DCX16,
    DCX22,
    DCX26,
    DCX32,
    RE10,
    RE13,
    RE25,
    RE30,
    ECX10,
    ECI30,
    ECI40,
    ECI52,
    EC4POLE,
    EC9_2F, //EC9.2Fl
    EC32F_12, //12V
    EC32F_24, //24V
    EC90F,
    EC90FL //frameless
};

/**
 * @enum ControllerType
 * @brief Enumeration that tells the type of a motor controller.
 */
enum ControllerType
{
    NOT_USED = 0,
    EPOS2 = 1,
    EPOS4 = 2
}; 

/**
 * @enum ActivatedModeOfOperation
 * @brief Enumeration that tells the activated mode of operation of a motor controller.
 */
enum ActivatedModeOfOperation
{
    INTERPOLATED_POSITION_MODE = 0,
    PROFILE_VELOCITY_MODE = 1,
    PROFILE_POSITION_MODE = 2,
    POSITION_MODE = 3,
    VELOCITY_MODE = 4,
    CURRENT_MODE = 5,  
    CYCLIC_SYNCHRONOUS_TORQUE_MODE = 6
    //NO_MODE = 15
}; 

/**
 * @enum ROSCommand
 * @brief Enumeration that tells the possible commands received from ROS.
 */
enum ROSCommand //TODO special EPOS4 cases
{
    SET_TARGET_POSITION = 0,
    SET_TARGET_VELOCITY = 1,
    SET_PROFILE_ACCELERATION = 2,
    SET_PROFILE_DECELERATION = 3,
    SET_PROFILE_VELOCITY = 4,
    SET_OUTPUT_CURRENT_LIMIT = 5,
    SET_CONTROLWORD = 6,
    SET_CURRENT_MODE_SETTING_VALUE = 7,
    SET_MAXIMAL_SPEED_IN_CURRENT_MODE = 8,
    SET_MODES_OF_OPERATION = 9,
    SEND_DUMB_MESSAGE = 15
};

#endif // OSA_COMMON_ENUMS_H

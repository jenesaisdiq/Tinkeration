/**
****************************************************************************
* @file    tinkeration.h
* @authors  Satish Nair, Zachary Crockett, Mohit Bhoite; wrapped into library by Richard Whitney
* @version V0.0.1
* @date    08-August-2014
* @brief   Tinker library
****************************************************************************
 Copyright (c) 2014 Spark Labs, Inc.  All rights reserved.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this program; if not, see <http://www.gnu.org/licenses/>.
****************************************************************************
*/


Class Tinkeration {
	public:
		Tinkeration();

		void
			begin(void);

		uint8_t
			tinkerDigitalRead(String pin),
			tinkerDigitalWrite(String command),
			tinkerAnalogRead(String pin),
			tinkerAnalogWrite(String command);

	private:


};
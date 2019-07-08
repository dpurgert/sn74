/***********************************************************************
*
*                 Program: Arduino SN74HC595 Library - sn74.h
*                      by: Dan Purgert <dan@djph.net>    
*               copyright: 2018
*                 version: 0.1
*                 purpose: Library for the SN74HC595 shift register, as
*                        : it's readily available from suppliers
*
*                 license: GPL v2 (only)
*              repository: http://github.com/dpurgert
*
*  This program is free software; you can redistribute it and/or
*  modify it under the terms of the GNU General Public License
*  as published by the Free Software Foundation.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
*  02110-1301, USA.
***********************************************************************/

#ifndef SN74_H
#define SN74_H

#include <stdint.h>
#include "sn74_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Latch pulse setup.  Required for when using separate pins for latch
 * (RCLK) and clock (SRCLK) clocking. */
/** Enable Timer1 Overflow interrupt, which fires after a LAT pulse; and 
    disable any Timer1 interrupts. */
#define setLATinterrupt()    TIFR1 |= _BV(TOV1); TIMSK = _BV(TOIE1)
#define clearLATinterrupt() TIMSK = 0

/** Enables Latch pulses */
#define enableLATpulse()    TCCR0A = _BV(COM1A1) | _BV(COM1B1)

/** Disables latch pulses */
#define disableLATpulse() TCCR0A = _BV(COM1B1)

void snInit (void);

void snCLR (void);
void snOE (uint8_t on);

void snShiftInit (void);
void snShift (uint8_t b);

void snLat (void);

#ifdef __cplusplus
}
#endif
#endif

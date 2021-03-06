/*
 * Copyright (c) 2010, Vanderbilt University
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE VANDERBILT UNIVERSITY BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE VANDERBILT
 * UNIVERSITY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE VANDERBILT UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE VANDERBILT UNIVERSITY HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Author: Janos Sallai, Miklos Maroti
 * Author: Thomas Schmid (adapted for CC2520)
 */

#ifndef __RADIOCONFIG_H__
#define __RADIOCONFIG_H__


#include <Timer.h>
#include <message.h>
#include <CC2520DriverLayer.h>

/* This is the default value of the PA_POWER field of the TXCTL register. */
#ifndef CC2520_DEF_RFPOWER
#define CC2520_DEF_RFPOWER	0
#endif

/* This is the default value of the CHANNEL field of the FSCTRL register. */
#ifndef CC2520_DEF_CHANNEL
#define CC2520_DEF_CHANNEL	11
#endif

/* The number of microseconds a sending micaz mote will wait for an acknowledgement */
#ifndef SOFTWAREACK_TIMEOUT
#define SOFTWAREACK_TIMEOUT	800
#endif

/**
 * This is the timer type of the radio alarm interface
 */
typedef TMicro TRadio;

/**
 * The number of radio alarm ticks per one microsecond .
 *
 * Removed three '0s because of overflow...
 */
#define RADIO_ALARM_MICROSEC    48000 / 32 / 1000

/**
 * The base two logarithm of the number of radio alarm ticks per one millisecond
 */
// FIXME: this needs to be calibrated
#define RADIO_ALARM_MILLI_EXP	(5)

/**
 * Make PACKET_LINK automaticaly enabled for Ieee154MessageC
 */
#if !defined(TFRAMES_ENABLED) && !defined(PACKET_LINK)
#define PACKET_LINK
#endif

#endif//__RADIOCONFIG_H__

/**
 * This file is part of icd2-osso-ic-dev
 *
 * Copyright (C) 2005-2007 Nokia Corporation. All rights reserved.
 *
 * Contact: Patrik Flykt <patrik.flykt@nokia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 * @author Kalle Valo <kalle.valo@nokia.com>
 * @author Patrik Flykt <patrik.flykt@nokia.com>
 */


#ifndef OSSO_IC_H
#define OSSO_IC_H

#ifdef __cplusplus
extern "C" {
#endif

/* These are the remaining defines of the deprecated osso-ic.h library */

/* IAP connect reasons */
/**
 * IAP connect reason which states that connection attempt has been initiated
 * by user. It shall be used only if the connection is a user-triggered event,
 * i.e. link is clicked, send/receive button in email is clicked, etc.
 */
#define OSSO_IAP_REQUESTED_CONNECT      0x00

/**
 * The IAP connection request which is a result of timed event. Use this if the
 * application itself (automatically) starts the connection, e.g. an email
 * program checks the mailbox in the background, a browser tries to refresh a
 * page, etc.
 *
 * The Internet connection will be established if:
 * - OSSO_IAP_ANY is requested and a connection is on
 * - a specific connection is requested and that specific connection is already
 *   on
 * - for all other cases the connection attempt is denied.
 */
#define OSSO_IAP_TIMED_CONNECT          0x01


/**
 * IAP meta name which forces to ask the user which IAP should be
 * used for connection.
 *
 * Even if an IAP connection is already established, this will force the
 * connection to be changed.
 *
 * @remarks <em> Use of this meta name is highly discouraged. </em> It
 * should be used only in very special cases and after thorough
 * consideration.
 */
#define OSSO_IAP_ASK                    "[ASK]"

/**
 * IAP meta name which is normally used.
 *
 * If there isn't any connection opened, either asks the IAP to be used
 * from user or uses the preferred IAP if one is set. If there is an
 * connection already opened, it will be used.
 */
#define OSSO_IAP_ANY                    "[ANY]"

/**
 * IAP meta name for scanning; used only in status update signals.
 */
#define OSSO_IAP_SCAN                   "[SCAN]"

#ifdef __cplusplus
}
#endif

#endif

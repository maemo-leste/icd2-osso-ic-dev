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
 * @author Patrik Flykt <patrik.flykt@nokia.com>
 */

#ifndef OSSO_IC_GCONF_H
#define OSSO_IC_GCONF_H

#ifdef __cplusplus
extern "C" {
#endif

/** GConf path of ICd related configuration data for non-subdir data */
#define ICD_GCONF_PATH			"/system/osso/connectivity/IAP"

/** GConf location for connectivity subdirs */
#define ICD_GCONF_SETTINGS              "/system/osso/connectivity"

/** WLAN TX power level (integer) */
#define ICD_GCONF_WLAN_TX_POWER		ICD_GCONF_PATH "/wlan_tx_power"

/** Allow linklocal IP address in infrastructure WLANs (boolean) */
#define ICD_GCONF_LINKLOCAL_WLAN_INFRA  ICD_GCONF_PATH "/linklocal_wlan_infra"

/** Network type to module name mapping path */
#define ICD_GCONF_NETWORK_MAPPING       ICD_GCONF_SETTINGS "/network_type"

/** List of network types (strings) to autoconnect to */
#define ICD_GCONF_NETWORK_AUTO_CONNECT  \
                                      ICD_GCONF_NETWORK_MAPPING "/auto_connect"

/** Network search interval in seconds when not connected */
#define ICD_GCONF_NETWORK_SEARCH_INTERVAL \
                                   ICD_GCONF_NETWORK_MAPPING "/search_interval"

/** Wheter to make an automatic connection attempt even while connected */
#define ICD_GCONF_NETWORK_CHANGE_WHILE_CONNECTED \
                    ICD_GCONF_NETWORK_MAPPING "/change_while_connected"

/** Network type to module name mapping GConf path name; g_free when done */
#define ICD_GCONF_NETWORK_TYPE_PATH(NETWORK_TYPE) \
        g_strconcat (ICD_GCONF_NETWORK_MAPPING, \
                    "/", \
                    (NETWORK_TYPE), \
                    "/network_modules", \
                    NULL);

/** Network idle timeout in seconds for a specific network type; g_free when
 * done */
#define ICD_GCONF_NETWORK_IDLE_TIMEOUT(NETWORK_TYPE) \
        g_strconcat (ICD_GCONF_NETWORK_MAPPING, \
                    "/", \
                    (NETWORK_TYPE), \
                    "/idle_timeout", \
                    NULL);

/** Service provider path */
#define ICD_GCONF_SRV_PROVIDERS         ICD_GCONF_SETTINGS "/srv_provider"

#ifdef __cplusplus
}
#endif

#endif /* OSSO_IC_GCONF_H */

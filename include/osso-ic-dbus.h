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
 * @author Timo Teräs <timo.teras@nokia.com>
 * @author Patrik Flykt <patrik.flykt@nokia.com>
 */

#ifndef OSSO_IC_DBUS_H
#define OSSO_IC_DBUS_H

#ifdef __cplusplus
extern "C" {
#endif

/* D-BUS stuff related to ICd */
#define ICD_DBUS_SERVICE		"com.nokia.icd"

#define ICD_DBUS_INTERFACE		"com.nokia.icd"
#define ICD_DBUS_PATH			"/com/nokia/icd"

/** Connect request from connectivity libraries
 * Arguments:
 * DBUS_TYPE_STRING     name of the (meta)IAP to activate
 * DBUS_TYPE_UINT       connection flags
 *
 * Returns:
 * D-Bus error or method call return with arguments:
 * DBUS_TYPE_STRING     name of the IAP that was activated
 */
#define ICD_CONNECT_REQ			"connect"

/** Disconnect request from connectivity libraries
 * Arguments:
 * DBUS_TYPE_STRING     name of the IAP to deactivate
 *
 * Returns:
 * D-Bus error or method call return with arguments:
 * DBUS_TYPE_STRING     name of the IAP that was deactivated
 */
#define ICD_DISCONNECT_REQ		"disconnect"

/** Connect request from the connectivity UI
 * Arguments:
 * DBUS_TYPE_STRING     name of the real IAP to activate
 */
#define ICD_ACTIVATE_REQ		"activate"

/** Request to disconnect the last connection from connectivity UI.
 * No arguments
 */
#define ICD_SHUTDOWN_REQ		"shutdown"

#define ICD_GET_STATE_REQ		"get_state"
#define ICD_GET_STATISTICS_REQ		"get_statistics"
#define ICD_GET_IPINFO_REQ		"get_ipinfo"

/** IAP status signal
 * Arguments:
 * DBUS_TYPE_STRING     name of the IAP whose status changed or "[SCAN]" for
 *                      network scanning related events
 * DBUS_TYPE_STRING     IAP or scanned network type
 * DBUS_TYPE_STRING     state
 * DBUS_TYPE_STRING     error code or empty string on disconnect
 */
#define ICD_STATUS_CHANGED_SIG		"status_changed"

/** DHCP and PPP address configuration signal interface */
#define ICD_DBUS_AUTOCONF_INTERFACE	"com.nokia.icd.autoconf"
/** DHCP and PPP address configuration signal path */
#define ICD_DBUS_AUTOCONF_PATH		"/com/nokia/icd/autoconf"

/** DHCP and PPP address configuration signal
 * Arguments:
 * DBUS_TYPE_STRING     interface name
 * DBUS_TYPE_STRING     sending application, i.e. "DHCP", "LINKLOCAL" or "PPP"
 * DBUS_TYPE_STRING     "CONNECTED" or "DISCONNECTED"
 */
#define ICD_AUTOCONF_CHANGED_SIG	"autoconf_changed"

/** Error internal to ICd or its modules, e.g. could not allocate memory, start
 * processes, NULL state in callbacks, etc. */
#define ICD_DBUS_ERROR_SYSTEM_ERROR	"com.nokia.icd.error.system_error"

/** No connection to the BT DUN device */
#define ICD_DBUS_ERROR_GATEWAY_ERROR	"com.nokia.icd.error.gateway_error"

/** PPP authentication failed */
#define ICD_DBUS_ERROR_PPP_AUTH_FAILED	"com.nokia.icd.error.ppp_authentication_failed"

/** WLAN authentication failed */
#define ICD_DBUS_ERROR_WLAN_AUTH_FAILED	"com.nokia.icd.error.wlan_authentication_failed"
/** WLAN WPA PSK authentication failed */
#define ICD_DBUS_ERROR_WLAN_WPA_PSK_AUTH_FAILED	\
                                        "com.nokia.icd.error.wlan_wpa_psk_authentication_failed"

/** No response from the DHCP server */
#define ICD_DBUS_ERROR_SERVER_ERROR	"com.nokia.icd.error.server_error"
/** No response from the BT DUN PPP server */
#define ICD_DBUS_ERROR_PPP_SERVER_ERROR	"com.nokia.icd.error.ppp_server_error"

/** No network signal, could not connect to access point, wrong dial-up number,
 * etc; i.e. link layer network problems */
#define ICD_DBUS_ERROR_NETWORK_ERROR	"com.nokia.icd.error.network_error"

/** IP address could not be configured via DHCP */
#define ICD_DBUS_ERROR_DHCP_FAILED      "com.nokia.icd.error.dhcp_failed"
/** IP address could not be configured via DHCP in a WLAN network with WEP
 * encryption */
#define ICD_DBUS_ERROR_DHCP_WEP_FAILED  "com.nokia.icd.error.dhcp_with_wep_failed"

#define ICD_DBUS_ERROR_WPA2_NOT_SUPPORTED "com.nokia.icd.error.wpa2_not_supported"
#define ICD_DBUS_ERROR_SAP_NOT_SUPPORTED  "com.nokia.icd.error.sap_not_supported"
#define ICD_DBUS_ERROR_SAP_CONNECT_FAILED "com.nokia.icd.error.sap_connect_failed"
#define ICD_DBUS_ERROR_SAP_NO_PHONE	"com.nokia.icd.error.sap_no_phone"
#define ICD_DBUS_ERROR_FLIGHT_MODE	"com.nokia.icd.error.flight_mode"

/** Connection does not exist when connecting or disconnecting */
#define ICD_DBUS_ERROR_INVALID_IAP	"com.nokia.icd.error.invalid_iap"

#define ICD_DBUS_ERROR_IAP_IN_USE	"com.nokia.icd.error.iap_in_use"

/** Connection request refused since no requested networks were available, no
 * connection available for IP info or statistics query */
#define ICD_DBUS_ERROR_IAP_NOT_AVAILABLE \
					"com.nokia.icd.error.iap_not_available"

/* D-BUS stuff related to GW HW detection */
#define GWHWD_DBUS_SERVICE		"com.nokia.gwhw_detect"

#define GWHWD_DBUS_INTERFACE		"com.nokia.gwhw_detect"
#define GWHWD_DBUS_PATH			"/com/nokia/gwhw_detect"

#define GWHWD_DETECT_REQ		"detect"

#define GWHWD_DBUS_ERROR		"com.nokia.gwhw_detect.error"

#ifdef __cplusplus
}
#endif


#endif

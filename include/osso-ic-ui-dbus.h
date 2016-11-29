/**
 * This file is part of icd2-osso-ic-dev
 *
 * Copyright (C) 2004-2006 Nokia Corporation. All rights reserved.
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
 * @author Aapo Mäkela <aapo.makela@nokia.com>
 */

#ifndef OSSO_ICD_UI_DBUS_H
#define OSSO_ICD_UI_DBUS_H

#ifdef __cplusplus
extern "C" {
#endif

#define ICD_UI_DBUS_SERVICE		"com.nokia.icd_ui"

#define ICD_UI_DBUS_INTERFACE		"com.nokia.icd_ui"
#define ICD_UI_DBUS_PATH		"/com/nokia/icd_ui"

/** Show connection dialog.
 * Arguments:
 * DBUS_TYPE_BOOLEAN	TRUE if CON-INF047 should be shown too
 *			("Saved connections not found")
 */
#define ICD_UI_SHOW_CONNDLG_REQ		"show_conn_dlg"

/** Error returned by show_conn_dlg in flight mode. */
#define ICD_UI_DBUS_ERROR_FLIGHT_MODE	"com.nokia.icd_ui.error.flight_mode"

/** Show disconnect dialog. No arguments. */
#define ICD_UI_SHOW_DISCONNDLG_REQ	"show_disconnect_dlg"

/** Show save connection as dialog.
 * Arguments:
 * DBUS_TYPE_STRING     name of the current IAP
 */
#define ICD_UI_SHOW_SAVEDLG_REQ         "show_save_dlg"

/** Show retry dialog.
 * Arguments:
 * DBUS_TYPE_STRING	name of the IAP to retry
 * DBUS_TYPE_STRING	name of the error why connection attempt failed
 */
#define ICD_UI_SHOW_RETRY_REQ		"show_retry_dlg"

/** Show change IAP dialog.
 * Arguments:
 * DBUS_TYPE_STRING	name of the currently active IAP
 * DBUS_TYPE_STRING	name of the IAP to be activated
 */
#define ICD_UI_SHOW_CHANGE_REQ		"show_change_dlg"

/** Show username/password dialog
* Arguments:
* DBUS_TYPE_STRING	supplied username or "" if unknown
* DBUS_TYPE_STRING	supplied password or "" if unknown
* DBUS_TYPE_STRING	name of the IAP related to the dialog
*/
#define ICD_UI_SHOW_PASSWD_REQ		"show_passwd_dlg"

/** Show EAP GTC challenge dialog
* Arguments:
* DBUS_TYPE_STRING	challenge string to show
*/
#define ICD_UI_SHOW_GTC_REQ	        "show_gtc_dlg"

/** Show EAP MSCHAPv2 change password dialog
* Arguments:
* DBUS_TYPE_STRING	supplied username
* DBUS_TYPE_STRING      old password that is to be changed
* DBUS_TYPE_STRING	the name of the internet connection this request
*                       relates to
*/
#define ICD_UI_MSCHAP_CHANGE_REQ	"show_mschap_change_dlg"

/** Show EAP private key password dialog
* Arguments:
* DBUS_TYPE_UINT32	the private key id
*/
#define ICD_UI_SHOW_PRIVATE_KEY_PASSWD_REQ "show_private_key_passwd_dlg"

/** Show server certificate error and expiration dialogs. If both boolean
* arguments are false, the error dialog is shown. If either or both boolean
* arguments are TRUE, the expiration dialog is shown instead.
* Arguments:
* DBUS_TYPE_STRING	certificate name
* DBUS_TYPE_STRING	certificate serial
* DBUS_TYPE_BOOLEAN	TRUE if certificate is expired, FALSE otherwise
* DBUS_TYPE_BOOLEAN	TRUE if root CA is unknown or self-signed certificate,
*                       FALSE otherwise
*/
#define ICD_UI_SHOW_SERVER_CERT_REQ "show_server_cert_dlg"

/** Request strong (16 digit) BT PIN dialog for a BT device
* Arguments:
* DBUS_TYPE_STRING	BDA of the device to pair with
* DBUS_TYPE_BOOLEAN	TRUE if strong authentication enabled,
*			FALSE if strong authentication is disabled
*/
#define ICD_UI_STRONG_BT_REQ		"strong_bt_req"

/** Show SIM PIN dialog
* Arguments:
* DBUS_TYPE_STRING	BDA of the device used with SAP
* DBUS_TYPE_BOOLEAN	TRUE if PIN was incorrect and retry dialog
*                       should be displayed before asking PIN.
*                       FALSE if this is the first PIN request.
*/
#define ICD_UI_SHOW_SIM_PIN_REQ		"show_sim_pin_dlg"

/** Signal emitted from UI when disconnect dialog has been closed.
 * Arguments:
 * DBUS_TYPE_BOOLEAN	TRUE if "disconnect" pressed, FALSE if "cancel"
 */
#define ICD_UI_DISCONNECT_SIG		"disconnect"

/** Signal emitted from UI when save as dialog has been closed.
 * Arguments:
 * DBUS_TYPE_STRING     Current name of the IAP
 * DBUS_TYPE_STRING     Saved name of the IAP. Empty, if not saved.
 */
#define ICD_UI_SAVE_SIG                 "save"

/** Signal emitted from UI when retry dialog has been closed.
 * Arguments:
 * DBUS_TYPE_STRING	name of the IAP related to dialog
 * DBUS_TYPE_BOOLEAN	TRUE if "retry" pressed, FALSE if "cancel"
 * DBUS_TYPE_BOOLEAN    TRUE if the IAP in the first argument is to be retried,
 *                      FALSE if the default retry mechanism is used. This
 *                      argument is optional and defaults to FALSE. Don't use
 *                      this argument unless you know what you are doing.
 */
#define ICD_UI_RETRY_SIG		"retry"

/** Signal emitted from UI when change connection dialog has been closed.
 * Arguments:
 * DBUS_TYPE_STRING	name of the "old" IAP related to dialog
 * DBUS_TYPE_STRING	name of the "new" IAP related to dialog
 * DBUS_TYPE_BOOLEAN	TRUE if "change" pressed, FALSE if "cancel"
 */
#define ICD_UI_CHANGE_SIG		"change"

/** Signal emitted from UI when the username/password dialog has been
 *  closed.
 * Arguments:
 * DBUS_TYPE_STRING	usename supplied or modified by the user
 * DBUS_TYPE_STRING	password supplied or modified by the user
 * DBUS_TYPE_STRING	name of the IAP related to the dialog
 * DBUS_TYPE_BOOLEAN	TRUE if "ok" pressed, FALSE if "cancel"
 */
#define ICD_UI_PASSWD_SIG		"passwd"

/** Signal emitted from UI when the EAP GTC challenge dialog has been closed.
 * Arguments:
 * DBUS_TYPE_STRING	response to the given challenge or "" if usr cancelled
 * DBUS_TYPE_BOOLEAN	TRUE if "ok" pressed, FALSE if "cancel"
 */
#define ICD_UI_GTC_RESPONSE_SIG		"gtc_response"

/** Signal emitted from UI when the MSCHAPv2 password has been changed
 * Arguments:
 * DBUS_TYPE_STRING	supplied username
 * DBUS_TYPE_STRING     the new password or "" if user cancelled
 * DBUS_TYPE_STRING	the name of the internet connection this request
 *                       relates to
 * DBUS_TYPE_BOOLEAN	TRUE if "ok" pressed, FALSE if "cancel"
 */
#define ICD_UI_MSCHAP_CHANGE_SIG	"mschap_change"

/** Signal emitted from UI when the private key password dialog has been
 * closed.
 * Arguments:
 * DBUS_TYPE_UINT32     the id of the private key
 * DBUS_TYPE_STRING	password for the private key or "" if none
 * DBUS_TYPE_BOOLEAN	TRUE if "ok" pressed, FALSE if "cancel"
 */
#define ICD_UI_PRIVATE_KEY_PASSWD_SIG	"private_key_passwd"

/** Signal emitted from UI when the server certificate error dialog has been
 * closed.
 * Arguments:
 * DBUS_TYPE_BOOLEAN	TRUE if certificate accepted, FALSE if rejected
 */
#define ICD_UI_SERVER_CERT_SIG	"server_cert"

/** Signal emitted from UI when the strong (16 digit) BT PIN has been entered
* Arguments:
* DBUS_TYPE_BOOLEAN	TRUE if strong PIN entered, FALSE if strong PIN dialog
*                       is cancelled
*/
#define ICD_UI_STRONG_BT_SIG		"strong_bt"

/** Signal emitted from UI when the SIM PIN has been entered.
 * Arguments:
 * DBUS_TYPE_STRING	SIM PIN code or "" if user canceled
 * DBUS_TYPE_BOOLEAN    TRUE if "ok" pressed, FALSE if "cancel"
 */
#define ICD_UI_SIM_PIN_SIG		"sim_pin"

#ifdef __cplusplus
}
#endif


#endif

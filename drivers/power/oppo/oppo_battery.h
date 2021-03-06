/*******************************************************************************
* Copyright (c)  2014- 2014  Guangdong OPPO Mobile Telecommunications Corp., Ltd
* VENDOR_EDIT
* Description: Source file for CBufferList.
*           To allocate and free memory block safely.
* Version   : 0.0
* Date      : 2014-07-30
* Author    : Lijiada @Bsp.charge
* ---------------------------------- Revision History: -------------------------
* <version>           <date>          < author >              <desc>
* Revision 0.0        2014-07-30      Lijiada @Bsp.charge
* Modified to be suitable to the new coding rules in all functions.
*******************************************************************************/

#ifndef _OPPO_BATTERY_H_
#define _OPPO_BATTERY_H_

#ifdef OPPO_BATTERY_PAR
#define OPPO_BATTERY_EXT
#else
#define OPPO_BATTERY_EXT extern
#endif

#define HYS_NONE										0
#define HYSTERISIS_DECIDEGC                     		20
#define LCD_ON_CHARGING_INPUT_CURRENT					1200
#define LCD_OFF_CHARGING_INPUT_CURRENT					1500
#define LCD_ON_CHARGING_FAST_CURRENT						1000
#define LCD_OFF_CHARGING_FAST_CURRENT					1500

#define CAMERA_ON_CHARGING_INPUT_CURRENT					1000
#define CAMERA_OFF_CHARGING_INPUT_CURRENT					1500
#define CAMERA_ON_CHARGING_FAST_CURRENT					600
#define CAMERA_OFF_CHARGING_FAST_CURRENT					1500

#define CMCC_CHARGER_FULL_4250MV						4240000
#define CMCC_CHARGER_FULL_4208MV						4208000
#define CMCC_FULL_CHARGING_INPUT_CURRENT					150
#define CMCC_CHARGING_INPUT_CURRENT						1500

#ifdef OPPO_BATTERY_PAR
struct opchg_charger *chip_opchg = NULL;
#else
extern struct opchg_charger *chip_opchg;
#endif

OPPO_BATTERY_EXT int oppo_power_type;

OPPO_BATTERY_EXT int opchg_inout_charge_parameters(struct opchg_charger *chip);
OPPO_BATTERY_EXT int opchg_init_charge_parameters(struct opchg_charger *chip);
#ifdef OPPO_USE_ADC_TM_IRQ
OPPO_BATTERY_EXT void opchg_get_adc_notification(enum qpnp_tm_state state, void *ctx);
#else
OPPO_BATTERY_EXT void opchg_get_adc_notification(struct opchg_charger *chip);
#endif
OPPO_BATTERY_EXT void opchg_get_charger_ov_status(struct opchg_charger *chip);
OPPO_BATTERY_EXT void opchg_config_reset_charger(struct opchg_charger *chip, int reason, int reset);
OPPO_BATTERY_EXT void opchg_config_input_chg_current(struct opchg_charger *chip, int reason, int mA);
OPPO_BATTERY_EXT void opchg_config_over_time(struct opchg_charger *chip, int mA);
OPPO_BATTERY_EXT void opchg_config_fast_current(struct opchg_charger *chip, int reason, int mA);
OPPO_BATTERY_EXT void opchg_config_term_voltage(struct opchg_charger *chip, int reason, int mV);
OPPO_BATTERY_EXT void opchg_config_term_current(struct opchg_charger *chip, int reason, int mA);
OPPO_BATTERY_EXT void opchg_config_charging_disable(struct opchg_charger *chip, int reason, int disable);
OPPO_BATTERY_EXT void opchg_config_suspend_enable(struct opchg_charger *chip, int reason, bool suspend);
OPPO_BATTERY_EXT void opchg_config_charging_phase(struct opchg_charger *chip,int phase);
#ifdef OPPO_USE_2CHARGER
OPPO_BATTERY_EXT void opchg_get_prop_fastcharger_status(struct opchg_charger *chip);
#endif
OPPO_BATTERY_EXT void opchg_check_status(struct opchg_charger *chip);
OPPO_BATTERY_EXT void opchg_set_status(struct opchg_charger *chip);
OPPO_BATTERY_EXT void opchg_update_thread(struct work_struct *work);
OPPO_BATTERY_EXT void opchg_delayed_wakeup_thread(struct work_struct *work);
OPPO_BATTERY_EXT void opchg_works_init(struct opchg_charger *chip);
OPPO_BATTERY_EXT int  opchg_battery_temp_region_get(struct opchg_charger *chip);

#endif /*_OPPO_BATTERY_H_*/

/* 
 * File:   esp32_snir.h
 * Author: pcruchet
 *
 * Created on 12 dÃ©cembre 2023, 09:35
 */

#ifndef ESP32_SNIR_H
#define ESP32_SNIR_H

#define BP1 39 // dÃ©finition des boutons-poussoirs
#define BP2 34
#define BP3 35

#define SW 23 // dÃ©finition de lâ€™interrupteur

#define LED 2 // dÃ©finition de la LED bleue sur le board ESP32
#define D1 13 // dÃ©finition de la LED rouge
#define D2 12 // dÃ©finition de la LED verte

#define ADD_OLED 0x3C // adresse de lâ€™afficheur OLED sur le bus I2C

#define DATALEDS 19 // dÃ©finition du GPIO pour la commande des LED RGB
#define NB_PIXELS 4 // nombre de pixels sur la carte.

#define ADC_LDR 36 // dÃ©finition du GPIO pour la conversion analogique numÃ©rique

#define RELAY_1 27 // dÃ©finition du GPIO pour le relais 1
#define RELAY_2 14 // dÃ©finition du GPIO pour le relais 2

#define TX_RS232 17 // dÃ©finition de la broche de transmission pour la RS232
#define RX_RS232 16 // dÃ©finition de la broche de rÃ©ception pour la RS232

#define TEMP 18 // dÃ©finition du bus 1-wire pour le capteur de tempÃ©rature

#define PWM 2 // dÃ©finition du GPIO pour le servomoteur

#endif /* ESP32_SNIR_H */

//
// Created by Iscle Gil on 12/7/22.
//

#ifndef DANARS_COMMON_H
#define DANARS_COMMON_H

#include <stdint.h>

void Exec_Get_Enc_Packet_Passkey(uint8_t *buf, int len, const char *deviceName);
void Exec_Get_Enc_Packet_Password(uint8_t *buf, int len, const char *deviceName);
void Exec_Get_Enc_Packet_Time(uint8_t *buf, int len, const char *deviceName);
uint8_t Exec_Get_Enc_Passkey_SN(uint8_t param_1, const char *deviceName);
void Exec_Get_Enc_Packet_SN(uint8_t *buf, int len, const char *deviceName);

#endif //DANARS_COMMON_H

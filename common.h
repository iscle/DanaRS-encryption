#pragma once

#include <stdint.h>

void Exec_Get_Enc_Packet_Passkey(uint8_t *buf, int len, const char *deviceName);
void Exec_Get_Enc_Packet_Password(uint8_t *buf, int len, const char *deviceName);
void Exec_Get_Enc_Packet_SN(uint8_t *buf, int len, const char *deviceName);
void Exec_Get_Enc_Packet_Time(uint8_t *buf, int len, const char *deviceName);
uint8_t Exec_Get_Enc_Passkey_SN(uint8_t param_1, const char *deviceName);

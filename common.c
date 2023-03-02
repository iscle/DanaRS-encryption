#include "common.h"
#include <stddef.h>

void Exec_Get_Enc_Packet_Passkey(uint8_t *buf, int len, const char *deviceName) {
    if (deviceName == NULL) return;

    for (int i = 3; i < len - 2; i++) {
        buf[i] = buf[i] ^ deviceName[(i + 1) % 2];
    }
}

void Exec_Get_Enc_Packet_Password(uint8_t *buf, int len, const char *deviceName) {
    if (deviceName == NULL) return;

    for (int i = 3; i < len - 2; i++) {
        buf[i] = buf[i] ^ (deviceName[0] + deviceName[1]);
    }
}

void Exec_Get_Enc_Packet_SN(uint8_t *buf, int len, const char *deviceName) {
    if (deviceName == NULL) return;

    uint8_t tmp[3];
    tmp[0] = deviceName[0] + deviceName[1] + deviceName[2];
    tmp[1] = deviceName[3] + deviceName[4] + deviceName[5] + deviceName[6] + deviceName[7];
    tmp[2] = deviceName[8] + deviceName[9];

    for (int i = 3; i < len; i++) {
        buf[i] ^= tmp[i % 3];
    }
}

void Exec_Get_Enc_Packet_Time(uint8_t *buf, int len, const char *deviceName) {
    if (deviceName == NULL) return;

    uint8_t tmp = 0;
    for (int i = 0; i < 6; i++) {
        tmp = tmp + deviceName[i];
    }
    for (int i = 3; i < len - 2; i++) {
        buf[i] = buf[i] ^ tmp;
    }
}

uint8_t Exec_Get_Enc_Passkey_SN(uint8_t param_1, const char *deviceName) {
    if (deviceName == NULL) return param_1;

    uint8_t tmp = 0;
    for (int i = 0; i < 10; i++) {
        tmp = tmp + deviceName[i];
    }

    return param_1 ^ tmp;
}

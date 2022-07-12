#include "common.h"
#include <stddef.h>

void Exec_Get_Enc_Packet_Passkey(uint8_t *buf, int len, const char *deviceName) {
    int i;

    if (deviceName != NULL) {
        for (i = 3; i < len - 2; i++) {
            buf[i] = buf[i] ^ deviceName[i % 2];
        }
    }
}

void Exec_Get_Enc_Packet_Password(uint8_t *buf, int len, const char *deviceName) {
    int i;

    if (deviceName != NULL) {
        for (i = 3; i < len - 2; i++) {
            buf[i] = buf[i] ^ deviceName[1] + deviceName[0];
        }
    }
}

void Exec_Get_Enc_Packet_Time(uint8_t *buf, int len, const char *deviceName) {
    uint8_t tmp;
    int i;

    if (deviceName != NULL) {
        tmp = 0;
        for (i = 0; i < 6; i++) {
            tmp = tmp + deviceName[i];
        }
        for (i = 3; i < len - 2; i++) {
            buf[i] = buf[i] ^ tmp;
        }
    }
}

uint8_t Exec_Get_Enc_Passkey_SN(uint8_t param_1, const char *deviceName) {
    uint8_t tmp;
    int i;

    if (deviceName != NULL) {
        tmp = 0;
        for (i = 0; i < 10; i++) {
            tmp = tmp + deviceName[i];
        }
        param_1 = param_1 ^ tmp;
    }
    return param_1;
}

void Exec_Get_Enc_Packet_SN(uint8_t *buf, int len, const char *deviceName) {
    uint8_t tmp[3];
    int i;

    if (deviceName != NULL) {
        tmp[0] = deviceName[0] + deviceName[1] + deviceName[2];
        tmp[1] = deviceName[3] + deviceName[4] + deviceName[5] + deviceName[6] + deviceName[7];
        tmp[2] = deviceName[8] + deviceName[9];

        for (i = 3; i < len - 2; i++) {
            buf[i] = buf[i] ^ tmp[i % 3];
        }
    }
}
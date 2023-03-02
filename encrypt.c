#include "encrypt.h"
#include <string.h>
#include <sys/errno.h>
#include "crc.h"
#include "common.h"

extern int _unknown_global_1;

static char _device_name[11];

static void set_device_name(const char *device_name) {
    memcpy(_device_name, device_name, 10);
    _device_name[10] = '\0';
}

static int encrypt_0xF4(uint8_t *out_data, int out_data_len, uint8_t *in_data, int in_data_len,  const char *device_name) {

}

static int encrypt_0x01(uint8_t *out_data, int out_data_len, uint8_t *in_data, int in_data_len,  const char *device_name) {

}

static int encrypt_0xD0(uint8_t *out_data, int out_data_len, uint8_t *in_data, int in_data_len,  const char *device_name) {

}

static int encrypt_0xD1(uint8_t *out_data, int out_data_len, uint8_t *in_data, int in_data_len,  const char *device_name) {

}

static int encrypt_0xF3(uint8_t *out_data, int out_data_len, uint8_t *in_data, int in_data_len,  const char *device_name) {

}

static int encrypt_0x00(uint8_t *out_data, int out_data_len, uint8_t *in_data, int in_data_len,  const char *device_name) {
    _unknown_global_1 = 0;

    out_data[0] = 0xA5; // header 1
    out_data[1] = 0xA5; // header 2
    out_data[2] = 0x0C; // length
    out_data[3] = 0x01; // command?
    out_data[4] = 0x00; // unknown
    memcpy(out_data + 5, _device_name, 10); // device name
    uint16_t crc = generateCrc(out_data + 3, 12);
    out_data[15] = (crc >> 8) & 0xFF; // crc 1
    out_data[16] = (crc >> 0) & 0xFF; // crc 2
    out_data[17] = 0x5A; // footer 1
    out_data[18] = 0x5A; // footer 2

    Exec_Get_Enc_Packet_SN(out_data, 19, _device_name);

    return 0;
}

static int encrypt_default(uint8_t *out_data, int out_data_len, uint8_t *in_data, int in_data_len,  const char *device_name) {

}

int encryptPacket(uint8_t *out_data, int out_data_len, uint8_t opcode, uint8_t *in_data, int in_data_len, char *device_name) {
    int ret;

    set_device_name(device_name);

    switch (opcode) {
        case 0xF4: {
            ret = encrypt_0xF4(out_data, out_data_len, in_data, in_data_len, device_name);
            break;
        }
        case 0x01: {
            ret = encrypt_0x01(out_data, out_data_len,  in_data, in_data_len, device_name);
            break;
        }
        case 0xD0: {
            ret = encrypt_0xD0(out_data, out_data_len,  in_data, in_data_len, device_name);
            break;
        }
        case 0xD1: {
            ret = encrypt_0xD1(out_data, out_data_len,  in_data, in_data_len, device_name);
            break;
        }
        case 0xF3: {
            ret = encrypt_0xF3(out_data, out_data_len,  in_data, in_data_len, device_name);
            break;
        }
        case 0x00: {
            ret = encrypt_0x00(out_data, out_data_len,  in_data, in_data_len, device_name);
            break;
        }
        default: {
            ret = encrypt_default(out_data, out_data_len,  in_data, in_data_len, device_name);
            break;
        }
    }

    return ret;
}
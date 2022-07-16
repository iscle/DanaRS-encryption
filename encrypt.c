#include "encrypt.h"
#include <string.h>
#include <sys/errno.h>
#include "crc.h"
#include "common.h"

extern int _someGlobalVar;

static int encryptOpcode00(uint8_t *out_buf, int out_data_len, const char *device_name) {
    uint16_t crc;

    if (out_data_len < 19)
        return -EINVAL;

    _someGlobalVar = 0;

    out_buf[0] = 0xA5; // header 1
    out_buf[1] = 0xA5; // header 2
    out_buf[2] = 0x0C; // length
    out_buf[3] = 0x01; // command?
    out_buf[4] = 0x00; // unknown
    memcpy(&out_buf[5], device_name, 10); // device name
    crc = generateCrc(&out_buf[3], 12);
    out_buf[15] = (crc >> 8) & 0xFF; // crc 1
    out_buf[16] = (crc >> 0) & 0xFF; // crc 2
    out_buf[17] = 0x5A; // footer 1
    out_buf[18] = 0x5A; // footer 2

    Exec_Get_Enc_Packet_SN(out_buf, 19, device_name);

    return 0;
}

int encryptPacket(uint8_t *out_data, int out_data_len, uint8_t opcode, uint8_t *in_data, int in_data_len, char *device_name) {
    int ret;

    switch (opcode) {
        case 0x00:
            ret = encryptOpcode00(out_data, out_data_len, device_name);
            break;
    }

    return ret;
}
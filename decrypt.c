#include <sys/errno.h>
#include <string.h>
#include <printf.h>
#include <stdlib.h>
#include "decrypt.h"
#include "common.h"
#include "crc.h"

extern char _enhancedEncryption;
extern int _unknown_global_1;

int decrypt_packet(uint8_t *out_data, int out_data_len, const uint8_t *in_data, int in_data_len, const char *device_name) {
    // packet structure
    // header -> 2 bytes
    // length -> 1 byte
    // data -> length bytes
    // crc -> 2 bytes
    // footer -> 2 bytes

    uint8_t *tmp;
    uint16_t crc;

    tmp = malloc(in_data_len);
    if (tmp == NULL)
        return -ENOMEM;

    memcpy(tmp, in_data, in_data_len);

    Exec_Get_Enc_Packet_SN(tmp, in_data_len, device_name);
    if (_unknown_global_1 > 1 && _enhancedEncryption == 0) {
        printf("Not implemented yet: Decryption by time, password and passkey\n");
        // TODO: Replace parameter deviceName with the correct values
        Exec_Get_Enc_Packet_Time(tmp, in_data_len, device_name);
        Exec_Get_Enc_Packet_Password(tmp, in_data_len, device_name);
        Exec_Get_Enc_Packet_Passkey(tmp, in_data_len, device_name);
    }

    if (tmp[2] != in_data_len - 7) {
        free(tmp);
        tmp = NULL;
        return -EINVAL;
    }

    crc = generateCrc(&tmp[3], tmp[2]);
    if (((crc >> 8) & 0xFF) != tmp[in_data_len - 4] || (crc & 0xFF) != tmp[in_data_len - 3]) {
        printf("Invalid crc! got=0x%04X, expected=0x%04X", crc, tmp[in_data_len - 4] << 8 & tmp[in_data_len - 3]);
        free(tmp);
        tmp = NULL;
        return -EINVAL;
    }

    if (out_data_len < tmp[2]) {
        free(tmp);
        tmp = NULL;
        return -EINVAL;
    }

    memcpy(out_data, &tmp[3], tmp[2]);

    if (out_data[0] == 0x02) { // ENCRYPTION_RESPONSE?
        printf("Not implemented yet: handle ENCRYPTION_RESPONSE\n");
    }

    free(tmp);
    tmp = NULL;

    return 0;
}

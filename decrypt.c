//
// Created by Iscle Gil on 12/7/22.
//

#include <sys/errno.h>
#include <string.h>
#include "decrypt.h"
#include "common.h"

extern char _enhancedEncryption;
extern char *_deviceName;
extern int _someGlobalVar;

int decrypt_packet(uint8_t *out_data, int out_data_len, const uint8_t *in_data, int in_data_len) {
    if (out_data_len < in_data_len)
        return -EINVAL;

    memcpy(out_data, in_data, in_data_len);

    Exec_Get_Enc_Packet_SN(out_data, in_data_len, _deviceName);

    if (_someGlobalVar != 0 && _someGlobalVar != 1 && _enhancedEncryption == 0) {
        Exec_Get_Enc_Packet_Time(out_data, in_data_len, _deviceName);
        Exec_Get_Enc_Packet_Password(out_data, in_data_len, _deviceName);
        Exec_Get_Enc_Packet_Passkey(out_data, in_data_len, _deviceName);
    }

    if (out_data[2] != in_data_len - 7) {
        return -EINVAL;
    }

    return 0;
}

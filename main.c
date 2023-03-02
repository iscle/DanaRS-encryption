#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "encrypt.h"
#include "decrypt.h"

char _enhancedEncryption;
int _someGlobalVar;

static int8_t signed_opcode = 0;
static int8_t signed_input_data[] = {
        -91, -91, 4, -21, -6, -57, -94, 63, 126, 90, 90
};
static uint8_t signed_input_data_len = sizeof(signed_input_data);
static int8_t signed_output_data[] = {
        2, 0, 79, 75
};
static uint8_t signed_output_data_len = sizeof(signed_output_data);

int main() {
    printf("DanaRS decryptor by Iscle!\n");

    char *device_name = "TKJ00172FB";
    uint8_t opcode = (uint8_t) signed_opcode;
    uint8_t *input_data = (uint8_t *) signed_input_data;
    uint8_t input_data_len = signed_input_data_len;
    uint8_t *output_data = (uint8_t *) signed_output_data;
    uint8_t output_data_len = signed_output_data_len;

    uint8_t *out_data = malloc(output_data_len);

//    encryptPacket(out_data, output_data_len, opcode, input_data, input_data_len, device_name);
    decrypt_packet(out_data, output_data_len, input_data, input_data_len, device_name);

    printf("result: %d\n", memcmp(out_data, output_data, output_data_len));

    return 0;
}

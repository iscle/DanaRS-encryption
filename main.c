#include <stdio.h>
#include <stdint.h>
#include <string.h>

char _enhancedEncryption;
char _deviceName[11];
int _someGlobalVar;

static int8_t signed_opcode = 0;
static int8_t signed_input_data[] = {
    0x00
};
static size_t signed_input_data_len = sizeof(signed_input_data);
static int8_t signed_output_data[] = {
        -91, -91, 12, -24, -6, -36, -94, -80, -72, -39, -53, -65, -37, -68, -54, -106, -78, 90, 90
};
static size_t signed_output_data_len = sizeof(signed_output_data);

int main() {
    char *device_name = "TKJ00172FB";
    uint8_t opcode = (uint8_t) signed_opcode;
    uint8_t *input_data = (uint8_t *) signed_input_data;
    size_t input_data_len = signed_input_data_len;
    uint8_t *output_data = (uint8_t *) signed_output_data;
    size_t output_data_len = signed_output_data_len;

    printf("Hello, World!\n");



    return 0;
}

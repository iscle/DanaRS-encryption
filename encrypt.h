#pragma once

#include <stdint.h>

int encryptPacket(uint8_t *out_data, int out_data_len, uint8_t opcode, uint8_t *in_data, int in_data_len, char *device_name);

#pragma once

#include <stdint.h>

int decrypt_packet(uint8_t *out_data, int out_data_len, const uint8_t *in_data, int in_data_len, const char *device_name);

//
// Created by Iscle Gil on 12/7/22.
//

#ifndef DANARS_DECRYPT_H
#define DANARS_DECRYPT_H

#include <stdint.h>

int decrypt_packet(uint8_t *out_data, int out_data_len, const uint8_t *in_data, int in_data_len);

#endif //DANARS_DECRYPT_H

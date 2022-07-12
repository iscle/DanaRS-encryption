#include "crc.h"

uint16_t generateCrc(const uint8_t *buf, int len) {
    uint16_t crc;
    int i;

    crc = 0;
    for (i = 0; i < len; i++) {
        crc = buf[i] ^ (crc >> 8 | crc << 8);
        crc = crc ^ (crc >> 4 & 0x000F);
        crc = crc ^ crc << 12;
        crc = crc ^ (crc & 0xFF) << 3;
    }

    return crc;
}

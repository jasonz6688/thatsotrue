#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char** argv) {
  FILE* pcm_file = fopen("./thats-so-true.wav", "r");

  if (pcm_file == NULL) {
    // printf("FILE NOT OPENED");
    exit(1);
  }

  char riff[5];
  riff[4] = '\0';
  fread((void*) riff, sizeof(uint32_t), 1, pcm_file);
  // printf("RIFF: %s\n", riff);

  uint32_t file_size;
  fread((void*) &file_size, sizeof(uint32_t), 1, pcm_file);
  // printf("FILE SIZE: %d\n", file_size);

  char wave[5];
  wave[4] = '\0';
  fread((void*) wave, sizeof(uint32_t), 1, pcm_file);
  // printf("WAVE: %s\n", wave);

  char fmt[5];
  fmt[4] = '\0';
  fread((void*) fmt, sizeof(uint32_t), 1, pcm_file);
  // printf("fmt: %s\n", fmt);

  uint32_t length;
  fread((void*) &length, sizeof(uint32_t), 1, pcm_file);
  // printf("LENGTH OF FORMAT: %d\n", length);

  uint16_t type;
  fread((void*) &type, sizeof(uint16_t), 1, pcm_file);
  // printf("TYPE OF FORMAT: %d\n", type);

  uint16_t num_channels;
  fread((void*) &num_channels, sizeof(uint16_t), 1, pcm_file);
  // printf("NUMBER OF CHANNELS: %d\n", num_channels);

  uint32_t sample_rate;
  fread((void*) &sample_rate, sizeof(uint32_t), 1, pcm_file);
  // printf("SAMPLE RATE: %u\n", sample_rate);

  uint32_t byte_rate;
  fread((void*) &byte_rate, sizeof(uint32_t), 1, pcm_file);
  // printf("BYTE RATE: %u\n", byte_rate);

  fseek(pcm_file, 36, SEEK_SET);

  char data[5];
  int i = 0;
  while (i < 12) {
    fread((void*) data, sizeof(uint32_t), 1, pcm_file);
    data[4] = '\0';
    i++;
  }

  while (!feof(pcm_file)) {
    uint8_t d;
    fread((void*) &d, sizeof(uint8_t), 1, pcm_file);
    printf("%d, ", d);
  }

  fclose(pcm_file);

  return 0;
}

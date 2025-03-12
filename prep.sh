#!/bin/bash

# Compile PCM C Code
gcc pcm.c -o pcm

# Convert Audio
ffmpeg -i thats-so-true.mp4 -ar 8000 -ac 1 -acodec pcm_u8 thats-so-true.wav

# Use PCM to get raw data
./pcm | pbcopy

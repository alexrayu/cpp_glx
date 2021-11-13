#!/bin/bash

NAME='window'

gcc $NAME.cpp -lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl -o $NAME.elf

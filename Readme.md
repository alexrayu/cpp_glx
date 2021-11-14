## Learning Sources.
1. [OglDev](https://ogldev.org/).
2. [Open.Gl](https://open.gl/introduction).

## Installation.

1. Install the glx library.
`$ apt install g++ make freeglut3-dev libglew-dev libglew2.1 libmagick++-dev libassimp-dev libglfw3 libglfw3-dev libglm-dev`

## Compiling.
The included libraries need to be passed to the compiler as parameters.
`$ gcc my_app.cpp -lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl -o my_app.elf`

Minimum working librs that are required for `window.cpp` are `-lglfw -lGL`.

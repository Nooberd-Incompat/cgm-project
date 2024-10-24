# cgm-project

Made by ```Yojith Kaustabh S20220010201```
```Aditya Pande S20220010007```
```Amodini AP S20220010014```
```Sathyam A S20220010197```

In this game, we simulate an intergalactic space war, in which two species of aliens are having to battle each other to safeguard their respective planets. This is inspired by real life events.


To run the C code, you will need to follow similar steps, ensuring that you have the necessary OpenGL and GLUT libraries installed on your system. Here's how to compile and run the code on different platforms:
On Linux or macOS:

Compilation:

    gcc -o space_shooter main.c -lGL -lGLU -lglut

Running the compiled program:

    ./space_shooter

On Windows (using MinGW):

Compilation: If you are using MinGW on Windows, the command will be:

    gcc -o space_shooter space_shooter.c -lopengl32 -lglu32 -lfreeglut

Running the compiled program:

bash

    space_shooter.exe

Make sure:

Linux/macOS: You need to install OpenGL and GLUT libraries. For example, on Ubuntu, you can install them with:

    sudo apt-get install freeglut3-dev

Windows (MinGW): You need to have MinGW configured properly with OpenGL and GLUT libraries available.


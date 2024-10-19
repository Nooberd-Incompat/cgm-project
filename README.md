# cgm-project

To run the C code, you will need to follow similar steps, ensuring that you have the necessary OpenGL and GLUT libraries installed on your system. Here's how to compile and run the code on different platforms:
On Linux or macOS:

    Compilation:

    bash

gcc -o space_shooter space_shooter.c -lGL -lGLU -lglut

Running the compiled program:

bash

    ./space_shooter

On Windows (using MinGW):

    Compilation: If you are using MinGW on Windows, the command will be:

    bash

gcc -o space_shooter space_shooter.c -lopengl32 -lglu32 -lfreeglut

Running the compiled program:

bash

    space_shooter.exe

Make sure:

    Linux/macOS: You need to install OpenGL and GLUT libraries. For example, on Ubuntu, you can install them with:

    bash

    sudo apt-get install freeglut3-dev

    Windows (MinGW): You need to have MinGW configured properly with OpenGL and GLUT libraries available.


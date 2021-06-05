# CPP_Collection

Collection of C++ projects:

-----------------------------------------------------------------------------------------------------

# glfw-cpp-example-cube

Testing GLFW library and compiling for windows  [Linux & Windows]

-----------------------------------------------------------------------------------------------------

# glx-cpp-example-cube

Example OpenGL Project using OpenGL GLX drawing methods to render a spining cube. [Linux Only]

This project is about testing OpenGL compatibility on linux OSes and old GPUs. 
No external third party library is required since the project is using the X window system and by extension, GLX to create the OpenGL context.
The compiled binary(ies) could be found in the "builds" folder and it's sources could be found in the "src" one.
To Compile it manualy, it is entended to run the "compile.sh" bash script if g++ is installed.
The actual code found in "/src/screen.h" could be found at the following web address. Though, it has been slightly edited to ensure multiple script compatibility.

LINK: https://www.khronos.org/opengl/wiki/Tutorial:_OpenGL_3.0_Context_Creation_(GLX)

-----------------------------------------------------------------------------------------------------

# sdl-cpp-base-project

Base for all SDL projects (all libraries included) [Linux Only]

-----------------------------------------------------------------------------------------------------

# sfml-base-project

Base for all SFML projects (all libraries included) [Linux Only]

-----------------------------------------------------------------------------------------------------

# sfml-example-cube

Drawing a rotating Cube using sfml-base-project's setup (also including OpenGL and GLU in include/GL) [Linux Only]

-----------------------------------------------------------------------------------------------------

# sfml-example-console

Starting from sfml-example-cube and adding a developper console [Linux Only]

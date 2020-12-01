#ifndef _MAIN_H
#define _MAIN_H

// Cabeceras para apple
#ifdef __APPLE__
#include <GLUT/glut.h>
#endif

#ifdef _WIN32
#include <windows.h>        // Archivo de cabecera para Windows
#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>
//#include "GL\gl.h"                // Archivo de cabecera para la libreria OpenGL32
//#include "glu.h"            // Archivo de cabecera para la libreria GLu32
//#include "glaux.h"            // Archivo de cabecera para la libreria Glaux
#include "GL\glut.h"            // Archivo de cabecera para la libreria Glut
#endif

#include <math.h>			// Archivo de cabecera para Funciones Matem‡ticas
#include <stdio.h>			// Header File For Standard Input/Output
#include <stdlib.h>			// Header File For Standard Library

#include <string.h> // pulls in declaration for strlen.
#endif 

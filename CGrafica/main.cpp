/*
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>
#endif
*/
#include "Main.h"

//DEFINICION DE VARIABLES

//Posicion de la camara
float pos_camX = -1, pos_camY = 0, pos_camZ = -5;

//Movimiento del objeto: arrow_keys()
int eye_camX = 0, eye_camY = 0, eye_camZ = 0;

//Posicion de inicio de la camara
float posX = -10, posY = -10, posZ = -33;

float cameraPos[] = {0.0f, 0.0f, 0.0f};
float cameraFront[] = {0.0f, 0.0f, -10.0f};
float cameraUp[] = {0.0f, 1.0f, 0.0f};

//Propiedades de LUZ
GLfloat Diffuse[] = {0.5f, 0.5f, 0.5f, 1.0f}; // Luz ambiente de la fuente
GLfloat Specular[] = {1.0, 1.0, 1.0, 1.0}; // Luz especular
GLfloat Position[] = {0.0f, 3.0f, 0.0f, 1.0f}; // Posicion de la luz
GLfloat Position2[] = {0.0f, 0.0f, -5.0f, 1.0f};

void InitGL() // Inicializamos parametros
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Color de Fondo
    glEnable(GL_TEXTURE_2D);
    
    //glShadeModel (GL_SMOOTH);
    
    //Propiedades de Luz
    glLightfv(GL_LIGHT0, GL_POSITION, Position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
    glEnable(GL_LIGHTING); //Activar luces
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL); //Activar colores definidos al objeto
    
    glClearDepth(1.0f); // Configuramos Depth Buffer
    glEnable(GL_DEPTH_TEST); // Habilitamos Depth Testing
    glDepthFunc(GL_LEQUAL); // Tipo de Depth Testing a realizar
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
// Funcion de dibujo

void display(void) // Creamos la funcion donde se dibuja
{
    //Limpia buffer de profundidad
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    
    /*
    glTranslatef(posX, posY, posZ);
    //glTranslatef(pos_camX, pos_camY, pos_camZ);
    glRotatef(eye_camX, 1.0, 0.0, 0.0);
    glRotatef(eye_camY, 0.0, 1.0, 0.0);
    glRotatef(eye_camZ, 0.0, 0.0, 1.0);
    */
    
    gluLookAt(cameraPos[0] - posX, cameraPos[1] - posY, cameraPos[2] - posZ, cameraPos[0] + cameraFront[0], cameraPos[1] + cameraFront[1], cameraPos[2] + cameraFront[2], cameraUp[0], cameraUp[1], cameraUp[2]);
    //gluLookAt(cameraPos[0] - posX, cameraPos[1] - posY, cameraPos[2] - posZ, eye_camX, eye_camY, eye_camZ, cameraUp[0], cameraUp[1], cameraUp[2]);

    
    
    //Dibujamos ejes en el origen (0,0,0,)
    //Eje X
    glBegin(GL_LINES);
    glColor3f(0., 0., 1.);
    glVertex3f(0., 0., 0.);
    glVertex3f(30., 0., 0.);
    glEnd();
    
    //Eje Y
    glBegin(GL_LINES);
    glColor3f(0., 1., 0.);
    glVertex3f(0., 0., 0.);
    glVertex3f(0., 30., 0.);
    glEnd();
    
    //Eje Z
    glBegin(GL_LINES);
    glColor3f(1., 0., 0.);
    glVertex3f(0., 0., 0.);
    glVertex3f(0., 0., 30.);
    glEnd();
    
    //CUBO
    glPushMatrix();
    glColor3f(1., 2., 9.);
    glTranslated(0, 0, 0);
    //glutSolidCube(size)
    glutSolidCube(7);
    glutWireCube(10);
    glPopMatrix();
    
    //ESFERA
    glPushMatrix();
    glColor3f(2., 2., 1.);
    glTranslated(0, 20, 0);
    //glutSolidSphere(radius, slices, stacks)
    glutSolidSphere(7, 20, 20);
    glutWireSphere(10, 30, 30);
    glPopMatrix();
    
    //CONO
    glPushMatrix();
    glColor3f(2., 1., 9.);
    glTranslated(20, 0, 0);
    glRotatef(-90, 1, 0, 0);
    //glutSolidCone(base, height, slices, stacks)
    glutSolidCone(7, 15, 30, 20);
    glutWireCone(10, 20, 30, 20);
    glPopMatrix();
    
    glutSwapBuffers();
}
// Funcion de cambio de tama√±o

void reshape(int width, int height) {
    if (height == 0) // Previniendo division entre cero
    {
        height = 1;
    }
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION); // Seleccionamos Projection Matrix

    glLoadIdentity();
    
    // Perspectiva: glFrustum(left, right, bottom, top, near, far)
    //glFrustum(-1, 1, -1, 1, 1, 200.0);
    glFrustum(-ar, ar, -1, 1, 1, 200.0);
    //glOrtho(-50, 50, -50, 50, -50, 50);
    glMatrixMode(GL_MODELVIEW); // Seleccionamos Modelview Matrix
    glLoadIdentity();
}

//POSICION DE LA CAMARA keyboard()
//ZOOM: Lejos-Cerca TECLAS: W Y S
//MOVIMIENTO: izquierda-derecha TECLAS: A Y D

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': //Movimientos de camara
        case 'W':
            posZ += 0.5f;
            break;
            
        case 's':
        case 'S':
            posZ -= 0.5f;
            break;
            
        case 'a':
        case 'A':
            posX += 0.5f;
            break;
            
        case 'd':
        case 'D':
            posX -= 0.5f;
            break;
            
        case 27:
            exit(0);
            break;
            
        default:
            break;
    }
    glutPostRedisplay(); //Indica a OpenGL Redibujar
}

// Aqui ponemos lo que queremos dibujar.
void display2(void)
{
    // Propiedades del material
    GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat mat_shininess[] = { 100.0f };
    
    // "Limpiamos" el frame buffer con el color de "Clear", en este
    // caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
    
    glTranslatef(0.0,0.0,-20.0);
    // Rotacion de 30 grados en torno al eje x
    glRotated(30.0, 1.0, 0.0, 0.0);
    // Rotacion de -30 grados en torno al eje y
    //glRotated(-30.0, 0.0, 1.0, 0.0);
    glRotated(-30, 0.0, 1.0, 0.0);
    // Dibujamos una "Tetera" y le aplico el material
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glutSolidTeapot(7.0);
    //glutWireCube(2.0f);
    
    //glFlush();
    glutSwapBuffers ( );
    return;
}

void arrow_keys(int a_keys, int x, int y) // Funcion para manejo de teclas especiales (arrow keys)
{
    switch (a_keys) {
        case GLUT_KEY_PAGE_UP:
            pos_camY -= 0.5f;
            break;
            
        case GLUT_KEY_PAGE_DOWN:
            pos_camY += 0.5f;
            break;
            
        case GLUT_KEY_UP: //Tecla arriba
            eye_camX = (eye_camX - 5) % 360;
            break;
            
        case GLUT_KEY_DOWN: //Tecla abajo
            eye_camX = (eye_camX + 5) % 360;
            break;
            
        case GLUT_KEY_LEFT: //Tecla izquierda
            eye_camY = (eye_camY - 5) % 360;
            break;
            
        case GLUT_KEY_RIGHT: //Tecla derecha
            eye_camY = (eye_camY + 5) % 360;
            break;
        default:
            break;
    }
    glutPostRedisplay(); //Indica a OpenGL Redibujar
}

//Funcion MAIN

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializamos OpenGL
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
    glutInitWindowSize(600, 600); // Tama√±o de la Ventana
    glutInitWindowPosition(0, 0); // Posicion de la Ventana
    glutCreateWindow("ESFERA, CONO, CUBO "); // Nombre de la Ventana
    //glutFullScreen     ( );                    // Pantalla completa
    InitGL(); // Parametros iniciales de la aplicaci√≥n
    glutDisplayFunc(display2); // Funcion de dibujo
    glutReshapeFunc(reshape); // Funcion en caso de cambio de tama√±o
    glutKeyboardFunc(keyboard); // Funcion de manejo de teclado
    glutSpecialFunc(arrow_keys); // Otras funciones
    glutMainLoop(); // Loop infinito, dibuja cuantas veces sea necesario
    return 0; // Necesario para ANSI C
}


//include GLUT
#include <GLUT/glut.h>

//set the macros for the window size
#define SIZEX 500
#define SIZEY 500

//initializing stuff
void init(void)
{
    glDisable( GL_DEPTH_TEST ); //triangles have two sides
    glDisable( GL_CULL_FACE ); //triangles have two sides
}

//Render one frame
void render(void)
{
    //Clear the window and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //Render the triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f ); //change vertex color
    glVertex2d( -0.5f, -0.5f );
    
    glColor3f(0.0f, 1.0f, 0.0f ); //change vertex color
    glVertex2d( 0.5f, -0.5f );
    
    glColor3f(0.0f, 0.0f, 1.0f ); //change vertex color
    glVertex2d( 0.0f, 0.5f );
    glEnd();
    
    //Swap front and back buffer
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    //init all OpenGL stuff
    glutInit(&argc,argv); //init GLUT
    //init framebuffer properties
    glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize(SIZEX, SIZEY); //init window dimensions
    glutCreateWindow("Test");  //create window
    
    //now that we have the window we can set the opengl state
    init();
    
    //set the callbacks
    glutDisplayFunc(render);  //render a frame
    glutIdleFunc(render);     //what to do when nothing happens
    
    //start the GLUT mainloop
    //(this function will be executed in a loop)
    glutMainLoop();
    
    return 0;
}

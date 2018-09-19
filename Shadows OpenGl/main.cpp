//
//  main.cpp
//  Shadows OpenGl
//
//  Created by Githinji Wanjohi on 9/19/18.
//  Copyright © 2018 Githinji Wanjohi. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <math.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble size=1.0;
void display(void);
void idle(void)
{
    display();
}
float lightx = 1.0,lighty = 1.0,lightroty = 1.0;
void myinit()
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y){
    if(key=='s'){
        lighty -= 0.1;
        //display();
    } else if(key == 'w'){
        lighty += 0.1;
        //display();
    } else if(key == 'a'){
         lightx -=0.1;
        //display();
    } else if(key == 'd'){
        lightx+=0.1;
        //display();
    }
    else if(key == 'c')
    {
        lightroty += 1;
    }
}

void specialKeys(int key, int x, int y){
    if( key == GLUT_KEY_UP){
        xRotated += 1;
    } else if( key == GLUT_KEY_LEFT){
        yRotated -= 1;
    } else if( key == GLUT_KEY_DOWN){
        xRotated -= 1;
    } else if( key == GLUT_KEY_RIGHT){
        yRotated += 1;
    }
}

void display(void)
{
    
    

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    
    glPushMatrix();
    glRotatef(lightroty, 1, 0, 0);
    glTranslatef(lightx, lighty, 1);
    GLfloat light_position[] = { lightx, lighty, 1.0, 0.0 };
    glutSolidSphere(0.1, 50, 50);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0,0.0,-5.0);
    // Red color used to draw.
    glColor3f(0.9, 0.3, 0.2);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a sphere.
    glutSolidCube(size);
    // Flush buffers to screen
    glPopMatrix();
    glFlush();
    // sawp buffers called because we are using double buffering
    // glutSwapBuffers();
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho (-1.5, 1.5, -1.5*(GLfloat)480/(GLfloat)640,
             1.5*(GLfloat)480/(GLfloat)640, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    //glViewport(0,0,w,h);  //Use the whole window for rendering
    glLoadIdentity();
}


int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize (640,480);
    glutInitWindowPosition (200,200);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
    xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50;
    glutCreateWindow("CUBE_LIGHT");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc (myReshape);
    myinit();
    glutIdleFunc(idle);
    glutMainLoop();
}

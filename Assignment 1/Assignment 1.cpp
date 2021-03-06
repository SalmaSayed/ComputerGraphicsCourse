// exerciseGraphics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
//VARIABLES
//Screen size
int screenx = 500;
int screeny = 500;

float step = 0.1f;      
float angle = 30.f;		 
float scale = 1.0f;
float x = 0.;
float y = 0.;
/********************************************************************************************/
//prototype
void initRendering();
void handleResize(int w, int h);
void handleKeypress(unsigned char key, int x, int y);
//void processSpecialKeys(int key, int mx, int my);
void drawTriangle();
void drawScene();
/*****************************************************************************************************/



int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(screenx, screeny);
	glutInitWindowPosition(0, 0);
	//Create the window
	glutCreateWindow(" Transformations ");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	//glutTimerFunc(25, update, 0); //Add a timer
	//glutSpecialFunc(processSpecialKeys);
	glutMainLoop();
	return 0;
}
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
		break;

	}
}

void drawTriangle() {
	glBegin(GL_TRIANGLES);
	glVertex3f(1.f, -1.f, -5.0f);
	glVertex3f(.5f, 1.f, -5.0f);
	glVertex3f(-1.f, -1.f, -5.0f);
	glEnd();
}

void drawDecta() {

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.75f, -0.5f, -15.0f);
	glVertex3f(0.0f, 0.0f, -15.0f);
	glVertex3f(2.0f, 0.0f, -15.0f);
	glVertex3f(1.25f, -0.5f, -15.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -15.0f);
	glVertex3f(-0.5f, 1.0f, -15.0f);
	glVertex3f(2.5f, 1.0f, -15.0f);
	glVertex3f(2.0f, 0.0f, -15.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 1.0f, -15.0f);
	glVertex3f(0.0f, 2.0f, -15.0f);
	glVertex3f(2.0f, 2.0f, -15.0f);
	glVertex3f(2.5f, 1.0f, -15.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, -15.0f);
	glVertex3f(0.75f, 2.5f, -15.0f);
	glVertex3f(1.25f, 2.5f, -15.0f);
	glVertex3f(2.0f, 2.0f, -15.0f);
	glEnd();
}


void drawOcta() {



	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -15.0f);
	glVertex3f(-0.5f, 1.0f, -15.0f);
	glVertex3f(2.5f, 1.0f, -15.0f);
	glVertex3f(2.0f, 0.0f, -15.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 1.0f, -15.0f);
	glVertex3f(-0.5f, 2.5f, -15.0f);
	glVertex3f(2.5f, 2.5f, -15.0f);
	glVertex3f(2.5f, 1.0f, -15.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 2.5f, -15.0f);
	glVertex3f(0.0f, 3.5f, -15.0f);
	glVertex3f(2.0f, 3.5f, -15.0f);
	glVertex3f(2.5f, 2.5f, -15.0f);
	glEnd();
}

void drawHebta() {

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.25f, 1.0f, -15.0f);
	glVertex3f(1.5f, 1.5f, -15.0f);
	glVertex3f(2.75f, 1.0f, -15.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -15.0f);
	glVertex3f(0.25f, 1.0f, -15.0f);
	glVertex3f(2.75f, 1.0f, -15.0f);
	glVertex3f(3.0f, 0.0f, -15.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -15.0f);
	glVertex3f(3.0f, 0.0f, -15.0f);
	glVertex3f(2.5f, -1.0f, -15.0f);
	glVertex3f(0.5f, -1.0f, -15.0f);
	glEnd();
}

void drawHexa() {

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -15.0f);
	glVertex3f(0.5f, 1.0f, -15.0f);
	glVertex3f(2.5f, 1.0f, -15.0f);
	glVertex3f(3.0f, 0.0f, -15.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -15.0f);
	glVertex3f(3.0f, 0.0f, -15.0f);
	glVertex3f(2.5f, -1.0f, -15.0f);
	glVertex3f(0.5f, -1.0f, -15.0f);
	glEnd();
}
void drawPenta() {

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -15.0f);
	glVertex3f(1.5f, 1.0f, -15.0f);
	glVertex3f(3.0f, 0.0f, -15.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -15.0f);
	glVertex3f(3.0f, 0.0f, -15.0f);
	glVertex3f(2.5f, -2.0f, -15.0f);
	glVertex3f(0.5f, -2.0f, -15.0f);
	glEnd();
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	/*******************************************************************************/

	glPushMatrix();
	glTranslatef(3.0,3.0,-10.0);
	drawPenta();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.0, 6.0, -10.0);
	drawHexa();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.0, 0.0, -10.0);
	drawHebta();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.0, -5.0, -10.0);
	drawOcta();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8.5, -6.0, -10.0);
	drawDecta();
	glPopMatrix();

	/********************************************************************************/
	glutSwapBuffers();
	glFlush();

}





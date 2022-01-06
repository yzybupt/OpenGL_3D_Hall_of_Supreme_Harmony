/**********************************************************************

  Forbidden City

  Dec, 4th, 2021

  This was the coursework submitted for EBU7405 3D Graphical Tools taught in the Joint Programme between Queen Mary University of London 
  & Beijing University of Posts and Telecommunications,2021-2022.The author was Yin Ziyuan enrolled in the JP.
  
  Contact:
	   yzy2018@bupt.edu.cn
    or:jp2018212840@qmul.ac.uk

  Every comment would be appreciated. Comments in the code were written in Chinese. 

  If you want to use parts of any code of mine:
	let me know and
	use it!
**********************************************************************
ESC: exit

CAMERA movement:
a : turn left
d : turn right
w : move up
s : move down

**********************************************************************/



#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <cstdlib>
#define PI 3.1415265359
GLdouble height = 0.5;
GLdouble theta = 0;
int status = -1;
double d = 21;
double zz = 0;
int NumOfEdges = 20;

void drawDiban1() {
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-157, -10, 0);
	glVertex3f(-160, -10, 0);
	glVertex3f(-160, -10, 90);
	glVertex3f(-157, -10, 90);
	glEnd();
	for (int i = 0; i < 14;i++) {
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex3f(-160,-10, 6 + i *6);
		glVertex3f(-157, -10, 6+ i * 6 );
		glEnd();
	}
}



void drawShibing() {
	glColor3f(0.8, 0.1647, 0.1647);
	for (int i = 0; i < 8; i++) {
		glPushMatrix();
		glTranslated(36, -11 + i, 60);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = 0; i < 8; i++) {
		glPushMatrix();
		glTranslated(34, -11 + i, 60);
		glutSolidCube(1);
		glPopMatrix();
	}

	glColor3f(1, 1, 0);
	for (int k = 0; k < 6; k++) {
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 4; i++) {
				glPushMatrix();
				glTranslated(33.5 + i * 1, -3 + k * 1, 60.5 - j * 1);
				glutSolidCube(1);
				glPopMatrix();
			}
		}
	}

	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslated(35, 2.5, 60);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(35, 3.5, 60);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(35, 5, 60);
	glutSolidCube(2);
	glPopMatrix();

	for (int i = 0; i < 5; i++) {
		glPushMatrix();
		glTranslated(37.5, 0 - i, 60);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = 0; i < 5; i++) {
		glPushMatrix();
		glTranslated(32.5, 0 - i, 60);
		glutSolidCube(1);
		glPopMatrix();
	}
}

void drawDiban2() {
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-154, -10, 0);
	glVertex3f(-157, -10, 0);
	glVertex3f(-157, -10, 90);
	glVertex3f(-154, -10, 90);
	glEnd();
	for (int i = 0; i < 14; i++) {
		glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex3f(-154, -10, 3 + i * 6);
		glVertex3f(-157, -10, 3 + i * 6);
		glEnd();
	}
}

void drawDamen() {
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-5, 18, -19);
	glVertex3f(-10, 18, -19);
	glVertex3f(-10, 8, -19);
	glVertex3f(-5, 8, -19);
	glEnd();


	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(10, 18, -19);
	glVertex3f(5, 18, -19);
	glVertex3f(5, 8, -19);
	glVertex3f(10, 8, -19);
	glEnd();


	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(5, 30, -19);
	glVertex3f(-5, 30, -19);
	glVertex3f(-5, 8, -19);
	glVertex3f(5, 8, -19);
	glEnd();


	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-5, 36, -19);
	glVertex3f(-10, 36, -19);
	glVertex3f(-10, 18, -19);
	glVertex3f(-5, 18, -19);
	glEnd();


	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(10, 36, -19);
	glVertex3f(5, 36, -19);
	glVertex3f(5, 18, -19);
	glVertex3f(10, 18, -19);
	glEnd();


	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(5, 36, -19);
	glVertex3f(-5, 36, -19);
	glVertex3f(-5, 30, -19);
	glVertex3f(5, 30, -19);
	glEnd();


	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(10, 38, -19);
	glVertex3f(-10, 38, -19);
	glVertex3f(-10, 36, -19);
	glVertex3f(10, 36, -19);
	glEnd();
}

void drawTower(float radius, int height, int xp, int zp, int yp) {
	float x, z;
	int i = 0;
	glBegin(GL_QUADS);
	for (i = 0; i < NumOfEdges - 1; i++)
	{
		x = xp + radius * cos((float)i / (float)NumOfEdges * PI * 2.0);
		z = zp + radius * sin((float)i / (float)NumOfEdges * PI * 2.0);
		glNormal3f(x, yp, z);
		glVertex3f(x, yp + height, z);
		glVertex3f(x, yp, z);

		x = xp + radius * cos((float)(i + 1) / (float)NumOfEdges * PI * 2.0);
		z = zp + radius * sin((float)(i + 1) / (float)NumOfEdges * PI * 2.0);
		glNormal3f(x, yp, z);
		glVertex3f(x, yp, z);
		glVertex3f(x, yp + height, z);
	}
	x = xp + radius * cos((float)i / (float)NumOfEdges * PI * 2.0);
	z = zp + radius * sin((float)i / (float)NumOfEdges * PI * 2.0);
	glNormal3f(x, yp, z);
	glVertex3f(x, yp + height, z);
	glVertex3f(x, yp, z);
	x = xp + radius * cos(1.0 / (float)NumOfEdges * PI * 2.0);
	z = zp + radius * sin(1.0 / (float)NumOfEdges * PI * 2.0);
	glNormal3f(x, yp, z);
	glVertex3f(x, yp, z);
	glVertex3f(x, yp + height, z);
	glEnd();


}

void drawFenceWall(int x, int y,int z, int number) {
	
	for (int i = 0; i < number; i++) {
		glPushMatrix();
		glTranslated(x + i*1, y, z);
		glutSolidCube(1);
		glPopMatrix();
	}
}

void drawFenceWall2(int x, int y, int z, int number) {

	for (int i = 0; i < number; i++) {
		glPushMatrix();
		glTranslated(x , y, z - i*1);
		glutSolidCube(1);
		glPopMatrix();
	}
}

void drawStairs(int x, int y, int z) {
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidCube(3);
	glPopMatrix();
}

void drawHead(int x, int y, int z) {
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidCube(1);
	glPopMatrix();
}

void drawJizuoCube(int x, int y, int z) {
	glPushMatrix();
	glTranslated(x, y, z);
	glutSolidCube(9);
	glPopMatrix();

}

void drawJizuo(int z) {
	drawJizuoCube(0, 3, z);
	drawJizuoCube(-9, 3, z);
	drawJizuoCube(-18, 3, z);
	drawJizuoCube(-27, 3, z);
	drawJizuoCube(-36, 3, z);
	drawJizuoCube(-45, 3, z);
	drawJizuoCube(9, 3, z);
	drawJizuoCube(18, 3, z);
	drawJizuoCube(27, 3, z);
	drawJizuoCube(36, 3, z);
	drawJizuoCube(45, 3, z);
}



void drawJizuo2(int z) {
	glPushMatrix();
	glTranslated(0, z, 0);
	drawJizuo(-12);
	drawJizuo(-21);
	drawJizuo(-30);
	drawJizuo(-39);
	drawJizuo(-48);
	drawJizuo(-57);
	drawJizuo(-66);
	drawJizuo(-75);
	drawJizuo(-84);
	drawJizuo(-93);
	drawJizuo(-102);
	glPopMatrix();
}

void drawMache() {
	glColor3f(0.8, 0.1647, 0.1647);
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 8; i++) {
			drawStairs(120 - j * 3, 10, -100 + i * 3);
		}
	}
	glColor3f(0.8, 0.1647, 0.1647);
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 19; i++) {
			glPushMatrix();
			glTranslated(120, 10 + j * 1, -100 + i * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 19; i++) {
			glPushMatrix();
			glTranslated(111, 10 + j * 1, -100 + i * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			glPushMatrix();
			glTranslated(111 + i * 1, 10 + j * 1, -100);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			glPushMatrix();
			glTranslated(111 + i * 1, 10 + j * 1, -81);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	glColor3f(1, 1, 0);
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 10; i++) {
			drawStairs(120 - j * 3, 20, -100 + i * 3);
		}
	}

	glColor3f(1, 0, 0);
	for (int i = 0; i < 14; i++) {
		glPushMatrix();
		glTranslated(111, 10, -78 + i * 1);
		glutSolidCube(2);
		glPopMatrix();
	}
	for (int i = 0; i < 14; i++) {
		glPushMatrix();
		glTranslated(120, 10, -78 + i * 1);
		glutSolidCube(2);
		glPopMatrix();
	}

	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslated(122, 7, -92);
	glRotated(90, 0, 1, 0);
	glutSolidTorus(1, 5, 10, 10);
	glPopMatrix();

	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslated(109, 7, -92);
	glRotated(90, 0, 1, 0);
	glutSolidTorus(1, 5, 10, 10);
	glPopMatrix();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(121, 18, -95);
	glVertex3f(121, 18, -88);
	glVertex3f(121, 13, -88);
	glVertex3f(121, 13, -95);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(110, 18, -95);
	glVertex3f(110, 18, -88);
	glVertex3f(110, 13, -88);
	glVertex3f(110, 13, -95);
	glEnd();


}



void idle() {
	d = d + 2;
	if (d >= 45) {
		d = 24;
	}
	if (zz == 71 || zz == 0) {
		status = -status;
	}
	if (status == 1) {
		zz = zz + 1;
	}
	if (status == -1) {
		zz = zz - 1;
	}
	glutPostRedisplay();
}


void mySpecialkey(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) {
		theta = theta + 0.1;
	}
	else if (key == GLUT_KEY_RIGHT) {
		theta = theta - 0.1;
	}
}

void mykey(unsigned char key, int x, int y) {
	if (key == 'w' || key == 'W') {
		height= height+ 0.1;
	}
	else if (key == 's' || key == 'S') {
		height = height - 0.1;
	}
	else if (key == 'a' || key == 'A') {
		theta = theta + 0.1;
	}
	else if (key == 'd' || key == 'D') {
		theta = theta - 0.1;
	}
	else if (key == 27) {
		exit(0);
	}

}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cos(theta),height,sin(theta), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


	glColor3f(1.0, 1.0, 1.0);
	//开始画地板和台阶////////////////////////////////////////
	//一级台阶
	drawStairs(-9, 0, 0);
	drawStairs(-6, 0, 0);
	drawStairs(-3, 0, 0);
	drawStairs(0, 0, 0);
	drawStairs(3, 0, 0);
	drawStairs(6, 0, 0);
	drawStairs(9, 0, 0);

	
	//二级台阶
	drawStairs(-9, 0, -3);
	drawStairs(-6, 0, -3);
	drawStairs(-3, 0, -3);
	drawStairs(0, 0, -3);
	drawStairs(3, 0, -3);
	drawStairs(6, 0, -3);
	drawStairs(9, 0, -3);
	drawStairs(-9, 3, -3);
	drawStairs(-6, 3, -3);
	drawStairs(-3, 3, -3);
	drawStairs(0, 3, -3);
	drawStairs(3, 3, -3);
	drawStairs(6, 3, -3);
	drawStairs(9, 3, -3);

	//三级台阶
	drawStairs(-9, 0, -6);
	drawStairs(-6, 0, -6);
	drawStairs(-3, 0, -6);
	drawStairs(0, 0, -6);
	drawStairs(3, 0, -6);
	drawStairs(6, 0, -6);
	drawStairs(9, 0, -6);
	drawStairs(-9, 3, -6);
	drawStairs(-6, 3, -6);
	drawStairs(-3, 3, -6);
	drawStairs(0, 3, -6);
	drawStairs(3, 3, -6);
	drawStairs(6, 3, -6);
	drawStairs(9, 3, -6);
	drawStairs(-9, 6, -6);
	drawStairs(-6, 6, -6);
	drawStairs(-3, 6, -6);
	drawStairs(0, 6, -6);
	drawStairs(3, 6, -6);
	drawStairs(6, 6, -6);
	drawStairs(9, 6, -6);

	//第一层基座
	drawJizuo(-12);
	drawJizuo(-21);
	drawJizuo(-30);
	drawJizuo(-39);
	drawJizuo(-48);
	drawJizuo(-57);
	drawJizuo(-66);
	drawJizuo(-75);
	drawJizuo(-84);
	drawJizuo(-93);
	drawJizuo(-102);

	//第二层基座
	drawJizuo2(-9);
	drawJizuoCube(0, -6, -3);
	drawJizuoCube(-9, -6, -3);
	drawJizuoCube(-18, -6, -3);
	drawJizuoCube(-27, -6, -3);
	drawJizuoCube(-36, -6, -3);
	drawJizuoCube(-45, -6, -3);
	drawJizuoCube(-54, -6, -3);
	drawJizuoCube(-63, -6, -3);
	drawJizuoCube(9, -6, -3);
	drawJizuoCube(18, -6, -3);
	drawJizuoCube(27, -6, -3);
	drawJizuoCube(36, -6, -3);
	drawJizuoCube(45, -6, -3);
	drawJizuoCube(54, -6, -3);
	drawJizuoCube(63, -6, -3);
	drawJizuoCube(0, -6, 0);
	drawJizuoCube(-9, -6, 0);
	drawJizuoCube(-18, -6, 0);
	drawJizuoCube(-27, -6, 0);
	drawJizuoCube(-36, -6, 0);
	drawJizuoCube(-45, -6, 0);
	drawJizuoCube(-54, -6, 0);
	drawJizuoCube(-63, -6, 0);
	drawJizuoCube(9, -6, 0);
	drawJizuoCube(18, -6, 0);
	drawJizuoCube(27, -6, 0);
	drawJizuoCube(36, -6, 0);
	drawJizuoCube(45, -6, 0);
	drawJizuoCube(54, -6, 0);
	drawJizuoCube(63, -6,0);
	drawJizuoCube(0, -6, 3);
	drawJizuoCube(-9, -6, 3);
	drawJizuoCube(-18, -6, 3);
	drawJizuoCube(-27, -6, 3);
	drawJizuoCube(-36, -6, 3);
	drawJizuoCube(-45, -6, 3);
	drawJizuoCube(-54, -6, 3);
	drawJizuoCube(-63, -6, 3);
	drawJizuoCube(9, -6, 3);
	drawJizuoCube(18, -6, 3);
	drawJizuoCube(27, -6, 3);
	drawJizuoCube(36, -6, 3);
	drawJizuoCube(45, -6, 3);
	drawJizuoCube(54, -6, 3);
	drawJizuoCube(63, -6, 3);
	drawJizuoCube(0, -6, 6);
	drawJizuoCube(-9, -6, 6);
	drawJizuoCube(-18, -6, 6);
	drawJizuoCube(-27, -6, 6);
	drawJizuoCube(-36, -6, 6);
	drawJizuoCube(-45, -6, 6);
	drawJizuoCube(-54, -6, 6);
	drawJizuoCube(-63, -6, 6);
	drawJizuoCube(9, -6, 6);
	drawJizuoCube(18, -6, 6);
	drawJizuoCube(27, -6, 6);
	drawJizuoCube(36, -6, 6);
	drawJizuoCube(45, -6, 6);
	drawJizuoCube(54, -6, 6);
	drawJizuoCube(63, -6, 6);
	drawJizuoCube(63, -6, -12);
	drawJizuoCube(54, -6, -12);
	drawJizuoCube(63, -6, -21);
	drawJizuoCube(54, -6, -21);
	drawJizuoCube(63, -6, -30);
	drawJizuoCube(54, -6, -30);
	drawJizuoCube(63, -6, -39);
	drawJizuoCube(54, -6, -39);
	drawJizuoCube(63, -6, -48);
	drawJizuoCube(54, -6, -48);
	drawJizuoCube(63, -6, -57);
	drawJizuoCube(54, -6, -57);
	drawJizuoCube(63, -6, -66);
	drawJizuoCube(54, -6, -66);
	drawJizuoCube(63, -6, -75);
	drawJizuoCube(54, -6, -75);
	drawJizuoCube(63, -6, -84);
	drawJizuoCube(54, -6, -84);
	drawJizuoCube(63, -6, -93);
	drawJizuoCube(54, -6, -93);
	drawJizuoCube(63, -6, -102);
	drawJizuoCube(54, -6, -102);
	drawJizuoCube(63, -6, -111);
	drawJizuoCube(54, -6, -111);
	drawJizuoCube(63, -6, -120);
	drawJizuoCube(54, -6, -120);
	drawJizuoCube(45, -6, -120);
	drawJizuoCube(45, -6, -111);
	drawJizuoCube(36, -6, -120);
	drawJizuoCube(36, -6, -111);
	drawJizuoCube(27, -6, -120);
	drawJizuoCube(27, -6, -111);
	drawJizuoCube(18, -6, -120);
	drawJizuoCube(18, -6, -111);
	drawJizuoCube(9, -6, -120);
	drawJizuoCube(9, -6, -111);
	drawJizuoCube(0, -6, -120);
	drawJizuoCube(0, -6, -111);
	drawJizuoCube(-9, -6, -120);
	drawJizuoCube(-9, -6, -111);
	drawJizuoCube(-18, -6, -120);
	drawJizuoCube(-18, -6, -111);
	drawJizuoCube(-27, -6, -120);
	drawJizuoCube(-27, -6, -111);
	drawJizuoCube(-36, -6, -120);
	drawJizuoCube(-36, -6, -111);
	drawJizuoCube(-45, -6, -120);
	drawJizuoCube(-45, -6, -111);
	drawJizuoCube(-54, -6, -120);
	drawJizuoCube(-54, -6, -111);
	drawJizuoCube(-63, -6, -120);
	drawJizuoCube(-63, -6, -111);
	drawJizuoCube(-63, -6, -102);
	drawJizuoCube(-54, -6, -102);
	drawJizuoCube(-63, -6, -93);
	drawJizuoCube(-54, -6, -93);
	drawJizuoCube(-63, -6, -84);
	drawJizuoCube(-54, -6, -84);
	drawJizuoCube(-63, -6, -75);
	drawJizuoCube(-54, -6, -75);
	drawJizuoCube(-63, -6, -66);
	drawJizuoCube(-54, -6, -66);
	drawJizuoCube(-63, -6, -57);
	drawJizuoCube(-54, -6, -57);
	drawJizuoCube(-63, -6, -48);
	drawJizuoCube(-54, -6, -48);
	drawJizuoCube(-63, -6, -39);
	drawJizuoCube(-54, -6, -39);
	drawJizuoCube(-63, -6, -30);
	drawJizuoCube(-54, -6, -30);
	drawJizuoCube(-63, -6, -21);
	drawJizuoCube(-54, -6, -21);
	drawJizuoCube(-63, -6, -12);
	drawJizuoCube(-54, -6, -12);
	
	//二层基座一级台阶
	drawStairs(-9, -9, 18);
	drawStairs(-6, -9, 18);
	drawStairs(-3, -9, 18);
	drawStairs(0, -9, 18);
	drawStairs(3, -9, 18);
	drawStairs(6, -9, 18);
	drawStairs(9, -9, 18);


	//二层基座二级台阶
	drawStairs(-9, -6, 15);
	drawStairs(-6, -6, 15);
	drawStairs(-3, -6, 15);
	drawStairs(0, -6, 15);
	drawStairs(3, -6, 15);
	drawStairs(6, -6, 15);
	drawStairs(9, -6, 15);
	drawStairs(-9, -9, 15);
	drawStairs(-6, -9, 15);
	drawStairs(-3, -9, 15);
	drawStairs(0, -9, 15);
	drawStairs(3, -9, 15);
	drawStairs(6, -9, 15);
	drawStairs(9, -9, 15);

	//二层基座三级台阶
	drawStairs(-9, -3, 12);
	drawStairs(-6, -3, 12);
	drawStairs(-3, -3, 12);
	drawStairs(0, -3, 12);
	drawStairs(3, -3, 12);
	drawStairs(6, -3, 12);
	drawStairs(9, -3, 12);
	drawStairs(-9, -9, 12);
	drawStairs(-6, -9, 12);
	drawStairs(-3, -9, 12);
	drawStairs(0, -9, 12);
	drawStairs(3, -9, 12);
	drawStairs(6, -9, 12);
	drawStairs(9, -9, 12);
	drawStairs(-9, -6, 12);
	drawStairs(-6, -6, 12);
	drawStairs(-3, -6, 12);
	drawStairs(0, -6, 12);
	drawStairs(3, -6, 12);
	drawStairs(6, -6, 12);
	drawStairs(9, -6, 12);

	//画二层基座围栏
	drawFenceWall(12, -1, 9, 53);
	drawFenceWall(12, 0, 9, 53);
	drawFenceWall(12, 1, 9, 53);
	drawFenceWall(12, 2, 9, 53);
	glPushMatrix();
	glTranslated(-76, 0, 0);
	drawFenceWall(12, 0, 9, 54);
	drawFenceWall(12, 1, 9, 54);
	drawFenceWall(12, 2, 9, 54);
	drawFenceWall(12, -1, 9, 54);
	glPopMatrix();

	for (int i = 0; i < 16; i++) {
		drawTower(0.25, 1, 12 + i*3.5, 9, 3);
	}

	for (int i = 0; i < 16; i++) {
		drawTower(0.25, 1, -11.5 - i * 3.5, 9, 3);
	}

	drawFenceWall2(65, 0, 9, 131);
	drawFenceWall2(65, 1, 9, 131);
	drawFenceWall2(65, 2, 9, 131);
	drawFenceWall2(65, -1, 9, 131);
	
	for (int i = 0; i < 38; i++) {
		drawTower(0.25, 1,  65, 9.5 - 3.5*i, 3);
	}


	drawFenceWall(-65, 0, -121, 131);
	drawFenceWall(-65, 1, -121, 131);
	drawFenceWall(-65, 2, -121, 131);
	drawFenceWall(-65, -1, -121, 131);
	for (int i = 0; i < 38; i++) {
		drawTower(0.25, 1, -65 + 3.5*i, -121, 3);
	}
	drawFenceWall2(-65, 0, 9, 131);
	drawFenceWall2(-65, 1, 9, 131);
	drawFenceWall2(-65, 2, 9, 131);
	drawFenceWall2(-65, -1, 9, 131);
	for (int i = 0; i < 38; i++) {
		drawTower(0.25, 1, -65, -121 + i*3.5, 3);
	}

	//画一层基座围栏
	drawFenceWall(11, 9, -9, 36);
	drawFenceWall(11, 10, -9, 36);
	drawFenceWall(11, 11, -9, 36);
	drawFenceWall(11, 8, -9, 36);
	glPushMatrix();
	glTranslated(-58, 0, 0);
	drawFenceWall(11, 9, -9, 37);
	drawFenceWall(11, 10, -9, 37);
	drawFenceWall(11, 11, -9, 37);
	drawFenceWall(11, 8, -9, 37);
	glPopMatrix();

	for (int i = 0; i < 10; i++) {
		drawTower(0.25, 1, 12 + i * 3.5, -9, 12);
	}

	for (int i = 0; i < 10; i++) {
		drawTower(0.25, 1, -11.5 - i * 3.5, -9, 12);
	}

	drawFenceWall2(47, 9, -9, 93);
	drawFenceWall2(47, 10, -9, 93);
	drawFenceWall2(47, 11, -9, 93);
	drawFenceWall2(47, 8, -9, 93);

	for (int i = 0; i < 27; i++) {
		drawTower(0.25, 1, 47, -9 - i* 3.5, 12);
	}

	drawFenceWall(-47, 9,  -102, 95);
	drawFenceWall(-47, 10, -102, 95);
	drawFenceWall(-47, 11, -102, 95);
	drawFenceWall(-47, 8, -102, 95);
	for (int i = 0; i < 28; i++) {
		drawTower(0.25, 1, -47 + 3.5 * i, -102, 12);
	}

	drawFenceWall2(-47, 9, -9, 93);
	drawFenceWall2(-47, 10, -9, 93);
	drawFenceWall2(-47, 11, -9, 93);
	drawFenceWall2(-47, 8, -9, 93);

	for (int i = 0; i < 27; i++) {
		drawTower(0.25, 1, -47, -9 - i * 3.5, 12);
	}
	

	//石柱前左2
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-15, 10, -15);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
    drawTower(1.25, 30, -15, -15, 12);

	//石柱前左1
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-42, 10, -15);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, -42, -15, 12);

	//石柱前右2
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(15, 10, -15);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, 15, -15, 12);

	//石柱前右1
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(42, 10, -15);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, 42, -15, 12);

	//石柱左左2
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(42, 10, -35);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, 42, -35, 12);

	//石柱左左3
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(42, 10, -56);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, 42, -56, 12);

	//石柱左左4
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(42, 10, -77);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, 42, -77, 12);

	//石柱左左5
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(42, 10, -96);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, 42, -96, 12);

	//石柱后
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-15, 10, -96);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, -15, -96, 12);

	//石柱后
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-42, 10, -96);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, -42, -96, 12);

	//石柱后
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(15, 10, -96);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, 15, -96, 12);

	//石柱右
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-42, 10, -35);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, -42, -35, 12);

	//石柱右
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-42, 10, -56);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, -42, -56, 12);

	//石柱右
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(-42, 10, -77);
	glutSolidCube(5);
	glPopMatrix();
	glColor3f(1.0, 0.0, 0.0);
	drawTower(1.25, 30, -42, -77, 12);
	
	//大殿主体方块
	for (int k = 0; k < 15; k++) {
		for (int j = 0; j < 24; j++) {
			for (int i = 0; i < 25; i++) {
				glPushMatrix();
				glColor3f(0.8, 0.1647, 0.1647);
				glTranslated(-36 + i * 3, 47 - k*3, -21 - j * 3);
				glutSolidCube(3);
				glPopMatrix();
			}
		}
	}

	//大殿第一层房顶
	for (int j = 0; j < 88; j++) {
		for (int i = 0; i < 99; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-49 + i * 1, 42, -12 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}
	//大殿第二层房顶
	for (int j = 0; j < 86; j++) {
		for (int i = 0; i < 97; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-48 + i * 1, 43, -13 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第三层房顶
	for (int j = 0; j < 84; j++) {
		for (int i = 0; i < 95; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-47 + i * 1, 44, -14 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第四层房顶
	for (int j = 0; j < 82; j++) {
		for (int i = 0; i < 93; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-46 + i * 1, 45, -15 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第五层房顶
	for (int j = 0; j < 80; j++) {
		for (int i = 0; i < 91; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-45 + i * 1, 46, -16 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第六层房顶
	for (int j = 0; j < 78; j++) {
		for (int i = 0; i < 89; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-44 + i * 1, 47, -17 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第七层房顶
	for (int j = 0; j < 76; j++) {
		for (int i = 0; i < 87; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-43 + i * 1, 48, -18 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第八层房顶
	for (int j = 0; j < 74; j++) {
		for (int i = 0; i < 85; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-42 + i * 1, 49, -19 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第九层房顶
	for (int j = 0; j < 72; j++) {
		for (int i = 0; i < 83; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-41 + i * 1, 50, -20 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十层房顶
	for (int j = 0; j < 70; j++) {
		for (int i = 0; i < 81; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-40 + i * 1, 51, -21 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}
	 
	//蓝色隔断
	for (int k = 0; k < 12; k++) {
		for (int j = 0; j < 22; j++) {
			for (int i = 0; i < 24; i++) {
				glPushMatrix();
				glColor3f(0, 0, 1);
				glTranslated(-35 + i * 3, 55 - k * 3, -24 - j * 3);
				glutSolidCube(3);
				glPopMatrix();
			}
		}
	}

	//正大光明匾

	for (int k = 0; k < 9; k++) {
		for (int i = 0; i < 3; i++) {
			glPushMatrix();
			glColor3f(1, 1, 0);
			glRotatef(15, 1, 0, 0);
			glTranslated(-2 + i * 1 ,41 + k * 1, -35 );
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十一层房顶
	for (int j = 0; j < 68; j++) {
		for (int i = 0; i < 82; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-40 + i * 1, 57, -22 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十一层房顶
	for (int j = 0; j < 66; j++) {
		for (int i = 0; i < 80; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-39 + i * 1, 58, -23 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十二层房顶
	for (int j = 0; j < 64; j++) {
		for (int i = 0; i < 78; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-38 + i * 1, 59, -24 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十三层房顶
	for (int j = 0; j < 62; j++) {
		for (int i = 0; i < 76; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-37 + i * 1, 60, -25 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十四层房顶
	for (int j = 0; j < 60; j++) {
		for (int i = 0; i < 74; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-36 + i * 1, 61, -26 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十五层房顶
	for (int j = 0; j < 58; j++) {
		for (int i = 0; i < 72; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-35 + i * 1, 62, -27 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十六层房顶
	for (int j = 0; j < 54; j++) {
		for (int i = 0; i < 70; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-34 + i * 1, 63, -29 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十七层房顶
	for (int j = 0; j < 50; j++) {
		for (int i = 0; i < 68; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-33 + i * 1, 64, -31 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿第十八层房顶
	for (int j = 0; j < 46; j++) {
		for (int i = 0; i < 66; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-32 + i * 1, 65, -33 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 42; j++) {
		for (int i = 0; i < 64; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-31 + i * 1, 66, -35 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 38; j++) {
		for (int i = 0; i < 62; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-30 + i * 1, 67, -37 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 34; j++) {
		for (int i = 0; i < 60; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-29 + i * 1, 68, -39 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 30; j++) {
		for (int i = 0; i < 58; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-28 + i * 1, 69, -41 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < 56; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-27 + i * 1, 70, -43 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 22; j++) {
		for (int i = 0; i < 54; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-26 + i * 1, 71, -45 - j * 1);
			glutSolidCube(1);

			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 18; j++) {
		for (int i = 0; i < 52; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-25 + i * 1, 72, -47 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 14; j++) {
		for (int i = 0; i < 50; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-24 + i * 1, 73, -49 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 48; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-23 + i * 1, 74, -51 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 46; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-22 + i * 1, 75, -53 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	//大殿第十八层房顶
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 44; i++) {
			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslated(-21 + i * 1, 76, -55 - j * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	//大殿大门
	drawDamen();

	glPushMatrix();
	glTranslated(-26, 0, 0);
	drawDamen();
	glPopMatrix();

	glPushMatrix();
	glTranslated(26, 0, 0);
	drawDamen();
	glPopMatrix();

	//左草地
	for (int i = 0; i < 15; i++) {
		glPushMatrix();
		glTranslated(22 + i*6, 0, 20);
		drawDiban1();
		drawDiban2();
		glPopMatrix();
	}

	//右草地
	for (int i = 0; i < 15; i++) {
		glPushMatrix();
		glTranslated(216 + i * 6, 0, 20);
		drawDiban1();
		drawDiban2();
		glPopMatrix();
	}
	
	//草地中间祭祀青铜鼎
	glPushMatrix();
	glTranslated(0,0,50);
	glColor3f(1, 1, 1);
	drawStairs(-9, 0, 75);
	drawStairs(-6, 0, 75);
	drawStairs(-3, 0, 75);
	drawStairs(0, 0, 75);
	drawStairs(3, 0, 75);
	drawStairs(6, 0, 75);
	drawStairs(9, 0, 75);

	drawStairs(-9, 0, 78);
	drawStairs(-6, 0, 78);
	drawStairs(-3, 0, 78);
	drawStairs(0, 0, 78);
	drawStairs(3, 0, 78);
	drawStairs(6, 0, 78);
	drawStairs(9, 0, 78);

	drawStairs(-9, 0, 81);
	drawStairs(-6, 0, 81);
	drawStairs(-3, 0, 81);
	drawStairs(0, 0, 81);
	drawStairs(3, 0, 81);
	drawStairs(6, 0, 81);
	drawStairs(9, 0, 81);

	drawStairs(-9, 0, 84);
	drawStairs(-6, 0, 84);
	drawStairs(-3, 0, 84);
	drawStairs(0, 0, 84);
	drawStairs(3, 0, 84);
	drawStairs(6, 0, 84);
	drawStairs(9, 0, 84);

	drawStairs(9, -3, 75);
	drawStairs(-9, -3, 75);
	drawStairs(9, -3, 84);
	drawStairs(-9, -3, 84);

	drawTower(1.25, 7, 9, 75, -11);
	drawTower(1.25, 7, -9, 75, -11);
	drawTower(1.25, 7, -9, 84, -11);
	drawTower(1.25, 7, 9, 84, -11);

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 12; i++) {
			glPushMatrix();
			glTranslated(10, 2 + j * 1, 74 + i * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 12; i++) {
			glPushMatrix();
			glTranslated(-10, 2 + j * 1, 74 + i * 1);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 21; i++) {
			glPushMatrix();
			glTranslated(10 - i * 1, 2 + j * 1, 85);
			glutSolidCube(1);
			glPopMatrix();
		}
	}

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 21; i++) {
			glPushMatrix();
			glTranslated(10 - i * 1, 2 + j * 1, 74);
			glutSolidCube(1);
			glPopMatrix();
		}
	}
	
	//把手右
	glPushMatrix();
	glTranslated(10,6,80.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 8, 80.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 6, 77.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 8, 77.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 7, 80.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 7, 77.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 8, 79.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 8, 78.5);
	glutSolidCube(1);
	glPopMatrix();


	//把手左
	glPushMatrix();
	glTranslated(-10, 6, 80.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 8, 80.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 6, 77.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 8, 77.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 7, 80.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 7, 77.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 8, 79.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 8, 78.5);
	glutSolidCube(1);
	glPopMatrix();

	//青铜鼎里的动态炭火1
	//glPushMatrix();
	//glTranslated(0, d-20, 79.5);
	//glutSolidTorus(1.2, 2.2, 10, 10);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslated(0, d - 15.65, 79.5);
	//glutSolidTorus(1.5, 3, 10, 10);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslated(0, d - 10, 79.5);
	//glutSolidTorus(2, 4, 10, 10);
	//glPopMatrix();
	//glPopMatrix();
	
	//炭火2
	glPushMatrix();
	glTranslated(0, d-20, 79.5);
	glutSolidTorus(d/20 * 0.6, d/10 * 0.55, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, d - 15.65, 79.5);
	glutSolidTorus(d / 20 * 0.75, d / 10 * 0.75, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, d - 10, 79.5);
	glutSolidTorus(d / 20, d / 10, 10, 10);
	glPopMatrix();


	glPopMatrix();

	
	//石狮子右
	glColor3f(1, 1, 1);
	for (int i = 0; i < 6; i++) {
		drawStairs(28, -10, 85 - i * 3);
		drawStairs(25, -10, 85 - i * 3);
		drawStairs(39, -10, 85 - i * 3);
		drawStairs(36, -10, 85 - i * 3);
		drawStairs(33, -10, 85 - i * 3);
		drawStairs(31, -10, 85 - i * 3);
	}
	for (int i = 0; i < 6; i++) {
		drawStairs(28, -7, 85 - i * 3);
		drawStairs(25, -7, 85 - i * 3);
		drawStairs(39, -7, 85 - i * 3);
		drawStairs(36, -7, 85 - i * 3);
		drawStairs(33, -7, 85 - i * 3);
		drawStairs(31, -7, 85 - i * 3);
	}

	glColor3f(1,1,0);
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslated(32,-7 - i * 1,87);
		glutSolidCube(1);
		glPopMatrix();
	}

	glColor3f(1, 1, 1);
	drawStairs(36, -4, 82);
	drawStairs(36, -1, 82);

	drawStairs(36, -1, 71);
	drawStairs(36, -4, 71);
	drawStairs(36, -4, 74);

	drawStairs(29, -4, 82);
	drawStairs(29, -1, 82);

	drawStairs(29, -1, 71);
	drawStairs(29, -4, 71);
	drawStairs(29, -4, 74);

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 5; i++) {
			drawStairs(36 - j * 3, 2, 71 + i * 3);
		}
	}

	for (int i = 0; i < 15; i++) {
		glPushMatrix();
		glTranslated(28,2, 70 + i * 1);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = 0; i < 15; i++) {
		glPushMatrix();
		glTranslated(28, 3, 70 + i * 1);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = 0; i < 15; i++) {
		glPushMatrix();
		glTranslated(28, 1, 70 + i * 1);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(30 + i * 1, 4, 85 - j * 1);
		}
	}
	
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(30 + i * 1, 5, 82 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(30 + i * 1, 6, 85 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(30 + i * 1, 7, 85 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(30 + i * 1, 8, 85 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(30 + i * 1, 9, 85 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(30 + i * 1, 10, 85 - j * 1);
		}
	}

	//石狮子左
	glColor3f(1, 1, 1);
	for (int i = 0; i < 6; i++) {
		drawStairs(-28, -10, 85 - i * 3);
		drawStairs(-25, -10, 85 - i * 3);
		drawStairs(-39, -10, 85 - i * 3);
		drawStairs(-36, -10, 85 - i * 3);
		drawStairs(-33, -10, 85 - i * 3);
		drawStairs(-31, -10, 85 - i * 3);
	}
	for (int i = 0; i < 6; i++) {
		drawStairs(-28, -7, 85 - i * 3);
		drawStairs(-25, -7, 85 - i * 3);
		drawStairs(-39, -7, 85 - i * 3);
		drawStairs(-36, -7, 85 - i * 3);
		drawStairs(-33, -7, 85 - i * 3);
		drawStairs(-31, -7, 85 - i * 3);
	}

	glColor3f(1, 1, 0);
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslated(-32, -7 - i * 1, 87);
		glutSolidCube(1);
		glPopMatrix();
	}

	glColor3f(1, 1, 1);
	drawStairs(-36, -4, 82);
	drawStairs(-36, -1, 82);

	drawStairs(-36, -1, 71);
	drawStairs(-36, -4, 71);
	drawStairs(-36, -4, 74);

	drawStairs(-29, -4, 82);
	drawStairs(-29, -1, 82);

	drawStairs(-29, -1, 71);
	drawStairs(-29, -4, 71);
	drawStairs(-29, -4, 74);

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 5; i++) {
			drawStairs(-36 + j * 3, 2, 71 + i * 3);
		}
	}

	for (int i = 0; i < 15; i++) {
		glPushMatrix();
		glTranslated(-28, 2, 70 + i * 1);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = 0; i < 15; i++) {
		glPushMatrix();
		glTranslated(-28, 3, 70 + i * 1);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = 0; i < 15; i++) {
		glPushMatrix();
		glTranslated(-28, 1, 70 + i * 1);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(-30 - i * 1, 4, 85 - j * 1);
		}
	}

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(-30 - i * 1, 5, 82 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(-30 - i * 1, 6, 85 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(-30 - i * 1, 7, 85 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(-30 - i * 1, 8, 85 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(-30 - i * 1, 9, 85 - j * 1);
		}
	}

	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 6; i++) {
			drawHead(-30 - i * 1, 10, 85 - j * 1);
		}
	}

	//士兵右
	glPushMatrix();
	glTranslated(10, 0, -20);
	drawShibing();
	glPopMatrix();

	//士兵左
	glPushMatrix();
	glTranslated(-80, 0, -20);
	drawShibing();
	glPopMatrix();

	//宫殿士兵
	glPushMatrix();
	glTranslated(-75, 12, -56);
	drawShibing();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 12, -56);
	drawShibing();
	glPopMatrix();

	//马车
	glPushMatrix();
	glTranslated(0, -12, zz + 50);
	drawMache();
	glPopMatrix();

	glFlush();
}
void init() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	GLfloat light_position[] = { 3.0, 3.0, 1.0, 0.0 };
	GLfloat light_position1[] = { 0.0, 1.0, 1.0, 0.0 };
	GLfloat light_position2[] = { 0.0, 0.0, 20.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-150.0, 150.0, -150.0, 150.0, -150.0, 550.0);
}
int main(int argc, char** argv) {
	glutInitWindowSize(1200, 1200);
	glutInit(&argc, argv);
	glutCreateWindow("3D Drawing with Visualised Axis");
	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	glutSpecialFunc(mySpecialkey);
	glutIdleFunc(idle);
	init();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

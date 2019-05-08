
	#include <iostream>		//Console write lib
	#include <stdlib.h>
	#include <glut.h>


	static double speedMerkur = 0, speedVenus = 0, speedDunya = 0, speedMars = 0, speedJupiter = 0, speedSaturn = 0, speedUranus = 0, speedNeptun = 0;
	static int YearDunya = 0;
	static bool pChanged = false;
	static bool animationState = false;
	static double AstroidX = -35.0;					//Astroid x konumu
	int StarX, StarY, StarsX[100], StarsY[100];		//Arkaplan yýldýzlarý x,y konumlarý
	static GLint fogMode;

	void fogSettings() {
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		{
			GLfloat mat[3] = { 0.1745, 0.01175, 0.01175 };
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
			mat[0] = 0.61424; mat[1] = 0.04136; mat[2] = 0.04136;
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
			mat[0] = 0.727811; mat[1] = 0.626959; mat[2] = 0.626959;
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
			glMaterialf(GL_FRONT, GL_SHININESS, 0.6*128.0);
		}

		glEnable(GL_FOG);

		{
			GLfloat fogColor[4] = { 0.1, 0.1, 0.1, 1.0 };
			fogMode = GL_EXP2;
			glFogi(GL_FOG_MODE, fogMode);
			glFogfv(GL_FOG_COLOR, fogColor);
			glFogf(GL_FOG_DENSITY, 0.05);
			glHint(GL_FOG_HINT, GL_DONT_CARE);
			glFogf(GL_FOG_START, 3.0);
			glFogf(GL_FOG_END, 5.0);
		}
		glClearColor(0.5, 0.5, 0.5, 0.5);  /* fog color */
	}

	void init(void) {

		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_DONT_CARE); // perspektif düzeltme
		fogSettings();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glutPostRedisplay();
	}

	void CreateSolar() {

		GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
		GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
		GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
		GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat no_shininess[] = { 0.0 };
		GLfloat low_shininess[] = { 5.0 };
		GLfloat high_shininess[] = { 100.0 };
		GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };

		glEnable(GL_TEXTURE_2D);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHTING);


		glPushMatrix();
		//Sun
		glPushMatrix();	//Sun push
		glColor4f(1.0, 1.0, 0, 1);
		glTranslatef(0, 0.0, 0.0);
		glutSolidSphere(1, 50, 20);
		glEnable(GL_LIGHTING);
		GLfloat light_position[] = { 0.0, 0.0, 0.0, 1 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		GLfloat light_diff[] = { 1.0, 1.0, 1.0, 1.0 };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diff);
		GLfloat light_amb[] = { 0.0, 0.0, 0.0, 1.0 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
		glPopMatrix();	//Sun pop
		glFlush();




		//Planets
		glPushMatrix();
		glRotatef((GLdouble)speedMerkur, 0.0, 1.0, 0.0);
		glTranslatef(1.7, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(0.1, 90, 400);
		glPopMatrix();
		glFlush();

		glPushMatrix();
		glRotatef((GLdouble)speedVenus, 0.0, 1.0, 0.0);
		glTranslatef(2.2, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(0.15, 90, 400);
		glPopMatrix();
		glFlush();

		glPushMatrix();
		glRotatef((GLdouble)speedDunya, 0.0, 1.0, 0.0);
		glTranslatef(2.8, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(0.25, 90, 400);
		glPopMatrix();
		glFlush();

		glPushMatrix();
		glRotatef((GLdouble)speedMars, 0.0, 1.0, 0.0);
		glTranslatef(3.4, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glutSolidSphere(0.13, 90, 400);
		glPopMatrix();
		glFlush();

		glPushMatrix();
		glRotatef((GLdouble)speedJupiter, 0.0, 1.0, 0.0);
		glTranslatef(4.2, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(0.4, 90, 400);
		glPopMatrix();
		glFlush();

		glPushMatrix();
		glRotatef((GLdouble)speedSaturn, 0.0, 1.0, 0.0);
		glTranslatef(5.3, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(0.35, 90, 400);
		glPopMatrix();
		glFlush();

		glPushMatrix();
		glRotatef((GLdouble)speedUranus, 0.0, 1.0, 0.0);
		glTranslatef(6.2, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(0.28, 90, 400);
		glPopMatrix();
		glFlush();

		glPushMatrix();
		glRotatef((GLdouble)speedNeptun, 0.0, 1.0, 0.0);
		glTranslatef(7.2, 0.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glutSolidSphere(0.28, 90, 400);
		glPopMatrix();
		glFlush();


		//Astroid push
		glPushMatrix();
		glTranslatef(AstroidX, -10.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glutSolidSphere(1.8, 90, 400);
		glPopMatrix();
		glFlush();


		glPopMatrix();

	}

	//Yýldýz konumlarýný random olarak alýyoruz.
	void StarsXY() {

		for (int i = 0; i < 50; i++)
		{
			StarX = (rand() % 70) - 35;
			StarY = (rand() % 40) - 20;

			StarsX[i] = StarX;
			StarsY[i] = StarY;
		}
	}

	//Alýnan x,y lere göre yýldýzlarý sürekli çiziyoruz.
	void DisplayStars() {
		for (int i = 0; i < 50; i++)
		{
			glPushMatrix();
			glTranslatef(StarsX[i], -10, StarsY[i]);
			glutSolidSphere(0.08, 90, 400);
			glPopMatrix();
		}
	}


	void display(void) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		CreateSolar();
		DisplayStars();
		glutSwapBuffers();
	}

	void reshape(int w, int h)
	{
		glViewport(0, 0, (GLsizei)w, (GLsizei)h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(440, (GLdouble)w / (GLdouble)h, 1.0, 20.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0, 10, 0.0, 0, 0.0, 0.0, 0.0, 1.0, -1.0);
	}

	void MenuWrite() {
		std::cout << "\n-----------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "	Merhaba, Gunes sistemi simulasyonuna hosgeldiniz." << std::endl;
		std::cout << "	->	Kamera secenekleri icin		: 'p' tuslayiniz." << std::endl;
		std::cout << "	->	Sis efekti icin	        	: 'o' tuslayiniz." << std::endl;
		std::cout << "	->	Gezegen secenekleri icin	: '1,2,3,4,5,6,7,8' yada 'a,s,d,f,g,h,j,k' tuslayiniz." << std::endl;
		std::cout << "	->	Simulasyonu baslatmak icin	: 'q' tuslayiniz." << std::endl;
		std::cout << "	->	Astroid simulasyonu icin	: 'x', Sifirlamak icin : 'X' tuslayiniz" << std::endl;
		std::cout << "	->	Simulasyondan cikmak icin	: 'esc' tuslayiniz." << std::endl;
		std::cout << "	->	Menuyu yazdirmak icin		: 'm' yada 'M' tuslayiniz." << std::endl;
		std::cout << "-----------------------------------------------------------------------------------------------------------------------\n" << std::endl;
	}

	void animate() {

		speedMerkur = (speedMerkur + (double)4.14);
		speedVenus = (speedVenus + (double)1.62);
		speedDunya = (speedDunya + (double)1);
		speedMars = (speedMars + (double)0.53);
		speedJupiter = (speedJupiter + (double)0.083);
		speedSaturn = (speedSaturn + (double)0.033);
		speedUranus = (speedUranus + (double)0.012);
		speedNeptun = (speedNeptun + (double)0.007);

		if ((int)speedDunya % 360 == 0) {
			YearDunya = YearDunya + 1;
		}
		std::cout << "	Dunya'ya gore		gecen gun sayisi : " << (int)speedDunya << "		Gecen Yil :" << YearDunya << std::endl;

		if (YearDunya >= 0) {
			AstroidX = (AstroidX + (double)0.1);
		}
		else if (YearDunya >= 20) {
			AstroidX = -35.0;
		}

		glutPostRedisplay();
	}

	void keyboard(unsigned char key, int x, int y) {

		switch (key) {

		case 'p':
			glLoadIdentity();
			if (!pChanged)
				gluLookAt(8.25, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			else
				gluLookAt(0, 10, 0.0, 0, 0.0, 0.0, 0.0, 1.0, -1.0);

			pChanged = !pChanged;
			glutPostRedisplay();
			break;

		case 'q':
			if (!animationState)
				glutIdleFunc(animate);
			else {
				glutIdleFunc(NULL);
				std::cout << "Simulasyon durduruldu." << std::endl;
				MenuWrite();
			}

			animationState = !animationState;
			break;

		case ' ':
			speedMerkur = (speedMerkur + (double)41.4);
			speedVenus = (speedVenus + (double)16.2);
			speedDunya = (speedDunya + (double)10);
			speedMars = (speedMars + (double)5.3);
			speedJupiter = (speedJupiter + (double)0.83);
			speedSaturn = (speedSaturn + (double)0.33);
			speedUranus = (speedUranus + (double)0.12);
			speedNeptun = (speedNeptun + (double)0.07);

			if ((int)speedDunya % 360 == 0) {
				YearDunya = YearDunya + 1;
			}
			std::cout << "	Dunya'ya gore		gecen gun sayisi : " << (int)speedDunya << "		Gecen Yil :" << YearDunya << std::endl;

			glutPostRedisplay();
			break;

		case 'b':
			speedMerkur = (speedMerkur - (double)41.4);
			speedVenus = (speedVenus - (double)16.2);
			speedDunya = (speedDunya - (double)10);
			speedMars = (speedMars - (double)5.3);
			speedJupiter = (speedJupiter - (double)0.83);
			speedSaturn = (speedSaturn - (double)0.33);
			speedUranus = (speedUranus - (double)0.12);
			speedNeptun = (speedNeptun - (double)0.07);

			if ((int)speedDunya % 360 == 0) {
				YearDunya = YearDunya - 1;
			}
			std::cout << "	Dunya'ya gore		gecen gun sayisi : " << (int)speedDunya << "		Gecen Yil :" << YearDunya << std::endl;

			glutPostRedisplay();
			break;

		case 'x':
			AstroidX = (AstroidX + (double)0.1);
			glutPostRedisplay();
			break;

		case'X':
			AstroidX = -35.0;
			glutPostRedisplay();
			break;

		case '1':
			speedMerkur = (speedMerkur + (double)41.4);
			glutPostRedisplay();
			break;

		case 'a':
			speedMerkur = (speedMerkur - (double)41.4);
			glutPostRedisplay();
			break;

		case '2':
			speedVenus = (speedVenus + (double)16.2);
			glutPostRedisplay();
			break;

		case 's':
			speedVenus = (speedVenus - (double)16.2);
			glutPostRedisplay();
			break;

		case '3':
			speedDunya = (speedDunya + (double)10);
			glutPostRedisplay();
			break;

		case 'd':
			speedDunya = (speedDunya - (double)10);
			glutPostRedisplay();
			break;

		case '4':
			speedMars = (speedMars + (double)5.3);
			glutPostRedisplay();
			break;

		case 'f':
			speedMars = (speedMars - (double)5.3);
			glutPostRedisplay();
			break;

		case '5':
			speedJupiter = (speedJupiter + (double)0.83);
			glutPostRedisplay();
			break;

		case 'g':
			speedJupiter = (speedJupiter - (double)0.83);
			glutPostRedisplay();
			break;

		case '6':
			speedSaturn = (speedSaturn + (double)0.33);
			glutPostRedisplay();
			break;

		case 'h':
			speedSaturn = (speedSaturn - (double)0.33);
			glutPostRedisplay();
			break;

		case '7':
			speedUranus = (speedUranus + (double)0.12);
			glutPostRedisplay();
			break;

		case 'j':
			speedUranus = (speedUranus - (double)0.12);
			glutPostRedisplay();
			break;

		case '8':
			speedNeptun = (speedNeptun + (double)0.07);
			glutPostRedisplay();
			break;

		case 'k':
			speedNeptun = (speedNeptun - (double)0.07);
			glutPostRedisplay();
			break;

		case 'm':
			MenuWrite();
			break;

		case 'M':
			MenuWrite();
			break;

		case 'o':
		case 'O':
			if (fogMode == GL_EXP) {
				fogMode = GL_LINEAR;
				printf("Fog mode is GL_EXP2\n");
			}
			else if (fogMode == GL_EXP2) {
				fogMode = GL_EXP;
				printf("Fog mode is GL_LINEAR\n");
			}
			else if (fogMode == GL_LINEAR) {
				fogMode = GL_EXP2;
				printf("Fog mode is GL_EXP\n");
			}
			glFogi(GL_FOG_MODE, fogMode);
			glutPostRedisplay();
			break;

		case 27:
			exit(0);
			break;

		default:
			break;

		}
	}


	int main(int argc, char** argv)
	{
		StarsXY();
		MenuWrite();
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
		glutInitWindowSize(800, 640);
		glutInitWindowPosition(200, 50);
		glutCreateWindow("Gunes Sistemi Simulasyonu");
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(reshape);
		glutKeyboardFunc(keyboard);
		glutMainLoop();
		return 0;
	}

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<windows.h>
#include <stdlib.h>

float zupdown = 200 ;
float updown = 0 ;
float kirikanan = 0;

void init(void);
void tampil(void);
void keyboard(unsigned char ,int,int);
void ukuran(int,int);
void mouse(int button, int state,int x,int y);
void mouseMotion(int x,int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

int is_depth;

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Kelompok 12");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(tampil);

    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0 , 0.0 , 0.0 , 0.0 );
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(5.0);
    glLineWidth(3.0f);
}

void kubus()
{ /*
    NOTE
    default posisi x,y,z yang ada di bawah
    merupakan posisi dari awal pertama kali di buka
   */
 //   garis pembantu x
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.5,0.5);
    glVertex3f(150,0,0);
    glVertex3f(-150,0,0);
    glEnd();

    //garis pembantu y
    glBegin(GL_LINE_STRIP);
    glColor3f(0.5,0.5,0.0);
    glVertex3f(0,150,0);
    glVertex3f(0,-150,0);
    glEnd();
    //garis pembantu z
    glBegin(GL_LINE_STRIP);
    glColor3f(0.5,0.5,0.0);
    glVertex3f(0,0,150);
    glVertex3f(0,0,-150);
    glEnd();
//------  Depan -------------------------------------------------------------------------------------

	////jendela depan
	for(int i = 0; i <= 5; i++){

        // Jendela line ------------------------------------------||||
		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(-35-(i*15),		27		,10.0);
		glVertex3f(-35-(i*15),		35		,10.0);
		glVertex3f(-23-(i*15),		35		,10.0);
		glVertex3f(-23-(i*15),		27		,10.0);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(-35-(i*15),		16		,10.0);
		glVertex3f(-35-(i*15),		24		,10.0);
		glVertex3f(-23-(i*15),		24		,10.0);
		glVertex3f(-23-(i*15),		16		,10.0);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(-35-(i*15),		5		,10.0);
		glVertex3f(-35-(i*15),		13		,10.0);
		glVertex3f(-23-(i*15),		13		,10.0);
		glVertex3f(-23-(i*15),		5		,10.0);
		glEnd();

		// Jendela KACA -----------------------------||||


		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(-35-(i*15),		27		,10.0);
		glVertex3f(-35-(i*15),		35		,10.0);
		glVertex3f(-23-(i*15),		35		,10.0);
		glVertex3f(-23-(i*15),		27		,10.0);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(-35-(i*15),		16		,10.0);
		glVertex3f(-35-(i*15),		24		,10.0);
		glVertex3f(-23-(i*15),		24		,10.0);
		glVertex3f(-23-(i*15),		16		,10.0);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(-35-(i*15),		5		,10.0);
		glVertex3f(-35-(i*15),		13		,10.0);
		glVertex3f(-23-(i*15),		13		,10.0);
		glVertex3f(-23-(i*15),		5		,10.0);
		glEnd();

	}

	//// jendela Depan 3
	for(int i = 0; i <= 1; i++){
       // Jendela line --------------------------------|||
		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(-128-(i*15),		27		,10.0);
		glVertex3f(-128-(i*15),		35		,10.0);
		glVertex3f(-115-(i*15),		35		,10.0);
		glVertex3f(-115-(i*15),		27		,10.0);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(-128-(i*15),		16		,10.0);
		glVertex3f(-128-(i*15),		24		,10.0);
		glVertex3f(-115-(i*15),		24		,10.0);
		glVertex3f(-115-(i*15),		16		,10.0);
		glEnd();

		// Jendela Kaca ---------------------------|||

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(-128-(i*15),		27		,10.0);
		glVertex3f(-128-(i*15),		35		,10.0);
		glVertex3f(-115-(i*15),		35		,10.0);
		glVertex3f(-115-(i*15),		27		,10.0);
		glEnd();

        glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(-128-(i*15),		16		,10.0);
		glVertex3f(-128-(i*15),		24		,10.0);
		glVertex3f(-115-(i*15),		24		,10.0);
		glVertex3f(-115-(i*15),		16		,10.0);
		glEnd();

	}



	 //depan ++
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-100.0,0.0,10.0);
    glVertex3f(-100.0,40.0,10.0);
    glVertex3f(0.0,40.0,10.0);
    glVertex3f(0.0,0.0,10.0);
    glEnd();

  //depan 2 ++
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-115.0,0.0,10.0);
    glVertex3f(-115.0,45.0,10.0);
    glVertex3f(-100.0,45.0,10.0);
    glVertex3f(-100.0,0.0,10.0);
    glEnd();

      //depan 2 ++atas
    glBegin(GL_TRIANGLES);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-115.0,45.0,10.0);
    glVertex3f(-107.5,50.0,10.0);
    glVertex3f(-100.0,45.0,10.0);
    glEnd();

    //depan 2 ++atas atap kanan
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-107.5,50.0,10.0);
    glVertex3f(-107.5,50.0,-30.0);
    glVertex3f(-100.0,45.0,-30.0);
    glVertex3f(-100.0,45.0,10.0);
    glEnd();

    //depan 2 ++atas atap kiri
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-107.5,50.0,10.0);
    glVertex3f(-107.5,50.0,-30.0);
    glVertex3f(-115.0,45.0,-30.0);
    glVertex3f(-115.0,45.0,10.0);
    glEnd();

    //depan 2 ++atas atap kiri tengah
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-115.5,40.0,10.0);
    glVertex3f(-115.5,40.0,-30.0);
    glVertex3f(-115.0,45.0,-30.0);
    glVertex3f(-115.0,45.0,10.0);
    glEnd();

    //depan 2 ++atas atap kanan tengah
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-100.5,40.0,10.0);
    glVertex3f(-100.5,40.0,-30.0);
    glVertex3f(-100.0,45.0,-30.0);
    glVertex3f(-100.0,45.0,10.0);
    glEnd();

    //Depan 3
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-115.0,13.35,10.0);
    glVertex3f(-115.0,40.0,10.0);
    glVertex3f(-155.0,40.0,10.0);
    glVertex3f(-155.0,13.35,10.0);
    glEnd();


    //depanz
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(40.0,0.0,100.0);
    glVertex3f(40.0,40.0,100.0);
    glVertex3f(0.0,40.0,100.0);
    glVertex3f(0.0,0.0,100.0);
    glEnd();

    //depanz2
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(70.0,0.0,115.0);
    glVertex3f(70.0,40.0,115.0);
    glVertex3f(0.0,40.0,115.0);
    glVertex3f(0.0,0.0,115.0);
    glEnd();

    //depanz2 atap
    glBegin(GL_TRIANGLES);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(40.0,50.0,115.0);
    glVertex3f(40.0,40.0,115.0);
    glVertex3f(0.0,40.0,115.0);
    glEnd();

    //depan z tengah
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(40.0,0.0,20.0);
    glVertex3f(40.0,50.0,20.0);
    glVertex3f(0.0,50.0,20.0);
    glVertex3f(0.0,0.0,20.0);
    glEnd();

    //depan z tengah atas
    glBegin(GL_QUADS);
    glColor3f(0,0.7,0);
    glVertex3f(40.0,53.0,20.0);
    glVertex3f(40.0,50.0,20.0);
    glVertex3f(0.0,50.0,20.0);
    glVertex3f(0.0,53.0,20.0);
    glEnd();

    //depan z tengah atas 2
    glBegin(GL_QUADS);
    glColor3f(0,0.7,0);
    glVertex3f(40.0,53.0,20.0);
    glVertex3f(40.0,63.0,10.0);
    glVertex3f(0.0,63.0,10.0);
    glVertex3f(0.0,53.0,20.0);
    glEnd();

    //depan z tengah atas 3
    glBegin(GL_QUADS);
    glColor3f(0,0.7,0);
    glVertex3f(40.0,65.0,10.0);
    glVertex3f(40.0,63.0,10.0);
    glVertex3f(0.0,63.0,10.0);
    glVertex3f(0.0,65.0,10.0);
    glEnd();

    //depanTengah
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(0.0,40.0,20.0);
    glVertex3f(0.0,50.0,20.0);
    glVertex3f(-10,50.0,10.0);
    glVertex3f(-10,40.0,10.0);
    glEnd();

    //depan atas Tengah
    glBegin(GL_QUADS);
    glColor3f(0,0.7,0);
    glVertex3f(0.0,53.0,20.0);
    glVertex3f(0.0,50.0,20.0);
    glVertex3f(-10,50.0,10.0);
    glVertex3f(-10,53.0,10.0);
    glEnd();

    //depan atas Tengah 2
    glBegin(GL_QUADS);
    glColor3f(0,0.7,0);
    glVertex3f(0.0,53.0,20.0);
    glVertex3f(0.0,63.0,10.0);
    glVertex3f(-5,63.0,5.0);
    glVertex3f(-10,53.0,10.0);
    glEnd();


    //depan atas Tengah atas
    glBegin(GL_QUADS);
    glColor3f(0,0.7,0);
    glVertex3f(40.0,65.0,10.0);
    glVertex3f(40.0,65.0,-30.0);
    glVertex3f(0,65.0,-30.0);
    glVertex3f(0,65.0,10.0);
    glEnd();

    //depandepanTengah Pintu
    glBegin(GL_QUADS);
    glColor4f(0,0,0,0.7);
    glVertex3f(-5.0,0.0,25.0);
    glVertex3f(-5.0,10.0,25.0);
    glVertex3f(-15.0,10.0,15.0);
    glVertex3f(-15.0,0.0,15.0);
    glEnd();


    //depandepanTengah
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(0.0,0.0,30.0);
    glVertex3f(0.0,40.0,30.0);
    glVertex3f(-20.0,40.0,10.0);
    glVertex3f(-20.0,0.0,10.0);
    glEnd();

    //Depan 4
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-153.0,0,10);
    glVertex3f(-153.0,13.35,10.);
    glVertex3f(-155.0,13.35,10.);
    glVertex3f(-155.0,0,10);
    glEnd();

    //Depan 5
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-128.0,0,10);
    glVertex3f(-128.0,13.35,10.);
    glVertex3f(-130.0,13.35,10.);
    glVertex3f(-130.0,0,10);
    glEnd();

//--- Belakang --------------------------------------------------------------------------------------



    //// jendela belakang

	for(int i = 1; i <= 1; i++){


       // Jendela line --------------------------------|||
		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(48-(i*15),		27		,-30.0);
		glVertex3f(48-(i*15),		35		,-30.0);
		glVertex3f(60-(i*15),		35		,-30.0);
		glVertex3f(60-(i*15),		27		,-30.0);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(48-(i*15),		16		,-30);
		glVertex3f(48-(i*15),		24		,-30);
		glVertex3f(60-(i*15),		24		,-30);
		glVertex3f(60-(i*15),		16		,-30);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(48-(i*15),		5		,-30);
		glVertex3f(48-(i*15),		13		,-30);
		glVertex3f(60-(i*15),		13		,-30);
		glVertex3f(60-(i*15),		5		,-30);
		glEnd();

		// Jendela Kaca --------------------------------|||

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(48-(i*15),		27		,-30.0);
		glVertex3f(48-(i*15),		35		,-30.0);
		glVertex3f(60-(i*15),		35		,-30.0);
		glVertex3f(60-(i*15),		27		,-30.0);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(48-(i*15),		16		,-30);
		glVertex3f(48-(i*15),		24		,-30);
		glVertex3f(60-(i*15),		24		,-30);
		glVertex3f(60-(i*15),		16		,-30);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(48-(i*15),		5		,-30);
		glVertex3f(48-(i*15),		13		,-30);
		glVertex3f(60-(i*15),		13		,-30);
		glVertex3f(60-(i*15),		5		,-30);
		glEnd();

	}



    //// jendela belakang +2 ++
	for(int i = 0; i <= 7; i++){

      // Jendela line --------------------------------|||
		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(15-(i*14),		27		,-50.0);
		glVertex3f(15-(i*14),		35		,-50.0);
		glVertex3f(5-(i*14),		35		,-50.0);
		glVertex3f(5-(i*14),		27		,-50.0);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(15-(i*14),		16		,-50);
		glVertex3f(15-(i*14),		24		,-50);
		glVertex3f(5-(i*14),		24		,-50);
		glVertex3f(5-(i*14),		16		,-50);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(15-(i*14),		5		,-50);
		glVertex3f(15-(i*14),		13		,-50);
		glVertex3f(5-(i*14),		13		,-50);
		glVertex3f(5-(i*14),		5		,-50);
		glEnd();

		// Jendela Kaca --------------------------------|||


        glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(15-(i*14),		27		,-50.0);
		glVertex3f(15-(i*14),		35		,-50.0);
		glVertex3f(5-(i*14),		35		,-50.0);
		glVertex3f(5-(i*14),		27		,-50.0);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(15-(i*14),		16		,-50);
		glVertex3f(15-(i*14),		24		,-50);
		glVertex3f(5-(i*14),		24		,-50);
		glVertex3f(5-(i*14),		16		,-50);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(15-(i*14),		5		,-50);
		glVertex3f(15-(i*14),		13		,-50);
		glVertex3f(5-(i*14),		13		,-50);
		glVertex3f(5-(i*14),		5		,-50);
		glEnd();

	}


    //// jendela belakang 3
	for(int i = 0; i <= 2; i++){
         // Jendela line --------------------------------|||
		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(-110-(i*14),		35		,-30.0);
		glVertex3f(-110-(i*14),		42		,-30.0);
		glVertex3f(-122-(i*14),		42		,-30.0);
		glVertex3f(-122-(i*14),		35		,-30.0);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(-110-(i*14),		24		,-30);
		glVertex3f(-110-(i*14),		32		,-30);
		glVertex3f(-122-(i*14),		32		,-30);
		glVertex3f(-122-(i*14),		24		,-30);
		glEnd();

		// Jendela Kaca --------------------------------|||

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(-110-(i*14),		35		,-30.0);
		glVertex3f(-110-(i*14),		42		,-30.0);
		glVertex3f(-122-(i*14),		42		,-30.0);
		glVertex3f(-122-(i*14),		35		,-30.0);
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(-110-(i*14),		24		,-30);
		glVertex3f(-110-(i*14),		32		,-30);
		glVertex3f(-122-(i*14),		32		,-30);
		glVertex3f(-122-(i*14),		24		,-30);
		glEnd();


	}


	//// JENDELAAAAAA belakang Tengah
    for(int i = 0; i <= 7; i++){

      // Jendela line --------------------------------|||
		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(15-(i*14),		42		,-30.0);
		glVertex3f(15-(i*14),		48		,-30.0);
		glVertex3f(5-(i*14),		48		,-30.0);
		glVertex3f(5-(i*14),		42		,-30.0);
		glEnd();

		// Jendela Kaca --------------------------------|||

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(15-(i*14),		42		,-30.0);
		glVertex3f(15-(i*14),		48		,-30.0);
		glVertex3f(5-(i*14),		48		,-30.0);
		glVertex3f(5-(i*14),		42		,-30.0);
		glEnd();
	}

	//belakang ++
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-100.0,0.0,-30.0);
    glVertex3f(-100.0,40.0,-30.0);
    glVertex3f(70.0,40.0,-30.0);
    glVertex3f(70.0,0.0,-30.0);
    glEnd();

    //belakang +2
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-100.0,0.0,-50.0);
    glVertex3f(-100.0,40.0,-50.0);
    glVertex3f(20.0,40.0,-50.0);
    glVertex3f(20.0,0.0,-50.0);
    glEnd();

    //belakang Tengah
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-155.0,40.0,-30.0);
    glVertex3f(-155.0,50.0,-30.0);
    glVertex3f(40.0,50.0,-30.0);
    glVertex3f(40.0,40.0,-30.0);
    glEnd();


    //belakang Tengah 2
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(0.0,40.0,-30.0);
    glVertex3f(0.0,65.0,-30.0);
    glVertex3f(50.0,65.0,-30.0);
    glVertex3f(50.0,40.0,-30.0);
    glEnd();


    //belakang Tengah 2.1
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(0.0,40.0,-25.0);
    glVertex3f(0.0,65.0,-25.0);
    glVertex3f(50.0,65.0,-25.0);
    glVertex3f(50.0,40.0,-25.0);
    glEnd();

    //belakang Tengah 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(0.0,50.0,-30.0);
    glVertex3f(0.0,65.0,-30.0);
    glVertex3f(-12.0,50.0,-30.0);
    glEnd();


    //belakang 2
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-115.0,0.0,-30.0);
    glVertex3f(-115.0,45.0,-30.0);
    glVertex3f(-100.0,45.0,-30.0);
    glVertex3f(-100.0,0.0,-30.0);
    glEnd();

    //belakang 3 ++
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-115.0,13.35,-30.0);
    glVertex3f(-115.0,40.0,-30.0);
    glVertex3f(-155.0,40.0,-30.0);
    glVertex3f(-155.0,13.35,-30.0);
    glEnd();


    //belakang 4
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-153.0,0,-30.0);
    glVertex3f(-153.0,13.35,-30.0);
    glVertex3f(-155.0,13.35,-30.0);
    glVertex3f(-155.0,0,-30.0);
    glEnd();

    //Belakang 5
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-128.0,0,-30);
    glVertex3f(-128.0,13.35,-30);
    glVertex3f(-130.0,13.35,-30);
    glVertex3f(-130.0,0,-30);
    glEnd();

    //belakang Tengah 2.2
    glBegin(GL_TRIANGLES);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(50.0,50.0,-30.0);
    glVertex3f(50.0,40.0,-30.0);
    glVertex3f(60.0,40.0,-30.0);
    glEnd();

    //belakang Tengah 2.3
    glBegin(GL_TRIANGLES);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(50.0,50.0,-25.0);
    glVertex3f(50.0,40.0,-25.0);
    glVertex3f(60.0,40.0,-25.0);
    glEnd();

//-------- KANAN  ----------------------------------------------------------------------------------

    ////jendela kanan
	for(int i = 1; i <= 5; i++){
     // Jendela line --------------------------------|||
		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(0,		27				,25+(i*14));
		glVertex3f(0,		35				,25+(i*14));
		glVertex3f(0,		35				,37+(i*14));
		glVertex3f(0,		27				,37+(i*14));
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(0,		16				,25+(i*14));
		glVertex3f(0,		24				,25+(i*14));
		glVertex3f(0,		24				,37+(i*14));
		glVertex3f(0,		16				,37+(i*14));
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(0,		5				,25+(i*14));
		glVertex3f(0,		13				,25+(i*14));
		glVertex3f(0,		13				,37+(i*14));
		glVertex3f(0,		5				,37+(i*14));
		glEnd();

		// Jendela Kaca --------------------------------|||

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(0,		27				,25+(i*14));
		glVertex3f(0,		35				,25+(i*14));
		glVertex3f(0,		35				,37+(i*14));
		glVertex3f(0,		27				,37+(i*14));
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(0,		16				,25+(i*14));
		glVertex3f(0,		24				,25+(i*14));
		glVertex3f(0,		24				,37+(i*14));
		glVertex3f(0,		16				,37+(i*14));
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(0,		5				,25+(i*14));
		glVertex3f(0,		13				,25+(i*14));
		glVertex3f(0,		13				,37+(i*14));
		glVertex3f(0,		5				,37+(i*14));
		glEnd();

	}


    //// jendela kananZ
	for(int i = 0; i <= 9; i++){
       // Jendela line --------------------------------|||
		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(70,		27				,-25+(i*14));
		glVertex3f(70,		35				,-25+(i*14));
		glVertex3f(70,		35				,-13+(i*14));
		glVertex3f(70,		27				,-13+(i*14));
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(70,		16				,-25+(i*14));
		glVertex3f(70,		24				,-25+(i*14));
		glVertex3f(70,		24				,-13+(i*14));
		glVertex3f(70,		16				,-13+(i*14));
		glEnd();

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(70,		5				,-25+(i*14));
		glVertex3f(70,		13				,-25+(i*14));
		glVertex3f(70,		13				,-13+(i*14));
		glVertex3f(70,		5				,-13+(i*14));
		glEnd();

		// Jendela Kaca --------------------------------|||

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(70,		27				,-25+(i*14));
		glVertex3f(70,		35				,-25+(i*14));
		glVertex3f(70,		35				,-13+(i*14));
		glVertex3f(70,		27				,-13+(i*14));
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(70,		16				,-25+(i*14));
		glVertex3f(70,		24				,-25+(i*14));
		glVertex3f(70,		24				,-13+(i*14));
		glVertex3f(70,		16				,-13+(i*14));
		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(70,		5				,-25+(i*14));
		glVertex3f(70,		13				,-25+(i*14));
		glVertex3f(70,		13				,-13+(i*14));
		glVertex3f(70,		5				,-13+(i*14));
		glEnd();


	}

	//// JENDELAAAAAAAAAAAAkananZ Tengah
    for(int i = 1; i <= 9; i++){

    // Jendela line --------------------------------|||

		glBegin(GL_LINE_LOOP);
		glColor3f(0,1,1);
		glVertex3f(40,		42				,-25+(i*14));
		glVertex3f(40,		48				,-25+(i*14));
		glVertex3f(40,		48				,-13+(i*14));
		glVertex3f(40,		42				,-13+(i*14));
		glEnd();

		// Jendela Kaca --------------------------------|||

        glBegin(GL_QUADS);
		glColor4f(0,1,1,0.2);
		glVertex3f(40,		42				,-25+(i*14));
		glVertex3f(40,		48				,-25+(i*14));
		glVertex3f(40,		48				,-13+(i*14));
		glVertex3f(40,		42				,-13+(i*14));
		glEnd();


	}
	    //kanan ++
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(0.0,40.0,100.0);
    glVertex3f(0.0,0.0,100.0);
    glVertex3f(0.0,0.0,10.0);
    glVertex3f(0.0,40.0,10.0);
    glEnd();


	//kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(0.0,40.0,100.0);
    glVertex3f(0.0,0.0,100.0);
    glVertex3f(0.0,0.0,115.0);
    glVertex3f(0.0,40.0,115.0);
    glEnd();

      //kananZ
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(70.0,40.0,115.0);
    glVertex3f(70.0,0.0,115.0);
    glVertex3f(70.0,0.0,-30.0);
    glVertex3f(70.0,40.0,-30.0);
    glEnd();


        //kananZ +2
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(20.0,40.0,-50.0);
    glVertex3f(20.0,0.0,-50.0);
    glVertex3f(20.0,0.0,-30.0);
    glVertex3f(20.0,40.0,-30.0);
    glEnd();

    //kananZ +2.1
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-100.0,40.0,-50.0);
    glVertex3f(-100.0,0.0,-50.0);
    glVertex3f(-100.0,0.0,-30.0);
    glVertex3f(-100.0,40.0,-30.0);
    glEnd();

      //kananZ Tengah
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(40.0,50.0,115.0);
    glVertex3f(40.0,40.0,115.0);
    glVertex3f(40.0,40.0,-30.0);
    glVertex3f(40.0,50.0,-30.0);
    glEnd();

    //kananZ Tengah tengah
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(40.0,65.0,10.0);
    glVertex3f(40.0,40.0,10.0);
    glVertex3f(40.0,40.0,-30.0);
    glVertex3f(40.0,65.0,-30.0);
    glEnd();

    //kananZ Tengah tengah zzzzzz
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(50.0,65.0,-25.0);
    glVertex3f(50.0,40.0,-25.0);
    glVertex3f(50.0,40.0,-30.0);
    glVertex3f(50.0,65.0,-30.0);
    glEnd();


    //kananZ Tengah tengah
    glBegin(GL_TRIANGLES);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(40.0,65.0,10.0);
    glVertex3f(40.0,40.0,10.0);
    glVertex3f(40.0,40.0,30.0);
    glEnd();


    //kananZ 2
    glBegin(GL_QUADS);
    glColor3f(0.0,0,0);
    glVertex3f(40.0,40.0,100.0);
    glVertex3f(40.0,0.0,100.0);
    glVertex3f(40.0,0.0,115.0);
    glVertex3f(40.0,40.0,115.0);
    glEnd();



//----- kiri -----------------------------------------------------------------------------------------

    //kiri Tengah
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-10.0,50.0,10.0);
    glVertex3f(-10.0,0.0,10.0);
    glVertex3f(-10.0,0.0,-30.0);
    glVertex3f(-10.0,50.0,-30.0);
    glEnd();

    //kiri Tengah
    glBegin(GL_QUADS);
    glColor3f(0,0.7,0);
    glVertex3f(-10.0,50.0,10.0);
    glVertex3f(-10.0,53.0,10.0);
    glVertex3f(-10.0,53.0,-30.0);
    glVertex3f(-10.0,50.0,-30.0);
    glEnd();

    //kiri Tengah 2
    glBegin(GL_QUADS);
    glColor3f(0,0.7,0);
    glVertex3f(0.0,63.0,10.0);
    glVertex3f(-10.0,53.0,10.0);
    glVertex3f(-10.0,53.0,-30.0);
    glVertex3f(0.0,63.0,-30.0);
    glEnd();

    //kiri Tengah 3
    glBegin(GL_QUADS);
    glColor3f(0,0.7,0);
    glVertex3f(0,63.0,10.0);
    glVertex3f(0,65.0,10.0);
    glVertex3f(0,65.0,-30.0);
    glVertex3f(0,63.0,-30.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-100.0,40.0,10.0);
    glVertex3f(-100.0,0.0,10.0);
    glVertex3f(-100.0,0.0,-30.0);
    glVertex3f(-100.0,40.0,-30.0);
    glEnd();

    //kiri2
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-115.0,40.0,10.0);
    glVertex3f(-115.0,0.0,10.0);
    glVertex3f(-115.0,0.0,-30.0);
    glVertex3f(-115.0,40.0,-30.0);
    glEnd();

    //kiri3
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-155.0,40.0,10.0);
    glVertex3f(-155.0,13.35,10.0);
    glVertex3f(-155.0,13.35,-30.0);
    glVertex3f(-155.0,40.0,-30.0);
    glEnd();

    //kiri atap
    glBegin(GL_TRIANGLES);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-155.0,40.0,10.0);
    glVertex3f(-155.0,40.0,-30.0);
    glVertex3f(-155.0,50.05,-30.0);
    glEnd();

    //kiri 3.1
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-155.0,13.35,10.0);
    glVertex3f(-155.0,0,10.0);
    glVertex3f(-155.0,0,-30.0);
    glVertex3f(-155.0,13.35,-30.0);
    glEnd();

        //kiri 3.2
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-153.0,13.35,10.0);
    glVertex3f(-153.0,0,10.0);
    glVertex3f(-153.0,0,-30.0);
    glVertex3f(-153.0,13.35,-30.0);
    glEnd();

    //kiri 3.21
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-128.0,13.35,10.0);
    glVertex3f(-128.0,0,10.0);
    glVertex3f(-128.0,0,-30.0);
    glVertex3f(-128.0,13.35,-30.0);
    glEnd();

        //kiri 3.22
    glBegin(GL_QUADS);
    glColor3f(0.80,0.25,0.32);
    glVertex3f(-130.0,13.35,10.0);
    glVertex3f(-130.0,0,10.0);
    glVertex3f(-130.0,0,-30.0);
    glVertex3f(-130.0,13.35,-30.0);
    glEnd();

//---------- Atas ------------------------------------------------------------------
    float lantai = 13.35;
	int a;
    for(a = 0;a < 3;a++)
    {
    //atas 1
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-155.0,lantai,10.0);
    glVertex3f(0.0,lantai,10.0);
    glVertex3f(0.0,lantai,-30.0);
    glVertex3f(-155.0,lantai,-30.0);
    glVertex3f(0.0,lantai,115.0);
    glVertex3f(70.0,lantai,115.0);
    glVertex3f(70.0,lantai,-30.0);
    glVertex3f(0.0,lantai,-30.0);
    glVertex3f(20.0,lantai,-50.0);
    glVertex3f(-100.0,lantai,-50.0);
    glVertex3f(-100.0,lantai,-30.0);
    glVertex3f(20.0,lantai,-30.0);
    glEnd();
    lantai = lantai + 13.35;
    }

    lantai = lantai - 13.35;
   glBegin(GL_TRIANGLES);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(0.0,lantai,0.0);
    glVertex3f(0.0,lantai,30.0);
    glVertex3f(-30.0,lantai,0);
    glEnd();

    lantai = 0;


     glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-155.0,40.05,10.0);
    glVertex3f(0.0,40.05,10.0);
    glVertex3f(0.0,50.05,-30.0);
    glVertex3f(-155.0,50.05,-30.0);
    glVertex3f(0.0,40.05,115.0);
    glVertex3f(40.0,50.05,115.0);
    glVertex3f(40.0,50.05,-30.0);
    glVertex3f(0.0,40.05,-30.0);
    glEnd();

    //atas Tengah 2.2
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(50.0,50.0,-25.0);
    glVertex3f(50.0,50.0,-30.0);
    glVertex3f(60.0,40.0,-30.0);
    glVertex3f(60.0,40.0,-25.0);
    glEnd();


//------- Bawah --------------------------------------------------------------------

//    bawah
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(-115.0,lantai,10.0);
    glVertex3f(0.0,lantai,10.0);
    glVertex3f(0.0,lantai,-30.0);
    glVertex3f(-115.0,lantai,-30.0);
    glVertex3f(0.0,lantai,115.0);
    glVertex3f(70.0,lantai,115.0);
    glVertex3f(70.0,lantai,-30.0);
    glVertex3f(0.0,lantai,-30.0);
    glVertex3f(20.0,lantai,-50.0);
    glVertex3f(-100.0,lantai,-50.0);
    glVertex3f(-100.0,lantai,-30.0);
    glVertex3f(20.0,lantai,-30.0);
    glEnd();

// Tanah
    glBegin(GL_QUADS);
    glColor3f(0.6,0.6,0.6);
    glVertex3f(200.0,lantai,200.0);
    glVertex3f(-200.0,lantai,200.0);
    glVertex3f(-200.0,lantai,-200.0);
    glVertex3f(200.0,lantai,-200.0);
    glEnd();

}

void tampil(void)
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(0,updown,zupdown,kirikanan,0.0f,0.0f,0.0f,1.0f,0.0f);//untuk mengatur sudut pandang
        glRotatef(xrot,1.0f,0.0f,0.0f);
        glRotatef(yrot,0.0f,1.0f,0.0f);
        kubus();

		glutSwapBuffers();

    }


    void mouse(int button, int state,int x,int y)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            mouseDown = true;
            xdiff += x - yrot;
            ydiff += -y + xrot;
        }
            else
                mouseDown = false;
    }

    void mouseMotion(int x , int y)
    {
        if(mouseDown)
        {
            yrot = x - xdiff;
            xrot = y + ydiff;

            glutPostRedisplay();
        }
    }


void keyboard(unsigned char key,int x,int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zupdown = zupdown-3 ;break;;break;
    case 'd':
    case 'D':
        kirikanan++;break;
    case 's':
    case 'S':
         zupdown = zupdown+3 ;break;
    case 'a':
    case 'A':
        kirikanan--;break;
    case '7':
        glTranslatef(0.0,3.0,0.0);break;
    case '9':
        glTranslatef(0.0,-3.0,0.0);break;
    case '2':
        updown--;break;
    case '8':
        glRotatef(-2.0,1.0,0.0,0.0);break;
    case '6':
        glRotatef(2.0,0.0,1.0,0.0);break;
    case '4':
        glRotatef(-2.0,0.0,1.0,0.0);break;
    case '1':
        updown++;break;
    case '3':
        glRotatef(-2.0,0.0,0.0,1.0);break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();

}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar/tinggi,5.0,500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}

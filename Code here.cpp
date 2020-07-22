
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<windows.h>
#include <stdlib.h>
float zupdown = 3 ;
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
    glVertex3f(50,0,0);
    glVertex3f(-50,0,0);
    glEnd();

    //garis pembantu y
    glBegin(GL_LINE_STRIP);
    glColor3f(0.5,0.5,0.0);
    glVertex3f(0,50,0);
    glVertex3f(0,-50,0);
    glEnd();

    //garis pembantu z
    glBegin(GL_LINE_STRIP);
    glColor3f(0.5,0.5,0.0);
    glVertex3f(0,0,50);
    glVertex3f(0,0,-50);
    glEnd();
//------  Depan -------------------------------------------------------------------------------------
     //depan

    //depanz
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(40.0,-10.0,70.0);
    glVertex3f(40.0,50.0,70.0);
    glVertex3f(0.0,50.0,70.0);
    glVertex3f(0.0,-10.0,70.0);
    glEnd();


//--- Belakang --------------------------------------------------------------------------------------

    //belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-70.0,-10.0,-30.0);
    glVertex3f(-70.0,50.0,-30.0);
    glVertex3f(40.0,50.0,-30.0);
    glVertex3f(40.0,-10.0,-30.0);
    glEnd();
//-------- KANAN  ----------------------------------------------------------------------------------
    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(0.0,50.0,70.0);
    glVertex3f(0.0,-10.0,70.0);
    glVertex3f(0.0,-10.0,10.0);
    glVertex3f(0.0,50.0,10.0);
    glEnd();
      //kananZ
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(40.0,50.0,70.0);
    glVertex3f(40.0,-10.0,70.0);
    glVertex3f(40.0,-10.0,-30.0);
    glVertex3f(40.0,50.0,-30.0);
    glEnd();

//----- kiri -----------------------------------------------------------------------------------------
    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-70.0,50.0,10.0);
    glVertex3f(-70.0,-10.0,10.0);
    glVertex3f(-70.0,-10.0,-30.0);
    glVertex3f(-70.0,50.0,-30.0);
    glEnd();
//---------- Atas ------------------------------------------------------------------
    float lantai = 10.0;
    for(int a = 0;a < 3;a++)
    {
    //atas 1
    glBegin(GL_QUADS);
    glColor3f(0.0,0.5,1.0);
    glVertex3f(-70.0,lantai,10.0);
    glVertex3f(0.0,lantai,10.0);
    glVertex3f(0.0,lantai,-30.0);
    glVertex3f(-70.0,lantai,-30.0);
    glVertex3f(0.0,lantai,70.0);
    glVertex3f(40.0,lantai,70.0);
    glVertex3f(40.0,lantai,-30.0);
    glVertex3f(0.0,lantai,-30.0);
    glEnd();
    lantai = lantai + 20;
    }



//------- Bawah --------------------------------------------------------------------

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.0,1.5,0.0);
    glVertex3f(-70.0,-10.0,10.0);
    glVertex3f(0.0,-10.0,10.0);
    glVertex3f(0.0,-10.0,-30.0);
    glVertex3f(-70.0,-10.0,-30.0);
    glVertex3f(0.0,-10.0,70.0);
    glVertex3f(40.0,-10.0,70.0);
    glVertex3f(40.0,-10.0,-30.0);
    glVertex3f(0.0,-10.0,-30.0);
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

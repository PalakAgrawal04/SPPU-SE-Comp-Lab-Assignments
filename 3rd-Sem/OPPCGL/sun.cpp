#include <math.h>
#include <GL/glut.h>
using namespace std;
float ballX = -0.8f;
float ballY = -0.3f;
float ballZ = -1.2f;
// setting colors
float colR = 5.0;
float colG = 5.0;
float colB = 0.0;
// setting background COLOR
float bgcolR = 0.0;
float bgcolG = 0.0;
float bgcolB = 0.0;
static int flag = 1;
// create sun
void drawsun()
{
    glColor3f(colR, colG, colB);
    glTranslatef(ballX, ballY, ballZ);
    glutSolidSphere(0.1, 30, 30);
}
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void update(int value)
{
    if (flag)
    {
        ballX += 0.001f;
        ballY += 0.0007f;
        colR -= 0.001;
        colG += 0.005;
        bgcolB += 0.001;
        if (ballX > 0.3)
        {
            flag = 0;
        }
    }
    if (!flag)
    {
        ballX += 0.001f;
        ballY -= 0.0007f;
        colR += 0.001;
        colG -= 0.005;
        bgcolB -= 0.001;
        if (ballX < -0.3)
        {
            flag = 1;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(bgcolR, bgcolG, bgcolB, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    drawsun();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("SUN");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
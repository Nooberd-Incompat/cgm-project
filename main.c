#ifdef _WIN32
    #include<windows.h>
#endif
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#define GL_SILENCE_DEPRECATION

#define XMAX 1200
#define YMAX 700
#define SPACESHIP_SPEED 20
#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3

GLint m_viewport[4];
int mButtonPressed = 0;
float mouseX, mouseY;
enum view {INTRO, MENU, INSTRUCTIONS, GAME, GAMEOVER};
enum view viewPage = INTRO; // initial value
int keyStates[256] = {0};
int direction[4] = {0};
int laser1Dir[2] = {0};
int laser2Dir[2] = {0};

int alienLife1 = 100;
int alienLife2 = 100;
int gameOver = 0;
float xOne = 500, yOne = 0;
float xTwo = 500, yTwo = 0;
int laser1 = 0, laser2 = 0;
GLint CI = 0;
GLfloat a[][2] = {0, -50, 70, -50, 70, 70, -70, 70};
GLfloat LightColor[][3] = {1, 1, 0, 0, 1, 1, 0, 1, 0};
GLfloat AlienBody[][2] = {{-4,9}, {-6,0}, {0,0}, {0.5,9}, {0.15,12}, {-14,18}, {-19,10}, {-20,0},{-6,0}};
GLfloat AlienCollar[][2] = {{-9,10.5}, {-6,11}, {-5,12}, {6,18}, {10,20}, {13,23}, {16,30}, {19,39}, {16,38},
                          {10,37}, {-13,39}, {-18,41}, {-20,43}, {-20.5,42}, {-21,30}, {-19.5,23}, {-19,20},
                          {-14,16}, {-15,17},{-13,13},  {-9,10.5}};
GLfloat ALienFace[][2] = {{-6,11}, {-4.5,18}, {0.5,20}, {0.,20.5}, {0.1,19.5}, {1.8,19}, {5,20}, {7,23}, {9,29},
                        {6,29.5}, {5,28}, {7,30}, {10,38},{11,38}, {11,40}, {11.5,48}, {10,50.5},{8.5,51}, {6,52},
                        {1,51}, {-3,50},{-1,51}, {-3,52}, {-5,52.5}, {-6,52}, {-9,51}, {-10.5,50}, {-12,49}, {-12.5,47},
                        {-12,43}, {-13,40}, {-12,38.5}, {-13.5,33},{-15,38},{-14.5,32},  {-14,28}, {-13.5,33}, {-14,28},
                        {-13.8,24}, {-13,20}, {-11,19}, {-10.5,12}, {-6,11}};
GLfloat ALienBeak[][2] = {{-6,21.5}, {-6.5,22}, {-9,21}, {-11,20.5}, {-20,20}, {-14,23}, {-9.5,28}, {-7,27}, {-6,26.5},
                        {-4.5,23}, {-4,21}, {-6,19.5}, {-8.5,19}, {-10,19.5}, {-11,20.5}};

void displayRasterText(float x ,float y ,float z ,char *stringToDisplay) {
    glRasterPos3f(x, y, z);
    for(char* c = stringToDisplay; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 , *c);
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1200, 1200, -700, 700); 
    glMatrixMode(GL_MODELVIEW);
}

void introScreen() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(-425, 490, 0.0, "NMAM INSTITUTE OF TECHNOLOGY");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-700, 385, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(0.0, 0.0, 1.0);
    displayRasterText(-225, 300, 0.0, "A MINI PROJECT ON ");
    glColor3f(1.0, 0.0, 1.0);
    displayRasterText(-125, 225, 0.0, "Space Shooter");
    glColor3f(1.0, 0.7, 0.8);
    displayRasterText(-100, 150, 0.0, "created by");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-130, 80, 0.0, "SHOOTERS");
    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(-800, -100, 0.0, "STUDENT NAMES");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-800, -200, 0.0, "Saurav N Shetty");
    displayRasterText(-800, -285, 0.0, "Rajath R Pai");
    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(500, -100, 0.0, "Under the Guidance of");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(500, -200, 0.0, "Prof X");
    glColor3f(1.0, 0.0, 0.0);
    displayRasterText(-250, -400, 0.0, "Academic Year 2020-2021");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-300, -550, 0.0, "Press ENTER to start the game");
    glFlush();
    glutSwapBuffers();
}

void startScreenDisplay() {
    glLineWidth(10);
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP); // Border
        glVertex2f(-750 ,-500);
        glVertex2f(-750 ,550);
        glVertex2f(750 ,550);
        glVertex2f(750 ,-500);
    glEnd();

    glLineWidth(1);
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON); // START GAME POLYGON
        glVertex2f(-200 ,300);
        glVertex2f(-200 ,400);
        glVertex2f(200 ,400);
        glVertex2f(200 ,300);
    glEnd();

    glBegin(GL_POLYGON); // INSTRUCTIONS POLYGON
        glVertex2f(-200, 50);
        glVertex2f(-200 ,150);
        glVertex2f(200 ,150);
        glVertex2f(200 ,50);
    glEnd();

    glBegin(GL_POLYGON); // QUIT POLYGON
        glVertex2f(-200 ,-200);
        glVertex2f(-200 ,-100);
        glVertex2f(200, -100);
        glVertex2f(200, -200);
    glEnd();

    if(mouseX >= -100 && mouseX <= 100 && mouseY >= 150 && mouseY <= 200) {
        glColor3f(0, 0, 1);
        if(mButtonPressed) {
            alienLife1 = alienLife2 = 100;
            viewPage = GAME;
            mButtonPressed = 0;
        }
    } else
        glColor3f(0, 0, 0);

    displayRasterText(-100, 340, 0.4, "Start Game");

    if(mouseX >= -100 && mouseX <= 100 && mouseY >= 30 && mouseY <= 80) {
        glColor3f(0, 0, 1);
        if(mButtonPressed) {
            viewPage = INSTRUCTIONS;
            mButtonPressed = 0;
        }
    } else
        glColor3f(0, 0, 0);
    
    displayRasterText(-120, 90, 0.4, "Instructions");

    if(mouseX >= -100 && mouseX <= 100 && mouseY >= -90 && mouseY <= -40) {
        glColor3f(0, 0, 1);
        if(mButtonPressed) {
            exit(0);
        }
    } else
        glColor3f(0, 0, 0);
    
    displayRasterText(-100, -160, 0.4, "    Quit");

    glFlush();
    glutSwapBuffers();
}

void instructionScreenDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 0, 0);
    displayRasterText(-300, 550, 0.0, "INSTRUCTIONS");
    glColor3f(1, 1, 1);
    displayRasterText(-850, 400, 0.0, "1. Use Arrow Keys to move the spaceship.");
    displayRasterText(-850, 300, 0.0, "2. Use the Right Control Key to shoot.");
    displayRasterText(-850, 200, 0.0, "3. You have 3 lives. If you are hit 3 times by an enemy, the game will end.");
    displayRasterText(-850, 100, 0.0, "4. Your score will increase with every enemy you destroy.");
    displayRasterText(-850, 0, 0.0, "5. Press 'P' to pause the game.");
    displayRasterText(-850, -100, 0.0, "6. Press 'Q' to quit the game.");
    displayRasterText(-850, -200, 0.0, "7. Defeat all enemies to win the game.");
    glColor3f(1, 0, 0);
    displayRasterText(-850, -400, 0.0, "Press ENTER to go back to the menu");

    glFlush();
    glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
    if (key == 13) { // Enter key
        if (viewPage == INTRO)
            viewPage = MENU;
        else if (viewPage == INSTRUCTIONS || viewPage == GAMEOVER)
            viewPage = MENU;
    }
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (viewPage == INTRO) {
        introScreen();
    } else if (viewPage == MENU) {
        startScreenDisplay();
    } else if (viewPage == INSTRUCTIONS) {
        instructionScreenDisplay();
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 700);
    glutCreateWindow("Space Shooter");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutIdleFunc(display);
    
    glutMainLoop();
    return 0;
}

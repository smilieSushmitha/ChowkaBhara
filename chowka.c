#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int inAbout=0, enter=1;
void *font;
float player2InitialCoinPositions[4][2]={{0,0.525},{-0.075,0.6},{0,0.675},{0.075,0.6}};
float player1InitialCoinPositions[4][2]={{0,-0.675},{-0.075,-0.6},{0,-0.525},{0.075,-0.6}};

float player2FinalCoinPosition[4][2]={{0.0,0.1},{0.1,0.0},{0.0,-0.1},{-0.1,0.0}};
float player1FinalCoinPosition[4][2]={{ -0.1,0.1}, {0.1,0.1},{0.1,-0.1}, {-0.1,-0.1}};

int ply1=1,ply2=0,ral=0,i;

int A[25][2]={{674,562},{779,562},{884,562},{884,457},{884,352},{884,247},{884,142},{779,142},{674,142},{569,142},{464,142},{464,247},{464,352},{464,457},{464,562},{569,562},{569,457},{569,352},{569,247},{674,247},{779,247},{779,352},{779,457},{674,457},{674,352}};
int B[25][2]={{674,142},{569,142},{464,142},{464,247},{464,352},{464,457},{464,562},{569,562},{674,562},{779,562},{884,562},{884,457},{884,352},{884,247},{884,142},{779,142},{779,247},{779,352},{779,457},{674,457},{569,457},{569,352},{569,247},{674,247},{674,352}};

int k1=0,k2=0,k3=0,k4=0;

float d[4][2]={{0,0.525},{-0.075,0.6},{0,0.675},{0.075,0.6}};
float c[4][2]={{0,-0.675},{-0.075,-0.6},{0,-0.525},{0.075,-0.6}};

float a[25][2]={{0.0,-0.60},{0.30,-0.60},{0.60,-0.60},{0.60,-0.30},{0.60,0.0},{0.60,0.30},{0.60,0.60},{0.30,0.60},{0.0,0.60},{-0.30,0.60},{-0.60,0.60},{-0.60,0.30},{-0.60,0.0},{-0.60,-0.3},{-0.60,-0.60},{-0.30,-0.60},{-0.30,-0.30},{-0.30,0.0},{-0.30,0.30},{0.0,0.30},{0.30,0.30},{0.30,0.0},{0.30,-0.30},{0.0,-0.30},{0.0,0.0}};
float b[25][2]={{0.0,0.60},{-0.30,0.60},{-0.60,0.60},{-0.6,0.30},{-0.60,0.0},{-0.60,-0.30},{-0.60,-0.60},{-0.30,-0.60},{0.0,-0.60},{0.30,-0.60},{0.60,-0.60},{0.60,-0.30},{0.60,0.0},{0.60,0.30},{0.60,0.60},{0.30,0.60},{0.30,0.30},{0.30,0.0},{0.30,-0.30},{0.0,-0.30},{-0.30,-0.30},{-0.30,0.0},{-0.30,0.30},{0.0,0.30},{0.0,0.0}};

int p1=0,p2=0;
int l1=0,l2=0,l3=0,l4=0;
int f1=0,f2=0,f3=0,f4=0,g1=0,g2=0,g3=0,g4=0,h1=0,h2=0,h3=0,h4=0,m1=0,m2=0,m3=0,m4=0;	

int s1=0,s2=0,s3=0,diceRoll=0;
void myInit();
void gameInit();
void AboutTheProject(void);
void RulesOfTheGame(void);
void circle();
void mesh();
void loading();
void myReshape(int w,int h);
void wait(void);
void player1Won(void);
void player2Won(void);
void check_cond();
void display();
void player1(int ch);
void player2(int ch);
void dice(int y);
void AboutTheProject(void);
void RulesOfTheGame(void);
void guideLinesNearBoard(void);
void dispPlayerNearBoard(void);  
void playersCoin();
void circle();
void mesh();
void gameBoard();
void options(int id);
void loader();
void chowkaBhara();
void loading(void);
void displayMain(void);
void myMouse(int btn,int state,int x,int y);
void key(unsigned char key,int x,int y);

void myInit()
{
 glClearColor(1,0.8,0.5,1);
 glEnable(GL_DEPTH_TEST);
 glutInitDisplayMode(GLUT_RGBA);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(1355,703);
 glutCreateWindow("CHOWKA-BHARA GAME");
}

void gameInit()
{
 	 c[0][0]=player1InitialCoinPositions[0][0];
 	 c[1][0]=player1InitialCoinPositions[1][0];
 	 c[2][0]=player1InitialCoinPositions[2][0];
 	 c[3][0]=player1InitialCoinPositions[3][0];
 	 
 	 c[0][1]=player1InitialCoinPositions[0][1];
 	 c[1][1]=player1InitialCoinPositions[1][1];
 	 c[2][1]=player1InitialCoinPositions[2][1];
 	 c[3][1]=player1InitialCoinPositions[3][1];
 	 
     d[0][0]=player2InitialCoinPositions[0][0];
 	 d[1][0]=player2InitialCoinPositions[1][0];
 	 d[2][0]=player2InitialCoinPositions[2][0];
 	 d[3][0]=player2InitialCoinPositions[3][0];
 	 
 	 d[0][1]=player2InitialCoinPositions[0][1];
 	 d[1][1]=player2InitialCoinPositions[1][1];
 	 d[2][1]=player2InitialCoinPositions[2][1];
 	 d[3][1]=player2InitialCoinPositions[3][1];
  ply1=1;ply2=0;ral=0;i;
 k1=0;k2=0;k3=0;k4=0;
 p1=0;p2=0;
 l1=0;l2=0;l3=0;l4=0;
 f1=0;f2=0;f3=0;f4=0;
 g1=0;g2=0;g3=0;g4=0;
 h1=0;h2=0;h3=0;h4=0;
 m1=0;m2=0;m3=0;m4=0;	
 s1=0;s2=0;s3=0;diceRoll=0;
 	 
}

void myReshape(int w,int h)
{
 glViewport(0,0,w,h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 if(w<=h)
         glOrtho(-1.0,1.0,-1.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-20.0,20.0);
 else
     glOrtho(-1.0*(GLfloat)w/(GLfloat)h,1.0*(GLfloat)w/(GLfloat)h,-1.0,1.0,-20.0,20.0);
 glMatrixMode(GL_MODELVIEW);
 glutPostRedisplay();
}

void wait(void)
{
 int i,j;
 for(i=1;i<1000;i++)
	 for(j=1;j<9000;j++);
}

void player1and2Won(void)
{
  char *about="\t\t\tCONGRATULATIONS  !\n\n\n         MATCH   DRAWN.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nQ = QUIT   ENTER = RESTART";
  void *en=GLUT_BITMAP_TIMES_ROMAN_24;
  int i;
  float x=-0.4,y=0.6,z=0;

  glPushMatrix();
  glLoadIdentity();

   glColor3f(0.7,0.1,0.1);
  glRasterPos3f(x,y,z);

  for(i=0;about[i]!='\0';i++)
  {
	  if(about[i]=='\n')
	  {   y-=0.08;
		  glRasterPos3f(x,y,z);
	  }
	  if(about[i]=='\t')
	  {
		  x-=0.03;
	  }
	  else
	  { 
	    glutBitmapCharacter(en,about[i]);
	  }
  }
 glPopMatrix(); 

glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
  glVertex2f(-0.15,0.15);
        glVertex2f(0.15,-0.15);
        glVertex2f(0.15,0.15);
        glVertex2f(-0.15,-0.15);
  glEnd();
  
   glBegin(GL_LINE_LOOP);
  glVertex2f(-0.15,0.15);
  glVertex2f(0.15,0.15);
        glVertex2f(0.15,-0.15);
        glVertex2f(-0.15,-0.15);
  glEnd(); 
  
glColor3f(0.7,0.1,0.1);
 glBegin(GL_POINTS);
    glVertex2f(player1FinalCoinPosition[0][0],player1FinalCoinPosition[0][1]);
	glVertex2f(player1FinalCoinPosition[1][0],player1FinalCoinPosition[1][1]);
    glVertex2f(player1FinalCoinPosition[2][0],player1FinalCoinPosition[2][1]);
    glVertex2f(player1FinalCoinPosition[3][0],player1FinalCoinPosition[3][1]);
    
    	glColor3f(0.4,0.1,0.7);
	glVertex2f(player2FinalCoinPosition[0][0],player2FinalCoinPosition[0][1]);
	glVertex2f(player2FinalCoinPosition[1][0],player2FinalCoinPosition[1][1]);
	glVertex2f(player2FinalCoinPosition[2][0],player2FinalCoinPosition[2][1]);
	glVertex2f(player2FinalCoinPosition[3][0],player2FinalCoinPosition[3][1]);
	
    glEnd();
    
  
  
glFlush(); 
enter=1; 

}


void player1Won(void)
{
  char *about="\t\t\tCONGRATULATIONS  !\n\n\nPLAYER  1  WON  THE  GAME.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nQ = QUIT   ENTER = RESTART";
  void *en=GLUT_BITMAP_TIMES_ROMAN_24;
  int i;
  float x=-0.4,y=0.6,z=0;

  glPushMatrix();
  glLoadIdentity();

   glColor3f(0.7,0.1,0.1);
  glRasterPos3f(x,y,z);

  for(i=0;about[i]!='\0';i++)
  {
	  if(about[i]=='\n')
	  {   y-=0.08;
		  glRasterPos3f(x,y,z);
	  }
	  if(about[i]=='\t')
	  {
		  x-=0.03;
	  }
	  else
	  { 
	    glutBitmapCharacter(en,about[i]);
	  }
  }
 glPopMatrix(); 

glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
  glVertex2f(-0.15,0.15);
        glVertex2f(0.15,-0.15);
        glVertex2f(0.15,0.15);
        glVertex2f(-0.15,-0.15);
  glEnd();
  
   glBegin(GL_LINE_LOOP);
  glVertex2f(-0.15,0.15);
  glVertex2f(0.15,0.15);
        glVertex2f(0.15,-0.15);
        glVertex2f(-0.15,-0.15);
  glEnd(); 
  
glColor3f(0.7,0.1,0.1);
 glBegin(GL_POINTS);
    glVertex2f(player1FinalCoinPosition[0][0],player1FinalCoinPosition[0][1]);
	glVertex2f(player1FinalCoinPosition[1][0],player1FinalCoinPosition[1][1]);
    glVertex2f(player1FinalCoinPosition[2][0],player1FinalCoinPosition[2][1]);
    glVertex2f(player1FinalCoinPosition[3][0],player1FinalCoinPosition[3][1]);
	
    glEnd();
    
  
  
glFlush(); 
enter=1; 

}


void player2Won(void)
{

	
  char *about="\t\t\tCONGRATULATIONS  !\n\n\nPLAYER  2  WON  THE  GAME.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nQ = QUIT   ENTER = RESTART";
  void *en=GLUT_BITMAP_TIMES_ROMAN_24;
  int i;
  float x=-0.4,y=0.6,z=0;
  
  glPushMatrix();
  glLoadIdentity();

   glColor3f(0.4,0.1,0.7);
  glRasterPos3f(x,y,z);

  for(i=0;about[i]!='\0';i++)
  {
	  if(about[i]=='\n')
	  {   y-=0.08;
		  glRasterPos3f(x,y,z);
	  }
	  if(about[i]=='\t')
	  {
		  x-=0.03;
	  }
	  else
	  {
	    glutBitmapCharacter(en,about[i]);
	  }
  }
 glPopMatrix();
     glColor3f(0.0,0.0,0.0);
 glBegin(GL_LINES);
  glVertex2f(-0.15,0.15);
        glVertex2f(0.15,-0.15);
        glVertex2f(0.15,0.15);
        glVertex2f(-0.15,-0.15);
  glEnd();
  
   glBegin(GL_LINE_LOOP);
  glVertex2f(-0.15,0.15);
  glVertex2f(0.15,0.15);
        glVertex2f(0.15,-0.15);
        glVertex2f(-0.15,-0.15);
  glEnd(); 
 glBegin(GL_POINTS);	
		glColor3f(0.4,0.1,0.7);
	glVertex2f(player2FinalCoinPosition[0][0],player2FinalCoinPosition[0][1]);
	glVertex2f(player2FinalCoinPosition[1][0],player2FinalCoinPosition[1][1]);
	glVertex2f(player2FinalCoinPosition[2][0],player2FinalCoinPosition[2][1]);
	glVertex2f(player2FinalCoinPosition[3][0],player2FinalCoinPosition[3][1]);
	
    glEnd();
    

glFlush(); 
enter=1; 
}




void check_cond()
{

 	 if(s3==4)
 	 {
	  		  diceRoll=0;
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	    	glClearColor(0,0,0,0);
			glFlush(); 
			player1and2Won(); 
			}
	  		  
     else if(s1==4)
	  {  	diceRoll=0;
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	    	glClearColor(0,0,0,0);
			glFlush(); 
			player1Won();   
      }



      else if(s2==4)
	  {	diceRoll=0;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glFlush();
	player2Won();
      }
}

void display()
{
 	 mesh();	
    glPointSize(25);    
    glBegin(GL_POINTS);

glColor3f(0.7,0.1,0.1);
    glVertex2f(c[0][0],c[0][1]);
	glVertex2f(c[1][0],c[1][1]);
    glVertex2f(c[2][0],c[2][1]);
    glVertex2f(c[3][0],c[3][1]);

	
		glColor3f(0.4,0.1,0.7);
	glVertex2f(d[0][0],d[0][1]);
	glVertex2f(d[1][0],d[1][1]);
	glVertex2f(d[2][0],d[2][1]);
	glVertex2f(d[3][0],d[3][1]);
	
    glEnd();
    glFlush();
	circle();
	check_cond();

}





void player2(int ch)
{
 	 printf("p2=%d\n",p2);
 	 printf("values of l1=%d, l2=%d, l3=%d, l4=%d, m1=%d, m2=%d, m3=%d, m4=%d\n",l1,l2,l3,l4,m1,m2,m3,m4);
 	 glColor3f(1.0,1.0,1.0);
     glPointSize(25);
     
     if((l1==0)&&(m1==0))
     {
	  	printf(" player 2 coin1 @ home \n");
          glBegin(GL_POINTS);
               glVertex2f(player2InitialCoinPositions[0][0],player2InitialCoinPositions[0][1]);
          glEnd();
          glFlush();
     }
     else if(m1==1)
     {
         printf(" player 2 coin 1 rchd EOG \n");
          glBegin(GL_POINTS);
               glVertex2f(0.0,0.1);//need to change
          glEnd();
          glFlush();
     }
     else
     {
	  	 if( (l1!=4) || (l1!=8) || (l1!=12) )
	  	 {
		  	 printf("player 2 coin 1 is in between home and EOG\n\n");
	          glBegin(GL_POINTS);
	               glVertex2f(b[l1][0],b[l1][1]);
	          glEnd();
	          glFlush();
		  }
		  else if(l1==4)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(-0.6,-0.075);
	          glEnd();
	          glFlush();
		  }
		  else if(l1==8)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(-0.075,-0.675);
	          glEnd();
	          glFlush();
		  }
		  else if(l1==12)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(0.6,-0.075);
	          glEnd();
	          glFlush();
		  }
     }
     
     if((l2==0)&&(m2==0))
     {
	  					 printf(" player 2 coin 2 is at home \n");
          glBegin(GL_POINTS);
               glVertex2f(player2InitialCoinPositions[1][0],player2InitialCoinPositions[1][1]);
          glEnd();
          glFlush();
     }
     else if(m2==1)
     {
	  	  printf("player 2 coin 2 rchd EOG\n");
          glBegin(GL_POINTS);
               glVertex2f(0.1,0.0);//need to change
          glEnd();
          glFlush();
     }
     else
     { 
	   	  if( (l2!=4) || (l2!=8) || (l2!=12) )
	  	 {
		  	 printf("player 2 coin 2 is in between home n EOG\n\n");
	          glBegin(GL_POINTS);
	               glVertex2f( b[l2][0],b[l2][1]);
	          glEnd();
	          glFlush();
		  }
		  else if(l2==4)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(-0.675,0);
	          glEnd();
	          glFlush();
		  }
		  else if(l2==8)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(-0.075,-0.525);
	          glEnd();
	          glFlush();
		  }
		  else if(l2==12)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(0.525,0.0);
	          glEnd();
	          glFlush();
		  }
     }
     
     if((l3==0)&&(m3==0))
     {
	  					 printf("player 2 coin 3 is at home\n"); 
          glBegin(GL_POINTS);
               glVertex2f(player2InitialCoinPositions[2][0],player2InitialCoinPositions[2][1]);
          glEnd();
          glFlush();
     }
     else if(m3==1)
     {
	  	  printf("player 2 coin 3 has rchd EOG\n");
          glBegin(GL_POINTS);
               glVertex2f(0.0,-0.1);//need to change
          glEnd();
          glFlush();
     }
     else
     {
	  	 if( (l3!=4) || (l3!=8) || (l3!=12) )
	  	 {
		  	 printf("player 2 coin 3 is in between home n EOG\n\n");
	          glBegin(GL_POINTS);
	               glVertex2f(b[l3][0],b[l3][1]);
	          glEnd();
	          glFlush();
		  }
		  else if(l3==4)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(-0.6,0.075);
	          glEnd();
	          glFlush();
		  }
		  else if(l3==8)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(0.075,-0.525);
	          glEnd();
	          glFlush();
		  }
		  else if(l3==12)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(0.6,0.075);
	          glEnd();
	          glFlush();
		  }
     }
     
     if((l4==0)&&(m4==0))
     {
	  					 printf("player 2 coin 4 is at home\n");
          glBegin(GL_POINTS);
               glVertex2f(player2InitialCoinPositions[3][0],player2InitialCoinPositions[3][0]);
          glEnd();
          glFlush();
     }
     else if(m4==1)
     {
	  	  printf("player 2 coin 4 rchd EOG \n");
          glBegin(GL_POINTS);
               glVertex2f(-0.1,0.0);
          glEnd();
          glFlush();
     }
     else
     {
	  	 if( (l4!=4) || (l4!=8) || (l4!=12) )
	  	 {
		  	 printf("player 2 coin 4 is in between home n EOG");
	          glBegin(GL_POINTS);
	               glVertex2f(b[l4][0],b[l4][1]);
	          glEnd();
	          glFlush();
		  }
		  else if(l4==4)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(-0.525,0.0);
	          glEnd();
	          glFlush();
		  }
		  else if(l4==8)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(0.075,-0.675);
	          glEnd();
	          glFlush();
		  }
		  else if(l4==12)
		  {
		   	   glBegin(GL_POINTS);
	               glVertex2f(0.675,0.0);
	          glEnd();
	          glFlush();
		  }
     }
     if(p1==0 && k1>7 && k2>7 && k3>7 && k4>7 && p2==0 && l1>7 && l2>7 && l3>7 && l4>7)
     {
	  		  s3=4;
	  		  display();
	  		  return;
	  }
    
     if( p1==0 && k1>7 && k2>7 && k3>7 && k4>7 && p2==1 && (l1>7 || (l1==0 && m1==1) ) && (l2>7 || (l2==0 && m2==1) ) && (l3>7|| (l3==0 && m3==1)) && (l4>7|| (l4==0 && m4==1)) )
     {
	  	  printf("no chances of getting hit for player 2\n");
	  	 s2=4;
	  	 display();
	  	 return;
	 }
     if( p2==1 && ( (l1==0 && m1==1) || l1>15 ) && ( (l2==0 && m2==1) || l2>15) && ( (l3==0 && m3==1) || l3>15) && ( (l4==0 && m4==1) || l4>15) && p1==0 && (k1>7 || k1==0 || k1>0) && (k2>7 || k2==0|| k2>0)  && (k3>7|| k3==0 || k3>0) && (k4>7 || k4==0 || k4>0))
     {
	  	  printf("no chances of getting hit for player 2\n");
	  	 s2=4;
	  	 display();
	  	 return;
	 }	
     
     if( ( ( m1==1) || (l1+ral>24) || (p2==0 && l1+ral>15) || (( ( (b[ral+l1][0] == d[1][0] && b[ral+l1][1]==d[1][1]) || (b[ral+l1][0] == d[2][0] && b[ral+l1][1]==d[2][1]) || (b[ral+l1][0] == d[3][0] && b[ral+l1][1]==d[3][1]) )) ) ) && ( ( m2==1) || (l2+ral>24) || (p2==0 && l2+ral>15) || ( ( ( (b[ral+l2][0] == d[0][0] && b[ral+l2][1]==d[0][1]) || (b[ral+l2][0] == d[2][0] && b[ral+l2][1]==d[2][1]) || (b[ral+l2][0] == d[3][0] && a[ral+l2][1]==d[3][1]) )) ) ) && ( ( m3==1) || (l3+ral>24) ||  (p2==0 && l3+ral>15) || ((( (b[ral+l3][0] == d[0][0] && b[ral+l3][1]==d[0][1]) || (b[ral+l3][0] == d[1][0] && b[ral+l3][1]==d[1][1]) || (b[ral+l3][0] == d[3][0] && b[ral+l3][1]==d[3][1]) )) ) ) && ( ( m4==1) || (l4+ral>24) ||  (p2==0 && l4+ral>15) || (( ( (b[ral+l4][0] == d[0][0] && b[ral+l4][1]==d[0][1]) || (b[ral+l4][0] == d[1][0] && b[ral+l4][1]==d[1][1]) || (b[ral+l4][0] == d[2][0] && b[ral+l4][1]==d[2][1]) )) ) )  )
	{
	 	 printf("player 2 dealing with error condition\n");
	   ply1=1;
	   ply2=0;
	  diceRoll=1;
	   display();
	   return;
	}
     if( p2==0 && ch==1 && l1+ral>15)
     {
	    if(( ( (b[ral+l2][0] == d[0][0] && b[ral+l2][1]==d[0][1]) || (b[ral+l2][0] == d[2][0] && b[ral+l2][1]==d[2][1]) || (b[ral+l2][0] == d[3][0] && a[ral+l2][1]==d[3][1]) )) &&( ( (b[ral+l3][0] == d[0][0] && b[ral+l3][1]==d[0][1]) || (b[ral+l3][0] == d[1][0] && b[ral+l3][1]==d[1][1]) || (b[ral+l3][0] == d[3][0] && b[ral+l3][1]==d[3][1]) )) && ( ( (b[ral+l4][0] == d[0][0] && b[ral+l4][1]==d[0][1]) || (b[ral+l4][0] == d[1][0] && b[ral+l4][1]==d[1][1]) || (b[ral+l4][0] == d[2][0] && b[ral+l4][1]==d[2][1]) )))
		{
		 	ply2--;
			ply1++;
			display();
			return;  	 
        }
      } 
      if( p2==0 && ch==2 && l2+ral>15)
     {
	    if(( ( (b[ral+l1][0] == d[1][0] && b[ral+l1][1]==d[1][1]) || (b[ral+l1][0] == d[2][0] && b[ral+l1][1]==d[2][1]) || (b[ral+l1][0] == d[3][0] && b[ral+l1][1]==d[3][1]) )) && ( ( (b[ral+l3][0] == d[0][0] && b[ral+l3][1]==d[0][1]) || (b[ral+l3][0] == d[1][0] && b[ral+l3][1]==d[1][1]) || (b[ral+l3][0] == d[3][0] && b[ral+l3][1]==d[3][1]) )) && ( ( (b[ral+l4][0] == d[0][0] && b[ral+l4][1]==d[0][1]) || (b[ral+l4][0] == d[1][0] && b[ral+l4][1]==d[1][1]) || (b[ral+l4][0] == d[2][0] && b[ral+l4][1]==d[2][1]) )))
		{
		 	ply2--;
			ply1++;
			display();
			return;  	 
        }
      }
      if( p2==0 && ch==3 && l3+ral>15)
     {
	    if(( ( (b[ral+l1][0] == d[1][0] && b[ral+l1][1]==d[1][1]) || (b[ral+l1][0] == d[2][0] && b[ral+l1][1]==d[2][1]) || (b[ral+l1][0] == d[3][0] && b[ral+l1][1]==d[3][1]) )) && ( ( (b[ral+l2][0] == d[0][0] && b[ral+l2][1]==d[0][1]) || (b[ral+l2][0] == d[2][0] && b[ral+l2][1]==d[2][1]) || (b[ral+l2][0] == d[3][0] && a[ral+l2][1]==d[3][1]) )) && ( ( (b[ral+l4][0] == d[0][0] && b[ral+l4][1]==d[0][1]) || (b[ral+l4][0] == d[1][0] && b[ral+l4][1]==d[1][1]) || (b[ral+l4][0] == d[2][0] && b[ral+l4][1]==d[2][1]) )))
		{
		 	ply2--;
			ply1++;
			display();
			return;  	 
        }
      }
      if( p2==0 && ch==4 && l4+ral>15)
     {
	    if(( ( (b[ral+l2][0] == d[0][0] && b[ral+l2][1]==d[0][1]) || (b[ral+l2][0] == d[2][0] && b[ral+l2][1]==d[2][1]) || (b[ral+l2][0] == d[3][0] && a[ral+l2][1]==d[3][1]) )) && ( ( (b[ral+l3][0] == d[0][0] && b[ral+l3][1]==d[0][1]) || (b[ral+l3][0] == d[1][0] && b[ral+l3][1]==d[1][1]) || (b[ral+l3][0] == d[3][0] && b[ral+l3][1]==d[3][1]) )) && ( ( (b[ral+l4][0] == d[0][0] && b[ral+l4][1]==d[0][1]) || (b[ral+l4][0] == d[1][0] && b[ral+l4][1]==d[1][1]) || (b[ral+l4][0] == d[2][0] && b[ral+l4][1]==d[2][1]) )))
		{
		 	ply2--;
			ply1++;
			display();
			return;  	 
        }
      }
    if(m1==1 && ch==1)
    {
	 		 ply2++;
             ply1--;
             display();
             printf("cant move player 2 coin 1 since it has already rchd EOG \n");
			 return;
    }
    else if(m2==1&& ch==2)
    {
	 	  ply2++;
             ply1--;
	 	 printf("cant move player 2 coin 2 since it has already rchd EOG\n");
             display();
            
			 return;
    }
    else if(m3==1&& ch==3)
    {
	 	 ply2++;
             ply1--;
	 	 printf("cant move player 2 coin 3 since it has already rchd EOG \n");
             display();
			 return;
    }
    else if(m4==1&& ch==4)
    {
	 	 printf("cant move player 2 coin 4 since it has already rchd EOG \n");
             ply2++;
             ply1--;
             display();
			 return;
    }
    
    
    
    if((ral+l1>24 && ch==1) || (ral+l1>15 && p2==0 && ch==1))
    { 	
		
	 	 printf("cant move player 2 coin 1 either because it greater than EOG position or because position is beyond outter circle n has not yet got hit \n");
	 	 ply2++;
         ply1--;
         display();
         return;
                            
    }
     else if((ral+l2>24 && ch==2) || (ral+l2>15 && p2==0 && ch==2))
    {
	 	  
	 	  printf("cant move player 2 coin 2 either because it greater than EOG position or because position is beyond outter circle n has not yet got hit \n");
	 	 ply2++;
         ply1--;
         display();
         return;
                            
    }
     else if((ral+l3>24 && ch==3) || (ral+l3>15 && p2==0 && ch==3))
    {
	 	  
	 	 printf("cant move player 2 coin 3 either because it greater than EOG position or because position is beyond outter circle n has not yet got hit \n");
	 	 ply2++;
         ply1--;
         display();
         return;
                            
    }
     else if((ral+l4>24 && ch==4) || (ral+l4>15 && p2==0 && ch==4))
    {
	 	  
	 	 printf("cant move player 2 coin 4 either because it greater than EOG position or because position is beyond outter circle n has not yet got hit \n");
	 	 ply2++;
         ply1--;
         display();
         return;
                            
    }
    
    if(ch==1 && ( (b[ral+l1][0] == d[1][0] && b[ral+l1][1]==d[1][1]) || (b[ral+l1][0] == d[2][0] && b[ral+l1][1]==d[2][1]) || (b[ral+l1][0] == d[3][0] && b[ral+l1][1]==d[3][1]) ))
    {
	 		

             printf("cant move player 2 coin 1 because its new position is containing its own coin\n");
             ply2++;
             ply1--;
             display();
			 return;
    }
    if(ch==2 && ( (b[ral+l2][0] == d[0][0] && b[ral+l2][1]==d[0][1]) || (b[ral+l2][0] == d[2][0] && b[ral+l2][1]==d[2][1]) || (b[ral+l2][0] == d[3][0] && a[ral+l2][1]==d[3][1]) ))
    {
	 		 
             printf("cant move player 2 coin 2 because its new position is containing its own coin\n");
             ply2++;
             ply1--;
             display();
			 return;
    }
    if(ch==3 && ( (b[ral+l3][0] == d[0][0] && b[ral+l3][1]==d[0][1]) || (b[ral+l3][0] == d[1][0] && b[ral+l3][1]==d[1][1]) || (b[ral+l3][0] == d[3][0] && b[ral+l3][1]==d[3][1]) ))
    {
	 		 
			  	  
             printf("cant move player 2 coin 3 because its new position is containing its own coin\n");
             ply2++;
             ply1--;
			 display();
			 return;
    }
    if(ch==4 && ( (b[ral+l4][0] == d[0][0] && b[ral+l4][1]==d[0][1]) || (b[ral+l4][0] == d[1][0] && b[ral+l4][1]==d[1][1]) || (b[ral+l4][0] == d[2][0] && b[ral+l4][1]==d[2][1]) ))
    {
	 		 
			 printf("cant move player 2 coin 4 because its new position is containing its own coin\n");
             ply2++;
             ply1--;
             display();
			 return;
    }
    
    if(ral==8|ral==4)
	  {
				   				   ply2++;
				   				   ply1--;
	   }
     switch(ch)
     {
               case 1:
                      if( ( ral+l1 <=24)&& (m1==0))
                      {
  	                    if( ral+l1 <24)
  	                    {
                          for(i=0; i<4; i++)
                          {
						   		   
                                   if( b[ral+l1][0]==c[i][0] && b[ral+l1][1]==c[i][1])
                                   {	
								   		
                                       if( i==0 )
                                       {
                                           f1=0;
                                           k1=0;
                                           c[0][0]=player1InitialCoinPositions[0][0];
                                           c[0][1]=player1InitialCoinPositions[0][1];
                                           printf("got a player 2 coin 1 replaced player 1 coin 1\n");
                                       } 
                                       if( i==1 )
                                       {
                                           f2=0;
                                           k2=0;
                                           c[1][0]=player1InitialCoinPositions[1][0];
                                           c[1][1]=player1InitialCoinPositions[1][1];
                                           printf("got a player 2 coin 1 replaced player 1 coin 2\n");
                                       } 
                                       if( i==2 )
                                       {
                                           f3=0;
                                           k3=0;
                                           c[2][0]=player1InitialCoinPositions[2][0];
                                           c[2][1]= player1InitialCoinPositions[2][1];
                                           printf("got a player 2 coin 1 replaced player 1 coin 3\n");
                                       } 
                                       if( i==3 )
                                       {
                                           f4=0;
                                           k4=0;
                                           c[3][0]=player1InitialCoinPositions[3][0];
                                           c[3][1]= player1InitialCoinPositions[3][1];
                                           printf("got a player 2 coin 1 replaced player 1 coin 4\n");
                                       }
                                       p2=1;
                                       ply1--;
                                       ply2++; 
                                   }
                                   
                          }
						 }
                          printf("redrawing player 2 coin 1 current pos with white color\n");
                          glColor3f(1.0,1.0,1.0);
                          glPointSize(25);
                          glBegin( GL_POINTS );
                                   glVertex2f( d[0][0], d[0][1]);
                          glEnd();
                          
                          glColor3f(0.7,0.1,0.1);
                          l1=ral+l1;
                          printf("assigning point of player 2 coin 1\n\n");
                          printf("l1=%d\n",l1);
                          d[0][0]=b[l1][0];
                          d[0][1]=b[l1][1];
                         
                      
                      }ch=0;
                      
                      if( l1==24 )
                      {
					   	  printf(" drawing player 2 coin 1 when rchd EOG\n");
					   	  glColor3f(1.0,1.0,1.0);
					   	   glBegin( GL_POINTS );
                                   glVertex2f(d[0][0],d[0][1]);
    					   glEnd();
                          l1=0;
                          m1=1;
                          	glColor3f(0.7,0.1,0.1);
                          glBegin( GL_POINTS );
                                   d[0][0]=0.0;//need to change
                                   d[0][1]=0.1;//need to change
                                   glVertex2f(d[0][0],d[0][1]);
                                   s2++;
                          glEnd();
                      }
                      else if(l1==4)
					  {
					   	   glColor3f(1.0,1.0,1.0);
					   	   glBegin( GL_POINTS );
                                   glVertex2f(d[0][0],d[0][1]);
    					   glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
 	   					           d[0][0]=-0.6;
                                   d[0][1]=-0.075;
                                   glVertex2f(d[0][0],d[0][1]);
				          glEnd();
				          glFlush();
					  }
					  else if(l1==8)
					  {
					   	   glColor3f(1.0,1.0,1.0);
					   	   glBegin( GL_POINTS );
                                   glVertex2f(d[0][0],d[0][1]);
    					   glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
   			                       d[0][0]=-0.075;
                                   d[0][1]=-0.675;
                                   glVertex2f(d[0][0],d[0][1]);		  
				          glEnd();
				          glFlush();
					  }
					  else if(l1==12)
					  {
					   	   glColor3f(1.0,1.0,1.0);
					   	   glBegin( GL_POINTS );
                                   glVertex2f(d[0][0],d[0][1]);
    					   glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
   			                       d[0][0]=0.6;
                                   d[0][1]=-0.075;
                                   glVertex2f(d[0][0],d[0][1]);	
				          glEnd();
				          glFlush();
					  }   
                      diceRoll=1;
                      break;                                    
               case 2:                         
                      if( ( ral+l2 <=24)&& (m2==0))
                      {
					   	  if( ral+l2 <24)
                          {
                             for(i=0; i<4; i++)
                             {
						   		  
                                   if( b[ral+l2][0]==c[i][0] && b[ral+l2][1]==c[i][1])
                                   {
                                   	  
								        if( i==0 )
                                       {
									   		printf("got a player 2 coin 2 replaced player 1 coin 1\n");
                                           f1=0;
                                           k1=0;
                                           c[0][0]=player1InitialCoinPositions[0][0];
                                           c[0][1]=player1InitialCoinPositions[0][1];
                                       } 
                                       if( i==1 )
                                       {
									   	   printf("got a player 2 coin 2 replaced player 1 coin 2\n");
                                           f2=0;
                                           k2=0;
                                           c[1][0]=player1InitialCoinPositions[1][0];
                                           c[1][1]= player1InitialCoinPositions[1][1];
                                       } 
                                       if( i==2 )
                                       {
									   	   printf("got a player 2 coin 2 replaced player 1 coin 3\n");
                                           f3=0;
                                           k3=0;
                                           c[2][0]=player1InitialCoinPositions[2][0];
                                           c[2][1]=player1InitialCoinPositions[2][1];
                                       } 
                                       if( i==3 )
                                       {
									   	   printf("got a player 2 coin 2 replaced player 1 coin 4\n");
                                           f4=0;
                                           k4=0;
                                           c[3][0]=player1InitialCoinPositions[3][0];
                                           c[3][1]=player1InitialCoinPositions[3][1];
                                       }
                                       p2=1;
                                       ply1--;
                                       ply2++; 
                                   }
							   }        
                          }
                          printf("redrawing player 2 coin 2 current pos with white color\n");
                          glColor3f(1.0,1.0,1.0);
                          glPointSize(25);
                          glBegin( GL_POINTS );
                                   glVertex2f( d[1][0], d[1][1]);
                          glEnd();
                          
                          glColor3f(0.7,0.1,0.1);
                          l2=ral+l2;
                          printf("assigning point of player 2 coin 2\n\n");
                           printf("l2=%d\n",l2);
						  d[1][0]=b[l2][0];
                          d[1][1]=b[l2][1];
                        
						if( l2==24)
                      {
					   		printf(" drawing player 2 coin 2 when rchd EOG\n");
                          l2=0;
                          m2=1;
                          glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f(d[1][0],d[1][1]);
                          glEnd();         
                          	glColor3f(0.7,0.1,0.1);
                          glBegin( GL_POINTS );
                                   d[1][0]=0.1;//need to change
                                   d[1][1]=0.0;//need to change
                                   glVertex2f(d[1][0],d[1][1]);
                                   s2++;
                          glEnd();
                      } 
					  else if(l2==4)
					  { 
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f(d[1][0],d[1][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
 	   					           d[1][0]=-0.675;
                                   d[1][1]=0.0;
                                   glVertex2f(d[1][0],d[1][1]);
				          glEnd();
				          glFlush();
					  }
					  else if(l2==8)
					  {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f(d[1][0],d[1][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
					   	           d[1][0]=-0.075;
                                   d[1][1]=-0.525;
                                   glVertex2f(d[1][0],d[1][1]);
				          glEnd();
				          glFlush();
					  }
					  else if(l2==12)
					  {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f(d[1][0],d[1][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
                                   d[1][0]=0.525;
                                   d[1][1]=0.0;
                                   glVertex2f(d[1][0],d[1][1]);
				          glEnd();
				          glFlush();
					  } 
                      
                      }ch=0;
                      
                      diceRoll=1;
                      break;
               case 3:
                      if( ( ral+l3<=24) && (m3==0))
                      {
					   	  if( ral+l3 <24)
                         {
                            for(i=0; i<4; i++)
                            {
						   		  
                                   if( b[ral+l3][0]==c[i][0] && b[ral+l3][1]==c[i][1])
                                   {
								   	  
                                       if( i==0 )
                                       {
									   	   printf("got a player 2 coin 3 replaced player 1 coin 1\n");
                                           f1=0;
                                           k1=0;
                                           c[0][0]=player1InitialCoinPositions[0][0];
                                           c[0][1]= player1InitialCoinPositions[0][1];
                                       } 
                                       if( i==1 )
                                       {
									   	   printf("got a player 2 coin 3 replaced player 1 coin 2\n");
                                           f2=0;
                                           k2=0;
                                           c[1][0]=player1InitialCoinPositions[1][0];
                                           c[1][1]= player1InitialCoinPositions[1][1];
                                       } 
                                       if( i==2 )
                                       {
									   	   printf("got a player 2 coin 3 replaced player 1 coin 3\n");
                                           f3=0;
                                           k3=0;
                                           c[2][0]=player1InitialCoinPositions[2][0];
                                           c[2][1]= player1InitialCoinPositions[2][1];
                                       } 
                                       if( i==3 )
                                       {
									   	   printf("got a player 2 coin 3 replaced player 1 coin 4\n");
                                           f4=0;
                                           k4=0;
                                           c[3][0]=player1InitialCoinPositions[3][0];
                                           c[3][1]=player1InitialCoinPositions[3][1];
                                       }
                                       p2=1; 
                                       ply1--;
                                       ply2++;
                                   }
                                   
                            }
						}
                          printf("redrawing player 2 coin 3 current pos with white color\n");
                          glColor3f(1.0,1.0,1.0);
                          glPointSize(25);
                          glBegin( GL_POINTS );
                                   glVertex2f( d[2][0], d[2][1]);
                          glEnd();
                          
                          glColor3f(0.7,0.1,0.1);
                          l3=ral+l3;
                          printf("assigning point of player 2 coin 3\n\n");
                           printf("l3=%d\n",l3);
						  d[2][0]=b[l3][0];
                          d[2][1]=b[l3][1];
                        if( l3==24)
                      {
                          l3=0;
                          m3=1;
                          printf(" drawing player 2 coin 1 when rchd EOG\n");
                          	glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f(d[2][0],d[2][1]);
                          glEnd();
                          	glColor3f(0.7,0.1,0.1);
                          glBegin( GL_POINTS );
                                   d[2][0]=0.0;
                                   d[2][1]=-0.1;
                                   glVertex2f(d[2][0],d[2][1]);
                                   s2++;
                          glEnd();
                      }
					  else if(l3==4)
					  {
					   	   	glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f(d[2][0],d[2][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   
					   	   glBegin( GL_POINTS );
                                   d[2][0]=-0.6;
                                   d[2][1]=0.075;
                                   glVertex2f(d[2][0],d[2][1]);
				          glEnd();
				          glFlush();
					  }
					  else if(l3==8)
					  {
					   	   	glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f(d[2][0],d[2][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
                                   d[2][0]=0.075;
                                   d[2][1]=-0.525;
                                   glVertex2f(d[2][0],d[2][1]);
				          glEnd();
				          glFlush();
					  }
					  else if(l3==12)
					  {
					   	   	glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f(d[2][0],d[2][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
                                   d[2][0]=0.6;
                                   d[2][1]=0.075;
                                   glVertex2f(d[2][0],d[2][1]);
				          glEnd();
				          glFlush();
					  }  
                      
                      }ch=0;
                      
                      diceRoll=1;
                      break;
               case 4:
                    if( ( ral+l4 <=24)& (m4==0))
                      {
					   	  if( ral+l4 <24)
  	                        {
                          for(i=0; i<4; i++)
                          {
						   		   
                                   if( b[ral+l4][0]==c[i][0] && b[ral+l4][1]==c[i][1])
                                   {
								   	   
                                       if( i==0 )
                                       {
									   	   printf("got a player 2 coin 4 replaced player 1 coin 1\n");
                                           f1=0;
                                           k1=0;
                                           c[0][0]=player1InitialCoinPositions[0][0];
                                           c[0][1]= player1InitialCoinPositions[0][1];
                                       } 
                                       if( i==1 )
                                       {
									   	    printf("got a player 2 coin 4 replaced player 1 coin 2\n");
                                           f2=0;
                                           k2=0;
                                           c[1][0]=player1InitialCoinPositions[1][0];
                                           c[1][1]= player1InitialCoinPositions[1][1];
                                       } 
                                       if( i==2 )
                                       {
									   	    printf("got a player 2 coin 4 replaced player 1 coin 3\n");
                                           f3=0;
                                           k3=0;
                                           c[2][0]=player1InitialCoinPositions[2][0];
                                           c[2][1]= player1InitialCoinPositions[2][1];
                                       } 
                                       if( i==3 )
                                       {
									   	    printf("got a player 2 coin 4 replaced player 1 coin 4\n");
                                           f4=0;
                                           k4=0;
                                           c[3][0]=player1InitialCoinPositions[3][0];
                                           c[3][1]= player1InitialCoinPositions[3][1];
                                       }
                                       p2=1;
                                       ply1--;
                                       ply2++; 
                                   }
                                   
                          }
						  }
                          printf("redrawing player 2 coin 2 current pos with white color\n");
                          glColor3f(1.0,1.0,1.0);
                          glPointSize(25);
                          glBegin( GL_POINTS );
                                   glVertex2f( d[3][0], d[3][1]);
                          glEnd();
                          
                          glColor3f(0.7,0.1,0.1);
                          l4=ral+l4;
                          printf("assigning point of player 2 coin 1\n\n");
                           printf("l4=%d\n",l4);
						  d[3][0]=b[l4][0];
                          d[3][1]=b[l4][1];
                          
                        
                          
                      }ch=0;
                        if( l4==24 )
                      {
					   		 printf(" drawing player 2 coin 1 when rchd EOG\n");
                          l4=0;
                          m4=1;
                          glColor3f(1.0,1.0,1.0);
                           glBegin( GL_POINTS );
                                   glVertex2f(d[3][0],d[3][1]);
                          	glEnd();
							  glColor3f(0.7,0.1,0.1);
                          glBegin( GL_POINTS );
                                   d[3][0]=-0.1;
                                   d[3][1]=0.0;
                                   glVertex2f(d[3][0],d[3][1]);
                                   s2++;
                          glEnd();
                      }
                      
                  else if(l4==4)
					  {
					   			glColor3f(1.0,1.0,1.0);
                           glBegin( GL_POINTS );
                                   glVertex2f(d[3][0],d[3][1]);
                           glEnd();
					   			glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
	   					       d[3][0]=-0.525;
                                   d[3][1]=0.0;
                                   glVertex2f(d[3][0],d[3][1]);
				          glEnd();
				          glFlush();
					  }
					  else if(l4==8)
					  {
					   	   glColor3f(1.0,1.0,1.0);
                           glBegin( GL_POINTS );
                                   glVertex2f(d[3][0],d[3][1]);
                          	glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
					   	           d[3][0]=0.075;
                                   d[3][1]=-0.675;
                                   glVertex2f(d[3][0],d[3][1]);
				          glEnd();
				          glFlush();
					  }
					  else if(l4==12)
					  {
					   	   glColor3f(1.0,1.0,1.0);
                           glBegin( GL_POINTS );
                                   glVertex2f(d[3][0],d[3][1]);
                          	glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	   glBegin(GL_POINTS);
					   	           d[3][0]=0.675;
                                   d[3][1]=0.0;
                                   glVertex2f(d[3][0],d[3][1]);
				          glEnd();
				          glFlush();
					  }
                      
                      diceRoll=1;
                      break;
               
     }
     ch=0;
     display();
}
		 

void player1(int ch)
{
 	 printf("p1=%d\n",p1);
 	 printf("values of k1=%d, k2=%d, k3=%d, k4=%d, h1=%d, h2=%d, h3=%d, h4=%d\n",k1,k2,k3,k4,h1,h2,h3,h4);
     glPointSize(25);
     glColor3f(1.0,1.0,1.0);
     
	 if((k1==0)&&(h1==0))
     {
	  					 printf(" player 1 coin 1 @ home \n");
          glBegin(GL_POINTS);
               glVertex2f(c[0][0],c[0][1]);
          glEnd();
          glFlush();
     }
     else if(h1==1)
     {
	  	  printf(" player 1 coin 1 rchd EOG \n");
          glBegin(GL_POINTS);
               glVertex2f(-0.1,0.1);
          glEnd();
          glFlush();
     }
     else
     {
	  	 if( (k1!=4) || (k1!=8) || (k1!=12) )
	  	 {
		  	 printf("player 1 coin 1 is in between home and EOG\n");
	          glBegin(GL_POINTS);
	               glVertex2f(a[k1][0],a[k1][1]);
	          glEnd();
	          glFlush();
          }
          else if( k1==4 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(0.525,-0.075);
	          glEnd();
	          glFlush();
          }
          else if( k1==8 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(-0.075,0.525);
	          glEnd();
	          glFlush();
          }
          else if( k1==12 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(-0.675,-0.075);
	          glEnd();
	          glFlush();
          }
          
     }
     
     if((k2==0)&&(h2==0))
     {
	  					  printf(" player 1 coin 2 @ home \n");
          glBegin(GL_POINTS);
               glVertex2f(c[1][0],c[1][1]);
          glEnd();
          glFlush();
     }
     else if(h2==1)
     {
	  	  printf(" player 1 coin 2 rchd EOG \n");
          glBegin(GL_POINTS);
               glVertex2f(0.1,0.1);
          glEnd();
          glFlush();
     }
     else
     {
	  	  if( (k2!=4) || (k2!=8) || (k2!=12) )
	  	 {
		  	 printf("player 1 coin 2 is in between home and EOG\n");
	          glBegin(GL_POINTS);
	               glVertex2f( a[k2][0],a[k2][1]);
	          glEnd();
	          glFlush();
          }
          else if( k2==4 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(0.525,0.075);
	          glEnd();
	          glFlush();
          }
          else if( k2==8 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(-0.075,0.675);
	          glEnd();
	          glFlush();
          }
          else if( k2==12 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(-0.675,0.075);
	          glEnd();
	          glFlush();
          }
     }
     
     if((k3==0)&&(h3==0))
     {
	  					 printf(" player 1 coin 3 @ home \n");
          glBegin(GL_POINTS);
               glVertex2f(c[2][0],c[2][1]);
          glEnd();
          glFlush();
     }
     else if(h3==1)
     {
	  	  printf(" player 1 coin 3 rchd EOG \n");
          glBegin(GL_POINTS);
               glVertex2f(0.1,-0.1);
		  glEnd();
          glFlush();
     }
     else
     {
	  	 if( (k3!=4) || (k3!=8) || (k3!=12) )
	  	 {
		  	 printf("player 1 coin 3 is in between home and EOG\n");
	          glBegin(GL_POINTS);
	               glVertex2f(a[k3][0],a[k3][1]);
	          glEnd();
	          glFlush();
          }
           else if( k3==4 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(0.675,0.075);
	          glEnd();
	          glFlush();
          }
          else if( k3==8 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(0.075,0.675);
	          glEnd();
	          glFlush();
          }
          else if( k3==12 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(-0.525,0.075);
	          glEnd();
	          glFlush();
          }
     }
     
     if((k4==0)&&(h4==0))
     {
	  					  printf(" player 1 coin 4 @ home \n");
          glBegin(GL_POINTS);
               glVertex2f(c[3][0],c[3][1]);
          glEnd();
          glFlush();
     }
     else if(h4==1)
     {
	  	   printf(" player 1 coin 4 rchd EOG \n");
          glBegin(GL_POINTS);
               glVertex2f(-0.1,-0.1);
          glEnd();
          glFlush();
     }
     else
     {
	  	 if( (k4!=4) || (k4!=8) || (k4!=12) )
	  	 {
		  	 printf("player 1 coin 4 is in between home and EOG\n");
	          glBegin(GL_POINTS);
	               glVertex2f(a[k4][0],a[k4][1]);
	          glEnd();
	          glFlush();
         }
          else if( k4==4 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(0.675,-0.075);
	          glEnd();
	          glFlush();
          }
          else if( k4==8 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(0.075,0.525);
	          glEnd();
	          glFlush();
          }
          else if( k4==12 )
          {
		   	    glBegin(GL_POINTS);
	               glVertex2f(-0.525,-0.075);
	          glEnd();
	          glFlush();
          }
     }
     if(ply2==0 && k1>15 && k2>15 && k3>15 && k4>15)
	 {
	  		   s1=4;
				 display();
				 return;
     } 
     if(p1==0 && k1>7 && k2>7 && k3>7 && k4>7 && p2==0 && l1>7 && l2>7 && l3>7 && l4>7)
     {
	  		  s3=4;
	  		  display();
	  		  return;
	  }
	  if( p1==1 && (k1>7 || (k1==0 && h1==1)) && (k2>7|| (k2==0 && h2==1)) && (k3>7|| (k3==0 && h3==1)) && (k4>7|| (k4==0 && h4==1)) && p2==0 && l1>7 && l2>7 && l3>7 && l4>7)
     {
	  	 printf("no chances of getting hit for player 2\n");
	  	 s1=4;
	  	 display();
	  	 return;
	 }
     if( p1==1 && ( (k1==0 && h1==1) || k1>15 ) && ( (k2==0 && h2==1) || k2>15) && ( (k3==0 && h3==1) || k3>15) && ( (k4==0 && h4==1) || k4>15) && p2==0 && (l1>7 || l1==0 || l1>0) && (l2>7 || l2==0|| l2>0)  && (l3>7|| l3==0 || l3>0) && (l4>7 || l4==0 || l4>0))
     {
	  	 printf("no chances of getting hit for player 2\n");
	  	 s1=4;
	  	 display();
	  	 return;
	 }
     
   if(((h1==1) || (k1+ral>24) || (k1+ral>15 & p1==0) || ((( ( (a[ral+k1][0] == c[1][0] && a[ral+k1][1]==c[1][1]) || (a[ral+k1][0] == c[2][0] && a[ral+k1][1]==c[2][1]) || (a[ral+k1][0] == c[3][0] && a[ral+k1][1]==c[3][1]) ))))) && ((h2==1) || (k2+ral>24) || (k2+ral>15 & p1==0) || ((( ( (a[ral+k2][0] == c[0][0] && a[ral+k2][1]==c[0][1]) || (a[ral+k2][0] == c[2][0] && a[ral+k2][1]==c[2][1]) || (a[ral+k2][0] == c[3][0] && a[ral+k2][1]==c[3][1]) ))))) && ((h3==1) || (k3+ral>24) || (k3+ral>15 & p1==0) || (( ( (a[ral+k3][0] == c[0][0] && a[ral+k3][1]==c[0][1]) || (a[ral+k3][0] == c[1][0] && a[ral+k3][1]==c[1][1]) || (a[ral+k3][0] == c[3][0] && a[ral+k3][1]==c[3][1]) ))) ) && ((h4==1) || (k4+ral>24) || (k4+ral>15 & p1==0) || (( ( (a[ral+k4][0] == c[0][0] && a[ral+k4][1]==c[0][1]) || (a[ral+k4][0] == c[1][0] && a[ral+k4][1]==c[1][1]) || (a[ral+k4][0] == c[2][0] && a[ral+k4][1]==c[2][1]) )))) )
	{
      printf("player 1 dealing with error conditions\n");	 		   
	  ply1=0;
	  ply2=1;
	  diceRoll=1;
	  display();
	  return;
	} 
     
     
     if(p1==0 && k1+ral>15)
     {
	  		  if(( ( (a[ral+k2][0] == c[0][0] && a[ral+k2][1]==c[0][1]) || (a[ral+k2][0] == c[2][0] && a[ral+k2][1]==c[2][1]) || (a[ral+k2][0] == c[3][0] && a[ral+k2][1]==c[3][1]) )) && ( ( (a[ral+k3][0] == c[0][0] && a[ral+k3][1]==c[0][1]) || (a[ral+k3][0] == c[1][0] && a[ral+k3][1]==c[1][1]) || (a[ral+k3][0] == c[3][0] && a[ral+k3][1]==c[3][1]) )) && ( ( (a[ral+k4][0] == c[0][0] && a[ral+k4][1]==c[0][1]) || (a[ral+k4][0] == c[1][0] && a[ral+k4][1]==c[1][1]) || (a[ral+k4][0] == c[2][0] && a[ral+k4][1]==c[2][1]) )))
	  		  {
			   	  ply1--;
		  		  ply2++;
		  		  display();
		  		  return;
			  }
     }
     if(p1==0 && k2+ral>15)
     {
	  		  if(( ( (a[ral+k1][0] == c[1][0] && a[ral+k1][1]==c[1][1]) || (a[ral+k1][0] == c[2][0] && a[ral+k1][1]==c[2][1]) || (a[ral+k1][0] == c[3][0] && a[ral+k1][1]==c[3][1]) )) && ( ( (a[ral+k3][0] == c[0][0] && a[ral+k3][1]==c[0][1]) || (a[ral+k3][0] == c[1][0] && a[ral+k3][1]==c[1][1]) || (a[ral+k3][0] == c[3][0] && a[ral+k3][1]==c[3][1]) )) && ( ( (a[ral+k4][0] == c[0][0] && a[ral+k4][1]==c[0][1]) || (a[ral+k4][0] == c[1][0] && a[ral+k4][1]==c[1][1]) || (a[ral+k4][0] == c[2][0] && a[ral+k4][1]==c[2][1]) )))
	  		  {
			   	  ply1--;
		  		  ply2++;
		  		  display();
		  		  return;
			  }
     }
     if(p1==0 && k3+ral>15)
     {
	  		  if(( ( (a[ral+k1][0] == c[1][0] && a[ral+k1][1]==c[1][1]) || (a[ral+k1][0] == c[2][0] && a[ral+k1][1]==c[2][1]) || (a[ral+k1][0] == c[3][0] && a[ral+k1][1]==c[3][1]) )) && ( ( (a[ral+k2][0] == c[0][0] && a[ral+k2][1]==c[0][1]) || (a[ral+k2][0] == c[2][0] && a[ral+k2][1]==c[2][1]) || (a[ral+k2][0] == c[3][0] && a[ral+k2][1]==c[3][1]) )) && ( ( (a[ral+k4][0] == c[0][0] && a[ral+k4][1]==c[0][1]) || (a[ral+k4][0] == c[1][0] && a[ral+k4][1]==c[1][1]) || (a[ral+k4][0] == c[2][0] && a[ral+k4][1]==c[2][1]) )))
	  		  {
			   	  ply1--;
		  		  ply2++;
		  		  display();
		  		  return;
			  }
     }
     if(p1==0 && k4+ral>15)
     {
	  		  if(( ( (a[ral+k2][0] == c[0][0] && a[ral+k2][1]==c[0][1]) || (a[ral+k2][0] == c[2][0] && a[ral+k2][1]==c[2][1]) || (a[ral+k2][0] == c[3][0] && a[ral+k2][1]==c[3][1]) )) && ( ( (a[ral+k3][0] == c[0][0] && a[ral+k3][1]==c[0][1]) || (a[ral+k3][0] == c[1][0] && a[ral+k3][1]==c[1][1]) || (a[ral+k3][0] == c[3][0] && a[ral+k3][1]==c[3][1]) )) && ( ( (a[ral+k4][0] == c[0][0] && a[ral+k4][1]==c[0][1]) || (a[ral+k4][0] == c[1][0] && a[ral+k4][1]==c[1][1]) || (a[ral+k4][0] == c[2][0] && a[ral+k4][1]==c[2][1]) )))
	  		  {
			   	  ply1--;
		  		  ply2++;
		  		  display();
		  		  return;
			  }
     }
    if(h1==1 && ch==1)
    {
	 	 printf("cant move player 1 coin 1 since it has already rchd EOG \n");
         ply1++;
         ply2--;
         display();
         return;
    }
    else if(h2==1&& ch==2)
    {
	 	 printf("cant move player 1 coin 2 since it has already rchd EOG \n");
         ply1++;
         ply2--;
         display();
         return;
     }
    else if(h3==1&& ch==3)
    {
	 	 printf("cant move player 1 coin 3 since it has already rchd EOG \n");
         ply1++;
         ply2--;
         display();
         return;
    }
    else if(h4==1&& ch==4)
    {
	 	 printf("cant move player 1 coin 4 since it has already rchd EOG \n");
         ply1++;
         ply2--;
         display();
         return;
    }
    
	 
    if((ral+k1>24 && ch==1) || (ral+k1>15 && p1==0 && ch==1))
    {
	 	 
	 	printf("cant move player 1 coin 1 either because it greater than EOG position or because position is beyond outter circle n has not yet got hit \n");	  
	 	 ply1++;
	 	 ply2--;
        display();
		return;                   
    }
    else if((ral+k2>24 && ch==2) || (ral+k2>15 && p1==0 && ch==2))
    {
	 	 
	 	 printf("cant move player 1 coin 2 either because it greater than EOG position or because position is beyond outter circle n has not yet got hit \n");
	 	  ply1++;
	 	 ply2--;
        display();
		return;                   
    }
    else if((ral+k3>24 && ch==3) || (ral+k3>15 && p1==0 && ch==3))
    {
	 	 
	 	 printf("cant move player 1 coin 3 either because it greater than EOG position or because position is beyond outter circle n has not yet got hit \n");
	 	  ply1++;
	 	 ply2--;
        display();
		return;                   
    }
    else if((ral+k4>24 && ch==4) || (ral+k4>15 && p1==0 && ch==4))
    {
	 	 
	 	 printf("cant move player 1 coin 4 either because it greater than EOG position or because position is beyond outter circle n has not yet got hit \n");
	 	  ply1++;
	 	 ply2--;
        display();
		return;                   
    }
    
    if((ch==1 && ( (a[ral+k1][0] == c[1][0] && a[ral+k1][1]==c[1][1]) || (a[ral+k1][0] == c[2][0] && a[ral+k1][1]==c[2][1]) || (a[ral+k1][0] == c[3][0] && a[ral+k1][1]==c[3][1]) )))
    {
	 		printf("cant move player 1 coin 1 because its new position is containing its own coin\n");
			  ply1++;
        	  ply2--;
   			  display();
             return;
    }
    if((ch==2 && ( (a[ral+k2][0] == c[0][0] && a[ral+k2][1]==c[0][1]) || (a[ral+k2][0] == c[2][0] && a[ral+k2][1]==c[2][1]) || (a[ral+k2][0] == c[3][0] && a[ral+k2][1]==c[3][1]) )))
    {
	 		  printf("cant move player 1 coin 2 because its new position is containing its own coin\n");
			ply1++;
         ply2--;
         display();
			 return;
    }
    if(ch==3 && ( (a[ral+k3][0] == c[0][0] && a[ral+k3][1]==c[0][1]) || (a[ral+k3][0] == c[1][0] && a[ral+k3][1]==c[1][1]) || (a[ral+k3][0] == c[3][0] && a[ral+k3][1]==c[3][1]) ))
    {
	 		  printf("cant move player 1 coin 3 because its new position is containing its own coin\n");
			 ply1++;
         ply2--;	
         display();
			 return;
    }
    if(ch==4 && ( (a[ral+k4][0] == c[0][0] && a[ral+k4][1]==c[0][1]) || (a[ral+k4][0] == c[1][0] && a[ral+k4][1]==c[1][1]) || (a[ral+k4][0] == c[2][0] && a[ral+k4][1]==c[2][1]) ))
    {
	 		  printf("cant move player 1 coin 4 because its new position is containing its own coin\n");
			 ply1++;
         ply2--;
         display();
			 return;
    }
    
    if(ral==8|ral==4)
		 		  {
				   				   ply1++;
				   				   ply2--;
				   }
     switch(ch)
     {
               case 1:
                      if( ( ral+k1 <=24) && (h1==0))
                      {
					   	  if( ral+k1 <24)
  	                        {
                          for(i=0; i<4; i++)
                          {
                                   if( a[ral+k1][0]==d[i][0] && a[ral+k1][1]==d[i][1])
                                   {
                                       if( i==0 )
                                       {
									   	   printf("got a player 1 coin 1 replaced player 2 coin 1\n");
                                           g1=0;
                                           l1=0;
                                           d[0][0]= player2InitialCoinPositions[0][0];
                                           d[0][1]=  player2InitialCoinPositions[0][1];
                                       } 
                                       if( i==1 )
                                       {
									   	   printf("got a player 1 coin 1 replaced player 2 coin 2\n");
                                           g2=0;
                                           l2=0;
                                           d[1][0]= player2InitialCoinPositions[1][0];
                                           d[1][1]=  player2InitialCoinPositions[1][1];
                                       } 
                                       if( i==2 )
                                       {
									   	   printf("got a player 1 coin 1 replaced player 2 coin 3\n");
                                           g3=0;
                                           l3=0;
                                           d[2][0]=player2InitialCoinPositions[2][0];
                                           d[2][1]= player2InitialCoinPositions[2][1];
                                       } 
                                       if( i==3 )
                                       {
									   	   printf("got a player 1 coin 1 replaced player 2 coin 4\n");
                                           g4=0;
                                           l4=0;
                                           d[3][0]=player2InitialCoinPositions[3][0];
                                           d[3][1]= player2InitialCoinPositions[3][1];
                                       }
                                       p1=1;
	                                   ply1++;
                                       ply2--; 
                                   }
                                   
                          }
						  }
                          printf("redrawing player 1 coin 1 current pos with white color\n");
                          glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                          glVertex2f(c[0][0], c[0][1]);
                          glEnd();
                          
                          glColor3f(0.7,0.1,0.1);
                          k1=ral+k1;
                         printf("assigning point of player 1 coin 1\n");
                         printf("k1=%d\n",k1);
                          c[0][0]=a[k1][0];
                          c[0][1]=a[k1][1];
                          
                      }ch=0;
                      if( k1==24 )
                      {
					   	   printf(" drawing player 1 coin 1 when rchd EOG\n");
                          k1=0;
                          h1=1;
                          glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                          glVertex2f(c[0][0], c[0][1]);
                          glEnd();
                          glColor3f(0.7,0.1,0.1); 
						  glBegin( GL_POINTS );
                                   c[0][0]=-0.1;
                                   c[0][1]=0.1;
                                   glVertex2f(c[0][0],c[0][1]);
                                   s1++;
                          glEnd();
                      }
                      else if( k1==4 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                          glVertex2f(c[0][0], c[0][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
                                   c[0][0]=0.525;
                                   c[0][1]=-0.075;
                                   glVertex2f(c[0][0],c[0][1]);
				          glEnd();
				          glFlush();
			          }
			          else if( k1==8 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                          glVertex2f(c[0][0], c[0][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
                                   c[0][0]=-0.075;
                                   c[0][1]=0.525;
                                   glVertex2f(c[0][0],c[0][1]);
				          glEnd();
				          glFlush();
			          }
			          else if( k1==12 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                          glVertex2f(c[0][0], c[0][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
                                   c[0][0]=-0.675;
                                   c[0][1]=-0.075;
                                   glVertex2f(c[0][0],c[0][1]);
				          glEnd();
				          glFlush();
			          }
                      diceRoll=1;
                      break;                                    
               case 2:                         
                      if( ( ral+k2 <=24) && (h2==0))
                      {
					   	  if( ral+k2 <24)
  	                        {
                          for(i=0; i<4; i++)
                          {
                                   if( a[ral+k2][0]==d[i][0] && a[ral+k2][1]==d[i][1])
                                   {
                                       if( i==0 )
                                       {
									   	   printf("got a player 1 coin 2 replaced player 2 coin 1\n");
                                           g1=0;
                                           l1=0;
                                           d[0][0]=player2InitialCoinPositions[0][0];
                                           d[0][1]= player2InitialCoinPositions[0][1];
                                       } 
                                       if( i==1 )
                                       {
									   	    printf("got a player 1 coin 2 replaced player 2 coin 2\n");
                                           g2=0;
                                           l2=0;
                                           d[1][0]=player2InitialCoinPositions[1][0];
                                           d[1][1]= player2InitialCoinPositions[1][1];
                                       } 
                                       if( i==2 )
                                       {
									   	    printf("got a player 1 coin 2 replaced player 2 coin 3\n");
                                           g3=0;
                                           l3=0;
                                           d[2][0]=player2InitialCoinPositions[2][0];
                                           d[2][1]=player2InitialCoinPositions[2][1];
                                       } 
                                       if( i==3 )
                                       {
									   	    printf("got a player 1 coin 2 replaced player 2 coin 4\n");
                                           g4=0;
                                           l4=0;
                                           d[3][0]=player2InitialCoinPositions[3][0];
                                           d[3][1]= player2InitialCoinPositions[3][1];
                                       }
                                       p1=1;
                                       ply1++;
                                       ply2--; 
                                   }
                                   
                          }
						  }
                          printf("redrawing player 1 coin 2 current pos with white color\n");
                          glColor3f(1.0,1.0,1.0);
                          glPointSize(25);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[1][0], c[1][1]);
                          glEnd();
                          
                          glColor3f(0.7,0.1,0.1);
                          k2=ral+k2;
                          printf("assigning point of player 1 coin 2\n\n");
                          printf("k2=%d\n",k2);
						  c[1][0]=a[k2][0];
                          c[1][1]=a[k2][1];
                          
                      }ch=0;
                      if( k2==24 )
                      {
					   	  printf(" drawing player 1 coin 2 when rchd EOG\n");
                          k2=0;
                          h2=1;
                          glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[1][0], c[1][1]);
                          glEnd();
                          glColor3f(0.7,0.1,0.1);
                          glBegin( GL_POINTS );
                                   c[1][0]=0.1;
                                   c[1][1]=0.1;
                                   glVertex2f(c[1][0],c[1][1]);
                                   s1++;
                          glEnd();
                      }
                      else if( k2==4 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[1][0], c[1][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
                                   c[1][0]=0.525;
                                   c[1][1]=0.075;
                                   glVertex2f(c[1][0],c[1][1]);
				          glEnd();
				          glFlush();
			          }
			          else if( k2==8 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[1][0], c[1][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
                                   c[1][0]=-0.075;
                                   c[1][1]=0.675;
                                   glVertex2f(c[1][0],c[1][1]);
				          glEnd();
				          glFlush();
			          }
			          else if( k2==12 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[1][0], c[1][1]);
                          glEnd();
					   	   glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
                                   c[1][0]=-0.675;
                                   c[1][1]=0.075;
                                   glVertex2f(c[1][0],c[1][1]);
				          glEnd();
				          glFlush();
			          }

                      diceRoll=1;
                      break;
               case 3:
                      if( ( ral+k3 <=24) && (h3==0))
                      {
					   	  if( ral+k3 <24)
  	                        {
                          for(i=0; i<4; i++)
                          {
                                   if( a[ral+k3][0]==d[i][0] && a[ral+k3][1]==d[i][1])
                                   {
                                       if( i==0 )
                                       {
									   	   printf("got a player 1 coin 3 replaced player 2 coin 1\n");
                                           g1=0;
                                           l1=0;
                                           d[0][0]=player2InitialCoinPositions[0][0];
                                           d[0][1]=player2InitialCoinPositions[0][1];
                                       } 
                                       if( i==1 )
                                       {
									   	   printf("got a player 1 coin 3 replaced player 2 coin 2\n");
                                           g2=0;
                                           l2=0;
                                           d[1][0]=player2InitialCoinPositions[1][0];
                                           d[1][1]= player2InitialCoinPositions[1][1];
                                       } 
                                       if( i==2 )
                                       {
									   	   printf("got a player 1 coin 3 replaced player 2 coin 3\n");
                                           g3=0;
                                           l3=0;
                                           d[2][0]=player2InitialCoinPositions[2][0];
                                           d[2][1]= player2InitialCoinPositions[2][1];
                                       } 
                                       if( i==3 )
                                       {
									   	   printf("got a player 1 coin 3 replaced player 2 coin 4\n");
                                           g4=0;
                                           l4=0;
                                           d[3][0]=player2InitialCoinPositions[3][0];
                                           d[3][1]= player2InitialCoinPositions[3][1];
                                       }
                                       p1=1; 
                                       ply1++;
                                       ply2--;
                                   }
					          }      
                          }
                          printf("redrawing player 1 coin 3 current pos with white color\n");
                          glColor3f(1.0,1.0,1.0);
                          glPointSize(25);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[2][0], c[2][1]);
                          glEnd();
                          
                          glColor3f(0.7,0.1,0.1);
                          k3=ral+k3;
                          printf("assigning point of player 1 coin 3\n\n");
                          printf("k3=%d\n",k3);
						  c[2][0]=a[k3][0];
                          c[2][1]=a[k3][1];
                          
                      
                      }ch=0;
                      if( k3==24 )
                      {
					   	  printf(" drawing player 1 coin 3 when rchd EOG\n");
                          k3=0;
                          h3=1;
                          glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[2][0], c[2][1]);
                          glEnd();
                          glColor3f(0.7,0.1,0.1);
                          glBegin( GL_POINTS );
                                   c[2][0]=0.1;
                                   c[2][1]=-0.1;
                                   glVertex2f(c[2][0],c[2][1]);
                                   s1++;
                          glEnd();
                      }
                      else if( k3==4 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[2][0], c[2][1]);
                          glEnd();
                          glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
					   	    	   c[2][0]=0.675;
                                   c[2][1]=0.075;
                                   glVertex2f(c[2][0],c[2][1]);
				          glEnd();
				          glFlush();
			          }
			          else if( k3==8 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[2][0], c[2][1]);
                          glEnd();
                          glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
				                    c[2][0]=0.075;
                                   c[2][1]=0.675;
                                   glVertex2f(c[2][0],c[2][1]);
				          glEnd();
				          glFlush();
			          }
			          else if( k3==12 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[2][0], c[2][1]);
                          glEnd();
                          glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
 	    				           c[2][0]=-0.525;
                                   c[2][1]=0.075;
                                   glVertex2f(c[2][0],c[2][1]);
				          glEnd();
				          glFlush();
			          }
                      diceRoll=1;
                      break;
               case 4:
                    if( ( ral+k4 <=24) && (h4==0))
                      {
					   	  if( ral+k4 <24)
  	                        {
                          for(i=0; i<4; i++)
                          {
                                   if( a[ral+k4][0]==d[i][0] && a[ral+k4][1]==d[i][1])
                                   {
                                       if( i==0 )
                                       {
									   	   printf("got a player 1 coin 4 replaced player 2 coin 1\n");
                                           g1=0;
                                           l1=0;
                                           d[0][0]=player2InitialCoinPositions[0][0];
                                           d[0][1]= player2InitialCoinPositions[0][1];
                                       } 
                                       if( i==1 )
                                       {
									   	   printf("got a player 1 coin 4 replaced player 2 coin 2\n");
                                           g2=0;
                                           l2=0;
                                           d[1][0]=player2InitialCoinPositions[1][0];
                                           d[1][1]= player2InitialCoinPositions[1][1];
                                       } 
                                       if( i==2 )
                                       {
									   	   printf("got a player 1 coin 4 replaced player 2 coin 3\n");
                                           g3=0;
                                           l3=0;
                                           d[2][0]=player2InitialCoinPositions[2][0];
                                           d[2][1]= player2InitialCoinPositions[2][1];
                                       } 
                                       if( i==3 )
                                       {
									   	   printf("got a player 1 coin 4 replaced player 2 coin 4\n");
                                           g4=0;
                                           l4=0;
                                           d[3][0]=player2InitialCoinPositions[3][0];
                                           d[3][1]= player2InitialCoinPositions[3][1];
                                       }
                                       p1=1;
                                       ply1++;
                                       ply2--;
                                   }
					          }         
                          }
                          printf("redrawing player 1 coin 4 current pos with white color\n");
                          glColor3f(1.0,1.0,1.0);
                          glPointSize(25);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[3][0], c[3][1]);
                          glEnd();
                          
                          glColor3f(0.7,0.1,0.1);
                          k4=ral+k4;
                           printf("assigning point of player 1 coin 4\n\n");
                          printf("k4=%d\n",k4);
						  c[3][0]=a[k4][0];
                          c[3][1]=a[k4][1];
                          
                      
                      }ch=0;
                      if( k4==24 )
                      {
					   	   printf(" drawing player 1 coin 4 when rchd EOG\n");
                          k4=0;
                          h4=1;
                          glColor3f(1.0,1.0,1.0);
                          glBegin( GL_POINTS );
                                   glVertex2f( c[3][0], c[3][1]);
                          glEnd();
                          
                          glColor3f(0.7,0.1,0.1);
                          glBegin( GL_POINTS );
                                   c[3][0]=-0.1;
                                   c[3][1]=-0.1;
                                   glVertex2f(c[3][0],c[3][1]);
                                   s1++;
                          glEnd();
                      }
                       else if( k4==4 )
			          {
						glColor3f(1.0,1.0,1.0);
			                          glBegin( GL_POINTS );
			                                   glVertex2f( c[3][0], c[3][1]);
			                          glEnd();
							
					   	glColor3f(0.7,0.1,0.1);
						    glBegin(GL_POINTS);
			                                   c[3][0]=0.675;
			                                   c[3][1]=-0.075;
			                                   glVertex2f(c[3][0],c[3][1]);
				          glEnd();
				          glFlush();
			          }
			          else if( k4==8 )
			          {
					glColor3f(1.0,1.0,1.0);
			                          glBegin( GL_POINTS );
			                                   glVertex2f( c[3][0], c[3][1]);
			                          glEnd();
						glColor3f(0.7,0.1,0.1);
					   	    glBegin(GL_POINTS);
			                                   c[3][0]=0.075;
			                                   c[3][1]=0.525;
			                                   glVertex2f(c[3][0],c[3][1]);
				          glEnd();
				          glFlush();
			          }
			          else if( k4==12 )
			          {
					   	   glColor3f(1.0,1.0,1.0);
			                glBegin( GL_POINTS );
                              glVertex2f( c[3][0], c[3][1]);
                          glEnd();
						glColor3f(0.7,0.1,0.1);
				   	    glBegin(GL_POINTS);
                                c[3][0]=-0.525;
                               c[3][1]=-0.075;
                               glVertex2f(c[3][0],c[3][1]);
		                 glEnd();
				          glFlush();
			          }
                      diceRoll=1;
                      break;
               
     }
     ch=0;
     display();
}


int shuffle()
{
    int i,j,k,l;
    for(;;)
    {
           i=rand()%2;
           j=rand();
           k=j%4;
           l=j%8;
           if(i==0)
           {
                      switch(k)
                      {
                               case 0 : return 4;
                               case 1 : return 1;
                               case 2 : return 2;
                               case 3 : return 3;
                      }
          }
          if(i==1 && l==0) 
                  return 8;
     }
}

void dice(int y)
{
	glPointSize(5);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glVertex2f(-1.45,-0.15);
	glVertex2f(-1.15,-0.15);
	glVertex2f(-1.15,-0.45);
	glVertex2f(-1.45,-0.45);
	glEnd();
	
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1.45,-0.15);
	glVertex2f(-1.15,-0.15);
	glVertex2f(-1.15,-0.45);
	glVertex2f(-1.45,-0.45);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1.45,-0.15);
	glVertex2f(-1.15,-0.15);
	glVertex2f(-1.05,-0.05);
	glVertex2f(-1.35,-0.05);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1.15,-0.15);
	glVertex2f(-1.05,-0.05);
	glVertex2f(-1.05,-0.35);
	glVertex2f(-1.15,-0.45);
	glEnd();
	glPointSize(10);
	switch(y)
	{
	case 0:
	case 1:	
			glBegin(GL_POINTS);
			glVertex2f(-1.30,-0.30);
			glEnd();
			break;
    case 2:glBegin(GL_POINTS);
			glVertex2f(-1.375,-0.225);
            glVertex2f(-1.225,-0.375);
			glEnd();
	         break;
	 case 3:glBegin(GL_POINTS);
			glVertex2f(-1.375,-0.225);
            glVertex2f(-1.225,-0.375);
			glVertex2f(-1.30,-0.30);
			glEnd();
	         break;
	case 4:glBegin(GL_POINTS);
			glVertex2f(-1.375,-0.225);
            glVertex2f(-1.225,-0.375);
			glVertex2f(-1.225,-0.225);
			glVertex2f(-1.375,-0.375);
			glEnd();
	         break;
	case 8:glBegin(GL_POINTS);
            glVertex2f(-1.375,-0.225);
            glVertex2f(-1.225,-0.375);
			glVertex2f(-1.225,-0.225);
			glVertex2f(-1.375,-0.375);
			
			glVertex2f(-1.3,-0.225);
            glVertex2f(-1.225,-0.3);
			glVertex2f(-1.3,-0.375);
			glVertex2f(-1.375,-0.3);
			glEnd();
	        break;
	case 6:glBegin(GL_POINTS);
			glVertex2f(-0.72,0.29);
            glVertex2f(-0.755,0.29);
            glVertex2f(-0.79,0.29);
			glVertex2f(-0.72,0.34);
			glVertex2f(-0.755,0.34);
			glVertex2f(-0.79,0.34);
			glEnd();
	         break;

	}
	glPointSize(25);
	glFlush();
}

void myMouse(int btn,int state,int x,int y)
{ 
int C[10][10];
//GLint rand();
int D[10][10];
	C[0][0]=A[k1][0];C[0][1]=A[k1][1];C[1][0]=A[k2][0];C[1][1]=A[k2][1];
	C[2][0]=A[k3][0];C[2][1]=A[k3][1];C[3][0]=A[k4][0];C[3][1]=A[k4][1];
	D[0][0]=B[l1][0];D[0][1]=B[l1][1];D[1][0]=B[l2][0];D[1][1]=B[l2][1];
	D[2][0]=B[l3][0];D[2][1]=B[l3][1];D[3][0]=B[l4][0];D[3][1]=B[l4][1];
	


	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{	
		printf("x=%d,y=%d\n",x,y);
		printf("ply1=%d,ply2=%d before entering players blk\n",ply1,ply2);
		printf("ral=%d\n",ral);
		if(ply1>0)
		{
		 		  
		    ply1--;
		    ply2++;
		    
		    printf("ply1=%d,ply2=%d while entering player1\n",ply1,ply2);
		   
			if(k1==0&&x>657&&x<697&&y<615&&y>580)
			{
				player1(1);	
			}
		    else if(k2==0&&x>622&&x<657&&y<580&&y>545)
			{
				player1(2);
			}
	    	else if(k3==0&&x>657&&x<697&&y<545&&y>510)
			{
				player1(3);
			}
		    else if(k4==0&&x>692&&x<727&&y<580&&y>545)
			{
				player1(4);
			}
			else if( (k1==4 && x>838 && x<878 && y>358 && y<398) || (k1==8 && x>628 && x<668 && y>148 && y<188) || (k1==12 && x>418 && x<458 && y>358 && y<398) )
		    {
			     player1(1);  
		    }
		    else if( (k2==4 && x>838 && x<878 && y>306 && y<346) || (k2==8 && x>628 && x<668 && y>96 && y<136) || (k2==12 && x>418 && x<458 && y>306 && y<346) )
		    {
			     player1(2);  
		    }
		    else if( (k3==4 && x>890 && x<930 && y>306 && y<346) || (k3==8 && x>680 && x<720 && y>96 && y<136) || (k3==12 && x>470 && x<510 && y>306 && y<346) )
		    {
			     player1(3);  
		    }
		    else if( (k4==4 && x>890 && x<930 && y>358 && y<398) || (k4==8 && x>680 && x<720 && y>148 && y<188) || (k4==12 && x>470 && x<510 && y>358 && y<398) )
		    {
			     player1(4);  
		    }
	    	else if((x<(C[0][0]+20)&&x>(C[0][0]-20)&&y>(C[0][1]-20)&&y<(C[0][1]+20)&&k1>0))
	    	{
			 	  
			     player1(1);
			    
		    }
			else if((x<(C[1][0]+20)&&x>(C[1][0]-20)&&y>(C[1][1]-20)&&y<(C[1][1]+20)&&k2>0))
	    	{
			 	
		 		     player1(2);
		 		     
		    }
            else if((x<(C[2][0]+20)&&x>(C[2][0]-20)&&y>(C[2][1]-20)&&y<(C[2][1]+20)&&k3>0))
			{	
					    
						 player1(3);
					    
			}    
	        else if((x<(C[3][0]+20)&&x>(C[3][0]-20)&&y>(C[3][1]-20)&&y<(C[3][1]+20)&&k4>0))
	    	{		
					    
						 player1(4);
					     
		    }
		    else
		    {
			 	ply1++;
			 	ply2--;
			}
			
				
		 }
		else
		{
		 	ply2--;
		 	ply1++;
		 	
		 	printf("ply1=%d,ply2=%d while entering player2\n",ply1,ply2);
			
            if(l1==0&&x>657&&x<692&&y>160&&y<195)
			{ 
			  							 
		    	player2(1);
			
			}

		    else if(l2==0&&x>622&&x<657&&y>125&&y<160)
			{
			 	 
				    	player2(2);
			
			}
			else if(l3==0&&x>657&&x<692&&y>90&&y<125)
			{
			 	 
		    	player2(3);
			
			}
			else if(l4==0&&x>692&&x<727&&y>125&&y<160)
			{
		    	player2(4);
			
			}
			else if( (l1==4 && x>444 && x<484 && y>358 && y<398) || (l1==8 && x>628 && x<668 && y>568 && y<608) || (l1==12 && x>864 && x<904 && y>358 && y<398) )
			{
		   		player2(1);
			}
			
			else if( (l2==4 && x>418 && x<458 && y>332 && y<372) || (l2==8 && x>628 && x<668 && y>516 && y<556) || (l2==12 && x>838 && x<878 && y>332 && y<372) )
			{
		   		player2(2);
			}
			else if( (l3==4 && x>444 && x<484 && y>306 && y<346) || (l3==8 && x>680 && x<720 && y>516 && y<556) || (l3==12 && x>864 && x<904 && y>306 && y<346) )
			{
		   		player2(3);
			}
			else if( (l4==4 && x>470 && x<510 && y>332 && y<372) || (l4==8 && x>680 && x<720 && y>568 && y<608) || (l4==12 && x>890 && x<930 && y>332 && y<372) )
			{
		   		player2(4);
			}
		   else if((x>(D[0][0]-20)&&x<(D[0][0]+20)&&y>(D[0][1]-20)&&y<(D[0][1]+20)&&l1>0)) 
		   {
		   		player2(1);
			}
		   else if((x>(D[1][0]-20)&&x<(D[1][0]+20)&&y>(D[1][1]-20)&&y<(D[1][1]+20)&&l2>0))
  		   {
		   	
	  	        player2(2);
			}
          else if((x>(D[2][0]-20)&&x<(D[2][0]+20)&&y>(D[2][1]-20)&&y<(D[2][1]+20)&&l3>0))
 		  {
		   	  
		   	        player2(3);
			}
          else if((x>(D[3][0]-20)&&x<(D[3][0]+20)&&y>(D[3][1]-20)&&y<(D[3][1]+20)&&l4>0))
 		  {   
		  	  
		  	   	      player2(4);
			  }		
		 else
		    {
			 	ply1--;
			 	ply2++;
			}
			
		 	
		
		}
	if(diceRoll==1)
		{
		     ral=shuffle();
		     dice(ral);
		     diceRoll=0;
	    }
		
	}		
						  

}


void AboutTheProject(void)
{
 char *about="This mini-Project is based on a very ancient game CHOWKA-BHARA,using OpenGL.\n\nINSTRUCTIONS :\nInput can be provided either from Mouse or from Keyboard.\nFor mouse interaction right-click on the screen and select the required option.\nTo quit use key 'Q' or 'q' on keyboard\n\n\n\n\n\n";
 enter=0;
 int i;
 float x=-1.8,y=0.9,z=0;
 if(inAbout!=0)
 {
  inAbout=1;
  glColor3f(0,0,0);
  glRasterPos3f(x,y,z);
  for(i=0;about[i]!='\0';i++)
  {
	  if(about[i]=='\n')
	  {   y-=0.08;
		  glRasterPos3f(x,y,z);
	  }
	  else
	       glutBitmapCharacter(font,about[i]);
	}
  glPopMatrix(); 
  glFlush();
 }
}
 
void RulesOfTheGame(void)
{
 char *about_game="RULES:\n\n1. At the start of the game , both the player's  4 pieces are placed in their home area.\n2. Player take it in turn to throw a single die but here the die contains number 1,2,3,4  and 8.\n3. Player moves pawn forward the number of squares as indicated by the die.\n4. Any throw of 4 or 8 results in another turn.\n5. If a player cannot make a valid move they must pass the die to the next player.\n6. HIT: If a player's pawn lands on a square containing an opponent's pawn , the opponent's pawn is captured and returns to the home area\n and the player capturing gets another turn.\n7. A pawn may not land on a square that already contains pawns of the same player.\n8. In safe zone pawns of different player and also pawns of same player can co-exist. The above two rules are not valid in safe zone.\n9. For a player's pawn to progress into the inner squares, he should have hit at least one of his opponent's pawn. This condition is imposed on player and not on his pawn.\n10. After reaching inner square the player must throw the exact number to reach the central square.\n11. The winner is the player who gets all 4 of their pawns on to the central square before the other\n\n\n* Right click for other options";
 int i;
 enter=0;
 float x=-1.8,y=0.9,z=0;
 inAbout=1;
 glPushMatrix();
 glLoadIdentity();
 glColor3f(0,0,0);
 glRasterPos3f(x,y,z);
 for(i=0;about_game[i]!='\0';i++)
 {
  if(about_game[i]=='\n')
  {  
   y-=0.08;
   glRasterPos3f(x,y,z);
  }
  else
      glutBitmapCharacter(font,about_game[i]);
 }
 glPopMatrix(); 
 glFlush(); 
} 


void guideLinesNearBoard(void)
{
  char *gui="KEYBOARD OPTIONS:\nQ-To Quit.\n\nMOUSE OPTIONS:\nLEFT BUTTON- To Select the coin,\nClick on the coin of Player to\nROLL DICE & to move.\nRIGHT BUTTON- To Restart.";
  float x=1.1,y=0.4,z=0;
  int i;
  glColor3f(0.0,0.5,0.3);
  glBegin(GL_LINE_LOOP);
    glVertex2f(1.08,0.5);
	glVertex2f(1.92,0.5);
	glVertex2f(1.92,-0.2);
	glVertex2f(1.08,-0.2);
  glEnd();
  //in_guide=1;
  glColor3f(1,0,0);
  glRasterPos3f(x,y,z);

  for(i=0;gui[i]!='\0';i++)
  {
	  if(gui[i]=='\n')
	  {	  y-=0.08;
		  glRasterPos3f(x,y,z);
	  }
	  else

    glutBitmapCharacter(font,gui[i]);
  }
  

  glFlush();


  }

void dispPlayerNearBoard(void)
{
  char *guide="PLAYER 1\n\nPLAYER 2";
  void *en=GLUT_BITMAP_TIMES_ROMAN_24;
  float x=-1.4,y=0.7,z=0;
  int i;
 // in_guide=1;
  glColor3f(0.7,0.1,0.1);
  glRasterPos3f(x,y,z);
   
  for(i=0;guide[i]!='\0';i++)
  {
	  if(guide[i]=='\n')
	  {
	  
	  glColor3f(0.4,0.1,0.7);
		  y-=0.08;
		  glRasterPos3f(x,y,z);
	  }

    glutBitmapCharacter(en,guide[i]);
  }

  glFlush();

  }
  
void playersCoin()
{
    glPointSize(25);    
    glBegin(GL_POINTS);
	glColor3f(0.7,0.1,0.1);
                     glVertex2f(player1InitialCoinPositions[0][0],player1InitialCoinPositions[0][1]);
                     glVertex2f(player1InitialCoinPositions[1][0],player1InitialCoinPositions[1][1]);
                     glVertex2f(player1InitialCoinPositions[2][0],player1InitialCoinPositions[2][1]);
                     glVertex2f(player1InitialCoinPositions[3][0],player1InitialCoinPositions[3][1]);
	glColor3f(0.4,0.1,0.7);
	                 glVertex2f(player2InitialCoinPositions[0][0],player2InitialCoinPositions[0][1]);
                     glVertex2f(player2InitialCoinPositions[1][0],player2InitialCoinPositions[1][1]);
                     glVertex2f(player2InitialCoinPositions[2][0],player2InitialCoinPositions[2][1]);
                     glVertex2f(player2InitialCoinPositions[3][0],player2InitialCoinPositions[3][1]);
    glEnd();
}

void circle()
{float ang;
int i;
	glPushMatrix();
	glLoadIdentity();
	
	
	glTranslatef(-1.47,0.72,0);
		if(ply1>0)
		{glColor3f(1,0,0);}
		else
		{glColor3f(1,1,1);}
	glBegin(GL_POLYGON);
	for(i=0;i<=12;i++)
	{
		ang=(3.1415/6)*i;
		glVertex2f(0.02*cos(ang),0.02*sin(ang));
	}
	glEnd();
	glColor3f(0,1,0);
	glFlush();
		glPopMatrix();
	glFlush();

	glPushMatrix();
	glLoadIdentity();

		glTranslatef(-1.47,0.56,0);
		if(ply1==0&&ply2==1)
		{glColor3f(1,0,0);}
		else
		{glColor3f(1,1,1);}
	glBegin(GL_POLYGON);
	for(i=0;i<=12;i++)
	{
		ang=(3.1415/6)*i;
		glVertex2f(0.02*cos(ang),0.02*sin(ang));
	}
	glEnd();
	glColor3f(0,1,0);
	glFlush();
	glPopMatrix();
	glFlush();
}

void mesh()
{
 	 glColor3f(0.0,0.0,0.0);
     
     glBegin(GL_LINES);
        glVertex2f(0.75,0.75);
	    glVertex2f(-0.75,0.75);   //Main BOX 

     	glVertex2f(-0.75,0.75);
	    glVertex2f(-0.75,-0.75);
	    
	    glVertex2f(-0.75,-0.75);
	    glVertex2f(0.75,-0.75);
	    
	    glVertex2f(0.75,0.75);
	    glVertex2f(0.75,-0.75);
	    
	    
	    glVertex2f(0.15,-0.75);
        glVertex2f(0.15,0.75);
        
        glVertex2f(-0.15,-0.75);
        glVertex2f(-0.15,0.75);
        
        glVertex2f(0.45,-0.75);
        glVertex2f(0.45,0.75);
        
         glVertex2f(-0.45,-0.75);
        glVertex2f(-0.45,0.75);
       
         glVertex2f(-0.75,-0.15);
        glVertex2f(0.75,-0.15);
        
         glVertex2f(-0.75,0.15);
        glVertex2f(0.75,0.15);
        
        glVertex2f(-0.75,0.45);
        glVertex2f(0.75,0.45);
        
        glVertex2f(-0.75,-0.45);
        glVertex2f(0.75,-0.45);
        
       //CROSS LINES
       
       
         glVertex2f(-0.15,0.75);
        glVertex2f(0.15,0.45);
        
          glVertex2f(-0.15,0.45);
        glVertex2f(0.15,0.75);
        	    
        	    
         glVertex2f(-0.75,0.15);
        glVertex2f(-0.45,-0.15);
        
          glVertex2f(-0.75,-0.15);
        glVertex2f(-0.45,0.15); 	
        
          glVertex2f(-0.15,0.15);
        glVertex2f(0.15,-0.15); 
        
          glVertex2f(-0.15,-0.15);
        glVertex2f(0.15,0.15);
        
          glVertex2f(0.45,-0.15);
        glVertex2f(0.75,0.15);
        
          glVertex2f(0.75,-0.15);
        glVertex2f(0.45,0.15);
        
          glVertex2f(-0.15,-0.75);
        glVertex2f(0.15,-0.45); 
        
          glVertex2f(0.15,-0.75);
        glVertex2f(-0.15,-0.45);  
	glEnd(); 	 

}

void gameBoard()
{    
     enter=0;
     glClearColor(1.0,1.0,1.0,1.0);
     glLineWidth(4);
     glClear(GL_COLOR_BUFFER_BIT);
      
     mesh();
     ral=shuffle();
     dice(ral);
     diceRoll=0;
     
	
	dispPlayerNearBoard();
	guideLinesNearBoard();
    playersCoin();
    circle();
}

void key(unsigned char key,int x,int y)
{

	if(key=='q' || key=='Q')
	            exit(0);	//call(2);
	
	

	if(key==13 && enter==1)
	{ 
	
		gameInit();
		wait();
		loading();
	}
}







void options(int id)
{
 switch(id)
 {
  case 1:
  	   glClearColor(1.0,1.0,1.0,1.0);
       glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	   inAbout=1;
	   AboutTheProject();
	   break;
  case 2:
  	   glClearColor(1.0,1.0,1.0,1.0);
  	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	  RulesOfTheGame();
      break;
  case 4:
  	   glClearColor(0.6,0.7,0,0);
	  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	  	gameInit();
		wait();
		loading();
	  break;
	  
  case 5:
	  exit(0);
 }
}



void loader()
{	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	{	glVertex2f(-.4,-.7);
		glVertex2f(-.4,-.65);
		glVertex2f(.4,-.65);
		glVertex2f(.4,-.7);
	}
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_QUADS);
	{	glVertex2f(-.39,-.69);
		glVertex2f(-.39,-.66);
		glVertex2f(-.34,-.66);
		glVertex2f(-.34,-.69);
	}	glEnd();
		glFlush();
		wait();
		wait();
		glBegin(GL_QUADS);
	{	glVertex2f(-.34,-.69);
		glVertex2f(-.34,-.66);
		glVertex2f(-.30,-.66);
		glVertex2f(-.30,-.69);
	}	glEnd();
		glFlush();
		wait();
		wait();
		wait();
			glBegin(GL_QUADS);
	{	glVertex2f(-.30,-.69);
		glVertex2f(-.30,-.66);
		glVertex2f(-.23,-.66);
		glVertex2f(-.23,-.69);
	}	glEnd();
		glFlush();
		wait();
		wait();
		wait();
			glBegin(GL_QUADS);
	{	glVertex2f(-.23,-.69);
		glVertex2f(-.23,-.66);
		glVertex2f(-.1,-.66);
		glVertex2f(-.1,-.69);
	}	glEnd();
		glFlush();
		wait();
		wait();
		wait();
			glBegin(GL_QUADS);
	{	glVertex2f(-.1,-.69);
		glVertex2f(-.1,-.66);
		glVertex2f(0.1,-.66);
		glVertex2f(0.1,-.69);
	}	glEnd();
		glFlush();
		wait();
		wait();
		wait();
		wait();
		wait();
		wait();
			glBegin(GL_QUADS);
	{	glVertex2f(0.1,-.69);
		glVertex2f(0.1,-.66);
		glVertex2f(0.15,-.66);
		glVertex2f(0.15,-.69);
	}	glEnd();
		glFlush();
		wait();
		wait();
		wait();
			glBegin(GL_QUADS);
	{	glVertex2f(0.15,-.69);
		glVertex2f(0.15,-.66);
		glVertex2f(0.2,-.66);
		glVertex2f(0.2,-.69);
	}	glEnd();
		glFlush();
		wait();
		wait();
			glBegin(GL_QUADS);
	{	glVertex2f(0.2,-.69);
		glVertex2f(0.2,-.66);
		glVertex2f(0.39,-.66);
		glVertex2f(0.39,-.69);
	}	glEnd();
		glFlush();
		wait();
		wait();
		wait();
		wait();

	gameBoard();
}

void chowkaBhara()
{
 	 glClearColor(0.6,0.7,0,0);
  	  glLineWidth(9);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	  glVertex2f(-1.6,0.8);
      glVertex2f(-1.8,0.8);
	  glVertex2f(-1.8,0.8);
	  glVertex2f(-1.8,0.4);//C
	  glVertex2f(-1.8,0.4);
	  glVertex2f(-1.6,0.4);
    glEnd();
    
    glFlush();

      glBegin(GL_LINES);
    	  glVertex2f(-1.5,0.4);
    	  glVertex2f(-1.5,0.7);
    	  glVertex2f(-1.5,0.55);  //H
    	  glVertex2f(-1.3,0.55);
    	  glVertex2f(-1.3,0.4);
    	  glVertex2f(-1.3,0.7);
	  glEnd();
      glFlush();

      glBegin(GL_LINES);
	  glVertex2f(-1.25,0.55);
	  glVertex2f(-1.1,0.7);
	  glVertex2f(-1.1,0.7);  //O
	  glVertex2f(-0.95,0.55);
	  glVertex2f(-0.95,0.55);
	  glVertex2f(-1.1,0.4);
	  glVertex2f(-1.1,0.4);
	  glVertex2f(-1.25,0.55);
      glEnd();
	  glFlush();

	  glBegin(GL_LINES);
    	  glVertex2f(-0.9,0.7);
    	  glVertex2f(-0.9,0.4);
    	  glVertex2f(-0.9,0.4);   //W
    	  glVertex2f(-0.8,0.5);
    	  glVertex2f(-0.8,0.5);
          glVertex2f(-0.7,0.4);
    	  glVertex2f(-0.7,0.4);
          glVertex2f(-0.7,0.7);
	  glEnd();
	  glFlush();

   glBegin(GL_LINES);
    	  glVertex2f(-0.6,0.7);
    	  glVertex2f(-0.6,0.4);
    	  glVertex2f(-0.45,0.7);   //k
    	  glVertex2f(-0.6,0.55);
    	  glVertex2f(-0.6,0.55);
          glVertex2f(-0.45,0.4);
	  glEnd();
	  glFlush();
	  
	  glBegin(GL_LINES);
    	  glVertex2f(-0.4,0.55);
    	  glVertex2f(-0.22,0.55);
    	  glVertex2f(-0.4,0.4);   //A
    	  glVertex2f(-0.3,0.7);
    	  glVertex2f(-0.3,0.7);
          glVertex2f(-0.2,0.4);
	  glEnd();
	  glFlush();
	  
      glBegin(GL_LINES);
    	  glVertex2f(-0.5,0.34);
    	  glVertex2f(-0.5,-0.1);
    	  glVertex2f(-0.5,0.34);
    	  glVertex2f(-0.3,0.2);
    	  glVertex2f(-0.3,0.2);
    	  glVertex2f(-0.5,0.1);  //B
    	  glVertex2f(-0.5,0.1);
    	  glVertex2f(-0.3,0.0);
    	  glVertex2f(-0.3,0.0);
    	  glVertex2f(-0.5,-0.1);
	  glEnd();
	  glFlush();
	  
	   glBegin(GL_LINES);
    	  glVertex2f(-0.23,0.2);
    	  glVertex2f(-0.23,-0.1);
    	  glVertex2f(-0.23,0.05);  //H
    	  glVertex2f(-0.05,0.05);
    	  glVertex2f(-0.05,-0.1);
    	  glVertex2f(-0.05,0.2);
	  glEnd();
      glFlush();

	  glBegin(GL_LINES);
    	  glVertex2f(0.05,-0.1);
    	  glVertex2f(0.15,0.22);
    	  glVertex2f(0.15,0.22);  //A
    	  glVertex2f(0.25,-0.1);
    	  glVertex2f(0.05,0.02);
    	  glVertex2f(0.19,0.02);
	  glEnd();
	  glFlush();

	  glBegin(GL_LINES);
    	  glVertex2f(0.35,-0.1);
    	  glVertex2f(0.35,0.22);
    	  glVertex2f(0.35,0.22);   //R
    	  glVertex2f(0.5,0.13);
    	  glVertex2f(0.5,0.13);
    	  glVertex2f(0.35,0.05);
    	  glVertex2f(0.35,0.05);
    	  glVertex2f(0.5,-0.1);
	  glEnd();
	  glFlush();
	  
	   glBegin(GL_LINES);
    	  glVertex2f(0.6,-0.1);
    	  glVertex2f(0.7,0.22);
    	  glVertex2f(0.7,0.22);  //A
    	  glVertex2f(0.8,-0.1);
    	  glVertex2f(0.6,0.02);
    	  glVertex2f(0.74,0.02);
	  glEnd();
	  glFlush();
}

void loading(void)
{
  char *about="LOADING...\n";
  void *en=GLUT_BITMAP_TIMES_ROMAN_24;
  float x=-0.16,y=-0.8,z=0;
  int i;
  enter=0;
  ply1=1;
  ply2=0;
	
	glClear(GL_COLOR_BUFFER_BIT);
	 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  	  glClearColor(0.6,0.7,0,0);
  	  
     for(i=0;about[i]!='\0';i++)
     {
	  /*if(about[i]=='\n')
	  {   // wait();
		  //y-=0.08;
		  glRasterPos3f(x,y,z);
	  }
	  else if(about[i]=='\t')
	  {
		  //x-=0.2;
		  glRasterPos3f(x,y,z);
	  }
	  else*/
	  {
	    glutBitmapCharacter(en,about[i]);
	  }
  }
	  

	chowkaBhara();
	  
      loader();
	  
	  glFlush();
}



void displayMain(void)
{
	char *about="* PRESS  ENTER TO START THE GAME\n";
	char *about1= "* RIGHT CLICK FOR OTHER OPTIONS \n";
  void *en=GLUT_BITMAP_TIMES_ROMAN_24;
  float x=0.5,y=-0.8,z=0;
  float x1=0.5,y1=-0.65,z1=0;
  int i;
  enter=1;
	
	glClear(GL_COLOR_BUFFER_BIT);
	 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  	  
	  chowkaBhara();
        
	  
	   glColor3f(1.0,1.0,1.0);
	  glRasterPos3f(x,y,z);

  for(i=0;about[i]!='\0';i++)
  {
	  if(about[i]=='\n')
	  {   wait();
		  y-=0.08;
		  glRasterPos3f(x,y,z);
	  }
	  else if(about[i]=='\t')
	  { //wait();
		  x-=0.2;
		  glRasterPos3f(x,y,z);
	  }
	  else
	  { 
	    glutBitmapCharacter(en,about[i]);
	  }
  }
  
  
   glColor3f(1.0,1.0,1.0);
	  glRasterPos3f(x1,y1,z1);
   for(i=0;about1[i]!='\0';i++)
  {
	  if(about1[i]=='\n')
	  {    
		  y1-=0.08;
		  glRasterPos3f(x1,y1,z1);
	  }
	  else if(about1[i]=='\t')
	  { 
		  x1-=0.2;
		  glRasterPos3f(x1,y1,z1);
	  }
	  else
	  { 
	    glutBitmapCharacter(en,about1[i]);
	  }
  }
  glFlush();
}	  

 

int main(int argc,char** argv)
{

 enter=1;
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
 myInit();
 glutCreateMenu(options);
 glutAddMenuEntry("About the Project",1);
 glutAddMenuEntry("Rules of the Game",2);
 glutAddMenuEntry("Game Mode or Restart",4);
 glutAddMenuEntry("Quit",5);
 glutMouseFunc(myMouse);
 glutKeyboardFunc(key);
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 glutReshapeFunc(myReshape);
 glutDisplayFunc(displayMain); 	
 font=GLUT_BITMAP_9_BY_15;//GLUT_BITMAP_HELVETICA_12;
 glutMainLoop();   
 return 0;
}

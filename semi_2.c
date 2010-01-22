#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include <GLUT/glut.h>
//#include <GL/glut.h>
#define D 100
#define WIDTH 36.2
#define HEIGHT 27.1  

int count=0;
int i,j,ans,roop,flag_circle=0;
int c1[100],c2[100],p1[100],p2[100];
int color1,color2,place1,place2;
double theta_w,theta_h;
float x1,x2,y3,y2;
float th1,th2;		
float th1_rad, th2_rad;	
float hankei = 1;

int GetRandom_c1(int min_c1, int max_c1); //・鬣タ・爨ヒテヘ、タ、・

int GetRandom_c2(int min_c2, int max_c2);

int GetRandom_p1(int min_p1, int max_p1);

int GetRandom_p2(int min_p2, int max_p2);


int GetRandom_c1(int min_c1, int max_c1) //・鬣タ・狹ヘ、ホセ蟶ツ、゜ト・
{
  return min_c1 + (int)(rand() * (max_c1 - min_c1 + 1.0) / (1.0 + RAND_MAX));
}


int GetRandom_c2(int min_c2, int max_c2)
{
  return min_c2 + (int)(rand() * (max_c2 - min_c2 + 1.0) / (1.0 + RAND_MAX));
}



int GetRandom_p1(int min_p1, int max_p1)
{
  return min_p1 + (int)(rand() * (max_p1 - min_p1 + 1.0) / (1.0 + RAND_MAX));
}


int GetRandom_p2(int min_p2, int max_p2)
{
  return min_p2 + (int)(rand() * (max_p2 - min_p2 + 1.0) / (1.0 + RAND_MAX));
}

/***********************************************************/

void target_point(void) //テ晙・タ、ホノチイ・
{
	
  glBegin(GL_POLYGON); //ア゜、ホノチイ・		

  for (th1 = 0.0;  th1 <= 360.0;  th1 = th1 + 10.0)
		{              
		  th2 = th1 + 10.0;
		  th1_rad = th1 / 180.0 * 3.1415926;  
		  th2_rad = th2 / 180.0 * 3.1415926; 

		  x1 = hankei * cos(th1_rad);
		  y3 = hankei * sin(th1_rad);
		  x2 = hankei * cos(th2_rad);
		  y2 = hankei * sin(th2_rad);
	
		  glVertex2f( x1, y3 );      
		  glVertex2f( x2, y2 );
		}

  glEnd();
}

void draw_circle(void) //・ソ。シ・イ・テ・ネ、ホノチイ・
{
  if(flag_circle == 0) //ソァ、ネーフテヨ、霪・
    {
      color1 = GetRandom_c1(0,3);
      color2 = GetRandom_c2(0,3);
      place1 = GetRandom_p1(0,7);
      place2 = GetRandom_p2(0,7);
      
      while(color1 == color2)
	{
	  color2 = GetRandom_c2(0,3);
	}
      
      if(place1 == place2)
	{
	  place2 = GetRandom_p2(0,7);
	}
      
      //ソァ、ネーフテヨ、ホナ妤ィ、ロホヒウハヌシ
      
      c1[ans] = color1;
      c2[ans] = color2;
      p1[ans] = place1;
      p2[ans] = place2;
      
      ans++;
      
    }
  
  switch(color1){
  case 0:
    glColor3d( 1.0 , 0.0 , 0.0 );  //red
    break;
  case 1:
    glColor3d( 0.0 , 1.0 , 0.0 );  //green
    break;
  case 2:
    glColor3d( 0.0 , 0.0 , 1.0 );  //blue
    break;
  case 3:
    glColor3d( 1.0 , 1.0 , 0.0 );  //yellow
    break;
  default:
    break;
  }
  
  switch(place1){
  case 1:
    glTranslated(-5.0 , 5.0 , 0.0); // left-up
    target_point();
    glTranslated(5.0 , -5.0 , 0.0);
    break;
  case 2:
    glTranslated(0.0 , 5.0 , 0.0); // up
    target_point();
    glTranslated(0.0 , -5.0 , 0.0);
    break;
  case 3:
    glTranslated(5.0 , 5.0 , 0.0); // right-up
    target_point();
    glTranslated(-5.0 , -5.0 , 0.0);
    break;
  case 4:
    glTranslated(-5.0 , 0.0 , 0.0); // left
    target_point();
    glTranslated(5.0 , 0.0 , 0.0);
    break;
  case 5:
    glTranslated(5.0 , 0.0 , 0.0); // right
    target_point();
    glTranslated(-5.0 , 0.0 , 0.0);
    break;
  case 6:
    glTranslated(-5.0 , -5.0 , 0.0); //left-down
    target_point();
    glTranslated(5.0 , 5.0 , 0.0); 
    break;
  case 7:
    glTranslated(0.0 , -5.0 , 0.0); // down
    target_point();
    glTranslated(0.0 , 5.0 , 0.0);
    break;
  case 8:
    glTranslated(5.0 , -5.0 , 0.0); //right-down
    target_point();
    glTranslated(-5.0 , 5.0 , 0.0); 
    break;
  default:
    break;
  }
  
  switch(color2){
  case 0:
    glColor3d( 1.0 , 0.0 , 0.0 );  //red
    break;
  case 1:
    glColor3d( 0.0 , 1.0 , 0.0 );  //green
    break;
  case 2:
    glColor3d( 0.0 , 0.0 , 1.0 );  //blue
    break;
  case 3:
    glColor3d( 1.0 , 1.0 , 0.0 );  //yellow
    break;
  default:
    break;
  }
  
  switch(place1){
  case 1:
    glTranslated(-5.0 , 5.0 , 0.0); // left-up
    target_point();
    glTranslated(5.0 , -5.0 , 0.0);
    break;
  case 2:
    glTranslated(0.0 , 5.0 , 0.0); // up
    target_point();
    glTranslated(0.0 , -5.0 , 0.0);
    break;
  case 3:
    glTranslated(5.0 , 5.0 , 0.0); // right-up
    target_point();
    glTranslated(-5.0 , -5.0 , 0.0);
    break;
  case 4:
    glTranslated(-5.0 , 0.0 , 0.0); // left
    target_point();
    glTranslated(5.0 , 0.0 , 0.0);
    break;
  case 5:
    glTranslated(5.0 , 0.0 , 0.0); // right
    target_point();
    glTranslated(-5.0 , 0.0 , 0.0);
    break;
  case 6:
    glTranslated(-5.0 , -5.0 , 0.0); //left-down
    target_point();
    glTranslated(5.0 , 5.0 , 0.0); 
    break;
  case 7:
    glTranslated(0.0 , -5.0 , 0.0); // down
    target_point();
    glTranslated(0.0 , 5.0 , 0.0);
    break;
  case 8:
    glTranslated(5.0 , -5.0 , 0.0); //right-down
    target_point();
    glTranslated(-5.0 , 5.0 , 0.0); 
    break;
  default:
    break;
  } 
}

void display(void)
{
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  if(count >= 60 && count <= 150) //750msエヨテ晙・タ、チイ・
    {
      glColor3d( 1.0 , 0.0 , 0.0 );  //red
      target_point(); //テ晙・タ、チイ・
    }
  
  if(count >= 180 && count <= 213) //25msエヨ・ソ。シ・イ・テ・ネ、チイ・
    {
      draw_circle(); //・ソ。シ・イ・テ・ネ、チイ・
      //sleep(0.5);
      flag_circle = 1;
    }
  
  if(count == 216) //コニ、モ・・シ・ラ、ヒフ皃・
    {
      count = 0;
      flag_circle = 0;
    }
  
  glutSwapBuffers();
  
  glutPostRedisplay();
  
  count++; //display、ャクニ、ミ、・ソイォ・ヲ・ネ
  
}

void resize(int w,int h)
{
  theta_w = 2*atan(WIDTH/(2*D));
  theta_h = 2*atan(HEIGHT/(2*D));
  
  theta_w = theta_w * (180 / 3.1415926); 
  theta_h = theta_h * (180 / 3.1415926); 
  
  glViewport(0,0,w,h);
  glLoadIdentity();
  glOrtho(-theta_w/2,theta_w/2,-theta_h/2,theta_h/2,1,-1);
}


void keyboard(unsigned char _key, int _x, int _y)
{
  switch (_key) {
    
  case 'q': 
    
    exit(0); 
    break;
  default: 
    break; 
  }
  
  
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  
  
  glutCreateWindow(argv[0]);
  glutReshapeFunc(resize);
  glutDisplayFunc(display);      
  glutKeyboardFunc(keyboard);      
  glutFullScreen();


  //srand((unsigned int)time(NULL));

  glutMainLoop();   

  return 0;
}

  

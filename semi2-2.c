#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include<math.h> 
#define PART 100
#define MONITW  362.0
#define MONITH  271.0
#define D 1000.0 
#define WIDTH 36.2
#define HEIGHT 27.1

void square();
void circle();
void circle_loop();
float rnd;
float deg2pixh(float degree);
float deg2pixw(float degree);
int select(int x, int y); 
int square_width;
int square_height;
int rest_width;
int rest_height;
int thx;
int thy;
int col[9]; 
int color1, color2, place1, place2;
int iro();
int basyo();
int exactly();
double theta_w, theta_h;
float x1,x2,y3,y2;
float th1,th2,th1_rad,th2_rad;
float hankei = 1;
void target_point();
void draw_circle();
void resize(int w, int h);

void initialize()
{
  int i;
  square_width = deg2pixw(5.0);
  square_height = deg2pixh(5.0);
  rest_width = (WIDTH-square_width)/2.0;
  rest_height = (HEIGHT-square_height)/2.0;
  thx = (int)(square_width/4);
  thy = (int)(square_height/4);
  for(i=1;i<=8;i++)
    {
      col[i] = 0;
    }
}

void keyboard(unsigned char key, int x, int y);

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void display2(void)
{
  int count;
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  if(count >= 10 && count <= 15000)
    {
      glColor3d( 1.0 , 0.0 , 0.0 );  //red
      target_point(); 
    }
  
  if(count >= 210 && count <= 213) 
    {
      draw_circle();
      //     flag_circle = 1;
    }
  
  if(count == 216)
    {
      count = 0;
      //flag_circle = 0;
    }
  
  glutSwapBuffers();
  
  glutPostRedisplay();
  
  count++;
}

void target_point(void)
{

  glBegin(GL_POLYGON);		

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

void draw_circle(void) 
{
   switch(color1){
  case 1:
    glColor3d( 1.0 , 0.0 , 0.0 );  //red
    break;
  case 2:
    glColor3d( 0.0 , 1.0 , 0.0 );  //green
    break;
  case 3:
    glColor3d( 0.0 , 0.0 , 1.0 );  //blue
    break;
  case 4:
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
  case 1:
    glColor3d( 1.0 , 0.0 , 0.0 );  //red
    break;
  case 2:
    glColor3d( 0.0 , 1.0 , 0.0 );  //green
    break;
  case 3:
    glColor3d( 0.0 , 0.0 , 1.0 );  //blue
    break;
  case 4:
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

void keyboard(unsigned char key, int x, int y)
{
  FILE *fp;
  static int counter;
  static int seikaicolor, seikaiplace, seikai, oshii;
  int i, j;

/*位置と色を決める*********************************************
************************************************************/
  color1 = rand()%4+1;
  do{
    color2 = rand()%4+1;
  }while(color1 == color2);

  place1 = rand()%8+1;
  do{
    place2 = rand()%8+1;
  }while(place1 == place2);

  switch(key){
/*正誤判定****************************************************
************************************************************/
  case ' ':
    if(counter != 0)
      if(kazu() == 1)//異なる二箇所を指定しているか
	for(i = 0; i < 8; i++)
	  {
	    if(iro()==1)
	      seikaicolor++;
	    if(basyo()==1)
	      seikaiplace++;
	    if(iro()==1&&basyo()==1)
	      if(exactly()==1)
		seikai++;
	      else oshii++;
	  }
  
    if(counter==100)
      {
	fp = fopen("test.txt", "w");
	fprintf(fp,"%d %d %d %d", seikaicolor, seikaiplace, seikai, oshii);
	fclose(fp);
      }
/**********************************************************/
    
    glutKeyboardFunc(0); //display2の妨害刺激の後に解除してもらう
    glutDisplayFunc(display2);
    glutPostRedisplay();
    counter++;
    break;
    
  case 'q':
    exit(0);
    break;
    
  default:
    break;
  }
}
//異なる２箇所を指定しているか
int kazu(void)
{
  int i,seikai=0;
  for(i=0;i<8;i++){
    if(col[i] != 0){
      seikai++;
    }
  }
  if(seikai==2)return 1;
  return 0;
}

//色が正しいかどうか
int iro(void)
{
  int i,j;
  for(i=0;i<8;i++){
    if(col[i] == color1){
      for(j=0;j<8;j++){
	if(i==j)continue;
	if(col[j]==color2)return 1;
      }
    }
  }
  return 0;
}

//場所が正しいかどうか
int basyo(void)
{
  int i,j;
  for(i=0;i<8;i++){
    if(i == place1){
      for(j=0;j<8;j++){
	if(i==j)continue;
	if(j == place2)return 1;
      }
    }
  }
  return 0;
}

//どちらも正しいかどうか
int exactly(void)
{
  int i,j;
  for(i=0;i<8;i++){
    if(col[i]==color1 && i == place1){
      for(j=0;j<8;j++){
	if(i==j)continue;
	if(col[j]==color2 && j == place2)return 1;
      }
    }
  }
  return 0;
}
float deg2pixh(float degree){ //任意のdegree（角度）をピクセルに変換する関数
  float deg1,pix;  
  pix = atan(MONITH/(D*2)); //radian  //printf("%f\n",pix);   
  pix = pix * (180.0 / M_PI); //.to_degree  //printf("%f\n",pix);   
  deg1 = (HEIGHT/2.0)/pix; //1deg の pixel   //printf("%f\n",deg1);
  return deg1*degree; 
}

float deg2pixw(float degree){ //任意のdegree（角度）をピクセルに変換する関数　  
  float deg1,pix;  
  pix = atan(MONITW/(D*2)); //radian  //printf("%f\n",pix);
  pix = pix * (180.0 / M_PI); //.to_degree  //printf("%f\n",pix);
  deg1 = (WIDTH/2.0)/pix; //1deg の pixel   // printf("%f\n",deg1);
  return deg1*degree;
 }
void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char *argv[])
{
  srand(time(NULL));
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  init();
  glutMainLoop();
  return 0;
}

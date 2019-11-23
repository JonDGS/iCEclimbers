#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

int players;
gchar *block_1 = "D:\\Utilities\\Downloads\\src\\image\\block(1).png";
gchar *block_2 = "D:\\Utilities\\Downloads\\src\\image\\block(2).png";
gchar *block_3 = "D:\\Utilities\\Downloads\\src\\image\\block(3).png";
gchar *block_4 = "D:\\Utilities\\Downloads\\src\\image\\block(4).png";
gchar *block_5 = "D:\\Utilities\\Downloads\\src\\image\\block(5).png";
gchar *block_6 = "D:\\Utilities\\Downloads\\src\\image\\block(6).png";
gchar *block_7 = "D:\\Utilities\\Downloads\\src\\image\\block(7)(1).png";
gchar *orange = "D:\\Utilities\\Downloads\\src\\image\\naranga(1).png";
gchar *banana = "D:\\Utilities\\Downloads\\src\\image\\banano(1).png";
gchar *eggplant = "D:\\Utilities\\Downloads\\src\\image\\/berenjena(1).png";
gchar *lettuce = "D:\\Utilities\\Downloads\\src\\image\\lechuga(1).png";
gchar *empty = "D:\\Utilities\\Downloads\\src\\image\\block.png";
gchar *per = "D:\\Utilities\\Downloads\\src\\image\\character(1).png";
gchar *per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(1).png";

char special[] = "0";
char special2[] = "0";
char fruit[] = "0";
char fruit2[] = "0";
char yeti[] = "0";
char yeti2[] = "0";
char bird[] = "0";
char bird2[] = "0";
char bloque[] = "0";
char bloque2[] = "0";
char tot[] = "0";
char tot2[] = "0";

int pos_x_N[2] = {15,16};
int pos_y_N[2] = {30,31};

int pos_x_B[1] = {8};
int pos_y_B[2] = {21,22};

int pos_x_Be[1] = {21};
int pos_y_Be[2] = {16,17};

int pos_x_L[2] = {22,23};
int pos_y_L[2] = {26,27};

int pos_x[2] = {4,5};
int pos_y[3] = {106,107,108};
int pos2_x[2] = {26,27};
int pos2_y[3] = {106,107,108};
int piso = 110;
static void create_window (GtkWidget *widget, int data);
int vida = 3;
int vida2 = 3;
int jump = 0;
int jump2 = 0;

bool left, right, up, left2, right2, up2 = false;

GtkWidget *pantalla;
int matriz[110][32] =
        {
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {6,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6},
                {0,0,0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0,0,0},
                {0,0,0,0,0,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,0,0,0,0,0},
                {0,0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,6,0,0,0,0,0,0,0,0,0,0,6,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,6,6,6,6,6,6,6,6,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,0,6,6,6,6,6,0,0,0,0,0,0,6,6,6,6,0,0,0,0,0,0,6,6,6,6,6,0,0,0},
                {0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0},
                {0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0},
                {0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0},
                {0,0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0,0},
                {0,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,0},
                {6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6},
                {6,6,6,6,6,0,0,0,0,0,6,6,6,6,0,0,0,0,6,6,6,6,0,0,0,0,0,6,6,6,6,6},
                {6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6},
                {6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6},
                {6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,6,6,6,6,6,6,0,0,6,6,6,6,6,6,0,0,6,6,6,6,6,6,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {6,6,6,6,6,6,6,0,0,6,6,6,6,6,6,0,0,6,6,6,6,6,6,0,0,6,6,6,6,6,6,6},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2}
        };

/*******************************************************************************
 * Isvalueinarray
 * Se encarga buscar un valor en un array.
 * Parametros:
 *		val: valor a buscar.
 *		array: el array en donde se va a buscar.
 *		size: el tamaño del array.
 * Return:
 *		True: si se encuenta el valor en el array.
 *		False: en caso contrario.
 *******************************************************************************/

bool isvalueinarray(int val, int* array, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(array[i] == val)
            return true;
    }
    return false;
}

/*******************************************************************************
 * Gameover
 * Se encarga de llevar todos los valores a su defecto y genera la pantalla de
 * GameOver.
 * Parametros: N/A
 * Return:
 *		La ventana de GameOver.
 *******************************************************************************/

static GtkWidget* gameover (void)
{
    GtkWidget *window;
    GtkWidget *re, *salir, *menu;
    GtkWidget *box, *score, *player1, *player2;

    piso = 110;
    pos_x[0] = 4;
    pos_x[1] = 5;
    pos_y[0] = 106;
    pos_y[1] = 107;
    pos_y[2] = 108;

    pos2_x[0] = 26;
    pos2_x[1] = 27;
    pos2_y[0] = 106;
    pos2_y[1] = 107;
    pos2_y[2] = 108;

    pos_y_N[0] = 15;
    pos_y_N[1] = 16;

    pos_x_B[0] = 8;

    pos_x_Be[0] = 21;

    pos_x_L[0] = 26;
    pos_x_L[1] = 27;

    vida = 3;
    vida2 = 3;

    for(int j = 102; j != 53; j = j - 7)
    {
        if (matriz[j][0] == 2)
        {
            for(int i = 4; i != 28; i++)
            {
                matriz[j][i] = 1;
            }
        }
        else if (matriz[j][0] == 4)
        {
            for(int i = 4; i != 28; i++)
            {
                matriz[j][i] = 3;
            }
        }
        else if (matriz[j][0] == 6)
        {
            for(int i = 4; i != 28; i++)
            {
                matriz[j][i] = 5;
            }
        }
    }

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "iCE Climber");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
    g_signal_connect (window, "destroy",G_CALLBACK (exit), NULL);

    box = gtk_box_new (GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add (GTK_CONTAINER (window), box);

    score = gtk_box_new (GTK_ORIENTATION_HORIZONTAL,30);
    gtk_container_add (GTK_CONTAINER (box), score);

    player1 = gtk_box_new (GTK_ORIENTATION_VERTICAL,5);
    gtk_container_add (GTK_CONTAINER (score), player1);
    char a1[] = "Player 1";
    char a2[] = "Bonus: ";
    strcat(a2, special);
    char a3[] = "Frutas: ";
    strcat(a3, fruit);
    char a4[] = "Focas: ";
    strcat(a4, yeti);
    char a5[] = "Pajaro: ";
    strcat(a5, bird);
    char a6[] = "Bloque: ";
    strcat(a6, bloque);
    char a7[] = "Total: ";
    strcat(a7, tot);
    for(int i = 0; i < 7;i++)
    {
        GtkWidget *aux;
        switch (i)
        {
            case 0:
                aux = gtk_label_new (a1);
                gtk_container_add (GTK_CONTAINER (player1), aux);
                break;
            case 1:
                aux = gtk_label_new (a2);
                gtk_container_add (GTK_CONTAINER (player1), aux);
                break;
            case 2:
                aux = gtk_label_new (a3);
                gtk_container_add (GTK_CONTAINER (player1), aux);
                break;
            case 3:
                aux = gtk_label_new (a4);
                gtk_container_add (GTK_CONTAINER (player1), aux);
                break;
            case 4:
                aux = gtk_label_new (a5);
                gtk_container_add (GTK_CONTAINER (player1), aux);
                break;
            case 5:
                aux = gtk_label_new (a6);
                gtk_container_add (GTK_CONTAINER (player1), aux);
                break;
            case 6:
                aux = gtk_label_new (a7);
                gtk_container_add (GTK_CONTAINER (player1), aux);
                break;
        }
    }

    if(players == 2){
        player2 = gtk_box_new (GTK_ORIENTATION_VERTICAL,5);
        gtk_container_add (GTK_CONTAINER (score), player2);

        char b1[] = "Player 2";
        char b2[] = "Bonus: ";
        strcat(b2, special2);
        char b3[] = "Frutas: ";
        strcat(b3, fruit2);
        char b4[] = "Focas: ";
        strcat(b4, yeti2);
        char b5[] = "Pajaro: ";
        strcat(b5, bird2);
        char b6[] = "Bloque: ";
        strcat(b6, bloque2);
        char b7[] = "Total: ";
        strcat(b7, tot2);
        for(int i = 0; i < 7;i++)
        {
            GtkWidget *aux;
            switch (i)
            {
                case 0:
                    aux = gtk_label_new (b1);
                    gtk_container_add (GTK_CONTAINER (player2), aux);
                    break;
                case 1:
                    aux = gtk_label_new (b2);
                    gtk_container_add (GTK_CONTAINER (player2), aux);
                    break;
                case 2:
                    aux = gtk_label_new (b3);
                    gtk_container_add (GTK_CONTAINER (player2), aux);
                    break;
                case 3:
                    aux = gtk_label_new (b4);
                    gtk_container_add (GTK_CONTAINER (player2), aux);
                    break;
                case 4:
                    aux = gtk_label_new (b5);
                    gtk_container_add (GTK_CONTAINER (player2), aux);
                    break;
                case 5:
                    aux = gtk_label_new (b6);
                    gtk_container_add (GTK_CONTAINER (player2), aux);
                    break;
                case 6:
                    aux = gtk_label_new (b7);
                    gtk_container_add (GTK_CONTAINER (player2), aux);
                    break;
            }
        }
    }

    re = gtk_button_new_with_label ("Re-play");
    if(players == 1){
        gpointer f = (void*) (int) 1;
        g_signal_connect (re, "clicked", G_CALLBACK (create_window), f);}
    else{
        gpointer ff = (void*) (int) 2;
        g_signal_connect (re, "clicked", G_CALLBACK (create_window), ff);}
    g_signal_connect_swapped (re, "clicked", G_CALLBACK (gtk_widget_hide_on_delete), window);
    gtk_container_add (GTK_CONTAINER (box), re);

    menu = gtk_button_new_with_label ("Menu");
    gtk_container_add (GTK_CONTAINER (box), menu);

    salir = gtk_button_new_with_label ("Exit");
    g_signal_connect (salir, "clicked",G_CALLBACK (exit), NULL);
    gtk_container_add (GTK_CONTAINER (box), salir);


    gtk_widget_show_all(window);
    return window;
}

/*******************************************************************************
 * Redraw
 * Genera el movimiento segun la informacion de él y re-dibuja la pantalla de
 * juego.
 * Parametros: N/A
 * Return: N/A
 *******************************************************************************/

void redraw (void)
{
    if(left == true)
    {
        if(pos_x[0] == 0)
        {
            pos_x[0] = 31;
            pos_x[1]--;
        }
        else if (pos_x[1] == 0)
        {
            pos_x[0]--;
            pos_x[1] = 31;
        }
        else
        {
            if(matriz[pos_y[0]][pos_x[0]-1] == 0 &&
               matriz[pos_y[1]][pos_x[0]-1] == 0 &&
               matriz[pos_y[2]][pos_x[0]-1] == 0)
            {
                if(isvalueinarray(pos_x[0]-1,pos_x_N,2) &&  isvalueinarray(pos_y[1],pos_y_N,2))
                {
                    pos_y_N[0] = -1;
                    pos_y_N[1] = -1;
                }
                else if(isvalueinarray(pos_x[0]-1,pos_x_B,1) &&  isvalueinarray(pos_y[1],pos_y_B,2))
                {
                    pos_x_B[0] = -1;
                }
                else if(isvalueinarray(pos_x[0]-1,pos_x_Be,1) &&  isvalueinarray(pos_y[1],pos_y_Be,2))
                {
                    pos_x_Be[0] = -1;
                }
                else if(isvalueinarray(pos_x[0]-1,pos_x_L,2) &&  isvalueinarray(pos_y[1],pos_y_L,2))
                {
                    pos_x_L[0] = -1;
                    pos_x_L[1] = -1;
                }
                pos_x[0]--;
                pos_x[1]--;
            }
        }
        left = false;
    }

    if(left2 == true)
    {
        if(pos2_x[0] == 0)
        {
            pos2_x[0] = 31;
            pos2_x[1]--;
        }
        else if (pos2_x[1] == 0)
        {
            pos2_x[0]--;
            pos2_x[1] = 31;
        }
        else
        {
            pos2_x[0]--;
            pos2_x[1]--;
        }
        left2 = false;
    }

    if (right == true)
    {
        if(pos_x[0] == 31)
        {
            pos_x[0] = 0;
            pos_x[1]++;
        }
        else if (pos_x[1] == 31)
        {
            pos_x[0]++;
            pos_x[1] = 0;
        }
        else
        {
            if(matriz[pos_y[0]][pos_x[1]+1] == 0 &&
               matriz[pos_y[1]][pos_x[1]+1] == 0 &&
               matriz[pos_y[2]][pos_x[1]+1] == 0)
            {
                if(isvalueinarray(pos_x[1]+1,pos_x_N,2) &&  isvalueinarray(pos_y[1],pos_y_N,2))
                {
                    pos_y_N[0] = -1;
                    pos_y_N[1] = -1;
                }
                else if(isvalueinarray(pos_x[1]+1,pos_x_B,1) &&  isvalueinarray(pos_y[1],pos_y_B,2))
                {
                    pos_x_B[0] = -1;
                }
                else if(isvalueinarray(pos_x[1]+1,pos_x_Be,1) &&  isvalueinarray(pos_y[1],pos_y_Be,2))
                {
                    pos_x_Be[0] = -1;
                }
                else if(isvalueinarray(pos_x[1]+1,pos_x_L,2) &&  isvalueinarray(pos_y[1],pos_y_L,2))
                {
                    pos_x_L[0] = -1;
                    pos_x_L[1] = -1;
                }
                pos_x[0]++;
                pos_x[1]++;
            }
        }
        right = false;
    }

    if (right2 == true)
    {
        if(pos2_x[0] == 31)
        {
            pos2_x[0] = 0;
            pos2_x[1]++;
        }
        else if (pos2_x[1] == 31)
        {
            pos2_x[0]++;
            pos2_x[1] = 0;
        }
        else
        {
            pos2_x[0]++;
            pos2_x[1]++;
        }
        right2 = false;
    }

    if(jump != 0 && up == true)
    {
        if(matriz[pos_y[0]-1][pos_x[0]] == 1 ||
           matriz[pos_y[0]-1][pos_x[0]] == 3 ||
           matriz[pos_y[0]-1][pos_x[0]] == 5 ||
           matriz[pos_y[0]-1][pos_x[1]] == 1 ||
           matriz[pos_y[0]-1][pos_x[1]] == 3 ||
           matriz[pos_y[0]-1][pos_x[1]] == 5)
        {
            if(matriz[pos_y[0]-1][pos_x[0]] == 1 ||
               matriz[pos_y[0]-1][pos_x[0]] == 3 ||
               matriz[pos_y[0]-1][pos_x[0]] == 5)
            {matriz[pos_y[0]-1][pos_x[0]] = 0;}
            else if (matriz[pos_y[0]-1][pos_x[1]] == 1 ||
                     matriz[pos_y[0]-1][pos_x[1]] == 3 ||
                     matriz[pos_y[0]-1][pos_x[1]] == 5)
            {matriz[pos_y[0]-1][pos_x[1]] = 0;}
            jump = 0;
        }
        else if(matriz[pos_y[0]-1][pos_x[0]] == 2 ||
                matriz[pos_y[0]-1][pos_x[0]] == 4 ||
                matriz[pos_y[0]-1][pos_x[0]] == 6 ||
                matriz[pos_y[0]-1][pos_x[0]] == 7 ||
                matriz[pos_y[0]-1][pos_x[1]] == 2 ||
                matriz[pos_y[0]-1][pos_x[1]] == 4 ||
                matriz[pos_y[0]-1][pos_x[1]] == 6 ||
                matriz[pos_y[0]-1][pos_x[1]] == 7)
        {
            jump = 0;
        }
        else
        {
            pos_y[0]--;
            pos_y[1]--;
            pos_y[2]--;
            jump--;
        }
    }
    else if (jump == 0 && (up == false || up == true))
    {
        if(matriz[pos_y[2]+1][pos_x[1]] == 1 ||
           matriz[pos_y[2]+1][pos_x[1]] == 2 ||
           matriz[pos_y[2]+1][pos_x[1]] == 3 ||
           matriz[pos_y[2]+1][pos_x[1]] == 4 ||
           matriz[pos_y[2]+1][pos_x[1]] == 5 ||
           matriz[pos_y[2]+1][pos_x[1]] == 6 ||
           matriz[pos_y[2]+1][pos_x[0]] == 1 ||
           matriz[pos_y[2]+1][pos_x[0]] == 2 ||
           matriz[pos_y[2]+1][pos_x[0]] == 3 ||
           matriz[pos_y[2]+1][pos_x[0]] == 4 ||
           matriz[pos_y[2]+1][pos_x[0]] == 5 ||
           matriz[pos_y[2]+1][pos_x[0]] == 6)
        {
            up = false;
        }
        else
        {
            pos_y[0]++;
            pos_y[1]++;
            pos_y[2]++;
            if(pos_y[2] == 10){
                piso = 29;
            }
            if(pos_y[2] == 44){
                piso = 53;
            }
            if(pos_y[2] == piso - 16 && piso != 29)
            {
                piso = piso - 7;
                if(piso < 29){piso = 29;}
            }
            if(pos_y[2] >= piso)
            {
                if(vida != 0)
                {
                    pos_x[0] = 1;
                    pos_x[1] = 2;
                    pos_y[0] = piso - 4;
                    pos_y[1] = piso - 3;
                    pos_y[2] = piso - 2;
                    vida--;
                }
                else
                {
                    g_print ("Game Over\n");
                    gameover();
                    gtk_widget_hide_on_delete(gtk_widget_get_parent(pantalla));
                }
            }
            if(pos2_y[2] >= piso && players == 2)
            {
                if(vida2 != 0)
                {
                    pos2_x[0] = 29;
                    pos2_x[1] = 30;
                    pos2_y[0] = piso - 4;
                    pos2_y[1] = piso - 3;
                    pos2_y[2] = piso - 2;
                    vida2--;
                }
                else
                {
                    g_print ("Game Over\n");
                    gameover();
                    gtk_widget_hide_on_delete(gtk_widget_get_parent(pantalla));
                }
            }
        }
    }

    if(jump2 != 0 && up2 == true)
    {
        if(matriz[pos2_y[0]-1][pos2_x[0]] == 1 ||
           matriz[pos2_y[0]-1][pos2_x[0]] == 3 ||
           matriz[pos2_y[0]-1][pos2_x[0]] == 5 ||
           matriz[pos2_y[0]-1][pos2_x[1]] == 1 ||
           matriz[pos2_y[0]-1][pos2_x[1]] == 3 ||
           matriz[pos2_y[0]-1][pos2_x[1]] == 5)
        {
            if(matriz[pos2_y[0]-1][pos2_x[0]] == 1 ||
               matriz[pos2_y[0]-1][pos2_x[0]] == 3 ||
               matriz[pos2_y[0]-1][pos2_x[0]] == 5)
            {matriz[pos2_y[0]-1][pos2_x[0]] = 0;}
            else if (matriz[pos2_y[0]-1][pos2_x[1]] == 1 ||
                     matriz[pos2_y[0]-1][pos2_x[1]] == 3 ||
                     matriz[pos2_y[0]-1][pos2_x[1]] == 5)
            {matriz[pos2_y[0]-1][pos2_x[1]] = 0;}
            jump2 = 0;
            up2 = false;
        }
        else if(matriz[pos2_y[0]-1][pos2_x[0]] == 2 ||
                matriz[pos2_y[0]-1][pos2_x[0]] == 4 ||
                matriz[pos2_y[0]-1][pos2_x[0]] == 6 ||
                matriz[pos2_y[0]-1][pos2_x[0]] == 7 ||
                matriz[pos2_y[0]-1][pos2_x[1]] == 2 ||
                matriz[pos2_y[0]-1][pos2_x[1]] == 4 ||
                matriz[pos2_y[0]-1][pos2_x[1]] == 6 ||
                matriz[pos2_y[0]-1][pos2_x[1]] == 7)
        {
            jump2 = 0;
            up2 = false;
        }
        else
        {
            pos2_y[0]--;
            pos2_y[1]--;
            pos2_y[2]--;
            jump2--;
            if(jump2 == 0){up2 = false;}
        }
    }
    else if (jump2 == 0 && (up2 == false || up2 == true))
    {
        if(matriz[pos2_y[2]+1][pos2_x[1]] == 1 ||
           matriz[pos2_y[2]+1][pos2_x[1]] == 2 ||
           matriz[pos2_y[2]+1][pos2_x[1]] == 3 ||
           matriz[pos2_y[2]+1][pos2_x[1]] == 4 ||
           matriz[pos2_y[2]+1][pos2_x[1]] == 5 ||
           matriz[pos2_y[2]+1][pos2_x[1]] == 6 ||
           matriz[pos2_y[2]+1][pos2_x[0]] == 1 ||
           matriz[pos2_y[2]+1][pos2_x[0]] == 2 ||
           matriz[pos2_y[2]+1][pos2_x[0]] == 3 ||
           matriz[pos2_y[2]+1][pos2_x[0]] == 4 ||
           matriz[pos2_y[2]+1][pos2_x[0]] == 5 ||
           matriz[pos2_y[2]+1][pos2_x[0]] == 6)
        {
            up2 = false;
        }
        else
        {
            pos2_y[0]++;
            pos2_y[1]++;
            pos2_y[2]++;
            if(pos2_y[2] == 10){
                piso = 29;
            }
            if(pos2_y[2] == 44){
                piso = 54;
            }
            if(pos2_y[2] == piso - 16 && piso != 29)
            {
                piso = piso - 7;
                if(piso < 29){piso = 29;}
            }
            if(pos_y[2] >= piso)
            {
                if(vida != 0)
                {
                    pos_x[0] = 1;
                    pos_x[1] = 2;
                    pos_y[0] = piso - 4;
                    pos_y[1] = piso - 3;
                    pos_y[2] = piso - 2;
                    vida--;
                }
                else
                {
                    g_print ("Game Over\n");
                    gameover();
                    gtk_widget_hide_on_delete(gtk_widget_get_parent(pantalla));
                }
            }
            if(pos2_y[2] >= piso && players == 2)
            {
                if(vida2 != 0)
                {
                    pos2_x[0] = 29;
                    pos2_x[1] = 30;
                    pos2_y[0] = piso - 4;
                    pos2_y[1] = piso - 3;
                    pos2_y[2] = piso - 2;
                    vida2--;
                }
                else
                {
                    g_print ("Game Over\n");
                    gameover();
                    gtk_widget_hide_on_delete(gtk_widget_get_parent(pantalla));
                }
            }
        }
    }


    int j,i,contador,contador2;
    per = "D:\\Utilities\\Downloads\\src\\image\\character(1).png";
    per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(1).png";
    block_7 = "D:\\Utilities\\Downloads\\src\\image\\block(7)(1).png";
    orange = "D:\\Utilities\\Downloads\\src\\image\\naranga(1).png";
    banana = "D:\\Utilities\\Downloads\\src\\image\\banano(1).png";
    eggplant = "D:\\Utilities\\Downloads\\src\\image\\berenjena(1).png";
    lettuce = "D:\\Utilities\\Downloads\\src\\image\\lechuga(1).png";
    GList *children, *iter, *children_i, *iter_i;
    children = gtk_container_get_children(GTK_CONTAINER(pantalla));
    j = piso;
    i = 0;
    int block7 = 0;
    int naranga = 0;
    int banano = 0;
    int berenjena = 0;
    int lechuga = 0;
    contador = 2;
    contador2 = 2;
    children = g_list_reverse(children);

    for(iter = children; iter != NULL; iter = g_list_next(iter))
    {
        j--;
        i = 0;
        children_i = gtk_container_get_children(GTK_CONTAINER(iter->data));
        for(iter_i = children_i; iter_i != NULL; iter_i = g_list_next(iter_i))
        {
            if(isvalueinarray(i,pos_x_N,2) && isvalueinarray(j,pos_y_N,2))
            {
                switch(naranga)
                {
                    case 0:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), orange);
                        orange = "D:\\Utilities\\Downloads\\src\\image\\naranga(2).png";
                        naranga++;
                        break;
                    case 1:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), orange);
                        orange = "D:\\Utilities\\Downloads\\src\\image\\naranga(3).png";
                        naranga++;
                        break;
                    case 2:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), orange);
                        orange = "D:\\Utilities\\Downloads\\src\\image\\naranga(4).png";
                        naranga++;
                        break;
                    case 3:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), orange);
                        break;
                }
            }
            else if(isvalueinarray(i,pos_x_B,1) && isvalueinarray(j,pos_y_B,2))
            {
                switch(banano)
                {
                    case 0:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), banana);
                        banana = "D:\\Utilities\\Downloads\\src\\image\\banano(2).png";
                        banano++;
                        break;
                    case 1:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), banana);
                        break;
                }
            }
            else if(isvalueinarray(i,pos_x_Be,1) && isvalueinarray(j,pos_y_Be,2))
            {
                switch(berenjena)
                {
                    case 0:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), eggplant);
                        eggplant = "D:\\Utilities\\Downloads\\src\\image\\berenjena(2).png";
                        berenjena++;
                        break;
                    case 1:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), eggplant);
                        break;
                }
            }
            else if(isvalueinarray(i,pos_x_L,2) && isvalueinarray(j,pos_y_L,2))
            {
                switch(lechuga)
                {
                    case 0:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), lettuce);
                        lettuce = "D:\\Utilities\\Downloads\\src\\image\\lechuga(2).png";
                        lechuga++;
                        break;
                    case 1:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), lettuce);
                        lettuce = "D:\\Utilities\\Downloads\\src\\image\\lechuga(3).png";
                        lechuga++;
                        break;
                    case 2:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), lettuce);
                        lettuce = "D:\\Utilities\\Downloads\\src\\image\\lechuga(4).png";
                        lechuga++;
                        break;
                    case 3:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), lettuce);
                        break;
                }
            }
            else if(isvalueinarray(i,pos_x,2) && isvalueinarray(j,pos_y,3) && players == 1)
            {
                gtk_image_set_from_file (GTK_IMAGE (iter_i->data), per);
                switch (contador)
                {
                    case 2:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(2).png";
                        contador = contador + 1;
                        break;
                    case 3:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(3).png";
                        contador = contador + 1;
                        break;
                    case 4:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(4).png";
                        contador = contador + 1;
                        break;
                    case 5:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(5).png";
                        contador = contador + 1;
                        break;
                    case 6:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(6).png";
                        contador = contador + 1;
                        break;
                }
            }
            else if(isvalueinarray(i,pos2_x,2) && isvalueinarray(j,pos2_y,3) && players == 2)
            {
                gtk_image_set_from_file (GTK_IMAGE (iter_i->data), per2);
                switch (contador2)
                {
                    case 2:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(2).png";
                        contador2++;
                        break;
                    case 3:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(3).png";
                        contador2++;
                        break;
                    case 4:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(4).png";
                        contador2++;
                        break;
                    case 5:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(5).png";
                        contador2++;
                        break;
                    case 6:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(6).png";
                        contador2++;
                        break;
                }
            }
            else if(matriz[j][i] == 0)
            {
                gtk_image_set_from_file (GTK_IMAGE (iter_i->data), empty);
            }
            else if(matriz[j][i] == 1)
            {
                gtk_image_set_from_file (GTK_IMAGE (iter_i->data), block_1);
            }
            else if(matriz[j][i] == 2)
            {
                gtk_image_set_from_file (GTK_IMAGE (iter_i->data), block_2);
            }
            else if(matriz[j][i] == 3)
            {
                gtk_image_set_from_file (GTK_IMAGE (iter_i->data), block_3);
            }
            else if(matriz[j][i] == 4)
            {
                gtk_image_set_from_file (GTK_IMAGE (iter_i->data), block_4);
            }
            else if(matriz[j][i] == 5)
            {
                gtk_image_set_from_file (GTK_IMAGE (iter_i->data), block_5);
            }
            else if(matriz[j][i] == 6)
            {
                gtk_image_set_from_file (GTK_IMAGE (iter_i->data), block_6);
            }
            else if(matriz[j][i] == 9)
            {
                switch(block7)
                {
                    case 0:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), block_7);
                        block_7 = "D:\\Utilities\\Downloads\\src\\image\\block(7).png";
                        block7++;
                        break;
                    case 1:
                        gtk_image_set_from_file (GTK_IMAGE (iter_i->data), block_7);
                        break;
                }
            }
            else if(matriz[j][i] == 11)
            {

            }
            else if(matriz[j][i] == 12)
            {

            }
            else if(matriz[j][i] == 13)
            {

            }
            else if(matriz[j][i] == 14)
            {
            }
            i++;
        }
    }
    g_list_free(children_i);
    g_list_free(children);
}

/*******************************************************************************
 * On Key Press Event
 * Validad los movimientos del jugador,segun la tecla presionada.
 * Parametros:
 *		widget: el widget desde donde se llamo esta funcion.
 *		event: el evento que hace referencia a la tecla que se presiono.
 * Return:
 *		False.
 *******************************************************************************/

static gboolean on_key_press_event (GtkWidget *widget, GdkEventKey *event)
{
    // Player 1
    // Arriba
    if(event->keyval == 119 && players == 1)
    {
        if(jump == 0 && up == false){
            jump = 8;}
        up = true;
    }
        // Izquierda
    else if(event->keyval == 97 && players == 1)
    {
        left = true;
    }
        // Abajo
    else if(event->keyval == 115 && players == 1)
    {
        g_print ("Abajo\n");
    }
        // Derecha
    else if(event->keyval == 100 && players == 1)
    {
        right = true;
    }
        // Player 2
        // Arriba
    else if(event->keyval == 65362 && players == 2)
    {
        if(jump2 == 0 && up2 == false){
            jump2 = 8;}
        up2 = true;
    }
        // Izquierda
    else if(event->keyval == 65361 && players == 2)
    {
        left2 = true;
    }
        // Abajo
    else if(event->keyval == 65364 && players == 2)
    {
        g_print ("Abajo 2\n");
    }
        // Derecha
    else if(event->keyval == 65363 && players == 2)
    {
        right2 = true;
    }
    return FALSE;
}

/*******************************************************************************
 * Create Window
 * Crea la pantalla de juego segun la cantidad de jugadores.
 * Parametros:
 *		widget: el widget desde donde se llamo esta funcion.
 *		data: integer que hace referencia a la cantidad de jugadores.
 * Return: N/A
 *******************************************************************************/

static void create_window (GtkWidget *widget, int data)
{
    players = data;
    GtkWidget *window;
    GList *children, *iter;
    int j,contador,contador2;
    int block7 = 0;
    int naranga = 0;
    int banano = 0;
    int berenjena = 0;
    int lechuga = 0;

    per = "D:\\Utilities\\Downloads\\src\\image\\character(1).png";
    per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(1).png";
    block_7 = "D:\\Utilities\\Downloads\\src\\image\\block(7)(1).png";
    orange = "D:\\Utilities\\Downloads\\src\\image\\naranga(1).png";
    banana = "D:\\Utilities\\Downloads\\src\\image\\banano(1).png";
    eggplant = "D:\\Utilities\\Downloads\\src\\image\\berenjena(1).png";
    lettuce = "D:\\Utilities\\Downloads\\src\\image\\lechuga(1).png";

    int num = rand() % 2;
    srand(time(0));
    if(num == 1)
    {
        pos_y_N[0] = 23;
        pos_y_N[1] = 24;
    }
    num = rand() % 2;
    srand(time(0));
    if(num == 1)
    {
        pos_x_B[0] = 23;
    }
    num = rand() % 2;
    srand(time(0));
    if (num == 1){
        pos_x_Be[0] = 10;
    }
    num = rand() % 2;
    srand(time(0));
    if(num == 1){
        pos_x_L[0] = 8;
        pos_x_L[1] = 9;
    }

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "iCE Climber");
    gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);
    g_signal_connect (window, "destroy",G_CALLBACK (exit), NULL);
    g_signal_connect (window, "key-press-event", G_CALLBACK(on_key_press_event), 0);

    pantalla = gtk_box_new (GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add (GTK_CONTAINER (window), pantalla);

    for(int x = 0; x != 29;x++)
    {
        GtkWidget *box;
        box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL,0);
        gtk_container_add (GTK_CONTAINER (pantalla), box);
    }

    children = gtk_container_get_children(GTK_CONTAINER(pantalla));
    j = piso;
    contador = 2;
    contador2 = 2;
    children = g_list_reverse(children);

    for(iter = children; iter != NULL; iter = g_list_next(iter))
    {
        j--;
        for(int i = 0; i != 32; i++)
        {
            if(isvalueinarray(i,pos_x,2) && isvalueinarray(j,pos_y,3) && players == 1)
            {
                GtkWidget *image;
                image = gtk_image_new ();
                gtk_image_set_from_file (GTK_IMAGE (image), per);
                gtk_container_add (GTK_CONTAINER (iter->data), image);
                switch (contador)
                {
                    case 2:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(2).png";
                        contador++;
                        break;
                    case 3:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(3).png";
                        contador++;
                        break;
                    case 4:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(4).png";
                        contador++;
                        break;
                    case 5:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(5).png";
                        contador++;
                        break;
                    case 6:
                        per = "D:\\Utilities\\Downloads\\src\\image\\character(6).png";
                        contador++;
                        break;
                }
            }
            else if(isvalueinarray(i,pos2_x,2) && isvalueinarray(j,pos2_y,3) && players == 2)
            {
                GtkWidget *image;
                image = gtk_image_new ();
                gtk_image_set_from_file (GTK_IMAGE (image), per2);
                gtk_container_add (GTK_CONTAINER (iter->data), image);
                switch (contador2)
                {
                    case 2:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(2).png";
                        contador2++;
                        break;
                    case 3:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(3).png";
                        contador2++;
                        break;
                    case 4:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(4).png";
                        contador2++;
                        break;
                    case 5:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(5).png";
                        contador2++;
                        break;
                    case 6:
                        per2 = "D:\\Utilities\\Downloads\\src\\image\\character2(6).png";
                        contador2++;
                        break;
                }
            }
            else if(matriz[j][i] == 0)
            {
                GtkWidget *image;
                image = gtk_image_new ();
                gtk_image_set_from_file (GTK_IMAGE (image), empty);
                gtk_container_add (GTK_CONTAINER (iter->data), image);
            }
            else if(matriz[j][i] == 1)
            {
                GtkWidget *image;
                image = gtk_image_new ();
                gtk_image_set_from_file (GTK_IMAGE (image), block_1);
                gtk_container_add (GTK_CONTAINER (iter->data), image);
            }
            else if(matriz[j][i] == 2)
            {
                GtkWidget *image;
                image = gtk_image_new ();
                gtk_image_set_from_file (GTK_IMAGE (image), block_2);
                gtk_container_add (GTK_CONTAINER (iter->data), image);
            }
            else if(matriz[j][i] == 3)
            {
                GtkWidget *image;
                image = gtk_image_new ();
                gtk_image_set_from_file (GTK_IMAGE (image), block_3);
                gtk_container_add (GTK_CONTAINER (iter->data), image);
            }
            else if(matriz[j][i] == 4)
            {
                GtkWidget *image;
                image = gtk_image_new ();
                gtk_image_set_from_file (GTK_IMAGE (image), block_4);
                gtk_container_add (GTK_CONTAINER (iter->data), image);
            }
            else if(matriz[j][i] == 5)
            {
                GtkWidget *image;
                image = gtk_image_new ();
                gtk_image_set_from_file (GTK_IMAGE (image), block_5);
                gtk_container_add (GTK_CONTAINER (iter->data), image);
            }
            else if(matriz[j][i] == 6)
            {
                GtkWidget *image;
                image = gtk_image_new ();
                gtk_image_set_from_file (GTK_IMAGE (image), block_6);
                gtk_container_add (GTK_CONTAINER (iter->data), image);
            }
            else if(matriz[j][i] == 9)
            {
                GtkWidget *image;
                switch(block7)
                {
                    case 0:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), block_7);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        block_7 = "D:\\Utilities\\Downloads\\src\\image\\block(7).png";
                        block7++;
                        break;
                    case 1:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), block_7);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        break;
                }
            }
            else if(matriz[j][i] == 11)
            {
                GtkWidget *image;
                switch(naranga)
                {
                    case 0:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), orange);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        orange = "D:\\Utilities\\Downloads\\src\\image\\naranga(1).png";
                        naranga++;
                        break;
                    case 1:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), orange);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        orange = "D:\\Utilities\\Downloads\\src\\image\\naranga(2).png";
                        naranga++;
                        break;
                    case 2:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), orange);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        orange = "D:\\Utilities\\Downloads\\src\\image\\naranga(3).png";
                        naranga++;
                        break;
                    case 3:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), orange);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        break;
                }
            }
            else if(matriz[j][i] == 12)
            {
                GtkWidget *image;
                switch(banano)
                {
                    case 0:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), banana);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        banana = "D:\\Utilities\\Downloads\\src\\image\\banano(2).png";
                        banano++;
                        break;
                    case 1:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), banana);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        break;
                }
            }
            else if(matriz[j][i] == 13)
            {
                GtkWidget *image;
                switch(berenjena)
                {
                    case 0:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), eggplant);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        eggplant = "D:\\Utilities\\Downloads\\src\\image\\berenjena(2).png";
                        berenjena++;
                        break;
                    case 1:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), eggplant);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        break;
                }
            }
            else if(matriz[j][i] == 14)
            {
                GtkWidget *image;
                switch(lechuga)
                {
                    case 0:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), lettuce);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        lettuce = "D:\\Utilities\\Downloads\\src\\image\\lechuga(2).png";
                        lechuga++;
                        break;
                    case 1:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), lettuce);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        lettuce = "D:\\Utilities\\Downloads\\src\\image\\lechuga(3).png";
                        lechuga++;
                        break;
                    case 2:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), lettuce);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        lettuce = "D:\\Utilities\\Downloads\\src\\image\\lechuga(4).png";
                        lechuga++;
                        break;
                    case 3:
                        image = gtk_image_new ();
                        gtk_image_set_from_file (GTK_IMAGE (image), lettuce);
                        gtk_container_add (GTK_CONTAINER (iter->data), image);
                        break;
                }
            }
        }
    }
    g_list_free(children);

    gtk_widget_add_tick_callback(window,redraw,NULL,NULL);
    gtk_widget_show_all(window);
}

/*******************************************************************************
 * Create Players
 * Crea en la ventana inicial los botones que van a decidir si va a jugar una o
 * dos personas.
 * Parametros:
 *		widget: el widget desde donde se llamo esta funcion.
 *		data: el widget en donde se crearan los botones.
 * Return: N/A
 *******************************************************************************/

void create_players(GtkWidget *widget, gpointer data)
{
    GList *children, *iter;
    GtkWidget *p1, *p2;

    children = gtk_container_get_children(GTK_CONTAINER(data));
    for(iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);

    p1 = gtk_button_new_with_label ("1-Player");
    gpointer f = (void*) (int) 1;
    g_signal_connect (p1, "clicked", G_CALLBACK (create_window), f);
    g_signal_connect_swapped (p1, "clicked", G_CALLBACK (gtk_widget_hide_on_delete), gtk_widget_get_parent(gtk_widget_get_parent(widget)));
    gtk_container_add (GTK_CONTAINER(data), p1);

    p2 = gtk_button_new_with_label ("2-Player");
    gpointer ff = (void*) (int) 2;
    g_signal_connect (p2, "clicked", G_CALLBACK (create_window), ff);
    g_signal_connect_swapped (p2, "clicked", G_CALLBACK (gtk_widget_hide_on_delete), gtk_widget_get_parent(gtk_widget_get_parent(widget)));
    gtk_container_add (GTK_CONTAINER(data), p2);

    gtk_widget_show_all(data);
}

/*******************************************************************************
 * Create Observe
 * Crea en la ventana inicial los textbox que se necesitan rellenar para saber
 * poder generar el observer.
 * Parametros:
 *		widget: el widget desde donde se llamo esta funcion.
 *		data: el widget en donde se crearan los textbox.
 * Return: N/A
 *******************************************************************************/

void create_observe(GtkWidget *widget, gpointer data)
{
    GList *children, *iter;
    GtkWidget *p1, *ip, *identificador;

    children = gtk_container_get_children(GTK_CONTAINER(data));
    for(iter = children; iter != NULL; iter = g_list_next(iter))
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    g_list_free(children);

    ip = gtk_entry_new();
    gtk_entry_set_text (ip, "IP");
    gtk_container_add (GTK_CONTAINER(data), ip);

    identificador = gtk_entry_new();
    gtk_entry_set_text (identificador, "Identificador");
    gtk_container_add (GTK_CONTAINER(data), identificador);

    p1 = gtk_button_new_with_label ("Conectar");
    gpointer f = (void*) (int) 0;
    g_signal_connect (p1, "clicked", G_CALLBACK (create_window), f);
    g_signal_connect_swapped (p1, "clicked", G_CALLBACK (gtk_widget_hide_on_delete), gtk_widget_get_parent(gtk_widget_get_parent(widget)));
    gtk_container_add (GTK_CONTAINER(data), p1);

    gtk_widget_show_all(data);
}

/*******************************************************************************
 * Main
 * Crea la ventana en la que se decidira que va a hacer la interfaz de juego.
 *******************************************************************************/

int main (int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *play, *observer;
    GtkWidget *box, *opcion;
    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "iCE Climber");
    gtk_window_set_default_size (GTK_WINDOW (window), 420, 150);
    g_signal_connect (window, "destroy",G_CALLBACK (exit), NULL);

    box = gtk_box_new (GTK_ORIENTATION_VERTICAL,5);
    gtk_container_add (GTK_CONTAINER (window), box);

    opcion = gtk_box_new (GTK_ORIENTATION_HORIZONTAL,5);

    play = gtk_button_new_with_label ("Play");
    g_signal_connect (play, "clicked", G_CALLBACK (create_players), opcion);
    gtk_container_add (GTK_CONTAINER (box), play);

    observer = gtk_button_new_with_label ("Observer");
    g_signal_connect (observer, "clicked", G_CALLBACK (create_observe), opcion);
    gtk_container_add (GTK_CONTAINER (box), observer);

    gtk_container_add (GTK_CONTAINER (box), opcion);

    gtk_widget_show_all(window);

    gtk_main ();
    return 0;
}
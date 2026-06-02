#include <stdio.h>
typedef struct{
    int rows;
    int cols;
    char pixels[50][100];
}Canvas;

void initializeCanvas(Canvas *c);
void displayCanvas(Canvas *c);
void drawRectangle(Canvas *c,int r,int col,int h,int w);

int main(){
    printf("2D Graphics Editor Project\n");

    Canvas picture;

    picture.rows=20;
    picture.cols=40;

    initializeCanvas(&picture);
    drawRectangle(&picture,3,5,10,20);
    printf("\n===== 2D GRAPHICS EDITOR =====\n\n");
    displayCanvas(&picture);

    return 0;
}
void initializeCanvas(Canvas *c){
    int i,j;
    for(i=0;i < c->rows;i++){
        for(j=0;j <c->cols;j++){
            c->pixels[i][j]='_';
        }
    }
}
void displayCanvas(Canvas *c){
    int i,j;
    for(i=0;i <c->rows;i++){
        for(j=0;j <c->cols;j++){
            printf("%c", c->pixels[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(Canvas *c,int r,int col,int h,int w){
    int i,j;
    for(i=r;i < r+h;i++){
        for(j=col;j < col+w;j++){
            if(i==r||i==r+h-1||j==col||j==col+w-1){
                c->pixels[i][j]='*';
            }
        }
    }
}
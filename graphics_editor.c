#include <stdio.h>
typedef struct{
    int rows;
    int cols;
    char pixels[50][100];
}Canvas;

void initializeCanvas(Canvas *c);
void displayCanvas(Canvas *c);
void drawRectangle(Canvas *c,int r,int col,int h,int w);
void drawLine(Canvas *c,int r1,int c1,int r2,int c2);
void drawTriangle(Canvas *c,int topRow,int topCol,int height);
void drawCircle(Canvas *c,int centerRow,int centerCol,int radius);

int main(){
    printf("2D Graphics Editor Project\n");

    Canvas picture;
    int choice;

    picture.rows=20;
    picture.cols=40;
    
    initializeCanvas(&picture);
    printf("Canvas initialized successfully.\n");

    do{
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Add Rectangle\n");
        printf("2. Add Line\n");
        printf("3. Add Triangle\n");
        printf("4. Add Circle\n");
        printf("5. Display Picture\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:{
            int r,col,h,w;
            printf("Enter row column height width: ");
            scanf("%d%d%d%d",&r,&col,&h,&w);
            drawRectangle(&picture,r,col,h,w);
            break;
        }
        case 2:{
            int r1,c1,r2,c2;
            printf("Enter start row and column: ");
            scanf("%d%d",&r1,&c1);
            printf("Enter end row and column: ");
            scanf("%d%d",&r2,&c2);
            drawLine(&picture,r1,c1,r2,c2);
            break;
        }
        case 3:{
            int topRow,topCol,height;
            printf("Enter top row,top column,height: ");
            scanf("%d%d%d",&topRow,&topCol,&height);
            drawTriangle(&picture,topRow,topCol,height);
            break;
        }
        case 4:{
            int centerRow,centerCol,radius;
            printf("Enter center row,center column,radius: ");
            scanf("%d%d%d",&centerRow,&centerCol,&radius);
            drawCircle(&picture,centerRow,centerCol,radius);
            break;
        }
        case 5:{
            displayCanvas(&picture);
            break;
        }
        case 6:{
            printf("Exiting...\n");
            break;
        }
        default:
            printf("Invalid choice!\n");
        }
    }while(choice!=6);

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
void drawLine(Canvas *c,int r1,int c1,int r2,int c2){
    int i;
    if(r1==r2){
        if(c1>c2){
            int temp=c1;
            c1=c2;
            c2=temp;
        }
        for(i=c1;i<=c2;i++){
            c->pixels[r1][i]='*';
        }
    }
    else if(c1==c2){
        if(r1>r2){
            int temp=r1;
            r1=r2;
            r2=temp;
        }
        for(i=r1;i<=r2;i++){
            c->pixels[i][c1]='*';
        }
    }
    else{
        int rowStep,colStep;
        int row=r1;
        int col=c1;
        if(r2>r1){
            rowStep=1;
        }
        else{
            rowStep=-1;
        }
        if(c2>c1){
            colStep=1;
        }
        else{
            colStep=-1;
        }
        while(1){
            c->pixels[row][col]='*';
            if(row==r2 && col==c2){
                break;
            }
            row+=rowStep;
            col+=colStep;
        }
    }
}
void drawTriangle(Canvas *c,int topRow,int topCol,int height){
    int bottomRow;
    bottomRow=topRow+height-1;
    drawLine(c,topRow,topCol,bottomRow,topCol-height+1);
    drawLine(c,topRow,topCol,bottomRow,topCol+height-1);
    drawLine(c,bottomRow,topCol-height+1,bottomRow,topCol+height-1);
}
void drawCircle(Canvas *c,int centerRow,int centerCol,int radius){
    int row,col;
    int distanceSquared;
    int radiusSquared;
    
    radiusSquared=radius*radius;
    for(row=0;row<c->rows;row++){
        for(col=0;col<c->cols;col++){
            distanceSquared=(row-centerRow)*(row-centerRow)+
            (col-centerCol)*(col-centerCol);
            if(distanceSquared>=radiusSquared-radius && 
                distanceSquared<=radiusSquared+radius){
                    c->pixels[row][col]='*';
            }
        }
    }
}
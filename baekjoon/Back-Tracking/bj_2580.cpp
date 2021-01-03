#include<stdio.h>
#define size 9
int map[size][size];
int breakIdx;
void traverse(int, int);
int inspect(int, int, int);
int main(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf(" %d",&map[i][j]);
        }
    }
    traverse(0,0);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}

void traverse(int x, int y){
    if(map[x][y]>0){
        if(x==size-1 && y==size-1){
            breakIdx++;
            return;
        }
        if(y<size-1)
            traverse(x,y+1);
        else
            traverse(x+1,0);    
    }
    else{
        for(int num=1;num<10;num++){
            if(inspect(x,y,num)){
                map[x][y]=num;
                if(x==size-1 && y==size-1){
                    breakIdx++;
                    return;        
                }
                if(y<size-1)
                    traverse(x,y+1);
                else
                    traverse(x+1,0);
                if(breakIdx>0)
                    return;
                map[x][y]=0;
            }
        }
    }    
}

int inspect(int x, int y, int n){
    for(int i=0;i<9;i++){
        if(map[x][i]==n)
            return 0;
    }
    for(int i=0;i<9;i++){
        if(map[i][y]==n)
            return 0;
    }
    int cornerX=(x/3)*3;
    int cornerY=(y/3)*3;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if(map[cornerX+i][cornerY+j]==n)
                return 0;
        }    
    }
    return 1;   
}
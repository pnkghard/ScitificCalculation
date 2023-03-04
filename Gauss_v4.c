#include<stdio.h>

#define N 3

//print matrix
void printMat(float mat[N][N+1]){
    int i, j;
    printf("\n");
    for(i=0; i<N; i++){
        for(j=0; j<N+1; j++){
            printf("%lf\t", mat[i][j]);
        }
        printf("\n");
    }
}

//upper tringle gauss elemination
void gaussEl(float mat[N][N+1]){
    int i, j, k;
    for(i=0; i<N; i++){
        float div = mat[i][i];
        for(j=0; j<N+1; j++){
            mat[i][j] /= div;
        }

        for(j=i+1; j<N; j++){
            float mul = mat[j][i];
            for(k=0; k<N+1; k++){
                mat[j][k] = mat[j][k] - (mul*mat[i][k]);
            }
        }

        printMat(mat);
    }
}

//finding value of x, y, z
void finalval(float mat[N][N+1]){
    float X[N];
    int k = N;
    int i, j;
    for(i=N-1; i>=0; i--){
        X[i] = mat[i][k];
        for(j=N-1; j>i; j--){
            X[i] -= X[j]*mat[i][j];
        }
    }
    printf("\nFinal value of x, y, z :\n");
    for(i=0; i<N; i++){
        printf("%lf\t",X[i]);
    }
}

int main(int argc, char** argv){
    float A[N][N+1] = {{2.0,3.0,1.0,-1.0},{5.0,-2.0,5.0,-4.0},{1.0,-1.0,3.0,-3.0}};//,{3.0,4.0,-7.0,2.0}};
    system("clear");
    printf("Gauss Elemination Method for linear equation :\n");
    printMat(A);
    printf("\n");
    gaussEl(A);
    finalval(A);
    printf("\n");
    return 0;
}
#include <stdio.h>
# define n 4
main()

{
//float a[n][n]={{1.0,2.0,-4.0},{2.0,5.0,-9.0},{3.0,-2.0,3.0}};
float a[n][n]={{2.0,3.0,1.0,-1.0},{5.0,-2.0,5.0,-4.0},{1.0,-1.0,3.0,-3.0},{3.0,4.0,-7.0,2.0}};
float ap[n][n];
int i,j,k;

//initialize matrix 'a'
for (i=0;i<n;i++){
	for (j=0;j<n;j++){
		printf("%f\t",a[i][j]);
          }
	printf("\n");
}


for (k=0;k<n;k++){
	for(j=k;j<n;j++){
		ap[k][j]=a[k][j]/a[k][k]; //scaling
	 	}

         for(j=k;j<n;j++){
         	a[k][j]=ap[k][j];   //copy scaled row to orig matrix 
	 	}

                                    //elimnination using scaled row
         for(i=k+1;i<n;i++){
         	for(j=k;j<n;j++){
			ap[i][j]=a[i][j]-a[i][k]*a[k][j];
			}
		}

         for(i=k+1;i<n;i++){
         	for(j=k;j<n;j++){
			a[i][j]=ap[i][j]; //copy eliminated rows to orig matrix
			}
		}


        printf("\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			printf("%f\t",a[i][j]);
          		}
		printf("\n");
		}

}

}

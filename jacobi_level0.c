#include<stdio.h>
#include<malloc.h>
#include<math.h>

#define NR 4 
#define NC 4 
#define itmax 2 


main(){

int i,j;

int iter;

int offset,b,bp;

double dx,dy,x,y;

double *u1;
double *u2;
double *tmp;

u1=(double *)malloc((NR+2)*(NC+2)*sizeof(double));
u2=(double *)malloc((NR+2)*(NC+2)*sizeof(double));


printf("layout\n");    
for(i=0;i<=NR+1;i++){
    offset=i*(NC+2);
    for(j=0;j<=NC+1;j++){
       b=offset+j;    
       printf(" %d\t",b);
    }
    printf("\n");    
}

    printf("\n");    
    printf("\n");    
    printf("\n");    
/* 
printf("\n");    
printf("u1\n");    
for(i=0;i<=NR+1;i++){
    offset=i*(NC+2);
    for(j=0;j<=NC+1;j++){
       b=offset+j;    
       u1[b]=0.0;
       printf("%f\t",u1[b]);
       
    }
    printf("\n");    
}

printf("\n");    
printf("u2\n");    
for(i=0;i<=NR+1;i++){
    offset=i*(NC+2);
    for(j=0;j<=NC+1;j++){
       b=offset+j;    
       u2[b]=0.0;
       printf("%f\t",u2[b]);
    }
    printf("\n");    
}
*/  


                                             //Discretization 
dx=1.0/(double)(NC+1); 
dy=1.0/(double)(NR+1);                     

                                               //initialize upper boundary
for(j=0;j<=NC+1;j++){
    b=(NR+1)*(NC+2)+j;
    x=(double)j*dx;
  //  u1[b]=sin(2*3.14*x);
  printf("%d\t%f \n",b,x);
}

    printf("\n");    
    printf("\n");    

/*
for(j=0;j<=NC+1;j++){
    b=(NR+1)*(NC+2)+j;
    x=(double)j*dx;
    u2[b]=sin(2*3.14*x);
}

*/
                                                //initialize right boubdary
for(i=0;i<=NR+1;i++){
    b=i*(NC+2)+(NC+1);
    y=(double)i*dy;
//    u1[b]=-sin(3.14*y);
      printf("%d\t%f \n",b,y);
}

/*
for(i=0;i<=NR+1;i++){
    b=i*(NC+2)+(NC+1);
    y=(double)i*dy;
    u2[b]=-sin(3.14*y);
}
*/


/*
printf("\n");    
printf("u1 boundary initialized\n");    
for(i=0;i<=NR+1;i++){
    b=i*(NC+2);
    for(j=0;j<=NC+1;j++){
//       b=offset+j;    
       printf("%f\t",u1[b]);
         b++; 
    }
    printf("\n");    
}
*/
//printf("#u2 modified\n");    
                                   //Jacobi iteration 
for(iter=1;iter<=itmax;iter++){
                                   //Jacobi kernel
	for(i=1;i<=NR;i++){
	    b=i*(NC+2)+1;
	    for(j=1;j<=NC;j++){
	       u2[b]=0.25*(u1[b-1]+u1[b+1]+u1[b-(NC+2)]+u1[b+(NC+2)]);
//               printf("%d\t%d\t%d\t%d\n",i,j,b,bp);   
               b++;
	    }
	}
/*	
	printf("\n");    
        printf("#u2 modified\n");    
	for(i=0;i<=NR+1;i++){
	    offset=i*(NC+2);
	    for(j=0;j<=NC+1;j++){    
	       b=offset+j;    
	       printf("%f\t",u2[b]);
	    }
	    printf("\n");    
	}
*/
                                     // Interchange READ & WRITE => u1<=>u2
        tmp=u1;
        u1=u2;
        u2=tmp;
}

/*
	for(i=0;i<=NR+1;i++){
	    b=i*(NC+2);
            y=(double)i*dy; 
	    for(j=0;j<=NC+1;j++){
               x=(double)j*dx;
	       printf("%f\t%f\t%f\n",x,y,u2[b]);
               b++; 
	    }
	    printf("\n");    
	}

*/

}

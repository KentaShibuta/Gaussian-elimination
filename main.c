#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "gauss.h"
#include "malloc.h"
#include "global_variable.h"


int main(void)
{
    double **A_b;
    //nnode = 3;
    double A[nnode][nnode]={{2, 4, -2},
                {1, 2, 1}, 
                {1, 3, 2}};
    double b[nnode] = {8, 6, 9};

    A_b = (double **)malloc2d(sizeof(double), nnode, nnode+1);
    x = (double *)malloc(sizeof(double) * nnode); 
//---------------------------------------------------------
    for(int i=0; i<nnode; i++){ // 拡大係数行列の作成
        for(int j=0; j<nnode+1; j++){
            if(j != nnode){
                A_b[i][j] = A[i][j];
            }else{
                A_b[i][nnode] = b[i];
            }
        }
    }

    for(int i=0; i<nnode; i++){ // 拡大係数行列の出力
        for(int j=0; j<nnode+1; j++){
            printf("%3f ", A_b[i][j]);
        }
        printf("\n");
    }

	gauss(A_b); //
//---------------------------------------------------------

    for(int i=0; i<nnode; i++){
        printf("x%d=%f\n", i, x[i]);
    }

    delete_double1d(x);
    delete_double2d(A_b);

	return 0;
}
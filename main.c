#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "gauss.h"
#include "malloc.h"
#include "global_variable.h"
#include "time.h"

int main(void)
{
    double **A_b;
    
    // 動作確認用の定数行列
    
    double A[nnode][nnode]={{2, 4, -2},
                {1, 2, 1}, 
                {1, 3, 2}};
    double b[nnode] = {8, 6, 9};
    

    /////////////////////////////
    /*
    double **A;
    srand((unsigned int) time(NULL)); // 乱数の種を設定
    A = (double **)malloc2d(sizeof(double), nnode, nnode+1);

    for(int i=0; i<nnode; i++){ // 行列の初期化
        for(int j=0; j<nnode; j++){
            A[i][j] = rand()/1000;
        }
    }

    double *x_b;
    x_b = (double *)malloc(sizeof(double) * nnode); 
    for(int i=0; i<nnode; i++){ // 決め打ちする解ベクトルの初期化
        x_b[i] = rand()/1000;
    }

    printf("入力した解ベクトル\n");
    for(int i=0; i<nnode; i++){ // 決め打ちする解ベクトルの初期化
        printf("x[%d] = %23.15e\n", i, x_b[i]);
    }

    double *b;
    b = (double *)malloc(sizeof(double) * nnode); 
    for(int i=0; i<nnode; i++){ // 定数ベクトルの初期化
        b[i] = 0;
    }

    for(int i=0; i<nnode; i++){
        for(int j=0; j<nnode; j++){
            b[i] += A[i][j] * x_b[j];
        }
    }
    */
    //////////////////////////////

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

	gauss(A_b);
//---------------------------------------------------------

    printf("計算結果\n");
    for(int i=0; i<nnode; i++){
        printf("x%d=%f\n", i, x[i]);
    }

    //////////////////////
    /*
    printf("差分\n");
    for(int i=0; i<nnode; i++){
        printf("x-xb[%d]=%23.15e\n", i, x[i]-x_b[i]);
    }
    */
    //////////////////////

    delete_double1d(x);
    delete_double2d(A_b);

    ///////////////////////
    /*
    delete_double2d(A);
    delete_double1d(x_b);
    delete_double1d(b);
    */
    ///////////////////////

	return 0;
}
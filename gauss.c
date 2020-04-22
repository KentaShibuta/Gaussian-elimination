// 2020.04.22 Kenta Shibuta
// 解ベクトル x[nnode]はグローバル変数の定義に合わせて適宜変更すること
#include <math.h>
#include "global_variable.h"
void gauss(double **a)
{
	int i, j, k, l, pivot;
	//double x[nnode];
	double p, q, m, b[1][nnode + 1];

	for (i = 0; i<nnode; i++) { // ピポットの選択
		m = 0;
		pivot = i;

		for (l = i; l<nnode; l++) {
			/*i列の中で一番値が大きい行を選ぶ*/
			if (fabs(a[l][i])>m) {
				m = fabs(a[l][i]);
				pivot = l;
			}
		}

		/*pivotがiと違えば、行の入れ替え*/
		if (pivot != i) {
			for (j = 0; j<nnode + 1; j++) {
				b[0][j] = a[i][j];
				a[i][j] = a[pivot][j];
				a[pivot][j] = b[0][j];
			}
		}
	}

	for (k = 0; k<nnode; k++) {
		p = a[k][k];              //対角要素を保存
								  /*対角要素は1になることがわかっているので直接代入*/
		a[k][k] = 1;

		for (j = k + 1; j<nnode + 1; j++) { // 対角成分以外の行成分を対角で割る
			a[k][j] /= p;
		}

		for (i = k + 1; i<nnode; i++) {
			q = a[i][k];

			for (j = k + 1; j<nnode + 1; j++) {
				a[i][j] -= q * a[k][j];
			}
			/*0となることがわかっているので直接代入*/
			a[i][k] = 0;
		}
	}

	/*解の計算*/
    
	for (i = nnode - 1; i >= 0; i--) {
        x[i] = a[i][nnode];
        for (j = nnode - 1; j > i; j--) {
            x[i] -= a[i][j] * x[j];
        }
	}	
}
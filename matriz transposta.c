#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


float** aloca_matriz(int m, int n)
{
	/* aloca */
	int i, j;
	float** mat = (float**)malloc(m* sizeof(float*));

	for (i = 0; i < m; i++)
		mat[i] = (float*)malloc(n * sizeof(float));

	/* preenche */
	printf("Digite os elementos da matriz:\n");
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%f", &mat[i][j]);

	return mat;
}
void imprime_matriz(int m, int n, float** matriz)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			printf("|%.2f", matriz[i][j]);
			if (j == (n - 1))
				printf("|\n");
		}
}
float** transposta(int m, int n, float** mat)
{
	int i, j;
	float** trp;

	/* aloca matriz transposta: n linhas, m colunas */
	trp = (float**)malloc(n * sizeof(float*));
	for (i = 0; i < n; i++)
		trp[i] = (float*)malloc(m * sizeof(float));

	/* preenche matriz */
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			trp[j][i] = mat[i][j];
			
	return trp;
}

int main(void)
{
	int i;
	int m, n;
	float** matriz;
	float** transp;

	/* coleta dados */
	printf("Digite o numero de linhas e o numero de colunas da matriz abaixo:\n");
	scanf("%d\n%d", &m, &n);
	
	/*- matriz original */
	matriz = aloca_matriz(m, n);
	printf("\nA matriz original eh:\n");
	imprime_matriz(m, n, matriz);

	/*matriz transposta */
	transp = transposta(m, n, matriz); 
	printf("\nA matriz transposta eh:\n");
	imprime_matriz(n, m, transp);

	printf("\n");

	/* libera mem�ria */
	for (i = 0; i < m; i++)
		free(matriz[i]);
	free(matriz);
	for (i = 0; i < n; i++)
		free(transp[i]);
	free(transp);
	
	return 0;
}
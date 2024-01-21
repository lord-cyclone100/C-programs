#include<stdio.h>

void print_matrix(int mat[10][10],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	return;
}

int check_sparse(int mat[10][10],int m,int n){
	int i,j,z=0,nz=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]==0){
				z++;
			}
			else{
				nz++;
			}
		}
	}
	if(z>nz){
		return 1;
	}
	else{
		return -1;
	}
}

int sparse_nonzero(int mat[10][10],int m,int n){
	int i,j,nz=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]!=0){
				nz++;
			}
		}
	}
	return nz;
}

void sparse_representation(int mat[10][10],int m,int n){
	int c = sparse_nonzero(mat,m,n);
	int sp[c][3],i,j,k=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(mat[i][j]!=0){
				sp[k][0]=i;
				sp[k][1]=j;
				sp[k][2]=mat[i][j];
				k++;
			}
		}
	}
	for(i=0;i<c;i++){
		for(j=0;j<n;j++){
			printf("%d ",sp[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int a[10][10],b[10][10],i,j,m,n;
	printf("Enter no of rows for the matrices:");
	scanf("%d",&m);
	printf("Enter no of columns for the matrices:");
	scanf("%d",&n);
	printf("Enter elements for the 1st matrix:");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("The 1st matrix:\n");
	print_matrix(a,m,n);
	printf("Enter elements for the 2nd matrix:");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	printf("The 2nd matrix:\n");
	print_matrix(b,m,n);
	
	int g=check_sparse(a,m,n);
	int h=check_sparse(b,m,n);
	
	if(!((g==1) && (h==1))){
		printf("The two matrices are not sparse");
	}
	else{
		printf("The two matrices are sparse\n");
		printf("Representing sparse matrix A\n");
		sparse_representation(a,m,n);
		printf("Representing sparse matrix B\n");
		sparse_representation(b,m,n);
	}
	return 0;
}
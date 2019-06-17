#include<iostream>
using namespace std;
int** create(int **a, int l, int m, int n)
{
	int i,k,o,b;
	int **c=new int*[n];
	for(i=0; i<n; i++)
		c[i]=new int[n];
	for(k=0, i=l; k<n; k++, i++)
		for(o=0, b=m; o<n; o++, b++)
			c[k][o]=a[i][b];
	return c;
}
int** add(int **a, int **b, int n)
{
	int **c=new int*[n];
	int i,j;
	for(i=0; i<n; i++)
		c[i]=new int[n];
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			c[i][j]=a[i][j]+b[i][j];
	return c;
}
int** sub(int **a, int **b, int n)
{
	int **c=new int*[n];
	int i,j;
	for(i=0; i<n; i++)
		c[i]=new int[n];
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			c[i][j]=a[i][j]-b[i][j];
	return c;
}
void combine(int **c, int **c11, int i, int j, int n)
{
	int a,b,x,y;
	for(a=0, x=i; a<n; a++, x++)
		for(b=0, y=j; b<n; b++, y++)
			c[x][y]=c11[a][b];
}
int** multiply(int **a, int **b, int n)
{
	if(n==1)
	{
		int **c=new int*[n];
		c[0]=new int[n];
		c[0][0]=a[0][0] * b[0][0];
		return c;
	}
	int **a11=create(a,0,0,n/2);
	int **a12=create(a,0,n/2,n/2);
	int **a21=create(a,n/2,0,n/2);
	int **a22=create(a,n/2,n/2,n/2);
	int **b11=create(b,0,0,n/2);
	int **b12=create(b,0,n/2,n/2);
	int **b21=create(b,n/2,0,n/2);
	int **b22=create(b,n/2,n/2,n/2);
	
	int **p1=multiply(add(a11, a22, n/2), add(b11, b22,n/2), n/2);	
	int **p2=multiply(add(a21, a22, n/2), b11, n/2);
	int **p3=multiply(a11, sub(b12, b22, n/2), n/2);
	int **p4=multiply(a22, sub(b21, b11, n/2), n/2);
	int **p5=multiply(add(a11, a12, n/2), b22, n/2);
	int **p6=multiply(sub(a21, a11, n/2), add(b11, b12, n/2), n/2);
	int **p7=multiply(sub(a12, a22, n/2), add(b21, b22, n/2), n/2);

	int **c11=add(sub(add(p1, p4, n/2), p5, n/2), p7, n/2);
	int **c12=add(p3, p5, n/2);
	int **c21=add(p2, p4, n/2);
	int **c22=add(sub(add(p1, p3, n/2), p2, n/2), p6, n/2);

	int **c=new int*[n];
	for(int i=0; i<n; i++)
		c[i]=new int[n];
	//for(int i=0; i<n/2; i++)
	//	for(int j=0; j<n/2; j++)
	//		cout<<c11[i][j]<<" ";
	combine(c,c11,0,0,n/2);
	combine(c,c12,0,n/2,n/2);
	combine(c,c21,n/2,0,n/2);
	combine(c,c22,n/2,n/2,n/2);
	return c;
}
int main()
{
	int t;
	cin>>t;
	int n,i,j;
	while(t--)
	{
		cin>>n;
		int **a=new int*[n+1];
		for(i=0; i<n+1; i++)
			a[i]=new int[n+1];
		
		int **b=new int*[n+1];
		for(i=0; i<n+1; i++)
			b[i]=new int[n+1];
		
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				cin>>a[i][j];
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				cin>>b[i][j];
		int **c;
		if(n%2!=0)
		{
			for(i=n; i<n+1; i++)
				for(j=n; j<n+1; j++)
					a[i][j]=0, b[i][j]=0;
			c=multiply(a,b,n+1);
		}
		else
			c=multiply(a,b,n);
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
				cout<<c[i][j]<<" ";
			cout<<endl;
		}
		
	}
	return 0;
}

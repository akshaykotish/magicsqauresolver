#include<iostream>
using namespace std;

int i_arr[8];
int j_arr[8];
int k_arr[8];

void initalise()
{
	int e=0;
	for(int i=1; i<=9; i++)
	{
		for(int j=i+1; j<=9; j++)
		{
			for(int k=j+1; k<=9; k++)
			{
				if(i+j+k == 15)
				{
					cout<<i<<" + "<<j<<" + "<<k<<" = 15"<<endl;
					i_arr[e] = i;
					j_arr[e] = j;
					k_arr[e] = k;
					e++;
				}
			}	
		}
	}
}

int get_i(int j, int k)
{
	cout<<"Log: Value Come:- "<<j<<" "<<k<<endl;
	int out = 0;
	for(int e=0; e<8; e++)
	{
		if((j_arr[e] == j && k_arr[e] == k) || (j_arr[e] == k && k_arr[e] == j))
		{
			out = i_arr[e];
			cout<<"Log: i_arr:"<<out<<endl;
		}
	}
	return out;
}

int get_j(int i, int k)
{
	cout<<"Log: Value Come:- "<<i<<" "<<k<<endl;
	int out = 0;
	for(int e=0; e<8; e++)
	{
		if((i_arr[e] == i && k_arr[e] == k) || (i_arr[e] == k && k_arr[e] == i))
		{
			out = j_arr[e];
			cout<<"Log: j_arr:"<<out<<endl;
		}
	}
	return out;
}

int get_k(int i, int j)
{
	cout<<"Log: Value Come:- "<<j<<" "<<i<<endl;
	int out = 0;
	for(int e=0; e<8; e++)
	{
		if((j_arr[e] == j && i_arr[e] == i) || (j_arr[e] == i && i_arr[e] == j))
		{
			out = k_arr[e];
			cout<<"Log: k_arr:"<<out<<endl;
		}
	}
	return out;
}

int check_horizontal(int arr[][3], int i, int j)
{
	int val = 0;
	
	int g[2];
	int g_e = 0;
	for(int j_e = 0; j_e<3; j_e++)
	{
		if(j_e != j)
		{
			g[g_e] = arr[i][j_e];
			g_e++;
		}
	}
	
	cout<<"Log: i & j Value:"<<i<<" "<<j<<endl;
	cout<<"Log: g1 & g2 Value:"<<g[0]<<" "<<g[1]<<endl;
	
	if(get_i(g[0], g[1]) != 0)
	{
		val = get_i(g[0], g[1]);
	}
	else if(get_j(g[0], g[1]) != 0)
	{
		val = get_j(g[0], g[1]);
	}
	else{
		val = get_k(g[0], g[1]);
	}
	
	cout<<"Log: Horizontal Value:"<<val<<endl;
	return val;
}

int check_vertical(int arr[][3], int i, int j)
{
	int val = 0;
	
	int g[2];
	int g_e = 0;
	for(int i_e = 0; i_e<3; i_e++)
	{
		if(i_e != i)
		{
			g[g_e] = arr[i_e][j];
			g_e++;
		}
	}
	
	cout<<"Log: i & j Value:"<<i<<" "<<j<<endl;
	cout<<"Log: g1 & g2 Value:"<<g[0]<<" "<<g[1]<<endl;
	if(get_i(g[0], g[1]) != 0)
	{
		val = get_i(g[0], g[1]);
	}
	else if(get_j(g[0], g[1]) != 0)
	{
		val = get_j(g[0], g[1]);
	}
	else{
		val = get_k(g[0], g[1]);
	}
	
	cout<<"Log: Vertical Value:"<<val<<endl;
	return val;
}

int check_diagonal(int arr[][3], int i, int j)
{
	int val = 0;
	
	int g[2];
	g[0] = 5;
	if(i==0)
	{
		i=2;
	}
	else if(i==2){
		i=0;
	}
	else{
		i=1;
	}
	if(j==0)
	{
		j=2;
	}
	else if(j==2){
		j=0;
	}
	else{
		j=1;
	}
	g[1] = arr[i][j];
	
	if(get_i(g[0], g[1]) != 0)
	{
		val = get_i(g[0], g[1]);
	}
	else if(get_j(g[0], g[1]) != 0)
	{
		val = get_j(g[0], g[1]);
	}
	else{
		val = get_k(g[0], g[1]);
	}
	
	cout<<"Log: Diagonal Value:"<<val<<endl;
	return val;
}
int check(int arr[][3], int i, int j)
{
	int val = 0;
	 
	int v1 = check_horizontal(arr, i, j);
	int v2 = check_vertical(arr, i, j);
	int v3 = 0;
	if((i == 0 && j ==0) && (i == 2 && j ==2) && (i == 2 && j ==0) && (i == 0 && j ==2))
	{
		int v3 = check_diagonal(arr, i, j);
		cout<<"Matched at "<<i<<" "<<j<<endl;
	}
	else{
		v3 = v2;
	}
	if(v1 == v2 && v2 == v3)
	{
		val = v1;
	}
	cout<<"Log: v1:"<<v1<<endl;
	cout<<"Log: v2:"<<v2<<endl;
	cout<<"Log: v3:"<<v3<<endl;
	return val;
}

void solve(int arr[][3])
{
	int temp[3][3];
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			temp[i][j] = arr[i][j];
			int v = check(arr, i, j);
			if(v != 0)
			{
				temp[i][j] = v;
				arr[i][j] = v;
			}
		}
	}
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<temp[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	initalise();
	//int arr[3][3] = {{5, 3, 4},{1, 5, 8},{6, 4, 2}};
	int arr[3][3] = {{4, 9, 2},{3, 5, 7},{8, 1, 5}};
	solve(arr);
}

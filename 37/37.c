// 图的路径长度
// 弗洛伊德算法求解
// 待详细分析

#if 0

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void maxCatenate(string *text,int n);

int main()
{
	string text[] = {
		"abcd",
		"bcde",
		"cdea",
		"deab",
		"eaba",
		"abab",
		"deac",
		"cdei",
		"bcdf",
		"cdfi",
		"dfic",
		"cdfk",
		"bcdg",
	};

	maxCatenate(text,13);

    return 0;
}

void maxCatenate(string text[],int n)
{
	int **G = new int*[n];

	for(int i = 0; i < n; i++)
	{
		G[i] = new int[n];
	}

	for(int i = 0; i < n; i++)
	{
		string suffix = text[i].substr(1);

		for(int j = 0; j < n; j++)
			if(text[j].find(suffix)==0)
				G[i][j] = 1;
	}

	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(G[i][k] != 0 && G[k][j] != 0)
				{
					int dist = G[i][k] + G[k][j];

					if(dist > G[i][j])
					{
						G[i][j] = dist;
					}
				}
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(G[i][i] > 1)
		{
			cout << "circle is deteted!" << endl;
			return;
		}
	}

    int max = 0;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		max = std::max(max, G[i][j]);

    cout<<"Max is " << max <<endl;
    cout<<"Max length is " << max + text[0].length() << endl;
}
#endif

#include <iostream>
#include <string>
using namespace std;

#define INFINITY -1000000   //求最长路径时，邻接矩阵初始化时应该设置成最小值

typedef struct graph
{
	string vertex[10];
	int arc[10][10];
	int num_vertex;
	int num_edge;
}graph;

int max_ = INFINITY;
int posi,posj;

bool largestpath(graph &g, int d[10][10], int p[10][10])
{
	int i,j,k,m;
	cout<<"the string count:";
	cin>>g.num_vertex;
	cout<<"the string is:";
	for(i=0;i<g.num_vertex;i++)
		cin>>g.vertex[i];
	cout<<"the m is:";
	cin>>m;
	for(i=0;i<g.num_vertex;i++) //邻接矩阵初始化
		for(j=0;j<g.num_vertex;j++)
			g.arc[i][j] = INFINITY;
	for(i=0;i<g.num_vertex;i++)
		for(j=0;j<g.num_vertex;j++)
		{
            //首尾匹配，则成为一条边，权值为1
			if(g.vertex[i].substr(g.vertex[i].size()-m,m) == g.vertex[j].substr(0,m))

				g.arc[i][j] = 1;
			else
				g.arc[i][j] = INFINITY;
		}

	for(i=0;i<g.num_vertex;i++)
		for(j=0;j<g.num_vertex;j++)
		{
			d[i][j] = g.arc[i][j];
			p[i][j] = j;
		}

	for(k=0;k<g.num_vertex;k++)
		for(i=0;i<g.num_vertex;i++)
			for(j=0;j<g.num_vertex;j++)
			{
                //最长路径需要取最大值，这和求最短路径正好相反
				if(d[i][j] < d[i][k]+d[k][j])
				{
					d[i][j] = d[i][k]+d[k][j];
					p[i][j] = p[i][k];
				}
                //记录当前最长路径
				if(d[i][j] > max_) 
				{
					max_ = d[i][j];
					posi = i;
					posj = j;
				}
			}
    //判断是否出现循环
	for(i=0;i<g.num_vertex;i++)
		if(g.arc[i][i] != INFINITY)
			return false;

	return true;
}

int main()
{
	graph g;
	int d[10][10];
	int p[10][10];
	bool flag = largestpath(g,d,p);
	if(flag==false)
		cout<<"exist cycle!"<<endl;
	else
	{
		cout<<"the long string list is:"<<endl;
		int num = 0;
		int i = posi, j=posj;
		cout<<g.vertex[i];
		num++;

		int k = p[i][j];
		while(k != j)
		{
			cout<<"->"<<g.vertex[k];
			k = p[k][j];
			num++;
		}
		cout<<"->"<<g.vertex[j]<<endl;
		num++;

		cout<<"the length of list is:"<<num<<endl;
	}
	return 0;
}


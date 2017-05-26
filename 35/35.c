//from http://blog.csdn.net/zhanxinhang

#include <stdio.h>
#define RES_NUM 2

void get_max_22Matrix_1(int *a,int row,int col,int *result)
//a为原矩阵，row，col指a矩阵的行和列，result存储最终得到的子二维矩阵
{
  int maxsum = 0, result_i, result_j, sum;
  
#define a(i, j) *(a + ((i)*col) + (j))  //用二维的形式表示一维数组，访问需要一定的代价
#define result(i, j) *(result + (i)*RES_NUM + (j))
  
  for(int i = 0; i < row - 1; i++)
  {
    for(int j = 0; j < col - 1 ; j++)
    {
      sum = a(i, j) + a(i + 1, j) + a(i, j + 1) + a(i + 1, j + 1); 
      //访问四个元素并相加得到当前的和
      if(maxsum < sum) //更新最大子二维矩阵数据
      {
        maxsum = sum;
        result_i = i;
        result_j = j;
      }
    }
  }
   /* 将结果存储到result二维数组中*/
  result(0,0) = a(result_i, result_j);
  result(1,0) = a(result_i + 1, result_j);
  result(0,1) = a(result_i, result_j + 1);
  result(1,1) = a(result_i + 1, result_j+1);

#undef a
#undef result
}


void get_max_22Matrix_2(int *a,int row,int col,int *result)
{
  int maxsum=0,result_i,result_j,sum,last_vsum=0;
  
#define a(i,j) *(a+(i)*col+(j))  
#define result(i,j) *(result+(i)*RES_NUM+(j))
  
  last_vsum = a(0,0)+a(1,0);  //初始last_vsum
  for(int i=0; i<row-1; i++)
  {
      for(int j=1; j<col; j++)
	  {
	    sum = last_vsum ;  //将last_vsum加入sum
	    last_vsum = a(i, j) + a(i + 1, j);//更新last_vsum
	    sum += last_vsum;//将更新后的last_vsum再与sum累加，得到当前子二维矩阵的和
	    
        if(maxsum < sum)
        {
          maxsum   = sum;
          result_i = i;
          result_j = j-1;
        }
	  }
  }
 
   /* 将结果存储到result二维数组中*/
   result(0,0)=a(result_i,result_j);
   result(1,0)=a(result_i+1,result_j);
   result(0,1)=a(result_i,result_j+1);
   result(1,1)=a(result_i+1,result_j+1);
#undef a
#undef result
}

int main()
{
  int result[RES_NUM*RES_NUM]={0};
  int a[3 * 5]={1,2,0,3,4,
    	      2,3,4,5,1,
    	      1,1,5,3,0};


  get_max_22Matrix_1(a,3,5,result);

 #define result(i,j) *(result+(i)*RES_NUM+(j))

  for(int i =0; i<2; i++)
  {
    for(int j=0; j<2; j++)
      printf("%d ",result(i,j));

    printf("\n");
  }

  return 0;
}


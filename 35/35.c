//from http://blog.csdn.net/zhanxinhang

#include <stdio.h>
#define RES_NUM 2

void get_max_22Matrix_1(int *a,int row,int col,int *result)
//aΪԭ����row��colָa������к��У�result�洢���յõ����Ӷ�ά����
{
  int maxsum = 0, result_i, result_j, sum;
  
#define a(i, j) *(a + ((i)*col) + (j))  //�ö�ά����ʽ��ʾһά���飬������Ҫһ���Ĵ���
#define result(i, j) *(result + (i)*RES_NUM + (j))
  
  for(int i = 0; i < row - 1; i++)
  {
    for(int j = 0; j < col - 1 ; j++)
    {
      sum = a(i, j) + a(i + 1, j) + a(i, j + 1) + a(i + 1, j + 1); 
      //�����ĸ�Ԫ�ز���ӵõ���ǰ�ĺ�
      if(maxsum < sum) //��������Ӷ�ά��������
      {
        maxsum = sum;
        result_i = i;
        result_j = j;
      }
    }
  }
   /* ������洢��result��ά������*/
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
  
  last_vsum = a(0,0)+a(1,0);  //��ʼlast_vsum
  for(int i=0; i<row-1; i++)
  {
      for(int j=1; j<col; j++)
	  {
	    sum = last_vsum ;  //��last_vsum����sum
	    last_vsum = a(i, j) + a(i + 1, j);//����last_vsum
	    sum += last_vsum;//�����º��last_vsum����sum�ۼӣ��õ���ǰ�Ӷ�ά����ĺ�
	    
        if(maxsum < sum)
        {
          maxsum   = sum;
          result_i = i;
          result_j = j-1;
        }
	  }
  }
 
   /* ������洢��result��ά������*/
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


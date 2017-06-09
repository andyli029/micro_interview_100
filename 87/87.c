// need to think
// http://www.cnblogs.com/jmzz/archive/2011/06/12/2078668.html
//

// 分治法
#if 0
#include <string>

string String Mutiply1(string a, string b)// 用字符串读入2个大整数
{
    String result = "";

    if (a.length() == 1 || b.length() == 1)// 递归结束的条件
                   //其中一个长度为1，另一个不一定
        result = "" + Long.valueOf(a) * Long.valueOf(b);

    else// 如果2个字符串的长度都 >= 2
    {
        // 1.分割成  a1  a0  b1  b0
        int lengthA0 = a.length() / 2;
        int lengthA1 = a.length() - lengthA0;
        String a1 = a.substring(0, lengthA1); // 截取前一半的字符串(较短的一半)
        String a0 = a.substring(lengthA1, a.length()); // 截取后一半的字符串

        int lengthB0 = b.length() / 2;
        int lengthB1=b.length()-lengthB0;
        String b1 = b.substring(0, lengthB1);
        String b0 = b.substring(lengthB1, b.length());
        // * a*b=
        // * (a1*b1)* 10^[(n1+n2)/2 ]
        // * +(a1*b0)*10^(n1/2)
        // * +(a0*b1)*10^(n2/2)
        // * +(a0*b0)
        // 2.计算展开式中的乘法
        String a1b1 = Mutiply1(a1, b1);
        String a1b0 = Mutiply1(a1, b0);
        String a0b1 = Mutiply1(a0, b1);
        String a0b0 = Mutiply1(a0, b0);

        // 3.模拟移位
        String resulta1b1 = a1b1;
        for (int i = 0; i < lengthA0+lengthB0; i++) {
            resulta1b1 += "0";
        }
        String resulta1b0 = a1b0;
        for (int i = 0; i <lengthA0; i++) {
            resulta1b0 += "0";
        }
        String resulta0b1 = a0b1;
        for (int i = 0; i < lengthB0; i++) {
            resulta0b1 += "0";
        }    
        // 4.大数相加
        result = MyBigAdd.add(resulta1b1, resulta1b0);
        result = MyBigAdd.add(result, resulta0b1);
        result = MyBigAdd.add(result, a0b0);
    }
    return result;
}

    /** 
     * @Description拿BigInteger自身大数相乘来判断自身算法的正确与否
     * @param args
     */
int main() 
{
    Scanner scan = new Scanner(System.in);
    while (scan.hasNext()) {

        String aString=scan.next();
        String bString=scan.next();

        BigInteger aBigInteger=new BigInteger(aString);
        BigInteger bBigInteger=new BigInteger(bString);

        String reslut1=aBigInteger.multiply(bBigInteger).toString();
        String result2=Mutiply1(aString, bString);

        System.out.println("标准答案：  "+reslut1);
        System.out.println("计算结果：  "+result2);

        System.out.println("结果是否正确：  "+reslut1.equals(result2));
    }

    return 0;
}
#endif

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int lenA, lenB;

// 列竖式
void Multiple(char A[], char B[], char C[]) 
{
    int i,j,k,tmp,lenC,index; // k:进位标识
    
    lenC = lenA + lenB - 1;
    for(i = lenB - 1; i >= 0; i--) 
	{
        index = lenC--;
		k = 0;
        if(B[i] != '0')
		{
            for(j = lenA - 1; j >= 0; j--) 
			{
                tmp = (C[index] - '0') + (A[j] - '0') * (B[i] - '0') + k;
                C[index--] = tmp % 10 + '0';
                k = tmp / 10;
            }
            C[index] = k + '0';
        }
    }
}

int main() {

	int i;
    char a[100],b[100],c[100];

	while(1)
	{
		printf("please cin the number(-1 finish):\n");
		scanf("%s",a);
		if(strcmp(a,"-1")==0)
			break;
		scanf("%s",b);
		
		lenA = strlen(a);
		lenB = strlen(b);
	    for(int k = 0; k < lenA + lenB; k++)
	        c[k] = '0';
	   	c[lenA + lenB] = '\0';
		Multiple(a, b, c);
	    printf("%s * %s = ", a, b);
	    
		i = 0;//输出 首先去除前导0 
	    while(c[i] == '0') i++;
		for(;c[i] != '\0';i++)
	        printf("%c",c[i]);
	        
		printf("\n");
	}
}

/*
1 1
2 12
12 1
1111 1111
21839244444444448880088888889 38888888888899999999999999988
-1
*/ 
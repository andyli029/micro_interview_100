// need to think
// http://www.cnblogs.com/jmzz/archive/2011/06/12/2078668.html
//

// ���η�
#if 0
#include <string>

string String Mutiply1(string a, string b)// ���ַ�������2��������
{
    String result = "";

    if (a.length() == 1 || b.length() == 1)// �ݹ����������
                   //����һ������Ϊ1����һ����һ��
        result = "" + Long.valueOf(a) * Long.valueOf(b);

    else// ���2���ַ����ĳ��ȶ� >= 2
    {
        // 1.�ָ��  a1  a0  b1  b0
        int lengthA0 = a.length() / 2;
        int lengthA1 = a.length() - lengthA0;
        String a1 = a.substring(0, lengthA1); // ��ȡǰһ����ַ���(�϶̵�һ��)
        String a0 = a.substring(lengthA1, a.length()); // ��ȡ��һ����ַ���

        int lengthB0 = b.length() / 2;
        int lengthB1=b.length()-lengthB0;
        String b1 = b.substring(0, lengthB1);
        String b0 = b.substring(lengthB1, b.length());
        // * a*b=
        // * (a1*b1)* 10^[(n1+n2)/2 ]
        // * +(a1*b0)*10^(n1/2)
        // * +(a0*b1)*10^(n2/2)
        // * +(a0*b0)
        // 2.����չ��ʽ�еĳ˷�
        String a1b1 = Mutiply1(a1, b1);
        String a1b0 = Mutiply1(a1, b0);
        String a0b1 = Mutiply1(a0, b1);
        String a0b0 = Mutiply1(a0, b0);

        // 3.ģ����λ
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
        // 4.�������
        result = MyBigAdd.add(resulta1b1, resulta1b0);
        result = MyBigAdd.add(result, resulta0b1);
        result = MyBigAdd.add(result, a0b0);
    }
    return result;
}

    /** 
     * @Description��BigInteger�������������ж������㷨����ȷ���
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

        System.out.println("��׼�𰸣�  "+reslut1);
        System.out.println("��������  "+result2);

        System.out.println("����Ƿ���ȷ��  "+reslut1.equals(result2));
    }

    return 0;
}
#endif

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int lenA, lenB;

// ����ʽ
void Multiple(char A[], char B[], char C[]) 
{
    int i,j,k,tmp,lenC,index; // k:��λ��ʶ
    
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
	    
		i = 0;//��� ����ȥ��ǰ��0 
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
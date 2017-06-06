#include <stdio.h>

/*
//�����Ƿ�p������,Ȼ��p->next������copy��p�У�������ɾ��p->next���ɡ�

				  �ڴ�λ��        0		1		2		3		4		5
        ���ƿ�ʼǰ�洢��ֵ        a		b		c		d		e		f
			src��ʼλ��                         *
			dest��ʼλ��                *
        ���ƽ��ͺ�洢��ֵ        a		c		d		e		e		f

		
���ô�src��ʼλ�ÿ�ʼ��������ƽ���
				  �ڴ�λ��        0		1		2		3		4		5
        ���ƿ�ʼǰ�洢��ֵ        a		b		c		d		e		f
			src��ʼλ��                         *
			dest��ʼλ��                        *  
        ���ƽ��ͺ�洢��ֵ        a		b		c		d		e		f


���ô�src��ʼλ�ÿ�ʼ��������ƽ���
				  �ڴ�λ��        0		1		2		3		4		5
        ���ƿ�ʼǰ�洢��ֵ        a		b		c		d		e		f
			src��ʼλ��                         *
			dest��ʼλ��                                *
        ���ƽ��ͺ�洢��ֵ        a		b		c		c		c		c
		
���ϣ�����  ��destλ����srcλ����ʱ���Դ�src�Ŀ�ʼλ��  2  ��ʼ����ֱ�� 4 ������ 
ֵc,d,e ������ȷ���ƣ����ǵ�destλ����src��ʱ��׼ȷ˵�����ص�����ʱֵc,d,e������ȷ���ơ�
���ӽ���λ�ÿ�ʼ��ǰ���ƿ��Խ����������
 
���ô�src+3 λ�ÿ�ʼ���������ǰ�ƽ���
				  �ڴ�λ��        0		1		2		3		4		5
        ���ƿ�ʼǰ�洢��ֵ        a		b		c		d		e		f
			src��ʼλ��                         *
			dest��ʼλ��                                *
        ���ƽ��ͺ�洢��ֵ        a		b		c		c		d		e

*/

// Copy from the end to the beginning.

void* memmove(void *dest, const void* src, size_t n)
{
	void* temp = dest;

	if (dest <= src || (char*)dest >= ((char*)src+n))
	{
		while(n--)
		{
			*((char*)dest) = *((char*)src);
			dest = (char*)dest + 1;
			src  = (char*)src  + 1;
		}
	}
	else
	{
		dest = (char*)dest + n - 1;
		src  = (char*)src  + n - 1;

		while(n--)
		{
			*((char*)dest) = *((char*)src);
			dest = (char*)dest - 1;
			src  = (char*)src - 1;
		}
	}

	return(temp);
}

int main()
{
//�˴���Ϊchar* p="hello,world",��ô�������*(p+1)='a'����ʱ���ͻ����
//���൱���޸�һ�������ַ�����
	char p[] = "hello,world";
	char dest[6] = {0};
	char *q = (char*)memmove(dest,p,5);

	printf("dest : %s\n",dest);
	printf("q : %s\n",q);
	return 0;
}

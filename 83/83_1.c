#include <stdio.h>

/*
//首先是放p中数据,然后将p->next的数据copy入p中，接下来删除p->next即可。

				  内存位置        0		1		2		3		4		5
        复制开始前存储的值        a		b		c		d		e		f
			src开始位置                         *
			dest开始位置                *
        复制解释后存储的值        a		c		d		e		e		f

		
采用从src开始位置开始复制完后推进：
				  内存位置        0		1		2		3		4		5
        复制开始前存储的值        a		b		c		d		e		f
			src开始位置                         *
			dest开始位置                        *  
        复制解释后存储的值        a		b		c		d		e		f


采用从src开始位置开始复制完后推进：
				  内存位置        0		1		2		3		4		5
        复制开始前存储的值        a		b		c		d		e		f
			src开始位置                         *
			dest开始位置                                *
        复制解释后存储的值        a		b		c		c		c		c
		
综上，看出  当dest位置在src位置左时可以从src的开始位置  2  开始复制直到 4 结束。 
值c,d,e 可以正确复制，但是单dest位置在src右时，准确说存在重叠现象时值c,d,e不能正确复制。
而从结束位置开始向前复制可以解决如下问题
 
采用从src+3 位置开始复制完后向前推进：
				  内存位置        0		1		2		3		4		5
        复制开始前存储的值        a		b		c		d		e		f
			src开始位置                         *
			dest开始位置                                *
        复制解释后存储的值        a		b		c		c		d		e

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
//此处若为char* p="hello,world",那么下面进行*(p+1)='a'操作时，就会出错。
//这相当于修改一个常量字符串。
	char p[] = "hello,world";
	char dest[6] = {0};
	char *q = (char*)memmove(dest,p,5);

	printf("dest : %s\n",dest);
	printf("q : %s\n",q);
	return 0;
}

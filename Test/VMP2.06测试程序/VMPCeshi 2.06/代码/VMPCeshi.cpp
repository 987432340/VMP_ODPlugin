// VMPCeshi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>

extern "C" void __declspec(naked) __declspec(dllexport) tiaojianZhuanyi1()
{
	__asm//测试所有条件转移
	{
		mov eax,0x11111111
		test eax,eax
		ja ja1
		sub eax,0x22222222
		jb jb1
		sub eax,0x33333333
		jbe jbe1
jb1:
		sub eax,0x44444444
		je je1
		sub eax,0x55555555
		jg jg1
		sub eax,0x66666666
		jge jge1
		sub eax,0x77777777
		jl jl1
		sub eax,0x88888888
		jle jle1
jge1:
jbe1:
		sub eax,0x99999999
		jnb jnb1
je1:
		sub eax,0xaaaaaaaa
		jno jno1
		sub eax,0xbbbbbbbb
		jns jns1
		sub eax,0xcccccccc
		jnz jnz1
jnb1:
jno1:
jl1:
		sub eax,0xdddddddd
		jo jo1
		sub eax,0xeeeeeeee
		jpe jpe1
jle1:
		sub eax,0xffffffff
		jpo jpo1
jns1:
jnz1:
jo1:
		sub eax,0x12345678
		js js1
jpo1:
jpe1:
		sub eax,0x87654321
jg1:
ja1:
js1:
		sub eax,0x89abcdef
		retn
	}
}

extern "C" int __declspec(dllexport) switch1(int a)
{
	int aa = 0x11111111, bb = 0xAAAAAAAA;

	switch (a)//测试分支表
	{
	case 1:
		aa += a + 0x22222222;
		break;
	case 2:
		aa += a + 0x33333333;
		break;
	case 3:
		aa += a + 0x44444444;
		break;
	case 4:
	case 5:
		aa += a + 0x55555555;
		break;
	}
	switch (aa)//测试分支表和分支索引表
	{
	case 0x100:
		bb -= aa + 0x66666666;
		break;
	case 0x105:
		bb -= aa + 0x77777777;
		break;
	case 0x109:
		bb -= aa + 0x88888888;
		break;
	case 0x118:
	case 0x120:
		bb -= aa + 0x99999999;
		break;
	}
	return bb;
}

extern "C" int __declspec(dllexport) xunhuan1(int a)
{
	int aa = 0x11111111, bb = 0xAAAAAAAA, i;

	for (i = 0; i < a; i++)//测试普通循环
	{
		aa += i;
		bb -= aa + 0x22222222;;
	}
	return bb;
}

extern "C" int __declspec(dllexport) xunhuan2(int a)
{
	int aa = 0x11111111, bb = 0xAAAAAAAA, i;

	while (aa > 0)//测试不同类型嵌套循环
	{
		aa -= a;
		bb += aa - 0x22222222;
		for (i = a; i > 0; i--)
		{
			bb += i + 0x33333333;
			do 
			{
				bb -= a + 0x12345678;
			} while (bb > aa);
			bb += i + 0x44444444;
		}
		bb -= i;
	}
	return bb;
}

extern "C" int __declspec(dllexport) fenzhi1(int a)
{
	int aa = 0x11111111, bb = 0xAAAAAAAA;

	if (a > 0)//测试if-else
	{
		aa += 0x22222222;
	}
	else
	{
		aa += 0x33333333;
	}
	if (aa < 0x44444444)//测试if
	{
		bb -= 0x55555555;
	}
	return bb;
}

extern "C" int __declspec(dllexport) fenzhi2(int a)
{
	int aa = 0x11111111, bb = 0xAAAAAAAA;

	if (a > 0 && a < 100)//测试多条件分支
	{
		bb += a;
	}
	else if (a >= 500 || a <= 1000)
	{
		bb -= a;
	}
	else
	{
		bb += a + 10000;
	}
	if (aa >= 0x11111111)//测试嵌套分支
	{
		if (aa + a < 0x22222222)
		{
			if (aa < 0x33333333)
			{
				bb += 0x44444444;
			}
		}
		else
		{
			bb += 0x55555555;
		}
	}
	else
	{
		bb += 0x66666666;
	}
	return bb;
}

int diaoyong(int a)
{
	if (a > 0)
	{
		return 0x11111111;
	}
	return 0x22222222;
}

extern "C" int __declspec(dllexport) diaoyong1(int a)
{
	int aa = 0x11111111, bb = 0xAAAAAAAA;

	if (a > 100)
	{
		MessageBox(0, "MessageBox", "MessageBox", 0);//测试调用API
	}
	if(a < 1000)
	{
		aa += diaoyong(a);//测试调用普通函数
	}
	bb += fenzhi1(aa + a);//测试调用被虚拟化的函数
	return bb;
}

extern "C" bool __declspec(dllexport) jisuan(char a[8], char b[8])
{
	int i, j;
	char aa = 0;

	//简单的计算，测试全部程序结构
	if (a[0] + b[0] != a[7] + b[7])
	{
		return false;
	}
	for (i = 0; i < 8; i++)
	{
		aa += a[i] ^ b[1];
		aa -= a[i] + b[2];
		if (i == 3)
		{
			aa += b[3];
		}
		else if (i >= 4 && i <= 6)
		{
			aa -= b[4];
		}
		for (j = 7; j >= i; j--)
		{
			aa ^= j + b[5];
		}
	}
	if (aa == b[6])
	{
		return true;
	}
	return false;
}

int main(int argc, char* argv[])
{
	char aa[8] = {12, 34, 56, 78, 11, 22, 33, 44};
	char bb[8] = {98, 76, 54, 32, 10, 11, 186, 66};

	if (jisuan(aa, bb))
	{
		MessageBox(0, "true", "true", 0);
	}
	else
	{
		MessageBox(0, "false", "false", 0);
	}
	return 0;
}

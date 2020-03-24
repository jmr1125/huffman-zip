#include<bits/stdc++.h>
#include"huffman.h"
using namespace std;
//r(read): 只读
//w(write): 只写
//a(append): 追加
//t(text): 文本文件，可省略不写
//b(binary): 二进制文件

struct ibs
{
	FILE* fp=NULL;
	int pos;
	char c;
	int flen;
	
	
	void setfilename(const char*filename)
	{
		pos=8;
		fp=fopen(filename,"rb");
		if(fp==NULL)
		{
			cerr<<"file can't open!!!";
			exit(1);
		}
		else
		{
			fseek(fp, 0, SEEK_END); //定位到文件末 
			flen = ftell(fp); //文件长度
			fseek(fp, 0, SEEK_SET); //恢复到文件头
		}
	}
	int getfilesize()
	{
		return flen;
	}
	
	
	
	bool getbit()
	{
		if(pos==char_size)
		{
			fread(&c,1,1,fp);
			pos=1;
			return (c&(1<<pos-1));
		}
		++pos;
		return (c&(1<<pos-1));
	}
	char getchar()
	{
		char c;
		fread(&c,1,1,fp);
		return c;
	}
	void close()
	{
		fclose(fp);
	}
	
	FILE* getstream()
	{
		return fp;
	}
};
struct obs
{
	FILE* fp=NULL;
	int pos;
	char c;
	int flen;
	void setfilename(const char*filename)
	{
		pos=0;
		c=0;
		fp=fopen(filename,"wb");
		if(fp==NULL)
		{
			cerr<<"file can't open!!!";
			exit(1);
		}
		fseek(fp, 0, SEEK_END); //定位到文件末 
		flen = ftell(fp); //文件长度
		fseek(fp, 0, SEEK_SET); //恢复到文件头
		
	}
	int getfilesize()
	{
		return flen;
	}
	
	void putbit(int val)
	{
		if(pos==char_size)
		{
			fwrite(&c,1,1,fp);
			pos=0;
			c=0;
		}
		++pos;
		c+=val*(1<<pos-1);
	}
	void putchar(char c)
	{
		fwrite(&c,1,1,fp);
	}
	
	void flush()
	{
		if(pos==0)
		{
			return;
		}
		fwrite(&c,1,1,fp);
		pos=0;
		c=0;
	}
	void close()
	{
		flush();
		fclose(fp);
	}
	
	
	FILE* getstream()
	{
		return fp;
	}
};

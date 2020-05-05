#include<bits/stdc++.h>
#include<bits/ios_base.h>
#define char_size 8
using namespace std;
#define ifs ifstream
#define ofs ofstream
#define in ios_base::in
#define out ios_base::out
#define binary ios_base::binary
#define openmode ios_base::openmode

#define end ios_base::end
#define begin ios_base::beg
#define now_pos ios_base::cur
/*
fseek(fp, 0, SEEK_END); //定位到文件末 
flen = ftell(fp); //文件长度
fseek(fp, 0, SEEK_SET); //恢复到文件头
*/
struct ibs
{
	ifs fin;
	int pos;
	char c;
	
	size_t file_len; 
	ibs(string filename,openmode mode=in|binary)
	{
		pos=8;
		c=0;
		fin.open(filename,mode);
		if(fin==NULL)
		{
			cerr<<"file can't open!!";
			exit(1);
		}
		fin.seekg(0,end);
		file_len=fin.tellg();
		fin.seekg(0,begin);
	}
	void setfilename(string file_name,openmode mode=in|binary)
	{
		ibs(file_name,mode);
	}
	size_t getfilesize()
	{
		return file_len;
	}
	int getint()
	{
		int cnt;
		fin>>cnt;
		return cnt;
	}
	
	char getchar()
	{
		char d;
		d=fin.get();
		return d;
	}
	template<class _t>
	void gettype(_t&cnt)
	{
		fin>>cnt;
	}
	bool getbit()
	{
		if(pos==char_size)
		{
			pos=0;
			c=getchar();
		}
		++pos;
		return (c&(1<<pos-1));
	}
	bool eof()
	{
		return fin.eof();
	}
	void close()
	{
		fin.close();
	}
};
struct obs
{
	ofs fout;
	int pos;
	char c;
	
	size_t file_len;
	obs(string file_name,openmode mode=in|binary)
	{
		pos=0;
		c=0;
		fout.open(file_name,mode);
		if(fout==NULL)
		{
			cerr<<"file can't open!!!";
			exit(1);
		}
		fout.seekp(0,end);
		file_len=fout.tellp();
		fout.seekp(0,begin);
	}
	void setfilename(string file_name,openmode mode=in|binary)
	{
		obs(file_name,mode);
	}
	size_t getfilesize()
	{
		return file_len;
	}
	void putint(int n)
	{
		fout<<n;
	}
	
	void putchar(char c)
	{
		fout.put(c);
	}
	template<class _t>
	void puttype(_t n)
	{
		fout<<n;
	}
	void putbit(int val)
	{
		if(pos==char_size)
		{
			putchar(c);
			pos=0;
			c=0;
		}
		++pos;
		c|=val*(1<<pos-1);
	}
	
	void flush()
	{
		if(pos==0)
		{
			return;
		}
		putchar(c);
		pos=0;
		c=0;
	}
	void close()
	{
		flush();
		fout.close();
	}
};

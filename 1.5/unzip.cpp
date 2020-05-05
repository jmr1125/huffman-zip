#include<bits/stdc++.h>
#include"huffman.h"
#include"bio.h"
using namespace std;
//          zip_const_value
int diff,cosize;
//          file_value
string infile;
string outfile;
//          zip_code
bool code[max_mem];
int xb=0;

char t[32768];
bool have[32768];
int now=1;
//          out_value
int oxb=0;



int main()
{
	printf("in file name:");
	getline(cin,infile);
	outfile=infile.substr(0,infile.size()-5);
	if(infile.substr(infile.size()-5,5)!=".hzip")
	{
		printf("it isn't a hzip file (*.hzip)");
		return 1;
	}
//	getline(cin,outfile);
//	infile="1";
//	outfile="3.txt";
	
	
	
	ibs fin(infile,in|binary);
	obs fout(outfile,out|binary);
	fin.gettype(diff);
	cout<<"diff:"<<diff<<"\n";
	for(int i=1;i<=diff;++i)
	{
		char c;
		short code;
		c=fin.getchar();
		fin.gettype(code);
		cout<<"\'"<<c<<"\' ASCII:"<<(int)c<<" id:"<<code<<" code:";
		for(int j=int(log2(code));j>=1;--j)
		{
			cout<<get(code,j);
		}
		cout<<"\n";
		t[code]=c;
		have[code]=true;
	}
	fin.gettype(cosize);
	cout<<"codesize:"<<cosize<<" bits"<<endl;
	cout<<"string huff code:";
	for(int i=1;i<=cosize;++i)
	{
		int code=fin.getbit();
		if(!code)
		{
			now=now<<1;
		}
		if(code)
		{
			now=(now<<1)+1;
		}
		if(now>32767)
		{
			cout<<"\ncode error";
			return 1;
		}
		if(have[now])
		{
			cout<<(char)t[now];
			fout.putchar(t[now]);
			now=1;
		}
	}
	cout<<"\nfinished..";
	fout.close();
	return 0;
}

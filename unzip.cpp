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
	
	
	
	ibs in;
	obs out;
	in.setfilename(infile.c_str());
	out.setfilename(outfile.c_str());
	fread(&diff,1,1,in.fp);
	cout<<"diff:"<<diff<<"\n";
	for(int i=1;i<=diff;++i)
	{
		char c;
		short code;
		fread(&c,1,1,in.fp);
		fread(&code,1,2,in.fp);
		cout<<"\'"<<c<<"\' ASCII:"<<(int)c<<" id:"<<code<<" code:";
		for(int j=int(log2(code));j>=1;--j)
		{
			cout<<get(code,j);
		}
		cout<<"\n";
		t[code]=c;
		have[code]=true;
	}
	fread(&cosize,1,8,in.fp);
	cout<<"codesize:"<<cosize<<" bits"<<endl;
	cout<<"string huff code:";
	for(int i=1;i<=cosize;++i)
	{
		int code=in.getbit();
		if(!code)
		{
			now=now<<1;
		}
		if(code)
		{
			now=(now<<1)+1;
		}
		if(have[now])
		{
			cout<<t[now];
			out.putchar(t[now]);
			now=1;
		}
	}
	cout<<"finished..";
	out.close();
	return 0;
}

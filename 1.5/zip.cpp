#include "huffman.h"
#include "bio.h"
#define tree_max 1024
using namespace std;
//          file_const_value
string infile;
string outfile;
//          file
size_t infilelen;
char fdat[max_mem];
//          tree
int coun[char_diff+1],xb=0;
huf a[tree_max+1];
//          code
hufcode co[char_diff+1];
//          out
bool o[max_mem];
long long oxb=0;
int diff;

bool cmp1(huf a,huf b)
{
	return (a.use==0&&b.use==1)||((a.use==b.use)&&(a.huff[1].cou<b.huff[1].cou));
}

int main()
{
	printf("in file name£º");
	getline(cin,infile);
	outfile=infile+".hzip";
//	getline(cin,outfile);
//	infile="text.txt";
//	outfile="1";
	
	
	
	ibs fin(infile,in|binary);
	infilelen=fin.getfilesize();
	
	for(int i=0;i<infilelen;++i)
	{
		char c=fin.getchar();
		coun[c+128]++;
		fdat[i]=c;
	}
	fin.close();
	for(int i=1;i<=512;++i)
	{
		if(coun[i]>0)
		{
			a[++xb].huff[1].cou=coun[i];
			a[xb].huff[1].c=i;
		}
	}
	for(int c=1;c<=xb-1;++c)
	{
		sort(a+1,a+1+xb,cmp1);
		ne_ro(a[1].huff,a[2].huff,a[1].huff[1].cou+a[2].huff[1].cou);
		a[2].use=true;
	}
	for(int i=1;i<=tree_max;++i)
	{
		if(coun[a[1].huff[i].c]>0)
		{
			co[a[1].huff[i].c].size=log2(i);
			for(int j=(log2(i));j>=1;--j)
			{
				_set(co[a[1].huff[i].c].code,j,get(i,j));
			}
		}
	}
	
	for(int i=1;i<=512;++i)
	{
		if(coun[i]>0)
		{
			cout<<"\'"<<char(i-128)<<"\' code:";
			for(int j=1;j<=co[i].size;++j)
			{
				cout<<get(co[i].code,j);
			}
			cout<<endl;
			++diff;
		}
	}
	cout<<"code:\n";
	for(int i=0;i<infilelen;++i)
	{
		for(int j=1;j<=co[fdat[i]+128].size;++j)
		{
			cout<<get(co[fdat[i]+128].code,co[fdat[i]+128].size-j+1);
		}
	}
	
	
	
	obs fout(outfile,out|binary);
	cout<<endl<<diff<<endl;
	fout.puttype(diff);
	for(short i=1;i<=tree_max;++i)
	{
		if(coun[a[1].huff[i].c]>0)
		{
			char c=a[1].huff[i].c-128;
			fout.putchar(c);
			fout.puttype(i);
		}
	}
	for(int i=0;i<infilelen;++i)
	{
		for(int j=1;j<=co[fdat[i]+128].size;++j)
		{
			oxb++;
		}
	}
	cout<<oxb<<endl;
	fout.puttype(oxb);
//	for(int i=0;i<infilelen;++i)
//	{
//		for(int j=1;j<=co[fdat[i]+128].size;++j)
//		{
////			out.putbit(get(co[fdat[i]+128].code,co[fdat[i]+128].size-j+1));
//			cout<<get(co[fdat[i]+128].code,co[fdat[i]+128].size-j+1);
//		}
//	}
	for(int i=0;i<infilelen;++i)
	{
		for(int j=1;j<=co[fdat[i]+128].size;++j)
		{
			fout.putbit(get(co[fdat[i]+128].code,co[fdat[i]+128].size-j+1));
		}
	}
	fout.flush();
	fout.close();
	return 0;
}

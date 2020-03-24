#include<bits/stdc++.h>
using namespace std;
#ifndef huffman_h
#define huffman_h


#define tree_max 1024
#define ll_max 4611686018427387904
#define char_diff 512
#define char_size 8
#define max_mem 134217728
#define file_max 10485760

struct hu
{
	int cou;
	int c;//ÆÕÍ¨×Ö·û+Æ«ÒÆÁ¿
};
struct huf
{
	bool use;
	hu huff[tree_max];
};
struct hufcode
{
	int code,size;
};

inline void ch_ro(hu T[],int ol_ro,int ne_ro)
{
	hu a[tree_max];
	for(int i=1;i<=tree_max;++i)
	{
		a[i].cou=0;
		a[i].c=0;
	}
	for(int i=511;i>=1;--i)
	{
		int p=i+(ne_ro-ol_ro)*pow(2,(int)log2(i));
		a[p]=T[i];
	}
	memcpy(T,a,sizeof(a));
}
inline void ne_ro(hu a[],hu b[],int val)//´æµ½a 
{
	ch_ro(a,1,3);
	ch_ro(b,1,2);
	for(int i=1;i<=tree_max;++i)
	{
		if(a[i].cou==0)
		{
			a[i]=b[i];
		}
	}
	for(int i=1;i<=tree_max;++i)
	{
		b[i].cou=0;
		b[i].c=0;
	}
	a[1].cou=val;
}

inline int get(int a,int b)
{
	return (a&(1<<(b-1)))?1:0;
}
inline void _set(int &a,int b,int val)
{
	if(b<1)
	{
		cerr<<"b<0!!!!!!";
		return;
	}
	if(((a&(1<<(b-1)))?1:0)!=val)
	{
		a^=1<<(b-1);
	}
	return;
}
#endif

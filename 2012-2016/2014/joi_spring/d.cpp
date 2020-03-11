#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

#include "ramen.h"



void Ramen(int N) {
	if(N==1) Answer(0,0);
	
	vector<int> A[2];
	int i,x;
	for(i=0;i+1<N;i+=2) {
		x=Compare(i,i+1);
		A[x==1].push_back(i); 
		A[x==-1].push_back(i+1);
	}
	if(N%2) {
		A[0].push_back(N-1);
		A[1].push_back(N-1);
	}
	while(A[0].size()>1) {
		int a=A[0].back();
		A[0].pop_back();
		int b=A[0].back();
		A[0].pop_back();
		x=Compare(a,b);
		if(x==1) A[0].push_back(b);
		else A[0].push_back(a);
	}
	while(A[1].size()>1) {
		int a=A[1].back();
		A[1].pop_back();
		int b=A[1].back();
		A[1].pop_back();
		x=Compare(a,b);
		if(x==1) A[1].push_back(a);
		else A[1].push_back(b);
	}
	Answer(A[0][0],A[1][0]);
	
	
}


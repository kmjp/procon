#include <message.h>
#include <cassert>
#include <cstdio>
#include "stones.h"
#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int TN,MY;
int N;


void slow() {
	int i,j,k,l,r,x,y; string s;
	if(MY!=0) return;
	
	int step=0;
	int pre=-1,cur=0;
	while(cur<=N) {
		step++;
		int ma=-1LL<<30;
		for(i=pre+1;i<=cur;i++) ma=max(ma,i+(int)GetJumpLength(i));
		pre=cur;
		cur=ma;
	}
	cout<<step<<endl;
	
}
/*
void fast() {
	int i,j,k,l,r,x,y; string s;
	
	int L=S*MY/TN;
	int R=S*(MY+1)/TN;
	
	int pre=1<<30;
	int cnt=0;
	if(L>0) pre=GetStackItem(L-1);
	
	for(i=L;i<R;i++) {
		x=GetStackItem(i);
		if(x<pre) cnt++;
		pre=x;
	}
	
	PutInt(0,cnt);
	Send(0);
	
	if(MY==0) {
		int ret=0;
		FOR(i,TN) {
			Receive(i);
			ret+=GetInt(i);
		}
		cout<<ret<<endl;
	}
}
*/
void solve(){
	
	N=GetNumberOfStones();
	
	if(N<=10000000) slow();
	//else fast();
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}



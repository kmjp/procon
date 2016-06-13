#include "message.h"
#include <bits/stdc++.h>
#include "lisp_plus_plus.h"
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
ll N;
int id[1010];

void solve(){
	int i,j,k,l,r,x,y; string s;
	N=GetLength();
	
	if(N<=1010) {
		if(MY!=0) return;
		x=0;
		FOR(i,N) {
			y = GetCharacter(i);
			if(y=='(') x++;
			if(y==')') x--;
			if(x<0) return _P("%d\n",i);
		}
		if(x==0) return _P("-1\n");
		return _P("%d\n",N);
	}
	else {
		TN--;
		FOR(i,TN+1) id[i]=1LL*i*N/TN;
		
		if(MY!=TN) {
			int mi=0;
			x=0;
			for(i=id[MY];i<id[MY+1];i++) {
				y = GetCharacter(i);
				if(y=='(') x++;
				if(y==')') x--;
				mi=min(mi,x);
			}
			
			PutLL(TN, x);
			PutLL(TN, mi);
			Send(TN);
		}
		
		if(MY==TN) {
			int cur=0;
			int mimi=0;
			FOR(i,TN) {
				Receive(i);
				x = GetLL(i);
				y = GetLL(i);
				mimi=min(mimi,cur+y);
				if(mimi<0) {
					FOR(j,TN) {
						if(j==i) PutLL(j,cur);
						else PutLL(j,-1);
						Send(j);
					}
					return;
				}
				cur += x;
			}
			
			FOR(j,TN) PutLL(j,-1), Send(j);
			if(cur==0) _P("-1\n");
			else _P("%d\n",N);
		}
		
		if(MY!=TN) {
			Receive(TN);
			x = GetLL(TN);
			if(x==-1) return;
			for(i=id[MY];i<id[MY+1];i++) {
				y = GetCharacter(i);
				if(y=='(') x++;
				if(y==')') x--;
				if(x<0) return _P("%d\n",i);
			}
			
		}
		
	}
	
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}



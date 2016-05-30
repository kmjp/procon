#include <message.h>
#include <bits/stdc++.h>
#include "rps.h"
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
const int D=6;

int winright(char a,char b) {
	if(a==b) return 0;
	if(a=='R' && b=='S') return 0;
	if(a=='S' && b=='P') return 0;
	if(a=='P' && b=='R') return 0;
	return 1;
}

vector<pair<int,char>> go(vector<pair<int,char>> V) {
	int i;
	while(V.size()>1) {
		vector<pair<int,char>> VV;
		FOR(i,V.size()/2) VV.push_back(V[i*2+winright(V[i*2].second,V[i*2+1].second)]);
		swap(V,VV);
	}
	return V;
}

void solve(){
	int i,j,k,l,r,x,y; string s;
	vector<pair<int,char>> V;
	N=GetN();
	if(N<=D) {
		if(MY!=0) return;
		FOR(i,1<<N) V.push_back({i,GetFavoriteMove(i)});
		
		V=go(V);
		cout<<V[0].first<<endl;
	}
	else {
		if(MY>=1<<D) return;
		FOR(i,1<<(N-D)) V.push_back({(MY<<(N-D)) + i,GetFavoriteMove((MY<<(N-D)) + i)});
		
		V=go(V);
		PutInt(0,V[0].first);
		PutInt(0,V[0].second);
		Send(0);
		
		if(MY==0) {
			for(i=1;i<1<<D;i++) {
				Receive(i);
				x=GetInt(i);
				y=GetInt(i);
				V.push_back({x,y});
			}
			V=go(V);
			cout<<V[0].first<<endl;
		}
		
	}
	
	
}


int main(int argc,char** argv){
	
	TN=NumberOfNodes();
	MY=MyNodeId();
	solve();
	return 0;
	
}



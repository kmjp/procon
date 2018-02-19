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

vector<vector<int>> P;

int N;
int MH,TH;

void dfs(int cur,int p) {
	if(P[cur][0]==P[p][0]) return;
	if(P[p][0]<P[cur][0]) {
		if(P[cur][1]!=-1) {
			dfs(P[cur][1],p);
		}
		else {
			P[cur][1]=p;
		}
	}
	else {
		if(P[cur][2]!=-1) {
			dfs(P[cur][2],p);
		}
		else {
			P[cur][2]=p;
		}
	}
}

int dfs2(int c) {
	int h=0;
	if(P[c][1]!=-1) h=max(h,dfs2(P[c][1])+1);
	if(P[c][2]!=-1) h=max(h,dfs2(P[c][2])+1);
	TH+=h;
	return h;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		P.push_back({x,-1,-1});
		if(i) dfs(0,P.size()-1);
	}
	
	MH=dfs2(0);
	cout<<MH<<endl;
	cout<<TH<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

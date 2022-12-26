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

int N;
vector<int> E[101010];;

int dfs(int cur) {
	if(E[cur].empty()) return 1;
	int C[4]={};
	FORR(e,E[cur]) {
		int r=dfs(e);
		C[r]++;
	}
	if(C[0]&&C[0]+C[2]==E[cur].size()) return 1;
	if(C[1]&&C[1]+C[2]==E[cur].size()) return 0;
	if(C[2]==E[cur].size()) return 3;
	return 2;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int nim=0;
	cin>>N;
	
	int num=0;
	FOR(i,N) {
		cin>>x;
		FOR(j,x) E[j].clear();
		for(j=1;j<x;j++) {
			cin>>y;
			E[y-1].push_back(j);
		}
		
		x=dfs(0);
		if(x==3) {
			cout<<"Alice"<<endl;
			return;
		}
		if(x==0) num++;
		
	}
	if(num%2==1) cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

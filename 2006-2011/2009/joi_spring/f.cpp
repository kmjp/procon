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

int N,C;
vector<int> T[3030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,2*N) {
		cin>>x>>y;
		T[y].push_back(x);
	}
	FOR(i,N+1) sort(ALL(T[i]));
	
	while(T[C].size()<2) {
		T[C].push_back(T[0].back());
		T[0].pop_back();
	}
	int TC=T[C][0]+T[C][1];
	FOR(i,N+1) sort(ALL(T[i]));
	for(i=1;i<=N;i++) if(T[i].size()==1) {
		for(j=T[0].size()-1;j>=0;j--) {
			if(T[0][j]+T[i][0]<=TC) {
				T[i].push_back(T[0][j]);
				T[0].erase(T[0].begin()+j);
				break;
			}
		}
		if(j==-1) {
			T[i].push_back(T[0].back());
			T[0].pop_back();
		}
	}
	for(i=1;i<=N;i++) if(T[i].size()==0) {
		T[i].push_back(T[0].back());
		T[0].pop_back();
		for(j=T[0].size()-1;j>=0;j--) {
			if(T[0][j]+T[i][0]<=TC) {
				T[i].push_back(T[0][j]);
				T[0].erase(T[0].begin()+j);
				break;
			}
		}
		if(j==-1) {
			T[i].push_back(T[0].back());
			T[0].pop_back();
		}
	}
	
	int ret=1;
	for(i=1;i<=N;i++) if(T[i][0]+T[i][1]>TC) ret++;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S[300];

const int MV=500;
vector<int> E[MV+1];
int match[MV+1], vis[MV+1];

int bip_dfs(int v) {
	int i;
	vis[v]=1;
	FOR(i,E[v].size()) if(vis[E[v][i]]==0) {
		int tar=E[v][i];
		if(match[tar]<0 || (vis[match[tar]]==0 && bip_dfs(match[tar]))) {
			match[tar]=v;
			match[v]=tar;
			return 1;
		}
	}
	return 0;
}

int bip_match(int NV){
	int i,nmatch=0;
	MINUS(match);
	FOR(i,NV) if(match[i]==-1) { ZERO(vis); nmatch += bip_dfs(i);}
	return nmatch;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	
	FOR(i,26) {
		FOR(j,100003) {
			int ng=0;
			FOR(x,N) if(S[x].size()<=j) ng++;
			if(ng) break;
			ll ma[4]={};
			FOR(x,N) {
				E[x].clear();
				E[N+x].clear();
				FOR(y,N) if(j+y<S[x].size() && S[x][j+y]=='a'+i) {
					E[x].push_back(N+y),E[N+y].push_back(x);
					ma[y/60] |= 1LL<<(y%60);
				}
				if(E[x].empty()) {
					ng++;
					break;
				}
			}
			if(ng) continue;
			for(y=N;y<=199;y++) ma[y/60] |= 1LL<<(y%60);
			if(ma[0]!=(1LL<<60)-1) continue;
			if(ma[1]!=(1LL<<60)-1) continue;
			if(ma[2]!=(1LL<<60)-1) continue;
			if(ma[3]!=(1LL<<20)-1) continue;
			
			x=bip_match(2*N);
			if(x==N) {
				cout<<"YES"<<endl;
				return;
			}
			j+=(N-x)-1;
		}
		
	}
	cout<<"NO"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

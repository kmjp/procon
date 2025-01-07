#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,M;
vector<int> E[202020],RE[202020];
int num[202020];

int mc[20];
int tmask[1<<19];


vector<int> ok[20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	/*
	cin>>N;
	int ret=0;
	for(i=1;i<=N;i++) {
		for(j=i;j<=N;j+=i) num[j]^=1;
		ret+=num[i];
		if(ret>i/5) cout<<i<<" "<<ret<<endl;
	}
	return;
	*/
	int mask;
	FOR(i,19) {
		for(x=i+1;x<=19;x+=(i+1)) mc[i]|=1<<(x-1);
	}
	FOR(mask,1<<19) if(mask) {
		int total=0;
		FOR(i,19) if(mask&(1<<i)) total^=mc[i];
		for(i=1;i<=19;i++) if(mask<(1<<i)) {
			int t=total&((1<<i)-1);
			if(__builtin_popcount(t)*5<=i) ok[i].push_back(mask);
		}
	}
	
	//for(i=1;i<=19;i++) cout<<i<<" "<<ok[i].size()<<endl;
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N+1) E[i].clear(),RE[i].clear();
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
		}
		
		if(N>=20) {
			cout<<N<<endl;
			for(i=1;i<=N;i++) cout<<i<<" ";
			cout<<endl;
		}
		else {
			int must[22]={};
			for(i=1;i<=N;i++) FORR(e,E[i-1]) must[i-1]|=1<<e;
			int ret=0;
			FORR(cand,ok[N]) {
				
				FOR(i,N) if(cand&(1<<i)) if((cand&must[i])!=must[i]) break;
				if(i==N) {
					ret=cand;
					break;
				}
			}
			if(ret==0) {
				cout<<-1<<endl;
			}
			else {
				cout<<__builtin_popcount(ret)<<endl;
				FOR(i,N) if(ret&(1<<i)) cout<<i+1<<" ";
				cout<<endl;
			}
		}
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

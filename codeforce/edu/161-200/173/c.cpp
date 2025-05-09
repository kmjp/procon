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

int T,N;
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int c=-1;
		int ma=0,mi=0;
		int cur=0;
		int R=0,L=0;
		FOR(i,N) {
			cin>>A[i];
			if(abs(A[i])!=1) {
				c=i;
				cur=mi=ma=0;
			}
			else {
				ma=max(ma,cur);
				mi=min(mi,cur);
				cur+=A[i];
				R=max(R,cur-mi);
				L=min(L,cur-ma);
			}
		}
		
		set<int> S;
		for(i=L;i<=R;i++) S.insert(i);
		
		if(c!=-1) {
			cur=0;
			int RR=0,RL=0;
			for(i=c+1;i<N;i++) {
				cur+=A[i];
				RR=max(RR,cur);
				RL=min(RL,cur);
			}
			cur=0;
			int LR=0,LL=0;
			for(i=c-1;i>=0;i--) {
				cur+=A[i];
				LR=max(LR,cur);
				LL=min(LL,cur);
			}
			for(i=LL+RL+A[c];i<=LR+RR+A[c];i++) S.insert(i);
		}
		cout<<S.size()<<endl;
		FORR(e,S) cout<<e<<" ";
		cout<<endl;
			

	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int N,M,A[101010];
int D[101010];
set<int> S[3];
int ret[202020];

void change(int p,int d) {
	if(d>1) d=1;
	if(d<-1) d=-1;
	S[D[p]+1].erase(p);
	D[p]=d;
	S[D[p]+1].insert(p);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		D[i]=1;
		S[2].insert(i);
	}
	S[0].insert(N);
	S[1].insert(N);
	S[2].insert(N);
	FOR(i,M) cin>>A[i];
	for(i=M-1;i>=0;i--) {
		x=A[i]-1;
		
		if(D[x]==1) {
			change(x,-1);
			if(x) {
				if(D[x-1]==1) {
					change(x,0);
				}
				else {
					change(x-1,D[x-1]+1);
				}
			}
			if(x+1<N) {
				if(D[x+1]==1) {
					y=min(*S[0].lower_bound(x+1),*S[1].lower_bound(x+1));
					if(y!=N) change(y,D[y]+1);
				}
				else {
					change(x+1,D[x+1]+1);
				}
			}
		}
		else if(D[x]==-1) {
			change(x,1);
			if(x) {
				if(D[x-1]==-1) {
					change(x,0);
				}
				else {
					change(x-1,D[x-1]-1);
				}
			}
			if(x+1<N) {
				if(D[x+1]==-1) {
					y=min(*S[1].lower_bound(x+1),*S[2].lower_bound(x+1));
					if(y!=N) change(y,D[y]-1);
				}
				else {
					change(x+1,D[x+1]-1);
				}
			}
		}
	}
	int mi=0;
	FOR(i,N-1) {
		ret[i+1]=ret[i]+D[i];
		mi=min(mi,ret[i+1]);
	}
	for(i=1;i<N;i++) cout<<ret[i]-mi<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

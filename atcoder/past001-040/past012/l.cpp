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

int N,M;
vector<int> ev[202020];
int A[202020];
int P[202020];
int L[202020],R[202020];
ll from[3],to[3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) {
		cin>>P[i]>>x>>L[i]>>R[i];
		ev[x-1].push_back(i);
	}
	ll ma=0;
	FOR(i,3) {
		from[0]=0;
		from[1]=from[2]=-1LL<<60;
		FOR(j,N) {
			FORR(e,ev[j]) if(i==(L[e]+R[e])%3) from[L[e]]+=P[e];
			FOR(x,3) to[x]=max(from[x],from[(x+2)%3]+A[j]);
			swap(from,to);
		}
		FORR(e,ev[N]) if(i==(L[e]+R[e])%3) from[L[e]]+=P[e];
		ma=max(ma,from[i]);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

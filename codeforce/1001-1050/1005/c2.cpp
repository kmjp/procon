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
ll S[202020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			S[i+1][0]=S[i][0];
			S[i+1][1]=S[i][1];
			if(A[i]>0) S[i+1][0]+=abs(A[i]);
			if(A[i]<0) S[i+1][1]+=abs(A[i]);
		}
		int L=0,R=N-1;
		ll ret=0;
		ll ma=0;
		while(L<=R) {
			while(L<=R&&A[L]>0) ret+=A[L], L++;
			while(L<=R&&A[R]<0) ret+=-A[R], R--;
			ma=max(ma,ret);
			if(L>R) break;
			ma=max(ma,ret+S[R+1][1]-S[L][1]);
			ma=max(ma,ret+S[R+1][0]-S[L][0]);
			L++;
			R--;
		}
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

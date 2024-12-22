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

int T,N,A[805];
int memo[808][808];
int memo2[406][806];

int take(int L,int R) {
	if(L>R) return 0;
	if(memo[L][R]==101010) {
		int ret=10000;
		if(A[L]!=-1) {
			for(int x=L+1;x<=R;x+=2) {
				int len=(x-L)/2+1;
				int a=take(L+1,x-1);
				int b=take(x+1,R);
				if(a>A[L]) continue;
				if(b>N) continue;
				ret=min(ret,max(A[L],b-len));
			}
		}
		memo[L][R]=ret;
	}
	
	return memo[L][R];
}

int hoge(int ma,int L,int R) {
	if(L+1>=R) return 0;
	if(memo2[ma][L]==-1<<20) {
		int ret=hoge(ma,L+1,R);
		if(A[L]!=-1&&A[L]<=ma) {
			for(int x=L+1;x<R;x+=2) {
				int ok=take(L+1,x-1);
				if(ok<=A[L]) {
					int len=(x-L)/2+1;
					ret=max(ret,len+hoge(ma+len,x+1,R));
				}
			}
		}
		memo2[ma][L]=ret;
	}
	return memo2[ma][L];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		FOR(x,N+3) FOR(y,N+3) memo[x][y]=101010;
		FOR(x,N/2+3) FOR(y,N+3) memo2[x][y]=-1<<20;
		
		FOR(i,N) {
			cin>>x;
			x--;
			
			if(x>i||(i-x)%2) A[i]=-1;
			else A[i]=(i-x)/2;
		}
		
		cout<<hoge(0,0,N)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

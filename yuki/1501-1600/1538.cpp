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

int N,K;
int X[20];
set<ll> C[2][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>X[i];
		if(K==X[i]) {
			cout<<"Yes"<<endl;
			return;
		}
	}
	
	if(N==1) {
		cout<<"No"<<endl;
		return;
	}
	
	int A=N/2;
	int B=N-A;
	
	int mask;
	FOR(mask,1<<A) {
		for(int sm=mask;sm>=0;sm--) {
			sm&=mask;
			ll sum=0;
			int p=0,m=0;
			FOR(i,A) if(mask&(1<<i)) {
				if(sm&(1<<i)) p=1, sum+=X[i];
				else m=1, sum-=X[i];
			}
			C[p][m].insert(sum);
		}
	}
	FOR(mask,1<<B) {
		for(int sm=mask;sm>=0;sm--) {
			sm&=mask;
			ll sum=0;
			int p=0,m=0;
			FOR(i,B) if(mask&(1<<i)) {
				if(sm&(1<<i)) p=1, sum+=X[i+A];
				else m=1, sum-=X[i+A];
			}
			
			FOR(x,2) FOR(y,2) if((x|p)&&(y|m)) {
				if(C[x][y].count(K-sum)) {
					cout<<"Yes"<<endl;
					return;
				}
			}
		}
	}
	
	cout<<"No"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

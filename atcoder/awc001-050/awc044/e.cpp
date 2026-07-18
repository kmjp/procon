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
vector<pair<int,int>> V;
const ll mo=998244353;
vector<ll> F,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	F.resize(M+1);
	T.resize(M+1);
	F[0]=1;
	FOR(i,N) {
		cin>>x;
		FORR(v,T) v=0;
		if(x==0) {
			ll sum=0;
			FOR(j,M+1) if(F[j]) {
				if(j<M) (T[j+1]+=F[j]*(M-j))%=mo;
				(T[j]+=j*F[j])%=mo;
			}
		}
		else {
			if(x>M) {
				cout<<0<<endl;
				return;
			}
			for(j=x;j<=M;j++) T[j]=F[j];
			(T[x]+=F[x-1]*(M-(x-1)))%=mo;
		}
		swap(F,T);
	}
	
	ll ret=0;
	FOR(i,M+1) ret+=F[i];
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

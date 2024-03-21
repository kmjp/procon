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
ll X[10];
ll C[202020][10];
int T[202020];
map<vector<ll>,int> D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>X[i];
		X[i]*=100;
	}
	FOR(i,N) {
		FOR(j,M) {
			cin>>C[i][j];
		}
		cin>>T[i];
		vector<ll> V;
		int same=0;
		FOR(j,M) {
			C[i][j]*=T[i];
			V.push_back(C[i][j]);
			if(T[i]==100&&X[j]==C[i][j]) same++;
		}
		if(same==M) {
			cout<<"Yes"<<endl;
			return;
		}
		
		D[V]++;
	}
	FOR(i,N) if(T[i]!=100) {
		vector<ll> V;
		FOR(j,M) V.push_back(C[i][j]);
		D[V]--;
		vector<ll> L;
		FOR(j,M) {
			ll di=X[j]-C[i][j];
			if(di%(100-T[i])) break;
			di/=(100-T[i]);
			di*=100;
			L.push_back(di);
		}
		if(j==M) {
			if(D[L]>0) {
				cout<<"Yes"<<endl;
				return;
			}
		}
		
		D[V]++;
	}
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

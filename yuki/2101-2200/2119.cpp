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
set<int> S[101010];
int B[101010],C[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	FOR(i,M) {
		cin>>B[i]>>C[i];
		C[i]=(C[i]%B[i]+B[i])%B[i];
		S[B[i]].insert(C[i]);
	}
	
	vector<pair<int,int>> cand;
	for(i=1;i<=100000;i++) {
		if(S[i].size()>1) {
			cout<<"NaN"<<endl;
			return;
		}
		if(S[i].size()==1) {
			cand.push_back({*S[i].begin(),i});
		}
	}
	
	FOR(i,N+1) {
		int ok=1;
		FORR2(a,b,cand) {
			if(i%b!=a) {
				ok=0;
				break;
			}
		}
		if(ok) {
			cout<<i<<endl;
			return;
		}
	}
	cout<<"NaN"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int N;
int P[202020],R[202020];
vector<int> ret;
int did[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		R[P[i]]=i;
	}
	
	FOR(i,N) {
		x=R[i];
		while(x>i) {
			if(did[x-1]==1) return _P("-1\n");
			did[x-1]=1;
			ret.push_back(x);
			swap(P[x-1],P[x]);
			R[P[x]]=x;
			R[P[x-1]]=x-1;
			x--;
		}
	}
	FOR(i,N-1) if(did[i]==0) return _P("-1\n");
	FORR(r,ret) cout<<r<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

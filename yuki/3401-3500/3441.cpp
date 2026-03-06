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
int P[202020];
int vis[202020];

vector<int> D[202020];

int NG[202020];

void hoge(vector<int> C) {
	map<int,int> M;
	int i;
	C.push_back(C[0]);
	int g=0;
	FOR(i,C.size()-1) {
		g=__gcd(g,abs(C[i]-C[i+1]));
	}
	FORR(b,D[g]) NG[b]+=C.size()-2;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
	}
	for(i=1;i<=N;i++) {
		for(j=i;j<=N;j+=i) D[j].push_back(i);
	}
	
	FOR(i,N) if(vis[i]==0) {
		vector<int> C={i};
		vis[i]=1;
		while(1) {
			x=P[C.back()];
			if(vis[x]==1) break;
			vis[x]=1;
			C.push_back(x);
		}
		if(C.size()>1) hoge(C);
	}
	
	for(i=1;i<=N-1;i++) {
		cout<<NG[i]<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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
set<int> E[202020],E2[202020];
string S,T;
int did[202020];

vector<int> O[202020];
int in[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
		E2[x-1].insert(y-1);
		E2[y-1].insert(x-1);
	}
	cin>>S;
	FORR(c,S) c=c=='W';
	T=S;
	
	queue<int> Q;
	FOR(i,N) if(E[i].size()==1) {
		did[i]=1;
		Q.push(i);
	}
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		if(E[cur].size()==0) {
			if(S[cur]==0) {
				cout<<-1<<endl;
				return;
			}
			continue;
		}
		int tar=*E[cur].begin();
		E[tar].erase(cur);
		if(did[tar]==0&&E[tar].size()<=1) {
			Q.push(tar);
			did[tar]=1;
		}
		if(S[cur]==1) {
			S[tar]^=1;
			O[cur].push_back(tar);
			in[tar]++;
		}
		else {
			O[tar].push_back(cur);
			in[cur]++;
		}
	}
	
	vector<int> P;
	set<int> cand;
	FOR(i,N) if(in[i]==0) cand.insert(i);
	while(cand.size()) {
		int cur=*cand.begin();
		cand.erase(cur);
		assert(T[cur]==1);
		FORR(e,E2[cur]) T[e]^=1;
		P.push_back(cur+1);
		FORR(e,O[cur]) {
			in[e]--;
			if(in[e]==0) cand.insert(e);
		}
	}
	if(P.size()!=N) {
		cout<<-1<<endl;
	}
	else {
		FORR(p,P) cout<<p<<" ";
		cout<<endl;
	}
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

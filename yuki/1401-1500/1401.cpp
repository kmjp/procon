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
vector<int> S[2020];

vector<int> E[2020];
int in[2020];
set<int> is;
vector<int> R;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		S[i].resize(x);
		FOR(j,x) {
			cin>>S[i][j];
			is.insert(S[i][j]);
		}
		if(S[i].back()!=S[i][0]) {
			E[S[i][0]].push_back(S[i].back());
			in[S[i].back()]++;
		}
	}
	queue<int> Q;
	FORR(s,is) if(in[s]==0) Q.push(s);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		R.push_back(x);
		FORR(e,E[x]) {
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
	}
	FORR(s,is) if(in[s]) return _P("0\n");
	cout<<R.size()<<endl;
	FOR(i,R.size()) {
		if(i) cout<<" ";
		cout<<R[i];
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}


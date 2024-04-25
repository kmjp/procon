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
string S[202020],T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		vector<int> V[26];
		FOR(j,S[i].size()) V[S[i][j]-'a'].push_back(j);
		int ig=0;
		FOR(j,26) {
			reverse(ALL(V[j]));
			if(V[j].size()>=2) ig=1;
		}
		int did=0;
		FOR(j,S[i].size()) if(did==0) {
			FOR(x,S[i][j]-'a') if(V[x].size()) {
				swap(S[i][j],S[i][V[x][0]]);
				did=1;
			}
			V[S[i][j]-'a'].pop_back();
		}
		if(did==0&&ig==0) swap(S[i][S[i].size()-1],S[i][S[i].size()-2]);
		if(T=="") T=S[i];
		T=min(T,S[i]);
	}
	int num=0;
	FOR(i,N) if(S[i]==T) num++;
	FOR(i,N) {
		if(S[i]==T) cout<<N+1-num<<endl;
		else cout<<0<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

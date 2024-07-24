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
int Q;
map<string,int> M;
set<pair<int,string>> S[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>s>>x;
			M[s]=x;
			S[0].insert({x,s});
		}
		else if(i==2) {
			cin>>x;
			N-=x;
		}
		else {
			cin>>s>>x;
			S[0].erase({M[s],s});
			S[1].insert({M[s],s});
			N+=x;
		}
		set<pair<int,string>> V;
		while(S[0].size()+S[1].size()>N) {
			if(S[0].size()) {
				V.insert(*S[0].begin());
				S[0].erase(S[0].begin());
			}
			else {
				V.insert(*S[1].begin());
				S[1].erase(S[1].begin());
			}
		}
		FORR(v,V) cout<<v.second<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int T,N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		int ret=1<<30;
		int cand=0;
		for(i=1;i<=N;i++) if(N%i==0&&N/i<=26) {
			int C[26]={};
			FORR(c,S) C[c-'a']++;
			sort(C,C+26);
			reverse(C,C+26);
			int ok=0;
			FOR(j,N/i) ok+=min(i,C[j]);
			ok=N-ok;
			if(ok<ret) ret=ok, cand=i;
		}
		string T=S;
		vector<pair<int,char>> V;
		FOR(i,26) V.push_back({0,'a'+i});
		FORR(c,S) V[c-'a'].first++;
		sort(ALL(V));
		reverse(ALL(V));
		ret=0;
		FOR(i,N) {
			FOR(x,26) if(V[x].second==S[i]) break;
			if((x<N/cand&&V[x].first>cand) || x>=N/cand) {
				V[x].first--;
				ret++;
				FOR(y,N/cand) if(V[y].first<cand) {
					V[y].first++;
					T[i]=V[y].second;
					break;
				}
			}
		}
		FOR(j,N/cand) assert(V[j].first==cand);
		cout<<ret<<endl;
		cout<<T<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

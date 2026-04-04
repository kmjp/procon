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

int T;
int N,Q;
string S;
int X,V,I;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		string S;
		cin>>S;
		int NX=-1,NI=-1;
		S="X"+S+"I";
		vector<pair<char,int>> W;
		int base=-11,lef=0;
		FORR(c,S) {
			if(W.empty()||W.back().first!=c) W.push_back({c,0});
			W.back().second++;
			if(c=='I') NI++, base++;
			if(c=='X'||c=='V') NX++;
			if(c=='X') base+=10;
			if(c=='V') base+=5;
			if(c=='?') lef++;
		}
		map<int,int> cand[2][2];
		int IV=0;
		FOR(i,W.size()-1) {
			if(W[i].first=='I'&&(W[i+1].first=='V'||W[i+1].first=='X')) base-=2;
		}
		for(i=1;i<W.size()-1;i++) if(W[i].first=='?') {
			x=W[i-1].first=='I';
			y=W[i+1].first!='I';
			cand[x][y][W[i].second]++;
		}
		
		while(Q--) {
			cin>>X>>V>>I;
			int x=lef;
			int ret=base;
			
			I=min(I,x);
			x-=I;
			ret+=I;
			
			V=min(V,x);
			x-=V;
			ret+=V*5;
			
			X=min(X,x);
			ret+=X*10;
			X+=V;
			
			vector<pair<int,int>> C;
			int si=0;
			FORR2(a,b,cand[1][1]) {
				if(a==1) {
					ret-=2*b;
				}
				else {
					x=min(X,b);
					ret-=2*x;
					X-=x;
					x=min(I,b);
					ret-=2*x;
					I-=x;
					C.push_back({a-2,b});
				}
			}
			FORR2(a,b,cand[0][1]) {
				x=min(I,b);
				ret-=2*x;
				I-=x;
				C.push_back({a-1,b});
			}
			FORR2(a,b,cand[1][0]) {
				x=min(X,b);
				ret-=2*x;
				X-=x;
				C.push_back({a-1,b});
			}
			FORR2(a,b,cand[0][0]) C.push_back({a,b});
			sort(ALL(C));
			FORR2(a,b,C) {
				x=min({a/2*b,I,X});
				ret-=2*x;
				I-=x;
				X-=x;
			}
			
			
			
			cout<<ret<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

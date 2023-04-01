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


int H,W;
string S[101];
map<vector<int>,int> dp[101];

vector<int> hoge(vector<int> V,int mask) {
	vector<int> A;
	FORR(v,V) {
		int nm=v&mask;
		mask^=nm;
		if(nm) {
			A.push_back(nm);
		}
		else {
			return {};
		}
	}
	int i;
	FOR(i,W) if(mask&(1<<i)) {
		int cur=1<<i;
		int add=0;
		FORR(v,A) {
			if((v&(cur<<1))||cur&(v<<1)) {
				add|=v;
				v=0;
			}
		}
		A.push_back(cur|add);
	}
	V.clear();
	FORR(a,A) if(a) V.push_back(a);
	sort(ALL(V));
	return V;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	W=7;
	int miy=H+1,may=0;
	FOR(y,H) {
		cin>>S[y];
		while(S[y].size()<7) S[y]+='.';
		FORR(c,S[y]) if(c=='#') miy=min(miy,y), may=max(may,y);
	}
	
	int mask;
	FOR(mask,1<<7) {
		int co=0;
		int ng=0;
		FOR(x,W) {
			if(mask&(1<<x)&&S[miy][x]=='.') co++;
			if((mask&(1<<x))==0&&S[miy][x]=='#') ng=1;
		}
		if(ng==0) dp[miy][hoge({},mask)]=co;
	}
	
	for(y=miy+1;y<=may;y++) {
		FOR(mask,1<<7) {
			int co=0;
			int ng=0;
			FOR(x,W) {
				if(mask&(1<<x)&&S[y][x]=='.') co++;
				if((mask&(1<<x))==0&&S[y][x]=='#') ng=1;
			}
			if(ng) continue;
			FORR2(V,cco,dp[y-1]) {
				vector<int> V2=hoge(V,mask);
				if(V2.empty()) continue;
				if(dp[y].count(V2)==0) dp[y][V2]=100000;
				dp[y][V2]=min(dp[y][V2],cco+co);
			}
		}
	}
	
	int ret=1<<20;
	FORR2(a,b,dp[may]) if(a.size()==1) ret=min(ret,b);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

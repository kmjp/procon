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


int N,A,B;
string S;

int dp[130000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(dp);
	cin>>N>>A>>B>>S;
	string T;
	FORR(c,S) {
		T+=c;
		if(T.size()>=3&&T.substr(T.size()-3)=="con") {
			T.pop_back();
			T.pop_back();
			T.pop_back();
			T+="X";
		}
	}
	vector<int> L;
	int cur=0;
	FORR(c,T) {
		if(c=='X') cur++;
		else if(cur) {
			L.push_back(cur);
			cur=0;
		}
	}
	if(cur) L.push_back(cur);
	dp[0]=0;
	FORR(n,L) {
		for(i=12505;i>=0;i--) if(dp[i]>=0) {
			for(x=n/A;x>=0;x--) {
				y=(n-x*A)/B;
				dp[i+x]=max(dp[i+x],dp[i]+y);
			}
		}
	}
	int ma=0;
	FOR(i,12505) if(dp[i]>=i-1) ma=max(ma,i+min(dp[i],i));
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

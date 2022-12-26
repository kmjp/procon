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
int L[28][28];
int ma=0;

int dp[28];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		FORR(c,s) c-='a';
		FOR(j,s.size()-1) {
			if(s[j]>s[j+1]) break;
		}
		if(j==s.size()-1) {
			if(s[0]==s.back()) L[s[0]][s[0]]+=s.size();
			else L[s[0]][s.back()]=max(L[s[0]][s.back()],(int)s.size());
		}
	}
	
	int ma=0;
	for(x=0;x<=25;x++) {
		int cur=*max_element(dp,dp+x+2)+L[x][x];
		ma=max(ma,cur);
		for(y=x+1;y<26;y++) dp[y+1]=max(dp[y+1],cur+L[x][y]);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

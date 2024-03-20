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
map<int,int> M;
vector<int> C;
int dp[8192];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<int,int> M;
	int ok=0;
	int cur=0;

	cin>>N;
	FOR(i,N) {
		cin>>x;
		cur^=x;
		M[x]++;
		C.push_back(x);
		if(x==0||M[x]>=2) ok=1;
	}
	
	if(cur!=0||(N==2&&M[0]==0)) {
		cout<<"No"<<endl;
	}
	else if(ok) {
		cout<<"Yes"<<endl;
	}
	else {
		x=0;
		FORR(c,C) {
			if(x==0) {
				x=1;
			}
			else {
				
				FOR(i,8192) if(dp[i]) dp[i^c]=1;
				dp[c]=1;
			}
			if(dp[0]) {
				cout<<"Yes"<<endl;
				return;
			}
		}
		cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

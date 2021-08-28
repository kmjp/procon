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
string S;
const ll mo=924844033;

int len0[3030303];
ll dp[3030303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	
	if(count(ALL(S),'1')==0) {
		cout<<S.size()<<endl;
		return;
	}
	
	int lef=1;
	while(S.back()=='0') {
		S.pop_back();
		lef++;
	}
	
	N=S.size();
	int cur=0;
	FOR(i,N) {
		if(S[i]=='0') {
			cur++;
		}
		else {
			len0[i]=cur+1;
			cur=0;
		}
	}
	map<int,ll> tar;
	ll sum=lef;
	for(i=N-1;i>=0;i--) if(S[i]=='1') {
		dp[i]=sum;
		int pre=0;
		
		while(tar.size()) {
			x=tar.begin()->first;
			y=tar.begin()->second;
			if(x<=len0[i]) {
				(sum-=1LL*(x-pre)*y)%=mo;
				pre=x;
				tar.erase(tar.begin());
			}
			else {
				(sum-=1LL*(len0[i]-pre)*y)%=mo;
				break;
			}
		}
		sum=(sum+mo+len0[i]*dp[i])%mo;
		tar[len0[i]]=dp[i];
	}
	
	cout<<(tar.begin()->first)*(ll)(tar.begin()->second)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

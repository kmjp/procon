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

ll N;
const ll mo=1000000007;
ll p10[20];

array<ll,4> memo[20][2][2][10]; //Œ…, less, head, prev

array<ll,4> dfs(int d,int le,int head,int prev) {
	if(d==-1) {
		if(head) return {0,0,0,0};
		return {1,0,0,0};
	}
	if(memo[d][le][head][prev][0]!=-1) return memo[d][le][head][prev];
	ll count[2]={},sum[2]={};
	
	int i;
	int c=N/p10[d]%10;
	FOR(i,10) {
		if(le==0&&i>c) continue;
		auto p=dfs(d-1,le|(i<c),i?0:head,i);
		
		if(i==0&&head==0) {
			count[1]+=p[0]+p[1];
			sum[1]+=p[2]+p[3];
			if(head==0) (sum[1]+=(p[0]+p[1])*abs(i-prev))%=mo;
		}
		else {
			count[0]+=p[0];
			count[1]+=p[1];
			(sum[0]+=p[2])%=mo;
			(sum[1]+=p[3])%=mo;
			if(head==0) {
				(sum[0]+=p[0]*abs(i-prev))%=mo;
				(sum[1]+=p[1]*abs(i-prev))%=mo;
			}
		}
	}
	memo[d][le][head][prev]={count[0]%mo,count[1]%mo,sum[0]%mo,sum[1]%mo};
	return memo[d][le][head][prev];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,19) p10[i+1]=p10[i]*10;
	MINUS(memo);
	cin>>N;
	auto p=dfs(19,0,1,0);
	
	cout<<(p[2]+p[3]*2)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

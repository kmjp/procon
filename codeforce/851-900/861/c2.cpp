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
ll L,R;
ll p10[20];
ll dp[20][2][2][2];
int CL,CR;

ll dfs(int d,int mo,int le,int to) {
	if(d<0) {
		if(mo+le<2) return -2;
		return 0;
	}
	
	if(dp[d][mo][le][to]!=-1) return dp[d][mo][le][to];
	ll ret=-2;
	
	ll cl=L/p10[d]%10;
	ll cr=R/p10[d]%10;
	int i;
	FOR(i,10) {
		if(i<CL||i>CR) {
			if(!(i==0&&to)) continue;
		}
		if(le==0&&i>cr) continue;
		if(mo==0&&i<cl) continue;
		ret=dfs(d-1,mo||(i>cl),le||(i<cr),i==0&&to);
		if(ret>=0) {
			ret+=i*p10[d];
			break;
		}
	}
	
	
	return dp[d][mo][le][to]=ret;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,19) p10[i+1]=p10[i]*10;
	
	cin>>T;
	while(T--) {
		cin>>L>>R;
		L--,R++;
		vector<pair<int,ll>> cand;
		FOR(CL,10) FOR(CR,10) {
			if(CL>CR) continue;
			if(CL==0&&CR==0) continue;
			MINUS(dp);
			cand.push_back({CR-CL,dfs(19,0,0,1)});
		}
		sort(ALL(cand));
		FORR2(a,v,cand) {
			if(v>=0) {
				cout<<v<<endl;
				break;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

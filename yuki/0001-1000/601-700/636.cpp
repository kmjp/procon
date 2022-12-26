#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S[2];
int N;

int memo[2][101010];

int hoge(int id,int d) {
	if(d>=N) return 0;
	if(memo[id][d]>=0) return memo[id][d];
	if(d==N-1) {
		if(S[id][d]>='5') return min(2+'9'-S[id][d],S[id][d]-'4');
		else if(S[id][d]>='1') return min(S[id][d]-'0',2+'4'-S[id][d]);
		return 0;
	}
	
	int ret=101010;
	
	if(S[id][d]>='5') ret=min(ret,S[id][d]-'4'+hoge(id,d+1));
	ret=min(ret,S[id][d]-'0'+hoge(id,d+1));
	
	if(S[id][d]>='5') ret=min(ret,1+'9'-S[id][d]+hoge(id^1,d+1));
	else if(S[id][d]>='1') ret=min(ret,1+'4'-S[id][d]+hoge(id^1,d+1));
	else if(S[id][d]>='0') ret=min(ret,1+hoge(id^1,d+1));
	
	return memo[id][d]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S[0];
	while(S[0].back()=='0') S[0].pop_back();
	N=S[0].size();
	
	S[1]=S[0];
	int carry=0;
	for(i=N-1;i>=0;i--) {
		if(carry==0) {
			if(S[1][i]!='0') {
				carry=1;
				S[1][i]='0'+(10-(S[1][i]-'0'));
			}
		}
		else {
			S[1][i]='0'+(9-(S[1][i]-'0'));
		}
	}
	
	MINUS(memo);
	
	cout<<hoge(0,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

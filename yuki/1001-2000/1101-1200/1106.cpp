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

ll N;
ll memo[30][2][2][120];
vector<int> V;


ll dp(int d,int pos,int les,int dif) {
	if(d==V.size()) {
		return (dif==60)&&pos;
	}
	
	if(memo[d][pos][les][dif]>=0) return memo[d][pos][les][dif];
	ll ret=0;
	int i;
	for(i=-2;i<=2;i++) {
		if(les==0 && i>V[d]) continue;
		if(pos==0&&i<0) continue;
		
		ret+=dp(d+1,pos|(i>0),les|i<V[d],dif+i);
		
	}
	return memo[d][pos][les][dif]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(N) {
		x=N%5;
		if(x<0) x+=5;
		if(x>=3) x=x-5;
		V.push_back(x);
		N=(N-x)/5;
	}
	reverse(ALL(V));
	MINUS(memo);
	
	cout<<dp(0,0,0,60)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

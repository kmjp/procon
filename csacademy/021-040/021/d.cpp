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

int N,K;
int did[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K;
	
	queue<pair<string,int>> Q;
	string S="0";
	S[0]+=K;
	Q.push({S,K});
	
	while(Q.size()) {
		auto q=Q.front();
		Q.pop();
		if(q.second%N==0) {
			cout<<q.first<<endl;
			return;
		}
		if(did[q.second*10%N]==0) {
			did[q.second*10%N]=1;
			Q.push({q.first+"0",q.second*10%N});
		}
		if(did[(q.second*10+K)%N]==0) {
			did[(q.second*10+K)%N]=1;
			Q.push({q.first+S,(q.second*10+K)%N});
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

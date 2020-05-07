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


int Q;
deque<pair<char,int>> D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>j;
		if(j==1) {
			cin>>s>>x;
			D.push_back({s[0],x});
		}
		else {
			cin>>x;
			ll C[26]={};
			while(x&&D.size()) {
				y=min(x,D[0].second);
				C[D[0].first-'a']+=y;
				D[0].second-=y;
				x-=y;
				if(D[0].second==0) D.pop_front();
			}
			ll ret=0;
			FOR(i,26) ret+=C[i]*C[i];
			cout<<ret<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

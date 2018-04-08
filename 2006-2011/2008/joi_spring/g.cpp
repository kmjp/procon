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

int N;
map<pair<int,int>,int> M;

int L,R,U,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>x>>y;
	FOR(i,N) {
		cin>>L>>U>>R>>D;
		for(y=U;y<=D;y++) for(x=L;x<=R;x++) M[{x,y}]++;
	}
	
	int ma=0;
	int tot=0;
	FORR(r,M) {
		if(r.second>ma) ma=r.second, tot=0;
		if(r.second==ma) tot++;
	}
	cout<<ma<<endl;
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

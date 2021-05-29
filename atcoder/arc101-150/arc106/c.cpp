#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<pair<int,int>> ret;
	
	if(M>0) {
		if(M>N-2) {
			cout<<-1<<endl;
			return;
		}
		ret.push_back({1,500000});
		FOR(i,M+1) {
			ret.push_back({10+i*2,10+i*2+1});
		}
		FOR(i,N-(M+2)) ret.push_back({500010+i*2,500010+i*2+1});
	}
	else if(M==0) {
		FOR(i,N) ret.push_back({10+i*2,10+i*2+1});
	}
	else {
		cout<<-1<<endl;
		return;
	}
	
	FORR(r,ret) {
		cout<<r.first<<" "<<r.second<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

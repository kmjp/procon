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
int C[101010],T[101010];
ll ret[101010];
vector<pair<ll,int>> E;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>C[i]>>T[i];
		E.push_back({T[i],i});
	}
	E.push_back({1LL<<60,N});
	
	set<int> S;
	sort(ALL(E));
	ll pre=0;
	FORR(e,E) {
		ll dif=e.first-pre;
		while(dif>0 && S.size()) {
			x=*S.begin();
			
			if(C[x]<=dif) {
				ret[x]=pre+C[x];
				pre+=C[x];
				dif-=C[x];
				S.erase(S.begin());
			}
			else {
				C[x]-=dif;
				dif=0;
			}
		}
		pre=e.first;
		S.insert(e.second);
	}
	
	FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

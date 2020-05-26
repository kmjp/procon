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
int D[1010];
int L[1010];
vector<int> ev[2][1010];
set<int> alive;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s>>L[i];
		D[i]=s=="y";
		ev[D[i]^1][L[i]].push_back(i);
		alive.insert(i);
	}
	
	int ret=0;
	FOR(i,1010) {
		FORR(e,ev[0][i]) if(alive.count(e)) {
			ret++;
			while(1) {
				auto it=alive.lower_bound(e);
				if(it==alive.end()) break;
				if(L[*it]>=L[e] && D[*it]==0) break;
				alive.erase(it);
			}
			
			while(1) {
				auto it=alive.lower_bound(e);
				if(it==alive.begin()) break;
				it--;
				if(L[*it]>=L[e] && D[*it]==0) break;
				alive.erase(it);
			}
			
		}
		FORR(e,ev[1][i]) alive.erase(e);
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

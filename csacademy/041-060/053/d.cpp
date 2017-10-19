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
vector<int> X[201010];
int C[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		X[x-1].push_back(y-1);
	}
	FOR(i,100000) {
		if(X[i].size()==1) X[i].clear();
		sort(ALL(X[i]));
	}
	
	ll ret=0;
	int S=40;
	map<pair<int,int>,int> M;
	FOR(i,100000) {
		if(X[i].size()>S) {
			FORR(c,X[i]) C[c]++;
			FOR(j,100000) if(j!=i && X[j].size()>=2) {
				int cnt=0;
				FORR(c,X[j]) cnt+=C[c];
				ret+=1LL*cnt*(cnt-1)/2;
			}
			FORR(c,X[i]) C[c]--;
			X[i].clear();
		}
		else {
			FOR(y,X[i].size()) FOR(x,y) M[{X[i][x],X[i][y]}]++;
		}
	}
	
	FORR(r,M) ret+=1LL*r.second*(r.second-1)/2;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

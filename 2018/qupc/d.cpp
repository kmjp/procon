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

int N,M,L;
int T[101010];
vector<int> A[101010],B[101010];
vector<pair<ll,ll>> C[101010];
multiset<pair<ll,ll>> S;
multiset<ll> MR;
int ma=-1;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L;
	FOR(i,N) {
		cin>>T[i];
		T[i]++;
	}
	FOR(i,M) {
		cin>>x>>y;
		A[x-1].push_back(y);
	}
	FOR(i,L) {
		cin>>x>>y;
		B[x-1].push_back(y);
	}
	FOR(i,N) {
		sort(ALL(A[i]));
		sort(ALL(B[i]));
		y=0;
		FORR(a,A[i]) {
			while(y<B[i].size() && B[i][y]<a+T[i]) y++;
			if(y==B[i].size()) {
				ma=max(ma,a);
			}
			else {
				MR.insert(B[i][y]+T[i]);
				S.insert({a,B[i][y]+T[i]});
			}
		}
	}
	
	ll cur=0;
	ll ret=0;
	while(MR.size()) {
		while(S.size() && S.begin()->first<cur) {
			MR.erase(MR.find(S.begin()->second));
			S.erase(S.begin());
		}
		if(MR.empty()) break;
		ret+=2;
		cur=*MR.begin();
	}
	if(ma>=cur) ret++;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

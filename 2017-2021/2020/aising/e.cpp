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

int T;
int N;
int K[202020],L[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll ret=0;
		vector<pair<int,int>> A,B;
		set<int> AS,BS;
		FOR(i,N) {
			cin>>K[i]>>L[i]>>R[i];
			
			if(L[i]>=R[i]) {
				ret+=R[i];
				A.push_back({L[i]-R[i],K[i]});
			}
			else {
				ret+=L[i];
				B.push_back({R[i]-L[i],K[i]});
			}
		}
		FOR(i,A.size()) AS.insert(i);
		FOR(i,B.size()) BS.insert(A.size()+i);
		sort(ALL(A));
		reverse(ALL(A));
		
		FORR(v,A) {
			auto it=AS.lower_bound(v.second);
			if(it==AS.begin()) {
				AS.erase(*AS.rbegin());
			}
			else {
				it--;
				ret+=v.first;
				AS.erase(it);
			}
		}
		sort(ALL(B));
		reverse(ALL(B));
		FORR(v,B) {
			auto it=BS.lower_bound(v.second);
			if(it==BS.end()) {
				BS.erase(BS.begin());
			}
			else {
				ret+=v.first;
				BS.erase(it);
			}
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

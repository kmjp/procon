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
multiset<int> S;
int P[101010];
vector<pair<int,int>> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	S.insert(0);
	S.insert(0);
	S.insert(N+1);
	S.insert(N+1);
	
	FOR(i,N) {
		cin>>P[i+1];
		V.push_back({P[i+1],i+1});
	}
	sort(ALL(V));
	reverse(ALL(V));
	ll ret=0;
	FORR(v,V) {
		ll num=v.first;
		int id=v.second;
		auto it=S.lower_bound(id);
		int R1=*it++;
		int R2=*it--;
		it--;
		int L1=*it--;
		int L2=*it;
		ret+=num*(R2-R1)*(id-L1);
		ret+=num*(L1-L2)*(R1-id);
		S.insert(id);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

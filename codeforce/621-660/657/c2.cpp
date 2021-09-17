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
int N,M;
int A[101010],B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<pair<int,int>> V;
		FOR(i,M) {
			cin>>x>>y;
			V.push_back({x,y});
		}
		sort(ALL(V));
		vector<ll> S;
		S.push_back(0);
		FORR(v,V) S.push_back(S.back()+v.first);
		ll ma=0;
		
		FOR(i,V.size()) {
			ll tmp;
			x=lower_bound(ALL(V),make_pair(V[i].second+1,0))-V.begin();
			
			if(x<=i) {
				if(M-x>=N) {
					tmp=S[V.size()]-S[V.size()-N];
				}
				else {
					tmp=S[V.size()]-S[x]+1LL*V[i].second*(N-(M-x));
				}
			}
			else {
				if(M-x>=N-1) {
					tmp=S[V.size()]-S[V.size()-(N-1)]+V[i].first;
				}
				else {
					tmp=S[V.size()]-S[x]+V[i].first+1LL*V[i].second*(N-1-(M-x));
				}
			}
			
			ma=max(ma,tmp);
		}
		
		
		
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

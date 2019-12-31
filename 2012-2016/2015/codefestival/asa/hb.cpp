#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll K,A[101010],S,ret;
vector<pair<int,ll> > V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i], S+=A[i];
	ret += 2*S + N;
	
	vector<pair<ll,ll> > st;
	st.push_back({0,-1});
	FOR(i,N+1) {
		if(A[i]>st.back().first) {
			st.push_back({A[i],i});
		}
		else {
			while(st[st.size()-2].first>A[i]) {
				ll num=st.back().first-st[st.size()-2].first;
				ret += 2*num;
				V.push_back({i-st.back().second,num});
				st.pop_back();
			}
			ll num=st.back().first-A[i];
			ret += 2*num;
			V.push_back({i-st.back().second,num});
			st.back().first=A[i];
			
		}
	}
	
	ret -= 2*K;
	
	sort(ALL(V));
	FORR(r,V) {
		ll rem=min(r.second,K/r.first);
		ret -= 2*rem;
		K -= rem*r.first;
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

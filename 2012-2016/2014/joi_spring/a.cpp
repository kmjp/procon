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

int N,M,Q;
int A[303030],B[303030],X[303030],Y[303030],T[303030];
int best[101010];
vector<pair<int,int>> V;
vector<pair<int,int>> ev;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N+1) best[i]=1<<30;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>X[i]>>Y[i];
		ev.push_back({Y[i],i});
		ev.push_back({X[i],M+i});
	}
	sort(ALL(ev));
	reverse(ALL(ev));
	FORR(e,ev) {
		x=e.second;
		if(x<M) {
			if(B[x]==N) best[N]=Y[x];
			T[x]=best[B[x]];
		}
		else {
			x-=M;
			best[A[x]]=min(best[A[x]],T[x]);
			if(A[x]==1) {
				if(V.empty() || best[A[x]]<V.back().first) V.push_back({best[A[x]],X[x]});
			}
		}
	}
	V.push_back({-1,-1});
	sort(ALL(V));
	cin>>Q;
	while(Q--) {
		cin>>x;
		y=lower_bound(ALL(V),make_pair(x,0))-V.begin();
		if(y<V.size() && V[y].first==x) {
			cout<<V[y].second<<endl;
		}
		else {
			cout<<V[y-1].second<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

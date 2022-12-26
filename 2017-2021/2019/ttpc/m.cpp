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
vector<int> E[101010];
int L[101010],R[101010],eid;


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> did,ret;

void EulerTour(int cur,int pre=-1) {
	if(pre==-1) ZERO(L),ZERO(R),eid=0;
	L[cur]=eid++;
	ITR(it,E[cur]) if(*it!=pre) EulerTour(*it,cur);
	R[cur]=eid;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	EulerTour(0);
	FOR(i,N) {
		int smaller=i;
		FORR(e,E[i]) if(L[e]>L[i]) {
			int sm=did(R[e]-1)-did(L[e]-1);
			ret.add(0,sm);
			ret.add(L[e],-sm);
			ret.add(R[e],sm);
			ret.add(N,-sm);
			smaller-=sm;
		}
		ret.add(L[i],smaller);
		ret.add(R[i],-smaller);
		
		did.add(L[i],1);
	}
	
	FOR(i,N) cout<<ret(L[i])<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

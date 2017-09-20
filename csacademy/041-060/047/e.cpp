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
ll D;
ll H[101010],G[101010];
ll F[101010],P[101010];
vector<int> ev[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) cin>>H[i];
	FOR(i,N) {
		cin>>G[i];
		F[i]=1;
		if(H[i]<=D) {
			F[i]+=(D-H[i]+1)/G[i];
			while(H[i]+(F[i]-1)*G[i]<=D) F[i]++;
		}
		P[i]=min((D+1+G[i]-1)/G[i],101000LL);
		ev[min(F[i],101000LL)].push_back(P[i]-1);
	}
	int ok=N;
	int ma=0;
	
	set<int> slot;
	multiset<int> M;
	for(i=1;i<=N+1;i++) {
		slot.insert(i-1);
		while(M.size() && *M.begin()==i-1) {
			if(slot.size()) slot.erase(*slot.rbegin());
			M.erase(M.begin());
		}
		FORR(e,ev[i]) {
			if(e>=i) {
				M.insert(e);
			}
			else if(slot.size()) {
				auto it=slot.lower_bound(e+1);
				if(it!=slot.begin()) {
					it--;
					slot.erase(it);
				}
			}
			
			ok--;
		}
		int ret=ok+(i-slot.size())+min(M.size(),slot.size());
		//cout<<i<<ok<<(i-slot.size())<<M.size()<<slot.size()<<" "<<ret<<endl;
		ma=max(ma,ret);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

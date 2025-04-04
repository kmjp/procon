#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int N,K,Q;
int A[202020];
int B[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

BIT<ll,20> num,sum;
int L[202020],R[202020];
ll ret[202020];
vector<int> ev[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>Q;
		FOR(i,N+1) num.add(i,-num(i)),sum.add(i,-sum(i));
		map<int,int> C;
		multiset<int> S;
		FOR(i,N) {
			cin>>A[i];
			A[i]-=i;
			B[i]=0;
			x=A[i];
			if(C.count(x)) {
				S.erase(S.find(C[x]));
			}
			C[x]++;
			S.insert(C[x]);
			if(i>=K-1) {
				if(i>K-1) {
					x=A[i-K];
					S.erase(S.find(C[x]));
					C[x]--;
					S.insert(C[x]);
				}
				B[i-(K-1)]=K-*S.rbegin();
			}
			ev[i].clear();
		}
		FOR(i,Q) {
			cin>>L[i]>>R[i];
			L[i]--;
			ev[L[i]].push_back(i);
		}
		map<int,int> P;
		for(i=N-1;i>=0;i--) {
			x=B[i];
			P[x]++;
			num.add(N-x,1);
			sum.add(N-x,x);
			while(P.rbegin()->first>x) {
				y=P.rbegin()->first;
				num.add(N-x,P[y]);
				num.add(N-y,-P[y]);
				sum.add(N-x,(ll)P[y]*x);
				sum.add(N-y,(ll)-P[y]*y);
				P[x]+=P[y];
				P.erase(y);
			}
			FORR(e,ev[i]) {
				x=R[e]-L[e]-K+1;
				y=num.lower_bound(x);
				if(y) {
					k=num(y-1);
					ret[e]=sum(y-1)+1LL*(x-k)*(N-y);
				}
			}
		}
		
		FOR(i,Q) cout<<ret[i]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

class RangeArray {
public:
	map<ll,ll> V;
	void clear(){ V.clear();V[-1]=V[(1<<30)+1]=-1; }
	RangeArray() { clear(); }

	ll operator[](ll v) { return (--V.lower_bound(v+1))->second; }
	
	void set_range(ll L,ll R,ll v) { // A[L..(R-1)]=v
		if(L>=R) return;
		auto it=V.lower_bound(R+1);
		ll t=(--it)->second; V[R]=t;
		it=V.lower_bound(R); it--;
		while(it->first>=L) it=V.erase(it), it--;
		V[L]=v;
	}
};

int N;
ll K;
ll A[101010],B[101010];
ll X[101010][2];
ll S[101010];

RangeArray ra;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	K*=2;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		A[i]*=2;
		if(B[i]==1 && A[i]>K/2) return _P("-1\n");
		S[i+1]=S[i]+A[i];
	}
	
	FOR(i,2) {
		ra.clear();
		for(x=1;x<=N;x++) {
			int v=ra[S[x]%(K/2)];
			if(v==-1) {
				X[x][i]=2*S[x];
			}
			else {
				ll d=S[x]-S[v];
				X[x][i]=X[v][i]+(d+K/2-1)/(K/2)*(K/2)*2;
			}
			if(B[x-1]==1) {
				ll L=S[x-1]+1,R=S[x]+1;
				if(L+(K/2)<=R) ra.set_range(0,(K/2),x);
				else {
					L%=K/2;
					R%=K/2;
					if(L<R) {
						ra.set_range(L,R,x);
					}
					else {
						ra.set_range(L,K/2,x);
						ra.set_range(0,R,x);
					}
				}
			}
		}
		FOR(x,N+1) S[x]=S[N]-S[x];
		reverse(B,B+N);
		reverse(S,S+N+1);
	}
	
	ll ret=1LL<<60;
	FOR(i,N+1) ret=min(ret,X[i][0]+X[N-i][1]);
	cout<<ret/2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

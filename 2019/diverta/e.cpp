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
int A[505050];

ll mo=1000000007;
ll ret;
vector<int> id[1<<20];

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) (bit[0][entry-1]+=val0)%=mo, (bit[1][entry-1]+=val1)%=mo, entry += entry & -entry;
	}
	V total(int entry) {
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) (v0+=bit[0][entry-1])%=mo, (v1+=bit[1][entry-1])%=mo, entry -= entry & -entry;
		return ((e*v0+v1)%mo+mo)%mo;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1)%mo);
		update(R+1,-val,val*R%mo);
	}
};
BIT_r<ll,21> bt;

ll dp[2];
ll V[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int tot=0;
	id[0].push_back(0);
	FOR(i,N) {
		cin>>A[i];
		tot^=A[i];
		id[tot].push_back(i+1);
	}
	
	if(tot==0) {
		ll ret=1;
		FOR(i,id[0].size()-2) ret=ret*2%mo;
		bt.add(0,0,1);
		for(i=1;i<1<<20;i++) if(id[i].size()) {
			FORR(j,id[i]) {
				x=lower_bound(ALL(id[0]),j)-id[0].begin();
				V[j]=bt.total(x-1);
				bt.add(x,1<<20,V[j]);
			}
			ret+=bt.total(1<<20)-bt.total((1<<20)-1);
			FORR(j,id[i]) {
				x=lower_bound(ALL(id[0]),j)-id[0].begin();
				bt.add(x,1<<20,mo-V[j]);
			}
		}
		cout<<(ret%mo+mo)%mo<<endl;
	}
	else {
		dp[0]=1;
		x=0;
		FOR(i,N) {
			x^=A[i];
			if(x==tot) (dp[1]+=dp[0])%=mo;
			if(x==0) (dp[0]+=dp[1])%=mo;
		}
		cout<<dp[0]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

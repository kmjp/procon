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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	V set(int e,V v) { add(e,v-val[e]);}
};

int N;
ll K;
pair<int,int> P[101010];
BIT<ll,21> bit;

ll num(int v) {
	ZERO(bit.bit);
	ZERO(bit.val);
	
	ll ret=0;
	int i,j=N-1;
	for(i=N-1;i>=0;i--) {
		while(P[j].first>P[i].first+v) bit.add(P[j].second,1),j--;
		ret += j-i;
		ret += bit.total(min(100000,P[i].second+v))-bit.total(max(0,P[i].second-v-1));
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N);
	
	int ret=0;
	for(i=19;i>=0;i--) if(num(ret+(1<<i))<K) ret+=1<<i;
	cout<<ret+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

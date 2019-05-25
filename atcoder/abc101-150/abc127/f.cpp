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

int Q;

int T[202020],A[202020],B[202020];
ll S[202020];
vector<ll> As;

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
BIT<ll,20> num,tot;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	As.push_back(-1<<30);
	As.push_back(1<<30);
	
	for(i=1;i<=Q;i++) {
		cin>>T[i];
		if(T[i]==1) {
			cin>>A[i]>>B[i];
			As.push_back(A[i]);
		}
		S[i]=S[i-1]+B[i];
	}
	
	sort(ALL(As));
	As.erase(unique(ALL(As)),As.end());
	for(i=1;i<=Q;i++) {
		if(T[i]==1) {
			A[i]=lower_bound(ALL(As),A[i])-As.begin();
			num.add(A[i],1);
			tot.add(A[i],As[A[i]]);
		}
		else {
			x=num(1<<19);
			y=(x+1)/2;
			r=num.lower_bound(y);
			ll ret=S[i];
			y=num(r-1);
			ll su=tot(r-1);
			ret+=1LL*y*As[r]-su;
			y=num(1<<19)-num(r);
			ret+=tot(1<<19)-tot(r)-1LL*y*As[r];
			cout<<As[r]<<" "<<ret<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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
int X[202020],Y[202020];
ll mo=998244353;
vector<int> Xs,Ys;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> Lbt,Rbt;
int ev[202020];
ll p2[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,202010) p2[i+1]=p2[i]*2%mo;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		Xs.push_back(X[i]);
		Ys.push_back(Y[i]);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	
	FOR(i,N) {
		X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
		ev[X[i]]=Y[i];
		Rbt.add(Y[i],1);
	}
	ll ret=0;
	FOR(i,N) {
		Rbt.add(ev[i],-1);
		int lt,ld,rt,rd;
		FOR(lt,2) FOR(ld,2) FOR(rt,2) FOR(rd,2) {
			ll LT=lt?p2[Lbt(N)-Lbt(ev[i])]-1:1;
			ll LD=ld?p2[Lbt(ev[i])]-1:1;
			ll RT=rt?p2[Rbt(N)-Rbt(ev[i])]-1:1;
			ll RD=rd?p2[Rbt(ev[i])]-1:1;
			int cand=1;
			if((lt&&rd)||(ld&&rt)) cand++;
			(ret+=LT*LD%mo*RD%mo*RT*cand)%=mo;
		}
		
		Lbt.add(ev[i],1);
	}
	cout<<(ret%mo+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

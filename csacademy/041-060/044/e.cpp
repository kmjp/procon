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
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt,bt2;

int N;
int A[101010];
vector<int> V;
vector<int> ev[101010];
ll ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i],V.push_back(A[i]), bt.add(i,1), ret[i]=1LL<<60;
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	
	FOR(i,N) ev[lower_bound(ALL(V),A[i])-V.begin()].push_back(i);
	ret[ev[0].back()]=ev[0].back()+1;
	
	FOR(i,V.size()-1) {
		FORR(e,ev[i]) bt.add(e,-1);
		FORR(e,ev[i+1]) bt2.add(e,1);
		FORR(e,ev[i]) if(ret[e]<1LL<<60) {
			x=ev[i+1][0];
			y=ev[i+1].back();
			
			if(e<x) {
				ret[y]=min(ret[y],ret[e]+(bt(y)-bt(e)));
			}
			else if(y<e) {
				ret[x]=min(ret[x],ret[e]+(bt(e)-bt(x-1)));
			}
			else {
				// e->x->y
				int goleft=bt(e)-bt(x-1);
				int goright=bt(y)-bt(x-1)-(bt2(e)-bt2(x-1));
				ret[y]=min(ret[y],ret[e]+goleft+goright);
				//e->y->x
				goright=bt(y)-bt(e);
				goleft=bt(y)-bt(x-1)-(bt2(y)-bt2(e-1));
				ret[x]=min(ret[x],ret[e]+goleft+goright);
			}
			
		}
		FORR(e,ev[i+1]) bt2.add(e,-1);
	}
	
	ll mi=1LL<<60;
	FORR(e,ev[V.size()-1]) mi=min(mi,ret[e]);
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

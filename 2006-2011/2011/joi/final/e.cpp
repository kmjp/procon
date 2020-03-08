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
int A[303030],B[303030],id[303030];
pair<int,int> P[303030];

vector<int> ok[103030];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> num,sum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		ok[B[i]].push_back(i);
		P[i]={A[i],i};
	}
	sort(P,P+N);
	FOR(i,N) id[P[i].second]=i;
	
	int ma=0;
	for(i=100000;i>=1;i--) {
		FORR(e,ok[i]) num.add(id[e],1), sum.add(id[e],A[e]);
		int ret=-1;
		for(j=18;j>=0;j--) {
			ll nc=num(ret+(1<<j));
			ll su=sum(ret+(1<<j));
			if(su<=i*nc) ret+=1<<j;
		}
		ma=max(ma,(int)num(ret));
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

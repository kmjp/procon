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
int A[101010];
int num[101010];
int C[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,18> bt;

const int SQ=500;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		num[A[i]]++;
	}
	
	ll ret=0;
	FOR(x,N) {
		int ma=0;
		FOR(i,SQ*2) if(x+i<N) {
			if(num[A[x+i]]<SQ) {
				C[A[x+i]]++;
				ma=max(ma,C[A[x+i]]);
			}
			if(ma*2>i+1) ret++;
		}
		FOR(i,SQ*2) if(x+i<N && num[A[x+i]]<SQ) C[A[x+i]]--;
	}
	
	FOR(i,100100) if(num[i]>=SQ) {
		int cur=1<<17;
		bt.add(cur,1);
		FOR(x,N) {
			if(A[x]==i) cur++;
			else cur--;
			ret+=bt(cur-1);
			bt.add(cur,1);
		}
		cur=1<<17;
		bt.add(cur,-1);
		FOR(x,N) {
			if(A[x]==i) cur++;
			else cur--;
			bt.add(cur,-1);
		}
	}
	
	
	
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

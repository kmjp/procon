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
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};


int N,M,K;
int A[101010],S[10];
int L[101010],R[101010],X[101010];
int mi[101010];

int LL[101010],RR[101010];
vector<int> ev[102010];
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i], mi[i]=101010;
	FOR(i,K) {
		cin>>S[i];
		FOR(j,N) if(A[j]==S[i]) mi[j]=0;
	}
	sort(S,S+K);
	FOR(i,M) {
		cin>>L[i]>>R[i]>>X[i];
		R[i]++;
	}
	
	FOR(i,K) {
		int s=S[i];
		
		FOR(j,N) LL[j]=0, RR[j]=M+1;
		
		FOR(j,20) {
			FOR(x,102000) ev[x].clear();
			ZERO(bt.bit);
			FOR(x,N) {
				ev[(LL[x]+RR[x])/2].push_back(x);
				bt.add(x+1,A[x]-(x?A[x-1]:0));
			}
			
			FOR(x,M) {
				bt.add(L[x],X[x]);
				bt.add(R[x],-X[x]);
				FORR(e,ev[x]) {
					int sum=bt(e+1);
					if(sum==s) mi[e]=min(mi[e],x+1);
					if(sum>s) RR[e]=x;
					else LL[e]=x;
				}
			}
		}
	}
	FOR(i,102000) ev[i].clear();
	ll sum=0;
	ZERO(bt.bit);
	FOR(i,N) ev[mi[i]].push_back(i), sum+=A[i], bt.add(i+1,1);
	FOR(i,M) {
		FORR(e,ev[i]) bt.add(e+1,-1);
		int cnt=bt(R[i]-1)-bt(L[i]-1);
		sum += 1LL*X[i]*cnt;
		cout<<sum<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

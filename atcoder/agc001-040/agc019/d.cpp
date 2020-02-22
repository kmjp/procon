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

string S,T;
int A[10060];
int B[10060];
int L[10060],R[10060];
int N;
int n1,n0;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	N=S.size();
	
	n1=count(ALL(S),'1');
	n0=count(ALL(T),'0');
	if(n1 && n0==N) return _P("-1\n");
	if(S==T) return _P("0\n");
	
	int mi=1<<30;
	for(int loop=0;loop<2;loop++) {
		int pre=-1;
		FOR(i,5*N) {
			A[i]=S[i%N]=='1';
			B[i]=T[i%N]=='1';
			if(B[i]) pre=i;
			L[i]=pre;
		}
		pre=5*N;
		for(i=5*N-1;i>=0;i--) {
			if(B[i]) pre=i;
			R[i]=pre;
		}
		
		//left
		FOR(i,N) {
			int tar=0,shiftmi=101010;
			vector<pair<int,int>> V;
			FOR(j,N) {
				x=2*N+j;
				y=2*N+j-i;
				if(A[x]!=B[y]) {
					tar++;
					if(L[x]<y) V.push_back({y-L[x],R[x]-x});
				}
			}
			if(V.empty()) {
				shiftmi=0;
			}
			else {
				int RR[2020]={};
				int lma=0,rma=0;
				sort(ALL(V));
				FORR(v,V) lma=max(lma,v.first),rma=max(rma,v.second);
				shiftmi=min(lma,rma);
				for(r=V.size()-1;r>=0;r--) {
					RR[r]=max(RR[r+1],V[r].second);
					shiftmi=min(shiftmi,V[r].first+RR[r+1]);
				}
			}
			mi=min(mi,tar+i+2*shiftmi);
		}
		reverse(ALL(S));
		reverse(ALL(T));
	}
	
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

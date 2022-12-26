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

ll mo=998244353;
int N;
int B[1303030];
int A[1303030];

vector<int> P[303030];
int L[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
	}
	
	if(count(A,A+N,0)==0) return _P("0\n");
	if(count(A,A+N,0)==N) {
		ll ret=1;
		FOR(i,N) ret=ret*(i+1)%mo;
		cout<<ret<<endl;
		return;
	}
	
	FOR(i,N) if(A[i]==0 && A[(i+N-1)%N]>0) {
		FOR(j,2*N) B[j]=A[(i+j)%N];
		FOR(j,2*N) A[j]=B[j];
		FOR(j,N) P[A[j]].push_back(j);
		break;
	}
	
	ll ret=1;
	set<int> empty,unused;
	int numfree=0;
	
	empty.insert(4*N);
	FOR(i,N) empty.insert(i), empty.insert(i+N);
	
	FOR(i,N) {
		L[i]=P[i].size();
		if(L[i]>L[0]) return _P("0\n");
		if(L[i]==0) {
			ret=ret*numfree%mo;
			numfree--;
		}
		else {
			if(P[i][0]+L[i]-1!=P[i].back()) return _P("0\n");
			FORR(p,P[i]) {
				empty.erase(p);
				empty.erase(N+p);
				unused.insert(p);
			}
			
			x=P[i][0];
			if(A[x+N-1]>i && A[x+L[i]]>i && L[i]!=L[0]) return _P("0\n");
			if(A[x+N-1]<i && A[x+L[i]]<i) ret=ret*(L[0]-L[i]+1)%mo;
			auto it=unused.lower_bound(P[i][0]-(L[0]-1));
			while(it!=unused.end() && *it<=P[i].back()) {
				auto it2=empty.lower_bound(*it);
				if(*it2-*it<L[0]) {
					it=unused.lower_bound(*it2);
				}
				else {
					numfree++;
					it=unused.erase(it);
				}
			}
			numfree--;
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

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
int A[303030];
int ma[303030];
int mi[303030];
int did[303030];

int proc(vector<int> cand) {
	if(cand.empty()) return 1;
	FORR(c,cand) if(A[c]!=c) return 0;
	
	int i;
	int L=-1,R=-1;
	for(i=cand[0]-1;i<=cand.back()+1;i+=2) {
		if(A[i]==i) return 0;
		if(A[i]<i) {
			if(R>A[i]) return 0;
			R=A[i];
		}
		else {
			if(L>A[i]) return 0;
			L=A[i];
		}
	}
	
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		
		if(abs(i-A[i])%2==1) return _P("No\n");
		if(i<A[i]) {
			did[i+1]++;
			did[A[i]+1]--;
		}
		else {
			did[A[i]+1]++;
			did[i+1]--;
		}
	}
	
	vector<int> cand;
	for(i=1;i<=N;i++) {
		if(i>=2) did[i]+=did[i-2];
		if(did[i]) {
			if(did[i-1]) return _P("No\n");
			if(cand.size() && cand.back()+2!=i) {
				if(!proc(cand)) return _P("No\n");
				cand.clear();
			}
			cand.push_back(i);
		}
	}
	if(!proc(cand)) return _P("No\n");
	cout<<"Yes"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

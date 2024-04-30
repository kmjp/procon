#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
ll A[202020];
int ret[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	if(N==2) {
		cout<<"10"<<endl;
		return;
	}
	int mi=32;
	map<ll,vector<int>> V;
	FOR(i,32) {
		V.clear();
		FOR(j,N) {
			V[A[j]>>i].push_back(j);
			if(V[A[j]>>i].size()>=3) mi=i;
		}
		if(mi==i) break;
	}
	
	FORR2(a,b,V) {
		if(b.size()==2) {
			ret[b[1]]=1;
		}
		else if(b.size()==3) {
			if((A[b[0]]^A[b[1]])>(A[b[0]]^A[b[2]])&&(A[b[0]]^A[b[1]])>(A[b[1]]^A[b[2]])) {
				ret[b[2]]=1;
			}
			else if((A[b[0]]^A[b[2]])>(A[b[1]]^A[b[2]])) {
				ret[b[1]]=1;
			}
			else {
				ret[b[0]]=1;
			}
		}
		else if(b.size()==4) {
			int x=0,y,aa,bb;
			int best=-1;
			ll v=-1;
			for(y=1;y<4;y++) {
				for(aa=1;aa<4;aa++) {
					for(bb=aa+1;bb<4;bb++) {
						if(aa==y||bb==y) continue;
						if(min(A[b[x]]^A[b[y]],A[b[aa]]^A[b[bb]])>v) {
							best=y;
							v=min(A[b[x]]^A[b[y]],A[b[aa]]^A[b[bb]]);
						}
					}
				}
			}
			for(i=1;i<4;i++) if(i!=best) ret[b[i]]=1;
		}
	}
	FOR(i,N) cout<<ret[i];
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int A[3],B[2][3];
int D[2];
int ma;
typedef tuple<int,int,int> S;
set<S> V[10001];
map<S,int> M;

int val(S v){ return get<0>(v)*1000+get<1>(v)*100+get<2>(v);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0]>>A[1]>>A[2];
	FOR(i,2) cin>>D[i]>>B[i][0]>>B[i][1]>>B[i][2];
	
	S f = tie(A[0],A[1],A[2]);
	M[f]=0;
	V[val(f)].insert(f);
	
	for(i=10000;i>=0;i--) {
		ITR(it,V[i]) {
			ma=max(ma,M[*it]);
			FOR(j,2) {
				S k=*it;
				
				x=D[j];
				r=min(x/1000,get<0>(k)); x -= r*1000; get<0>(k)-=r;
				r=min(x/100,get<1>(k));  x -= r*100 ; get<1>(k)-=r;
				r=min(x,get<2>(k));      x -= r;      get<2>(k)-=r;
				if(x==0) {
					get<0>(k) += B[j][0];
					get<1>(k) += B[j][1];
					get<2>(k) += B[j][2];
					M[k]=max(M[k],M[*it]+1);
					V[val(k)].insert(k);
				}
			}
		}
	}
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}


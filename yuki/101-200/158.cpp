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



struct S {
	int a,b,c;
	S(int _a,int _b,int _c){ a=_a, b=_b, c=_c;}
	int val(){ return a*1000+b*100+c;};
};
struct cmp {
	bool operator()(const S& a, const S& b) const {
		return a.a<b.a || (a.a==b.a && (a.b<b.b || (a.b==b.b && a.c<b.c)));  };
};

int A[3],B[2][3];
int D[2];
int ma;
set<S,cmp> V[10001];
map<S,int,cmp> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A[0]>>A[1]>>A[2];
	FOR(i,2) cin>>D[i]>>B[i][0]>>B[i][1]>>B[i][2];
	
	S f(A[0],A[1],A[2]);
	M[f]=0;
	V[f.val()].insert(f);
	
	for(i=10000;i>=0;i--) {
		ITR(it,V[i]) {
			ma=max(ma,M[*it]);
			FOR(j,2) {
				S k=*it;
				
				x=D[j];
				r=min(x/1000,k.a); k.a -= r; x -= r*1000;
				r=min(x/100,k.b);  k.b -= r; x -= r*100;
				r=min(x,k.c);      k.c -= r; x -= r;
				if(x==0) {
					S k2(k.a+B[j][0],k.b+B[j][1],k.c+B[j][2]);
					M[k2]=max(M[k2],M[*it]+1);
					V[k2.val()].insert(k2);
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


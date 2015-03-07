#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void update(int e, V val) {e++; while(e<=1<<ME) bit[e-1]+=val,e+=e&-e;}
};
BIT<double,22> bt;

int N,QQ;
ll P[201000],Q[202000];
double facl[404000];
double pat[202000];

double pp(int x1,int y1,int x2,int y2) {
	int dx=x2-x1,dy=y2-y1;
	if(dx==0 || dy==0) return 0;
	return facl[dx+dy]-facl[dx]-facl[dy];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	facl[1]=0;
	for(i=1;i<=400000;i++) facl[i+1]=facl[i]+log(i+1);
	
	cin>>N;
	FOR(i,N) cin>>P[i]>>Q[i];
	FOR(i,N-1) {
		pat[i+1]=pp(P[i],Q[i],P[i+1],Q[i+1]);
		bt.update(i+1,pat[i+1]);
	}
	
	cin>>QQ;
	while(QQ--) {
		int t,k,a,b,l1,r1,l2,r2;
		cin>>t;
		if(t==1) {
			cin>>k>>a>>b;
			k--;
			
			if(k!=0) {
				double np=pp(P[k-1],Q[k-1],a,b);
				bt.update(k,np-pat[k]);
				pat[k]=np;
			}
			if(k!=N-1) {
				double np=pp(a,b,P[k+1],Q[k+1]);
				bt.update(k+1,np-pat[k+1]);
				pat[k+1]=np;
			}
			P[k]=a;
			Q[k]=b;
		}
		else {
			cin>>l1>>r1>>l2>>r2;
			l1--,r1--,l2--,r2--;
			if(bt.total(r2)-bt.total(l2) > bt.total(r1)-bt.total(l1)) _P("SECOND\n");
			else _P("FIRST\n");
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}


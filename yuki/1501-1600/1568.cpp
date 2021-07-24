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

ll L;
int N,Q;
ll A[1<<19];
ll X[1<<19];
ll D;

struct node {
	ll dif;
	ll ma,mi,up,down;
};

node merge(node a,node b) {
	node v;
	if(a.ma==0&&a.mi==0) return b;
	if(b.ma==0&&b.mi==0) return a;
	v.dif=a.dif+b.dif;
	v.ma=max(a.ma,a.dif+b.ma);
	v.mi=min(a.mi,a.dif+b.mi);
	v.up=max({a.up,b.up,b.ma+a.dif-a.mi});
	v.down=min({a.down,b.down,b.mi+a.dif-a.ma});
	return v;
}

node V[20][1<<19];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>N>>Q;
	A[0]=0;
	FOR(i,N) {
		cin>>A[i+1];
	}
	for(i=N+1;i<1<<18+1;i++) A[i]=1LL<<53;
	for(i=1;i<1<<18;i++) {
		if(i%2==1) X[i]=X[i-1]+A[i]-A[i-1];
		else X[i]=X[i-1]-(A[i]-A[i-1]);
	}
	N+=2;
	FOR(i,N-1) {
		node& v=V[0][i];
		v.dif=X[i+1]-X[i];
		if(X[i+1]>X[i]) {
			v.dif=v.ma=v.up=X[i+1]-X[i];
			v.mi=v.down=0;
		}
		else {
			v.dif=v.mi=v.down=X[i+1]-X[i];
			v.ma=v.up=0;
		}
	}
	FOR(i,19) FOR(j,N) V[i+1][j]=merge(V[i][j],V[i][j+(1<<i)]);
	
	while(Q--) {
		ll B,C;
		cin>>B>>C;
		B=(B+D)%L;
		C=(C+D)%1000000000000000LL;
		
		x=lower_bound(A,A+N,C+1)-A-1;
		ll dif;
		if(X[x]<X[x+1]) {
			dif=A[x+1]-C;
		}
		else {
			dif=-(A[x+1]-C);
		}
		
		if(dif>=B) {
			D=B;
		}
		else if(dif<=B-L) {
			D=abs(B-L);
		}
		else {
			node v;
			v.dif=dif;
			v.ma=v.up=max(0LL,v.dif);
			v.mi=v.down=min(0LL,v.dif);
			x++;
			for(i=18;i>=0;i--) {
				node v2=merge(v,V[i][x]);
				if(v2.up<B&&v2.down>B-L) {
					x+=1<<i;
					v=v2;
				}
			}
			if(X[x]<X[x+1]) {
				D=A[x]+(B-(v.dif-v.mi))-C;
			}
			else {
				D=A[x]+(-(v.ma-v.dif)-(B-L))-C;
			}
		}
		
		
		cout<<D<<endl;
		
	}
	

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

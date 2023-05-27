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

int T,N;
int X[202020];
int Y[202020];
int table[2][2][4];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,20> var,op;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(x,2) FOR(y,2) {
		table[x][y][0]=x&y;
		table[x][y][1]=x|y;
		table[x][y][2]=x^y;
		table[x][y][3]=(1-x)|y;
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			var.add(i,1);
			cin>>s;
			X[i]=s=="True";
		}
		FOR(i,N-1) {
			op.add(i,1);
			cin>>s;
			if(s=="and") Y[i]=0;
			if(s=="or") Y[i]=1;
			if(s=="xor") Y[i]=2;
			if(s=="imp") Y[i]=3;
		}
		FOR(i,N-1) {
			cin>>x;
			int a=var.lower_bound(x);
			int b=var.lower_bound(x+1);
			int c=op.lower_bound(x);
			X[a]=table[X[a]][X[b]][Y[c]];
			var.add(b,-1);
			op.add(c,-1);
		}
		x=var.lower_bound(1);
		var.add(x,-1);
		if(X[x]) {
			cout<<"True"<<endl;
		}
		else {
			cout<<"False"<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

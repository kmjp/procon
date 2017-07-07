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
	void clear() {ZERO(bit);};
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};


vector<int> X[2525];
int N;
ll ret=0;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>x>>y;
		X[x].push_back(y);
	}
	
	FOR(x,2501) sort(ALL(X[x]));
	
	ll tot=0;
	int L,R;
	FOR(L,2501) if(X[L].size()) {
		BIT<int,13> bt;
		bt.clear();
		FORR(e,X[L]) bt.add(e,1);
		
		for(R=L+1;R<=2500;R++) if(X[R].size()) {
			FORR(e,X[R]) if(bt(e)==bt(e-1)) bt.add(e,1);
			int a=0,b=0,pre=0;
			while(a<X[L].size() && b<X[R].size()) {
				if(X[L][a]<X[R][b]) {
					tot += (bt(2501)-bt(X[R][b]-1)) * (bt(X[L][a])-bt(pre));
					pre = X[L][a];
					a++;
				}
				else if(X[L][a]>X[R][b]) {
					tot += (bt(2501)-bt(X[L][a]-1)) * (bt(X[R][b])-bt(pre));
					pre = X[R][b];
					b++;
				}
				else {
					tot += (bt(2501)-bt(X[L][a]-1)) * (bt(X[R][b]-1)-bt(pre));
					tot += (bt(2501)-bt(X[L][a]));
					pre = X[L][a];
					a++;
					b++;
				}
			}
		}
	}
	cout<<tot<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

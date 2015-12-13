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
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

int N,M,Q;
int NN[101010];
int cnt[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N>>Q;
	bt.add(0,M);
	FOR(i,N) {
		cin>>NN[i];
		bt.add(cnt[NN[i]],-1);
		cnt[NN[i]]++;
		bt.add(cnt[NN[i]],1);
	}
	FOR(i,Q) {
		cin>>j;
		if(j==1) {
			cin>>x>>y;
			bt.add(cnt[NN[x]],-1);
			cnt[NN[x]]--;
			bt.add(cnt[NN[x]],1);
			NN[x]=y;
			bt.add(cnt[NN[x]],-1);
			cnt[NN[x]]++;
			bt.add(cnt[NN[x]],1);
			
		}
		else {
			cin>>x;
			cout<<bt(x-1)<<endl;
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

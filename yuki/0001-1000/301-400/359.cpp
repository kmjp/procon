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

int T;
int L;
int A[9];

int li[8][3]= {
	{0,1,2},
	{3,4,5},
	{6,7,8},
	{0,3,6},
	{1,4,7},
	{2,5,8},
	{0,4,8},
	{2,4,6},
};


int isok() {
	int i;
	FOR(i,8) {
		if(A[li[i][0]]==A[li[i][1]]) return 0;
		if(A[li[i][0]]==A[li[i][2]]) return 0;
		if(A[li[i][1]]==A[li[i][2]]) return 0;
		if(A[li[i][0]]<A[li[i][1]] && A[li[i][1]]<A[li[i][2]]) return 0;
		if(A[li[i][0]]>A[li[i][1]] && A[li[i][1]]>A[li[i][2]]) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>L;
		vector<int> V;
		vector<int> cand;
		FOR(i,9) {
			cin>>A[i];
			if(A[i]==0) V.push_back(i);
			else {
				if(A[i]<L) cand.push_back(A[i]);
				if(L-A[i]>=1) cand.push_back(L-A[i]);
			}
		}
		if(L<2) {
			_P("0\n");
			continue;
		}
		cand.push_back(1);
		cand.push_back(L/2);
		cand.push_back(L-1);
		sort(ALL(cand));
		cand.erase(unique(ALL(cand)),cand.end());
		
		ll tot=0;
		FORR(r,cand) {
			A[V[0]]=r;
			A[V[1]]=L-r;
			tot += isok();
		}
		
		FOR(i,cand.size()-1) {
			int x=cand[i]+1;
			int y=cand[i+1]-1;
			
			if(x>y) continue;
			A[V[0]]=x;
			A[V[1]]=L-x;
			if(isok()) tot+=y-x+1;
		}
		
		_P("%lld\n",tot);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

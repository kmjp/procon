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

int N,L,X;
set<int> ex;
multiset<int> M;
multiset<int> D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>X;
	ex.insert(X);
	M.insert(-1);
	M.insert(-2);
	M.insert(min(X,L-X));
	M.insert(L+1);
	M.insert(L+2);
	FOR(i,N) {
		cin>>x;
		if(ex.count(x)) {
			ex.erase(x);
			x=min(x,L-x);
			auto it=M.find(x);
			int a=*prev(prev(it));
			int b=*prev(it);
			int d=*next(it);
			int e=*next(next(it));
			M.erase(it);
			if(a>=0) D.erase(D.find(x-a));
			if(e<=L) D.erase(D.find(e-x));
			if(b>=0 && d<=L) D.erase(D.find(d-b));
			if(a>=0 && d<=L) D.insert(d-a);
			if(b>=0 && e<=L) D.insert(e-b);
		}
		else {
			ex.insert(x);
			x=min(x,L-x);
			M.insert(x);
			auto it=M.find(x);
			int a=*prev(prev(it));
			int b=*prev(it);
			int d=*next(it);
			int e=*next(next(it));
			if(a>=0 && d<=L) D.erase(D.find(d-a));
			if(b>=0 && e<=L) D.erase(D.find(e-b));
			if(a>=0) D.insert(x-a);
			if(e<=L) D.insert(e-x);
			if(b>=0 && d<=L) D.insert(d-b);
		}
		
		auto it=M.end();
		it--;
		it--;
		it--;
		x=*it--;
		y=*it--;
		/*
		FORR(m,M) if(m>=0 && m<=L) cout<<m<<" ";
		cout<<" :";
		FORR(d,D) cout<<d<<" ";
		cout<<endl;
		*/
		cout<<min(D.size()?*D.begin():1<<30,(L-y)-x)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

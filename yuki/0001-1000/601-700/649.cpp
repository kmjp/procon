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


int Q,K;
multiset<ll> A,B;
ll V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q>>K;
	FOR(i,Q) {
		cin>>x;
		if(x==1) {
			cin>>V;
			A.insert(V);
			if(A.size()>K) {
				B.insert(*A.rbegin());
				A.erase(A.find(*A.rbegin()));
			}
		}
		else {
			if(A.size()==K) {
				cout<<*A.rbegin()<<endl;
				A.erase(A.find(*A.rbegin()));
				if(B.size()) {
					A.insert(*B.begin());
					B.erase(B.begin());
				}
			}
			else {
				cout<<-1<<endl;
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

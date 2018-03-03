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

int N,Q;
string S;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> A,B,A2,B2;
set<int> AA,AB,DA,DB;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	FOR(i,N) {
		if(S[i]=='(') {
			A.add(i,1);
			AA.insert(i);
		}
		else {
			B.add(i,1);
			AB.insert(i);
		}
	}
	FOR(i,N) {
		if(S[i]==')' && AA.size()<AB.size()) {
			B.add(i,-1);
			AB.erase(i);
			DB.insert(i);
		}
	}
	for(i=N-1;i>=0;i--) {
		if(S[i]=='(' && AA.size()>AB.size()) {
			A.add(i,-1);
			AA.erase(i);
			DA.insert(i);
		}
	}
	ll AS=0,BS=0;
	int cnt=0;
	FOR(i,N) if(AA.count(i)||AB.count(i)) {
		cnt++;
		if(S[i]=='(') AS+=cnt;
		else BS+=cnt;
	}
	cout<<BS<<" "<<AS<<endl;
	
	while(Q--) {
		cin>>x;
		x--;
		if(DA.count(x) || DB.count(x)) {
			AS+=A(N)-A(x);
			BS+=B(N)-B(x);
			if(S[x]=='(') {
				A.add(x,1);
				AS+=A(x)+B(x);
				DA.erase(x);
				AA.insert(x);
			}
			else {
				B.add(x,1);
				BS+=A(x)+B(x);
				DB.erase(x);
				AB.insert(x);
			}
		}
		if(S[x]=='(') {
			S[x]=')';
			AS-=A(x)+B(x);
			BS+=A(x)+B(x);
			A.add(x,-1);
			B.add(x,1);
			AA.erase(x);
			AB.insert(x);
		}
		else {
			S[x]='(';
			
			AS+=A(x)+B(x);
			BS-=A(x)+B(x);
			B.add(x,-1);
			A.add(x,1);
			AA.insert(x);
			AB.erase(x);
		}
		
		while(AA.size()>AB.size()) {
			if(DB.size()) {
				x=*DB.rbegin();
				DB.erase(x);
				AB.insert(x);
				AS+=A(N)-A(x);
				BS+=B(N)-B(x);
				B.add(x,1);
				BS+=A(x)+B(x);
			}
			else {
				x=*AA.rbegin();
				AA.erase(x);
				DA.insert(x);
				AS-=A(N)-A(x);
				BS-=B(N)-B(x);
				AS-=A(x)+B(x);
				A.add(x,-1);
			}
			
		}
		while(AA.size()<AB.size()) {
			if(DA.size()) {
				x=*DA.begin();
				DA.erase(x);
				AA.insert(x);
				AS+=A(N)-A(x);
				BS+=B(N)-B(x);
				A.add(x,1);
				AS+=A(x)+B(x);
			}
			else {
				x=*AB.begin();
				AB.erase(x);
				DB.insert(x);
				AS-=A(N)-A(x);
				BS-=B(N)-B(x);
				BS-=A(x)+B(x);
				B.add(x,-1);
			}
		}
		
		cout<<BS<<" "<<AS<<"   "<<AB.size()<<"/"<<AA.size()<<" "<<B(N)<<" "<<A(N)<<endl;
		FORR(v,AA) cout<<v;
		cout<<" : ";
		FORR(v,AB) cout<<v;
		cout<<endl;
		cout<<BS-AS<<endl;
		
		
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int N,M,T;
int A[101010],B[101010];
bitset<50500> S[50505];
int ok[50505],C[50505];


void uniform() {
	int i,j;
	
	FOR(i,M) S[A[i]]=S[B[i]]=S[A[i]]|S[B[i]];
	FOR(i,N) if(S[i].count()==N) {
		ok[i]=1;
		
		string R(M,'^');
		for(i=M-1;i>=0;i--) {
			if(ok[B[i]]) R[i]='v';
			ok[A[i]]=ok[B[i]]=ok[A[i]]|ok[B[i]];
			
		}
		cout<<R<<endl;
		return;
	}
	cout<<-1<<endl;
}

void nonuniform() {
	int i,j;
	
	if(N==2) return _P("-1\n");
	FOR(i,N) {
		ok[i]=i;
		C[i]++;
	}
	
	string R(M,'^');
	for(i=M-1;i>=0;i--) {
		if(C[ok[A[i]]]>=2) {
			R[i]='v';
			C[ok[A[i]]]--;
			ok[A[i]]=ok[B[i]];
			C[ok[A[i]]]++;
		}
		else {
			R[i]='^';
			C[ok[B[i]]]--;
			ok[B[i]]=ok[A[i]];
			C[ok[B[i]]]++;
		}
	}
	cout<<R<<endl;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>T;
	FOR(i,N) S[i][i]=1;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
	}
	
	if(T==1) {
		uniform();
	}
	else {
		nonuniform();
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

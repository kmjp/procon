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

int N,M;
int A[101010];
string S[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int cur=0;
	int order=1;
	FOR(i,M) cin>>S[i];
	
	int acc=0,t=0;
	int last=0;
	FOR(i,M) {
		if(S[i]=="number") {
			if(t) {
				A[cur]+=acc;
				acc=t=0;
				cur=(cur+order)%N;
			}
			last=cur;
			A[cur]--;
			cur=(cur+order)%N;
		}
		else if(S[i]=="skip") {
			if(t) {
				A[cur]+=acc;
				acc=t=0;
				cur=(cur+order)%N;
			}
			A[cur]+=acc;
			t=0;
			last=cur;
			A[cur]--;
			cur=(cur+order)%N;
			cur=(cur+order)%N;
		}
		else if(S[i]=="reverse") {
			if(t) {
				A[cur]+=acc;
				acc=t=0;
				cur=(cur+order)%N;
			}
			last=cur;
			A[cur]--;
			order=N-order;
			cur=(cur+order)%N;
		}
		else if(S[i]=="drawtwo") {
			if(t==4) {
				A[cur]+=acc;
				acc=t=0;
				cur=(cur+order)%N;
			}
			t=2;
			acc+=2;
			last=cur;
			A[cur]--;
			cur=(cur+order)%N;
		}
		else if(S[i]=="drawfour") {
			if(t==2) {
				A[cur]+=acc;
				acc=t=0;
				cur=(cur+order)%N;
			}
			t=4;
			acc+=4;
			last=cur;
			A[cur]--;
			cur=(cur+order)%N;
		}
	}
	cout<<(last+1)<<" "<<-A[last]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

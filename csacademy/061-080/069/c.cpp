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

int N;
string S;
int F;
ll from[3030];
ll to[3030];

ll mo=1000000007;
int A,B;
int D[3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	int cur=0;
	FOR(i,N) {
		D[i+1]=D[i];
		if(S[i]=='(') {
			if(cur+1>N-(i+1)) {
				cur--;
				A++;
			}
			else {
				cur++;
			}
		}
		else {
			if(cur==0) {
				cur++;
				B++;
			}
			else {
				cur--;
			}
		}
	}
	
	from[0]=1;
	cur=0;
	FOR(i,N) {
		ZERO(to);
		FOR(x,A+B+1) {
			int tcur=cur;
			if(x<=B) tcur+=2*x;
			else tcur+=2*B-2*(x-B);
			if(tcur<0) continue;
			if(S[i]=='(') {
				// take
				(to[x]+=from[x])%=mo;
				if(x>=B && tcur) (to[x+1]+=from[x])%=mo;
			}
			else {
				if(tcur) (to[x]+=from[x])%=mo;
				if(x<B) (to[x+1]+=from[x])%=mo;
			}
		}
		
		if(S[i]=='(') cur++;
		else cur--;
		swap(from,to);
	}
	
	
	cout<<(A+B)<<" "<<from[A+B]<<endl;
	
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

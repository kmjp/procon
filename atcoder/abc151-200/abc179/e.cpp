#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


ll N,X,M;
int pre[201010];
ll A[201010],S[201010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>M;
	MINUS(pre);
	A[1]=S[1]=X;
	pre[X]=1;
	int start,loop;
	for(i=2;i<=201010;i++) {
		A[i]=(A[i-1]*A[i-1])%M;
		S[i]=S[i-1]+A[i];
		
		if(i==N) {
			cout<<S[i]<<endl;
			return;
		}
		
		if(pre[A[i]]>=0) {
			start=pre[A[i]];
			loop=i-pre[A[i]];
			break;
		}
		pre[A[i]]=i;
	}
	
	ll ret=0;
	ll lp=(N-start)/loop;
	ret+=lp*(S[start+loop]-S[start]);
	N-=lp*loop;
	ret+=S[N];
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

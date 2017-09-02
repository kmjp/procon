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

int X;
int K;
map<ll,vector<int>> V;
map<int,int> M;
int Q,T,A;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>K;
	vector<int> B={0,0,X,0};
	int pre=0;
	V[pre]=B;
	M[pre]=0;
	FOR(i,K) {
		cin>>x;
		int dif=x-pre;
		if(i%2==0) {
			
			if(B[2]<=dif) {
				B[0]=X;
				B[1]=B[2]=B[3]=0;
			}
			else {
				B[1]-=dif;
				B[2]-=dif;
				if(B[1]<0) {
					B[0]+=-B[1];
					B[1]=0;
				}
			}
		}
		else {
			if(B[1]+dif>=X) {
				B[0]=0;
				B[1]=B[2]=B[3]=X;
			}
			else {
				B[1]+=dif;
				B[2]+=dif;
				if(B[2]>X) {
					B[3]+=X-B[2];
					B[2]=X;
				}
			}
		}
		pre=x;
		V[pre]=B;
		M[pre]=(i%2)^1;
	}
	cin>>Q;
	while(Q--) {
		cin>>T>>A;
		auto it=V.lower_bound(T+1);
		it--;
		
		int p=it->first;
		vector<int> v=it->second;
		
		int cur=0;
		if(v[0]>=A) cur=v[1];
		else cur=min(v[2],v[1]+(A-v[0]));
		
		
		if(M[p]==0) cur-=T-p;
		else cur+=T-p;
		cout<<min(max(0,cur),X)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

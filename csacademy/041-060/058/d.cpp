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
int N;
int A[1<<18];
int S[1<<18];
int R[1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		set<int> S0,S1;
		cin>>N;
		FOR(i,1<<N) cin>>A[i+1],R[A[i+1]]=i+1;
		for(i=1;i<2<<N;i++) S0.insert(i);
		FOR(i,2<<N) S[i+1]=0;
		
		vector<int> ret;
		for(i=1<<N;i>=1;i--) {
			
			int highest=*S0.begin();
			
			x = R[i]+(1<<N)-1;
			while(x>=1) {
				if(S[x/2]) {
					S1.erase(x/2);
					break;
				}
				x/=2;
				S[x]=i;
				S0.erase(x);
				S1.insert(x);
			}
			
			//cout<<x<<"\t";
			x/=2;
			while(x>=1) {
				S1.erase(x);
				x/=2;
			}
			S1.erase(0);
			
			if(S1.size()) highest=min(highest,*S1.begin());
			
			y=0;
			while(highest>=1<<y) y++;
			/*
			cout<<highest<<" ";
			FORR(s,S0) cout<<s<<",";
			cout<<" /1/ ";
			FORR(s,S1) cout<<s<<",";
			cout<<"!"<<x<<endl;
			*/
			ret.push_back(N+1-y);
		}
		FOR(i,1<<N) _P("%d%c",ret[(1<<N)-1-i],(i==(1<<N)-1)?'\n':' ');
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

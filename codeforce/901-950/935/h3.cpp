#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,X;
int A[404040];
vector<int> C[20];

int pre[404040],suf[404040];
int num[404040],used[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X;
		int ma=0;
		FOR(i,20) C[i].clear();
		pre[0]=(1<<20)-1;
		int alland=(1<<20)-1;
		FOR(i,N) {
			cin>>A[i];
			ma=max(ma,A[i]);
			FOR(j,20) if((A[i]&(1<<j))==0) C[j].push_back(i);
			pre[i+1]=pre[i]&A[i];
			alland&=A[i];
			used[i]=0;
		}
		FOR(i,ma+1) num[i]=0;
		FOR(i,N) num[A[i]]++;
		suf[N+1]=(1<<20)-1;
		for(i=N;i>=1;i--) suf[i]=suf[i+1]&A[i-1];
		
		vector<int> cand;
		FOR(i,20) {
			if(C[i].size()<=2) {
				FORR(a,C[i]) cand.push_back(a);
			}
		}
		
		sort(ALL(cand));
		cand.erase(unique(ALL(cand)),cand.end());

		pair<int,int> P={-1,-1};
		FORR(c,cand) {
			num[A[c]]--;
			used[c]=1;
			int cur=(1<<20)-1;
			for(i=c+1;i<N;i++) {
				if(i>c+1) cur&=A[i-1];
				int g=__gcd(A[c],A[i]);
				int a=pre[c]&cur&suf[i+2];
				if(g>a+X) P={c,i};
			}
			cur=(1<<20)-1;
			for(i=c-1;i>=0;i--) {
				if(i<c-1) cur&=A[i+1];
				int g=__gcd(A[c],A[i]);
				int a=pre[i]&cur&suf[c+2];
				if(g>a+X) P={c,i};
			}
		}
		
		for(int g=alland+X+1;g<=ma;g++) if(P.first==-1) {
			int sum=0;
			for(i=g;i<=ma;i+=g) sum+=num[i];
			if(sum>=2) {
				vector<int> C;
				FOR(i,N) if(used[i]==0&&A[i]%g==0) C.push_back(i);
				P.first=C[0];
				P.second=C[1];
			}
		}
		
		if(P.first>=0) {
			cout<<"Yes"<<endl;
			cout<<2<<" "<<A[P.first]<<" "<<A[P.second]<<endl;
			cout<<N-2;
			FOR(i,N) if(i!=P.first&&i!=P.second) cout<<" "<<A[i];
			cout<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
			
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

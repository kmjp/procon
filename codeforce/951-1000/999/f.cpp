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

int T,N;
string A,B;

int S[2<<20][2];
int pre[2<<20][2];
int nex[2<<20][2];
vector<int> cand;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,1<<25);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<21> st[2];
int dp[2<<20];
vector<int> del[2<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B;
		N=A.size();
		B=string(N+1,A[0]^1)+B+string(N+2,A.back()^1);
		A=string(N+1,A[0]^1)+A+string(N+2,A.back()^1);
		N=A.size();
		
		int p[2]={-1,-1};
		FOR(i,N) {
			S[i+1][0]=S[i][0]+(A[i]=='0');
			S[i+1][1]=S[i][1]+(A[i]=='1');
			p[B[i]-'0']=i;
			pre[i][0]=p[0];
			pre[i][1]=p[1];
		}
		p[0]=p[1]=N;
		for(i=N-1;i>=0;i--) {
			p[B[i]-'0']=i;
			nex[i][0]=p[0];
			nex[i][1]=p[1];
		}
		cand.clear();
		cand.push_back(0);
		for(i=1;i<N;i++) if(A[i]!=A[cand.back()]) cand.push_back(i);
		cand.push_back(N);
		//cout<<A<<endl;
		//cout<<B<<endl;
		FOR(i,cand.size()-1) {
			x=cand[i];
			y=A[x]-'0';
			//cout<<"#"<<i<<" "<<x<<" "<<y<<" "<<nex[x][y^1]<<" "<<cand[i+1]<<endl;
			if(nex[x][y^1]<cand[i+1]) {
				dp[i]=1<<25;
			}
			else {
				//‚Ç‚±‚Ü‚Å¶‚ÉL‚Î‚¹‚é‚©
				int Lok=x-pre[x][y^1]-1;
				int Lcur=i;
				for(j=20;j>=0;j--) if(Lcur-(1<<j)>=0&&S[x][y]-S[cand[Lcur-(1<<j)]][y]<=Lok) Lcur-=1<<j;
				int Rok=nex[cand[i+1]][y^1]-cand[i+1];
				int Rcur=i+1;
				for(j=20;j>=0;j--) if(Rcur+(1<<j)<cand.size()-1&&S[cand[Rcur+(1<<j)]][y]-S[cand[i+1]][y]<=Rok) Rcur+=1<<j;
				del[Rcur].push_back(i);
				if(i==0) {
					dp[i]=0;
				}
				else {
					dp[i]=(st[(i%2)^1].getval(Lcur,i)+i-1)/2;
				}
				//cout<<i<<" "<<Lok<<" "<<Lcur<<" "<<Rok<<" "<<Rcur<<" "<<dp[i]<<endl;
			}
			FORR(v,del[i]) {
				//cout<<"del "<<v<<endl;
				st[v%2].update(v,1<<25);
			}
			st[i%2].update(i,dp[i]*2-i);
			
		}
		if(dp[cand.size()-2]>1<<23) {
			cout<<-1<<endl;
		}
		else {
			cout<<dp[cand.size()-2]<<endl;
		}
		
		FOR(i,cand.size()+3) del[i].clear();
		FOR(i,N+1) st[i%2].update(i,1<<25);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

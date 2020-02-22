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


string S;
int N;
ll mo=998244353;
ll dp[202020][2][3][3];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>S;
	N=S.size();
	
	if(N<=7) {
		set<string> T,R;
		T.insert(S);
		while(T.size()) {
			set<string> U;
			FORR(t,T) {
				R.insert(t);
				FOR(i,N-1) {
					if(t[i]!=t[i+1]) {
						string a=t;
						a[i]=a[i+1]='a'+'b'+'c'-a[i]-a[i+1];
						if(R.count(a)==0) {
							U.insert(a);
							R.insert(a);
						}
					}
				}
				
			}
			T=U;
		}
		cout<<R.size()<<endl;
		return;
	}
	
	int cnt[3]={};
	int tot=0;
	FORR(c,S) {
		c-='a';
		cnt[c]++;
		tot+=c;
	}
	
	if(cnt[0]==N || cnt[1]==N || cnt[2]==N) return _P("1\n");
	
	dp[1][0][0][0]=1;
	dp[1][0][1][1]=1;
	dp[1][0][2][2]=1;
	for(i=1;i<N;i++) {
		
		FOR(j,2) FOR(x,3) FOR(y,3) FOR(z,3) {
			(dp[i+1][j|(x==z)][z][(y+z)%3]+=dp[i][j][x][y])%=mo;
		}
	}
	
	ll ret=1;
	FOR(i,3) ret+=dp[N][1][i][tot%3];
	FOR(i,N-1) if(S[i]==S[i+1]) {
		ret--;
		break;
	}
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

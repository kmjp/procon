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

int T,N,A[101010],X[101010];
ll from[33];
ll to[33];
ll pat[33];

const ll mo=1000000007;
ll dpF[33][6][2][2];
ll dpT[33][6][2][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>X[i];
		
		ZERO(from);
		from[0]=1;
		FOR(i,N) {
			
			ZERO(dpF);
			dpF[0][0][0][0]=1;
			int ty,good,less,tar;
			for(j=29;j>=0;j--) {
				ZERO(dpT);
				FOR(k,31) FOR(ty,6) FOR(good,2) FOR(less,2) {
					ll v=dpF[k][ty][good][less];
					if(v==0) continue;
					FOR(tar,2) {
						if(tar==1&&less==0&&((X[i]&(1<<j))==0)) continue;
						
						if(tar) {
							int ta=good || (A[i]&(1<<j));
							int nk = (ty==0)?0:k+1;
							int nty=5;
							if(ta) {
								if(ty==0) nty=1;
								if(ty==1||ty==2) nty=2;
							}
							else {
								if(ty==0) nty=0;
								if(ty==1||ty==4) nty=4;
								if(ty==2) nty=3;
							}
							(dpT[nk][nty][good][less]+=v)%=mo;
						}
						else {
							int ngood = good || (A[i]&(1<<j));
							int nless = less || (X[i]&(1<<j));
							(dpT[k][ty][ngood][nless]+=v)%=mo;
						}
					}
				}
				swap(dpT,dpF);
			}
			ZERO(pat);
			pat[0]=mo-1; //0‚Ì•ª
			FOR(k,30) FOR(good,2) FOR(less,2) {
				(pat[0]+=dpF[k][0][good][less])%=mo;
				(pat[1]+=dpF[k][1][good][less])%=mo;
				(pat[k+1]+=dpF[k][2][good][less])%=mo;
				(pat[0]+=dpF[k][3][good][less])%=mo;
				(pat[k^1]+=dpF[k][4][good][less])%=mo;
				(pat[k+1]+=dpF[k][5][good][less])%=mo;
			}
			
			ZERO(to);
			FOR(x,32) FOR(y,32) (to[x^y]+=from[x]*pat[y])%=mo;
			swap(from,to);
		}
		cout<<from[0]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

int N,K;

map<int,int> B[2][1010100];
set<pair<int,int>> S;
ll dp[2010][2010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		if(1LL*x*y>=K) return _P("1\n");
		B[0][x][y]++;
		B[1][y][x]++;
		S.insert({x,y});
	}
	
	int R=S.size();
	int cand=2*sqrt(K/R)+1;
	
	int ret=1<<20;
	FOR(i,2) {
		FOR(x,2010) FOR(y,2010) dp[x][y]=-1LL<<60;
		dp[0][0]=0;
		for(x=1;x<=1000;x++) {
			vector<pair<int,int>> V;
			FORR(m,B[i][x]) V.push_back(m);
			reverse(ALL(V));
			if(V.size()>cand) V.resize(cand);
			int num=0;
			ll sum=0;
			FORR(m,V) num+=m.second,sum+=1LL*m.second*m.first;
			while(V.size()>=2 && x*(num-V.back().second)*(sum-1LL*V.back().second*V.back().first)>=K) {
				num-=V.back().second;
				sum-=1LL*V.back().first*V.back().second;
				V.pop_back();
				ret=min(ret,num);
				cand=min(ret,cand);
			}
			FORR(m,V) {
				for(y=0;y<=2000;y++) {
					for(r=y/x;r<=cand;r++) {
						if(r!=0 && y>=x) break;
						deque<pair<int,ll>> D;
						int num=r;
						for(int b=y;b<=2000;b+=x) {
							
							if(D.size()&&D.front().first+m.second<num) D.pop_front();
							while(D.size() && D.back().second+(num-D.back().first)*m.first<=dp[b][num]) D.pop_back();
							if(dp[b][num]>=0) D.push_back({num,dp[b][num]});
							if(D.size() && dp[b][num]<D.front().second+(num-D.front().first)*m.first) {
								dp[b][num]=D.front().second+(num-D.front().first)*m.first;
								//cout<<"!"<<x<<" "<<b<<" "<<num<<" "<<dp[b][num]<<endl;
							}
							if(dp[b][num]>=0 && b*dp[b][num]>=K) ret=min(ret,num);
							num++;
							if(num>=cand || num>=ret) break;
						}
					}
				}
			}
		}
		
		/*
		for(x=1;x<=2000;x++) for(y=1;y<=2000;y++) if(dp[x][y]>=1) {
			cout<<i<<" "<<x<<" "<<y<<" "<<dp[x][y]<<" "<<(x*dp[x][y]>=K)<<endl;
		}
		*/
		for(x=1;x<=2000;x++) for(y=1;y<=2000;y++) if(y<ret && dp[x][y]>=0 && 1LL*x*dp[x][y]>=K) {
			ret=y;
		}
		
	}
	if(ret==1<<20) ret=-1;
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

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

ll H,W;
int N;
map<int,vector<int>> V;

ll from[3][3][2];
ll to[3][3][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>N;
	FOR(i,N) {
		cin>>y>>x;
		V[y-1].push_back(x-1);
	}
	W--;
	FOR(i,3) FOR(j,3) FOR(x,2) from[i][j][x]=1LL<<60;
	from[2][0][0]=0;
	int pre=0;
	int d1,d2,c;
	int p1,p2,q;
	FORR2(y,v,V) {
		ll up=y-pre;
		pre=y;
		
		sort(ALL(v));
		
		ll cross=W;
		ll Lside=2*v.back();
		ll Rside=2*(W-v[0]);
		ll split=2*W;
		v.push_back(0);
		v.push_back(W);
		sort(ALL(v));
		FOR(i,v.size()-1) split=min(split,2*(W-(v[i+1]-v[i])));
		
		FOR(d1,3) FOR(d2,3) FOR(c,2) to[d1][d2][c]=1LL<<60;
		
		//‰¡’f
		FOR(d1,3) FOR(d2,3) FOR(c,2) {
			ll cur=from[d1][d2][c];
			if(cur>=1LL<<60) continue;
			assert(!((d1==0||d2==0)&&c));
			FOR(p1,3) FOR(p2,3) FOR(q,3) {
				// ‰º‹L‚Ì“_‚ÌŽŸ”‚Í‹ô”
				if((d1+p1)%2) continue;
				if((d2+p2)%2) continue;
				
				//‚Ç‚¿‚ç‚©‚Í•K{
				if(p1+p2==0) continue;
				// ”ñ˜AŒ‹‚È‘¤‚Í•Ó‚ª•K{
				if(c==0) {
					if(d1&&p1==0) continue;
					if(d2&&p2==0) continue;
				}

				int nd1=p1+q;
				if(nd1) nd1=(nd1-1)%2+1;
				int nd2=p2+q;
				if(nd2) nd2=(nd2-1)%2+1;
				
				if(q) {
					//‰¡’f‚·‚é
					chmin(to[nd1][nd2][1],cur+up*(p1+p2)+cross*q);
				}
				else {
					if(nd2==0) {
						chmin(to[nd1][nd2][0],cur+up*(p1+p2)+Lside);
						chmin(to[nd1][2][0],cur+up*(p1+p2)+split);
					}
					else if(nd1==0) {
						chmin(to[nd1][nd2][0],cur+up*(p1+p2)+Rside);
						chmin(to[2][nd2][0],cur+up*(p1+p2)+split);
					}
					else chmin(to[nd1][nd2][c],cur+up*(p1+p2)+split);
				}
			}
		}
		
		swap(from,to);
	}
	ll ret=min({from[2][2][1],from[2][0][0],from[0][2][0]});
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

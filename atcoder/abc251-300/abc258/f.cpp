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

int T;
ll B,K,SX,SY,GX,GY;
ll D[6][6];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>B>>K>>SX>>SY>>GX>>GY;
		vector<ll> Xs,Ys;
		Xs.push_back(SX);
		Xs.push_back(SX/B*B);
		Xs.push_back(SX/B*B+B);
		Xs.push_back(GX);
		Xs.push_back(GX/B*B);
		Xs.push_back(GX/B*B+B);
		Ys.push_back(SY);
		Ys.push_back(SY/B*B);
		Ys.push_back(SY/B*B+B);
		Ys.push_back(GY);
		Ys.push_back(GY/B*B);
		Ys.push_back(GY/B*B+B);
		sort(ALL(Xs));
		sort(ALL(Ys));
		priority_queue<pair<ll,int>> Q;
		FOR(y,6) FOR(x,6) {
			if(Xs[x]==SX&&Ys[y]==SY) {
				D[y][x]=0;
				Q.push({0,y*6+x});
			}
			else {
				D[y][x]=1LL<<60;
			}
		}
		while(Q.size()) {
			ll co=-Q.top().first;
			int cy=Q.top().second/6;
			int cx=Q.top().second%6;
			Q.pop();
			if(Xs[cx]==GX&&Ys[cy]==GY) {
				cout<<co<<endl;
				break;
			}
			
			if(D[cy][cx]!=co) continue;
			if(cx) {
				ll a=co+(Xs[cx]-Xs[cx-1])*((Ys[cy]%B==0)?1:K);
				if(D[cy][cx-1]>a) {
					D[cy][cx-1]=a;
					Q.push({-a,cy*6+cx-1});
				}
			}
			if(cx<5) {
				ll a=co+(Xs[cx+1]-Xs[cx])*((Ys[cy]%B==0)?1:K);
				if(D[cy][cx+1]>a) {
					D[cy][cx+1]=a;
					Q.push({-a,cy*6+cx+1});
				}
			}
			if(cy) {
				ll a=co+(Ys[cy]-Ys[cy-1])*((Xs[cx]%B==0)?1:K);
				if(D[cy-1][cx]>a) {
					D[cy-1][cx]=a;
					Q.push({-a,(cy-1)*6+cx});
				}
			}
			if(cy<5) {
				ll a=co+(Ys[cy+1]-Ys[cy])*((Xs[cx]%B==0)?1:K);
				if(D[cy+1][cx]>a) {
					D[cy+1][cx]=a;
					Q.push({-a,(cy+1)*6+cx});
				}
			}
			
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

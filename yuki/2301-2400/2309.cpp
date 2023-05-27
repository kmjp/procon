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
ll A,B,C,X,Y,Z,W;

ll ret;
void hoge(ll x,ll y,ll z,ll w) {
	if(x>=0&&y>=0&&z>=0&&w>=0) ret=max(ret,x*X+y*Y+z*Z+w*W);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C;
		cin>>X>>Y>>Z>>W;
		ret=0;
		FOR(i,3) {
			for(int a=0;a<=A;a++) {
				ll x,y,z,w;
				// X‚ð”„‚ç‚È‚¢
				//   z+w=a
				// y  +w=B
				// y+z+w=C
				w=a+B-C;
				z=a-w;
				y=B-w;
				hoge(0,y,z,w);
				
				// Y‚ð”„‚ç‚È‚¢
				// x+z+w=a
				// x  +w=B
				//   z+w=C
				w=B+C-a;
				x=B-w;
				z=C-w;
				hoge(x,0,z,w);
				
				// Z‚ð”„‚ç‚È‚¢
				// x  +w=a
				// x+y+w=B
				//   y+w=C
				w=a+C-B;
				x=a-w;
				y=C-w;
				hoge(x,y,0,w);
				
				// W‚ð”„‚ç‚È‚¢
				// x  +z=a
				// x+y  =B
				//   y+z=C
				if((a+B+C)%2==0) {
					x=(a+B-C)/2;
					y=(-a+B+C)/2;
					z=(a-B+C)/2;
					hoge(x,y,z,0);
				}
				
				// W‚ð1ŒÂ”„‚é
				// x  +z=a-1
				// x+y  =B-1
				//   y+z=C-1
				if((a+B+C+3)%2==0&&a&&B&&C) {
					x=(a+B-C-1)/2;
					y=(-a+B+C-1)/2;
					z=(a-B+C-1)/2;
					hoge(x,y,z,1);
				}
				
			}
			
			swap(A,B);
			swap(B,C);
			swap(X,Y);
			swap(Y,Z);
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

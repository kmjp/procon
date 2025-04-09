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
int N,K;
ll X[101010][3];
int P[101010];
int in[101010];
ll from[6][6][6];
ll to[6][6][6];

ll calc() {
	int i,j;
	vector<int> V[3];
	FOR(i,N) V[P[i]].push_back(X[i][P[i]]);
	vector<int> C;
	FOR(i,3) {
		sort(ALL(V[i]));
		reverse(ALL(V[i]));
		FOR(j,V[i].size()/2) C.push_back(V[i][j*2]+V[i][j*2+1]);
	}
	if(C.size()>=K) {
		sort(ALL(C));
		reverse(ALL(C));
		ll sum=0;
		FOR(i,K) sum+=C[i];
		return sum;
	}
	return -1;
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		vector<pair<int,int>> V;
		FOR(i,N) {
			cin>>X[i][0]>>X[i][1]>>X[i][2];
			FOR(j,3) {
				if(X[i][j]>=X[i][(j+1)%3]&&X[i][j]>=X[i][(j+2)%3]) P[i]=j;
			}
			V.push_back({-X[i][P[i]],i});
			in[i]=0;
		}
		int C[3]={};
		sort(ALL(V));
		ll sum=0;
		FOR(i,2*K) {
			sum+=-V[i].first;
			x=V[i].second;
			in[x]=1;
			C[P[x]]++;
		}
		FOR(x,5) FOR(y,5) FOR(z,5) from[x][y][z]=-1LL<<60;
		from[2][2][2]=0;
		FOR(i,N) {
			FOR(x,5) FOR(y,5) FOR(z,5) to[x][y][z]=-1LL<<60;
			FOR(x,5) FOR(y,5) FOR(z,5) if(from[x][y][z]>=-1LL<<59) {
				chmax(to[x][y][z],from[x][y][z]);
				if(in[i]) {
					if(P[i]==0&&x) {
						chmax(to[x-1][y][z],from[x][y][z]-X[i][0]);
						chmax(to[x-1][y+1][z],from[x][y][z]-X[i][0]+X[i][1]);
						chmax(to[x-1][y][z+1],from[x][y][z]-X[i][0]+X[i][2]);
					}
					if(P[i]==1&&y) {
						chmax(to[x][y-1][z],from[x][y][z]-X[i][1]);
						chmax(to[x+1][y-1][z],from[x][y][z]-X[i][1]+X[i][0]);
						chmax(to[x][y-1][z+1],from[x][y][z]-X[i][1]+X[i][2]);
					}
					if(P[i]==2&&z) {
						chmax(to[x][y][z-1],from[x][y][z]-X[i][2]);
						chmax(to[x+1][y][z-1],from[x][y][z]-X[i][2]+X[i][0]);
						chmax(to[x][y+1][z-1],from[x][y][z]-X[i][2]+X[i][1]);
					}
				}
				else {
					chmax(to[x+1][y][z],from[x][y][z]+X[i][0]);
					chmax(to[x][y+1][z],from[x][y][z]+X[i][1]);
					chmax(to[x][y][z+1],from[x][y][z]+X[i][2]);
				}
			}
			swap(from,to);
		}
		ll ma=-1LL<<60;
		for(x=-2;x<=2;x++) for(y=-2;y<=2;y++) for(z=-2;z<=2;z++) if(x+y+z==0&&(C[0]+x)%2==0&&(C[1]+y)%2==0&&(C[2]+z)%2==0&C[0]+x>=0&&C[1]+y>=0&&C[2]+z>=0) {
			ma=max(ma,from[x+2][y+2][z+2]);
		}
		sum+=ma;
		
		cout<<sum<<endl;
			
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

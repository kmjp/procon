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

int H,W;
string S[106];
pair<int,char> P[3];

double A[300][300];
int B[300][300];
int num[30000];
int cand[30000][115][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	double pi=atan(1)*4;
	
	P[0].second='R';
	P[1].second='G';
	P[2].second='B';
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FORR(c,S[y]) {
			FOR(i,3) if(c==P[i].second) P[i].first++;
		}
	}
	sort(P,P+3);
	
	if(P[0].first==0) return _P("-1\n");
	
	vector<double> V;
	for(y=-H;y<=H;y++) for(x=-W;x<=W;x++) if(x||y) {
		int g=__gcd(abs(y),abs(x));
		V.push_back(atan2(-y/g,x/g));
		if(V.back()<0) V.back()+=2*pi;
		A[150+x][150+y]=V.back();
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	for(y=-H;y<=H;y++) for(x=-W;x<=W;x++) if(x||y) {
		B[150+x][150+y]=lower_bound(ALL(V),A[150+x][150+y])-V.begin();
	}
	
	
	ll ret=0;
	
	FOR(y,H) FOR(x,W) if(S[y][x]==P[0].second) {
		int sx=0,sy=0,nx=0,ny=0;
		int y2,x2;
		FOR(y2,H) FOR(x2,W) {
			if(S[y2][x2]==P[1].second) {
				
				i=B[x2-x+150][y2-y+150];
				j=B[x-x2+150][y-y2+150];
				cand[i][num[i]][0]=2;
				cand[j][num[j]][0]=1;
				cand[i][num[i]][1]=cand[j][num[j]][1]=x2-x;
				cand[i][num[i]][2]=cand[j][num[j]][2]=y2-y;
				num[i]++;
				num[j]++;
				
				sx+=(x2-x);
				sy+=(y2-y);
				if(y2>y || (y2==y && x2<x)) {
					nx+=(x2-x);
					ny+=(y2-y);
				}
			}
			if(S[y2][x2]==P[2].second) {
				i=B[x2-x+150][y2-y+150];
				cand[i][num[i]][0]=0;
				cand[i][num[i]][1]=x2-x;
				cand[i][num[i]][2]=y2-y;
				num[i]++;
			}
		}
		
		FOR(i,V.size()) {
			FOR(j,num[i]) {
				if(cand[i][j][0]==0) {
					ret+=cand[i][j][2]*(sx-2*nx)-cand[i][j][1]*(sy-2*ny);
				}
				if(cand[i][j][0]==2) {
					nx+=cand[i][j][1];
					ny+=cand[i][j][2];
				}
				if(cand[i][j][0]==1) {
					nx-=cand[i][j][1];
					ny-=cand[i][j][2];
				}
			}
			num[i]=0;
		}
		
	}
	
	double R=ret/2.0;
	FOR(i,3) if(P[i].first>0) R/=P[i].first;
	_P("%.12lf\n",R);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

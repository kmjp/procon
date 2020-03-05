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

int A,B,C;
int AX[11],AY[11];
int BX1[51],BY1[51],BX2[51],BY2[51];
int CX[11],CY[11];
vector<pair<int,int>> V;
int memo[505][505];
double D[11][500];

int cross(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
	ll XX[3],YY[3];
	XX[0]=x2-x1; YY[0]=y2-y1;
	XX[1]=x3-x1; YY[1]=y3-y1;
	XX[2]=x4-x1; YY[2]=y4-y1;
	ll c1=XX[0]*YY[1]-XX[1]*YY[0];
	ll c2=XX[0]*YY[2]-XX[2]*YY[0];
	//cout<<c1<<" "<<c2<<endl;
	if((c1<=0&&c2<=0)||(c1>=0&&c2>=0)) return 0;
	XX[0]=x4-x3; YY[0]=y4-y3;
	XX[1]=x1-x3; YY[1]=y1-y3;
	XX[2]=x2-x3; YY[2]=y2-y3;
	c1=XX[0]*YY[1]-XX[1]*YY[0];
	c2=XX[0]*YY[2]-XX[2]*YY[0];
	//cout<<c1<<" "<<c2<<endl;
	if((c1<=0&&c2<=0)||(c1>=0&&c2>=0)) return 0;
	return 1;
}

int blocked(int a,int b) {
	if(memo[a][b]>=0) return memo[a][b];
	
	int x1=V[a].first;
	int y1=V[a].second;
	int x2=V[b].first;
	int y2=V[b].second;
	int i;
	FOR(i,B) {
		//Œð·”»’è
		if(cross(x1,y1,x2,y2,BX1[i],BY1[i],BX1[i],BY2[i])) return memo[a][b]=i*10+3;
		if(cross(x1,y1,x2,y2,BX1[i],BY1[i],BX2[i],BY1[i])) return memo[a][b]=i*10+4;
		if(cross(x1,y1,x2,y2,BX2[i],BY2[i],BX1[i],BY2[i])) return memo[a][b]=i*10+5;
		if(cross(x1,y1,x2,y2,BX2[i],BY2[i],BX2[i],BY1[i])) return memo[a][b]=i*10+6;
		//‘ÎŠpü‚Æ‚ÌŒð·”»’è‚Å“à•””²‚¯–hŽ~
		if(cross(x1,y1,x2,y2,BX1[i],BY1[i],BX2[i],BY2[i])) return memo[a][b]=i*10+3;
		if(cross(x1,y1,x2,y2,BX1[i],BY2[i],BX2[i],BY1[i])) return memo[a][b]=i*10+3;
	}
	
	
	
	return memo[a][b]=0;
	
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>A>>B>>C;
	cin>>x>>y;
	
	FOR(i,A) {
		cin>>AX[i]>>AY[i];
		V.push_back({AX[i],AY[i]});
	}
	FOR(i,B) {
		cin>>BX1[i]>>BY1[i]>>BX2[i]>>BY2[i];
		V.push_back({BX1[i],BY1[i]});
		V.push_back({BX1[i],BY2[i]});
		V.push_back({BX2[i],BY1[i]});
		V.push_back({BX2[i],BY2[i]});
	}
	FOR(i,C) {
		cin>>CX[i]>>CY[i];
		V.push_back({CX[i],CY[i]});
	}
	MINUS(memo);
	priority_queue<pair<double,int>> Q;
	FOR(x,A) {
		FOR(y,V.size()) D[x][y]=1e9;
		D[x][x]=0;
		Q.push({0,x*10+x});
	}
	
	while(Q.size()) {
		double di=-Q.top().first;
		int cur=Q.top().second/10;
		int id=Q.top().second%10;
		Q.pop();
		if(D[id][cur]!=di) continue;
		FOR(i,V.size()) if(blocked(cur,i)==0) {
			double nd=di+hypot(V[cur].first-V[i].first,V[cur].second-V[i].second);
			if(nd<D[id][i]) {
				D[id][i]=nd;
				Q.push({-nd,i*10+id});
			}
		}
	}
	double tot=0;
	FOR(y,C) {
		double mi=1e9;
		FOR(x,A) mi=min(mi,D[x][A+4*B+y]);
		tot+=mi*2;
	}
	
	_P("%.12lf\n",tot);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

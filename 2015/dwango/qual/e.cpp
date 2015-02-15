#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,Q,NX,NY;
int A[1500],B[1500],C[1500];
int QA[1500],QB[1500],QC[1500];
int pat[3000][3000];
int emp[3000][3000],fil[3000][3000];
map<int,int> MX,MY;
vector<int> XX,YY;

ll area(ll dx,ll dy,ll d) {
	if(d<=0) return 0;
	ll ret=d*(d+1)/2;
	if(dx<d) ret -= (d-dx)*(d-dx+1)/2;
	if(dy<d) ret -= (d-dy)*(d-dy+1)/2;
	if(dx+dy<d) ret += (d-(dx+dy))*(d-(dx+dy)+1)/2;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MX[N]=MY[N]=MX[0]=MY[0]=0;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		MX[N-(A[i]+C[i]-1)]=MY[B[i]-1]=0;
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>QA[i]>>QB[i]>>QC[i];
		MX[N-(QA[i]+QC[i]-1)]=MY[QB[i]-1]=0;
	}
	ITR(it,MX) it->second=XX.size(), XX.push_back(it->first);
	ITR(it,MY) it->second=YY.size(), YY.push_back(it->first);
	NX=XX.size();
	NY=YY.size();
	FOR(i,M) {
		A[i]=MX[N-(A[i]+C[i]-1)];
		B[i]=MY[B[i]-1];
		pat[A[i]][B[i]]=max(pat[A[i]][B[i]],C[i]);
	}
	
	FOR(x,NX) FOR(y,NY) {
		if(x+1<NX) pat[x+1][y]=max(pat[x+1][y],pat[x][y]-(XX[x+1]-XX[x]));
		if(y+1<NY) pat[x][y+1]=max(pat[x][y+1],pat[x][y]-(YY[y+1]-YY[y]));
	}
	FOR(x,NX) {
		for(y=NY-1;y>=0;y--) {
			if(pat[x][y]==0) emp[x][y]=emp[x][y+1]+1;
			if(y!=NY-1 && pat[x][y]-(YY[y+1]-YY[y])==pat[x][y+1]) fil[x][y]=fil[x][y+1]+1;
		}
	}
	
	FOR(i,Q) {
		QA[i]=MX[N-(QA[i]+QC[i]-1)];
		QB[i]=MY[QB[i]-1];
		ll ret=1LL*QC[i]*(QC[i]+1)/2;
		for(x=QA[i];x<NX-1;x++) for(y=QB[i];y<NY-1;y++) {
			j=QC[i]-(XX[x]-XX[QA[i]])-(YY[y]-YY[QB[i]]);
			if(j<=0) break;
			if(emp[x][y]) {
				y+=emp[x][y]-1;
			}
			else if(fil[x][y]) {
				ret -= area(XX[x+1]-XX[x],YY[y+fil[x][y]]-YY[y],min(j,pat[x][y]));
				y+=fil[x][y]-1;
			}
			else {
				ret -= area(XX[x+1]-XX[x],YY[y+1]-YY[y],min(j,pat[x][y]));
			}
		}
		
		cout<<ret<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

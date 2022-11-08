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

int N,Q;
int Y1[2020],Y2[2020],X1[2020],X2[2020],E[2020];
int A[2020][2020];
int B[2020][2020];
int C[2020][2020];

const int MAT=8080;
bitset<8080> BS[8080];
int V[8080],R[8080];

int Gauss(int R,int C,bitset<8080> BS[MAT],int v[MAT],int r[MAT]) {
	int i,j,k;
	int nex=0;
	FOR(i,R) {
		while(nex<C) {
			for(j=i;j<R;j++) if(BS[j][nex]) break;
			if(j!=R) break;
			nex++;
		}
		if(nex>=C) break;
		swap(BS[i],BS[j]);
		swap(v[i],v[j]);
		FOR(j,R) if(i!=j && BS[j][nex]) {
			v[j]^=v[i];
			BS[j]^=BS[i];
		}
		nex++;
	}
	FOR(i,C) r[i]=0;
	int num=0;
	FOR(i,R) {
		
		FOR(j,C) if(BS[i][j]) break;
		if(j<C) {
			r[j]=v[i];
			num++;
		}
		else if(v[i]) {
			return -1;
		}
	}
	
	return num;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>Y1[i]>>Y2[i]>>X1[i]>>X2[i]>>E[i];
		if(E[i]) {
			A[Y1[i]][X1[i]]++;
			A[Y2[i]+1][X1[i]]--;
			A[Y1[i]][X2[i]+1]--;
			A[Y2[i]+1][X2[i]+1]++;
		}
	}
	FOR(y,N+2) FOR(x,N+2) {
		if(y) A[y][x]+=A[y-1][x];
		if(x) A[y][x]+=A[y][x-1];
		if(x&&y) A[y][x]-=A[y-1][x-1];
		if(A[y][x]) B[y][x]=1;
		if(y) B[y][x]+=B[y-1][x];
		if(x) B[y][x]+=B[y][x-1];
		if(x&&y) B[y][x]-=B[y-1][x-1];
		
	}
	vector<int> X;
	FOR(i,Q) {
		if(E[i]==0) {
			//0‚ª1ŒÂ‚à‚È‚¢‚Æ•s‰Â
			k=B[Y2[i]][X2[i]]-B[Y1[i]-1][X2[i]]-B[Y2[i]][X1[i]-1]+B[Y1[i]-1][X1[i]-1];
			if(k==(Y2[i]-Y1[i]+1)*(X2[i]-X1[i]+1)) {
				cout<<"No"<<endl;
				return;
			}
		}
		else {
			X.push_back((Y1[i]-1)*2020+(X1[i]-1));
			X.push_back((Y1[i]-1)*2020+(X2[i]-0));
			X.push_back((Y2[i]-0)*2020+(X1[i]-1));
			X.push_back((Y2[i]-0)*2020+(X2[i]-0));
		}
	}
	sort(ALL(X));
	X.erase(unique(ALL(X)),X.end());
	int nex=0;
	FOR(i,Q) if(E[i]>0) {
		x=lower_bound(ALL(X),(Y1[i]-1)*2020+(X1[i]-1))-X.begin();
		BS[nex][x]=1;
		x=lower_bound(ALL(X),(Y1[i]-1)*2020+(X2[i]-0))-X.begin();
		BS[nex][x]=1;
		x=lower_bound(ALL(X),(Y2[i]-0)*2020+(X1[i]-1))-X.begin();
		BS[nex][x]=1;
		x=lower_bound(ALL(X),(Y2[i]-0)*2020+(X2[i]-0))-X.begin();
		BS[nex][x]=1;
		V[nex]=E[i]>1;
		nex++;
	}
	i=Gauss(nex,X.size(),BS,V,R);
	if(i==-1) {
		cout<<"No"<<endl;
		return;
	}
	FOR(i,X.size()) {
		y=X[i]/2020;
		x=X[i]%2020;
		C[y][x]=R[i];
	}
	
	cout<<"Yes"<<endl;
	
	FOR(y,N) {
		FOR(x,N) {
			int a=B[y+1][x+1]-B[y][x+1]-B[y+1][x]+B[y][x];
			if(a==0) cout<<"0 ";
			else {
				a=C[y+1][x+1]^C[y][x+1]^C[y+1][x]^C[y][x];
				cout<<(a+1)<<" ";
			}
		}
		cout<<endl;
	}
			
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

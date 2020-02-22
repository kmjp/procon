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

int N,Q;
int arr[40000];
int *S=&arr[10000];
int *D=&arr[30000];

pair<int,int> up(pair<int,int>& a,pair<int,int> b) {
	if(a.first>b.first) return a;
	if(a.first<b.first) return a=b;
	a.second+=b.second;
	return a;
}

pair<int,int> rect(int X1,int X2,int Y1,int Y2) {
	pair<int,int> v={-1<<30,0};
	pair<int,int> best[2]={{-1<<30,0},{-1<<30,0}};
	int x,y;
	for(x=X1;x<=X2;x++) {
		int s=x+Y1;
		int id=s%2;
		up(best[id],{D[Y1-X1+(x-X1)],1});
		if(x!=X1) up(best[id],{D[Y1-X1-(x-X1)],1});
		up(v,{best[id].first+S[s],best[id].second});
	}
	
	best[0]=best[1]={-1<<30,0};
	for(x=X2;x>X1;x--) {
		int s=x+Y2;
		int id=s%2;
		up(best[id],{D[Y2-X2+(X2-x)],1});
		if(x!=X2) up(best[id],{D[Y2-X2-(X2-x)],1});
		up(v,{best[id].first+S[s],best[id].second});
	}
	
	return v;
}


void solve() {
	int i,j,k,l,r,x,y,a,b; string s;
	
	cin>>N>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y>>r;
			for(i=x;i<=y;i++) S[i]+=r;
		}
		else if(i==2) {
			cin>>x>>y>>r;
			for(i=x;i<=y;i++) D[i]+=r;
		}
		else {
			
			int X1,X2,Y1,Y2;
			cin>>Y1>>Y2>>X1>>X2;
			
			pair<int,int> v={-1<<30,0};
			while((Y2-Y1+1)*(X2-X1+1)) {
				if(Y2-Y1>=X2-X1) {
					up(v,rect(X1,X2,Y1,Y1+(X2-X1)));
					Y1+=X2-X1+1;
				}
				else {
					up(v,rect(X1,X1+(Y2-Y1),Y1,Y2));
					X1+=Y2-Y1+1;
				}
			}
			cout<<v.first<<" "<<v.second<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}

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

template<class V,int NV> class SegTree_max {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_max(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

template<class V,int NV> class SegTree_min {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_min(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_min<int,1<<20> SR,SD;
SegTree_max<int,1<<20> SL,ST;

int H,W,N,OH,OW;
int X[101010],Y[101010],L[101010];
vector<int> Xs,Ys;

int DL[101010];
int DR[101010];
int DT[101010];
int DD[101010];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	Xs.push_back(0);
	Xs.push_back(W+1);
	Ys.push_back(0);
	Ys.push_back(H+1);
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>L[i];
		if(X[i]==0 || X[i]==W+1) Ys.push_back(Y[i]);
		else Xs.push_back(X[i]);
	}
	sort(ALL(Xs));
	sort(ALL(Ys));
	Xs.erase(unique(ALL(Xs)),Xs.end());
	Ys.erase(unique(ALL(Ys)),Ys.end());
	OW=W;
	OH=H;
	W=Xs.size();
	H=Ys.size();
	FOR(i,H) SR.update(i,DR[i]=OW+1);
	FOR(i,W) SD.update(i,DD[i]=OH+1);
	FOR(i,N) {
		if(X[i]==0 || X[i]==OW+1) {
			y=lower_bound(ALL(Ys),Y[i])-Ys.begin();
			if(X[i]==0) {
				int xt=W-1,xd=W-1;
				
				for(j=20;j>=0;j--) {
					if(ST.getval(0,xt-(1<<j)+1)>=Y[i]) xt-=1<<j;
					if(SD.getval(0,xd-(1<<j)+1)<=Y[i]) xd-=1<<j;
				}
				DL[y]+=L[i];
				if(min({Xs[xt],Xs[xd],DR[y]})<=DL[y]) {
					DL[y]=0;
					if(Xs[xt]<Xs[xd]&&Xs[xt]<DR[y]) ST.update(xt,DT[xt]=0);
					if(Xs[xd]<Xs[xt]&&Xs[xd]<DR[y]) SD.update(xd,DD[xd]=OH+1);
					if(DR[y]<Xs[xt]&&DR[y]<Xs[xd]) SR.update(y,DR[y]=OW+1);
				}
				SL.update(y,DL[y]);
			}
			else {
				int xt=0,xd=0;
				for(j=20;j>=0;j--) {
					if(xt+(1<<j)<W&&ST.getval(xt+(1<<j),W)>=Y[i]) xt+=1<<j;
					if(xd+(1<<j)<W&&SD.getval(xd+(1<<j),W)<=Y[i]) xd+=1<<j;
				}
				DR[y]-=L[i];
				if(max({Xs[xt],Xs[xd],DL[y]})>=DR[y]) {
					DR[y]=OW+1;
					if(Xs[xt]>Xs[xd]&&Xs[xt]>DL[y]) ST.update(xt,DT[xt]=0);
					if(Xs[xd]>Xs[xt]&&Xs[xd]>DL[y]) SD.update(xd,DD[xd]=OH+1);
					if(DL[y]>Xs[xt]&&DL[y]>Xs[xd]) SL.update(y,DL[y]=0);
				}
				SR.update(y,DR[y]);
			}
		}
		else {
			x=lower_bound(ALL(Xs),X[i])-Xs.begin();

			if(Y[i]==0) {
				int yl=H-1,yr=H-1;
				
				
				for(j=20;j>=0;j--) {
					if(SL.getval(0,yl-(1<<j)+1)>=X[i]) yl-=1<<j;
					if(SR.getval(0,yr-(1<<j)+1)<=X[i]) yr-=1<<j;
				}
				DT[x]+=L[i];
				if(min({Ys[yl],Ys[yr],DD[x]})<=DT[x]) {
				
					DT[x]=0;
					if(Ys[yl]<Ys[yr]&&Ys[yl]<DD[x]) SL.update(yl,DL[yl]=0);
					if(Ys[yr]<Ys[yl]&&Ys[yr]<DD[x]) SR.update(yr,DR[yr]=OW+1);
					if(DD[x]<Ys[yl]&&DD[x]<Ys[yr]) SD.update(x,DD[x]=OH+1);
				}
				ST.update(x,DT[x]);
			}
			else {
				int yl=0,yr=0;
				
				for(j=20;j>=0;j--) {
					if(yl+(1<<j)<H&&SL.getval(yl+(1<<j),H)>=X[i]) yl+=1<<j;
					if(yr+(1<<j)<H&&SR.getval(yr+(1<<j),H)<=X[i]) yr+=1<<j;
				}
				DD[x]-=L[i];
				if(max({Ys[yl],Ys[yr],DT[x]})>=DD[x]) {
					DD[x]=OH+1;
					if(Ys[yl]>Ys[yr]&&Ys[yl]>DT[x]) SL.update(yl,DL[yl]=0);
					if(Ys[yr]>Ys[yl]&&Ys[yr]>DT[x]) SR.update(yr,DR[yr]=OW+1);
					if(DT[x]>Ys[yl]&&DT[x]>Ys[yr]) ST.update(x,DT[x]=0);
				}
				SD.update(x,DD[x]);
			}
		}
		/*
		for(x=1;x<=W-2;x++) cout<<"#"<<Xs[x]<<" "<<DT[x]<<" "<<DD[x]<<endl;
		for(x=1;x<=H-2;x++) cout<<"!"<<Ys[x]<<" "<<DL[x]<<" "<<DR[x]<<endl;
		cout<<"!-------"<<endl;
		*/
	}
	ll ret=0;
	for(i=1;i<=W-2;i++) {
		//cout<<"#"<<Xs[i]<<" "<<DT[i]<<" "<<DD[i]<<endl;
		ret+=DT[i]+OH+1-DD[i];
	}
	for(i=1;i<=H-2;i++) {
		//cout<<"!"<<Ys[i]<<" "<<DL[i]<<" "<<DR[i]<<endl;
		ret+=DL[i]+OW+1-DR[i];
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

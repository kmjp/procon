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


#include "meetings.h"

vector<int> E[2020];
int vis[2020];
int target[2020];
int C[2020];
map<vector<int>,int> M;

int ask(int a,int b,int c) {
	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);
	if(M.count({a,b,c})==0) {
		//cout<<"!"<<a<<b<<c<<" ";
		M[{a,b,c}]=Query(a,b,c);
		//cout<<M[{a,b,c}]<<endl;
	}
	return M[{a,b,c}];
	
}

void add(int a,int b) {
	if(a==b) return;
	//cout<<"add"<<a<<b<<endl;
	E[a].push_back(b);
	E[b].push_back(a);
}
void del(int a,int b) {
	if(a==b) return;
	//cout<<"del"<<a<<b<<endl;
	E[a].erase(find(ALL(E[a]),b));
	E[b].erase(find(ALL(E[b]),a));
}

int countc(int cur,int pre) {
	//cout<<"!cc"<<cur<<" "<<pre<<endl;
	if(target[cur]==0) return C[cur]=0;
	C[cur]=1;
	FORR(e,E[cur]) if(e!=pre) C[cur]+=countc(e,cur);
	return C[cur];
}

pair<int,int> dfs_center(int cur,int pre,int sum) {
	pair<int,int> res=make_pair(1<<30,-1);
	int ma=0;
	C[cur]=1;
	
	FORR(r,E[cur]) if(r!=pre && target[r]) {
		res=min(res,dfs_center(r,cur,sum));
		ma=max(ma,C[r]);
		C[cur]+=C[r];
	}
	return min(res,make_pair(max(ma,sum-C[cur]),cur));
}


void hoge(int root,int tar) {
	//cout<<"!!"<<root<<endl;
	int num=countc(root,-1);
	//cout<<"!!"<<root<<num<<endl;
	if(num==1) {
		add(root,tar);
		return;
	}
	if(num==2) {
		int nei;
		FORR(e,E[root]) if(target[e]) nei=e;
		int r=ask(root,nei,tar);
		
		if(root==r) {
			add(root,tar);
			vis[tar]=1;
		}
		else if(nei==r) {
			add(nei,tar);
			vis[tar]=1;
		}
		else {
			del(root,nei);
			add(root,r);
			add(nei,r);
			add(tar,r);
			vis[tar]=1;
			vis[r]=1;
		}
		return;
	}
	
	auto p=dfs_center(root,-1,num);
	root=p.second;
	//cout<<"nc "<<root<<endl;
	countc(root,-1);
	vector<pair<int,int>> cand;
	FORR(e,E[root]) if(target[e]) cand.push_back({C[e],e});
	sort(ALL(cand));
	reverse(ALL(cand));
	//cout<<"cand ";
	//FORR(c,cand) cout<<c.first<<":"<<c.second<<" ";
	//cout<<endl;
	int i;
	for(i=0;i<cand.size();i+=2) {
		if(i+1>=cand.size()) {
			hoge(cand[i].second,tar);
			return;
		}
		int a=cand[i].second;
		int b=cand[i+1].second;
		int r=ask(a,b,tar);
		
		if(a==r) {
			target[root]=0;
			hoge(a,tar);
			return;
		}
		else if(b==r) {
			target[root]=0;
			hoge(b,tar);
			return;
		}
		else if(r==root) {
			target[a]=0;
			target[b]=0;
			continue;
		}
		else {
			int x=ask(a,root,r);
			if(x==root) x=b;
			else x=a;
			
			del(x,root);
			add(root,r);
			add(x,r);
			add(tar,r);
			vis[tar]=vis[r]=1;
			return;
		}
	}
	//cout<<"new "<<root<<tar<<endl;
	add(root,tar);
	return;
}


void Solve(int N) {
	int i,x;
	
	vis[0]=vis[1]=1;
	add(0,1);
	
	for(i=2;i<N;i++) if(vis[i]==0) {
		//cout<<"go "<<i<<endl;
		FOR(x,N) target[x]=1;
		hoge(0,i);
	}
	
	FOR(i,N) FORR(e,E[i]) if(i<e) {
		//cout<<"bridge "<<i<<" "<<e<<endl;
		Bridge(i,e);
	}
	
}




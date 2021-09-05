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


class LockingTree {
public:
vector<int> E[2020];
int P[2020];

map<int,int> LO;
int L[2020],R[2020];
int id;

	void dfs(int cur) {
		L[cur]=id++;
		FORR(e,E[cur]) dfs(e);
		R[cur]=id;
	}
    LockingTree(vector<int>& parent) {
        int N=parent.size();
        int i;
        FOR(i,N) E[i].clear();
        FOR(i,N) {
			P[i]=parent[i];
			if(i) E[P[i]].push_back(i);
		}
		id=0;
		dfs(0);
		LO.clear();
    }
    
    bool lock(int num, int user) {
        if(LO.count(L[num])) {
			return 0;
		}
		else {
			LO[L[num]]=user;
			return 1;
		}
    }
    
    bool unlock(int num, int user) {
        if(LO.count(L[num])==0) {
			return 0;
		}
		else if(LO[L[num]]==user) {
			LO.erase(L[num]);
			return 1;
		}
		else {
			return 0;
		}
    }
    
    bool upgrade(int num, int user) {
		int cur=num;
		while(1) {
			if(LO.count(L[cur])) return 0;
			if(cur==0) break;
			cur=P[cur];
		}
		
        if(LO.count(L[num])) {
			return 0;
		}
		int ret=0;
		while(1) {
			auto it=LO.lower_bound(L[num]);
			if(it==LO.end()) break;
			if(it->first>=R[num]) break;
			ret++;
			LO.erase(it);
		}
		if(ret) {
			LO[L[num]]=user;
			return 1;
		}
		return 0;
        
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
 
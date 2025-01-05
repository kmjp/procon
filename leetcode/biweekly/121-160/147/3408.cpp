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

class TaskManager {
public:
	map<pair<int,int>,int> T;
	map<int,int> P;
    TaskManager(vector<vector<int>>& tasks) {
        T.clear();
        P.clear();
        FORR(t,tasks) {
			T[{t[2],t[1]}]=t[0];
			P[t[1]]=t[2];
		}
    }
    
    void add(int userId, int taskId, int priority) {
        T[{priority,taskId}]=userId;
        P[taskId]=priority;
    }
    
    void edit(int taskId, int newPriority) {
        int op=P[taskId];
        if(op!=newPriority) {
			P[taskId]=newPriority;
	        T[{newPriority,taskId}]=T[{op,taskId}];
	        T.erase({op,taskId});
	    }
    }
    
    void rmv(int taskId) {
        if(P.count(taskId)) {
			int op=P[taskId];
			P.erase(taskId);
			T.erase({op,taskId});
		}
    }
    
    int execTop() {
		int ret=-1;
		if(T.size()) {
			auto p=T.rbegin()->first;
			ret=T.rbegin()->second;
			T.erase(p);
			P.erase(p.second);
		}
		return ret;
	
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
 
 
 
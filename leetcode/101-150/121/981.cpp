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


class TimeMap {
public:
	map<string,vector<pair<int,string>> > M;
    /** Initialize your data structure here. */
    TimeMap() {
        M.clear();
    }
    
    void set(string key, string value, int timestamp) {
        M[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
		pair<int,string> a = {timestamp+1,string("")};
        auto it=lower_bound(M[key].begin(),M[key].end(),a);
        if(it==M[key].begin()) return "";
        it--;
        return it->second;
    }
};

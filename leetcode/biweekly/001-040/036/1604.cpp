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




class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
		map<string,vector<int>> V;
		int i;
		FOR(i,keyName.size()) {
			int tim=((keyTime[i][0]-'1')*10+(keyTime[i][1]-'1')*1)*60+((keyTime[i][3]-'1')*10+(keyTime[i][4]-'1')*1);
			V[keyName[i]].push_back(tim);
		}
		
		vector<string> ret;
		FORR(a,V) {
			int ng=0;
			int i;
			vector<int> B=a.second;
			sort(ALL(B));
			
			for(i=0;i+2<B.size();i++) if(B[i+2]-B[i]<=60) ng=1;
			if(ng) ret.push_back(a.first);
			
			
		}
		return ret;
        
    }
};


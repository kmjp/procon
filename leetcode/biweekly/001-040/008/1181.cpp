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


vector<string> split(const string &str, char delim=' '){
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
		vector<vector<string>> S;
		vector<string> R;
		FORR(p,phrases) S.push_back(split(p));
		int i,j;
		FOR(i,S.size()) FOR(j,S.size()) if(i!=j && S[i].back()==S[j][0]) {
			string T="";
			int x;
			FOR(x,S[i].size()) {
				if(x) T+=" ";
				T+=S[i][x];
			}
			FOR(x,S[j].size()) {
				if(x) T+=" "+S[j][x];
			}
			R.push_back(T);
		}
		sort(ALL(R));
		R.erase(unique(ALL(R)),R.end());
		return R;
		
        
    }
};


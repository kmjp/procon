
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

vector<string> split(const string &str, char delim=','){
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

    vector<string> invalidTransactions(vector<string>& transactions) {
		vector<vector<string>> V;
        FORR(v,transactions) {
			V.push_back(split(v));
		}
		vector<string> R;
		int x,y;
		FOR(x,V.size()) {
			int valid=1;
			int tim=atoi(V[x][1].c_str());
			int val=atoi(V[x][2].c_str());
			if(val>1000) valid=0;
			FOR(y,V.size()) if(x!=y) {
				int tim2=atoi(V[y][1].c_str());
				if(V[x][0]==V[y][0] && V[x][3]!=V[y][3] && abs(tim-tim2)<=60) valid=0;
			}
			if(valid==0) R.push_back(transactions[x]);
		}
		return R;
    }
};


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> m;
        for(int i=0;i<equations.size();i++){
            auto p=equations[i];
            double val=values[i];
            string from=p[0],to=p[1];
            m[from][to]=val;
            m[to][from]=1/val;
            m[from][from]=1.00;
        }
        for(auto &k:m){
            for(auto &i:m[k.first]){
                for(auto &j:m[k.first]){
                    m[i.first][j.first]=m[i.first][k.first]*m[k.first][j.first];
                }
            }
        }
        vector<double> res;
        for(auto x:queries){
            string from=x[0],to=x[1];
            if(m.find(from)!=m.end() && m[from].find(to)!=m[from].end()){
                res.push_back(m[from][to]);
            }else{
                res.push_back(-1.0);
            }
        }
        return res;
    }
};
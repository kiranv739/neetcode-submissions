class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        stack<double> s;
        int n = speed.size();

        map<int,double,greater<int>> m;
        for(int i=0;i<n;i++){
            m[pos[i]] = (double)(target - pos[i])/ speed[i];
        }

        for(auto car: m){
           if(s.empty() || car.second>s.top()) s.push(car.second);
        }
    return s.size();
    }
};

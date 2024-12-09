#include <bits/stdc++.h>

std::ifstream fin("in.txt");
 //Modified with added 0 to the end of each row (i don't now how to separete input)
#define all(a) a.begin(),a.end()

//bool Good(std::vector<int> &v){
//    bool flag = v[0] < v[1];
//    for (int i = 0; i < (int)v.size()-1; ++i){
//        if (flag && (v[i+1] - v[i] > 3 || v[i+1] - v[i] < 1))return false;
//        if(!flag && (v[i] - v[i+1] > 3 || v[i] - v[i+1] < 1))return false;
//    }
//    return true;
//}
//void part1(){
//    int a, t = 1;
//    std::vector<int> n;
//    bool flag, demp;
//    uint64_t ans {};
//    while(fin >> a){
//        if (a == 0){
//            flag = n[0] < n[1];
//            for(int i = 0; i < (int)n.size()-1; ++i){
//                
//                if (flag && (n[i+1] - n[i] > 3 || n[i+1] - n[i] < 1)){
//                    if(demp && (n[i+2] - n[i] < 3 && n[i+2] - n[i] > 1)){
//                        demp = false;
//                        continue;
//                    }
//                    else if(demp && i == (int)n.size()-2)continue;
//                    else{
//                        t = 0;
//                        break;
//                    }
//                }
//                else if(!flag && (n[i] - n[i+1] > 3 || n[i] - n[i+1] < 1)){
//                    if(demp && (n[i] - n[i+2] < 3 && n[i] - n[i+2] > 1)){
//                        demp = false;
//                        continue;
//                    }
//                    else if(demp && i == (int)n.size()-2)continue;
//                    else{
//                        t = 0;
//                        break;
//                    }
//                }
//            }
//            ans += t;
//            t = 1;
//            n.clear();
//            demp = true;
//        }
//        else{
//            n.push_back(a);
//        }
//    }
//    std::cout << ans;
//
//
//
//}
//
//void part2(){
//    int a;
//    uint64_t ans{};
//    std::vector<int> v;
//    bool good;
//    while(fin >> a){
//        v.push_back(a);
//        while(fin >> a && a!=0){
//            v.push_back(a);
//        }
//        good = Good(v);
//        if(!good){
//            for (int i = 0; i < (int) v.size(); ++i){
//                std::vector<int> temp = v;
//                temp.erase(temp.begin()+i);
//                good = good || Good(temp);
//            }
//        }
//        if(good) ans++;
//        v.clear();
//    }
//    std::cout << ans;
//        
//
//
//}

//nevermind, i think i can now

void part1(){ // modified to be part 2 :(
    std::string s;
    int ans = 0;
    while(std::getline(fin,s)){
        std::istringstream is(s);
        std::vector<int> v;
        for(int x; is >> x;){
            v.push_back(x);
        }
        std::vector<int>  diff;
        int sumAbs = 0;
        int mx = 0, mn = 4;
        for(int i = 1; i < (int)v.size(); ++i)diff.push_back(v[i] - v[i-1]);
        for(auto i : v){
            sumAbs += abs(i);
            mx = std::max(mx, i);
            mn = std::min(mn, i);
        }

        bool ok = abs(std::accumulate(all(diff),0)) == sumAbs;
        ok &= mx <= 3 && mn >= 1;
        ans += ok;
    }
    std::cout << ans;
}



int main(){
    part1();

}
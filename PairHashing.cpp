#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
          return hash1;
    }
};
 
int main()
{
    unordered_map<pair<int, int>, bool, hash_pair> um;
    
    pair<int, int> p1(1000, 2000);
    pair<int, int> p2(2000, 3000);
    pair<int, int> p3(3005, 3005);
    pair<int, int> p4(4000, 4000);

    um[p1] = true;
    um[p2] = false;
    um[p3] = true;
    um[p4] = false;
 
    cout << "Contents of the unordered_map : \n";
    for (auto p : um)
        cout << "[" << (p.first).first << ", "
             << (p.first).second << "] ==> " << p.second
             << "\n";
 
    return 0;
}

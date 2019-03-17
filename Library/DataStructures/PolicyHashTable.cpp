#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return hash<int>{}(x ^ RANDOM); }
};
gp_hash_table<key, int, chash> table;

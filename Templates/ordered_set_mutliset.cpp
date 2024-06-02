#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// remove #define int long long

//Ordered_Set
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// os.insert(element),os.erase(element),os.find_by_order(k) {iterator to the k'th element 0 indexing},os.order_of_key(k) {count of elements smaller than k}; 
template<class T>using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
//erase x in multiset a -> a.erase(a.find_by_order(a.order_of_key(x)))
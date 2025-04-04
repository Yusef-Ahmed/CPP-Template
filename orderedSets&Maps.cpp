#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;

// ordered map
template<typename K, typename V, typename Comp = std::less<K>>
using ordered_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

// ordered set
template<typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, null_type, Comp>;

// ordered multimap
template<typename K, typename V, typename Comp = std::less_equal<K>>
using ordered_multimap = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

// ordered multiset
template<typename K, typename Comp = std::less_equal<K>>
using ordered_multiset = ordered_multimap<K, null_type, Comp>;

/// order_of_key(key): Returns the number of elements in the set strictly less than key.
/// find_by_order(k): Returns an iterator to the k-th element in the set (0-based index).
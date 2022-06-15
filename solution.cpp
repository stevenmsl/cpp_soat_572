#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace sol572;
using namespace std;

/*takeaways
  - pay attention to the edge cases
  - pay attention to the subtle difference in
    implementation between isSubtree and _isSameTree
    for the edge cases
  - Time complexity: O(max(n, m))
*/

bool Solution::isSubtree(Node *s, Node *t)
{
  /* an empty tree is a subtree of any tree including
     an empty tree
  */
  if (t == nullptr)
    return true;

  /* we have exhausted s  */
  if (s == nullptr)
    return false;

  /* if s->val == t->val we will recursively
     check if two trees are the same
  */
  if (_isSameTree(s, t))
    return true;
  /* check either child to see if t is a subtree of
   */
  else
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

bool Solution::_isSameTree(Node *s, Node *t)
{
  if (s == nullptr && t == nullptr)
    return true;
  if (s == nullptr || t == nullptr)
    return false;

  if (s->val != t->val)
    return false;

  return _isSameTree(s->left, t->left) && _isSameTree(s->right, t->right);
}
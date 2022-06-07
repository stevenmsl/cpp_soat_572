
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol572
{

  class Solution
  {
  private:
    bool _isSameTree(Node *s, Node *t);

  public:
    bool isSubtree(Node *s, Node *t);
  };

}
#endif
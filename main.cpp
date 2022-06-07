#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol572;

/*
s:
     3
    / \
   4   5
  / \
 1   2

t:
   4
  / \
 1   2

*/

tuple<Node *, Node *, bool>
testFixture1()
{
  auto s = new Node(3);
  s->left = new Node(4);
  s->left->left = new Node(1);
  s->left->right = new Node(2);
  s->right = new Node(5);

  auto t = new Node(4);
  t->left = new Node(1);
  t->right = new Node(2);

  return make_tuple(s, t, true);
}

/*
s:
     3
    / \
   4   5
  / \
 1   2
    /
   0
t:
   4
  / \
 1   2


*/

tuple<Node *, Node *, bool>
testFixture2()
{
  auto s = new Node(3);
  s->left = new Node(4);
  s->left->left = new Node(1);
  s->left->right = new Node(2);
  s->left->right->left = new Node(0);
  s->right = new Node(5);

  auto t = new Node(4);
  t->left = new Node(1);
  t->right = new Node(2);

  return make_tuple(s, t, false);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see : " << get<2>(f) << endl;
  cout << sol.isSubtree(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;

  cout << "Expect to see : " << get<2>(f) << endl;
  cout << sol.isSubtree(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  // testistringStream();
  return 0;
}
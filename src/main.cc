#include <iostream>

#include "ab_pruning/ab_node.h"

// NODE creates a non-terminal node
#define NODE(name) ABNode name(#name)
// TNODE creates a terminal node
#define TNODE(name, value) ABNode name(#name, true, value)
// RELATE relates two nodes
#define RELATE(node, child_node) node.add_child(child_node)

int
main(int argc, char** argv)
{
  // First we'll build the tree
  // define all the E nodes first
  TNODE(e0, 3);
  TNODE(e1, -2);
  TNODE(e2, 1);
  TNODE(e3, -6);
  TNODE(e4, 1);
  TNODE(e5, -5);
  TNODE(e6, 4);
  TNODE(e7, 2);
  TNODE(e8, 0);
  TNODE(e9, 7);
  TNODE(e10, 2);
  TNODE(e11, 3);
  TNODE(e12, 6);
  TNODE(e13, 1);
  TNODE(e14, 2);

  // Now the D nodes
  NODE(d0);
  RELATE(d0, e0);
  RELATE(d0, e1);
  RELATE(d0, e2);

  NODE(d1);
  RELATE(d1, e3);

  NODE(d2);
  RELATE(d2, e4);
  RELATE(d2, e5);

  NODE(d3);
  RELATE(d3, e6);

  NODE(d4);
  RELATE(d4, e7);
  RELATE(d4, e8);

  NODE(d5);
  RELATE(d5, e9);
  RELATE(d5, e10);

  TNODE(d6, -3);

  NODE(d7);
  RELATE(d7, e11);

  NODE(d8);
  RELATE(d8, e12);
  RELATE(d8, e13);
  RELATE(d8, e14);

  TNODE(d9, 8);

  // now C
  NODE(c0);
  RELATE(c0, d0);
  RELATE(c0, d1);
  RELATE(c0, d2);

  TNODE(c1, 5);

  NODE(c2);
  RELATE(c2, d3);
  RELATE(c2, d4);

  NODE(c3);
  RELATE(c3, d5);
  RELATE(c3, d6);

  NODE(c4);
  RELATE(c4, d7);
  RELATE(c4, d8);
  RELATE(c4, d9);

  // now B
  NODE(b0);
  RELATE(b0, c0);
  RELATE(b0, c1);
  RELATE(b0, c2);

  NODE(b1);
  RELATE(b1, c3);
  RELATE(b1, c4);

  // and now (finally) A
  NODE(a0);
  RELATE(a0, b0);
  RELATE(a0, b1);

  // awesome! now we just need to eval a0
  // it should trace all the steps correctly, so now just
  // let it go!
  a0.make_max_min();
  int aval = a0.eval();

  std::cout << "Expansions completed" << std::endl;
  std::cout << "Value of Max Node A = " << aval << std::endl;
}

#ifndef AB_NODE_H__
#define AN_NODE_H__

#include <vector>
#include <string>

class ABNode
{
private:
  std::string m_name;
  bool m_is_terminal;
  int m_terminal_value;
  std::vector<ABNode> m_children;
  bool m_is_max_node;
public:
  ABNode();

  ABNode(std::string name, bool is_terminal=false, int terminal_value=0);

  std::string
  name() const;

  bool
  is_terminal() const;

  int
  terminal_value() const;

  void
  add_child(ABNode &n);

  bool
  is_max_node();

  int
  eval();
};

#endif

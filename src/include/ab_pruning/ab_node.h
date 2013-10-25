#ifndef AB_NODE_H__
#define AN_NODE_H__

#include <vector>
#include <string>

class ABNode
{
private:
  std::string m_name;
  bool m_terminal;
  int m_terminal_value;
  std::vector<ABNode> m_children;
public:
  ABNode();
  
  ABNode(std::string name, bool terminal=false, int terminal_value=0);

  std::string
  name() const;

  bool
  terminal() const;

  int
  terminal_value() const;

  void
  add_child(ABNode &n);

  int
  eval();
};

#endif

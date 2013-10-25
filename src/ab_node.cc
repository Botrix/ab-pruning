#include "ab_pruning/ab_node.h"

ABNode::ABNode()
{
  // empty
}

ABNode::ABNode(std::string name, bool terminal, int terminal_value) :
  m_name(name),
  m_terminal(terminal),
  m_terminal_value(terminal_value)
{
  // empty
}

std::string
ABNode::name() const
{
  return m_name;
}

bool
ABNode::terminal() const
{
  return m_terminal;
}

int
ABNode::terminal_value() const
{
  return m_terminal_value;
}

void
ABNode::add_child(ABNode &n)
{
  m_children.push_back(n);
}


#include "ab_pruning/ab_node.h"

ABNode::ABNode() :
  m_is_max_node(true)
{
  // empty
}

ABNode::ABNode(std::string name, bool is_terminal, int terminal_value) :
  m_name(name),
  m_is_terminal(is_terminal),
  m_terminal_value(terminal_value),
  m_is_max_node(true)
{
  // empty
}

std::string
ABNode::name() const
{
  return m_name;
}

bool
ABNode::is_terminal() const
{
  return m_is_terminal;
}

int
ABNode::terminal_value() const
{
  return m_terminal_value;
}

void
ABNode::add_child(ABNode &n)
{
  // put it onto our children list
  m_children.push_back(n);

  // mark it as being an oppisite node from ours
  // since we start with max nodes this will result
  // in a tree that goes max, min, max, min, etc
  n.m_is_max_node = !m_is_max_node;
}

bool
ABNode::is_max_node()
{
  return m_is_max_node;
}

int
ABNode::eval()
{
  // if it's terminal just return its value!
  if (m_is_terminal) {
    return m_terminal_value;
  }
}

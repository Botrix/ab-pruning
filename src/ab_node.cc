#include "ab_pruning/ab_node.h"

#include <iostream>

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
}

bool
ABNode::is_max_node()
{
  return m_is_max_node;
}

void
ABNode::is_max_node(bool val)
{
  m_is_max_node = val;
}

void
ABNode::make_max_min(bool max)
{
  m_is_max_node = max;
  for (int i = 0; i < m_children.size(); i++) {
    m_children[i].make_max_min(!max);
  }
}

eval_res_t
ABNode::eval(int alpha, int beta)
{
  eval_res_t out;

  if (m_is_terminal) {
    std::cout << "Expanding Terminal Node " << m_name << ": " << m_terminal_value << std::endl;
    out.val = m_terminal_value;
    out.node = this;
    return out;
  }

  if (m_is_max_node) {
    out.val = alpha;
    std::cout << "Expanding Max Node " << m_name << ": alpha=" << alpha << " beta=" << beta << std::endl;
    for (int i = 0; i < m_children.size(); i++) {
      eval_res_t val = m_children[i].eval(alpha, beta);
      if (val.val > alpha) {
        alpha = val.val;
        out.val = val.val;
        out.node = &m_children[i];
      }
      if (beta <= alpha) {
        for (int j = i + 1; j < m_children.size(); j++) {
          std::cout << "Skipping expansion of Node " << m_children[j].m_name << " because it cannot make alpha higher" << std::endl;
        }
        break;
      }
    }
    return out;
  } else {
    out.val = beta;
    std::cout << "Expanding Min Node " << m_name << ": alpha=" << alpha << " beta=" << beta << std::endl;
    for (int i = 0; i < m_children.size(); i++) {
      eval_res_t val = m_children[i].eval(alpha, beta);
      if (val.val < beta) {
        beta = val.val;
        out.val = val.val;
        out.node = &m_children[i];
      }
      if (beta <= alpha) {
        for (int j = i + 1; j < m_children.size(); j++) {
          std::cout << "Skipping expansion of Node " << m_children[j].m_name << " because it cannot make beta lower" << std::endl;
        }
        break;
      }
    }
    return out;
  }
}

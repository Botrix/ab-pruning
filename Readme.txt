Michael Gerow
6804481189
gerow@usc.edu

== Program Description:
The implementation should be pretty straightforward.  The entry point is in src/main.cc.  In there we use the ABNode class, which is defined in src/include/ab_node.h and src/ab_node.cc. I use some macros to build the tree without too much verbosity, but hopefully they're easy enough to follow.  All of the alpha beta pruning magic happens in ABNode::eval in src/ab_node.cc.

The assignment didn't mention anything specific about what kind of information we should print about terminal nodes, so I've gone ahead and had them be a special case where we print 'Expanding Terminal Node' followed by the value of that node.

== Build Instructions:
Make sure you are using bash when you build, otherwise the script that adds the necessary binaries to the path will fail.  You can do with just by typing 'bash' in the terminal.

Once in bash, you need to source setup.sh, which should be as easy as running 'source ./setup.sh' from within the project directory.

After that, all you need to do is run 'make' to build the program, and then run './build/src/main' to run it.

== Questions Answered:
1. We could use these searches to create nice heuristics to guide which nodes on the tree we try to expand first. Optimally, we want to expand the "best" nodes for any given node first so that we are more likely to prune the rest, so if we have some information about what positions are likely better than others we can be more careful about which nodes we decide to fully expand first.  So we sould likely reorder the tree to take advantage of these results.

2. We can get a good estimation of this by using the average running time of regular minimax and minimax with alpha beta pruning.

Branching factor: b
Depth: d

Minimax w/o alpha beta pruning: O(b^d)
Minimax with alpha beta pruning: O(b^(d/2))

This effectively means that if we use alpha beta pruning we can go to twice the depth that we were able to go to using only minimax without alpha beta pruning.

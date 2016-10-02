#carlnet

*carlnet* offers a set of tools for studying the behavior of complex systems on
self-modifying networks. That is to say, it facilitates investigations of
groups of agents (automata governed by simple behavioral rules) acting on a
network whose connections they themselves can modify.

As a concrete example, consider a social network in which, whenever an
individual has more than a certain threshold of money, that individual gives a
certain amount to each of its "friends" (agents to which it is connected). On a
stable network, this system could be modeled by the well-known [Abelian
sandpile model](https://en.wikipedia.org/wiki/Abelian_sandpile_model
"Wikipedia") or a trivial variation thereof. But consider a modification of
this system in which individuals will "break off" a friendship if they haven't
received anything from a friend in a certain period of time and start up a
friendship with someone else. How would the network evolve with these "greedy"
agents in the mix? In order to investigate such questions, *carlnet* offers
efficient tools to model agents with control over the connections in the
network.

*carlnet* can also model complex systems on static networks (the Abelian
sandpile model can easily be implemented on an arbitrary static network with
*carlnet*), but it is designed to minimize performance penalties for highly
dynamic networks.

## Building carlnet

Right now, *carlnet* can be built using the provided Makefile. A CmakeLists.txt
is also available but is currently out of date. Eventually, I plan to move the
build system over entirely to cmake.

## Development status

*carlnet* is still very much in development, and it is being developed as a
hobbyist project. Tagged releases will be provided as the project builds up a
useful feature set. Future features will include some (hopefully non-empty)
subset of the following:

- A collection of example simulations
- MPI-based parallelization with efficient load-rebalancing based on current
    network structure
- Integrated visualization tools
- Integrated tools for analyzing simulation results

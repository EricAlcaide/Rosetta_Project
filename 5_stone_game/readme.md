# Stone Game

### The Problem

Two players (numbered 1 and 2) are playing a game with ```n``` stones. Player 1 always plays first, and the two players move in alternating turns. The game's rules are as follows:

* In a single move, a player can remove either 2, 3, or 5 stones from the game board.

* If a player is unable to make a move, that player loses the game.

Given the number of stones, find and print the name of the winner (i.e.,  or ) on a new line. Each player plays optimally, meaning they will not make a move that causes them to lose the game if some better, winning move exists.

#### Additional Info

If ```n = 10``` , **P1** can remove either 2 or 3 stones to win the game, so we print ```First``` on a new line. Recall that each player moves optimally, so **P1** will not remove 5 stones because doing so would cause **P1** to lose the game.

### Desired Output / Test Cases

* **Input:** List containing test cases: [1,2,3,4,5,6,7,10]
* **Output:**

1:  Second
2:  First
3:  First
4:  First
5:  First
6:  First
7:  Second
10: First

### Theory
The goal of this code snippet is to provide an easy implementation of the Minimax algorithm, widely used in games AIs. This algorithm is composed by 2 players that evaluate each node and select the best action possible for themselves.

For `n % 7` in `[0, 1]`, the first player loses, otherwise the first player wins.
Please find this [link](https://theory.stanford.edu/~trevisan/cs103-14/hw2sol.pdf) for a rigorous proof.

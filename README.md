# ultimate-tic-tac-toe
A C++ Command Line implementation of the complicated but enjoyable game of ultimate tic tac toe! I wrote this game as a personal challenge. I found this gem of a game online and thought to myself if it's this hard to play, it must be harder to implement. Turns out with some smart and clear thinking, it was no problem!

### Building the Game
To build the project, download the repository locally and simply run the command `make all` to build. This creates the command line executable called ultimate. Enter `./ultimate` to start the game. The makefile uses the GCC compiler. 

The `SingleBoard` and `MultiBoard` classes contain the model and logic of the game. The `SingleBoard` class can also be used to play regular tic tac toe. `MultiBoard` uses a 3x3 matrix of `Singleboard` to implement the game.  

### Playing the Game
The way to play the game is explained [here](https://mathwithbaddrawings.com/ultimate-tic-tac-toe-original-post/).

In the command line version, each player is asked to input their row and column for their chance. If the player has a choice of selection which mini board to play on, that is selected by entering row and column of the board. In both cases, the rows and columns start at 1. The mega board is shown after every turn.

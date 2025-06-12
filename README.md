# TicTacToe
A simple Tic-Tac-Toe made in C++

This C++ program is a fully functional Tic Tac Toe game for two players played on a 3×3 grid. The game is developed using a procedural programming style and demonstrates fundamental concepts such as loops, conditionals, functions, arrays, and user input validation.

🔧 Features:

    Interactive Console Interface
    Players are prompted to enter the row and column for their move, with validation for invalid inputs.

    Clear Game State Display
    A stylized board is printed after each move using the printBoard() function, helping users track the current state of the game.

    Turn-Based Logic
    Player turns alternate between 'X' and 'O' using the switchTurn() function.

    Win Condition Checks
    The game checks for a winner after each move by analyzing:

        All rows (checkRowWin)

        All columns (checkColumnsWin)

        Both diagonals (checkDiagonalWin)

    Draw Detection
    If the board is full and no player has won, a tie is declared using isBoardFull() and a tie message is shown with replay options.

    Replay Support
    After a win or tie, users can choose to replay the game or exit gracefully.

    Input Validation
    Ensures only valid moves are accepted, using getPlayerInput() and updateBoard().

📦 Modular Functionality:

Each task in the game is broken into small functions:

    initializeBoard() – sets all cells to empty.

    printBoard() – prints the game board.

    getPlayerInput() – gets and validates user input.

    updateBoard() – updates the board if the selected cell is empty.

    checkWinner() – checks all win conditions.

    displayTieMessage() – handles tie message and user choice to replay.

🧠 Educational Value:

This code is an excellent resource for:

    Learning 2D arrays and how to navigate them.

    Understanding turn-based game logic.

    Practicing input validation and user interaction.

    Seeing how functions help in modularizing and organizing code.

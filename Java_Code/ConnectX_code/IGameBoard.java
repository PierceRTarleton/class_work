package cpsc2150.connectX;

public interface IGameBoard {
    /**
     * This interface places tokens on the game board, checks whether a player has won
     * and formats the game board as a sting
     *
     * Defines: BoardSize- the number of tokens that can be placed on the board: Z
     *          Number_to_Win- the number of tokens in a line that is needed to win: Z
     *          Number_of_Rows- the number of elements that can fit in a row: Z
     *          Number_of_Columns- the number of elements that can fit in a column: Z
     *
     * Constraints: 9 <= BoardSize <= 1000
     *              2 <= Number_to_Win <= 25
     *              Number_to_Win < Number_of_Rows
     *              Number_to_Win < Number_of_Columns
     *              3 <= Number_of_Rows <= 100
     *              3 <= Number_of_Columns <= 100
     *
     * Initialization Ensures: 2 <= Number_to_Win <= 25
     *                         Number_to_Win < Number_of_Rows
     *                         Number_to_Win < Number_of_Columns
     *                         3 <= Number_of_Rows <= 100
     *                         3 <= Number_of_Columns <= 100
     */

    public static final char empty = ' ';
    public static final int DoubleDigitRows = 9;
    public static final int Halfing = 2;
    public static final int MAX_Row_Column_SIZE = 100;
    public static final int MIN_Row_Column_SIZE = 3;
    public static final int MAX_Win_SIZE = 25;
    public static final int MIN_Win_SIZE = 3;
    public static final int MIN_NumPlayers = 2;
    public static final int MAX_NumPlayers = 10;


    /**
     * @pre 0 <= c < Number_of_Columns
     *      c = [column to place the token]
     *
     * @post checkIfFree = Whether the column has empty space
     *
     * @param c: column to place the token
     * @return whether there is a free spot in the column
     */
    default public boolean checkIfFree(int c){
        return (' ' == whatsAtPos(new BoardPosition((getNumRows()-1), c)));
    }

    /**
     * @pre 0 <= c < Number_of_Rows
     *      c = [column of last placed token]
     *      [must have called placeToken]
     *
     * @post checkForWin = (whether the last token placed results in the number in a row = Number_to_Win)
     *
     * @param c: column of last placed token
     * @return whether the last token placed results in the number in a row = Number_to_Win
     */
    default public boolean checkForWin(int c){
        //algorithm to find first empty pos of column c
        int uperBound = getNumRows();
        int lowerBound = 0;
        int checkpos = getNumRows()/Halfing;

        // Loops through the column and finds the last placed token, loop while (checkpos position has a token and checkpos+1 position does not) is false
        while(!(whatsAtPos(new BoardPosition(checkpos, c)) != empty && whatsAtPos(new BoardPosition((checkpos+1), c)) == empty)){

            // If checkpos is empty then checkpos = midpoint between checkpos and the lowerBound
            if(whatsAtPos(new BoardPosition(checkpos, c)) == empty){
                uperBound = checkpos;
                checkpos = (lowerBound+uperBound)/Halfing;
            }

            // If checkpos is not empty then checkpos = midpoint between checkpos and the upperbound
            else{
                lowerBound = checkpos;
                checkpos = (lowerBound+uperBound)/Halfing;
                if(checkpos == getNumRows()-1){
                    break;
                }
            }
        }


        BoardPosition pos = new BoardPosition(checkpos, c);
        char player = whatsAtPos(pos);
        return (checkHorizWin(pos, player) || checkVertWin(pos, player) || checkDiagWin(pos, player));
    }

    /**
     * @pre 0 <= c < Number_of_Columns
     *      checkIfFree(c) = true
     *      p ≠ empty
     *
     * @post [token placed at the fist available position in the column from the bottom]
     *
     * @param p: the character to represent the player placing the token
     * @param c: the column to place the token in
     */
    public void placeToken(char p, int c);

    /**
     * @pre 0 <= pos.getRow() < Number_of_Rows
     *      0 <= pos.getColumn() < Number_of_Columns
     *      pos = [last position played]
     *
     * @post checkHorizWin = (whether the number of player tokens are in a row horizontally = Number_to_Win)
     *
     * @param pos: the BoardPosition of the last placed token
     * @param p: the token of the player that last placed the token
     * @return whether the number of player tokens are in a row horizontally = Number_to_Win
     */
    default public boolean checkHorizWin(BoardPosition pos, char p){
        int row = pos.getRow();
        int column = pos.getColumn();
        int InRow = 1;
        int Iter = column + 1;

        //gets how many tokens to the right of pos = p, before it gets a token that does not equal p
        while (Iter < getNumColumns()) {
            if(isPlayerAtPos(new BoardPosition(row, Iter), p)) {
                InRow++;
                Iter++;
            } else {
                Iter = getNumColumns();
            }
        }

        //gets how many tokens to the left of pos = p, before it gets a token that does not equal p
        Iter = column - 1;
        while (Iter >= 0){
            if(isPlayerAtPos(new BoardPosition(row, Iter), p)){
                InRow++;
                Iter--;
            } else {
                Iter = -1;
            }
        }

        //checks if there are 4 in a line
        return (InRow >= getNumToWin());
    }

    /**
     * @pre 0 <= pos.getRow() < Number_of_Rows
     *      0 <= pos.getColumn() < Number_of_Columns
     *      pos = [last position played]
     *
     * @post checkVertWin = (whether the number of player tokens are in a row vertically = Number_to_Win)
     *
     * @param pos: the BoardPosition of the last placed token
     * @param p: the token of the player that last placed the token
     * @return whether the number of player tokens are in a row vertically = Number_to_Win
     */
    default public  boolean checkVertWin(BoardPosition pos, char p){
        int row = pos.getRow();
        int column = pos.getColumn();
        int InColumn = 1;

        //check whether the positions bellow the pos == p
        int Iter = row - 1;
        while (Iter >= 0) {
            if(isPlayerAtPos(new BoardPosition(Iter, column), p)) {
                InColumn++;
                Iter--;
            } else {
                Iter = -1;
            }
        }

        //checks if there are 4 in a line
        return (InColumn >= getNumToWin());
    }

    /**
     * @pre 0 <= pos.getRow() < Number_of_Rows
     *      0 <= pos.getColumn() < Number_of_Columns
     *      pos = [last position played]
     *
     * @post checkDiagWin = (whether the number of player tokens are in a row diagonally = Number_to_Win)
     *
     * @param pos: the BoardPosition of the last placed token
     * @param p: the token of the player that last placed the token
     * @return whether the number of player tokens are in a row diagonally = Number_to_Win
     */
    default public boolean checkDiagWin(BoardPosition pos, char p){
        int row = pos.getRow();
        int column = pos.getColumn();
        int InDiag = 1;
        int IterR = row + 1;
        int IterC = column + 1;

        // finds how may consecutive tokens to the upper right of pos = p
        while (IterR < getNumRows() && IterC < getNumColumns()) {
            if(isPlayerAtPos(new BoardPosition(IterR, IterC), p)) {
                InDiag++;
                IterR++;
                IterC++;
            } else {
                IterR = getNumRows();
            }
        }

        // finds how may consecutive tokens to the lower left of pos = p
        IterC = column - 1;
        IterR = row -1;
        while (IterR >= 0 && IterC >= 0){
            if(isPlayerAtPos(new BoardPosition(IterR, IterC), p)){
                InDiag++;
                IterR--;
                IterC--;
            } else {
                IterR = -1;
            }
        }

        // checks win condition, if not satisfied resets to check other diagonal
        if (InDiag >= getNumToWin()) {
            return true;
        } else {
            InDiag = 1;
            IterC = column - 1;
            IterR = row + 1;
        }

        // finds how may consecutive tokens to the upper left of pos = p
        while (IterR < getNumRows() && IterC >= 0) {
            if(isPlayerAtPos(new BoardPosition(IterR, IterC), p)) {
                InDiag++;
                IterR++;
                IterC--;
            } else {
                IterR = getNumRows();
            }
        }

        // finds how may consecutive tokens to the lower right of pos = p
        IterC = column + 1;
        IterR = row - 1;
        while (IterR > -1 && IterC < getNumColumns()) {
            if(isPlayerAtPos(new BoardPosition(IterR, IterC), p)) {
                InDiag++;
                IterR--;
                IterC++;
            } else {
                IterR = -1;
            }
        }

        // returns whether the win condition was satisfied
        return InDiag >= getNumToWin();
    }

    /**
     * @pre 0 <= pos.getRow() < Number_of_Rows
     *      0 <= pos.getColumn() < Number_of_Columns
     *
     * @post whatsAtPos = token at BoardPosition pos
     *
     * @param pos: the BoardPosition to get the token from
     * @return the token at BoardPosition pos
     */
    public char whatsAtPos(BoardPosition pos);

    /**
     * @pre 0 <= pos.getRow() < Number_of_Rows
     *      0 <= pos.getColumn() < Number_of_Columns
     *
     * @post isPlayerAtPos = whether the player token is at position pos
     *
     * @param pos: the BoardPosition to check for the token player
     * @param player: the token of the player
     * @return whether the player token is at position pos
     */
    default public boolean isPlayerAtPos(BoardPosition pos, char player){
        return (whatsAtPos(pos) == player);
    }

    /**
     * @post toString() = a string with the characters formatted like so for a 100 X 100 Board
     *         where * is the player token
     *                      | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|...|99|
     *         column [99]  |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [...] |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [5]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [4]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [3]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [2]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [1]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [0]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *
     *
     *         will scale to any size, (column [#]) not included in string
     *
     * @return a string with the characters formatted like so for a 100 X 100 Board
     *         where * is the player token
     *                      | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|...|99|
     *         column [99]  |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [...] |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [5]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [4]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [3]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [2]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [1]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *         column [0]   |* |* |* |* |* |* |* |* |* |* |* |...|* |\n
     *
     *
     *         will scale to any size, (column [#]) not included in string
     */
    @Override
    public String toString();

    /**
     * @pre [there are no wins on the board]
     *
     * @post checkTie = whether the board is full
     *
     * @return whether the board is full with no player win
     */
    default public boolean checkTie(){
        boolean Tie = false;

        //checks the top of every column returns false if it finds an empty one, true otherwise
        for(int Iter = 0; Iter < getNumColumns(); Iter++){
            Tie = !(checkIfFree(Iter));
            if(!Tie){
                return Tie;
            }
            Iter++;
        }
        return Tie;
    }

    /**
     * @post getNumRows = Number_of_Rows
     *
     * @return Number_of_Rows
     */
    public int getNumRows();

    /**
     * @post getNumColumns = Number_of_Columns
     *
     * @return Number_of_Columns
     */
    public int getNumColumns();

    /**
     * @post getNumToWin = Number_to_Win
     *
     * @return Number_to_Win
     */
    public int getNumToWin();
}

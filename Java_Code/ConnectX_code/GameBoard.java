package cpsc2150.connectX;

import com.sun.rowset.internal.Row;

public class GameBoard extends AbsGameBoard implements IGameBoard {

    /**
     * @invariant Board [NumRows][NumColumns]
     *            Size.of.Board = NumRows * NumColumns
     *            3 >= NumColumns <= 100
     *            3 >= NumRows <= 100
     *            2 >= NumToWin <= 25
     *            NumToWin < NumRows
     *            NumToWin < NumColumns
     *
     * Correspondence NumRows = Number_of_Rows
     * Correspondence NumColumns = Number_of_Columns
     * Correspondence NumToWin = Number_to_Win
     * Correspondence Size.of.Board = BoardSize
     *
     * Initialization ensures Board [NumRows][NumColumns]
     *                        Size.of.Board = NumRows * NumColumns
     *                        3 >= NumColumns <= 100
     *                        3 >= NumRows <= 100
     *                        2 >= NumToWin <= 25
     *                        NumToWin < NumRows
     *                        NumToWin < NumColumns
     */


    private char[][] Board;
    private int NumColumns;
    private int NumRows;
    private int NumToWin;
    private BoardPosition LastPlaced;

    /**
     * @pre 3 <= columns <= 100
     *      3 <= rows <= 100
     *      2 <= win <= 25
     *      win < rows
     *      win < columns
     *
     * @post Board [NumRows][NumColumns]
     *       Size.of.Board = NumRows * NumColumns
     *       3 >= NumColumns <= 100
     *       3 >= NumRows <= 100
     *       2 >= NumToWin <= 25
     *       NumToWin < NumRows
     *       NumToWin < NumColumns
     */
    public GameBoard(int columns, int rows, int win){
        NumColumns = columns;
        NumRows = rows;
        NumToWin = win;
        Board = new char [NumRows][NumColumns];
        int Column = 0;
        int Row = 0;

        // initializes an array of BoardPositions the same size as Board
        for(int i = 0; i < (NumRows * NumColumns); i++){
            Board[Row][Column] = empty;
            Column++;
            if(Column == NumColumns){
                Row++;
                Column = 0;
            }
        }
    }

    //Finish diagarm for this one
    public void placeToken(char p, int c){
        int uperBound = getNumRows()-1;
        int lowerBound = 0;
        int checkpos = getNumRows()/2;

        // Loops through the column and finds the last placed token, loop while (checkpos position has a token and checkpos+1 position does not) is false
        while(!(whatsAtPos(new BoardPosition(checkpos, c)) != empty && whatsAtPos(new BoardPosition((checkpos+1), c)) == empty)){

            // If the column the lowest open position is 0 or getNumRows()-1 subtract 1 from checkpos
            if(checkpos == 0 || checkpos == getNumRows()-1){
                checkpos -= 1;
                break;
            }

            // If checkpos is empty and checkpos-1 has a token the checkpos-1
            if((whatsAtPos(new BoardPosition(checkpos, c)) == empty && whatsAtPos(new BoardPosition((checkpos-1), c)) != empty)){
                checkpos -= 1;
                break;
            }

            // If checkpos is empty then checkpos = midpoint between checkpos and the lowerBound
            if(whatsAtPos(new BoardPosition(checkpos, c)) == empty){
                uperBound = checkpos;
                checkpos = (lowerBound+uperBound)/Halfing;
            }

            // If checkpos is not empty then checkpos = midpoint between checkpos and the upperbound
            else if(whatsAtPos(new BoardPosition(checkpos, c)) != empty){
                lowerBound = checkpos;
                checkpos = (lowerBound+uperBound)/Halfing;
            }
        }

        // Add one to checkpos to get teh Board position to place the token in column c
        Board [checkpos+1][c] = p;
        LastPlaced = new BoardPosition((checkpos+1), c);
    }

    @Override
    public boolean checkForWin(int c){
        char player = whatsAtPos(LastPlaced);
        return (checkHorizWin(LastPlaced, player) || checkVertWin(LastPlaced, player) || checkDiagWin(LastPlaced, player));
    }

    public char whatsAtPos(BoardPosition pos){
        return Board[pos.getRow()][pos.getColumn()];
    }

    public int getNumRows(){
        return NumRows;
    }

    public int getNumColumns(){
        return NumColumns;
    }

    public int getNumToWin(){
        return NumToWin;
    }
}



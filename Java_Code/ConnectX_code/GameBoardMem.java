package cpsc2150.connectX;
import java.util.*;

public class GameBoardMem extends AbsGameBoard implements IGameBoard {

    /**
     * @invariant Board <Token, List of BoardPositions that the token is located at>
     *            Board.IsEmpty = true
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
     * Initialization ensures Board <Token, List of BoardPositions that the token is located at>
     *                        Board.IsEmpty = true
     *                        3 >= NumColumns <= 100
     *                        3 >= NumRows <= 100
     *                        2 >= NumToWin <= 25
     *                        NumToWin < NumRows
     *                        NumToWin < NumColumns
     */

    private Map<Character, ArrayList<BoardPosition>> Board;
    private int NumColumns;
    private int NumRows;
    private int NumToWin;

    /**
     * @pre 3 <= columns <= 100
     *      3 <= rows <= 100
     *      2 <= win <= 25
     *      win < rows
     *      win < columns
     *
     * @post Board <Token, List of BoardPositions that the token is located at>
     *       3 >= NumColumns <= 100
     *       3 >= NumRows <= 100
     *       2 >= NumToWin <= 25
     *       NumToWin < NumRows
     *       NumToWin < NumColumns
     *
     * @param win: the number in a row needed to win
     * @param rows: the number of rows in the game board
     * @param columns: the number of columns in the game board
     */
    public GameBoardMem(int columns, int rows, int win){
        NumColumns = columns;
        NumRows = rows;
        NumToWin = win;
        Board = new HashMap<Character, ArrayList<BoardPosition>>();
    }

    public void placeToken(char p, int c){
        int openPos = 0;
        ArrayList<BoardPosition> newList;

        // Searches the Map to find the BoardPosition with the highest row value.
        // Adds one to that value creating a board position with that row value and the column value given
        for(Map.Entry<Character,ArrayList<BoardPosition>> m: Board.entrySet()){
            for(BoardPosition pos: m.getValue()){
                if(pos.getColumn() == c && pos.getRow() >= openPos){
                        openPos = pos.getRow() + 1;
                }
            }
        }
        BoardPosition PosPLace = new BoardPosition(openPos, c);

        // If checks if there is key value of value p already if not it creates one
        if(!Board.containsKey(p)){
            newList = new ArrayList<>();
            Board.put(p, newList);
        }

        // adds the board position to the list that corresponds to the key value p
        Board.get(p).add(PosPLace);
    }

    public char whatsAtPos(BoardPosition pos){
        Character token = empty;
        for(Map.Entry<Character,ArrayList<BoardPosition>> m: Board.entrySet()){
            if(m.getValue().contains(pos)) {
                token = m.getKey();
                break;
            }
        }
        return token;
    }

    @Override
    public boolean isPlayerAtPos(BoardPosition pos, char player){
        return Board.get(player).contains(pos);
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

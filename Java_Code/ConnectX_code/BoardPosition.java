package cpsc2150.connectX;

public class BoardPosition {

    /**
     * @invariant Row:Z
     *            Column:Z
     *
     * Initialization Ensures: ?? is this needed for a class
     */

    private int Row;
    private int Column;

    /**
     * @pre  row: Z
     *       column: Z
     *
     * @post Row: Z
     *       Column: Z
     *       Row = row
     *       Column = column
     *
     * @param row: the row that the board position is located at
     * @param column: the column that the board position is located at
     */
    public BoardPosition (int row, int column){
        Row = row;
        Column = column;
    }

    /**
     * @post getRow = Row
     *
     * @return Row
     */
    public int getRow() {
        return Row;
    }

    /**
     * @post getColumn = Column
     *
     * @return Column
     */
    public int getColumn() {
        return Column;
    }

    /**
     * @post equals = true if the Row of numberTwo equals Row of current BoardPosition, and Column of numberTwo equals Column of current BoardPosition, else false
     *
     * @param numberTwo: the BoardPosition that the current BoardPosition is being compared to
     * @return true if the Row of numberTwo equals Row of current BoardPosition, and Column of numberTwo equals Column of current BoardPosition, else false
     */
    @Override
    public boolean equals(Object numberTwo){
        if(numberTwo instanceof BoardPosition) {
            return ((Row == ((BoardPosition) numberTwo).getRow()) && (Column == ((BoardPosition) numberTwo).getColumn()));
        }
        return false;
    }

    /**
     * @post toString = "<Row>,<Column>"
     *
     * @return a sting of format "<Row>,<Column>"
     */
    @Override
    public String toString(){
        return Row + ", " + Column;
    }

}

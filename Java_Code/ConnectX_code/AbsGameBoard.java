package cpsc2150.connectX;

abstract class AbsGameBoard implements IGameBoard {
    @Override
    public String toString(){
        String PrintBoard = "| ";
        int numberOfColumns = 0;
        while(numberOfColumns < getNumColumns()){
            if(numberOfColumns < DoubleDigitRows) {
                PrintBoard = PrintBoard + numberOfColumns + "| ";
            } else {
                PrintBoard = PrintBoard + numberOfColumns + "|";
            }
            numberOfColumns++;
        }
        PrintBoard = PrintBoard + "\n";
        int Line = getNumRows() - 1;
        int LineContent;
        while(Line >= 0){
            LineContent = 0;
            while(LineContent < getNumColumns()){
                PrintBoard = PrintBoard + "|" + whatsAtPos(new BoardPosition(Line, LineContent)) + " ";
                LineContent++;
            }
            PrintBoard = PrintBoard + "|\n";
            Line--;
        }
        return PrintBoard;
    }
}

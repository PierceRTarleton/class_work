package cpsc2150.connectX;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * The controller class will handle communication between our View and our Model (IGameBoard)
 *
 * This is where you will write code
 *
 * You will need to include your IGameBoard interface
 * and both of the IGameBoard implementations from Homework 3
 * If your code was correct you will not need to make any changes to your IGameBoard implementation class
 */

public class ConnectXController {
    //our current game that is being played
    private IGameBoard curGame;


    //The screen that provides our view
    private ConnectXView screen;

    private ArrayList<Character> PlayerList;
    private int playerTurn;
    private boolean newGame;



    public static final int MAX_PLAYERS = 10;
    public static final int Halfing = 2;
    //our play tokens are hard coded. We could make a screen to get those from the user, but


   private int numPlayers;



    /**
     * @pre np < MAX_PLAYERS
     *
     * @param np number of players
     * @param model the board implementation
     * @param view the screen that is shown
     * @post the controller will respond to actions on the view using the model.
     */
    ConnectXController(IGameBoard model, ConnectXView view, int np){
        this.curGame = model;
        this.screen = view;
        numPlayers = np;
        PlayerList = new ArrayList<>();
        PlayerList.add('X');
        PlayerList.add('O');
        PlayerList.add('T');
        PlayerList.add('F');
        PlayerList.add('R');
        PlayerList.add('S');
        PlayerList.add('D');
        PlayerList.add('L');
        PlayerList.add('J');
        PlayerList.add('M');
        playerTurn = 0;
        newGame = false;
    }

    /**
     *
     *
     * @param col the column of the activated button
     * @post will allow the player to place a token in the column if it is not full, otherwise it will display an error
     * and allow them to pick again. Will check for a win as well. If a player wins it will allow for them to play another
     * game hitting any button
     */
    public void processButtonClick(int col) {
        if(newGame || !(col < curGame.getNumColumns())){
            newGame();
        }

        //check if column is full prints error if true.
        if(!curGame.checkIfFree(col)){
            screen.setMessage("Column is full");
        }


        else {

            //place token in IGameBoard
            curGame.placeToken(PlayerList.get(playerTurn), col);

            //find the position the token was placed in to send to the view to display
            if(!curGame.checkIfFree(col)){
                //BoardPosition PlacedTolken = new BoardPosition((curGame.getNumRows()-1), col);
                screen.setMarker((curGame.getNumRows()-1), col, PlayerList.get(playerTurn));
            }
            else {
                //algorithm to find first empty pos of column col
                int uperBound = curGame.getNumRows();
                int lowerBound = 0;
                int checkpos = curGame.getNumRows() / Halfing;

                // Loops through the column and finds the last placed token, loop while (checkpos position has a token and checkpos+1 position does not) is false
                while (!(curGame.whatsAtPos(new BoardPosition(checkpos, col)) != ' ' && curGame.whatsAtPos(new BoardPosition((checkpos + 1), col)) == ' ')) {

                    // If checkpos is empty then checkpos = midpoint between checkpos and the lowerBound
                    if (curGame.whatsAtPos(new BoardPosition(checkpos, col)) == ' ') {
                        uperBound = checkpos;
                        checkpos = (lowerBound + uperBound) / Halfing;
                    }

                    // If checkpos is not empty then checkpos = midpoint between checkpos and the upperbound
                    else {
                        lowerBound = checkpos;
                        checkpos = (lowerBound + uperBound) / Halfing;
                        if (checkpos == curGame.getNumRows() - 1) {
                            break;
                        }
                    }
                }
                BoardPosition PlacedTolken = new BoardPosition(checkpos, col);
                screen.setMarker(PlacedTolken.getRow(), PlacedTolken.getColumn(), PlayerList.get(playerTurn));
            }

            // check for win and tie, if ether is true allow player to play again by clicking any button
            if(curGame.checkForWin(col)){
                screen.setMessage("Player " + PlayerList.get(playerTurn) + " Won!\n Click any Button to play again.");
                newGame = true;
            }
            else if(curGame.checkTie()){
                screen.setMessage("It is a tie Game.\n Click any Button to play again.");
                newGame = true;
            }

            //increment the playerTurn to get the index of the next player.
            else if(playerTurn == numPlayers-1){
                playerTurn = 0;
            }
            else {
                playerTurn++;
            }

            //display who has the next turn.
            if(!newGame) {
                screen.setMessage("It is " + PlayerList.get(playerTurn) + "'s turn");
            }
        }
    }

    /**
     * This method will start a new game by returning to the setup screen and controller
     */
    private void newGame()
    {
        //close the current screen
        screen.dispose();
        //start back at the set up menu
        SetupView screen = new SetupView();
        SetupController controller = new SetupController(screen);
        screen.registerObserver(controller);
    }
}

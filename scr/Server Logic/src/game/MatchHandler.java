package game;

import iceclimberlogic.GameLogic;

import java.util.LinkedList;

public class MatchHandler extends Thread {
    private LinkedList<String> queue = new LinkedList<String>();
    private LinkedList<GameLogic> games = new LinkedList<GameLogic>();
    public MatchHandler(){
        //constructor
    }

    /**
     * Creates a new game on the server
     * @param enemies number to be spawn on the game
     * @param enemiesID s
     * @return gameID
     */
    public String createGame(int enemies, int enemiesID[]){
       if(games.size() < 3) {
           GameLogic gameLogic = new GameLogic(enemies, enemiesID);
           games.add(gameLogic);
           return gameLogic.getGameID();
       }else{
           return null;
       }
    }

    /**
     * Updates the positions of the players in the server
     * @param gameID of the game being played
     * @param players positions
     */
    public void updatePlayers(String gameID, int players[][]){
        GameLogic gameLogic = searchGameByID(gameID);
        gameLogic.setUpdate(players);
    }

    /**
     * Searches for a game base off it's ID
     * @param gameID to search
     * @return gameLogic instance
     */
    public GameLogic searchGameByID(String gameID){
        int length = games.size();
        for(int i = 0; i < length; i++){
            GameLogic current = games.get(i);
            if(current.getGameID().equals(gameID)){
                return current;
            }
        }
        return null;
    }
}

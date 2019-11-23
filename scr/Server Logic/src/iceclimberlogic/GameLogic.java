/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package iceclimberlogic;

/**
 *
 * @author david
 */
public class GameLogic {
    private final int[] floors = {60,67,74,81,95,102};
    private int enemiesMatrix[][];
    private Enemy enemiesArray[];
    private int enemQ;
    private Player plyr1, plyr2;
    private final String gameID;

    public GameLogic(int enemQ, int enemiesIDs[]){
        this.gameID = this.toString();
        this.enemQ = enemQ;
        this.enemiesMatrix = new int[this.enemQ][3];
        this.enemiesArray = new Enemy[this.enemQ];
        int players[][] = {{0,0,0},{0,0,0}};
        this.createPlyrs(players);

        for(int i = 0; i < this.enemQ; i++){
            this.enemiesArray[i] = createEnemy(enemiesIDs[i]);
        }
        this.initEnemies();
    }

    public void initEnemies(){
        for(int i = 0; i < this.enemQ; i++){
            this.enemiesArray[i].start();
        }
    }

    public int[][] getUpdate(){
        for(int i = 0; i < enemQ; i++){
            this.enemiesMatrix[i][0] = this.enemiesArray[i].getEnem();
            this.enemiesMatrix[i][1] = this.enemiesArray[i].getPos()[0];
            this.enemiesMatrix[i][2] = this.enemiesArray[i].getPos()[1];
            System.out.println(this.enemiesMatrix[i][0] + " -> X: " + this.enemiesMatrix[i][1] + " Y: " + this.enemiesMatrix[i][2]);
        }
        return this.enemiesMatrix;
    }

    public void setUpdate(int plyrs[][]){
        this.plyr1.setPos(plyrs[0][1], plyrs[0][2]);
        if(plyrs[1][0] != 0){
            this.plyr2.setPos(plyrs[1][1], plyrs[1][2]);
        }
    }

    public void createPlyrs(int plyrs[][]){
        this.plyr1 = new Player(1, this.enemiesArray);
        this.plyr1.setPos(plyrs[0][1], plyrs[0][2]);
        if(plyrs[1][0] != 0){
            this.plyr2 = new Player(2, this.enemiesArray);
            this.plyr2.setPos(plyrs[1][1], plyrs[1][2]);
        }
    }

    public void hitEnemy(int plyrID){
        if(plyrID == 1){
            this.plyr1.hitEne();
        }else{
            this.plyr2.hitEne();
        }
    }

    public final Enemy createEnemy(int enemID){
        int pos[] = new int[2];
        int rnd = (int) Math.round(Math.random() * ((5-0) + 1 + 0));
        if(rnd == 6) rnd -= 1;
        switch(enemID){
            case 7:
                if(this.floors[rnd]%2 == 0){
                    pos[0] = 1;
                }else{
                    pos[0] = 30;
                }
                pos[1] = this.floors[rnd] - 2;
                break;
            case 8:
                pos[0] = 0;
                pos[1] = this.floors[rnd] - 2;
                break;
            case 9:
                rnd = (int) Math.round(Math.random() * ((4-0) + 1 + 0));
                pos[0] = (int) (Math.round(Math.random() * ((23 - 8) + 1)) + 4);
                pos[1] = this.floors[rnd] + 1;
                break;
            case 10:
                pos[0] = 2;
                pos[1] = 0;
                break;
            default:
                break;
        }
        System.out.println("Init on -> X: " + pos[0] + " Y: " + pos[1]);
        return new Enemy(enemID, pos);
    }


    //**************************************************************************
    //******************** GETTERS AND SETTERS *********************************
    //**************************************************************************

    public int getEnemQ(){
        return this.enemQ;
    }

    public String getGameID(){
        return this.gameID;
    }
}


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
public class Player extends Thread {
    private int genre;
    private String name;
    private boolean alive;
    private int[] score = {0,0,0,0,0};
    private int[] pos = {0,0};
    
    private int step = 1;
    private Enemy[] enem;
    
    public Player(int genre, Enemy enem[]){
        switch (genre) {
            case 1:
                this.genre = genre;
                this.name = "Popo";
                break;
            case 2:
                this.genre = genre;
                this.name = "Nana";
                break;
            default:
                System.out.println("ERROR: Genero no identificado");
                break;
        }
        this.enem = enem;
        this.alive = true;
    }
    
    @Override
    public void run(){
        try {
            while (true){
                this.pos[0] += step;
                if(hitEne()){
                   break;
                }
                if(this.pos[0] == 31 || this.pos[0] == 0){
                    step *= -1;
                }
                System.out.println(this.genre + " -> X: " + this.pos[0] + " Y: " + this.pos[1]);
                Thread.sleep(500);
            }
        } catch (InterruptedException ex) {
            System.out.println("Thread interrupted.");
        }
    }
    
    public boolean hitEne(){
        for(int i = 0; i < enem.length; i++){
            if((Math.abs(this.pos[0] - this.enem[i].getPos()[0]) <= 2) && (this.pos[1] == this.enem[i].getPos()[1])){
                this.enem[i].setAlive(false);
                System.out.println("Enemy killed!");
                return true;
            }
        }
        return false;
    }
    
    //**************************************************************************
    //******************** GETTERS AND SETTERS ********************************* 
    //**************************************************************************
    
    public void setAlive(boolean alive){
        this.alive = alive;
    }
    
    public boolean setPos(int x, int y){
        this.pos[0] = x;
        this.pos[1] = y;
        for(int i = 0; i < enem.length; i++){
            if((Math.abs(this.pos[0] - this.enem[i].getPos()[0]) <= 2) && (this.pos[1] == this.enem[i].getPos()[1])) {
                this.alive = false;
            }
        }
        return this.alive;
    }

    public void setScore(int id){
        switch(id){
            case 7:
                this.score[2] += 400;
                break;
            case 8:
                this.score[3] += 800;
                break;
            case 10:
                this.score[0] += 3000;
                break;
            case 11:
                this.score[1] += 100;
                break;
            case 12:
                this.score[1] += 200;
                break;
            case 13:
                this.score[1] += 300;
                break;
            case 14:
                this.score[1] += 400;
                break;
            default:
                this.score[4] += 10;
                break;
        }
    }
    
    public boolean checkIsAlive(){
        return this.alive;
    }
    
    public int[] getPos(){
        return this.pos;
    }

    public int[] getScore(){
        return this.score;
    }
}

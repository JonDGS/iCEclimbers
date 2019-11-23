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
    // Matriz [57][32]
    private int genre;
    private String name;
    private int life;
    private int pos[] = {0,0};

    private int step = 1;
    private Enemy enem[];

    Player(int genre, Enemy enem[]){
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
        this.life = 3;
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
            if((Math.abs(this.pos[0] - this.enem[i].getPos()[0]) <= 1) && (this.pos[1] == this.enem[i].getPos()[1])){
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

    public void setLife(int life){
        this.life = life;
    }

    public void setPos(int x, int y){
        this.pos[0] = x;
        this.pos[1] = y;
    }

    public int getLife(){
        return this.life;
    }

    public int[] getPos(){
        return this.pos;
    }
}

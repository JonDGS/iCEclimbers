/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package iceclimberlogic;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author david
 */
public class Enemy extends Thread {
    // Matriz [32][110]
    private int pos[];
    private int enem;
    private boolean alive = true;
    
    private int stepH = 1;
    private int stepV = 1;
    
    public Enemy(int enem, int[] pos){
        this.enem = enem;
        this.pos = pos;
    }
    
    
    @Override
    public void run() {
        switch (this.enem){
            // Foca u Oso polar
            case 7:
                while(alive){
                    try {
                        this.pos[0] += stepH;
                        if(this.pos[0] == 31 || this.pos[0] == 1){
                            stepH *= -1;
                        }
                        System.out.println("Foca -> X: " + this.pos[0] + " Y: " + this.pos[1]);
                        Thread.sleep(500);
                    } catch (InterruptedException ex) {
                        System.out.println("Thread interrupted!");
                    }
                }
                this.pos[0] = -1;
                this.pos[1] = -1;
                break;
            // Ave
            case 8:
                while(alive){
                    try{
                        this.pos[0] += stepH;
                        this.pos[1] += stepV;
                        if(this.pos[0] == 31 || this.pos[0] == 0){
                            stepH *= -1;
                        }else if(this.pos[1] == 52 || this.pos[1] == 109 || (this.pos[0]%6 == 0 && this.pos[1]%7 == 0)){
                            stepV *= -1;
                        }
                        System.out.println("Ave -> X: " + this.pos[0] + " Y: " + this.pos[1]);
                        Thread.sleep(500);
                    }catch(InterruptedException ex){
                        System.out.println("Thread interrupted!");
                    }
                }
                this.pos[0] = -1;
                this.pos[1] = -1;
                break;
            // Hielo
            case 9:
                while(alive){
                    try{
                        if(this.pos[1] == 109){
                            this.alive = false;
                        }else{
                            this.pos[1] += 1;                              
                        }
                        System.out.println("Hielo -> X: " + this.pos[0] + " Y: " + this.pos[1]);
                        Thread.sleep(250);                          
                    }catch(InterruptedException ex){
                        System.out.println("Thread interrupted!");
                    }                   
                }
                this.pos[0] = -1;
                this.pos[1] = -1;
                break;
            // Pterodactilo
            case 10:
                while(alive){
                    try {
                        this.pos[0] += stepH;
                        if(this.pos[0] == 31 || this.pos[0] == 2){
                            stepH *= -1;
                        }
                        System.out.println("Pterodactilo -> X: " + this.pos[0] + " Y: " + this.pos[1]);
                        Thread.sleep(500);
                    } catch (InterruptedException ex) {
                        System.out.println("Thread interrupted!");
                    }
                }
                break;
        }            
    }
    
    //**************************************************************************
    //******************** GETTERS AND SETTERS ********************************* 
    //**************************************************************************
    
    public void setEnem(int enem){
        this.enem = enem;
    }
    
    public void setPos(int x, int y){
        this.pos[0] = x;
        this.pos[1] = y;
        System.out.println("Enemigo en posicion x: " + this.pos[0] + " y: " + this.pos[1]);
    }
    
    public void setAlive(boolean alive){
        this.alive = alive;
    }
    
    public boolean getAlive(){
        return this.alive;
    }
    
    public int[] getPos(){
        return this.pos;
    }
    
    public int getEnem(){
        return this.enem;
    }
}

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
public class VerdFrut {
    private final int id;
    private int pts;
    
    VerdFrut(int id){
        this.id = id;
        switch(pts){
            case 1:
                this.pts = 100;
                break;
            case 2:
                this.pts = 200;
                break;
            case 3:
                this.pts = 300;
                break;
            case 4:
                this.pts = 400;
                break;
            default:
                System.out.println("ERROR: Identificador invalido.");
                this.pts = -1;
                break;
        }
    }
    
    /***************************************************************************
    ********************* GETTERS AND SETTERS **********************************
    ***************************************************************************/
    
    public int getPts(){
        return this.pts;
    }
    
    public int getId(){
        return this.id;
    }
}

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
public class ICEclimberLogic {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int plyrs[][] = {{1,5, 107}, {2, 27,107}};
        int ids[] = {10,7,7,8,9};
        GameLogic gl = new GameLogic(5, ids);
        gl.initEnemies();
        gl.createPlyrs(plyrs);
    }
    
}

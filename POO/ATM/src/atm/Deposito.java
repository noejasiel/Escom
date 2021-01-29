/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atm;

import javax.swing.JOptionPane;

/**
 *
 * @author noeja
 */

//tambien puede ser public class Deposito extends main y ya no necesitaria main.saldo
public class Deposito {
    
    
    
    public void setDeposito(float num){
        if(num < 0){
            JOptionPane.showMessageDialog(null, " ERROR Cantidad Incorrecta");
        }else{
            main.saldo += num;

        }
    }
}

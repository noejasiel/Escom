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
public class Retirar {
    
    
    
    public void setRetiro(float retiro){
        if(retiro < 0){
            JOptionPane.showMessageDialog(null, " ERROR Cantidad Incorrecta");
        }else{
            
            if(main.saldo > retiro){ //se puede realizar la operacion
                 if(main.saldo - retiro < 1000){
                     main.saldo -= retiro + main.comision;
                     JOptionPane.showMessageDialog(null, 
                        "Retiro realizado, se cobro Comision tu saldo: "+main.saldo+ " es menor a 1000");
            }else{
                main.saldo -= retiro;
                JOptionPane.showMessageDialog(null, 
                        "Retiro realizado, NO se cobro Comision tu saldo: "+main.saldo+ " es mayor a 1000");
            }
            }else{
                JOptionPane.showMessageDialog(null, "Saldo Insuficiente");
            }
            
        }
        
        
    }
}

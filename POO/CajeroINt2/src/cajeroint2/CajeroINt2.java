/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cajeroint2;

import javax.swing.JOptionPane;

/**
 *
 * @author noeja
 */
public class CajeroINt2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        
        int option = 0;
        cajero22 proceso = new cajero22();
        //canti.SetCantidad(10000);
        do{
            option = Integer.parseInt(JOptionPane.showInputDialog(null, "Bienvenido al A.T.M por favor, Ingresa una opcion \n"
                    + "1.- ver Saldo \n 2.- Depositar \n 3.- Retirar \n 4.- salir", "MENU", JOptionPane.YES_NO_CANCEL_OPTION));
        
            if(option == 1 ){
                JOptionPane.showMessageDialog(null, proceso.GetCantidad(), "Saldo Disponible", JOptionPane.INFORMATION_MESSAGE);
            }else if(option == 2){
                String cantidad_depositar;
                do{
                     cantidad_depositar =JOptionPane.showInputDialog(null,
                                        "ingrese cantidad a depositar", "Deposito",
                                       JOptionPane.WARNING_MESSAGE);
                
                    if (cantidad_depositar != null){
                    
                         proceso.SetCantidad(Float.parseFloat(cantidad_depositar));

                     }else{
                         JOptionPane.showMessageDialog(null, "Operacion no completada ");
                     }
                }while(cantidad_depositar == null);
                
            }else if(option == 3){
                float cantidad_retirar = Float.parseFloat(JOptionPane.showInputDialog(null,
                                        "ingrese cantidad a Retirar", "Retiro",
                                       JOptionPane.QUESTION_MESSAGE));
                proceso.setRetiro(cantidad_retirar);
                
            }
            if(option >4 || option < 1){
                JOptionPane.showMessageDialog(null, "Igrese Opcion Valida", "ERROR", JOptionPane.WARNING_MESSAGE);
            }
        }while(option != 4);
        
        
        
    }
    
    
}

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
public class ATM {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        main saldo = new main();
        Deposito depositar = new Deposito();
        Retirar retiro = new Retirar();
        int opcion = 0;
        
        
       do{
           opcion = Integer.parseInt(JOptionPane.showInputDialog(null, 
                   "Bienvenido al A.T.M por favor,"
                   + " Ingresa una opcion \n"
                    + "1.- ver Saldo \n "
                   + "2.- Depositar \n "
                   + "3.- Retirar \n "
                   + "4.- Nombre \n "
                   + "5.- domicilio \n "        
                   + "6.- salir", "MENU", JOptionPane.YES_NO_CANCEL_OPTION));
       
           if(opcion == 1){
               JOptionPane.showMessageDialog(null, "tu saldo actual es: "+saldo.getCantidad());
           }else if(opcion == 2){
               
               String cantidad_depositar;
                do{
                     cantidad_depositar =JOptionPane.showInputDialog(null,
                                        "ingrese cantidad a depositar", "Deposito",
                                       JOptionPane.WARNING_MESSAGE);
                
                    if (cantidad_depositar != null){
                    
                         depositar.setDeposito(Float.parseFloat(cantidad_depositar));
                    }else {
                         JOptionPane.showMessageDialog(null, "NO se puede Cancelar la Operacion");
                     }
                }while(cantidad_depositar == null);
               
           }else if(opcion == 3){
               
                float cantidad_retirar = Float.parseFloat(JOptionPane.showInputDialog(null,
                                        "ingrese cantidad a Retirar", "Retiro",
                                       JOptionPane.QUESTION_MESSAGE));
                retiro.setRetiro(cantidad_retirar);
               
           }else if(opcion > 6 || opcion < 1){
               JOptionPane.showMessageDialog(null, "opcion invalida");
           }else if(opcion == 4){
               String name = JOptionPane.showInputDialog(null,
                       "Hola "+saldo.getName()+" escribe el nuevo nombre");
               saldo.setName(name);
           }else if(opcion == 5){
               String direc = JOptionPane.showInputDialog(null,
                       "Hola "+saldo.getName()+" tu direccion es: "
                       +saldo.getdirecion()+" Escribe tu nueva direccion");
               
               if (direc != null){
                    saldo.setdireccion(direc);
                }else {
                    JOptionPane.showMessageDialog(null, "NO se puede Cancelar la Operacion");
                }
            }
       
       
       }while(opcion != 6);
        
      
    }
    
}

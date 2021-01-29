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
public class cajero22 {
    private char IDcuenta;
    private float saldo = 1500;
    private char nombre;
    private char direccion;
    public float comision = (float) 30.50;
    
    
    public void SetCantidad(float cant){
        if(cant < 0){
            JOptionPane.showMessageDialog(null, "no se puede depositar esta cantidad", "error", JOptionPane.ERROR_MESSAGE);
        }else{
            this.saldo += cant;  
        }
         
    }
    public float GetCantidad(){
        return saldo;
    }
    
     public void setRetiro(float cant){
         
        if(cant < 0){
            JOptionPane.showMessageDialog(null, "Ingrese cantidad correcta", "ERROR", JOptionPane.WARNING_MESSAGE);
        }else{
            if(cant > saldo){
            JOptionPane.showMessageDialog(null, "no se puede Retirar esta cantidad \n ingrese una opcion valida",
                                          "error", JOptionPane.ERROR_MESSAGE);
        }else if(saldo < 1000){
            JOptionPane.showMessageDialog(null, "se cobro una comision de: "+comision, "Comision", JOptionPane.WARNING_MESSAGE);
            saldo -= cant + comision;
        }else{
            saldo -= cant;
            if(saldo < 1000){
                saldo -= comision;
                JOptionPane.showMessageDialog(null, "se cobro una comision de: "+comision, "Comision", JOptionPane.WARNING_MESSAGE);

            }
        }
        }
    }
    
}

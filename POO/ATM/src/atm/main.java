/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atm;

/**
 *
 * @author noeja
 */
public class main {
    static float saldo = 1500;
    static float comision = (float) 30.5;
    private String nombre = "default";
    private String direccion = "default";

    
    public float getCantidad(){
        return saldo;
    }
    public void setName(String name){
         nombre = name;
    }
    public void setdireccion(String direc){
         direccion = direc;
    }
     public String getName(){
        return nombre;
    }
    public String getdirecion(){
        return direccion;
    }
}

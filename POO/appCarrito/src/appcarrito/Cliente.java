/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package appcarrito;

/**
 *
 * @author noeja
 */
public class Cliente {
    
     private int id;
    private String nombre;
    private String correo;
    
    private Carro CA;
    
    //Constructor
    public Cliente(int I, String N, String C){
        id=I;
        nombre=N;
        correo=C;
        CA=null;
    }

    
    
    //Asigna un Carro al cliente
    public void asignarCarro(Carro C){
        
    CA= C;
    C.asignarCliente(this);
    }
    
    public String getName(){
        return this.nombre;
    }
            
}

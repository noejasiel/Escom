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
public class Item {
    private int cantidad;
    
    private Carro CA;
    private Producto P;
    
    //Constructor
    public Item(Producto N, int A){
    cantidad=A;
    }
    
    //Registra producto
    public void registrarProducto(Producto A){
    P=A;
    }
    //Registra carro
    public void registrarCarro(Carro C){
    CA=C;
    }
}

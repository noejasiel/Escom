/*
Elaborado por: Alfonso Aguilar Lopez y Silva Hernandez Noe;

programa que simula un carrito de compras con 3 clientes programados ademas de productos

*/
package appcarrito;

import java.util.ArrayList;
import java.util.Objects;
import javax.swing.JOptionPane;


class Carro {
   private int id;
    private Cliente C;
    private Carro Carro;
   ArrayList pedidos = new ArrayList();
    static private ArrayList <Item> articulos;
    //Constructor
    public Carro(int I){
    id=I;
    articulos = new ArrayList();
    C=null;
    }
    
    public Carro(){
        this.id=0;
        this.C=null;
        this.articulos = new ArrayList();
    }

    //Asigna el cliente
    public void asignarCliente(Cliente A){
    C=A;
    }
    
    public void add(Producto p, int inventario, int cantidad){
        
        //JOptionPane.showMessageDialog(null, );
        if(cantidad > inventario || inventario - cantidad < 0){
            JOptionPane.showMessageDialog(null, "no hay inventario bro");
        }else{
        Item I = new Item(p, inventario);
            
        this.articulos.add(I);
        I.registrarCarro(this);
        I.registrarProducto(p);
        pedidos.add(p.nombre);
        pedidos.add(cantidad);
        pedidos.add(p.precio);
        JOptionPane.showMessageDialog(null, pedidos);
        //p.cant = p.cant - cantidad;
        
        } 
    }
    
    public void setCarro(ArrayList<Producto> prroductos){
       // this.devolver();
       int opcion = 0;
       int find = 0;
       
       do{
        opcion = Integer.parseInt(JOptionPane.showInputDialog(null, "Modificar \n "+ this.devolver() + "\n Selecione una opcion: \n"
                + " 1.- quitar producto \n 2.- modificar producto\n 3.- salir"));
        
        if(opcion == 1){
            String buscar;
            int findd = 0;
            buscar = JOptionPane.showInputDialog(null, "Quitar Producto \n "+ this.devolver() + "\n Escriba el articulo que desea quitar\n ej: baby yoda");
            findd = this.pedidos.indexOf(buscar);
            this.pedidos.remove(findd);
            this.pedidos.remove(findd);
            this.pedidos.remove(findd);
        }else if(opcion == 2){
            
            String buscar;
            int  aumen = 0;
            int resta = 0;
            boolean indice;
            buscar = JOptionPane.showInputDialog(null, "Mod producto \n "+ this.devolver() + "\n Escriba el articulo que desea modificar\n ej: baby yoda");
            aumen =Integer.parseInt(JOptionPane.showInputDialog(null, "Cuantas unidades desear aumentar?"));
            find = this.pedidos.indexOf(buscar);
            for(int i = 0; i< prroductos.size(); i++){
                if( Objects.equals(prroductos.get(i).nombre, buscar) ){
                    if(aumen > prroductos.get(i).cant || (int)this.pedidos.get(find + 1) + aumen > prroductos.get(i).cant){
                        JOptionPane.showMessageDialog(null, "Operacion incorrecta - no hay esa cantidad de producto");
                    }else{
                        this.pedidos.set(find + 1 , (int)this.pedidos.get(find + 1) + aumen);
                        JOptionPane.showMessageDialog(null, "HOLAAA esta es mi buscar :"+" y pedidos " + prroductos.get(i).nombre);
                    }
                    
                    
                }

            }
            
        }
       }while(opcion != 3);
       
    }
    
    public ArrayList devolver(){
        return this.pedidos;
    }
    public void limpiar(){
        this.pedidos.clear();
    }

    
    public void ticket(){
         int cont = 1;
       int aux2 = 0;
       for(int i = 0; i<pedidos.size(); i++){
           System.out.print(" "+ pedidos.get(i));
           if(cont == 3){
               int aux = 0;
               aux =(int) pedidos.get(i-1)*(int)pedidos.get(i);
               aux2 +=aux;
               System.out.print(" "+aux );
               System.out.println("\n");
               cont = 0;
           }
           cont++;
       }
       System.out.print("el Total es: "+aux2 );
       
    }
    
}

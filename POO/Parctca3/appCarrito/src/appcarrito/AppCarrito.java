/*
Elaborado por: Alfonso Aguilar Lopez y Silva Hernandez Noe;

programa que simula un carrito de compras con 3 clientes programados ademas de productos

*/
package appcarrito;

import java.util.ArrayList;
import javax.swing.JOptionPane;

public class AppCarrito {

    public static void main(String[] args) {
    ArrayList <Cliente> Clientes = new ArrayList(); 
    ArrayList <Carro> Carros = new ArrayList(); 
    ArrayList <Producto> Productos = new ArrayList();
    
    //para cada carro
    ArrayList  findProducts1 = new ArrayList();
    ArrayList  findCantidad1 = new ArrayList();
    ArrayList  findProducts2 = new ArrayList();
    ArrayList  findCantidad2 = new ArrayList();
    ArrayList  findProducts3 = new ArrayList();
    ArrayList  findCantidad3 = new ArrayList();
    
    Carro Ca1=new Carro(204511);
    Carro Ca2=new Carro(204522);
    Carro Ca3=new Carro(204533);
    //Registro de carros
    Carros.add(Ca1);
    Carros.add(Ca2);
    Carros.add(Ca3);
    
    Cliente C1=new Cliente(204501,"Jasiel Silva","jasielS@gmail.com");
    Cliente C2=new Cliente(204502,"Alfredo Aguilar","alfredA@gmail.com");
    Cliente C3=new Cliente(204503,"Yaxkin Mendoza","yaxkinM@gmail.com");
    
    //Registro de clientes
    Clientes.add(C1);
    Clientes.add(C2);
    Clientes.add(C3);
    
    //Asignar un carro al cliente
    C1.asignarCarro(Ca1);
    C2.asignarCarro(Ca2);
    C3.asignarCarro(Ca3);
        
    //definiendo productos
    Producto p1 = new Producto("baby yoda", 10, 100);
    Producto p2 = new Producto("balon", 10, 50);    
    Producto p3 = new Producto("soda", 10, 10);
    Producto p4 = new Producto("libreta", 10, 20);
    Producto p5 = new Producto("botella agua", 10, 15);
    Producto p6 = new Producto("bmx", 5, 1000);
    Producto p7 = new Producto("tv", 10, 3000);    
    Producto p8 = new Producto("uvas", 10, 10);
    Producto p9 = new Producto("xbox", 10, 2000);
    Producto p10 = new Producto("ps10", 10, 2500);
    
    
    Productos.add(p1);
    Productos.add(p2);
    Productos.add(p3);
    Productos.add(p4);
    Productos.add(p5);
    Productos.add(p6);
    Productos.add(p7);
    Productos.add(p8);
    Productos.add(p9);
    Productos.add(p10);
    
    
    
    //menu
    int opcion = 0;
    do{
            opcion = Integer.parseInt(JOptionPane.showInputDialog(null, "Bienvenido a ESCOMAZON por favor, Ingresa una opcion \n"
                    + "1.-" + Clientes.get(0).getName()+ " \n 2.-" + Clientes.get(1).getName()+ 
                    " \n 3.-" + Clientes.get(2).getName()+ " \n 4.- salir", "MENU", JOptionPane.YES_NO_CANCEL_OPTION));
            //CLIENTE 1
            if(opcion == 1){
                JOptionPane.showMessageDialog(null, "bienvenido "+ Clientes.get(0).getName());
                int opcion1 = 0;
                do{
                    opcion1 = Integer.parseInt(JOptionPane.showInputDialog(null, "Bienvenido a ESCOMAZON por favor, Ingresa una opcion \n"
                    + "1.- Mostrar Carro \n 2.- Agregar al carrito \n"
                        + " 3.- vaciar carro \n 4.- hacer pedido \n5.- salir", "MENU", JOptionPane.YES_NO_CANCEL_OPTION));
                    if(opcion1 == 1){
                        int find = 0;
                        int val;
                        Carros.get(0).setCarro(Productos);
                        
                    }else if(opcion1 == 2){
                        int Opcion, cant, aux = 0;
                        Opcion = Integer.parseInt(JOptionPane.showInputDialog(null, "estos son los productos \n selecione alguno \n 1.-" 
                                + Productos.get(0).nombre + "--- " + Productos.get(0).cant + "\n 2.-" + Productos.get(1).nombre+ "--- " + Productos.get(1).cant + "\n 3.-" + 
                                Productos.get(2).nombre+ "--- " + Productos.get(2).cant +"\n 4.-" + Productos.get(3).nombre+ "--- " + Productos.get(3).cant +"\n 5.-" +
                                Productos.get(4).nombre +"--- " + Productos.get(4).cant +"\n 6.-" + Productos.get(5).nombre + "--- " + Productos.get(5).cant + "\n 7.-" + Productos.get(6).nombre+ "--- " + Productos.get(6).cant + "\n 8.-" + 
                                Productos.get(7).nombre+ "--- " + Productos.get(7).cant +"\n 9.-" + Productos.get(8).nombre+ "--- " + Productos.get(8).cant +"\n 10.-" +
                                Productos.get(9).nombre +"--- " + Productos.get(9).cant));
                        cant = Integer.parseInt(JOptionPane.showInputDialog(null, "selecione la cantidad"));
                        findProducts1.add(Opcion - 1);
                        findCantidad1.add(cant);
                        Carros.get(0).add(Productos.get(Opcion - 1), Productos.get(Opcion - 1).cant, cant);
                        
                    }else if(opcion1 == 3){
                        Carros.get(0).limpiar();
                    }else if(opcion1 == 4){
                        Carros.get(0).ticket();
                        int cont = 0;
                        for(int i = 0; i<findProducts1.size(); i++){
                            int auxx, aux2 = 0;
                            auxx = (int)findProducts1.get(i);
                            aux2 = (int)findCantidad1.get(i);
                            //JOptionPane.showMessageDialog(null, "HLA"+(int)Productos.get(auxx).cant);
                            Productos.get(auxx).cant = (int)Productos.get(auxx).cant - aux2;
                        }
                        
                        Carros.get(0).limpiar();
                        findProducts1.clear();
                        findCantidad1.clear();
                        
                    }
                }while(opcion1 != 5);
               //CLIENTE 2 
            }else if(opcion == 2){
                JOptionPane.showMessageDialog(null, "bienvenido "+ Clientes.get(1).getName());
                int opcion1 = 0;
                do{
                    opcion1 = Integer.parseInt(JOptionPane.showInputDialog(null, "Bienvenido a ESCOMAZON por favor, Ingresa una opcion \n"
                    + "1.- Mostrar Carro \n 2.- Agregar al carrito \n"
                        + " 3.- vaciar carro \n 4.- hacer pedido \n5.- salir", "MENU", JOptionPane.YES_NO_CANCEL_OPTION));
                    if(opcion1 == 1){
                         int find = 0;
                        Carros.get(1).setCarro(Productos);
                    }else if(opcion1 == 2){
                         int Opcion, cant, aux = 0;
                        Opcion = Integer.parseInt(JOptionPane.showInputDialog(null, "estos son los productos \n selecione alguno \n 1.-" 
                                + Productos.get(0).nombre + "--- " + Productos.get(0).cant + "\n 2.-" + Productos.get(1).nombre+ "--- " + Productos.get(1).cant + "\n 3.-" + 
                                Productos.get(2).nombre+ "--- " + Productos.get(2).cant +"\n 4.-" + Productos.get(3).nombre+ "--- " + Productos.get(3).cant +"\n 5.-" +
                                Productos.get(4).nombre +"--- " + Productos.get(4).cant));
                        cant = Integer.parseInt(JOptionPane.showInputDialog(null, "selecione la cantidad"));
                        findProducts2.add(Opcion - 1);
                        findCantidad2.add(cant);
                        Carros.get(1).add(Productos.get(Opcion - 1), Productos.get(Opcion - 1).cant, cant);
                    }else if(opcion1 == 3){
                        Carros.get(1).limpiar();
                    }else if(opcion1 == 4){
                        Carros.get(1).ticket();
                        //JOptionPane.showMessageDialog(null, findProducts2 + " y mis cantidades a restra " + findCantidad2 );
                        int cont = 0;
                        for(int i = 0; i<findProducts2.size(); i++){
                            int auxx, aux2 = 0;
                            auxx = (int)findProducts2.get(i);
                            aux2 = (int)findCantidad2.get(i);
                            //JOptionPane.showMessageDialog(null, "HLA"+(int)Productos.get(auxx).cant);
                            Productos.get(auxx).cant = (int)Productos.get(auxx).cant - aux2;
                        }
                        
                        Carros.get(1).limpiar();
                        findProducts2.clear();
                        findCantidad2.clear();
                    }
                }while(opcion1 != 5);
                //
                //1CLIENTE 3
            }else if(opcion == 3){
                JOptionPane.showMessageDialog(null, "bienvenido "+ Clientes.get(2).getName());
                int opcion1 = 0;
                do{
                    opcion1 = Integer.parseInt(JOptionPane.showInputDialog(null, "Bienvenido a ESCOMAZON por favor, Ingresa una opcion \n"
                    + "1.- Mostrar Carro \n 2.- Agregar al carrito \n"
                        + " 3.- vaciar carro \n 4.- hacer pedido \n5.- salir", "MENU", JOptionPane.YES_NO_CANCEL_OPTION));
                    if(opcion1 == 1){
                        
                         int find = 0;
                        Carros.get(2).setCarro(Productos);
                    }else if(opcion1 == 2){
                         int Opcion, cant, aux = 0;
                        Opcion = Integer.parseInt(JOptionPane.showInputDialog(null, "estos son los productos \n selecione alguno \n 1.-" 
                                + Productos.get(0).nombre + "--- " + Productos.get(0).cant + "\n 2.-" + Productos.get(1).nombre+ "--- " + Productos.get(1).cant + "\n 3.-" + 
                                Productos.get(2).nombre+ "--- " + Productos.get(2).cant +"\n 4.-" + Productos.get(3).nombre+ "--- " + Productos.get(3).cant +"\n 5.-" +
                                Productos.get(4).nombre +"--- " + Productos.get(4).cant));
                        cant = Integer.parseInt(JOptionPane.showInputDialog(null, "selecione la cantidad"));
                        findProducts3.add(Opcion - 1);
                        findCantidad3.add(cant);
                        Carros.get(2).add(Productos.get(Opcion - 1), Productos.get(Opcion - 1).cant, cant);
                        
                    }else if(opcion1 == 3){
                        Carros.get(2).limpiar();
                    }else if(opcion1 == 4){
                        
                        Carros.get(2).ticket();
                        //JOptionPane.showMessageDialog(null, findProducts3 + " y mis cantidades a restra " + findCantidad3 );
                        int cont = 0;
                        for(int i = 0; i<findProducts3.size(); i++){
                            int auxx, aux2 = 0;
                            auxx = (int)findProducts3.get(i);
                            aux2 = (int)findCantidad3.get(i);
                            //JOptionPane.showMessageDialog(null, "HLA"+(int)Productos.get(auxx).cant);
                            Productos.get(auxx).cant = (int)Productos.get(auxx).cant - aux2;
                        }
                        
                        Carros.get(2).limpiar();
                        findProducts3.clear();
                        findCantidad3.clear();
                    }
                }while(opcion1 != 5);
                
            }
            
        }while( opcion != 4);
    
    }
  
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cajero;

/**
 *
 * @author noeja
 */


public class Cajero {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Empleado empleado1=new Empleado ("Fernando", "Ureña", 23, 800);
 
        Empleado empleado2=new Empleado ("", "Lopez", 50 ,1800);
 
        //Mostramos el valor actual del salario del empleado1
        System.out.println("El salario del empleado1 es "+empleado1.getSalario());
 
        //Modificamos la edad del empleado1
        empleado1.setEdad(43);
 
        empleado1.plus(100);
 
        //Mostramos el salario de nuevo, ahora tendra 100 mas
        System.out.println("El salario actual del empleado1 es "+empleado1.getSalario());
 
        //Modificamos el nombre del empleado2
        empleado2.setNombre("Antonio");
 
        empleado2.plus(100);
 
        //Mostramos el salario de nuevo, ahora tendra 100 mas
        System.out.println("El salario del empleado2 es "+empleado2.getSalario());
     
    }
    
}


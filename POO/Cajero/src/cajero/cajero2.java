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
public class Empleado {
    //Atributos
    /**
     * Nombre del empleado
     */
    private String nombre;
    /**
     * Apellido del empleado
     */
    private String apellido;
    /**
     * Edad del empleado
     */
    private int edad;
    /**
     * Salario del empleado
     */
    private double salario;
 
    //Metodos publicos
 
    /**
     * Devuelve el nombre del empleado
     * @return nombre del empleado
     */
    public String getNombre() {
        return nombre;
    }
 
    /**
     * Modifica el nombre de un empleado
     * @param nombre
     */
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
 
    /**
     * Devuelve la edad de un empleado
     * @return edad del empleado
     */
    public int getEdad() {
        return edad;
    }
 
    /**
     * Modifica la edad de un empleado
     * @param edad
     */
    public void setEdad(int edad) {
        this.edad = edad;
    }
 
    /**
     * Devuelve el salario de un empleado
     * @return salario del empleado
     */
    public double getSalario() {
        return salario;
    }
 
         /**
     * Suma un plus al salario del empleado si el empleado tiene mas de 40 años
     * @param sueldoPlus
     * @return <ul>
     *          <li>true: se suma el plus al sueldo</li>
     *          <li>false: no se suma el plus al sueldo</li>
     *          </ul>
     */
    public boolean plus (double sueldoPlus){
        boolean aumento=false;
        if (edad>40 && compruebaNombre()){
            salario+=sueldoPlus;
            aumento=true;
        }
        return aumento;
    }
 
    //Metodos privados
 
    private boolean compruebaNombre(){
        if(nombre.equals("")){
            return false;
        }
        return true;
    }
 
    //Constructor
         /**
     * Constructor por defecto
     */
         public Empleado(){
        this.nombre="";
        this.apellido="";
        this.edad=0;
        this.salario=0;
    }
 
        /**
     * Constructor con 4 parametros
     * @param nombre nombre del empleado
     * @param apellido nombre del empleado
     * @param edad edad del empleado
     * @param salario salario del empleado
     */
    public Empleado(String nombre, String apellido, int edad, double salario){
        this.nombre=nombre;
        this.apellido=apellido;
        this.edad=edad;
        this.salario=salario;
    }
}

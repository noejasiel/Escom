
package fonda;

import javax.swing.JOptionPane;

public class Fonda {

    public static void main(String[] args) {
        
        Entrada entrada = new Entrada();
        //entrada.getImprimir();
        
        String Entrada;
        int eleccion[] = new int[3];
        int aux;
        int aux2;
        do{
             Entrada = JOptionPane.showInputDialog(null, "Estas son las entradas disponibles \n"
                                               + "1.- Ensalada fresca de atún \n"
                                               + "2.- Tostadas de Camaron con Aguacate\n"
                                               + "3.- Pescado en Salsa de Mango   ");
             
             
             
            if(Entrada != null){
                aux = Integer.parseInt(Entrada);
             eleccion[0]= aux;
                String Guisados;
                do{
                     Guisados = JOptionPane.showInputDialog(null, "Estas son los Guisados disponibles \n"
                                                   + "1.- Chicharron en salsa verde \n"
                                                   + "2.- Papas con Chorizo\n"
                                                   + "3.- Alambre \n"
                                                   + "4.- enchiladas suizas   ");
                //aux = Integer.parseInt(Guisados);
                //eleccion[1]= aux;
                
                    if(Guisados != null){
                        String Postre = "";
                        do{
                            Postre = JOptionPane.showInputDialog(null, "Estas son los Postres disponibles \n"
                                                       + "1.- Moca Brownies al Doble Chocolate \n"
                                                       + "2.- Flan de Rompope\n"
                                                       + "3.- Paletas de Mojito\n "
                                                       + "4.- Rosca de Choco-Cereza   ");
                           
                            if(Postre != null){
                                //enviamos los platos elegidos a la clase
                                aux2 = Integer.parseInt(Postre);
                                entrada.preparar(eleccion);
                                entrada.preparar(Guisados);
                                entrada.preparar(aux2);
                            }else{
                                 JOptionPane.showMessageDialog(null, "debe escoger un Postre");
                            }
                            
                        }while(Postre == null);
                    }else{
                        JOptionPane.showMessageDialog(null, "debe escoger un Guisado");
                    }
                }while(Guisados == null);
                
            }else{
                JOptionPane.showMessageDialog(null, "debe escoger una entrada");
            }
        }while(Entrada == null);
        
    }
    
}

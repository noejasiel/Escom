
package fonda;

import javax.swing.JOptionPane;

class Entrada {
     private String Entrada[] = {"Ensalada fresca de atún", 
                                 "Tostadas de Camaron con Aguacate",
                                 "Pescado en Salsa de Mango"};
     private String Guisado[] = {"Chicharron en salsa verde", "Papas con Chorizo",
                                 "Alambre", 
                                 "enchiladas suizas"};
     private String Postre[] = {"Moca Brownies al Doble Chocolate", 
                                "Flan de Rompope",
                                "Paletas de Mojito", 
                                "Rosca de Choco-Cereza"};
    
    
    public void preparar(int eleccion[]){
        
        JOptionPane.showMessageDialog(null, "preparando "+Entrada[eleccion[0]-1] );
 
    }
    public void preparar(String eleccion){
        
        int elecion_guisado = Integer.parseInt(eleccion);
        JOptionPane.showMessageDialog(null, "preparando "+Guisado[elecion_guisado-1] );
    }
    public void preparar(int eleccion){
        
        JOptionPane.showMessageDialog(null, "preparando "+Postre[eleccion-1] );
    }
   
     
     public void getImprimir(){
        for (String Entrada1 : Entrada) {
            JOptionPane.showMessageDialog(null, Entrada1);
        }
    }

    
}

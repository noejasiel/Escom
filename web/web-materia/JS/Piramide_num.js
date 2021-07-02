function Piramide(){
	var piramide = "";
	var n = document.getElementById("num").value;
	if(isNaN(n)){
		alert("Debe ser un numero");
	} else if(n<1 || n>40) {
		alert("El numero debe estar en un rango de [1,40]");
	} else{
		for (var i = 1; j <= n; i++){
			for (var j =  0; j < (n -i); j++) {
				piramide += "&nbsp;";
			}
			for (var k =  i; k > 0; k--) {
				piramide += k.toString();
			}
			for (var m =  2; m <= i; m++) {
				piramide = m.toString();
			}
			piramide += "<br>";
		}
		document.getElementById("piramide").innerHTML = piramide;
	}
	return false;
}
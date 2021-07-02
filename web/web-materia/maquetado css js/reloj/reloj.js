var reloj = document.getElementById("boton");
var div = document.getElementById("hero");
var nodo = document.createElement("p");
nodo.innerHTML = Date();
nodo.style.color = "blue";
reloj.addEventListener("click", function () {
  div.appendChild(nodo);
});

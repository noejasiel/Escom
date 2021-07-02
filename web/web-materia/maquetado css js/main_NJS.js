var boton = document.getElementById("boton");
var root = document.getElementById("navegacion");
console.log(root);
boton.addEventListener("click", function () {
  root.parentElement.style.background = "yellow";
});

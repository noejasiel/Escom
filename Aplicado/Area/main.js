const before = document.getElementById("submit-enviar");
const grado = document.getElementById("grado");

before.style.display = "none";
let intervalo = []; //
const valores = []; //mi funcion

const form = document
  .getElementById("form")
  .addEventListener("submit", function (event) {
    event.preventDefault();

    var Intervalos = document.getElementsByClassName("intervalo");

    for (let i = 0; i < 2; i++) {
      intervalo.push(parseInt(Intervalos[i].value));
    }
    console.log(intervalo, "intervalos");

    for (let i = grado.value; i >= 0; i--) {
      const nodo = document.createElement("input");
      nodo.placeholder = `ingresa coeficiente de x^${i}`;
      nodo.className = "valores";
      coeficientes.insertBefore(nodo, before);
    }
    before.style.display = "block";
  });

coeficientes.addEventListener("submit", function (event) {
  event.preventDefault();

  var values = document.getElementsByClassName("valores");

  for (let i = 0; i <= grado.value; i++) {
    valores.push(parseInt(values[i].value));
  }
  console.log(valores, "coeficientes de mi funcion");
  Evaluacion(valores);
  CreacionArea(intervalo);
});

function Evaluacion(valor) {}
grado_completo = [];
function CreacionArea(intervalo) {
  for (let i = grado; i >= 0; i--) {
    grado_completo.push(i);
  }

  console.log(intervalo, "desde new");
  base = intervalo[1] - intervalo[0];
  base = base / 100;
  console.log(base);

  sumaAreas(base);
}

function sumaAreas(base) {
  let intervalo_completo = [];
  for (let i = intervalo[0]; i <= intervalo[1]; i++) {
    intervalo_completo.push(i);
  }
  console.log(intervalo_completo);
  alturas = [];
  let iterator = valores.length - 1; // mi grado
  let area = []; //mi funcion evaluada
  // for (let i = 0; i <= iterator[1]; i++) {
  //   area.push(
  //     Math.pow(valores[i] * (intervalo_completo[i] + base), grado_completo[i])
  //   );
  // }
  console.log(area, valores, intervalo_completo, grado_completo);
}

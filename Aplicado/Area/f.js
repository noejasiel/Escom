const grado = document.getElementById("grado");
const coeficientes = document.getElementById("coeficientes");
const before = document.getElementById("submit-enviar");
const imprimirValores = document.getElementById("results");

const form = document
  .getElementById("form")
  .addEventListener("submit", function (event) {
    event.preventDefault();
    // console.log(grado.value);

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
  const valores = [];
  var values = document.getElementsByClassName("valores");
  console.log("pruebaaa");
  console.log(values);
  for (let i = 0; i <= grado.value; i++) {
    valores.push(values[i].value);
  }
  // console.log(valores);
});

function Evaluacion(valores) {
  var flag = false;
  const cero = [];
  var flagg = new Boolean(false);
  an = findComunDenominadorAn(valores);
  a0 = findComunDenominadorA0(valores);
  console.log(a0, "negatvos");
  //si el dato independiente existeeeee  ************************************************************************
  if (valores[valores.length - 1] != 0) {
    let xzz = grado.value;
    imprimirValores.innerHTML += `
     <p> tu ecuacion es:</p>
    `;
    for (let i = 0; i < valores.length; i++) {
      imprimirValores.innerHTML += `
        ${valores[i]}x^${xzz} +
     `;
      xzz--;
    }
    //arreglo de funciones---encontrar soluciones tendra dos parametros que son las llamadas a funciones que nos regresaran algo,
    // ---findRaices como argumento tendra lo que retorneencontrarsoluciones
    findRaices(
      encontrarSoluciones(
        findComunDenominadorAn(valores),
        findComunDenominadorA0(valores)
      ),
      valores
    );
  } else {
    console.log("no existe termino independientes");
    imprimirValores.innerHTML += `
    <p> x1 = 0</p>
  `;
    evaluarX(valores);
  }

  for (let i = 0; i <= grado.value; i++) {
    if (valores[i] == 0) {
      cero.push(valores[i]);
      flag = true;
    }
  }
  if (flag == false) {
    console.log("no hay ceros", valores);
    /* si no hay ceros significa que poddemos hacer el metodo con toal libertad */
  } else {
    console.log("hay ceros ", valores);
  }
}
//gradoo0[aux2]; para saber que le voy a restar
function evaluarX(valores) {
  // console.log(valores, "evaluar XXXXXXXXXXXXXXXXXxxxx");
  // let gradoo0 = [];
  // for (let i = valores.length - 1; i >= 0; i--) {
  //   gradoo0.push(i);
  // }
  // console.log(gradoo0, "missss gradoooosss");
  let i = 0;
  let aux = 0;
  let aux2 = 0;

  let size = valores.length;
  while (valores[i + 1] != null) {
    size--;
    if (valores[i] != 0) {
      aux = valores[i];
      aux2 = size;
    }
    i++;
  }
  const newArr = [];
  let aux3 = 0;
  for (let i = aux2; i <= valores.length - 1; i++) {
    newArr.push(valores[aux3]);
    aux3++;
  }

  Evaluacion(newArr);
}

function findRaices(soluciones, valores) {
  let gradoo = valores.length - 1;
  let potencia = [];
  for (let i = gradoo; i >= 0; i--) {
    potencia.push(i);
  }
  console.log(typeof parseFloat(potencia[0]));
  // valores = parseFloat(valores);
  console.log(potencia, valores, soluciones, "desde encontrar raices");
  var resultado = 0;
  var resulta = 0;
  // console.log(valores, soluciones, gradoo, "prueba2");
  let terminoIndependiente;
  let porsi = [];
  let aux;
  let x = 1;
  for (let j = 0; j < soluciones.length; j++) {
    resulta = 0;
    for (let i = 0; i < gradoo; i++) {
      console.log(
        valores[i] + "valor",
        soluciones[j] + "solucion",
        parseFloat(potencia[i]) + "potencua"
      );

      resultado =
        parseFloat(valores[i]) *
        Math.pow(soluciones[j], parseFloat(potencia[i]));
      resulta += resultado;

      aux = soluciones[j];
    }
    terminoIndependiente = parseFloat(valores[valores.length - 1]);
    console.log(
      "ESTE ES MI TERMINO INDEPENDIENTEEEEE **********************++",
      terminoIndependiente
    );
    resulta += terminoIndependiente;
    if (
      resulta == 0 ||
      (resulta < 0.000000000001 && resulta > -0.000000000001)
    ) {
      imprimirValores.innerHTML += `
      <p>X${x}: ${aux}</p>
      `;
      console.log(
        "OMG es raizzz ******************************************++********"
      );
      x++;

      // for (let i = 1; i < valores.length; i++) {
      //   porsi.push(valores[i]);
      // }
      // console.log("resullll antes de fun", resulta, porsi);
      // Evaluacion(porsi);
    }
    console.log("resultadoooo", resulta, porsi);
  }
}

function encontrarSoluciones(an, a0) {
  console.log(an, a0, "desde mi new function");
  const soluciones = [];

  for (let i = 0; i < a0.length; i++) {
    for (let j = 0; j < an.length; j++) {
      soluciones.push(a0[i] / an[j]);
      // console.log("s:" + a0[i] + "/" + an[j]);
    }
  }
  for (let i = 0; i < soluciones.length; i++) {
    for (let i = 0; i < soluciones.length; i++) {
      if (soluciones[i] > soluciones[i + 1]) {
        aux = soluciones[i];
        soluciones[i] = soluciones[i + 1];
        soluciones[i + 1] = aux;
      }
    }
  }
  //filtrando los datos repetidos
  let result = soluciones.filter((item, index) => {
    return soluciones.indexOf(item) === index;
  });

  console.log(result);
  return result;
}

function findComunDenominadorAn(valores) {
  let an = valores[0];
  console.log(an, "pueba de negativo absoluto");
  //divisores an
  an = Math.abs(an);
  const an_div = [];

  for (let i = 1; i <= an; i++) {
    if (an % i == 0) {
      an_div.push(i);
      an_div.push(i * -1);
    }
  }

  var aux;
  for (let i = 0; i < an_div.length; i++) {
    for (let i = 0; i < an_div.length; i++) {
      if (an_div[i] > an_div[i + 1]) {
        aux = an_div[i];
        an_div[i] = an_div[i + 1];
        an_div[i + 1] = aux;
      }
    }
  }
  return an_div;

  console.log(an_div);
}

function findComunDenominadorA0(valores) {
  let a0 = valores[valores.length - 1];
  //aqui no afectara a mi cadena principal en cuestion de mi termino independiente
  a0 = Math.abs(a0);
  console.log(valores, "probando negativos", a0);

  //divisores a0
  const a0_div = [];

  for (let i = 1; i <= a0; i++) {
    if (a0 % i == 0) {
      a0_div.push(i);
      a0_div.push(i * -1);
    }
  }

  for (let i = 0; i < a0_div.length; i++) {
    for (let i = 0; i < a0_div.length; i++) {
      if (a0_div[i] > a0_div[i + 1]) {
        aux = a0_div[i];
        a0_div[i] = a0_div[i + 1];
        a0_div[i + 1] = aux;
      }
    }
  }
  return a0_div;
  console.log(a0_div);
}

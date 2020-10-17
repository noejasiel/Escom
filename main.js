var alfa = document.getElementById("alfa");
var alfabeto = document.getElementById("alfabeto");
var primera = document.getElementById("primera");
var segunda = document.getElementById("segunda");
var n = document.getElementById("potencia");
var evaluar = document.getElementById("evaluar");
//obteniendo mis div para imprimir en ellos
var div_alfabeto = document.getElementById("def_alfa");
var div_mostrar_palabras = document.getElementById("palbra_1_2");
var div_longitud = document.getElementById("longitud");
var div_sufi = document.getElementById("prefi_sufi");
var div_concatenar = document.getElementById("concatenar");
var div_potenciaa = document.getElementById("potenciaa");

var cambio = false;

alfa.addEventListener("click", (event) => {
  event.preventDefault();
  Transform();
});

function Transform() {
  alfabeto = alfabeto.value;
  primera = primera.value;
  segunda = segunda.value;
  console.log(primera);
  var arr = [];
  var arr1 = [];
  var arr2 = [];

  for (let i = 0; i < alfabeto.length; i++) {
    arr[i] = alfabeto.charAt(i);
  }
  for (let i = 0; i < primera.length; i++) {
    arr1[i] = primera.charAt(i);
  }
  for (let i = 0; i < segunda.length; i++) {
    arr2[i] = segunda.charAt(i);
  }
  // console.log(arr);
  // console.log(arr1);
  // console.log(arr2);

  //Imprimir mi alfabeto
  div_alfabeto.innerHTML = `
    <h3> tu alfabeto es: ${alfabeto}</h3>
  `;
  div_mostrar_palabras.innerHTML = `
    <h3>tus palabras dadas son:</h3>
    <p>palabra 1: ${primera}</p>
    <p>palabra 2: ${segunda}</p>
  `;

  comprobar(arr, arr1, arr2, alfabeto, primera, segunda);
  longitud(primera, segunda);
  concatenar(primera, segunda);
  // Evaluar(arr1);
}

function comprobar(arr, arr1, arr2, alfabeto, primera, segunda) {
  var resul = [];
  var resul1 = [];

  if (
    primera.length > alfabeto.length + 1 ||
    segunda.length > alfabeto.length + 1
  ) {
    console.log("imposible");
  } else {
    for (let i = 0; i < primera.length; i++) {
      for (let j = 0; j < alfabeto.length; j++) {
        if (arr1[i] == arr[j]) {
          resul.push(arr1[i]);
        }
      }
    }
    for (let i = 0; i < segunda.length; i++) {
      for (let j = 0; j < alfabeto.length; j++) {
        if (arr2[i] == arr[j]) {
          resul1.push(arr2[i]);
        }
      }
    }

    const newArr = resul.filter((el, index) => resul.indexOf(el) === index);
    const newArr1 = resul1.filter((el, index) => resul1.indexOf(el) === index);
    console.log(newArr);
    console.log(newArr1);

    console.log(newArr1);
    if (arr1.length == newArr.length && arr1 != 0) {
      console.log("OMG si se vale");
    } else {
      console.log("no bro");
    }
    if (arr2.length == newArr1.length && arr2 != 0) {
      console.log("OMG si se vale");
    } else {
      console.log("no bro");
    }
    // Sufijos(arr1);

    Prefijos(arr1);
    Potenciar(segunda, arr2, arr1);
  }
}

function longitud(primera, segunda) {
  // console.log("la longitud de la primera palabra es: " + primera.length);
  // console.log("la longitud de la segunda palabra es: " + segunda.length);

  div_longitud.innerHTML = `
    <h3>Longitud de las palabras</h3>
    <p>longitud palabra 1: ${primera.length} </p>
    <p>longitud palabra 2: ${segunda.length} </p>
  `;
}
function concatenar(primera, segunda) {
  var resultado = primera.length + segunda.length;
  console.log("la palabra concatenada es: " + primera + segunda);
  console.log("la longitud de la palabra concatenada es: " + resultado);
  div_concatenar.innerHTML = `
    <h3>Concatenacion de las palbras</h3>
    <p>las palabras concatenadas son : ${primera + segunda}</p>
    <p>su longitud es: ${resultado}</p>
  `;
}

function Prefijos(arr1) {
  var prefi = [];
  var aux = "";

  for (let i = 0; i < arr1.length; i++) {
    for (let j = i; j <= i; j++) {
      aux = aux + arr1[j];
      prefi.push(aux);
      // console.log(aux);
    }
  }

  // console.log(prefi, "final");

  var sufi = [];
  var auxx = "";
  for (let i = arr1.length - 1; i >= 0; i--) {
    for (let j = i; j <= i; j++) {
      auxx = auxx + arr1[j];
      sufi.push(auxx);
      console.log(auxx);
    }
  }
  // console.log(sufi, "defrv");

  div_sufi.innerHTML = `
    <h3>Prefijos y Sufijos</h3>
    <p>los prefijos son: ${prefi}</p>
    <p>los sufijos son: ${sufi}</p>
  `;
}

function Potenciar(segunda, arr2, arr1) {
  console.log(arr1, "desde pote quiero ver");
  var potencia = [];
  let aux = "";
  n = n.value;
  if (n >= 0) {
    for (let i = 0; i < n; i++) {
      aux += segunda + "-";
      // console.log(aux);
    }
  } else {
    n = Math.abs(n);
    console.log(n);
    let invertido = Espejo(arr2);
    for (let i = 0; i < n; i++) {
      aux += invertido + "-";
    }
    // console.log(aux, "desde el else");
  }
  potencia.push(aux);
  let dato = evaluar.value;

  // console.log(eva, "desde pote");

  div_potenciaa.innerHTML = `
    <h3>Potenciacion y Evaluacion</h3>
    <p>la palabra 2 potenciada a la ${n} potencia es : ${aux}</p>
    <p>evaluacion de a palabra 1 con la letra ${dato} dada es: ${Evaluar(
    arr1
  )} en total son ${Evaluar(arr1).length}</p>
  `;

  console.log(potencia, "potencia");
}

function Espejo(segunda) {
  //mi segunda es mi palabra completa
  var invertido = [];
  let x = "";
  console.log(segunda);
  for (let i = segunda.length - 1; i >= 0; i--) {
    x += segunda[i];
  }
  // invertido.push(x);
  return x;
}

function Evaluar(arr1) {
  let dato = evaluar.value;
  var newArr = arr1.filter((numb) => numb === dato);
  console.log(newArr, "evaluacion", arr1);
  return newArr;
}

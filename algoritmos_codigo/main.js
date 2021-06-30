var base = document.getElementById("base");
var submit = document.getElementById("enviar");
var xy = document.getElementById("resultado");
var x = document.getElementById("x");
var y = document.getElementById("y");

function dividir(xy, indice, base) {
  if (indice == "i") {
    var xyi = xy.slice(0, xy.length / 2);
    return xyi;
  } else {
    var xyd = xy.slice(xy.length / 2, xy.length);
    return xyd;
  }
}

function multiplar(x, y) {
  var xn = parseInt(x, 10);
  var yn = parseInt(y, 10);

  return xn * yn;
}

submit.addEventListener("click", function (event) {
  event.preventDefault();
  x = x.value;
  y = y.value;
  base = base.value;

  if (x.length == y.length && (x.length && y.length) % 2 == 0) {
    var ind = 1;
    while (ind <= 20) {
      if (x.length == Math.pow(2, ind)) {
        break;
      }
      ind++;
    }
  } else if (x.length != y.length) {
    if (x.length < y.length) {
      while (x.length != y.length) {
        var aux = x;
        x = "";
        x = "0" + aux;
      }
    }
    if (y.length < num1.length) {
      while (num1.length != y.length) {
        var aux = y;
        y = "";
        y = "0" + aux;
      }
    }
  } else if (x.length == 1 && y.length == 1) {
    var n = 1;
    while (n < 2) {
      while (x.length < 3) {
        var aux = x;
        var aux2 = y;
        x = "";
        y = "";
        x = "0" + aux;
        y = "0" + aux2;
        break;
      }
      n++;
    }
  }

  completar_paridad(x, y);
});

function completar_paridad(x, y) {
  var n = 1;
  while (n < 20) {
    if (Math.pow(2, n) < x.length && x.length < Math.pow(2, n + 1)) {
      var residuo = Math.pow(2, n + 1) - x.length;
      var i = 0;
      while (i < residuo) {
        var aux = x;
        var aux2 = y;
        y = "";
        x = "";
        x = "0" + aux;
        y = "0" + aux2;

        i++;
      }
    }
    n++;
  }

  multiplicar(x, y, base);
}
function casoBase(x, y) {
  if (x.length == 1 && y.length == 1) {
    return 1;
  } else {
    return 0;
  }
}

function productoBase(x, y) {
  return x * y;
}

function multiplicar(x, y, base) {
  if (casoBase(x, y) == 1) {
    productoBase(x, y);
  } else {
    var xi = dividir(x, "i", base);
    var xd = dividir(x, "d", base);
    var yi = dividir(y, "i", base);
    var yd = dividir(y, "d", base);

    var p1 = multiplar(xi, yi);
    var p2 = multiplar(
      parseInt(xi, 10) + parseInt(xd, 10),
      parseInt(yi, 10) + parseInt(yd, 10)
    );
    var p3 = multiplar(xd, yd);

    var resultado =
      Math.pow(parseInt(base, 10), x.length) * p1 +
      Math.pow(parseInt(base, 10), x.length / 2) * (p2 - p1 - p3) +
      p3;
    xy.textContent += `X * Y = ${resultado}`;
  }
}

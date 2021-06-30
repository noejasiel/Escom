var matrixInt = new Array();

for (let i = 0; i < 5; i++) {
  matrixInt[i] = new Array();
  for (let j = 0; j < 5; j++) {
    if (matrixInt[i] == 0) {
      matrixInt[i] = 2;
    }
    matrixInt[i][j] = 1;
  }
}
console.log(matrixInt);

/* Fisher–Yates shuffle */
function shuffle(array) {
  let currentIndex = array.length,
    randomIndex;

  // While there remain elements to shuffle.
  while (currentIndex > 0) {
    // Pick a remaining element.
    randomIndex = Math.floor(Math.random() * currentIndex);
    currentIndex--;

    // And swap it with the current element.
    [array[currentIndex], array[randomIndex]] = [
      array[randomIndex],
      array[currentIndex],
    ];
  }

  // Shuffled array
  return array;
}

/* Sort check */
function check(array) {
  for (let i = 0; i < array.length; i++) {
    if (array[i] > array[i + 1]) return false;
  }
  return true;
}

// Used like so
// Add one element at a time to see the time explode
var arr = [42, 2, 11, 37, 41, 15, 31, 16];
let count = 0;
while (check(arr) === false) {
  count++;
  shuffle(arr);
}
console.log(count);
console.log(arr);

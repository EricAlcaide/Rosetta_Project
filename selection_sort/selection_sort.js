function selectionSort(items) {
  var length = items.length;
  for (var i = 0; i < length - 1; i++) {
    var min = i;
    for (var j = i+1; j < length; j++) {
      if (items[j] < items[min]) {
        min = j;
      }
    }
    if (min != i) {
      var tmp = items[i];
      items[i] = items[min];
      items[min] = tmp;
    }
  }
  return items;
}


console.log(selectionSort([2,3,5,1,4]));
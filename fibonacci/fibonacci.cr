def fibonacci
  prev, actual = 0, 1
  aux = 0

  10.times do
    aux = actual + prev
    prev = actual
    actual = aux
    puts actual
  end
end

fibonacci

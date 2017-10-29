class AssertionError < RuntimeError; end
def assert &block; raise AssertionError unless yield; end

def caesar(plain, shift:)
  alphabets = ['A'..'Z', 'a'..'z'].map do |alphabet|
    Hash[alphabet.map.with_index.to_a]
  end

  plain.chars.map do |char|
    alphabet = alphabets.detect { |alphabet| alphabet.include? char }
    next char unless alphabet
    char_index = alphabet[char]
    new_char_index = (char_index + shift) % alphabet.size
    alphabet.keys[new_char_index]
  end.join
end

assert { caesar('This is a caesar cipher example', shift: 0) == 'This is a caesar cipher example' }
assert { caesar('A not so long string', shift: 2) == 'C pqv uq nqpi uvtkpi' }
assert { caesar('Negative shift', shift: -1) == 'Mdfzshud rghes' }
